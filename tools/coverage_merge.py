"""Merge PC/M/X coverage from successful harness runs, checking ROM identity.
usage: coverage_merge.py ROM OUT.json RUN.json [RUN.json ...]
"""
import sys, json, hashlib, romio

def main():
    rom = romio.load(sys.argv[1])
    digest = hashlib.sha256(rom).hexdigest()
    entries, runs = set(), []
    for path in sys.argv[3:]:
        data = json.load(open(path))
        assert data['rom_sha256'] == digest, 'coverage belongs to a different ROM'
        entries.update(tuple(entry) for entry in data['entries'])
        runs.append({key:data[key] for key in ('tool','arguments','tool_sha256','cpu_sha256') if key in data} |
                    {'states':len(data['entries'])})
    rom_pcs = {pc for pc,m,x in entries if 0xC0 <= pc>>16 <= 0xDF or (pc>>16<0x20 and pc&0xFFFF>=0x8000)}
    ram_pcs = {pc for pc,m,x in entries if pc>>16 in (0x7E,0x7F) or (pc>>16<0x40 and pc&0xFFFF<0x2000)}
    report = {'rom_sha256':digest,'entries':[list(entry) for entry in sorted(entries)],'runs':runs,
              'unique_rom_pcs':len(rom_pcs),'unique_ram_pcs':len(ram_pcs),
              'schema':'entries = [24-bit PC, M, X]; includes generated inputs where the harness uses them'}
    with open(sys.argv[2],'w') as f:
        json.dump(report,f,separators=(',',':'))
        f.write('\n')
    print('%d PC/M/X states, %d ROM PCs, %d RAM PCs' % (len(entries),len(rom_pcs),len(ram_pcs)))

if __name__ == '__main__':
    main()
