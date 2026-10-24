"""The post-fight event of the Dark Lich (event 0x42D, started by the boss death code `$C2:0C11`) run from a save state in map 246, as a timeline.
usage: lich_postfight.py ROM STATE OUT.json [md=1]
STATE: a ZSNES v143 state on map 246 with the three heroes (the one that follows the Mana Beast intro works; flag 0x4E is set to 6 here).
Starts event 0x42D the way the boss death does and steps the real frame body (`$C0:B08C`, event VM, text engine, map loader) until the VM is idle. Frame 0 is the frame of the call.
Output: VM commands that matter for the staging (actor animations / walks, waits, calls, screen effects, sound, text blocks as address and length) and every change of
animation code, state byte, facing or position of the three heroes. No script text is read or stored."""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, event_runs as ER, event_vm as E

HZ = E.HZ
SHOWN = (0x31, 0x34, 0x32, 0x08, 0x28, 0x2D, 0x40, 0x18)
NAMES = ('boy', 'girl', 'sprite')


def run(rom, state):
    w = ER.Runner(rom, state)
    w.set_leader(0)
    wm = w.c.wram
    wm[0xCF4E] = 6
    w.t_scene = w.t; w._observe()
    w.start_event(0x42D)
    t0 = w.t; last = {}; log = []; nops = 0
    while w.t - t0 < 8000:
        w.frame()
        for s in range(3):
            b = 0xE000 + 0x200 * s
            k = (wm[b + 0x11], wm[b + 0x1C], wm[b + 0x10], w.w16(b + 2), w.w16(b + 4))
            if s in last and last[s][:3] != k[:3]:
                log.append(dict(frame=w.t - t0, kind='hero', hero=NAMES[s], anim=k[0], state=k[1], facing=k[2], x=k[3], y=k[4]))
            last[s] = k
        while nops < len(w.vm_ops):
            o = w.vm_ops[nops]; nops += 1
            op = o['op']
            if op in SHOWN or op in range(0x20, 0x28) or op >= 0x50:
                ev, off = E.event_of(rom, o['bank'], o['addr'])
                if op >= 0x50:
                    log.append(dict(frame=o['t'] - t0, kind='vm', where='%03X+%04X' % (ev, off), op='TEXT'))
                else:
                    name = E.OPS[op][0]
                    log.append(dict(frame=o['t'] - t0, kind='vm', where='%03X+%04X' % (ev, off), op=name, **E.op_params(op, o['args'].ljust(4, b'\0'))))
        if wm[0xD0] == 0 and w.t - t0 > 10: break
    log.sort(key=lambda r: r['frame'])
    for r in log: r['s'] = round(r['frame'] / HZ, 3)
    return dict(source='tools/lich_postfight.py (real 65816 code, PPU/APU not emulated)', frame_hz=HZ, total_frames=w.t - t0, events=log)


if __name__ == '__main__':
    rom = romio.rom_from_argv()
    rep = run(rom, sys.argv[1])
    json.dump(rep, open(sys.argv[2], 'w'), indent=1)
    print('wrote', sys.argv[2], 'frames', rep['total_frames'])
    if 'md=1' in sys.argv:
        for r in rep['events']:
            print(r['frame'], r['s'], {k: v for k, v in r.items() if k not in ('frame', 's')})
