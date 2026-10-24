#!/usr/bin/env python3
"""Draw the ROM as a treemap coloured by how far each byte has been taken.

usage: rom_progress_treemap.py [--svg docs/images/rom-progress.svg] [--json data/rom_progress_summary.json]

Every physical ROM byte gets one owner from src/manifest.json and
data/decomp_c_status.json: code with verified C, code as matching assembly only,
typed data, literal data of a known kind (graphics, audio, text, maps), literal
data not classified yet, or bytes rebuilt by the boot-stream recomposition.
Area is proportional to bytes. Needs no ROM.
"""
import argparse, collections, json, math, pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
ROM_SIZE = 0x200000

CATEGORIES = [
    ('c', 'Code with verified C', '#2e9e5b'),
    ('asm', 'Code as matching assembly', '#8fcf6a'),
    ('typed', 'Typed data tables', '#4a90d9'),
    ('asset', 'Assets: graphics, audio, text, maps', '#e0a43a'),
    ('unclassified', 'Literal data, not classified yet', '#b9b9b9'),
    ('recomposed', 'Compressed boot program, rebuilt by the build', '#9b7fd1'),
]

ASSET_GROUPS = [
    ('audio', 'Audio'), ('text', 'Text'), ('graphics', 'Graphics'), ('tile', 'Graphics'),
    ('palette', 'Palettes'), ('colour', 'Palettes'), ('map', 'Maps'), ('scene', 'Scenes'),
    ('mode7', 'Scenes'), ('menu', 'Menus'), ('dialogue', 'Menus'), ('boss', 'Bosses'),
]
TYPED_GROUPS = [
    ('map', 'Maps'), ('event', 'Events'), ('boss', 'Bosses'), ('monster', 'Monsters'),
    ('actor', 'Actors'), ('hero', 'Heroes'), ('menu', 'Menus'), ('ui_', 'Menus'),
    ('audio', 'Audio'), ('spc', 'Audio'), ('spell', 'Spells'), ('weapon', 'Items'),
    ('armor', 'Items'), ('item', 'Items'), ('boot', 'Boot'), ('ai', 'AI'),
]


def physical(address):
    value = int(address, 16)
    bank = value >> 16
    if bank in (0x7E, 0x7F) or (bank < 0x40 and value & 0xFFFF < 0x8000):
        return None
    return value & 0x3FFFFF


def group(text, table, default):
    text = text.lower()
    for key, name in table:
        if key in text:
            return name
    return default


def classify(manifest):
    owner = [None] * ROM_SIZE
    for b in manifest['blocks']:
        if b['reference'] != 'rom':
            continue
        start = physical(b['address'])
        if start is None:
            continue
        status, etype = str(b.get('analysis_status') or ''), str(b.get('element_type') or '')
        name = pathlib.Path(b['source']).stem
        if b.get('kind', 'code') != 'data':
            cat, grp = 'asm', 'bank %02X' % (0xC0 | start >> 16)
        elif etype == 'unclassified_rom_bytes':
            cat, grp = 'unclassified', 'bank %02X' % (0xC0 | start >> 16)
        elif status.startswith('byte_exact_literal') or etype in (
                'tile_word_bitstream', 'rle_row_stream', 'palette_set_7x15_u16'):
            cat, grp = 'asset', group(etype + ' ' + name, ASSET_GROUPS, 'Other assets')
        else:
            cat, grp = 'typed', group(name + ' ' + etype, TYPED_GROUPS, 'Other tables')
        for i in range(start, start + b['size']):
            owner[i] = (cat, grp)
    return owner


def mark_c(owner, status):
    for r in status['routines'].values():
        start = physical(r['addr'])
        if start is None or r['status'] != 'verified':
            continue
        sub = pathlib.Path(r['file']).parent.name.replace('_', ' ')
        for i in range(start, start + r['bytes']):
            if owner[i] and owner[i][0] == 'asm':
                owner[i] = ('c', sub)


