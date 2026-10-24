"""Check native boot interrupt frames and register restoration on the inactive IRQ path.
usage: boot_interrupts.py ROM [--json OUT.json]
The active IRQ body and console timing are outside these register-preservation tests.
"""
import sys, json, random, romio, boot_decode, boot_trace, cpu65816 as cpu

REGISTERS = ('A','X','Y','S','D','DB','PB','PC','N','V','Z','C','M','XF','I','Dm','E')

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xA266)
    cases = {'inactive_IRQ':0,'initial_NMI_RTI':0}
    for nmi in (False,True):
        for trial in range(256):
            c = boot_trace.BootCpu()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = rng.randbytes(0x10000)
            c.wram[0x100] = 0x40
            c.wram[0x104:0x108] = bytes((0x5C,0x66,0xA2,0x7E))
            c.wram[0x1008C] = 0
            c.A,c.X,c.Y,c.D = [rng.randrange(0x10000) for _ in range(4)]
            c.DB = rng.randrange(256)
            c.PB,c.PC,c.S = 0xC0,0x1234,0x1FFF
            c.setP(trial)
            before = {name:getattr(c,name) for name in REGISTERS}
            memory = c.wram[:]
            c.interrupt(nmi=nmi)
            for _ in range(80):
                c.step()
                if c.PB==before['PB'] and c.PC==before['PC']: break
            else: raise RuntimeError('boot interrupt did not return')
            assert {name:getattr(c,name) for name in REGISTERS}==before
            # The saved native frame and handler scratch writes occupy these stack bytes.
            low = before['S']-(4 if nmi else 14)+1
            memory[low:before['S']+1] = c.wram[low:before['S']+1]
            assert c.wram==memory
            assert not c.hardware_reads.get(0x4211,0)
            cases['initial_NMI_RTI' if nmi else 'inactive_IRQ'] += 1
    return {'cases':cases,'verified':True,'entry':'7EA266','inactive_flag':'7F008C == 0',
            'preserved':list(REGISTERS),'active_body_verified_model':False,'cycle_accurate':False}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
