"""Recovered parent fade-in and title tilemap copy/submission.
usage: boot_parent_transition.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_parent_dispatch,boot_ppu_queue,boot_transform,boot_image,boot_vram,boot_dma,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def fade_in(mem,stack,apply):
    """$D20D: four-count receives, then increment the literal register00 byte to15."""
    bank = memoryview(mem)[65536:]
    classes = mem[0x603E:0x6072]
    while True:
        record,result = boot_parent_dispatch.dispatch(bank,4,stack-5)
        if not result: return record,0
        if bank[0x314]: continue
        node = boot_ppu_queue.allocate_entry(bank,classes,0)
        value = bank[node+2]
        if value>=15: return node,value
        value += 1
        bank[node+2] = value
        boot_ppu_queue.append_entry(bank,node)
        yield node,value
        apply(mem)
        if value>=15: return node,value


def copy_title_map(mem,offset):
    """$CD82: 29x32 low tile bytes from7E64A6, repeated attribute0310, queue BG map."""
    bank = memoryview(mem)[65536:]
    destination = word(bank,0x306)
    attribute = bank[0x310]
    for index in range(29*32):
        bank[destination+2*index] = mem[0x64A6+offset+index]
        bank[destination+2*index+1] = attribute
    boot_dma.queue_vram_buffer(bank,mem,destination)


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xD20D)
    cases = dict(fade_in=0,control_termination=0,title_map=0)
    updates = 0
    for trial in range(192):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        task = word(bank,0x9C)
        put_word(bank,0x9E,task)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,task,0)
        bank[task+2:task+6] = bytes((1,128,7,1))
        put_word(bank,task+12,0xF84)
        bank[0x96] &= ~64
        bank[0x311:0x316] = bytes((3,1,0,0,4))
        brightness = (0,1,7,14,15,0x80,0x8F,255)[trial%8]
        mirror = word(bank,0x2E2)
        put_word(bank,mirror,brightness|rng.randrange(256)<<8)
        stop = (trial//8)%4==3
        waiting = trial%3
        if stop: bank[0x314] = 2
        count = waiting+1 if stop else max(1,15-brightness)
        put_word(bank,task+10,0x2400)
        for index in range(count):
            record = 0x2400+8*index
            bank[record:record+8] = rng.randbytes(8)
            put_word(bank,record,record+8 if index+1<count else 0)
            bank[record+2] = 255
            put_word(bank,record+4,0xF84)
        if stop: bank[record+2] = 2
        expected = memory[:]
        c = cpu.CPU()
        c.wram[:] = memory
        c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0xD20D,1,0,0x300,0x7F
        c.push16(0xFFFD)
        def apply(mem):
            boot_ppu_queue.apply_shadow(memoryview(mem)[65536:],mem[0x603E:0x6072])
            boot_image.boundary_call(c,0xC18B)
            boot_transform.compare_memory(c.wram,mem,('fade-in shadow service',trial))
        model = fade_in(expected,0x1FFD,apply)
        while True:
            try: node,value = next(model)
            except StopIteration as end:
                result,flag = end.value
                break
            c.step()
            boot_image.run_until(c,0x7ED236)
            boot_transform.compare_memory(c.wram,expected,('fade-in queued step',trial,value))
            assert c.X==node
            updates += 1
        boot_image.run_until(c,0x7EFFFE)
        boot_transform.compare_memory(c.wram,expected,('fade-in return',trial))
        assert c.X==result and c.A&255==flag,('fade-in result',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),('fade-in restore',trial)
        cases['control_termination' if stop else 'fade_in'] += 1
    prepared = baseline[:]
    bank = memoryview(prepared)[65536:]
    source = boot_vram.create_buffer(bank,prepared,0x10)
    put_word(bank,0x306,source)
    for trial in range(256):
        memory = prepared[:]
        bank = memoryview(memory)[65536:]
        if trial>=2: memory[0x64A6:0x6BE6] = rng.randbytes(1856)
        bank[source:source+0x800] = rng.randbytes(0x800)
        bank[0x310] = rng.randrange(256)
        for _ in range(trial%4):
            node = boot_dma.allocate_descriptor(bank,memory,1)
            boot_dma.submit(bank,node)
        offset = 0 if trial%2==0 else 0x3A0
        expected = memory[:]
        copy_title_map(expected,offset)
        c = cpu.CPU()
        c.wram[:] = memory
        c.D,c.DB = 0x300,0x7F
        boot_tasks.call(c,0xCD82,X=offset)
        boot_transform.compare_memory(c.wram,expected,('title map',trial))
        e = memoryview(expected)[65536:]
        last = word(e,0x66)+2*(word(e,0x6C)-1)
        assert c.X==last and c.Y==word(e,last),('title map descriptor returns',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),('title map restore',trial)
        cases['title_map'] += 1
    return dict(verified=True,cases=cases,compared_ppu_updates=updates,title_maps=dict(real_sources=2,synthetic_cases=254,tile_entries=928,retained_destination_tail_bytes=192),comparison='all WRAM outside caller stack1F80-1FFF at each step/service/return, returned registers and ordered effects',scope='continuous original fade-in with preloaded timers/control notices, original C18B at supplied service boundaries; registered BG map with available heap/PPU/DMA records and real/synthetic config maps; pause/new control/physical PPU transfer and full parent task remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
