"""Full-WRAM model of actor-program restart and status-program call setup.
usage: actor_program_calls.py ROM [--json OUT]
"""
import json
import random
import sys

import combat_env
import romio


def word(memory, offset):
    return int.from_bytes(memory[offset:offset + 2], 'little')


def store(memory, offset, value):
    memory[offset:offset + 2] = (value & 65535).to_bytes(2, 'little')


def restart(rom, memory, base, program):
    pointer = word(rom, 0x100009 + program * 16)
    store(memory, base + 0x144, pointer + 3)
    for offset in (0x146, 0x14C, 0x14E):
        store(memory, base + offset, 0)
    store(memory, base + 0x1AC, 65535)


def compare(env, expected, label, incoming_d, incoming_db, incoming_m):
    # All native return addresses, saved registers and local frames fit here.
    expected[0x1EE0:0x1F01] = env.c.wram[0x1EE0:0x1F01]
    assert env.c.wram == expected, (label,
        [(hex(i), a, b) for i, (a, b) in enumerate(zip(env.c.wram, expected)) if a != b][:8])
    assert (env.c.S, env.c.D, env.c.DB, env.c.M, env.c.XF) == (0x1F00, incoming_d, incoming_db, incoming_m, 0)


def validate(rom):
    rnd = random.Random(0x263C)
    overflows = wrapped = 0
    for trial in range(512):
        env = combat_env.Env(rom)
        env.c.wram[:] = rnd.randbytes(len(env.c.wram))
        slot, program = trial % 6, trial % 256
        base = 0xE000 + slot * 0x200
        expected = bytearray(env.c.wram)
        restart(rom, expected, base, program)
        d, db, m = (0x300, 0x1234)[trial % 2], (0, 0x7E, 0xFF)[trial % 3], trial % 2
        env.call(0xC1263C, A=(trial & 255) | 0xAB00, X=slot * 0x200,
                 m=m, D=d, DB=db, long=False)
        compare(env, expected, ('restart', trial), d, db, m)
    for trial in range(1024):
        env = combat_env.Env(rom)
        env.c.wram[:] = rnd.randbytes(len(env.c.wram))
        slot, depth = trial % 6, trial % 256
        program = (trial * 73 + trial // 256) & 255
        base = 0xE000 + slot * 0x200
        env.obj(slot).sb(0x14F, depth)
        expected = bytearray(env.c.wram)
        old_pc = word(expected, base + 0x144)
        # The original saves first, even for an invalid depth; offset is byte-masked.
        store(expected, base + 0x150 + ((depth * 2) & 255), old_pc)
        store(expected, base + 0x144, word(rom, 0x104ED3 + ((program * 2) & 255)))
        next_depth = (depth + 1) & 255
        if next_depth < 16:
            expected[base + 0x14F] = next_depth
            wrapped += int(depth == 255)
        else:
            # The pre-check saved-PC write can already have overwritten object id.
            restart(rom, expected, base, expected[base + 0x180])
            overflows += 1
        d, db, m = (0x300, 0x1234)[trial % 2], (0, 0x7E, 0xFF)[trial % 3], trial % 2
        env.call(0xC12698, A=program | 0xAB00, X=slot * 0x200,
                 m=m, D=d, DB=db, long=False)
        compare(env, expected, ('call', trial, depth, program), d, db, m)
    script_errors = 0
    for trial in range(1024):
        env = combat_env.Env(rom)
        env.c.wram[:] = rnd.randbytes(len(env.c.wram))
        slot, depth = trial % 6, trial % 256
        base = 0xE000 + slot * 0x200
        env.obj(slot).sb(0x14F, depth)
        expected = bytearray(env.c.wram)
        is_call = trial < 512
        if is_call:
            old_pc = word(expected, base + 0x144)
            store(expected, base + 0x150 + ((depth * 2) & 255), old_pc + 3)
            target = int.from_bytes(rom[0x104F16 + old_pc:0x104F18 + old_pc], 'big')
            store(expected, base + 0x144, target)
            next_depth = (depth + 1) & 255
        else:
            next_depth = (depth - 1) & 255
        error = next_depth >= 16
        if error:
            restart(rom, expected, base, expected[base + 0x180])
            expected[base + 0x140] = 0
            script_errors += 1
        else:
            expected[base + 0x14F] = next_depth
            if not is_call:
                store(expected, base + 0x144, word(expected, base + 0x150 + next_depth * 2))
        d = (0x300, 0x1234)[trial % 2]
        env.call(0xC102B7 if is_call else 0xC102F8, A=0xAB55,
                 X=trial * 17 & 65535, Y=base, m=1, D=d, DB=0x7E, long=False)
        compare(env, expected, ('script_call' if is_call else 'script_return', trial, depth), d, 0x7E, 1)
        assert env.c.A & 255 == (0 if error else 255)
    return dict(verified=True, restart_cases=512, call_cases=1024,
                script_call_cases=512, script_return_cases=512, script_error_cases=script_errors,
                overflow_restart_cases=overflows, invalid_255_depth_wrap_cases=wrapped,
                scope='Original C1263C restart, C12698 status-program call and C102B7/C102F8 script CALL/RET with C10100 error restart over full random WRAM outside33-byte native return/local-frame window, stack/D/DB/M/X restoration checked. All byte program ids and all depth bytes appear, across six slots. Saved-PC write precedes depth check; illegal depths can overwrite later actor fields before restart. Depth255 wraps to0. CALL saves PC+3 then reads big-endian target; RET accepts depth16 and restarts at depth0. Return low A is FF to continue or00 on restart. Call-table index aliases modulo128; meaning of undefined ids and full VM execution/timing remain open.')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json') + 1], 'w') as output:
            json.dump(report, output, indent=2)
            output.write('\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
