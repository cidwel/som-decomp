"""Inventory event commands/text and reachable ordinary-monster/hero AI bytecode.
usage: script_regions.py ROM [--json OUT.json]
Only boundaries, ids and counts are saved. Script bytes and dialogue are not exported.
"""
import sys, json, hashlib, romio, event_vm, aidis

def inventory(rom):
    regions, events, omitted = [], [], []
    def span(name,offset,size,kind):
        assert 0<=offset<offset+size<=len(rom)
        regions.append({'name':name,'offset':offset,'size':size,'type':kind})
    for bank in (0xC9,0xCA):
        span('bank %02X event pointers'%bank,(bank&0x3F)<<16,0x800,'event pointer table')
    for ev in range(2048):
        bank,start,end = event_vm.event_range(rom,ev)
        if end<=start:
            omitted.append({'event':ev,'start':start,'next_pointer':end,
                            'reason':'no increasing boundary; final C9 pointer has no sentinel'})
            continue
        _,commands = event_vm.decode_event(rom,ev)
        assert commands and commands[-1]['off']+commands[-1]['bytes']==end
        for command in commands:
            assert command['name']!='?', (ev,command['off'])
        span('event %03X encoded commands/text'%ev,((bank&0x3F)<<16)+start,end-start,'event bytecode and encoded text')
        events.append({'id':ev,'bank':bank,'start':start,'end':end,'commands':len(commands),
                       'text_bytes':sum(c['bytes'] for c in commands if c['name']=='TEXT')})
    entries,seen,unknown = [],{},set()
    seeds = []
    for object_id in list(range(0x57))+[0x80,0x81,0x82]:
        pointer = int.from_bytes(rom[0x100009+16*object_id:0x10000B+16*object_id],'little')
        span('object %02X AI entry'%object_id,0x100009+16*object_id,2,'AI entry pointer')
        entries.append({'object_id':object_id,'entry':pointer})
        seeds += [pointer,(pointer+3)&0xFFFF]
    known = set(aidis.FIX)|aidis.N0|aidis.N1|aidis.N3|aidis.N4|aidis.UNDEF
    while seeds:
        pc = seeds.pop()
        while pc not in seen:
            op = rom[aidis.BASE+pc]
            if op not in known:
                unknown.add(pc)
                break
            size,_,target,fallthrough = aidis.decode(rom,pc)
            assert pc+size<=0x10000, pc
            seen[pc] = size
            if target is not None: seeds.append(target)
            if not fallthrough: break
            pc += size
    for pc,size in sorted(seen.items()):
        span('AI instruction %04X'%pc,aidis.BASE+pc,size,'AI bytecode')
    span('text glyph pair dictionary',0x77299,0x3D*2,'two-glyph dictionary')
    mask = bytearray(len(rom))
    for row in regions: mask[row['offset']:row['offset']+row['size']] = b'\x01'*row['size']
    return {'rom_sha256':hashlib.sha256(rom).hexdigest(),'regions':regions,'events':events,
            'inferred_event_ends':[{'event':0x3FF,'method':'terminal GOTO; no C9 sentinel',
                                    'evidence':'tools/event_boundary_probe.py'}],
            'omitted_events':omitted,'ai_entries':entries,'ai_instructions':len(seen),
            'unknown_ai_positions':sorted(unknown),'unique_bytes':sum(mask),
            'validation':'existing decoders and boundary checks; not original execution of every script'}

def main():
    rom = romio.rom_from_argv()
    report = inventory(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print('%d events, %d AI instructions, %d unique bytes; %d event boundaries and %d AI positions unresolved' %
          (len(report['events']),report['ai_instructions'],report['unique_bytes'],
           len(report['omitted_events']),len(report['unknown_ai_positions'])))

if __name__=='__main__': main()
