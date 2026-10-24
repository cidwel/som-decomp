"""Recovered title window table producer and HDMA registration.
usage: boot_title_window.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_ppu_queue,boot_copy_queue,boot_dma,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def window(mem,width,centre):
    """$CE6B: queue run/mask pairs, table terminator and register2C HDMA source."""
    bank = memoryview(mem)[65536:]
    doubled = (centre*2)&65535
    top = (doubled-width)>>1 if doubled>=width else 0
    bottom = min((doubled+width)&65535,447)>>1
    height = (bottom-top)&65535
    node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],0x2C)
    destination = word(bank,0x30C)
    def emit(count,mask,length=2):
        nonlocal destination
        record = boot_copy_queue.allocate_record(bank)
        put_word(bank,record+1,destination)
        bank[record+4:record+7] = bytes((length,count,mask))
        if length==3: bank[record+7] = 0
        boot_copy_queue.append_record(bank,record)
        destination = (destination+2)&65535
    first = top&255
    if first:
        bank[node+2] &= 0xEE
        if first>=128:
            emit(127,bank[node+2])
            first -= 127
        emit(first,bank[node+2])
        if bottom&255>=223 and height&255:
            height = height&0xFF00|((height-1)&255)
            bottom = bottom&0xFF00|((bottom-1)&255)
    else: bank[node+2] |= 0x11
    count = height&255
    if count:
        if count>=128:
            emit(127,bank[node+2]|0x11)
            count -= 127
        emit(count,bank[node+2]|0x11)
    emit(1,bank[node+2],3)
    boot_ppu_queue.append_entry(bank,node)
    writes = []
    if not word(bank,0x30E):
        descriptor = boot_dma.allocate_descriptor(bank,mem,5)
        put_word(bank,0x30E,descriptor)
        put_word(bank,descriptor+2,word(bank,0x30C))
        bank[descriptor:descriptor+2] = bytes((0,0x2C))
        bank[descriptor+4] = 0x7F
        writes = boot_dma.submit(bank,descriptor)
    return top,bottom,writes


class RegisterCpu(cpu.CPU):
    def __init__(self):
        super().__init__()
        self.writes = []
    def wr8(self,address,value):
        bank,offset = address>>16,address&65535
        if (bank<64 or 128<=bank<192) and 0x4300<=offset<0x4380:
            self.writes.append((offset,value&255))
        super().wr8(address,value)


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    rng = random.Random(0xCE6B)
    cases = dict(new_hdma=0,existing_hdma=0)
    widths = (0,1,2,32,64,127,128,254,255,256,447,448,511,65535)
    centres = (0,1,63,64,112,127,128,223,224,32767,32768,65535)
    for trial in range(336):
        expected = initial.wram[:]
        bank = memoryview(expected)[65536:]
        put_word(bank,0x30C,0x3000)
        bank[0x3000:0x3020] = rng.randbytes(32)
        mirror = word(bank,0x2E2)
        put_word(bank,mirror+0x2C,rng.randrange(65536))
        existing = trial%2
        if existing:
            descriptor = boot_dma.allocate_descriptor(bank,expected,5)
            put_word(bank,0x30E,descriptor)
            boot_dma.submit(bank,descriptor)
        else: put_word(bank,0x30E,0)
        width,centre = widths[(trial//2)%len(widths)],centres[(trial//(2*len(widths)))%len(centres)]
        memory = expected[:]
        top,bottom,writes = window(expected,width,centre)
        c = RegisterCpu()
        c.wram[:] = memory
        c.D,c.DB,c.Y = 0x300,0x7F,centre
        boot_tasks.call(c,0xCE6B,X=width)
        cases['existing_hdma' if existing else 'new_hdma'] += 1
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
        assert c.X==top and c.Y==bottom and c.writes==writes,('window return',trial,c.X,c.Y,top,bottom)
        boot_transform.compare_memory(c.wram,expected,('window producer',trial))
        boot_copy_queue.run_queues(expected,rom)
        boot_tasks.call(c,0xC9E5)
        boot_transform.compare_memory(c.wram,expected,('window table service',trial))
        boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
        boot_tasks.call(c,0xC18B)
        boot_transform.compare_memory(c.wram,expected,('window shadow service',trial))
    return dict(verified=True,cases=cases,comparison='full WRAM outside caller stack1F80-1FFF; window X/Y, ordered HDMA registers, original copy-queue and shadow service effects',scope='336 calls with supplied width/centre, real config classes, valid bank7F table and available copy/PPU/HDMA resources; original game callees execute; hardware HDMA scanline effects/timing, exhausted resources and full D2FC caller open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
