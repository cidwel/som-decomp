#!/usr/bin/env python3
"""Headless audio check: the game must make sound, and the hybrid must sound like the original.

    tools/som_audio_check.py --core snes9x --reference-rom ORIG.sfc --hybrid-rom HYBRID.sfc

Runs both ROMs through tools/som_libretro_driver.c for N frames (default 1800, title + intro)
with the same START presses, dumps the raw stereo s16 stream the core produced, and checks:
  * not silent: whole-run RMS and peak above a floor, and enough one-second windows non-silent
  * not a constant tone/DC: the spectral centroid of the one-second windows changes over time
  * original and hybrid streams have equal sha256 (and equal length)
Writes nothing inside the repository; raw dumps go to the scratch directory.
Exit status 0 only if every assertion holds.
"""
import argparse
import hashlib
import json
import os
import pathlib
import subprocess
import sys

import numpy as np

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import som_boot_smoke as smoke  # noqa: E402

RMS_FLOOR = 200.0          # of 32768 full scale; a silent core gives ~0
PEAK_FLOOR = 2000
ACTIVE_WINDOW_RMS = 50.0
MIN_ACTIVE_FRACTION = 0.5
MIN_CENTROID_RANGE_HZ = 100.0


def run_driver(driver, core, rom, frames, script, out):
    out.mkdir(parents=True, exist_ok=True)
    raw = out / 'audio.s16'
    env = dict(os.environ, SOM_AUDIO_RAW=str(raw))
    proc = subprocess.run([str(driver), str(smoke.CORES[core]), str(rom), str(frames),
                           str(out / 'trace.txt'), str(script)], capture_output=True, text=True, env=env)
    if proc.returncode:
        raise SystemExit('driver failed: %s' % proc.stderr)
    rate = 32040.0
    for line in proc.stderr.splitlines():
        if line.startswith('av:'):
            rate = float(line.split(',')[1].split()[0])
    return raw, rate


def analyse(raw, rate):
    data = np.frombuffer(raw.read_bytes(), dtype='<i2').reshape(-1, 2).astype(np.float64)
    mono = data.mean(axis=1)
    win = int(rate)
    windows = []
    for i in range(0, len(mono) - win + 1, win):
        w = mono[i:i + win]
        spec = np.abs(np.fft.rfft(w * np.hanning(len(w))))
        freqs = np.fft.rfftfreq(len(w), 1.0 / rate)
        total = spec.sum()
        centroid = float((freqs * spec).sum() / total) if total > 0 else 0.0
        windows.append(dict(second=i // win, rms=round(float(np.sqrt((w ** 2).mean())), 1),
                            peak=int(np.abs(w).max()), centroid_hz=round(centroid, 1)))
    return dict(samples=len(data), seconds=round(len(data) / rate, 2),
                rms=round(float(np.sqrt((mono ** 2).mean())), 1), peak=int(np.abs(data).max()),
                sha256=hashlib.sha256(raw.read_bytes()).hexdigest(), windows=windows)


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--core', default='snes9x', choices=list(smoke.CORES))
    parser.add_argument('--core-path', type=pathlib.Path)
    parser.add_argument('--reference-rom', type=pathlib.Path)
    parser.add_argument('--hybrid-rom', required=True, type=pathlib.Path)
    parser.add_argument('--frames', type=int, default=1800)
    parser.add_argument('--input-script', type=pathlib.Path)
    parser.add_argument('--scratch', type=pathlib.Path, default=smoke.default_scratch())
    parser.add_argument('--json', type=pathlib.Path, help='write the report here')
    args = parser.parse_args()
    if smoke.inside_repo(args.scratch):
        raise SystemExit('scratch must be outside the repository')
    if args.core_path:
        smoke.CORES[args.core] = args.core_path
    args.scratch.mkdir(parents=True, exist_ok=True)
    out = args.scratch / 'audio' / args.core
    out.mkdir(parents=True, exist_ok=True)
    script = out / 'input.txt'
    script.write_text(args.input_script.read_text() if args.input_script else smoke.DEFAULT_SCRIPT)
    driver = smoke.build_driver(args.scratch)

    results = {}
    for label, rom in (('reference', args.reference_rom), ('hybrid', args.hybrid_rom)):
        if rom is None:
            continue
        raw, rate = run_driver(driver, args.core, rom, args.frames, script, out / label)
        results[label] = analyse(raw, rate)
        results[label]['sample_rate_hz'] = rate

    failures = []
    for label, r in results.items():
        act = [w for w in r['windows'] if w['rms'] > ACTIVE_WINDOW_RMS]
        cents = [w['centroid_hz'] for w in r['windows'] if w['rms'] > ACTIVE_WINDOW_RMS]
        r['active_windows'] = '%d/%d' % (len(act), len(r['windows']))
        r['centroid_range_hz'] = round(max(cents) - min(cents), 1) if cents else 0.0
        if r['rms'] < RMS_FLOOR:
            failures.append('%s: RMS %.1f below %.0f' % (label, r['rms'], RMS_FLOOR))
        if r['peak'] < PEAK_FLOOR:
            failures.append('%s: peak %d below %d' % (label, r['peak'], PEAK_FLOOR))
        if r['windows'] and len(act) / len(r['windows']) < MIN_ACTIVE_FRACTION:
            failures.append('%s: only %s one-second windows are non-silent' % (label, r['active_windows']))
        if r['centroid_range_hz'] < MIN_CENTROID_RANGE_HZ:
            failures.append('%s: spectrum does not change over time (centroid range %.1f Hz)'
                            % (label, r['centroid_range_hz']))
    identical = None
    if 'reference' in results and 'hybrid' in results:
        identical = results['reference']['sha256'] == results['hybrid']['sha256']
        if not identical:
            failures.append('reference and hybrid audio differ')
    for label, r in results.items():
        print('%-9s %s: %d samples (%.1f s @ %.0f Hz) rms=%.1f peak=%d active=%s centroid_range=%.0f Hz sha256=%s'
              % (label, args.core, r['samples'], r['seconds'], r['sample_rate_hz'], r['rms'], r['peak'],
                 r['active_windows'], r['centroid_range_hz'], r['sha256'][:16]))
        print('          per-second rms: ' + ' '.join('%g' % w['rms'] for w in r['windows']))
        print('          centroid (Hz):  ' + ' '.join('%g' % w['centroid_hz'] for w in r['windows']))
    if identical is not None:
        print('audio identical reference vs hybrid:', identical)
    print('AUDIO CHECK', 'PASSED' if not failures else 'FAILED: ' + '; '.join(failures))
    if args.json:
        args.json.write_text(json.dumps(dict(results=results, failures=failures), indent=1) + '\n')
    sys.exit(1 if failures else 0)


if __name__ == '__main__':
    main()
