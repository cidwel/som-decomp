"""Recovered 128-byte unit allocator and suffix release in boot WRAM.
usage: boot_heap.py ROM [--json OUT.json]
Models the original counters/hint updates, including zero count meaning 256 iterations.
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_pool,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def allocate_units(mem,count):
    """$7E:AF59: allocate using usage countdowns at C4 and owners at 1C4."""
    count &= 255
    hint = word(mem,0xC2)
    index = start = hint
    limit = (-hint)&255
    remaining = count
    while True:
        if mem[0xC4+index]:
            remaining,start = count,index
        else:
            remaining = (remaining-1)&255
            if not remaining: break
        index += 1
        limit = (limit-1)&255
        if not limit: return 0
    end = (-limit)&255
    if end>mem[0xC0]: mem[0xC0] = end
    if start==hint:
        next_free = start+count
        while mem[0xC4+next_free]:
            next_free += 1
            limit = (limit-1)&255
            if not limit:
                next_free = 0
                break
        put_word(mem,0xC2,next_free)
    else:
        start += 1
    owner = boot_pool.task_id(mem)
    for n in range(count or 256):
        mem[0xC4+start+n] = (count-n)&255
        mem[0x1C4+start+n] = owner
    return (start<<7)&0xFFFF

def free_units(mem,pointer):
    """$7E:B00F: release the allocation suffix starting at an aligned nonzero pointer."""
    if not pointer or pointer&127: return
    index = (pointer>>7)&255
    count = mem[0xC4+index]
    if not count: return
    for n in range(count):
        mem[0xC4+index+n] = mem[0x1C4+index+n] = 0
    previous = index-1
    while mem[0xC4+previous]>count:
        mem[0xC4+previous] -= count
        previous -= 1
    if index<mem[0xC2]: mem[0xC2] = index

def allocate_bytes(mem,size,fill):
    """$7E:B0A1: rounded allocation then fill, even when allocation returned zero."""
    pointer = allocate_units(mem,((size+127)&0xFFFF)>>7)
    mem[pointer:pointer+size] = bytes((fill&255,))*size
    return pointer

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xAF59)
    cases = dict(allocate_units=0,free_units=0)
    for trial in range(320):
        memory = bytearray(rng.randbytes(0x10000))
        memory[0xC4:0x2C4] = bytes(512)
        memory[0xC4],memory[0x1C4] = 1,1  # reserved zero-pointer unit and sentinel owner.
        put_word(memory,0x9E,0 if trial%3==0 else 0x600)
        memory[0x604] = 2+trial%20
        index = 1
        while index<256:
            length = min(rng.randint(1,16),256-index)
            if rng.randrange(3)==0:
                for n in range(length):
                    memory[0xC4+index+n] = length-n
                    memory[0x1C4+index+n] = rng.randint(1,21)
            index += length
        put_word(memory,0xC2,(0,1,128,255,rng.randrange(256))[trial%5])
        memory[0xC0] = rng.randrange(256)
        count = (0,1,2,255,rng.randint(1,24))[trial%5]
        expected = memory[:]
        result = allocate_units(expected,count)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        boot_tasks.call(c,0xAF59,A=count|rng.randrange(256)<<8)
        assert c.wram[0x10000:]==expected and c.X==result, ('allocate',trial)
        cases['allocate_units'] += 1
        memory[0xC4:0x2C4] = bytes(512)
        memory[0xC4],memory[0x1C4] = 1,1
        start = rng.randint(1,235)
        length = rng.randint(1,min(20,256-start))
        for n in range(length):
            memory[0xC4+start+n] = length-n
            memory[0x1C4+start+n] = 2+trial%20
        pointer = (start+rng.randrange(length))<<7
        if trial%8==0: pointer = 0
        elif trial%8==1: pointer += 1
        expected = memory[:]
        free_units(expected,pointer)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        boot_tasks.call(c,0xB0D6,X=pointer)
        assert c.wram[0x10000:]==expected, ('free',trial)
        cases['free_units'] += 1
    cases['allocate_bytes'] = 0
    for trial in range(96):
        memory = bytearray(rng.randbytes(0x10000))
        memory[0xC4:0x2C4] = bytes(512)
        memory[0xC4],memory[0x1C4] = 1,1
        if trial%3==0: memory[0xC4:0x1C4] = bytes((1,))*256
        put_word(memory,0x9E,0)
        put_word(memory,0xC2,(1,128,255)[trial%3])
        size = (0,1,127,128,129,1024,2048,32768)[trial%8]
        fill = rng.randrange(256)
        expected = memory[:]
        result = allocate_bytes(expected,size,fill)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        boot_tasks.call(c,0xB0A1,A=fill,X=size)
        assert c.wram[0x10000:]==expected and c.X==result,('fill allocation',trial)
        cases['allocate_bytes'] += 1
    return {'cases':cases,'verified':True,'unit_size':128,'usage':'7F00C4','owners':'7F01C4',
            'comparison':'entire bank 7F and allocation X',
            'scope':'valid 256-unit tables with reserved zero-pointer unit; not all malformed pointers/tables'}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
