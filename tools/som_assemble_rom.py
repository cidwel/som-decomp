#!/usr/bin/env python3
"""Stage 0 composer: assemble the ROM from src/ and fill the unknown gaps from the user's own ROM.

The source build (tools/build_recovered_rom.py) never reads a ROM; it yields a sparse
image plus a per-byte known mask.  This tool then copies, from a ROM supplied at run
time, only the bytes whose mask is 0, and reports exactly how many bytes came from each
side.  Every source-built byte is also compared with the user's ROM, and the final image
must hash to the expected original.  The result is a HYBRID image: it is not source-only.

Nothing is written inside the repository; the output defaults to a scratch directory.
"""
import argparse
import hashlib
import json
import os
import pathlib
import shutil
import sys
import tempfile

HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))

ROM_SIZE = 0x200000
EXPECTED_SHA256 = '4c15013131351e694e05f22e38bb1b3e4031dedac77ec75abecebe8520d82d5f'
EXPECTED_CHECKSUM = 0x51FC
EXPECTED_COMPLEMENT = 0xAE03
CHECKSUM_FIELD = 0xFFDC  # complement word, then checksum word (HiROM header at 0xFFC0)
CC65_BIN = pathlib.Path(os.environ.get('CC65_BIN')
                        or os.path.dirname(shutil.which('ca65') or '')
                        or pathlib.Path.home() / '.local/state/som-decomp/cc65-restored-20261016/runtime/usr/bin')


def internal_checksum_problems(image):
    """Return a list of problems with the SNES internal checksum fields of a 2 MiB image."""
    if len(image) != ROM_SIZE:
        return ['image has %d bytes, expected %d' % (len(image), ROM_SIZE)]
    complement = image[CHECKSUM_FIELD] | image[CHECKSUM_FIELD + 1] << 8
    checksum = image[CHECKSUM_FIELD + 2] | image[CHECKSUM_FIELD + 3] << 8
    problems = []
    if checksum != EXPECTED_CHECKSUM or complement != EXPECTED_COMPLEMENT:
        problems.append('header fields are %04X/%04X, expected %04X/%04X (checksum/complement)'
                        % (checksum, complement, EXPECTED_CHECKSUM, EXPECTED_COMPLEMENT))
    if (checksum ^ complement) != 0xFFFF:
        problems.append('checksum %04X is not the complement of %04X' % (checksum, complement))
    computed = sum(image) & 0xFFFF  # fields included, as the standard checksum does
    if computed != checksum:
        problems.append('computed sum %04X != stored checksum %04X' % (computed, checksum))
    return problems


def default_scratch():
    return pathlib.Path(os.environ.get('SOM_SCRATCH') or
                        pathlib.Path(tempfile.gettempdir()) / ('som-stage0-%s' % os.getuid()))


def inside_repo(path):
    try:
        path.resolve().relative_to(ROOT)
        return True
    except ValueError:
        return False


def load_user_rom(path):
    data = pathlib.Path(path).read_bytes()
    stripped = 0
    if len(data) == ROM_SIZE + 512:
        data, stripped = data[512:], 512
    if len(data) != ROM_SIZE:
        raise SystemExit('User ROM has %d bytes; expected %d (headerless) or +512 copier header'
                         % (len(data), ROM_SIZE))
    return data, stripped


def make_manifest(drop_overlaps, scratch):
    """Return the manifest path to build from, dropping blocks inside the boot stream if asked."""
    import build_recovered_rom as brr
    manifest_path = ROOT / 'src/manifest.json'
    if not drop_overlaps:
        return manifest_path, []
    manifest = json.loads(manifest_path.read_text())
    dropped = [b['source'] for b in brr.boot_stream_overlaps(manifest)]
    if not dropped:
        return manifest_path, []
    manifest['blocks'] = [b for b in manifest['blocks'] if b['source'] not in set(dropped)]
    path = scratch / 'manifest_without_boot_overlaps.json'
    path.write_text(json.dumps(manifest))
    return path, dropped


def source_build(scratch, ca65, ld65, drop_overlaps):
    import build_recovered_rom as brr
    manifest_path, dropped = make_manifest(drop_overlaps, scratch)
    out = scratch / 'build'
    try:
        report = brr.build(out, str(ca65), str(ld65), manifest_path)
    except ValueError as error:
        if 'overlaps manifest ROM sources' in str(error) and not drop_overlaps:
            raise SystemExit('%s\nRe-run with --drop-boot-overlaps to exclude those blocks '
                             '(their bytes are then filled from the user ROM and counted as such).'
                             % error)
        raise
    return out, dropped, report


