"""Recovered boot palette allocation, colour copy and forward/reverse transfer producers.
usage: boot_palette.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_dma,boot_copy_queue,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def allocate_palette(mem,argument):
    """$BBAB: scan eight 32-byte slots from the requested low-nibble index."""
    node = word(mem,0x2D2)+32*(argument&15)
    for _ in range(8):
        if word(mem,node)&0x8000:
            put_word(mem,node,0)
            return node
        node += 32
    return 0


def release_palette(mem,node):
    """$BBE7: mark its first colour word 8000, including node zero."""
    put_word(mem,node,0x8000)


def copy_colours(mem,rom,node,source,argument):
    """$BC9A: forward word copies of 1-16 colours to a selected colour offset."""
    destination = 65536+node+((argument&0xF0)>>3)
    for index in range((argument&15)+1):
        address = source+2*index
        value = boot_copy_queue.read(mem,rom,address) | boot_copy_queue.read(mem,rom,address+1)<<8
        put_word(mem,destination+2*index,value)


def queue_palette(mem,image,source,reverse=False,constant=False):
    """$BBFE/$BC43: queue 32 palette bytes; reverse reads CGRAM and clears colour 0."""
    node = boot_dma.allocate_descriptor(mem,image,2)
    if node is None: return None
    put_word(mem,node+5,32)
    put_word(mem,node+2,0xBCE9 if constant else source)
    colour = (((source-word(mem,0x2D2))&65535)>>1)&255
    mem[node+10],mem[node+4] = colour,0x7E if constant else 0x7F
    if reverse: mem[node],mem[node+1] = 0x80,0x3B
    boot_dma.submit(mem,node)
    if reverse: put_word(mem,source,0)
    return colour>>4


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    rng = random.Random(0xBBFE)
    cases = dict(allocate_palette=0,release_palette=0,copy_colours=0,queue_palette=0,queue_reverse=0,queue_constant=0)
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x2D2,0x4000)
        argument = rng.randrange(65536)
        start = 0x4000+32*(argument&15)
        occupancy = 255 if trial==0 else trial&255
        for index in range(8): put_word(bank,start+32*index,rng.randrange(32768)|(0 if occupancy&(1<<index) else 0x8000))
        expected = bank[:]
        result = allocate_palette(expected,argument)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xBBAB,A=argument)
        assert c.wram[65536:]==expected and c.X==result,('allocate palette',trial)
        cases['allocate_palette'] += 1
        node = 0 if trial%5==0 else start
        expected = bank[:]
        release_palette(expected,node)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        boot_tasks.call(c,0xBBE7,X=node)
        assert c.wram[65536:]==expected,('release palette',trial)
        cases['release_palette'] += 1
    for trial in range(320):
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        node = 0x5000
        source_bank = (0xC0,0xC1,0x7E,0x7F)[trial%4]
        source_offset = (0x5500,0xFFF0,0x2000,0x5000-2*(trial%3))[trial%4]
        source = source_bank<<16|source_offset
        argument = source_bank<<8 | ((trial//16)&15)<<4 | trial%16
        expected = memory[:]
        copy_colours(expected,rom,node,source,argument)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB,c.Y = rng.randrange(256),source_offset
        boot_tasks.call(c,0xBC9A,A=argument,X=node)
        assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:],('copy colours',trial)
        cases['copy_colours'] += 1
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x2D2,0x5000)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,(0,1,255,256)[trial%4])
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        source = (0x5000+32*(trial%16),0x4FFF,0x6000,0x5001)[trial%4]
        for reverse,constant,address,name in ((False,False,0xBBFE,'queue_palette'),(True,False,0xBC43,'queue_reverse'),(False,True,0xBD09,'queue_constant')):
            expected = bank[:]
            result = queue_palette(expected,image,source,reverse,constant)
            c = cpu.CPU()
            c.wram[:65536] = image
            c.wram[65536:] = bank
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address,X=source)
            assert c.wram[65536:]==expected and c.A&255==result,(name,trial,c.A,result)
            cases[name] += 1
    cases['allocate_copy_queue'] = 0
    for trial in range(160):
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        bank = memoryview(memory)[65536:]
        put_word(bank,0x2D2,0x4000)
        for index in range(23): put_word(bank,0x4000+32*index,0x8000 if index%3 else 0)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,trial%8)
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        expected = memory[:]
        e = memoryview(expected)[65536:]
        palette = allocate_palette(e,trial%16)
        argument = 0xC000|((trial//16)&15)<<4|trial%16
        source = 0xC05500
        copy_colours(expected,rom,palette,source,argument)
        result = queue_palette(e,image,palette)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xBBAB,A=trial%16)
        actual_palette = c.X
        c.Y = source&65535
        boot_tasks.call(c,0xBC9A,A=argument,X=actual_palette)
        boot_tasks.call(c,0xBBFE,X=actual_palette)
        assert actual_palette==palette and c.wram[65536:]==e and c.A&255==result,('allocate/copy/queue',trial)
        cases['allocate_copy_queue'] += 1
    return {'cases':cases,'verified':True,'comparison':'bank 7F; allocation X, queue low A; colour-copy all WRAM outside caller scratch 1F80-1FFF',
            'configuration_source':'C7B480 -> 7E5000',
            'scope':'valid pools with available transfer descriptor; ROM/RAM colour sources, forward overlap and long-source bank crossing; descriptor data, not DMA payload effects/timing; exhaustion waits remain open'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