def squarify(items, x, y, w, h):
    """items: list of (size, payload), sorted descending; returns (payload, x, y, w, h)."""
    out, items = [], [it for it in items if it[0] > 0]
    total = sum(s for s, _ in items)
    if not items or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    rects = [(s * scale, p) for s, p in items]

    def worst(row, side):
        area = sum(a for a, _ in row)
        return max(max(side * side * a / (area * area), area * area / (side * side * a)) for a, _ in row)

    while rects:
        side = min(w, h)
        row = [rects.pop(0)]
        while rects and worst(row + [rects[0]], side) <= worst(row, side):
            row.append(rects.pop(0))
        area = sum(a for a, _ in row)
        thick = area / side
        pos = 0.0
        for a, p in row:
            length = a / thick
            if w >= h:
                out.append((p, x, y + pos, thick, length))
            else:
                out.append((p, x + pos, y, length, thick))
            pos += length
        if w >= h:
            x, w = x + thick, w - thick
        else:
            y, h = y + thick, h - thick
    return out


def esc(text):
    return text.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')


def svg(counts, width=960, height=600, legend_h=120):
    colours = {k: c for k, _, c in CATEGORIES}
    labels = {k: t for k, t, _ in CATEGORIES}
    parts = ['<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 %d %d" width="%d" height="%d" '
             'font-family="Helvetica,Arial,sans-serif">' % (width, height + legend_h, width, height + legend_h),
             '<rect width="100%" height="100%" fill="#ffffff"/>']
    top = sorted(((sum(g.values()), k) for k, g in counts.items()), reverse=True)
    for cat, cx, cy, cw, ch in squarify(top, 0, 0, width, height):
        groups = sorted(((n, g) for g, n in counts[cat].items()), reverse=True)
        for grp, gx, gy, gw, gh in squarify(groups, cx + 2, cy + 2, cw - 4, ch - 4):
            parts.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="%s" stroke="#ffffff" stroke-width="1">'
                         '<title>%s / %s: %s bytes</title></rect>'
                         % (gx, gy, gw, gh, colours[cat], esc(labels[cat]), esc(grp), format(counts[cat][grp], ',')))
            if gw > 46 and gh > 16:
                size = 11 if gw > 80 and gh > 22 else 9
                parts.append('<text x="%.1f" y="%.1f" font-size="%d" fill="#1b1b1b">%s</text>'
                             % (gx + 4, gy + size + 2, size, esc(grp)))
        parts.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="none" stroke="#333333" stroke-width="2"/>'
                     % (cx + 1, cy + 1, cw - 2, ch - 2))
    y = height + 18
    for i, (k, text, colour) in enumerate(CATEGORIES):
        n = sum(counts.get(k, {}).values())
        lx, ly = 10 + (i % 2) * (width // 2), y + (i // 2) * 32
        parts.append('<rect x="%d" y="%d" width="18" height="18" fill="%s"/>' % (lx, ly, colour))
        parts.append('<text x="%d" y="%d" font-size="14" fill="#1b1b1b">%s: %s bytes (%.1f %%)</text>'
                     % (lx + 26, ly + 14, esc(text), format(n, ','), 100.0 * n / ROM_SIZE))
    parts.append('</svg>')
    return '\n'.join(parts) + '\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--svg', default=str(ROOT / 'docs/images/rom-progress.svg'))
    parser.add_argument('--json', default=str(ROOT / 'data/rom_progress_summary.json'))
    args = parser.parse_args()
    manifest = json.loads((ROOT / 'src/manifest.json').read_text())
    status = json.loads((ROOT / 'data/decomp_c_status.json').read_text())
    owner = classify(manifest)
    mark_c(owner, status)
    counts = collections.defaultdict(collections.Counter)
    for o in owner:
        cat, grp = o if o else ('recomposed', 'boot stream')
        counts[cat][grp] += 1
    pathlib.Path(args.svg).write_text(svg(counts))
    routines = list(status['routines'].values())
    verified = [r for r in routines if r['status'] == 'verified']
    summary = dict(
        rom_size=ROM_SIZE,
        bytes={k: sum(counts.get(k, {}).values()) for k, _, _ in CATEGORIES},
        groups={k: dict(counts[k].most_common()) for k in counts},
        c_routines_total=len(routines), c_routines_verified=len(verified),
        c_bytes_total=sum(r['bytes'] for r in routines), c_bytes_verified=sum(r['bytes'] for r in verified))
    pathlib.Path(args.json).write_text(json.dumps(summary, indent=1) + '\n')
    for k, text, _ in CATEGORIES:
        n = summary['bytes'][k]
        print('%-46s %9s  %5.1f %%' % (text, format(n, ','), 100.0 * n / ROM_SIZE))


if __name__ == '__main__':
    main()
