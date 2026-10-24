"""Verify the terminal C9 event's inferred two-byte GOTO boundary through the original VM.
usage: event_boundary_probe.py ROM STATE [--json OUT.json]
Stores only control-flow addresses/ids, never dialogue or script bytes.
"""
import sys,json,romio,event_vm

def validate(rom,state):
    bank,start,end = event_vm.event_range(rom,0x3FF)
    offset = event_vm.b24(bank<<16)+start
    opcode = rom[offset]
    assert 0x10<=opcode<0x18 and end-start==2
    target = (opcode&7)<<8|rom[offset+1]
    target_bank,target_start,_ = event_vm.event_range(rom,target)
    world = event_vm.World(rom,state)
    world.start_event(0x3FF)
    for _ in range(6): world.frame()
    observed = [(row['bank'],row['addr']) for row in world.vm_ops]
    assert observed[:2] == [(bank,start),(target_bank,target_start)]
    return {'event':0x3FF,'bank':bank,'start':start,'end':end,'target_event':target,
            'target_bank':target_bank,'target_start':target_start,'verified':True,
            'validation':'first two command addresses executed by original VM in six harness frames',
            'hooks':'World replaces video wait/sound duties as documented in event_vm.py'}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom,sys.argv[1])
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
