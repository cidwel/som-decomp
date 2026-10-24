"""Recovered cold/native/warm boot-ROM entry and hardware initialization.
usage: boot_startup.py ROM [--json OUT]
"""
import sys,json,random,romio,boot_decode,cpu65816 as cpu


def prepare(mem,rom):
    """C14D0F: RTI interrupt entries, initial registers and boot decompression."""
    mem[0x100] = mem[0x104] = 0x40
    decoded,info = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    start = boot_decode.BOOT_DEST&65535
    mem[start:start+info['output_size']] = decoded[start:start+info['output_size']]
    return [(0x4200,0),(0x2100,0x80)]+[(address,0) for address in range(0x4200,0x420E)]+[(0x4201,255)]


class RegisterCpu(cpu.CPU):
    def __init__(self):
        super().__init__()
        self.writes = []
    def wr8(self,address,value):
        if (address>>16 in (0,0xC0,0xC1)) and (address&65535==0x2100 or 0x4200<=address&65535<=0x420D):
            self.writes.append((address&65535,value&255))
        super().wr8(address,value)


def validate(rom):
    cpu.set_rom(rom)
    rng = random.Random(0x4CE5)
    cases = dict(cold_reset=0,native_cold_entry=0,warm_entry=0)
    for trial in range(12):
        for name,entry,target in (('cold_reset',0x008004,0x7EAF0B),('native_cold_entry',0xC10010,0x7EAF0B),('warm_entry',0xC10018,0x7EAF28)):
            expected = bytearray(rng.randbytes(0x20000))
            original = expected[:]
            writes = prepare(expected,rom)
            c = RegisterCpu();c.wram[:] = original
            c.PB,c.PC = entry>>16,entry&65535
            c.E = int(name=='cold_reset')
            c.M,c.XF = 1,1
            c.S,c.D,c.DB = (0x01FF if c.E else 0x17FF),rng.randrange(65536),rng.randrange(256)
            direct = c.D
            while (c.PB<<16|c.PC)!=target:
                c.step()
                if c.steps>200000: raise RuntimeError('boot entry did not reach decoded program')
            assert c.wram[:0x180]==expected[:0x180] and c.wram[0x200:]==expected[0x200:], (name,trial,'WRAM')
            assert c.writes==writes, (name,trial,'register writes')
            assert (c.S,c.D,c.DB,c.E,c.M,c.XF)==(0x1FF,direct,0,0,1,0), (name,trial,'entry state')
            cases[name] += 1
    return dict(verified=True,cases=cases,comparison='full WRAM outside temporary caller stack0180-01FF, ordered4200/2100/4201 initialization writes, final target andS/D/DB/E/M/X',scope='36 complete original cold/native/warm boot calls with randomized WRAM and incomingD/DB; literal register writes and complete real boot decompression; stops before decodedAF0B/AF28 executes; live APU/PPU reset timing and later startup remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2);f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
