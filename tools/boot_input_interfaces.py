"""Recovered eight alternate-interface readers and their dispatch selection.
usage: boot_input_interfaces.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_input,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word
TARGETS = ((0xA573,0xA5A4,0xA5B2,0xA603),(0xA615,0xA646,0xA654,0xA6A5))

def read_interface(mem,port,kind,auto,serial,data_bank):
    """Return the word and control writes; scratch cache stores use DB=00 inside readers."""
    cache = 0x10094 if data_bank==0x7F else 0x94
    if kind==0:
        put_word(mem,0x94,0)
        return auto[port],[]
    if kind==1: return auto[port+2]|word(mem,cache),[]
    if kind==3: return word(mem,cache),[]
    first = second = 0
    for value in serial:
        first = ((first<<1)|(value&1))&0xFFFF
        second = ((second<<1)|((value>>1)&1))&0xFFFF
    put_word(mem,0x94,second)
    return first,[0xBF if port==0 else 0x7F,0xFF]

def select(flags,index):
    """$7E:A6B7: return alternate (port,kind) or standard register offset/invalid."""
    if flags&0x40:
        if index<8: return 'alternate',0,index//2
        index -= 6
        flags = index&255  # The original subtraction replaces A before the second BIT.
    if index and flags&0x80: return 'alternate',1,(index-2)//2
    return ('standard',index//2,0) if index<=2 else ('invalid',0,0)

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xA573)
    class InputCpu(cpu.CPU):
        def rd8(self,address):
            if 0x4218<=address<=0x421F:
                value = self.auto[(address-0x4218)//2]
                return value>>8 if address&1 else value&255
            if address in (0x4016,0x4017): return next(self.serial[address-0x4016])
            return super().rd8(address)
        def hwwrite(self,address,value):
            if address==0x4201: self.control.append(value&255)
            super().hwwrite(address,value)
    reader_cases = dispatcher_cases = 0
    for trial in range(96):
        for port in range(2):
            for kind,address in enumerate(TARGETS[port]):
                memory = bytearray(rng.randbytes(0x20000))
                memory[0x8000:0xD6D3] = image[0x8000:0xD6D3]
                data_bank = (0,0x7F)[trial%2]
                auto = [rng.randrange(65536) for _ in range(4)]
                serial = [rng.randrange(256) for _ in range(16)]
                expected = memory[:]
                result,control = read_interface(expected,port,kind,auto,serial,data_bank)
                c = InputCpu()
                c.wram[:] = memory
                c.auto,c.serial,c.control = auto,[iter(serial),iter(serial)],[]
                c.DB,c.D = data_bank,rng.randrange(65536)
                c.setP((rng.randrange(256)&0xE7)|0x20)
                original_p,direct = c.P()&0xEF,c.D
                boot_tasks.call(c,address)
                expected[0x1FC0:0x2000] = c.wram[0x1FC0:0x2000]
                flags = ((0 if kind==0 else original_p)&0x7D)|(0x80 if direct&0x8000 else 0)|(2 if direct==0 else 0)
                assert c.wram==expected and c.A==result and c.control==control,('reader',trial,port,kind,c.A,result)
                assert c.DB==data_bank and c.D==direct and c.P()==flags,('reader flags',trial,port,kind,c.P(),flags)
                reader_cases += 1
    for trial in range(320):
        memory = bytearray(rng.randbytes(0x20000))
        memory[0x8000:0xD6D3] = image[0x8000:0xD6D3]
        flags,index = (0,0x40,0x80,0xC0)[trial%4],((trial//4)%5)*2
        memory[0x10096] = flags
        auto = [rng.randrange(65536) for _ in range(4)]
        serial = [rng.randrange(256) for _ in range(16)]
        route,port,kind = select(flags,index)
        expected = memory[:]
        if route=='alternate': result,control = read_interface(expected,port,kind,auto,serial,0x7F)
        else: result,control = (auto[port] if route=='standard' else 1),[]
        c = InputCpu()
        c.wram[:] = memory
        c.auto,c.serial,c.control = auto,[iter(serial),iter(serial)],[]
        c.DB,c.D = 0x7F,rng.randrange(65536)
        boot_tasks.call(c,0xA6B7,X=index)
        expected[0x1FC0:0x2000] = c.wram[0x1FC0:0x2000]
        assert c.wram==expected and c.A==result and c.control==control,('dispatch',trial,flags,index,c.A,result)
        dispatcher_cases += 1
    full_update_cases = 0
    c,_ = boot_tasks.initialized(rom)
    initialized = c.wram[:]
    for trial in range(160):
        memory = initialized[:]
        bank = memoryview(memory)[0x10000:]
        flags = (0,0x40,0x80,0xC0)[trial%4]
        bank[0x96],bank[0x97],bank[0x90] = flags,0,1
        put_word(bank,0x92,0x1000)
        put_word(bank,0x94,rng.randrange(65536)&0xEFE0)
        put_word(bank,0x9C,0x600)
        put_word(bank,0x9E,0x600)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,0x2C6,0x2400)
        for i in range(20):
            node = 0x600+16*i
            bank[node+4],bank[node+2] = 2+i,1
            put_word(bank,node+10,0)
            put_word(bank,0x2400+8*i,0x2400+8*(i+1) if i<19 else 0)
        for i in range(5):
            node = 0x1000+16*i
            bank[node+1] = (0,1,2+i,255)[(trial+i)%4]
            put_word(bank,node+2,rng.randrange(65536))
            put_word(bank,node+8,rng.randrange(65536))
            put_word(bank,node+10,rng.randrange(65536))
        auto = [rng.randrange(65536)&0xEFE0 for _ in range(4)]
        serial = [[rng.randrange(256) for _ in range(16)] for _ in range(2)]
        for stream in serial: stream[0] |= 1  # Avoid reset-vector transfer in returning update cases.
        expected = memory[:]
        pads,control = [],[0xFF]
        for index in range(0,10,2):
            route,port,kind = select(flags,index)
            if route=='alternate':
                value,writes = read_interface(expected,port,kind,auto,serial[port],0x7F)
                control.extend(writes)
            else: value = auto[port] if route=='standard' else 1
            pads.append(value)
        boot_input.update_standard(memoryview(expected)[0x10000:],pads)
        c = InputCpu()
        c.wram[:] = memory
        c.auto,c.control = auto,[]
        c.serial = [iter(([2]*8+[0] if flags&(0x40 if port==0 else 0x80) else [0,0])+serial[port]) for port in range(2)]
        c.DB,c.D = rng.randrange(256),rng.randrange(65536)
        boot_tasks.call(c,0xA6FF)
        expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
        assert c.wram==expected and c.control==control,('full interfaces',trial,flags)
        full_update_cases += 1
    return {'reader_cases':reader_cases,'dispatcher_cases':dispatcher_cases,'full_update_cases':full_update_cases,'verified':True,
            'comparison':'all WRAM except reader scratch 1FC0-1FFF or full-update scratch 1F80-1FFF; A, control writes, reader DB/D/P',
            'scope':'eight near readers, caller DB=00/7F, dispatcher flags 00/40/80/C0 and indices 0/2/4/6/8; 160 full updates across all flags; controlled input bytes, reset transfer excluded, not electrical timing'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
