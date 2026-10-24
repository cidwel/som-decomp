"""Resolved interpreter dispatch tables; targets/entry flags only, no instruction bytes.
usage: dispatch_tables.py ROM [--json OUT.json]
"""
import sys,json,hashlib,romio,aidis

TABLES = (
    ('monster/hero AI opcodes',0xC12257,256,0xC1252C,1,0),
    ('event commands (text clamped to 50)',0xC1E922,81,0xC1E8FF,1,1),
    ('event wait states 80-8F',0xC1E902,16,0xC1E8EC,1,1),
    ('boss/object state commands 00-15',0xC237CC,22,0xC237C9,0,0),
)

def inventory(rom):
    tables = []
    for name,address,count,dispatch,m,x in TABLES:
        offset = address&0x3FFFFF
        targets = []
        for index in range(count):
            target = int.from_bytes(rom[offset+2*index:offset+2*index+2],'little')
            targets.append({'index':index,'target':(address&0xFF0000)|target,'M':m,'X':x})
        tables.append({'name':name,'address':address,'offset':offset,'count':count,'stride':2,
                       'dispatch_instruction':dispatch,'targets':targets,'status':'documented',
                       'evidence':['tools/aidis.py','tools/event_vm.py','tools/statescript.py','docs/dispatch.md']})
    for op in aidis.UNDEF: assert tables[0]['targets'][op]['target']==0xC10100
    assert tables[1]['targets'][0]['target']==0xC1E9C4
    assert tables[3]['targets'][0]['target']==0xC237F8
    return {'rom_sha256':hashlib.sha256(rom).hexdigest(),'complete':False,'tables':tables,
            'scope':'four documented interpreter tables; other indirect calls and inline arguments remain open'}

def main():
    rom = romio.rom_from_argv()
    report = inventory(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print('%d dispatch tables, %d entries' % (len(report['tables']),sum(t['count'] for t in report['tables'])))

if __name__=='__main__': main()