def gap_list(mask):
    gaps, start = [], None
    for offset, known in enumerate(bytes(mask) + b'\x01'):
        if not known and start is None:
            start = offset
        elif known and start is not None:
            gaps.append((start, offset - start))
            start = None
    return gaps


def compose(partial, mask, user_rom):
    image = bytearray(partial)
    mismatches = [i for i in range(len(image)) if mask[i] and image[i] != user_rom[i]]
    for start, size in gap_list(mask):
        image[start:start + size] = user_rom[start:start + size]
    return bytes(image), mismatches


def bank_summary(gaps):
    banks = {}
    for start, size in gaps:
        key = '%02X' % (0xC0 + (start >> 16))
        banks[key] = banks.get(key, 0) + size
    return banks


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--user-rom', required=True, type=pathlib.Path,
                        help='your own legally obtained ROM (headerless, or with a 512-byte header)')
    parser.add_argument('--output', type=pathlib.Path,
                        help='hybrid .sfc path (default: <scratch>/som_hybrid.sfc)')
    parser.add_argument('--scratch', type=pathlib.Path, default=default_scratch(),
                        help='scratch directory (default: $SOM_SCRATCH or /tmp/som-stage0-UID)')
    parser.add_argument('--ca65', type=pathlib.Path, default=CC65_BIN / 'ca65')
    parser.add_argument('--ld65', type=pathlib.Path, default=CC65_BIN / 'ld65')
    parser.add_argument('--drop-boot-overlaps', action='store_true',
                        help='exclude manifest blocks that overlap the compressed boot stream')
    parser.add_argument('--reuse-build', type=pathlib.Path,
                        help='skip assembling; use rom.partial.bin/rom.known-mask.bin from this dir')
    parser.add_argument('--expected-sha256', default=EXPECTED_SHA256)
    args = parser.parse_args()

    args.scratch.mkdir(parents=True, exist_ok=True)
    output = args.output or args.scratch / 'som_hybrid.sfc'
    if inside_repo(output) or inside_repo(args.scratch):
        raise SystemExit('Refusing to write ROM data inside the repository: ' + str(output))

    user_rom, stripped = load_user_rom(args.user_rom)
    user_sha = hashlib.sha256(user_rom).hexdigest()
    if user_sha != args.expected_sha256:
        raise SystemExit('User ROM sha256 %s differs from the expected original %s'
                         % (user_sha, args.expected_sha256))

    dropped = []
    if args.reuse_build:
        build_dir = args.reuse_build
    else:
        build_dir, dropped, _ = source_build(args.scratch, args.ca65, args.ld65,
                                             args.drop_boot_overlaps)
    partial = (build_dir / 'rom.partial.bin').read_bytes()
    mask = (build_dir / 'rom.known-mask.bin').read_bytes()
    if len(partial) != ROM_SIZE or len(mask) != ROM_SIZE:
        raise SystemExit('Unexpected partial image size')

    image, mismatches = compose(partial, mask, user_rom)
    if mismatches:
        raise SystemExit('%d source-built bytes differ from the user ROM (first at 0x%06X); '
                         'refusing to write' % (len(mismatches), mismatches[0]))
    sha = hashlib.sha256(image).hexdigest()
    if sha != args.expected_sha256:
        raise SystemExit('Hybrid sha256 %s != expected %s' % (sha, args.expected_sha256))

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(image)
    gaps = gap_list(mask)
    from_source = sum(mask)
    report = dict(
        output=str(output), sha256=sha, sha256_matches_original=True,
        rom_size=ROM_SIZE, bytes_from_source=from_source,
        bytes_from_user_rom=ROM_SIZE - from_source,
        percent_from_source=round(100 * from_source / ROM_SIZE, 3),
        gaps=len(gaps), gap_bytes_by_bank=bank_summary(gaps),
        largest_gaps=[dict(offset='0x%06X' % s, address='%02X:%04X' % (0xC0 + (s >> 16), s & 0xFFFF),
                           size=n) for s, n in sorted(gaps, key=lambda g: -g[1])[:10]],
        source_bytes_compared_with_user_rom=from_source, source_bytes_mismatching=0,
        user_rom_copier_header_stripped=stripped,
        dropped_boot_overlap_blocks=dropped, hybrid=True)
    report_path = output.with_suffix('.report.json')
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    print('Hybrid ROM: %s' % output)
    print('  from source (assembled by ca65/ld65): %9d bytes (%.3f %%)'
          % (from_source, report['percent_from_source']))
    print('  from the user ROM (%d gaps):          %9d bytes' % (len(gaps), ROM_SIZE - from_source))
    print('  source bytes compared with user ROM: %d, mismatching: 0' % from_source)
    print('  sha256 %s == original' % sha)
    print('  report: %s' % report_path)


if __name__ == '__main__':
    main()
