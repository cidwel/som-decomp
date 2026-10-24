"""Recovered title row expansion and auxiliary HDMA table creation.
usage: boot_buffer_rows.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_heap,boot_copy_queue,boot_dma,boot_title_window,boot_transform

word,put_word = boot_tasks.word,boot_tasks.put_word


def row(mem,cursor,destination,data_bank=0x7F):
    """$8820: leading blanks, zero-terminated characters, pad to byte count32."""
    start = 0x59F8
    prefix = mem[start+cursor]
    if not prefix: return 0,destination,0
    count = prefix
    written = 0
    def emit(value):
        nonlocal destination,written
        mem[(data_bank-0x7E)*65536+destination] = value
        destination = (destination+2)&65535
        written += 1
    for _ in range(prefix): emit(0x60)
    cursor = (cursor+1)&65535
    while mem[start+cursor]:
        value = mem[start+cursor]
        emit(0x60 if value==0x20 else value)
        count = (count+1)&255
        cursor = (cursor+1)&65535
    cursor = (cursor+1)&65535
    while count<32:
        emit(0x60)
        count += 1
    return cursor,destination,written


def auxiliary(mem,slot,source,stack=0x1FFF):
    """$886E: raw52-byte reservation/copy, save pointer/descriptor and submit HDMA."""
    bank = memoryview(mem)[65536:]
    pointer = boot_heap.allocate_units(bank,1)
    boot_copy_queue.copy_pointer(mem,None,0x7E0000|source,0x7F0000|pointer,52)
    reference = ((stack-11)&65535)>>8
    descriptor = boot_dma.allocate_descriptor(bank,mem,reference<<8|5)
    put_word(bank,descriptor+2,pointer)
    put_word(bank,slot,pointer)
    put_word(bank,slot+2,descriptor)
    bank[descriptor+4] = 0x7F
    bank[descriptor+1] = 0x22
    bank[descriptor] = 2
    return descriptor,boot_dma.submit(bank,descriptor)


def validate(rom):
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0x8820)
    cases = dict(row=0,auxiliary=0)
    writes_total = 0
    for trial in range(320):
        expected = initial[:]
        cursor = (0,1,0xA600,0xFFF0)[trial%4]
        prefix = (0,1,2,31,32,127,128,255)[trial%8]
        length = (0,1,7,31,32,64,255)[(trial//8)%7]
        payload = bytes((prefix,))+bytes(rng.choice((0x20,0x60,rng.randrange(1,256))) for _ in range(length))+bytes((0,))
        for index,value in enumerate(payload): expected[0x59F8+((cursor+index)&65535)] = value
        data_bank = 0x7E if trial%3==0 else 0x7F
        destination = (0x3000,0xFFFC)[trial%2]
        # Destination canaries avoid overwriting the supplied source stream.
        for index in range(1200): expected[(data_bank-0x7E)*65536+((destination+index)&65535)] = rng.randrange(256)
        for index,value in enumerate(payload): expected[0x59F8+((cursor+index)&65535)] = value
        memory = expected[:]
        next_cursor,end,writes = row(expected,cursor,destination,data_bank)
        c = boot_title_window.RegisterCpu()
        c.wram[:] = memory
        c.D,c.DB,c.Y = 0x300,data_bank,destination
        boot_tasks.call(c,0x8820,X=cursor)
        boot_transform.compare_memory(c.wram,expected,('buffer row',trial))
        assert (c.X,c.Y)==(next_cursor,end) and (c.D,c.DB,c.S,c.M,c.XF)==(0x300,data_bank,0x1FFF,1,0)
        cases['row'] += 1
        writes_total += writes
    for trial in range(192):
        expected = initial[:]
        bank = memoryview(expected)[65536:]
        source = (0x5C93,0x5CC7,0x5CFB,0x6200)[trial%4]
        if source==0x6200: expected[source:source+52] = rng.randbytes(52)
        slot = (0x42,0x46,0x4A)[trial%3]
        channel = (trial//4)%8
        for higher in range(channel+1,8): bank[0x72+higher] = 99
        memory = expected[:]
        stack = (0x1FFF,0x02F9,0x07FF)[trial%3]
        node,writes = auxiliary(expected,slot,source,stack)
        c = boot_title_window.RegisterCpu()
        c.wram[:] = memory
        c.D,c.DB,c.Y = 0x300,0x7F,source
        c.S,c.PB,c.PC,c.M,c.XF,c.X = stack,0x7E,0x886E,1,0,slot
        c.push16(0xFFFD)
        while (c.PB<<16|c.PC)!=0x7EFFFE: c.step()
        scratch = (stack&0xFF00,stack+1)
        assert c.wram[:scratch[0]]==expected[:scratch[0]] and c.wram[scratch[1]:]==expected[scratch[1]:], ('auxiliary table',trial)
        assert c.X==channel*16 and c.writes==writes
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,stack,1,0)
        cases['auxiliary'] += 1
    return dict(verified=True,cases=cases,row_low_bytes_written=writes_total,comparison='full WRAM outside caller stack1F80-1FFF, row X/Y, auxiliary caller stack page excluded, channel register offset X, ordered HDMA registers and restored caller state',scope='320 row cases with source index/bank carry, destination word wrap, zero/prefix/count byte edges and caller DB7E/7F; 192 raw52-byte real/synthetic table copies across three slots/all eight HDMA channels and three caller stack pages/reference bytes; available resources; entire normal8D1A caller/88E7 setup, exhaustion and physical timing open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
