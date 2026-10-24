"""Run the hero cutscene pose animations (ACTOR_ANIM / ACTOR_ANIM_LOOP codes 0x80-0xB5) from a save state and record what the game draws (graphics go to a directory chosen by the caller).
usage: rip_hero_poses.py ROM STATE OUTDIR [hero[,hero]] [anim[,anim]] [dir[,dir]] [mode[,mode]]
  hero: boy girl sprite (default all)   anim: hex or decimal codes (default 0x80-0xB5)   dir: up down right (left is the mirror image of right; default up,down,right)
  mode: once = ACTOR_ANIM (state 0x40, runs until the script ends), loop = ACTOR_ANIM_LOOP (state 0x30, the script restarts while an event runs); default both
Output: OUTDIR/<hero>/pose_<code>_<mode>_<dir>.json and _<nn>.png (format of rip_hero_anims.py, docs/graphics.md section 7) plus OUTDIR/index_poses.json.
The commands are applied the way the VM does it ($C1:E8D3, opcodes 0x31 / 0x34): velocity cleared, obj+0x1C = 0x40 / 0x30, obj+0x11 = code, obj+0x30 = 0xFF, obj+0x42 = 1 (once) or 0 (loop).
For the loop mode the event VM state `$D0` is held at 0x82 (timed wait), because the end-of-script handler of state 0x30 (`$C0:F94B-F955`) restarts the script only while `$D0` is non-zero.
Sound requests (`$C3:0004`) made during the run are logged with their frame. `end_move` is the displacement that happens in the frame in which the script ends (the velocity is cleared after it is applied)."""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, rip_hero_anims as R

HZ = R.HZ
DIRS3 = ('up', 'down', 'right')
CODES = range(0x80, 0xB6)
SCREEN_POS = (128, 140)
ONCE_MAX, LOOP_FRAMES, MAX_PERIOD = 500, 360, 180


def place(g, B):
    w = g.c.wram
    wx, wy = SCREEN_POS[0] + (w[0xA8] | w[0xA9] << 8), SCREEN_POS[1] + (w[0xAA] | w[0xAB] << 8)
    w[B + 1] = w[B + 6] = 0; w[B + 2:B + 6] = bytes((wx & 255, wx >> 8, wy & 255, wy >> 8))


def run_pose(g, slot, B, code, mode, sounds, tail=None):
    """Apply the command and record: returns (latency_frames, frames) like rip_hero_anims.record. Frames carry p0 (actor position at the start) and the jump height."""
    w = g.c.wram
    tail = [] if tail is None else tail
    g.frame(); w[B + 6] = w[B + 7] = 0
    w[B + 0x1C] = 0x40 if mode == 'once' else 0x30; w[B + 0x11] = code; w[B + 0x30] = 0xFF; w[B + 0x42] = 1 if mode == 'once' else 0
    s0 = g.w16(B + 0x16); p0 = (g.w16(B + 2), g.w16(B + 4)); lat = []; frs = []
    n = ONCE_MAX if mode == 'once' else LOOP_FRAMES
    for i in range(n):
        if mode == 'loop': w[0xD0] = 0x82; w[0x4F] = 255
        g.frame(); fr = R.grab(g, slot, B)
        if mode == 'once' and frs and fr['state'] == 0:
            tail[:] = [g.w16(B + 2) - frs[-1]['wpos'][0], g.w16(B + 4) - frs[-1]['wpos'][1]]
            break
        fr['p0'] = p0; fr['t'] = g.f; fr['pos_now'] = (g.w16(B + 2), g.w16(B + 4))
        (frs if frs or fr['script'] != s0 else lat).append(fr)
    return lat, frs


def period(frs):
    """Smallest p such that picture, movement step and jump height repeat with period p over the whole recording (None if there is none within MAX_PERIOD)."""
    ks = [(R.key(f), f['height']) for f in frs]
    dl = [(frs[i]['wpos'][0] - frs[i - 1]['wpos'][0], frs[i]['wpos'][1] - frs[i - 1]['wpos'][1]) for i in range(1, len(frs))]
    for p in range(1, min(MAX_PERIOD, len(frs) // 2) + 1):
        if all(ks[i] == ks[i + p] for i in range(len(ks) - p)) and all(dl[i] == dl[i + p] for i in range(len(dl) - p)): return p
    return None


def rip(rom, state, outdir, heroes, codes, dirs, modes):
    idx = {}
    for hero in heroes:
        for d in dirs:
            g, slot, B = R.setup(rom, state, hero, 0, d, None)
            place(g, B); g.frame()
            base = g.save()
            for code in codes:
                for mode in modes:
                    g.load(base); sounds = []
                    g.c.hooks[0xC30004] = lambda cp: (sounds.append((g.f, [cp.wram[0x1E00 + k] for k in range(4)])), setattr(cp, 'PC', (cp.pull16() + 1) & 0xFFFF), setattr(cp, 'PB', cp.pull8()), True)[-1]
                    tail = []
                    lat, frs = run_pose(g, slot, B, code, mode, sounds, tail)
                    if not frs: continue
                    per = None
                    if mode == 'loop':
                        per = period(frs)
                        frs = frs[:per] if per else frs[:120]
                    else:
                        if g.w8(B + 0x1C) != 0 and len(frs) >= ONCE_MAX - 1: print('warning: %s %s %02X once did not end' % (hero, d, code))
                    t0 = frs[0]['t']
                    meta = dict(body_offset=frs[0]['body'], latency_frames=len(lat), hero=hero, attack='pose', level=0, direction=d, anim_id=code, mode=mode, state=0x40 if mode == 'once' else 0x30,
                                end_move=tail or [0, 0], loop_period=per, movement_per_cycle=[frs[-1]['wpos'][0] - frs[0]['p0'][0], frs[-1]['wpos'][1] - frs[0]['p0'][1]] if per else None,
                                sounds=[dict(frame=f - t0, cmd=v[0], id=v[1], word=v[2] | v[3] << 8) for f, v in sounds if f >= t0])
                    name = 'pose_%02X_%s_%s' % (code, mode, d)
                    R.export(rom, frs, os.path.join(outdir, hero), name, dict(meta, weapon_row=0, weapon_type=0))
                    idx.setdefault(hero, {})[name] = dict(anim=code, mode=mode, dir=d, frames=len(frs), loop_period=per)
                    print(hero, name, 'frames', len(frs), 'period', per, flush=True)
    path = os.path.join(outdir, 'index_poses.json')
    old = json.load(open(path)) if os.path.exists(path) else {}
    for h, v in idx.items(): old.setdefault(h, {}).update(v)
    json.dump(old, open(path, 'w'), indent=1)


if __name__ == '__main__':
    rom = romio.rom_from_argv(); state, outdir = sys.argv[1], sys.argv[2]
    arg = lambda i: sys.argv[i].split(',') if len(sys.argv) > i and sys.argv[i] else None
    heroes = arg(3) or list(R.HEROES)
    codes = [int(c, 0) for c in arg(4)] if arg(4) else list(CODES)
    rip(rom, state, outdir, heroes, codes, arg(5) or list(DIRS3), arg(6) or ['once', 'loop'])
