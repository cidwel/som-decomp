#!/usr/bin/env python3
"""Write the asset and literal-data sources of src/ from your own ROM.

usage: extract_rom_sources.py ROM [--templates data/rom_sources.json.gz] [--check]

The repository carries no ROM bytes. Graphics, audio, text, map bodies and other
literal data blocks are stored as templates whose numeric operands are blanks;
this tool fills them from a ROM whose SHA-256 matches the supported image and
writes the .s files at the paths listed in src/manifest.json. --check compares
the generated text with files already on disk instead of writing.
"""
import argparse, gzip, hashlib, json, pathlib, re

ROOT = pathlib.Path(__file__).resolve().parent.parent
SLOT = re.compile('\x01([bw])(\\d+)([ul])\x01')


def render(template, data):
    pos = 0

    def fill(m):
        nonlocal pos
        kind, width, case = m.group(1), int(m.group(2)), m.group(3)
        if kind == 'b':
            value, pos = data[pos], pos + 1
        else:
            value, pos = data[pos] | data[pos + 1] << 8, pos + 2
        text = '$%0*X' % (width, value)
        return text if case == 'u' else text.lower()

    text = SLOT.sub(fill, template)
    if pos != len(data):
        raise ValueError('template consumed %d of %d bytes' % (pos, len(data)))
    return text


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('rom')
    parser.add_argument('--templates', default=str(ROOT / 'data/rom_sources.json.gz'))
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    rom = pathlib.Path(args.rom).read_bytes()
    if len(rom) % 0x8000 == 0x200:
        rom = rom[0x200:]
    with gzip.open(args.templates, 'rt') as f:
        spec = json.load(f)
    sha = hashlib.sha256(rom).hexdigest()
    if sha != spec['rom_sha256']:
        raise SystemExit('ROM SHA-256 %s does not match the supported image %s' % (sha, spec['rom_sha256']))
    written = differ = 0
    for entry in spec['sources']:
        offset = int(entry['address'], 16) & 0x3FFFFF
        text = render(entry['template'], rom[offset:offset + entry['size']])
        path = ROOT / entry['source']
        if args.check:
            if not path.exists() or path.read_text() != text:
                differ += 1
            continue
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        written += 1
    if args.check:
        print('%d sources checked, %d differ' % (len(spec['sources']), differ))
        raise SystemExit(1 if differ else 0)
    print('%d sources written from the ROM' % written)


if __name__ == '__main__':
    main()
