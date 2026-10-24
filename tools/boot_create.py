"""Recovered boot task creation, composed from checked frame/timer/heap models.
usage: boot_create.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_wait,boot_heap,boot_pool,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def create(mem,descriptor):
    """$7E:AAFF: pop a task record, allocate its frame/timer/workspace; no rollback."""
    bank = memoryview(mem)[0x10000:]
    node = word(bank,0xA6)
    if not node: return 0
    put_word(bank,0xA6,word(bank,node))
    put_word(bank,node,0)
    parent = boot_pool.task_id(bank)
    bank[node+5] = parent
    frame_node = boot_tasks.allocate_task_frame(mem,node,parent,descriptor)
    bank[frame_node+3],bank[frame_node+2] = descriptor[3],8
    registration = boot_wait.allocate_registration(bank,bank[frame_node+4])
    put_word(bank,node+12,registration)
    size = word(descriptor,8)
    workspace = boot_heap.allocate_bytes(bank,size,registration&255) if size else 0
    put_word(bank,node+8,workspace)
    return node

def spawn(mem,descriptor):
    """$7E:AB88: create, enqueue and increment active count when a record is returned."""
    node = create(mem,descriptor)
    if node:
        bank = memoryview(mem)[0x10000:]
        boot_tasks.enqueue(bank,node)
        put_word(bank,0x9A,(word(bank,0x9A)+1)&0xFFFF)
    return node

def select_next(mem):
    """$7E:A948 up to A961: select ready head or create the fallback task."""
    bank = memoryview(mem)[0x10000:]
    node = word(bank,0xA0)
    if not node:
        node = create(mem,mem[0x600A:0x6014])
        bank[0xBE] = bank[node+4]
    return node


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xAAFF)
    cases = dict(create=0,spawn=0)
    failures = dict(no_record=0,no_task_page=0,no_registration=0,no_workspace=0)
    for trial in range(320):
        memory = bytearray(rng.randbytes(0x20000))
        memory[:0x10000] = image
        bank = memoryview(memory)[0x10000:]
        node = 0x700
        put_word(bank,node,0x710)
        put_word(bank,0xA6,0 if trial%8==0 else node)
        put_word(bank,0x9E,0 if trial%3==0 else 0x600)
        bank[0x604] = 2+trial%20
        bank[0xAA:0xBE] = bytes((1,))*20
        slot = trial%21
        if slot<20: bank[0xAA+slot] = 0
        put_word(bank,0x302,0xF80)
        for i in range(32): bank[0xF80+4*i] = 1
        registration_index = trial%33
        if registration_index<32: bank[0xF80+4*registration_index] = 0
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        heap_full = trial%7==0
        if heap_full: bank[0xC4:0x1C4] = bytes((1,))*256
        put_word(bank,0xC2,0xA0)
        bank[0xC0] = 0x9F
        put_word(bank,0xA0,0x900)
        put_word(bank,0x900,0x910)
        put_word(bank,0x910,0)
        bank[0x903],bank[0x913] = 64,128
        size = 64 if heap_full else (0,1,128,129,256,1024)[trial%6]
        descriptor = bytearray(rng.randbytes(10))
        put_word(descriptor,8,size)
        # Alternate bank-7E and bank-7F descriptor sources, outside the allocations.
        descriptor_bank = (0x7E,0x7F)[trial%2]
        descriptor_offset = 0x1800
        absolute = (descriptor_bank-0x7E)*0x10000+descriptor_offset
        memory[absolute:absolute+10] = descriptor
        for name,address,model in (('create',0xAAFF,create),('spawn',0xAB88,spawn)):
            expected = memory[:]
            result = model(expected,descriptor)
            c = cpu.CPU()
            c.wram[:] = memory
            c.DB,c.D = 0x7F,rng.randrange(65536)
            boot_tasks.call(c,address,A=descriptor_bank|(rng.randrange(256)<<8),X=descriptor_offset)
            # The local ten-byte copy and nested calls use caller scratch; all task pages count.
            expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
            assert c.wram==expected and c.X==result,(name,trial)
            cases[name] += 1
        if not word(bank,0xA6): failures['no_record'] += 1
        elif slot==20: failures['no_task_page'] += 1
        elif registration_index==32: failures['no_registration'] += 1
        elif heap_full: failures['no_workspace'] += 1
    cases['select_next'] = 0
    c,_ = boot_tasks.initialized(rom)
    initialized = c.wram[:]
    for trial in range(160):
        memory = initialized[:]
        bank = memoryview(memory)[0x10000:]
        if trial%3==0:
            put_word(bank,0xA0,0x700)
            bank[0x704] = 2+trial%20
        else:
            put_word(bank,0xA0,0)
            if trial%5==0: put_word(bank,0xA6,0)
            if trial%7==0: bank[0xAA:0xBE] = bytes((1,))*20
        expected = memory[:]
        result = select_next(expected)
        c = cpu.CPU()
        c.wram[:] = memory
        c.S,c.PB,c.PC,c.DB,c.M,c.XF = 0x1FFF,0x7E,0xA948,0x7F,1,0
        for _ in range(5000):
            c.step()
            if c.PB<<16|c.PC==0x7EA961: break
        else: raise RuntimeError('next-task selection timeout')
        expected[0x1F80:0x2000] = c.wram[0x1F80:0x2000]
        assert c.wram==expected and c.X==result and c.M==0 and c.S==0x1FFF,('select',trial)
        cases['select_next'] += 1
    return {'cases':cases,'verified':True,'failure_cases':failures,
            'comparison':'all WRAM except caller scratch 1F80-1FFF; returned X',
            'scope':'native ABI DB=7F; valid frame/timer/heap tables and queues, descriptors from banks 7E/7F; partial-resource failures retained'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
