"""Render the music of the game from the ROM: the real 65816 music loader (`JSL $C3:0004` with `$1E00` = 1) talks through the four APU ports to the real
sound driver running in spc700_cpu.Apu (boot upload of sfx_extract.boot_ram); when the loader returns, the APU state is saved as a .spc and libgme plays it.
usage: music_extract.py ROM OUTDIR [--ids all|0x11,0x0E] [--secs 60] [--spc] [--loop]
--loop renders 240 s, measures the loop (find_loop) and writes intro + one loop; index.json gets loop_start_s / loop_length_s.
OUTDIR must be outside the repository (game audio is never committed). docs/audio.md section 8."""
import sys, os, struct, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, cpu65816 as cpu, sfx_extract, spc700_cpu

REPO = os.path.realpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
N_SONGS = 59


def boot_state(rom, w):
    """The 65816 sound variables as the boot upload `$C3:0000` leaves them (`$C3:011F-015C`): page `$1E00` cleared, no song (`$1E05` = 0xFF),
    free APU pointer `$1E48` = `$1EF8` = 0x4800 + the word at `$C3:1AE2`, `$1EF0` = 2, `$1EF2` = 0xEA (echo page), source pointer `$1EFA` = `$C3:0000`."""
    for a in range(0x1E00, 0x1F00): w[a] = 0
    w[0x1E05] = 0xFF
    free = (struct.unpack_from('<H', rom, 0x031AE2)[0] + 0x4800) & 0xFFFF
    for a in (0x1EF8, 0x1E48): w[a], w[a + 1] = free & 0xFF, free >> 8
    w[0x1EFA], w[0x1EFB], w[0x1EF0], w[0x1EF2], w[0x1EF1] = 0, 0xC3, 2, 0xEA, 0


def load_song(rom, song, p2=0x08, p3=0x0F, apu_steps_per_read=96):
    apu = spc700_cpu.Apu(sfx_extract.boot_ram(rom)[0])
    apu.run(60000)                                             # driver initialisation up to its main loop
    cpu.set_rom(rom)
    c = cpu.CPU()
    ow, orr = c.wr8, c.rd8
    stats = dict(reads=0, writes=0)

    def wr8(a, v):
        o = a & 0xFFFF
        if (a >> 16) in (0, 0x80) and 0x2140 <= o <= 0x2143:
            apu.ports_in[o - 0x2140] = v & 0xFF; stats['writes'] += 1
            return
        ow(a, v)

    def rd8(a):
        o = a & 0xFFFF
        if (a >> 16) in (0, 0x80) and 0x2140 <= o <= 0x2143:
            before = list(apu.ports_out)
            for _ in range(apu_steps_per_read):
                apu.step()
                if apu.ports_out != before:
                    apu.run(16)                                # the driver acknowledges before it has read ports 2 and 3
                    break
            stats['reads'] += 1
            return apu.ports_out[o - 0x2140]
        return orr(a)
    c.wr8, c.rd8 = wr8, rd8
    w = c.wram
    boot_state(rom, w)
    w[0x1E00], w[0x1E01], w[0x1E02], w[0x1E03] = 1, song, p2, p3
    c.M = 1; c.XF = 1; c.S = 0x01FF; c.DB = 0; c.D = 0
    c.push8(0xFE); c.push16(0xFFFD); c.PB = 0xC3; c.PC = 0x0004
    n = 0
    while not (c.PB == 0xFE and c.PC == 0xFFFE):
        c.step(); n += 1
        if n > 50_000_000: raise RuntimeError('loader did not return')
    apu.run(200000)
    return apu, stats


def find_loop(stereo, sr=sfx_extract.SR):
    """(loop start, loop length) in samples of a render, measured on the audio: the lag where the 10 ms RMS envelope of 60-120 s repeats best,
    refined by cross-correlation of the raw signal, and the earliest time from which that lag still repeats (correlation > 0.9). Approximate:
    the driver's own loop command is not decoded."""
    import numpy as np
    x = np.asarray(stereo, dtype=np.float32).reshape(-1, 2).mean(axis=1)
    hop = sr // 100
    n = len(x) // hop
    env = np.sqrt((x[:n * hop].reshape(n, hop) ** 2).mean(axis=1))
    a = env[6000:12000]
    best = None
    for lag in range(1000, len(env) - 12000):
        d = np.abs(a - env[6000 + lag:12000 + lag]).mean()
        if best is None or d < best[0]: best = (d, lag)
    lag = best[1] * hop
    t = 100 * sr
    w = x[t:t + sr]
    cands = range(lag - hop * 5, lag + hop * 5)
    scores = [float(np.dot(w, x[t + c:t + c + sr])) for c in cands]
    lag = cands[int(np.argmax(scores))]

    def corr(p):
        u, v = x[p:p + sr // 2], x[p + lag:p + lag + sr // 2]
        den = float(np.linalg.norm(u) * np.linalg.norm(v))
        return float(np.dot(u, v)) / den if den else 1.0
    start = t
    while start > 0 and corr(start - sr // 10) > 0.9:
        start -= sr // 10
    return start, lag


def main():
    rom = romio.rom_from_argv()
    out = os.path.realpath(sys.argv[1])
    if out == REPO or out.startswith(REPO + os.sep): sys.exit('OUTDIR must be outside the repository')
    os.makedirs(out, exist_ok=True)
    args = sys.argv[2:]
    secs = float(args[args.index('--secs') + 1]) if '--secs' in args else 60.0
    loop = '--loop' in args
    ids = list(range(N_SONGS))
    if '--ids' in args and args[args.index('--ids') + 1] != 'all':
        ids = [int(x, 0) for x in args[args.index('--ids') + 1].split(',')]
    index = {}
    for song in ids:
        apu, st = load_song(rom, song)
        spc = apu.spc()
        if '--spc' in args:
            open(os.path.join(out, 'music_%02x.spc' % song), 'wb').write(spc)
        buf = sfx_extract.ungain(sfx_extract.render(spc, max(secs, 240.0) if loop else secs))
        index['%02x' % song] = dict(peak=sfx_extract.peak(buf), port_reads=st['reads'], port_writes=st['writes'])
        if loop and sfx_extract.peak(buf) > 100:
            start, length = find_loop(buf)
            buf = buf[:2 * (start + length)]
            index['%02x' % song].update(loop_start_s=round(start / sfx_extract.SR, 4), loop_length_s=round(length / sfx_extract.SR, 4))
        sfx_extract.write_wav(os.path.join(out, 'music_%02x.wav' % song), buf)
        print('music %02x peak %d writes %d' % (song, index['%02x' % song]['peak'], st['writes']), flush=True)
    json.dump(index, open(os.path.join(out, 'index.json'), 'w'), indent=1)


if __name__ == '__main__':
    main()
