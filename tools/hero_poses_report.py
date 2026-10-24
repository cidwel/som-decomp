"""Merge the output of rip_hero_poses.py into data/hero_poses.json and print the table of docs/hero-poses.md.
usage: hero_poses_report.py POSES_DIR OUT.json [md=1]
POSES_DIR holds <hero>/pose_<code>_<mode>_<dir>.json (dirs up, down, right; left is the mirror image of right).
Per animation code: for each mode the duration in frames (`end_move` is the displacement of the frame in which the script ends), the picture steps (script frame index, duration), the actor displacement per frame run-length coded, the jump height runs
and the sound requests. `cycle` is the length of one pass of the script; a looping pose that moves leaves the screen and cannot be compared picture by picture, so its cycle is
that of the same script run once (the script restarts from its first entry when state 0x30 meets its end operation)."""
import sys, os, json, glob

HEROES = ('boy', 'girl', 'sprite')
DIRS = ('up', 'down', 'right')
NO_END = (0x96, 0xB1)             # scripts that never end in state 0x40 (jump back to themselves)
USED_BY_EVENTS = None


def rle(seq):
    out = []
    for v in seq:
        if out and out[-1][0] == v: out[-1][1] += 1
        else: out.append([v, 1])
    return out


def timing(j):
    pf = j['per_frame']
    dx = [pf['actor_dx'][0]] + [pf['actor_dx'][i] - pf['actor_dx'][i - 1] for i in range(1, len(pf['actor_dx']))]
    dy = [pf['actor_dy'][0]] + [pf['actor_dy'][i] - pf['actor_dy'][i - 1] for i in range(1, len(pf['actor_dy']))]
    return dict(frames=j['total_frames'], steps=[[s['frame_idx'], s['frames']] for s in j['script_steps']],
                move=[[v[0][0], v[0][1], v[1]] for v in rle(list(zip(dx, dy)))], jump=[[h, n] for h, n in rle(pf['jump_height'])],
                end_move=j.get('end_move', [0, 0]), sounds=[[s['frame'], s['id']] for s in j['sounds']], pictures=len(j['frames']), latency_frames=j['latency_frames'])


def build(d):
    codes = sorted({int(os.path.basename(p).split('_')[1], 16) for p in glob.glob(os.path.join(d, '*', 'pose_*.json'))})
    out = {}
    for code in codes:
        ent = dict(code='0x%02X' % code, directions={})
        for dr in DIRS:
            per = {}
            for hero in HEROES:
                modes = {}
                for mode in ('once', 'loop'):
                    p = os.path.join(d, hero, 'pose_%02X_%s_%s.json' % (code, mode, dr))
                    if os.path.exists(p): modes[mode] = json.load(open(p))
                if not modes: continue
                o = timing(modes['once'])
                lp = modes.get('loop')
                cycle = o['frames'] if code not in NO_END else None
                if lp and lp['loop_period']: cycle = lp['loop_period']
                per[hero] = dict(once=o, cycle=cycle, ends=code not in NO_END)
            if not per: continue
            same = all(json.dumps({k: v for k, v in per[h]['once'].items() if k not in ('pictures',)}, sort_keys=True) == json.dumps({k: v for k, v in per['boy']['once'].items() if k not in ('pictures',)}, sort_keys=True) for h in per)
            ent['directions'][dr] = dict(same_timing_for_all_heroes=same, heroes=per)
        out[ent['code']] = ent
    return out


def md(data):
    print('| code | frames once (up/down/side) | steps (frame index, frames), down | move per cycle px (up / down / side) | jump | sounds (frame, id) |')
    print('|---|---|---|---|---|---|')
    for code, e in data.items():
        dd = e['directions']
        g = lambda dr: dd[dr]['heroes'].get('girl') or next(iter(dd[dr]['heroes'].values()))
        fr = '/'.join(str(g(dr)['once']['frames']) for dr in DIRS)
        st = ' '.join('%d:%d' % tuple(s) for s in g('down')['once']['steps'])
        mv = ' / '.join('%d,%d' % (sum(m[0] * m[2] for m in g(dr)['once']['move']) + g(dr)['once']['end_move'][0], sum(m[1] * m[2] for m in g(dr)['once']['move']) + g(dr)['once']['end_move'][1]) for dr in DIRS)
        jp = max(h for h, _ in g('down')['once']['jump'])
        sd = ' '.join('%d:0x%02X' % tuple(s) for s in g('down')['once']['sounds'])
        print('| %s | %s | %s | %s | %d | %s |' % (code, fr, st, mv, jp, sd))


if __name__ == '__main__':
    data = build(sys.argv[1])
    json.dump(dict(source='tools/rip_hero_poses.py + tools/hero_poses_report.py', frame_hz=60.0988, note='left = right mirrored (x displacement negated)', poses=data), open(sys.argv[2], 'w'), indent=None, separators=(',', ':'))
    print('wrote', sys.argv[2], len(data), 'codes', os.path.getsize(sys.argv[2]), 'bytes')
    if 'md=1' in sys.argv: md(data)
