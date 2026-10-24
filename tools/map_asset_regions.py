"""Locate map graphics, palettes and attributes read by the existing native decoder.
usage: map_asset_regions.py ROM [--json OUT.json]
The inventory saves range metadata, never graphics or palette bytes.
"""
import sys, json, hashlib, romio, map_native, map_tables

def inventory(rom):
    tables = map_tables.Tables(rom)
    headers = [tables.header(m) for m in range(511) if tables.header(m) is not None]
    regions = []
    def span(name, start, size, kind):
        start %= len(rom)
        assert 0 < size <= len(rom)
        while size:
            count = min(size,len(rom)-start)
            regions.append({'name':name,'offset':start,'size':count,'type':kind})
            size -= count
            start = 0
    def w(at): return int.from_bytes(rom[at:at+2],'little')
    span('map graphics pool pointers',0xCE270,12,'pointer table')
    pools = [int.from_bytes(rom[0xCE270+n:0xCE273+n],'little')&0x1FFFFF for n in (0,3,6,9)]
    sets = sorted({h[0]&0x3F for h in headers})
    for gset in sets:
        start,end = w(0xCE27E+2*gset),w(0xCE280+2*gset)
        assert end>=start and (end-start)%3==0
        span('graphics set %d bounds'%gset,0xCE27E+2*gset,4,'pointer table')
        if end>start: span('graphics set %d records'%gset,0xC0000+start,end-start,'graphics list')
        output_size = 0
        for y in range(start,end,3):
            value = w(0xC0000+y)
            mode,tile,count = value>>13,value&0x1FFF,rom[0xC0000+y+2]+1
            pool,unit = (0,16) if mode<4 else (1,24) if mode<6 else (2,32) if mode==6 else (3,64)
            span('graphics set %d source record %04X'%(gset,y),pools[pool]+tile*unit,count*unit,
                 '%dbpp tiles'%(2+pool) if pool<3 else '64-byte graphics units')
            output_size += count*(32 if mode<7 else 64)
        assert len(map_native.decode_gfx(rom,gset)) == output_size
    for pset in sorted({h[1]&0x7F for h in headers}):
        span('map palette %d'%pset,0xC8000+210*pset,210,'15-bit BGR palette')
    for setup in sorted({h[5]&0x3F for h in headers}):
        span('screen setup %d backdrop'%setup,0x80107+9*setup,2,'15-bit BGR palette')
    entries = set()
    for aset in sorted({h[2]&0x3F for h in headers}):
        start = 0xB0400+384*aset
        span('map attributes set %d indices'%aset,start,384,'attribute indices')
        entries.update(rom[start:start+384])
    for entry in sorted(entries):
        span('map attribute entry %d'%entry,0xB0000+4*entry,4,'tile attributes')
    mask = bytearray(len(rom))
    for row in regions: mask[row['offset']:row['offset']+row['size']] = b'\x01'*row['size']
    return {'rom_sha256':hashlib.sha256(rom).hexdigest(),'regions':regions,
            'unique_bytes':sum(mask),'graphics_sets':sets,
            'evidence':['tools/map_native.py','docs/maps.md'],
            'validation':'ranges reproduced from existing readers; not a fresh original-loader comparison of all maps'}

def main():
    rom = romio.rom_from_argv()
    report = inventory(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print('%d graphics sets, %d ranges, %d unique bytes' %
          (len(report['graphics_sets']),len(report['regions']),report['unique_bytes']))

if __name__=='__main__': main()
