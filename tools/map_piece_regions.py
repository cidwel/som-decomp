"""Inventory encoded map pieces, including references disabled by current event flags.
usage: map_piece_regions.py ROM [--json OUT.json]
Only addresses, dimensions and references are saved; decoded tiles stay in memory.
"""
import sys, json, hashlib, romio, map_native, map_tables

def inventory(rom):
    tables = map_tables.Tables(rom)
    pieces = map_native.Pieces(rom)
    references = {}
    for m in range(511):
        if tables.header(m) is None: continue
        for row in tables.pieces(m):
            references.setdefault(row['piece'], set()).add(m)
    records = []
    for pid, maps in sorted(references.items()):
        bank, pointer = pieces.locate(pid)
        offset = map_native.B(bank, pointer)
        width, height = (rom[offset] >> 1)+1, (rom[offset+1] >> 1)+1
        end = map_native.draw(rom, bank, pointer, bytearray(0x10000), 0, width, height)
        assert pointer+2 <= end and offset+end-pointer <= len(rom), (pid, bank, pointer, end)
        records.append({'id':pid, 'bank':bank, 'pointer':pointer, 'offset':offset,
                        'encoded_size':end-pointer, 'width':width, 'height':height,
                        'maps':sorted(maps)})
    mask = bytearray(len(rom))
    for row in records:
        lo = row['offset']
        mask[lo:lo+row['encoded_size']] = b'\x01'*row['encoded_size']
    return {'rom_sha256':hashlib.sha256(rom).hexdigest(), 'pieces':records,
            'unique_encoded_bytes':sum(mask),
            'evidence':['tools/map_native.py','docs/maps.md'],
            'validation':'decoded with existing model; not an execution comparison of every conditional variant'}

def main():
    rom = romio.rom_from_argv()
    report = inventory(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1], 'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print('%d referenced pieces, %d unique encoded bytes' % (len(report['pieces']),report['unique_encoded_bytes']))

if __name__ == '__main__': main()
