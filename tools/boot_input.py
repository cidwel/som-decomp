"""Recovered controller detection and standard-controller edge messages.
usage: boot_input.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_pool,boot_wait,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def detect(mem,kind,flags):
    """$7E:A4E9: update detected interface flags and send its FE/03 change message."""
    if mem[0x96]==kind: return
    mem[0x96] = kind
    if mem[0x97]:
        record = boot_pool.allocate(mem)
        mem[record+2],mem[record+4],mem[record+5] = 0xFE,3,flags
        boot_wait.append_record(mem,record,mem[0x97])

def update_standard(mem,pads):
    """$7E:A6FF after detection: update five states and append edge messages from decoded words."""
    if not mem[0x90]&1: return
    base = word(mem,0x92)
    for index in range(5):
        node = base+index*16
        buttons = pads[index] if index<len(pads) else 1
        if buttons==0x3030: return 'reset'
        if buttons&15:
            mem[node] = 0
            put_word(mem,node+2,0)
            continue
        old = word(mem,node+2)
        pressed = (old^buttons)&buttons
        released = (old^buttons)&(buttons^0xFFF0)
        put_word(mem,node+4,pressed)
        for event,bits,mask in ((1,pressed,word(mem,node+8)),(2,released,word(mem,node+10))):
            if event==2: put_word(mem,node+6,released)
            if bits&mask and mem[node+1]>=2:
                record = boot_pool.allocate(mem)
                mem[record+2],mem[record+4],mem[record+5] = 0xFE,event,index
                put_word(mem,record+6,bits&mask)
                boot_wait.append_record(mem,record,mem[node+1])
        mem[node] = 1
        put_word(mem,node+2,buttons)


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xA6FF)
    class InputCpu(cpu.CPU):
        def rd8(self,address):
            if address==0x4016: return next(self.serial16)
            if address==0x4017: return next(self.serial17)
            if 0x4218<=address<=0x421B:
                value = self.pads[(address-0x4218)//2]
                return value>>8 if address&1 else value&255
            return super().rd8(address)
    def memory_case(trial):
        memory = bytearray(rng.randbytes(0x10000))
        put_word(memory,0x9C,0x600)
        put_word(memory,0x9E,0 if trial%2 else 0x600)
        for i in range(20):
            node = 0x600+16*i
            memory[node+4] = 2+i
            memory[node+2] = 1
            put_word(memory,node+10,0)
        put_word(memory,0xA0,0)
        put_word(memory,0xA2,0)
        put_word(memory,0x2C6,0x2400)
        for i in range(20): put_word(memory,0x2400+8*i,0x2400+8*(i+1) if i<19 else 0)
        return memory
    cases = dict(detect=0,standard_edges=0)
    for trial in range(240):
        memory = memory_case(trial)
        memory[0x96] = (0,0x40,0x80,0xC0)[trial%4]
        memory[0x97] = (0,1,2,21,255)[trial%5]
        # Each probe polls a port up to eight times, stopping at its first zero.
        outcomes = [bool(rng.randrange(2)) for _ in range(4)]
        def phase(high): return [2]*8 if high else [2]*rng.randrange(8)+[0]
        first16,first17,last16,last17 = [phase(high) for high in outcomes]
        kind = (0x40 if outcomes[0] and not outcomes[2] else 0)|(0x80 if outcomes[1] and not outcomes[3] else 0)
        c = InputCpu()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        c.serial16,c.serial17 = iter(first16+last16),iter(first17+last17)
        c.DB = 0x7F
        c.setP((rng.randrange(256)&0xE7)|0x20)
        flags = c.P()&0xEF
        expected = memory[:]
        detect(expected,kind,flags)
        boot_tasks.call(c,0xA4E9)
        assert c.wram[0x10000:]==expected,('detect',trial)
        cases['detect'] += 1
    for trial in range(320):
        memory = memory_case(trial)
        memory[0x96] = 0
        memory[0x97] = 0
        memory[0x90] = rng.randrange(256)&0xFE if trial%5==0 else rng.randrange(256)|1
        put_word(memory,0x92,0x1000)
        for i in range(5):
            node = 0x1000+16*i
            memory[node+1] = (0,1,2+i,255)[(trial+i)%4]
            put_word(memory,node+8,(0,0xFFF0,rng.randrange(65536))[trial%3])
            put_word(memory,node+10,(0xFFF0,0,rng.randrange(65536))[trial%3])
        pads = [rng.randrange(65536)&0xFFF0,rng.randrange(65536)&0xFFF0]
        if trial%7==0: pads[trial%2] |= 1
        if 0x3030 in pads: pads = [0,0]
        expected = memory[:]
        update_standard(expected,pads)
        c = InputCpu()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        c.serial16,c.serial17,c.pads = iter([0,0]),iter([0,0]),pads
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xA6FF)
        assert c.wram[0x10000:]==expected,('standard input',trial)
        cases['standard_edges'] += 1
    cases['reset_transfer'] = 0
    reset = int.from_bytes(rom[0xFFFC:0xFFFE],'little')
    for trial in range(96):
        memory = memory_case(trial)
        memory[0x96],memory[0x97],memory[0x90] = 0,0,1
        put_word(memory,0x92,0x1000)
        for i in range(5):
            node = 0x1000+16*i
            memory[node+1] = 2+i
            put_word(memory,node+8,0xFFF0)
            put_word(memory,node+10,0xFFF0)
        pads = [rng.randrange(65536)&0xEFE0,rng.randrange(65536)&0xEFE0]
        pads[trial%2] = 0x3030
        expected = memory[:]
        assert update_standard(expected,pads)=='reset'
        c = InputCpu()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        c.serial16,c.serial17,c.pads = iter([0,0]),iter([0,0]),pads
        c.S,c.PB,c.PC,c.M,c.XF = 0x1FFF,0x7E,0xA6FF,1,0
        c.push16(0xFFFD)
        for _ in range(2000):
            c.step()
            if c.PB<<16|c.PC==reset: break
        else: raise RuntimeError('controller reset transfer timeout')
        assert c.wram[0x10000:]==expected and c.S==0x1FEE and c.DB==0x7F and c.D==0x1FF0,('reset transfer',trial)
        cases['reset_transfer'] += 1
    tables = [{'address':'7E%04X'%base,'entries':['7E%04X'%word(image,base+2*i) for i in range(4)],
               'dispatch':'7E%04X'%dispatch,'entry_mx':[1,0]} for base,dispatch in ((0xA60D,0xA6C9),(0xA6AF,0xA6E3))]
    return {'cases':cases,'verified':True,'indirect_tables':tables,'comparison':'entire bank 7F, original detection and every message callee execute',
            'scope':'controlled serial/auto-joypad reads; standard interface flags zero; returning cases exclude reset chord, 96 reset cases stop at vector; alternate readers verified separately in boot_input_interfaces.py; reset transfer checked to vector entry, restart body remains outside scope'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
