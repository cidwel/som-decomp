"""Recovered IRQ memory-copy queues, including the small odd-length helper behaviour.
usage: boot_copy_queue.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_heap,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def read(mem,rom,address):
    bank,offset = address>>16,address&65535
    if bank in (0x7E,0x7F): return mem[(bank-0x7E)*65536+offset]
    if 0xC0<=bank<=0xDF: return rom[address&0x1FFFFF]
    raise ValueError('copy model source bank outside scope')

def write(mem,address,value):
    bank,offset = address>>16,address&65535
    if bank not in (0x7E,0x7F): raise ValueError('copy model destination bank outside scope')
    mem[(bank-0x7E)*65536+offset] = value

def copy_pointer(mem,rom,source,destination,length):
    """$C44E: small word-copy path versus bank-fixed forward MVN kernel."""
    if not length: return
    if length>=17:
        for index in range(length):
            src = source&0xFF0000|((source+index)&65535)
            dst = destination&0xFF0000|((destination+index)&65535)
            write(mem,dst,read(mem,rom,src))
        return
    offset = 0
    if length&1:
        first = read(mem,rom,source)
        write(mem,destination,first)
        offset = 1
        # LDA byte replaces the low accumulator before DEC/LSR calculate the word count.
        length = (first-1)&65535
        if not length: return
    words = length>>1
    for _ in range(words or 65536):
        src,dst = (source+offset)&0xFFFFFF,(destination+offset)&0xFFFFFF
        low,high = read(mem,rom,src),read(mem,rom,(src+1)&0xFFFFFF)
        write(mem,dst,low)
        write(mem,(dst+1)&0xFFFFFF,high)
        offset = (offset+2)&65535

def copy_record(mem,rom,node):
    """$C985: lengths 1-3 are inline; zero encodes 256; all others are far pointers."""
    bank = memoryview(mem)[0x10000:]
    length = bank[node+4] or 256
    destination = word(bank,node+1)|bank[node+3]<<16
    if length<4:
        for index in range(length): write(mem,destination+index,bank[node+5+index])
    else:
        destination = bank[node+2]<<16|bank[node+1]<<8|bank[node+3]
        source = bank[node+6]<<16|bank[node+5]<<8|bank[node+7]
        copy_pointer(mem,rom,source,destination,length)

def release_record(mem,node):
    """$C93A: prepend an absolute record pointer, ignoring zero only."""
    if node:
        bank = memoryview(mem)[0x10000:]
        head = word(bank,0x2F8)
        mem[0x10000+node] = head&255
        # A word store at 7F:FFFF writes its high byte through the 80:0000 WRAM mirror.
        mem[(0x10000+node+1)&0x1FFFF] = head>>8
        put_word(bank,0x2F8,node)

def initialize_pool(mem):
    """$C8C8: allocate 256 bytes and link 31 eight-byte records, reserving offset zero."""
    base = boot_heap.allocate_units(mem,2)
    put_word(mem,0x2F6,base)
    put_word(mem,0x2F8,base+8)
    for offset in range(8,248,8): put_word(mem,base+offset,base+offset+8)
    put_word(mem,base+248,0)
    put_word(mem,0x2FE,0)
    put_word(mem,0x300,0x2FE)
    put_word(mem,0x2FA,0)
    put_word(mem,0x2FC,0x2FA)

def allocate_record(mem):
    """$C915: pop a nonzero free head and set the word at +3 to 007F."""
    node = word(mem,0x2F8)
    if node:
        put_word(mem,0x2F8,word(mem,node))
        put_word(mem,node+3,0x7F)
    return node

def append_record(mem,node):
    """$C95A: append a relative-offset record to the one-shot list, ignoring zero."""
    if not node: return
    tail = word(mem,0x300)
    mem[tail] = (node-word(mem,0x2F6))&255
    mem[node] = 0
    put_word(mem,0x300,node)


def run_queues(mem,rom):
    """$C9E5: retain persistent list, copy/release one-shot list and clear its header."""
    bank = memoryview(mem)[0x10000:]
    base = word(bank,0x2F6)
    for head in (0x2FA,0x2FE):
        offset = bank[head]
        while offset:
            node = base+offset
            copy_record(mem,rom,node)
            offset = bank[node]
            if head==0x2FE: release_record(mem,node)
    put_word(bank,0x2FE,0)
    put_word(bank,0x300,0x2FE)

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xC985)
    cases = dict(copy_record=0,release_record=0,run_queues=0)
    lengths = (0,1,2,3,4,5,6,7,15,16,17,255)
    def configure(memory,node,length,destination,source):
        bank = memoryview(memory)[0x10000:]
        bank[node+4] = length
        if 0<length<4:
            put_word(bank,node+1,destination&65535)
            bank[node+3] = destination>>16
            bank[node+5:node+8] = rng.randbytes(3)
        else:
            bank[node+1],bank[node+2],bank[node+3] = destination>>8&255,destination>>16,destination&255
            bank[node+5],bank[node+6],bank[node+7] = source>>8&255,source>>16,source&255
            if length&1 and length<17:
                # Vary the actual odd-path copy length, avoiding its zero-word-counter runaway.
                memory[((source>>16)-0x7E)*65536+(source&65535)] = (1,3,9,17)[(node//8+trial)%4]
    for trial in range(240):
        memory = bytearray(rng.randbytes(0x20000))
        memory[0x8000:0xD6D3] = image[0x8000:0xD6D3]
        length = lengths[trial%len(lengths)]
        source,destination = 0x7E6000,(0x7E4000,0x7F6000,0x7EFFF8)[trial%3]
        if trial%4==0 and (not length&1 or length>=17): source = 0xC05500
        elif trial%5==0 and (not length or length>=4): destination = source+1
        configure(memory,0x3008,length,destination,source)
        expected = memory[:]
        copy_record(expected,rom,0x3008)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = 0x7F
        boot_tasks.call(c,0xC985,X=0x3008)
        expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
        assert c.wram==expected,('copy record',trial,length)
        cases['copy_record'] += 1
        expected = memory[:]
        pointer = (0,0x3008,0xFFFF)[trial%3]
        release_record(expected,pointer)
        c = cpu.CPU()
        c.wram[:] = memory
        boot_tasks.call(c,0xC93A,X=pointer)
        expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
        assert c.wram==expected,('release',trial)
        cases['release_record'] += 1
    for trial in range(160):
        memory = bytearray(rng.randbytes(0x20000))
        memory[0x8000:0xD6D3] = image[0x8000:0xD6D3]
        bank = memoryview(memory)[0x10000:]
        put_word(bank,0x2F6,0x3000)
        put_word(bank,0x2F8,0x30F8)
        offset = 8
        for head,count in ((0x2FA,trial%13),(0x2FE,(trial*7)%13)):
            bank[head] = offset if count else 0
            for index in range(count):
                node = 0x3000+offset
                bank[node] = offset+8 if index+1<count else 0
                length = lengths[(trial+index)%len(lengths)]
                configure(memory,node,length,0x7E4000+offset*16,0x7E6000+offset*16)
                offset += 8
        expected = memory[:]
        run_queues(expected,rom)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xC9E5)
        expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
        assert c.wram==expected,('queues',trial)
        cases['run_queues'] += 1
    cases['initialize_pool'] = cases['allocate_record'] = cases['append_record'] = 0
    for trial in range(160):
        bank = bytearray(rng.randbytes(0x10000))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        if trial%7==0: bank[0xC4:0x1C4] = bytes((1,))*256
        put_word(bank,0xC2,0xA0)
        put_word(bank,0x9E,0 if trial%2 else 0x600)
        bank[0x604] = 2+trial%20
        expected = bank[:]
        initialize_pool(expected)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xC8C8)
        assert c.wram[0x10000:]==expected,('pool init',trial)
        cases['initialize_pool'] += 1
    for trial in range(240):
        bank = bytearray(rng.randbytes(0x10000))
        put_word(bank,0x2F6,0x3000)
        put_word(bank,0x2F8,0 if trial%4==0 else 0x3008)
        put_word(bank,0x3008,0x3010)
        put_word(bank,0x300,0x2FE if trial%2 else 0x3018)
        for name,address in (('allocate_record',0xC915),('append_record',0xC95A)):
            expected = bank[:]
            pointer = 0 if trial%3==0 else 0x3020
            if name=='allocate_record': result = allocate_record(expected)
            else: append_record(expected,pointer)
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = bank
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address,X=pointer)
            assert c.wram[0x10000:]==expected,(name,trial)
            if name=='allocate_record': assert c.X==result
            cases[name] += 1
    return {'cases':cases,'verified':True,'comparison':'all WRAM except caller scratch 1F80-1FFF; pool operations compare entire bank 7F, allocation X',
            'scope':'valid disjoint queues/destinations; inline, short pointer and MVN copies, including bank wrap; odd short source bytes 1/3/9/17, runaway word-counter case excluded'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
