"""Recovered parent fade-out with original timed dispatch and explicit PPU shadow service.
usage: boot_parent_fade.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_parent_dispatch,boot_ppu_queue,boot_transform,boot_image,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def fade(mem,stack,apply):
    """$D1DA: wait in four-count receives, then decrease register00 until zero."""
    bank = memoryview(mem)[65536:]
    classes = mem[0x603E:0x6072]
    while True:
        record,result = boot_parent_dispatch.dispatch(bank,4,stack-5)
        if not result: return record,0
        if bank[0x314]: continue
        node = boot_ppu_queue.allocate_entry(bank,classes,0)
        if not bank[node+2]: return node,1
        bank[node+2] = (bank[node+2]-1)&255
        value = bank[node+2]
        boot_ppu_queue.append_entry(bank,node)
        yield node,value
        apply(mem)
        if not value: return node,1


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xD1DA)
    cases = dict(fade=0,control_termination=0)
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
        brightness = (0,1,2,7,15,0x80,0x8F,3)[trial%8]
        mirror = word(bank,0x2E2)
        put_word(bank,mirror,brightness|rng.randrange(256)<<8)
        stop = trial%4==3
        waiting = trial%3
        if stop: bank[0x314] = 2
        count = waiting+1 if stop else max(1,brightness)
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
        c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0xD1DA,1,0,0x300,0x7F
        c.push16(0xFFFD)
        def apply(mem):
            boot_ppu_queue.apply_shadow(memoryview(mem)[65536:],mem[0x603E:0x6072])
            boot_image.boundary_call(c,0xC18B)
            boot_transform.compare_memory(c.wram,mem,('fade shadow service',trial))
        model = fade(expected,0x1FFD,apply)
        while True:
            try: node,value = next(model)
            except StopIteration as end:
                result,flag = end.value
                break
            c.step()
            boot_image.run_until(c,0x7ED203)
            boot_transform.compare_memory(c.wram,expected,('fade queued step',trial,value))
            assert c.X==node
            updates += 1
        boot_image.run_until(c,0x7EFFFE)
        boot_transform.compare_memory(c.wram,expected,('fade return',trial))
        assert c.X==result and c.A&255==flag,('fade result',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),('fade restore',trial)
        cases['control_termination' if stop else 'fade'] += 1
    return dict(verified=True,cases=cases,compared_ppu_updates=updates,comparison='all WRAM outside caller stack1F80-1FFF after queued steps, original shadow service and return; X/lowA and restored D/DB/S/M/X',scope='continuous original D1DA with all D17F/receive/PPU callees, preloaded timer/control records and no pause/new control creation; original C18B applied at supplied service boundaries, literal forced-blank brightness bytes included; physical PPU writes/IRQ timing remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
