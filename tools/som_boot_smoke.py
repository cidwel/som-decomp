#!/usr/bin/env python3
"""Stage 0 headless boot smoke test through installed libretro cores.

Runs N frames of a reference ROM and of the hybrid ROM (tools/som_assemble_rom.py) on each
core with the same scripted input, hashes every video frame and the audio stream, dumps
PNG screenshots, and reports whether the two ROMs behave identically.  The ROMs are read
from paths you give; outputs (traces, screenshots) go to a scratch directory, not the repo.

Input script: one "FIRST LAST BUTTON[,BUTTON...]" line per press, inclusive 0-based frames.
Buttons: B Y SELECT START UP DOWN LEFT RIGHT A X L R.
"""
import argparse
import json
import os
import pathlib
import struct
import subprocess
import sys
import tempfile
import zlib

HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parent
DRIVER_SOURCE = HERE / 'som_libretro_driver.c'
CORE_DIR = pathlib.Path.home() / '.var/app/org.libretro.RetroArch/config/retroarch/cores'
CORES = {'snes9x': CORE_DIR / 'snes9x_libretro.so', 'bsnes': CORE_DIR / 'bsnes_libretro.so'}

# Presses START on the title screen at frames 300, 360 and 420; later menu/gameplay steps
# are in docs/executable-stage0-20261017.md and are passed with --input-script.
DEFAULT_SCRIPT = '300 305 START\n360 365 START\n420 425 START\n'


def default_scratch():
    return pathlib.Path(os.environ.get('SOM_SCRATCH') or
                        pathlib.Path(tempfile.gettempdir()) / ('som-stage0-%s' % os.getuid()))


def inside_repo(path):
    try:
        path.resolve().relative_to(ROOT)
        return True
    except ValueError:
        return False


def write_png(ppm, png):
    data = ppm.read_bytes()
    magic, size, _, pixels = data.split(b'\n', 3)
    width, height = map(int, size.split())
    rows = b''.join(b'\x00' + pixels[y * width * 3:(y + 1) * width * 3] for y in range(height))

    def chunk(tag, body):
        return (struct.pack('>I', len(body)) + tag + body +
                struct.pack('>I', zlib.crc32(tag + body) & 0xFFFFFFFF))
    png.write_bytes(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', width, height, 8, 2, 0, 0, 0)) +
                    chunk(b'IDAT', zlib.compress(rows, 6)) + chunk(b'IEND', b''))


def build_driver(scratch):
    binary = scratch / 'som_libretro_driver'
    if not binary.exists() or binary.stat().st_mtime < DRIVER_SOURCE.stat().st_mtime:
        subprocess.run(['gcc', '-O2', '-Wall', '-o', str(binary), str(DRIVER_SOURCE), '-ldl'], check=True)
    return binary


def run(driver, core, rom, frames, script, directory, shot_frames):
    directory.mkdir(parents=True, exist_ok=True)
    trace = directory / 'trace.txt'
    proc = subprocess.run([str(driver), str(CORES[core]), str(rom), str(frames), str(trace),
                           str(script), str(directory), ','.join(map(str, shot_frames))],
                          capture_output=True, text=True)
    if proc.returncode:
        raise SystemExit('driver failed for %s %s: %s' % (core, rom, proc.stderr))
    lines = trace.read_text().split('\n')[:-1]
    for ppm in directory.glob('*.ppm'):
        write_png(ppm, ppm.with_suffix('.png'))
        ppm.unlink()
    return lines, proc.stderr.splitlines()[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--reference-rom', required=True, type=pathlib.Path,
                        help='the original ROM (control)')
    parser.add_argument('--hybrid-rom', required=True, type=pathlib.Path,
                        help='output of tools/som_assemble_rom.py')
    parser.add_argument('--cores', nargs='+', default=list(CORES), choices=list(CORES))
    parser.add_argument('--frames', type=int, default=1800)
    parser.add_argument('--input-script', type=pathlib.Path, help='input script file (default: START presses)')
    parser.add_argument('--shots', default='299,599,899,1199,1799',
                        help='comma separated frames to save as PNG for each run')
    parser.add_argument('--scratch', type=pathlib.Path, default=default_scratch())
    parser.add_argument('--tag', default='smoke')
    args = parser.parse_args()

    if inside_repo(args.scratch):
        raise SystemExit('Refusing to write screenshots/traces inside the repository')
    for core in args.cores:
        if not CORES[core].exists():
            raise SystemExit('Missing libretro core: %s' % CORES[core])
    args.scratch.mkdir(parents=True, exist_ok=True)
    out = args.scratch / args.tag
    out.mkdir(parents=True, exist_ok=True)
    script = out / 'input.txt'
    script.write_text(args.input_script.read_text() if args.input_script else DEFAULT_SCRIPT)
    shots = [int(f) for f in args.shots.split(',') if f]
    driver = build_driver(args.scratch)

    results, all_equal = {}, True
    for core in args.cores:
        traces = {}
        for label, rom in (('reference', args.reference_rom), ('hybrid', args.hybrid_rom)):
            traces[label], core_name = run(driver, core, rom, args.frames, script,
                                           out / core / label, shots)
        video = [t.split()[1] for t in traces['reference']]
        video_h = [t.split()[1] for t in traces['hybrid']]
        identical = traces['reference'] == traces['hybrid']
        mismatch = next((i for i, (a, b) in enumerate(zip(traces['reference'], traces['hybrid'])) if a != b), None)
        distinct = len(set(video))
        results[core] = dict(
            core=core_name, frames=len(video), video_hashes_equal=video == video_h,
            video_and_audio_hashes_equal=identical, first_mismatch_frame=mismatch,
            distinct_video_frames=distinct, final_video_hash=video[-1],
            final_audio_hash=traces['reference'][-1].split()[2],
            reference_trace=str(out / core / 'reference' / 'trace.txt'),
            screenshots=str(out / core / 'hybrid'))
        all_equal &= identical
        print('%-7s %-22s frames=%d identical(video+audio)=%s distinct_video=%d final=%s'
              % (core, core_name, len(video), identical, distinct, video[-1]))
    report = dict(frames=args.frames, input_script=script.read_text(), results=results,
                  hybrid_boots_identically=all_equal)
    (out / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print('hybrid boots identically on all cores:', all_equal, '| report:', out / 'report.json')
    sys.exit(0 if all_equal else 1)


if __name__ == '__main__':
    main()
