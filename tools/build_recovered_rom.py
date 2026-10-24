"""Assemble recovered sources into a sparse ROM image without reading a ROM.

Unknown bytes use FF; the accompanying mask is authoritative. Decoded boot
sources are emitted separately and do not count as reconstructed ROM bytes.
"""
import argparse
import hashlib
import json
import pathlib
import subprocess
import tempfile

import verify_source
import boot_stream_recomposition
import decoded_source_references

ROOT = pathlib.Path(__file__).resolve().parent.parent
ROM_SIZE = 0x200000


def assemble(block, directory, ca65, ld65):
    source = ROOT / block['source']
    if block.get('architecture', '65816') == 'spc700':
        return verify_source.spc_audio_initialization_source.assemble(
            int(block['assembly_address'], 16), verify_source.spc_source(source.read_text()))
    address = int(block['address'], 16) & 0xFFFF
    config = directory / 'block.cfg'
    obj = directory / 'block.o'
    binary = directory / 'block.bin'
    config.write_text(
        'MEMORY { PART: start = $%04X, size = $%04X, file = %%O; }\n'
        'SEGMENTS { CODE: load = PART, type = ro, optional = yes; '
        'RODATA: load = PART, type = ro, optional = yes; }\n' % (address, block['size']))
    subprocess.run([ca65, '-I', str(ROOT), str(source), '-o', str(obj)], check=True)
    subprocess.run([ld65, '-C', str(config), str(obj), '-o', str(binary)], check=True)
    return binary.read_bytes()


def boot_stream_overlaps(manifest):
    """Manifest ROM blocks that intersect the compressed boot stream (same rule as build())."""
    plan = json.loads(boot_stream_recomposition.PLAN.read_text())
    start, end = plan['source_offset'], plan['source_offset'] + plan['encoded_size']
    result = []
    for block in manifest['blocks']:
        if block['reference'] != 'rom':
            continue
        offset = int(block['address'], 16) & 0x3FFFFF
        if offset < end and offset + block['size'] > start:
            result.append(block)
    return result


def decoded_known_mask(manifest, reference):
    mask = bytearray(0x10000)
    for block in manifest['blocks']:
        if block['reference'] == reference:
            start = int(block['address'], 16) & 0xFFFF
            mask[start:start + block['size']] = b'\x01' * block['size']
    return mask


def boot_stream_known_clashes(manifest):
    """Manifest ROM blocks that cover a stream byte the recomposition itself produces.

    A ROM block may cover only stream positions that the recomposition cannot know (encoded literals whose decoded
    source is still missing); anything else would be a second owner of a recomposed byte.
    """
    plan = json.loads(boot_stream_recomposition.PLAN.read_text())
    start = plan['source_offset']
    _, known, _ = boot_stream_recomposition.recompose(
        plan, bytearray(0x10000), decoded_known_mask(manifest, 'decoded_boot_program'))
    result = []
    for block in boot_stream_overlaps(manifest):
        offset = int(block['address'], 16) & 0x3FFFFF
        lo, hi = max(offset, start) - start, min(offset + block['size'], start + len(known)) - start
        if any(known[lo:hi]):
            result.append(block)
    return result


def gaps(mask):
    result = []
    start = None
    for offset, known in enumerate(mask + b'\x01'):
        if not known and start is None:
            start = offset
        elif known and start is not None:
            result.append(dict(offset=start, size=offset-start))
            start = None
    return result


def recompose_resources(manifest, images, masks):
    reports = {}
    for name, resource in decoded_source_references.declarations(manifest).items():
        if not resource.get('recompose', False):
            continue
        path = ROOT / resource['plan']
        if hashlib.sha256(path.read_bytes()).hexdigest() != resource['plan_sha256']:
            raise ValueError('Decoded resource compression plan changed')
        plan = json.loads(path.read_text())
        if (plan['source_offset'] != resource['source'] & 0x3FFFFF or
                plan['destination_offset'] != resource['destination'] & 0xFFFF or
                plan['output_size'] != resource['output_size']):
            raise ValueError('Compression plan differs from the declared decoded resource')
        encoded, mask, info = boot_stream_recomposition.recompose(plan, images[name], masks[name])
        opaque = resource.get('opaque_header_offsets', [])
        if opaque != [1]:
            raise ValueError('Resource recomposition must exclude the uninterpreted header byte')
        mask[1] = 0
        offset = plan['source_offset']
        if offset < 0 or offset + len(encoded) > len(images['rom']):
            raise ValueError('Compressed resource exceeds the ROM image')
        gain = 0
        for index, known in enumerate(mask):
            if not known:
                continue
            address = offset + index
            if masks['rom'][address] and images['rom'][address] != encoded[index]:
                raise ValueError('Compressed resource conflicts with another ROM source')
            gain += not masks['rom'][address]
            images['rom'][address], masks['rom'][address] = encoded[index], 1
        reports[name] = info | dict(token_metadata_bytes=info['token_metadata_bytes'] - len(opaque),
                                    excluded_metadata_bytes=len(opaque),
                                    unknown_encoded_bytes=len(mask) - sum(mask),
                                    plan=resource['plan'], plan_sha256=resource['plan_sha256'],
                                    source_offset=offset, opaque_header_offsets=opaque,
                                    known_encoded_bytes=sum(mask), added_rom_bytes=gain,
                                    terminal_lookahead_included=False)
    return reports


