"""Decode $C1:4C30 blocks and compare them with the real routine.
usage: boot_decode.py ROM [--json OUT] [--disasm OUT]
No decompressed bytes are saved; the report contains addresses and measurements only.
"""
import sys, json, random, romio, cpu65816 as cpu, flowdis

BOOT_SOURCE = 0xC77C00
BOOT_DEST = 0x7E8000

def decode(rom, source, destination, memory=None):
    bank, pos = source >> 16, source & 0xFFFF
    start = pos
    def read():
        nonlocal pos
        v = rom[((bank << 16) | pos) & 0x3FFFFF]
        pos = (pos + 1) & 0xFFFF
        return v
    mode = read()
    reserved = read()
    size = (read() << 8) | read()
    if mode > 5:
        raise ValueError('unsupported shift selector %d' % mode)
    shift = 5 - mode
    mask = (1 << shift) - 1
    memory = bytearray(0x10000) if memory is None else memory
    y = destination & 0xFFFF
    end = (y + size) & 0xFFFF
    literals = matches = produced = 0
    while True:
        token = read()             # the routine reads even when Y has reached the end
        if y >= end:
            break
        if token < 0x80:
            count = token + 1
            for _ in range(count):
                memory[y] = read()
                y = (y + 1) & 0xFFFF
            literals += 1
        else:
            distance = (((token & mask) << 8) | read()) + 1
            count = ((token & 0x7F) >> shift) + 3
            x = (y - distance) & 0xFFFF
            for _ in range(count):
                memory[y] = memory[x]
                x = (x + 1) & 0xFFFF
                y = (y + 1) & 0xFFFF
            matches += 1
        produced += count
    return memory, {'source': '%06X' % source, 'destination': '%06X' % destination,
                    'selector': mode, 'reserved': reserved, 'output_size': size,
                    'produced_size': produced, 'encoded_size': (pos - start - 1) & 0xFFFF,
                    'consumed_size': (pos - start) & 0xFFFF,
                    'lookahead_address': '%06X' % ((bank << 16) | ((pos - 1) & 0xFFFF)),
                    'next_source': '%06X' % ((bank << 16) | pos),
                    'literal_runs': literals, 'backreferences': matches}

def execute(rom, source, destination, memory=None):
    cpu.set_rom(rom)
    c = cpu.CPU()
    if memory is not None:
        offset = 0 if destination >> 16 == 0x7E else 0x10000
        c.wram[offset:offset + 0x10000] = memory
    c.A = ((destination >> 16) << 8) | (source >> 16)
    c.X, c.Y = source & 0xFFFF, destination & 0xFFFF
    c.M, c.XF, c.DB, c.S = 1, 0, 0, 0x1FFF
    c.push16(0xFFFD)
    c.PB, c.PC = 0xC1, 0x4C30
    while c.PC != 0xFFFE or c.PB != 0xC1:
        c.step()
        if c.steps > 3_000_000:
            raise RuntimeError('decompressor timeout')
    return c

def validate(rom):
    memory, info = decode(rom, BOOT_SOURCE, BOOT_DEST)
    c = execute(rom, BOOT_SOURCE, BOOT_DEST)
    end = 0x8000 + info['output_size']
    assert memory[0x8000:end] == c.wram[0x8000:end]
    assert c.X == int(info['next_source'], 16) & 0xFFFF
    assert c.Y == end and c.S == 0x1FFF and c.D == 0 and c.DB == 0
    info['verified'] = True
    info['routine_steps'] = c.steps
    # Run the actual reset path, stopping before the decompressed entry executes.
    reset = cpu.CPU()
    reset.E = 1
    reset.S = 0x01FF
    reset.PC = int.from_bytes(rom[0xFFFC:0xFFFE], 'little')
    while (reset.PB << 16 | reset.PC) != 0x7EAF0B:
        reset.step()
        if reset.steps > 3_000_000:
            raise RuntimeError('reset timeout')
    assert memory[0x8000:end] == reset.wram[0x8000:end]
    info['reset_steps'] = reset.steps
    reached = flowdis.run(rom, [(0x7EAF0B, 1, 0), (0x7EAF28, 1, 0)], images={0x7E: memory})
    ram = {a: e for a, e in reached.items() if 0x7E8000 <= a < 0x7E0000 + end}
    info['ram_static_instructions'] = len(ram)
    info['ram_static_instruction_bytes'] = sum(1 + e[2] for e in ram.values())
    # Generated streams exercise every selector, overlapping matches and both WRAM banks.
    rng = random.Random(0x4C30)
    cases = 0
    for mode in range(6):
        shift = 5 - mode
        for destbank in (0x7E, 0x7F):
            for trial in range(20):
                stream = bytearray()
                length = 0
                for _ in range(30):
                    if not length or rng.randrange(2):
                        count = rng.randint(1, 128)
                        stream.append(count - 1)
                        stream.extend(rng.randbytes(count))
                    else:
                        distance = rng.randint(1, min(length, 1 << (shift + 8)))
                        count = rng.randint(3, (0x7F >> shift) + 3)
                        stream.extend((0x80 | ((count - 3) << shift) | ((distance - 1) >> 8),
                                       (distance - 1) & 0xFF))
                    length += count
                stream = bytes((mode, trial, length >> 8, length & 0xFF)) + stream + b'\xA5'
                testrom = bytearray(rom)
                testrom[0x1F0000:0x1F0000 + len(stream)] = stream
                source, dest = 0xDF0000, (destbank << 16) | 0x4000
                mem, result = decode(testrom, source, dest)
                actual = execute(testrom, source, dest)
                offset = (destbank - 0x7E) << 16
                assert mem[0x4000:0x4000 + length] == actual.wram[offset + 0x4000:offset + 0x4000 + length]
                assert actual.X == result['consumed_size'] and actual.Y == 0x4000 + length
                cases += 1
    blocks = []
    for source, destination in ((0xC7B480, 0x7E5000), (0xDCF240, 0x7E2000),
                                (0xDCE800, 0x7E4000), (0xC7C1C0, 0x7E4C00)):
        mem, block = decode(rom, source, destination)
        actual = execute(rom, source, destination)
        lo = destination & 0xFFFF
        hi = lo + block['output_size']
        assert mem[lo:hi] == actual.wram[lo:hi]
        assert actual.X == int(block['next_source'], 16) & 0xFFFF and actual.Y == hi
        block['verified'] = True
        blocks.append(block)
    calls = [{'address': '%06X' % a, 'target': '%06X' % e[3]} for a, e in sorted(ram.items())
             if e[0] == 'JSL' and e[3] == 0xC10014]
    return memory, {'boot_block': info, 'synthetic_cases': cases,
                    'initialization_blocks': blocks, 'ram_decompressor_calls': calls}

def main():
    rom = romio.rom_from_argv()
    memory, report = validate(rom)
    print(json.dumps(report, indent=2))
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json') + 1], 'w') as f:
            json.dump(report, f, indent=2)
            f.write('\n')
    if '--disasm' in sys.argv:
        reached = flowdis.run(rom, [(0x7EAF0B, 1, 0), (0x7EAF28, 1, 0)], images={0x7E: memory})
        with open(sys.argv[sys.argv.index('--disasm') + 1], 'w') as f:
            for address, entry in sorted(reached.items()):
                if address >> 16 == 0x7E:
                    f.write(flowdis.fmt(address, entry) + '\n')

if __name__ == '__main__':
    main()
