"""Recovered title buffer-task cleanup and forced-stop continuation.
usage: boot_buffer_cleanup.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_create,boot_title_teardown,boot_cleanup,boot_image,boot_heap,boot_dma,boot_ppu_queue,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def release_auxiliary(mem,slot):
    """$88CF: release descriptor slot+2 and heap slot, retaining both pointers."""
    boot_dma.release_descriptor(mem,word(mem,slot+2))
    boot_heap.free_units(mem,word(mem,slot))


def cleanup(mem):
    """$8CA6, also called by8DA0: release seven descriptors/three buffers, queue five defaults."""
    bank = memoryview(mem)[65536:]
    boot_dma.release_descriptor(bank,word(bank,0x3A))
    for slot in (0x4A,0x46,0x42): release_auxiliary(bank,slot)
    for slot in (0x40,0x3E,0x3C): boot_dma.release_descriptor(bank,word(bank,slot))
    for register,value in ((0x26,0),(0x30,0x30),(0x31,0),(0x2E,0),(0x23,0)):
        node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],register)
        bank[node+2] = value
        boot_ppu_queue.append_entry(bank,node)


def fixture(initial,rng,trial,owner=3):
    mem = initial[:]
    bank = memoryview(mem)[65536:]
    current = word(bank,0x9E) or word(bank,0x9C)
    put_word(bank,0x9E,current)
    bank[current+4] = owner
    for index,slot in enumerate((0x3A,0x40,0x3E,0x3C,0x44,0x48,0x4C)):
        put_word(bank,slot,0)
        if (trial+index)%4:
            reference = 1+(trial+index)%32
            flag = 5 if (trial+index)%3==0 else 1
            node = boot_dma.allocate_descriptor(bank,mem,reference<<8|flag)
            put_word(bank,slot,node)
            boot_dma.submit(bank,node)
    for index,slot in enumerate((0x42,0x46,0x4A)):
        pointer = boot_heap.allocate_units(bank,1+(trial+index)%8) if (trial+index)%5 else 0
        put_word(bank,slot,pointer)
    mirror = word(bank,0x2E2)
    for register in (0x26,0x30,0x31,0x2E,0x23):
        kind = mem[0x603E+register]
        put_word(bank,mirror+(kind if kind>1 else register),rng.randrange(65536))
    return mem


def validate(rom):
    cpu.set_rom(rom)
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0x8CA6)
    cases = dict(auxiliary_release=0,resource_cleanup=0,stop_continuation=0)
    for trial in range(160):
        for name,address in (('auxiliary_release',0x88CF),('resource_cleanup',0x8CA6),('stop_continuation',0x8DA0)):
            expected = fixture(initial,rng,trial)
            bank = memoryview(expected)[65536:]
            retained = bytes(bank[0x3A:0x4E])
            memory = expected[:]
            if name=='auxiliary_release': release_auxiliary(bank,0x4A)
            else: cleanup(expected)
            c = cpu.CPU()
            c.wram[:] = memory
            c.D,c.DB = 0x300,0x7F
            boot_tasks.call(c,address,X=0x4A)
            boot_transform.compare_memory(c.wram,expected,('buffer cleanup',name,trial))
            assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
            assert bytes(bank[0x3A:0x4E])==retained
            if name!='auxiliary_release':
                boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
                boot_tasks.call(c,0xC18B)
                boot_transform.compare_memory(c.wram,expected,('cleanup shadow service',name,trial))
            cases[name] += 1
    return dict(verified=True,cases=cases,comparison='full WRAM outside caller stack1F80-1FFF, retained resource pointers and restored D/DB/S/M/X; original C18B shadow service for both cleanup entries',scope='480 complete original calls, real configuration classes, mixed absent/live descriptors and allocated/zero heap pointers; available PPU/descriptor/channel/heap resources; release and queue helpers execute; isolated checks; stopped dispatch composition is checked separately, normal8D1A body, exhaustion and physical timing open')


def validate_stopped_dispatch(rom):
    """Original spawn/stop/continuation/completion/reap at explicit preparation boundaries."""
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0x8DA0)
    cases = dict(ready_stop=0,waiting_stop=0)
    for trial in range(32):
        c = cpu.CPU()
        c.wram[:] = initial
        bank = memoryview(c.wram)[65536:]
        parent = word(bank,0x9C)
        put_word(bank,0xA6,word(bank,parent))
        put_word(bank,parent,0)
        bank[parent+2:parent+6] = bytes((1,128,7,1))
        bank[0xAA+5] = 1
        put_word(bank,0x9E,parent)
        put_word(bank,0x9A,1)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0xFFFE,1,0,0x300,0x7F
        expected = c.wram[:]
        child = boot_create.spawn(expected,expected[0x5EA0:0x5EAA])
        boot_image.boundary_call(c,0xAB88,A=0x7E,X=0x5EA0)
        boot_transform.compare_memory(c.wram,expected,'buffer child spawn')
        assert bank[child+4]==2
        put_word(bank,0x9E,child)
        c.wram[:] = fixture(c.wram,rng,trial,owner=2)
        put_word(bank,0x9E,parent)
        waiting = trial%2
        if waiting:
            put_word(bank,0xA0,0)
            put_word(bank,0xA2,child)
            put_word(bank,child,0)
            bank[child+2] = 4
            put_word(bank,child+6,0x2D0)
        expected = c.wram[:]
        boot_title_teardown.stop_task(memoryview(expected)[65536:],2)
        boot_image.boundary_call(c,0xACAC,A=2)
        boot_transform.compare_memory(c.wram,expected,'buffer child stop request')
        assert word(bank,0xA0)==child and bank[child+2]==16
        expected = c.wram[:]
        target,stack = boot_tasks.dispatch_frame(expected,child)
        c.PB,c.PC,c.X,c.M,c.XF = 0x7E,0xA961,child,0,0
        boot_image.run_until(c,target)
        assert target==0x7E8DA0 and c.S==stack==0x2F9 and c.D==0x200
        boot_transform.compare_memory(c.wram,expected,'stopped child continuation entry')
        cleanup(expected)
        boot_image.run_until(c,0x7EAA22)
        def compare(label):
            assert c.wram[:0x200]==expected[:0x200] and c.wram[0x300:0x1F80]==expected[0x300:0x1F80] and c.wram[0x2000:]==expected[0x2000:],label
        compare('continuous original stopped continuation cleanup')
        boot_tasks.complete_task(expected)
        boot_image.run_until(c,0x7EA948)
        compare('continuous original stopped-task completion')
        assert word(bank,0xA4)==child and word(bank,0x9A)==1 and bank[child+2]==16
        boot_ppu_queue.apply_shadow(memoryview(expected)[65536:],expected[0x603E:0x6072])
        boot_image.boundary_call(c,0xC18B)
        compare('stopped continuation shadow service')
        registration = word(bank,child+12)
        workspace = word(bank,child+8)
        boot_cleanup.reap_one(expected)
        boot_image.boundary_call(c,0xA9C7)
        compare('stopped continuation original task reap')
        assert word(bank,0xA4)==0 and word(bank,0xA6)==child and bank[0xAA]==0
        assert word(bank,child+2)==word(bank,child+4)==0 and bank[registration]==0
        assert 2 not in bank[0x1C4:0x2C4]
        if workspace: assert bank[0xC4+(workspace>>7)]==0
        cases['waiting_stop' if waiting else 'ready_stop'] += 1
    return dict(verified=True,cases=cases,comparison='full WRAM at spawn/stop/dispatch; cleanup/completion/shadow/reap outside child page0200-02FF and caller scratch1F80-1FFF, selected continuation/frame, active count and freed task resources',scope='32 original descriptor5EA0 ready/waiting stop compositions; resources prepared at explicit boundary with child owner2; actual ACAC/A961/8DA0/8CA6/AA22 and original C18B/A9C7 execute, no game hooks; normal8D1A body, parent concurrency, IRQ timing and exhaustion open')


def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    report['stopped_dispatch'] = validate_stopped_dispatch(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
