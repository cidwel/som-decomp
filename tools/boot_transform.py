"""Recovered coefficient scaling, two-pass integer transform and six-block image groups.
usage: boot_transform.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_colour,boot_graphics,boot_coefficients,boot_colour_scene,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word
H = tuple(tuple(1 if sign=='+' else -1 for sign in row) for row in
          ('++++++++','++++----','++----++','++--++--','+--++--+','+--+-++-','+-+--+-+','+-+-+-+-'))


def signed(value,bits):
    value &= (1<<bits)-1
    return value-(1<<bits) if value&(1<<(bits-1)) else value


class Mode7Cpu(cpu.CPU):
    """Functional shared Mode-7 latch and signed 16-by-8 multiplier; no cycle timing."""
    def __init__(self):
        super().__init__()
        self.mode7 = {}
        self.mode7_latch = 0
        self.multiply_writes = []

    def wr8(self,address,value):
        bank,offset = (address>>16)&255,address&65535
        if (bank<0x40 or 0x80<=bank<0xC0) and (offset in (0x210D,0x210E) or 0x211B<=offset<=0x2120):
            value &= 255
            self.mode7[offset] = (value<<8)|self.mode7_latch
            self.mode7_latch = value
            if offset in (0x211B,0x211C): self.multiply_writes.append((offset,value))
            return
        super().wr8(address,value)

    def rd8(self,address):
        bank,offset = (address>>16)&255,address&65535
        if (bank<0x40 or 0x80<=bank<0xC0) and 0x2134<=offset<=0x2136:
            product = signed(self.mode7.get(0x211B,0),16)*signed(self.mode7.get(0x211C,0)>>8,8)
            return (product>>(8*(offset-0x2134)))&255
        return super().rd8(address)


def scale_coefficients(mem,destination,data_bank=0x7E):
    """$9AA4: multiply signed low coefficient bytes by zero-terminated byte weights."""
    template = (data_bank-0x7E)*65536+0x1D00
    index = 0
    writes = []
    while mem[template+index]:
        weight,value = mem[template+index],mem[destination+2*index]
        writes.extend(((0x211B,weight),(0x211B,0),(0x211C,value),(0x211C,value)))
        put_word(mem,destination+2*index,(weight*signed(value,8))&65535)
        index += 1
    return writes,index


def transform_block(mem,destination):
    """$9AD4: two separable eight-point sign sums with word wrap and final rounding."""
    for column in range(8):
        values = [word(mem,destination+16*row+2*column) for row in range(8)]
        for row,signs in enumerate(H):
            value = sum(sign*component for sign,component in zip(signs,values))&65535
            put_word(mem,destination+0x80+16*column+2*row,value)
    for column in range(8):
        values = [word(mem,destination+0x80+16*row+2*column) for row in range(8)]
        for row,signs in enumerate(H):
            value = (4+sum(sign*component for sign,component in zip(signs,values)))&65535
            put_word(mem,destination+16*column+2*row,(signed(value,16)>>3)&65535)


def decode_transform_block(mem,rom,node,destination,previous,data_bank=0x7E):
    """$9D0E: save decoded DC, scale/transform its block and return that saved predictor."""
    result = boot_coefficients.decode_block(mem,rom,node,destination,previous)
    writes,_ = scale_coefficients(mem,destination,data_bank)
    transform_block(mem,destination)
    return result,writes


def decode_image_group(mem,rom):
    """$9DB6: four blocks share predictor 0110, then one each uses 0112/0114."""
    node = word(mem,0x116)
    writes = []
    for block in range(6):
        predictor = 0x110 if block<4 else 0x110+2*(block-3)
        result,block_writes = decode_transform_block(mem,rom,node,0x1600+0x100*block,word(mem,predictor))
        put_word(mem,predictor,result)
        writes.extend(block_writes)
    return result,writes


def call(c,address,destination=0,A=0,X=0,data_bank=0x7E,step_limit=1_000_000):
    c.S,c.PB,c.PC,c.M,c.XF,c.D,c.A,c.X,c.DB = 0x1FFF,0x7E,address,0,0,destination,A,X,data_bank
    c.push16(0xFFFD)
    start = c.steps
    while c.PB<<16|c.PC!=0x7EFFFE:
        c.step()
        if c.steps-start>step_limit: raise RuntimeError('coefficient transform timeout')


def compare_memory(actual,expected,label):
    assert actual[:0x1F80]==expected[:0x1F80] and actual[0x2000:]==expected[0x2000:],label


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    boot_colour_scene.initialize_scene_template(baseline)
    rng = random.Random(0x9AD4)
    cases = dict(mode7_multiplier=0,scale_coefficients=0,transform_block=0,decode_transform_block=0,real_image_group=0)
    for trial in range(512):
        c = Mode7Cpu()
        first = (0,1,0x7FFF,0x8000,0xFFFF,rng.randrange(65536))[trial%6]
        second = (0,1,127,128,255,rng.randrange(256))[trial%6]
        c.wr8(0x211B,first&255)
        c.wr8(0x211B,first>>8)
        c.wr8(0x210D,rng.randrange(256))
        c.wr8(0x211C,second)
        expected = (signed(first,16)*signed(second,8))&0xFFFFFF
        actual = sum(c.rd8(0x802134+index)<<(8*index) for index in range(3))
        assert actual==expected,('mode7 multiply',trial)
        cases['mode7_multiplier'] += 1
    for trial in range(320):
        memory = baseline[:]
        destination = (0x800,0x1000,0x1600,0x1A00)[trial%4]
        memory[destination:destination+256] = rng.randbytes(256)
        expected = memory[:]
        transform_block(expected,destination)
        c = Mode7Cpu()
        c.wram[:] = memory
        call(c,0x9AD4,destination,data_bank=trial%256)
        compare_memory(c.wram,expected,('transform block',trial))
        assert c.D==destination+16 and c.X==0x70 and c.A==0 and c.DB==trial%256,('transform registers',trial)
        cases['transform_block'] += 1
    for trial in range(240):
        memory = baseline[:]
        destination = (0x800,0x1000,0x1600,0x1A00)[trial%4]
        memory[destination:destination+128] = rng.randbytes(128)
        data_bank = 0x7E if trial%2 else 0x7F
        template = (data_bank-0x7E)*65536+0x1D00
        count = (0,1,7,31,64)[trial%5]
        if trial%5==4: memory[template:template+64] = baseline[0x1D00:0x1D40]
        else: memory[template:template+count] = bytes(rng.randrange(1,256) for _ in range(count))
        memory[template+count] = 0
        expected = memory[:]
        writes,length = scale_coefficients(expected,destination,data_bank)
        c = Mode7Cpu()
        c.wram[:] = memory
        call(c,0x9AA4,destination,data_bank=data_bank)
        compare_memory(c.wram,expected,('scale coefficients',trial))
        assert c.multiply_writes==writes and c.D==destination and c.X==(destination-0x2100+2*length)&65535 and c.Y==0x1D00+length and c.M==1,('scale registers/writes',trial)
        cases['scale_coefficients'] += 1
    for trial in range(160):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        put_word(bank,0x8A,0x3000)
        for index in range(7):
            for bit in range(2): put_word(bank,0x3000+4*index+2*bit,0x3000+4*(2*index+1+bit))
        for index,value in enumerate((0,1,63,64,127,128,129,255)): put_word(bank,0x301C+4*index,value)
        memory[0x15000:0x15400] = rng.randbytes(1024)
        boot_colour.initialize_decoder(bank,0x80,0x7F,0x5000)
        bank[0x87] = (0,128,129,255)[trial%4]
        put_word(memory,0x116,0x80)
        previous = (0,6,127,128,0x7FFF,0x8000,0xFFFF,rng.randrange(65536))[trial%8]
        destination = (0x800,0x1000,0x1600,0x1A00)[trial%4]
        expected = memory[:]
        result,writes = decode_transform_block(expected,rom,0x80,destination,previous)
        c = Mode7Cpu()
        c.wram[:] = memory
        call(c,0x9D0E,destination,X=previous,data_bank=0)
        compare_memory(c.wram,expected,('decode/scale/transform',trial))
        assert c.X==result and c.multiply_writes==writes,('saved predictor/writes',trial)
        cases['decode_transform_block'] += 1
    memory = baseline[:]
    bank = memoryview(memory)[65536:]
    boot_colour.allocate_tree(bank)
    boot_graphics.initialize_staging(bank)
    header = boot_colour.build_tree(memory,rom,0xD2E536)
    boot_colour.initialize_decoder(bank,0x80,0xD2,0xE6BC)
    boot_colour.components(memory,rom,0x80)
    put_word(memory,0x116,0x80)
    put_word(memory,0x110,header&255)
    put_word(memory,0x112,0)
    put_word(memory,0x114,0)
    expected = memory[:]
    c = Mode7Cpu()
    c.wram[:] = memory
    for group in range(192):
        result,writes = decode_image_group(expected,rom)
        c.multiply_writes.clear()
        call(c,0x9DB6,data_bank=0)
        compare_memory(c.wram,expected,('real transformed image group',group))
        assert c.X==result and c.multiply_writes==writes and c.D==0,('image group predictor/writes',group)
        cases['real_image_group'] += 1
    return dict(cases=cases,verified=True,comparison='all WRAM outside caller stack scratch 1F80-1FFF, ordered multiplier writes and selected returned registers',real_image=dict(groups=192,blocks=1152,coefficients=73728,stream_refill_cursor=f'D2{word(memoryview(expected)[65536:],0x80):04X}'),hardware_reference='https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/ppu/io.cpp',scope='functional Mode-7 shared latch/signed 16-by-8 multiplication; native page-aligned low-WRAM blocks; byte-weight terminator lengths0-64, arbitrary word overflow and real configuration weights; full six-block decode/scale/transform groups; physical PPU timing, pixel-colour conversion and task/render synchronization remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
