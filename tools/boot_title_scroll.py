"""Recovered title word-scroll continuation and control exits.
usage: boot_title_scroll.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_wait,boot_ppu_queue,boot_parent_dispatch,boot_image,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def scroll(mem,stack,service):
    """$D348: decrement register0E words untilFFF0, dispatching every eight counts."""
    bank = memoryview(mem)[65536:]
    while True:
        node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],0x0E)
        value = (word(bank,node+2)-1)&65535
        put_word(bank,node+2,value)
        boot_ppu_queue.append_entry(bank,node)
        yield ('queue',0xD35D,node,value)
        service(mem)
        if value==0xFFF0: return value^0x80
        record,result = boot_parent_dispatch.dispatch(bank,8,stack-5)
        yield ('wait',0xD369,record,result)
        if not result: return 0


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    rng = random.Random(0xD348)
    cases = dict(complete=0,control_abort=0)
    updates = waits = 0
    fixtures = []
    for start in (0xFFF1,0xFFF2,0xFFF8,0,0x2F,0x30,0x100):
        steps = (start-0xFFF0)&65535
        fixtures.append((start,None))
        fixtures.extend((start,stop) for stop in sorted({1,steps//2,steps-1}) if 0<stop<steps)
    fixtures.extend((0x2F,stop) for stop in range(1,63) if (0x2F,stop) not in fixtures)
    fixtures.extend((0xFFF0,stop) for stop in (1,2,7,None))
    for start,stop in fixtures:
        cycle = start==0xFFF0 and stop is None
        expected = initial.wram[:]
        bank = memoryview(expected)[65536:]
        current = word(bank,0x9C)
        put_word(bank,0xA6,word(bank,current))
        put_word(bank,current,0)
        bank[current+2:current+6] = bytes((1,0,7,1))
        put_word(bank,current+12,0xF84)
        bank[0xF84:0xF88] = bytes((1,7,0,0))
        put_word(bank,0x9E,current)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        bank[0x96] &= ~64
        bank[0x311:0x318] = bytes((0,0,0,6 if stop else 0,4,0,0))
        mirror = word(bank,0x2E2)
        offset = expected[0x603E+0x0E]
        put_word(bank,mirror+offset,start)
        count = stop if stop else (((start-0xFFF0)&65535) or 65536)-1
        for index in range(0 if cycle else count):
            record = 0x2400+8*index
            bank[record:record+8] = rng.randbytes(8)
            put_word(bank,record,record+8 if index+1<count else 0)
            bank[record+2] = 6 if stop and index+1==count else 255
            put_word(bank,record+4,0xF84)
        put_word(bank,current+10,0x2400 if count and not cycle else 0)
        c = cpu.CPU()
        c.wram[:] = expected
        c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0xD348,1,0,0x300,0x7F
        c.push16(0xFFFD)
        actual_values = []
        last_node = None
        def service(mem):
            boot_ppu_queue.apply_shadow(memoryview(mem)[65536:],mem[0x603E:0x6072])
            boot_image.boundary_call(c,0xC18B)
            boot_transform.compare_memory(c.wram,mem,'word-scroll shadow service')
            if cycle and word(memoryview(mem)[65536:],mirror+offset)!=0xFFF0:
                boot_wait.notify_registration(memoryview(mem)[65536:],0xF84)
                boot_image.boundary_call(c,0xCC8C,X=0xF84)
                boot_transform.compare_memory(c.wram,mem,'full-cycle original timer delivery')
        model = scroll(expected,0x1FFD,service)
        while True:
            try: kind,end,node,value = next(model)
            except StopIteration as done:
                result = done.value
                break
            boot_image.run_until(c,0x7E0000|end)
            boot_transform.compare_memory(c.wram,expected,('title word-scroll',start,stop,kind,value))
            assert c.X==node
            last_node = node
            if kind=='queue':
                actual_values.append(value)
                updates += 1
            else: waits += 1
            c.step()
        boot_image.run_until(c,0x7EFFFE)
        boot_transform.compare_memory(c.wram,expected,('word-scroll return',start,stop))
        assert c.A==result==(0 if stop else 0xFF70) and c.X==last_node
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
        assert actual_values==[(start-index-1)&65535 for index in range(stop or count+1)]
        assert word(bank,mirror+offset)==actual_values[-1]
        assert word(bank,current+10)==0 and bank[0x314]==0 and bank[0x2DE+1]==0
        cases['control_abort' if stop else 'complete'] += 1
    return dict(verified=True,cases=cases,complete_word_cycle_steps=65536,compared_ppu_updates=updates,compared_dispatches=waits,comparison='full WRAM outside caller stack1F80-1FFF at queue/wait/shadow/return; queue/wait/final X, full return A and restored D/DB/S/M/X',scope='continuous original D348 calls, all62 early exits from real initial002F plus generated starts/control exits; real class42 register0E word shadow, available PPU/record resources, preloaded timers/control completion and explicit C18B service; one unbroken65536-step equal-endpoint cycle with supplied original CC8C delivery at each wait; empty-queue concurrency, exhaustion/pause/cancellation and physical timing open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
