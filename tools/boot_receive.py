"""Recovered timer setup and task message receive phases, checked through live dispatch.
usage: boot_receive.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_wait,boot_pool,boot_create,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def set_timer(mem,registration,count):
    """$7E:CC16: replace the countdown and enable waiting only for a nonzero word."""
    put_word(mem,registration+2,count)
    mem[registration] = 2 if count else 1

def prepare_receive(mem,node,delay=None):
    """ABAD uses the existing timer; ABE7 uses a supplied delay or a nonblocking yield."""
    registration = word(mem,node+12)
    if delay is None: boot_wait.mark_waiting(mem,registration)
    elif delay: set_timer(mem,registration,delay)
    elif not word(mem,node+10): put_word(mem,node+10,0xFFFF)

def finish_receive(mem,node,record,delay=None):
    """After resumption, disarm timer and consume FF notifications according to the entry."""
    registration = word(mem,node+12)
    boot_wait.mark_ready(mem,registration)
    if record and mem[record+2]==255:
        if delay is None or word(mem,record+4)==registration:
            boot_pool.release(mem,record)
            return 0
    return record

def release_irq(mem):
    """$7E:A241: decrement the IRQ-use count; clear vertical IRQ at zero."""
    if mem[0x8C]: mem[0x8C] -= 1
    if not mem[0x8C]:
        mem[0x90] &= 0xDF
        return mem[0x90]
    return None

def finish_idle(mem,node,stack):
    """A8BE with no active tasks: one nonblocking receive, then release IRQ use."""
    prepare_receive(mem,node,0)
    put_word(mem,node+6,stack-14)
    put_word(mem,node,0)
    mem[node+2] = 1
    consumed = word(mem,node+10)
    put_word(mem,node+10,boot_pool.take_link(mem,consumed))
    finish_receive(mem,node,0 if consumed==0xFFFF else consumed,0)
    return release_irq(mem)


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xABE7)
    cases = dict(set_timer=0,receive_existing_timer=0,receive_supplied_delay=0)
    for trial in range(240):
        memory = bytearray(rng.randbytes(0x10000))
        registration = 0xF84
        count = (0,1,255,256,65535,rng.randrange(65536))[trial%6]
        expected = memory[:]
        set_timer(expected,registration,count)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        c.Y,c.DB = count,rng.randrange(256)
        boot_tasks.call(c,0xCC16,X=registration)
        assert c.wram[0x10000:]==expected,('timer',trial)
        cases['set_timer'] += 1
    for trial in range(320):
        memory = bytearray(rng.randbytes(0x10000))
        node,registration = 0x700,0xF84
        put_word(memory,0x9E,node)
        put_word(memory,0xA0,0)
        put_word(memory,0xA2,0)
        put_word(memory,node+12,registration)
        put_word(memory,0x2C6,0x2600)
        memory[node+2],memory[node+3],memory[node+4] = 1,128,3
        record = (0xFFFF,0x2400,0x2400,0x2400)[trial%4]
        put_word(memory,node+10,record)
        put_word(memory,0x2400,0 if trial%2 else 0x2408)
        memory[0x2402] = (0,1,255,255)[trial%4]
        put_word(memory,0x2404,registration if trial%3 else 0xF80)
        for name,address,delay in (('receive_existing_timer',0xABAD,None),
                                   ('receive_supplied_delay',0xABE7,(0,1,256,65535)[trial%4])):
            expected = memory[:]
            prepare_receive(expected,node,delay)
            # No other ready task: suspend, select and resume the same task without a hook.
            put_word(expected,node+6,0x1FFD-12)
            put_word(expected,node,0)
            expected[node+2] = 1
            consumed = word(expected,node+10)
            put_word(expected,node+10,boot_pool.take_link(expected,consumed))
            result = finish_receive(expected,node,0 if consumed==0xFFFF else consumed,delay)
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = memory
            c.DB,c.D = rng.randrange(256),rng.randrange(65536)
            boot_tasks.call(c,address,X=0 if delay is None else delay)
            assert c.wram[0x10000:]==expected and c.X==result,(name,trial)
            cases[name] += 1
    cases['empty_queue_timer_resume'] = 0
    c,_ = boot_tasks.initialized(rom)
    initialized = c.wram[:]
    class TimerCpu(cpu.CPU):
        def rd8(self,address):
            if address in (0x2137,0x213D): return 0
            return super().rd8(address)
    for trial in range(96):
        memory = initialized[:]
        bank = memoryview(memory)[0x10000:]
        node,registration = 0x700,0xF84
        count = 1+trial%4
        delay = None if trial%2 else count
        put_word(bank,0x9E,node)
        put_word(bank,0x9A,1)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node,0)
        put_word(bank,node+10,0)
        put_word(bank,node+12,registration)
        bank[node+2],bank[node+3],bank[node+4],bank[node+5] = 1,128,3,1
        bank[0xAB] = 1  # Original caller owns page/id 3; fallback will reserve id 2.
        bank[registration],bank[registration+1] = 1,3
        put_word(bank,registration+2,count)
        expected = memory[:]
        e = memoryview(expected)[0x10000:]
        prepare_receive(e,node,delay)
        put_word(e,node+6,0x03DE-12)
        e[node+2] = 4
        put_word(e,0xA2,node)
        idle = boot_create.select_next(expected)
        boot_tasks.dispatch_frame(expected,idle)
        for _ in range(count):
            boot_wait.tick_registrations(e,iter([0]*32))
            if not word(e,idle+10): put_word(e,idle+10,0xFFFF)
            put_word(e,idle+6,0x02EB)
            e[idle+2] = 2
            boot_tasks.enqueue(e,idle)
            chosen = word(e,0xA0)
            put_word(e,0xA0,word(e,chosen))
            put_word(e,chosen,0)
            put_word(e,0x9E,chosen)
            e[chosen+2] = 1
            consumed = word(e,chosen+10)
            put_word(e,chosen+10,boot_pool.take_link(e,consumed))
            finish_receive(e,chosen,0 if consumed==0xFFFF else consumed,0 if chosen==idle else delay)
        assert chosen==node
        c = TimerCpu()
        c.wram[:] = memory
        c.S,c.PB,c.PC,c.M,c.XF,c.DB,c.D,c.X = 0x03E0,0x7E,0xABAD if delay is None else 0xABE7,1,0,0x7F,0x0300,0 if delay is None else delay
        c.push16(0xFFFD)
        serviced,ticks = False,0
        for _ in range(20000):
            address = c.PB<<16|c.PC
            if address==0x7EFFFE: break
            if address==0x7EA8C0 and not serviced:
                # Call the real timer service from the fallback task, with controlled PPU reads.
                # No suspension, dispatch, delivery or allocation routine is bypassed.
                serviced = True
                ticks += 1
                c.push16(0xA8BF)
                c.PC = 0xCCB7
            elif address==0x7EA8C3: serviced = False
            c.step()
        else: raise RuntimeError('empty-queue timer receive timeout')
        assert ticks==count and c.X==0 and c.S==0x03E0,('timer return',trial,ticks,c.X,c.S)
        assert c.wram[0x10000:]==e,('timer receive memory',trial)
        cases['empty_queue_timer_resume'] += 1
    class ControlCpu(cpu.CPU):
        def __init__(self):
            super().__init__()
            self.control_writes = []
        def hwwrite(self,address,value):
            if address==0x4200: self.control_writes.append(value&255)
            super().hwwrite(address,value)
    cases['release_irq'] = cases['idle_outer_return'] = 0
    for trial in range(160):
        bank = bytearray(rng.randbytes(0x10000))
        bank[0x8C] = (0,1,2,255,rng.randrange(256))[trial%5]
        expected = bank[:]
        control = release_irq(expected)
        c = ControlCpu()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xA241)
        assert c.wram[0x10000:]==expected and c.control_writes==([] if control is None else [control]),('release IRQ',trial)
        cases['release_irq'] += 1
    for trial in range(96):
        memory = initialized[:]
        bank = memoryview(memory)[0x10000:]
        node = boot_create.select_next(memory)
        target,stack = boot_tasks.dispatch_frame(memory,node)
        assert target==0x7EA8BE and stack==0x02F9
        put_word(bank,0x9A,0)
        bank[0x8C] = (0,1,2,255)[trial%4]
        bank[0x90] = rng.randrange(256)
        outer = 0x1F00
        put_word(bank,0x98,outer)
        original_db,original_p,direct = rng.randrange(256),rng.randrange(256),(0,0x8000,rng.randrange(65536))[trial%3]
        memory[outer+1],memory[outer+2] = original_db,original_p
        put_word(memory,outer+3,direct)
        put_word(memory,outer+5,0xEFFF)
        expected = memory[:]
        e = memoryview(expected)[0x10000:]
        control = finish_idle(e,node,stack)
        c = ControlCpu()
        c.wram[:] = memory
        c.PB,c.PC,c.S,c.DB,c.D,c.M,c.XF = 0x7E,0xA8BE,stack,0x7F,0x0200,1,0
        for _ in range(2000):
            c.step()
            if c.PB<<16|c.PC==0x7EF000: break
        else: raise RuntimeError('idle outer return timeout')
        flags = (original_p&0x7D)|(0x80 if direct&0x8000 else 0)|(2 if direct==0 else 0)
        assert c.wram[0x10000:]==e and c.control_writes==([] if control is None else [control]),('idle memory',trial)
        assert (c.DB,c.D,c.P(),c.S)==(original_db,direct,flags,outer+6),('idle frame',trial)
        cases['idle_outer_return'] += 1
    return {'cases':cases,'verified':True,'comparison':'entire bank 7F; receive X; IRQ-control writes; idle restores outer DB/D/P/PC/S',
            'scope':'preloaded message or FFFF yield sentinel; original suspension/selection/dispatch execute, no game hooks; 96 empty blocking-queue cases execute fallback plus the real timer scanner with controlled service calls/PPU reads; not IRQ timing'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
