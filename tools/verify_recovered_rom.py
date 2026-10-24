"""Compare a completed sparse build with ROM/decoded references after assembly."""
import argparse
import hashlib
import json
import pathlib

import romio
import decoded_source_references


def verify(rom, directory):
    report = json.loads((directory / 'build.json').read_text())
    if report['reference_rom_used']:
        raise ValueError('Build was not reference-free')
    references = {'rom': rom, **decoded_source_references.images(rom, report)}
    results = {}
    for name, artifact in report['artifacts'].items():
        image = (directory / artifact['image']).read_bytes()
        mask = (directory / artifact['mask']).read_bytes()
        if (hashlib.sha256(image).hexdigest() != artifact['image_sha256'] or
                hashlib.sha256(mask).hexdigest() != artifact['mask_sha256']):
            raise ValueError(f'Build artifact hash mismatch: {name}')
        reference = references[name]
        if len(image) != len(mask) or len(image) != len(reference):
            raise ValueError(f'Build artifact size mismatch: {name}')
        if any(known not in (0, 1) for known in mask):
            raise ValueError(f'Invalid occupancy mask: {name}')
        for offset, known in enumerate(mask):
            if known and image[offset] != reference[offset]:
                raise ValueError(f'Reconstructed byte mismatch: {name}+{offset:06X}')
        results[name] = dict(matching_bytes=sum(mask), image_sha256=artifact['image_sha256'],
                             mask_sha256=artifact['mask_sha256'])
    return dict(verified=True, rom_sha256=hashlib.sha256(rom).hexdigest(),
                build_report_sha256=hashlib.sha256((directory / 'build.json').read_bytes()).hexdigest(),
                reconstructed_rom_bytes=results['rom']['matching_bytes'],
                complete_rom_rebuild=report['complete_rom_rebuild'], references=results)


def static_check(manifest_path=None):
    """Cheap pre-build gate: no manifest ROM block may cover a stream byte that the recomposition produces."""
    import build_recovered_rom
    path = build_recovered_rom.ROOT / 'src/manifest.json' if manifest_path is None else pathlib.Path(manifest_path)
    manifest = json.loads(path.read_text())
    clashes = build_recovered_rom.boot_stream_known_clashes(manifest)
    if clashes:
        raise ValueError('Compressed boot stream overlaps manifest ROM sources: ' +
                         ', '.join(block['source'] for block in clashes))
    return dict(boot_stream_known_clashes=0,
                boot_stream_unknown_literal_blocks=len(build_recovered_rom.boot_stream_overlaps(manifest)))


def fresh_check(directory, ca65, ld65):
    """Rebuild from scratch (no persistent baseline) and require the same artifacts as `directory`.

    Persistent incremental builds only OR new blocks into earlier images and never re-run the boot-stream
    recomposition, so conflicts introduced by later manifest rows stay invisible to `verify`.
    """
    import tempfile
    import build_recovered_rom
    expected = json.loads((directory / 'build.json').read_text())
    with tempfile.TemporaryDirectory(prefix='som-fresh-build-') as temporary:
        fresh = build_recovered_rom.build(pathlib.Path(temporary), ca65, ld65)
    if fresh['manifest_sha256'] != expected['manifest_sha256']:
        raise ValueError('Persistent build was made from another manifest than the live one')
    for name, artifact in fresh['artifacts'].items():
        old = expected['artifacts'].get(name)
        if old is None or any(old[key] != artifact[key] for key in ('image_sha256', 'mask_sha256')):
            raise ValueError(f'Fresh build differs from the persistent build: {name}')
    if set(expected['artifacts']) != set(fresh['artifacts']):
        raise ValueError('Fresh build has different artifacts than the persistent build')
    return dict(fresh_build_matches_persistent=True, fresh_reconstructed_rom_bytes=fresh['reconstructed_rom_bytes'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom')
    parser.add_argument('--build', type=pathlib.Path, required=True)
    parser.add_argument('--json', type=pathlib.Path)
    parser.add_argument('--static', action='store_true', help='check the live manifest against the boot stream first')
    parser.add_argument('--fresh', action='store_true',
                        help='also rebuild from scratch and require identical artifacts (about 3 minutes)')
    parser.add_argument('--ca65', default='ca65')
    parser.add_argument('--ld65', default='ld65')
    args = parser.parse_args()
    if args.static or args.fresh:
        static_check()
    report = verify(romio.load(args.rom), args.build)
    if args.fresh:
        report['fresh_build'] = fresh_check(args.build, args.ca65, args.ld65)
    text = json.dumps(report, indent=2) + '\n'
    if args.json:
        args.json.write_text(text)
    print(text, end='')


if __name__ == '__main__':
    main()
