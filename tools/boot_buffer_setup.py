"""Recovered normal title-buffer display setup.
usage: boot_buffer_setup.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_heap,boot_dma,boot_copy_queue,boot_buffer_rows,boot_buffer_cleanup,boot_ppu_queue,boot_title_window

word,put_word = boot_tasks.word,boot_tasks.put_word


def setup(mem,stack=0x1FFF):
    """$88E7: scrolling table, seven HDMA descriptors and six register writes."""
    bank = memoryview(mem)[65536:]
    writes = []
    for offset,value in ((0x56,0x78),(0x59,0x1F),(0x5C,0x38),(0x5F,1),(0x62,0)):
        bank[offset] = value
    for offset in (0x57,0x5A,0x5D,0x60): put_word(bank,offset,0)
    def descriptor(slot,source,source_bank,register,mode,reference):
        node = boot_dma.allocate_descriptor(bank,mem,reference<<8|5)
        put_word(bank,slot,node)
        put_word(bank,node+2,source)
        bank[node+4],bank[node+1],bank[node] = source_bank,register,mode
        writes.extend(boot_dma.submit(bank,node))
    descriptor(0x3A,0x56,0x7F,0x10,2,0)
    for slot,source in ((0x4A,0x5CFB),(0x46,0x5CC7),(0x42,0x5C93)):
        _,programming = boot_buffer_rows.auxiliary(mem,slot,source,(stack-6)&65535)
        writes.extend(programming)
    descriptor(0x40,0x5C75,0x7E,0x21,0,((stack-11)&65535)>>8)
    for pointer_slot,descriptor_slot,source,register in ((0x54,0x3E,0x5C64,0x2D),(0x52,0x3C,0x5C53,0x27)):
        pointer = boot_heap.allocate_units(bank,1)
        put_word(bank,pointer_slot,pointer)
        boot_copy_queue.copy_pointer(mem,None,0x7E0000|source,0x7F0000|pointer,17)
        descriptor(descriptor_slot,pointer,0x7F,register,0,((stack-5)&65535)>>8)
    for register,value in ((0x26,0),(0x27,0xFF),(0x30,2),(0x31,0x31),(0x2E,2),(0x23,0x30)):
        node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],register)
        bank[node+2] = value
        boot_ppu_queue.append_entry(bank,node)
    return node,writes


def validate(rom):
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0x88E7)
    for trial in range(96):
        expected = initial[:]
        bank = memoryview(expected)[65536:]
        current = word(bank,0x9C)
        put_word(bank,0x9E,current)
        bank[current+4] = (1,2,7,19)[trial%4]
        if trial%2: bank[0x79] = 99
        mirror = word(bank,0x2E2)
        for register in (0x26,0x27,0x30,0x31,0x2E,0x23):
            kind = expected[0x603E+register]
            put_word(bank,mirror+(kind if kind>1 else register),rng.randrange(65536))
        if trial%3==0:
            for source,length in ((0x5C53,17),(0x5C64,17),(0x5C93,52),(0x5CC7,52),(0x5CFB,52)):
                expected[source:source+length] = rng.randbytes(length)
        stack = (0x1FFF,0x02F9,0x07FF)[trial%3]
        memory = expected[:]
        final_x,writes = setup(expected,stack)
        c = boot_title_window.RegisterCpu()
        c.wram[:] = memory
        c.S,c.PB,c.PC,c.D,c.DB,c.M,c.XF = stack,0x7E,0x88E7,0x300,0x7F,1,0
        c.push16(0xFFFD)
        while (c.PB<<16|c.PC)!=0x7EFFFE: c.step()
        scratch = (stack&0xFF00,stack+1)
        def compare(label,service=False):
            excluded = [scratch]+([(0x1F80,0x2000)] if service else [])
            cursor = 0
            for start,end in sorted(excluded):
                if start>cursor: assert c.wram[cursor:start]==expected[cursor:start], (label,trial)
                cursor = max(cursor,end)
            assert c.wram[cursor:]==expected[cursor:], (label,trial)
        compare('buffer setup')
        assert c.X==final_x and c.writes==writes, ('register output',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,stack,1,0)
        boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
        boot_tasks.call(c,0xC18B)
        compare('setup shadow',service=True)
        boot_buffer_cleanup.cleanup(expected)
        boot_tasks.call(c,0x8CA6)
        compare('setup cleanup',service=True)
        assert not any(bank[0x72:0x79]) and bank[0x79]==(99 if trial%2 else 0)
        boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
        boot_tasks.call(c,0xC18B)
        compare('cleanup shadow',service=True)
    return dict(verified=True,cases=96,comparison='full WRAM outside active caller stack (and1F80-1FFF for explicit services), returned X, ordered seven HDMA submissions, restored caller state, original C18B shadow and8CA6 cleanup',scope='normal88E7 preparation with three caller stack pages, four task owners, seven/eight available channels, real/synthetic table payloads and seeded register high bytes; normal8D1A message/animation composition, exhaustion and physical timing remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