def build(output, ca65, ld65,manifest_path=None):
    manifest_path = ROOT / 'src/manifest.json' if manifest_path is None else pathlib.Path(manifest_path)
    manifest = json.loads(manifest_path.read_text())
    resources = decoded_source_references.declarations(manifest)
    images = {'rom': bytearray([0xFF]) * ROM_SIZE,
              'decoded_boot_program': bytearray([0xFF]) * 0x10000}
    images.update({name: bytearray([0xFF]) * 0x10000 for name in resources})
    masks = {name: bytearray(len(image)) for name, image in images.items()}
    blocks = []
    with tempfile.TemporaryDirectory(prefix='som-recovered-build-') as temporary:
        for block in manifest['blocks']:
            decoded_source_references.check_block(block, resources)
            rebuilt = assemble(block, pathlib.Path(temporary), ca65, ld65)
            if len(rebuilt) != block['size']:
                raise ValueError(f"Incorrect assembled size: {block['source']}")
            reference = block['reference']
            image, mask = images[reference], masks[reference]
            offset = int(block['address'], 16) & (0x3FFFFF if reference == 'rom' else 0xFFFF)
            end = offset + len(rebuilt)
            if end > len(image) or any(mask[offset:end]):
                raise ValueError(f"Out-of-range or overlapping source: {block['source']}")
            image[offset:end] = rebuilt
            mask[offset:end] = b'\x01' * len(rebuilt)
            blocks.append(dict(source=block['source'], reference=reference, offset=offset,
                               size=len(rebuilt), source_sha256=hashlib.sha256(
                                   (ROOT / block['source']).read_bytes()).hexdigest(),
                               assembled_sha256=hashlib.sha256(rebuilt).hexdigest()))
    plan_path = boot_stream_recomposition.PLAN
    plan = json.loads(plan_path.read_text())
    compressed, compressed_mask, compression = boot_stream_recomposition.recompose(
        plan, images['decoded_boot_program'], masks['decoded_boot_program'])
    offset = plan['source_offset']
    end = offset+len(compressed)
    if end > ROM_SIZE:
        raise ValueError('Compressed boot stream exceeds the ROM image')
    if any(known and masks['rom'][offset + index] for index, known in enumerate(compressed_mask)):
        raise ValueError('Compressed boot stream overlaps manifest ROM sources: ' + ', '.join(
            block['source'] for block in boot_stream_known_clashes(manifest)))
    for index, known in enumerate(compressed_mask):
        if known:
            images['rom'][offset + index], masks['rom'][offset + index] = compressed[index], 1
    compression.update(source=str(plan_path.relative_to(ROOT)),
                       source_sha256=hashlib.sha256(plan_path.read_bytes()).hexdigest(),
                       source_offset=offset)
    resource_compression = recompose_resources(manifest, images, masks)
    output.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for name, image in images.items():
        image_name = name + '.partial.bin'
        mask_name = name + '.known-mask.bin'
        (output / image_name).write_bytes(image)
        (output / mask_name).write_bytes(masks[name])
        artifacts[name] = dict(image=image_name, mask=mask_name,
                               image_sha256=hashlib.sha256(image).hexdigest(),
                               mask_sha256=hashlib.sha256(masks[name]).hexdigest(),
                               reconstructed_bytes=sum(masks[name]), gaps=gaps(masks[name]))
    report = dict(manifest_sha256=hashlib.sha256(manifest_path.read_bytes()).hexdigest(),
                  reference_rom_used=False, complete_rom_rebuild=all(masks['rom']),
                  rom_size=ROM_SIZE, reconstructed_rom_bytes=sum(masks['rom']),
                  reconstructed_rom_percent=100 * sum(masks['rom']) / ROM_SIZE,
                  unknown_rom_bytes=ROM_SIZE-sum(masks['rom']), artifacts=artifacts, blocks=blocks)
    if resources:
        report['decoded_resources'] = manifest['decoded_resources']
    report['boot_stream_recomposition'] = compression
    if resource_compression:
        report['decoded_resource_recomposition'] = resource_compression
    (output / 'build.json').write_text(json.dumps(report, indent=2) + '\n')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=pathlib.Path, required=True)
    parser.add_argument('--ca65', default='ca65')
    parser.add_argument('--ld65', default='ld65')
    args = parser.parse_args()
    report = build(args.output, args.ca65, args.ld65)
    print(json.dumps({key: value for key, value in report.items()
                      if key not in ('artifacts', 'blocks')}, indent=2))


if __name__ == '__main__':
    main()
