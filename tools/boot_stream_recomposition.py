"""Recompose the boot stream from typed compression tokens and assembled RAM.

The optional extraction command records lengths/distances, never literal bytes.
Recomposition itself does not accept a reference ROM.
"""
import argparse
import json
import pathlib

import romio

ROOT = pathlib.Path(__file__).resolve().parent.parent
PLAN = ROOT / 'src/boot/encoded_boot_stream_plan.json'


def extract_plan(rom):
    offset = 0x77C00
    selector, reserved = rom[offset:offset+2]
    size = int.from_bytes(rom[offset+2:offset+4], 'big')
    shift = 5-selector
    distance_mask = (1 << shift)-1
    cursor, produced, runs = offset+4, 0, []
    while produced < size:
        token = rom[cursor]
        cursor += 1
        if token < 0x80:
            count = token+1
            runs.append(dict(literal_count=count))
            cursor += count
        else:
            count = ((token & 0x7F) >> shift)+3
            distance = ((token & distance_mask) << 8 | rom[cursor])+1
            cursor += 1
            runs.append(dict(match_count=count, distance=distance))
        produced += count
    if produced != size or selector not in range(6):
        raise ValueError('Invalid boot stream extent')
    return dict(format='som_boot_compression_token_plan_v1', source_offset=offset,
                destination_offset=0x8000, selector=selector, reserved=reserved,
                output_size=size, encoded_size=cursor-offset, runs=runs)


def recompose(plan, ram, ram_mask):
    selector = plan['selector']
    if plan['format'] != 'som_boot_compression_token_plan_v1' or selector not in range(6):
        raise ValueError('Unsupported compression plan')
    shift = 5-selector
    max_distance = 1 << (shift+8)
    image = bytearray((selector, plan['reserved']))
    image.extend(plan['output_size'].to_bytes(2, 'big'))
    mask = bytearray([1]) * 4
    metadata_bytes, literal_bytes = 4, 0
    cursor = plan['destination_offset']
    for run in plan['runs']:
        if 'literal_count' in run:
            count = run['literal_count']
            if set(run) != {'literal_count'} or not 1 <= count <= 128:
                raise ValueError('Invalid literal run')
            image.append(count-1)
            mask.append(1)
            metadata_bytes += 1
            for address in range(cursor, cursor+count):
                image.append(ram[address] if ram_mask[address] else 0xFF)
                mask.append(ram_mask[address])
                literal_bytes += ram_mask[address]
        else:
            count, distance = run['match_count'], run['distance']
            if (set(run) != {'match_count', 'distance'} or
                    not 3 <= count <= 3+(0x7F >> shift) or
                    not 1 <= distance <= max_distance or distance > cursor-plan['destination_offset']):
                raise ValueError('Invalid match run')
            encoded_distance = distance-1
            image.extend((0x80 | ((count-3) << shift) | (encoded_distance >> 8),
                          encoded_distance & 255))
            mask.extend((1, 1))
            metadata_bytes += 2
            for address in range(cursor, cursor+count):
                previous = address-distance
                if ram_mask[address] and ram_mask[previous] and ram[address] != ram[previous]:
                    raise ValueError(f'Compression plan disagrees with assembled RAM at {address:04X}')
        cursor += count
    if (cursor != plan['destination_offset']+plan['output_size'] or
            len(image) != plan['encoded_size']):
        raise ValueError('Compression plan size mismatch')
    return image, mask, dict(token_metadata_bytes=metadata_bytes,
                             assembled_literal_bytes=literal_bytes,
                             unknown_literal_bytes=len(image)-sum(mask),
                             encoded_size=len(image), output_size=plan['output_size'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom')
    args = parser.parse_args()
    PLAN.write_text(json.dumps(extract_plan(romio.load(args.rom)), indent=2)+'\n')


if __name__ == '__main__':
    main()
