"""Recovered VRAM allocation and registered-buffer creation.
usage: boot_vram.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_heap,boot_ppu_queue,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def allocate_pages(mem,argument):
    """$D5F3: return a page offset or FF, using packed tag/alignment and length."""
    count,tag = argument&255,argument>>8
    stride = tag>>4
    attempts = 32
    value = stride
    while not value&1:
        value >>= 1
        attempts >>= 1
    base = word(mem,0x32C)
    candidate = base
    for _ in range(attempts):
        if all(mem[candidate+i]==0 for i in range(count or 256)):
            for i in range(count or 256): mem[candidate+i] = tag
            return (candidate-base)&255
        candidate += stride
    return 255


def release_pages(mem,page):
    """$D678: clear every one of 32 page bytes matching the selected tag."""
    base = word(mem,0x32C)
    tag = mem[base+(page&255)]
    for index in range(32):
        if mem[base+index]==tag: mem[base+index] = 0


def release_buffers(mem):
    """$C6CB: free four RAM buffers and nonzero-tag pages, then their table."""
    base = word(mem,0x2F4)
    if not base: return
    for index in range(4):
        node = base+8*index
        source = word(mem,node+2)
        if source: boot_heap.free_units(mem,source)
        page = mem[node]
        if page: release_pages(mem,page)
    boot_heap.free_units(mem,word(mem,0x2F4))


def slot_address(mem,argument):
    """$C710: select one of four eight-byte registrations with argument bits 2-3."""
    return (word(mem,0x2F4)+8*((argument>>2)&3))&65535


def create_buffer(mem,image,argument):
    """$C76D: allocate a RAM buffer and VRAM pages, then queue three PPU settings."""
    slot = slot_address(mem,argument)
    kind = argument&3
    size = (0x800,0x1000,0x1000,0x2000)[kind]
    source = boot_heap.allocate_bytes(mem,size,0)
    put_word(mem,slot+2,source)
    put_word(mem,slot+4,0)
    put_word(mem,slot+6,0)
    mem[slot+1] = size>>8
    page = allocate_pages(mem,((argument&0xFC)<<8)|(size>>11))
    mem[slot] = page
    setting = ((page<<2)|kind)&255
    index = (argument>>2)&3
    classes = image[0x603E:0x6072]
    for register,value in ((7+index,setting),(0xD+2*index,0),(0xE+2*index,0)):
        node = boot_ppu_queue.allocate_entry(mem,classes,register)
        if register==7+index: mem[node+2] = value
        else: put_word(mem,node+2,value)
        boot_ppu_queue.append_entry(mem,node)
    return word(mem,slot+2)


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    rng = random.Random(0xD5F3)
    cases = dict(allocate_pages=0,release_pages=0,slot_address=0,create_buffer=0,release_buffers=0)
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x32C,0x3000)
        bank[0x3000:0x3040] = bytes(0 if rng.randrange(3) else rng.randrange(1,256) for _ in range(64))
        if trial%4==0: bank[0x3000:0x3040] = bytes(64)
        tag = (0x10,0x20,0x40,0x80)[trial%4]|((trial//4)&15)
        count = (1,2,4,8)[(trial//16)%4]
        argument = tag<<8|count
        expected = bank[:]
        result = allocate_pages(expected,argument)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xD5F3,A=argument)
        assert c.wram[65536:]==expected and c.A&255==result,('allocate pages',trial,c.A,result)
        cases['allocate_pages'] += 1
        expected = bank[:]
        page = trial%32
        release_pages(expected,page)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        boot_tasks.call(c,0xD678,A=page)
        assert c.wram[65536:]==expected,('release pages',trial)
        cases['release_pages'] += 1
        argument = rng.randrange(65536)
        expected_result = slot_address(bank,argument)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0xC710,A=argument)
        assert c.wram[65536:]==bank and c.A==expected_result,('slot address',trial,c.A,expected_result)
        cases['slot_address'] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x2F4,0x1800)
        put_word(bank,0x32C,0x1900)
        bank[0x1900:0x1940] = bytes(64) if trial%3 else bytes([0x40]*64)
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4:0x104],bank[0x1C4:0x204] = bytes([1]*64),bytes([1]*64)
        bank[0xC0] = 64
        put_word(bank,0xC2,64)
        put_word(bank,0x9E,0)
        if trial%5==0: bank[0xC4:0x1C4] = bytes([1]*256)
        put_word(bank,0x2D6,0x6000)
        put_word(bank,0x2D8,0x6004)
        put_word(bank,0x2E2,0x7000)
        put_word(bank,0x2E0,0x2DE)
        put_word(bank,0x2DE,0)
        for index in range(4): put_word(bank,0x6004+4*index,0x6008+4*index if index<3 else 0)
        argument = (0x10,0x20,0x40,0x80)[trial%4]|((trial//4)&15)
        expected = bank[:]
        result = create_buffer(expected,image,argument)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xC76D,A=argument)
        assert c.wram[65536:]==expected and c.X==result,('create buffer',trial,c.X,result,[(hex(i),a,b) for i,(a,b) in enumerate(zip(c.wram[65536:],expected)) if a!=b][:24])
        cases['create_buffer'] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x2F4,0 if trial%5==0 else 0x1800)
        put_word(bank,0x32C,0x1900)
        bank[0x1900:0x1920] = bytes((i//4+1)*16 for i in range(32))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        for index in range(4):
            source = 0 if (trial+index)%3==0 else 0x5000+128*index
            put_word(bank,0x1802+8*index,source)
            bank[0x1800+8*index] = (trial+8*index)%32
            if source: bank[0xC4+(source>>7)],bank[0x1C4+(source>>7)] = 1,3
        bank[0xC4+0x30],bank[0x1C4+0x30] = 1,3
        expected = bank[:]
        release_buffers(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xC6CB)
        assert c.wram[65536:]==expected,('release buffers',trial)
        cases['release_buffers'] += 1
    return {'cases':cases,'verified':True,'comparison':'entire bank 7F; allocated page low A, slot A and created-buffer X',
            'scope':'valid table/pool addresses; strides 1/2/4/8, lengths 1/2/4/8, 160 full creation cases including RAM/VRAM failure; no physical PPU rendering',
            'configuration_source':'C7B480 -> 7E5000'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
