"""Recovered boot task initialization and checked priority-queue model.
usage: boot_tasks.py ROM [--json OUT]
"""
import sys, json, random, romio, boot_decode, cpu65816 as cpu

def word(mem, at):
    return mem[at] | mem[at + 1] << 8

def put_word(mem, at, value):
    mem[at] = value & 0xFF
    mem[at + 1] = value >> 8

def enqueue(mem, node):
    """$7E:A8D6: insert after all existing tasks of equal or lower priority."""
    previous = 0xA0
    current = word(mem, previous)
    while current and mem[node + 3] >= mem[current + 3]:
        previous = current
        current = word(mem, current)
    put_word(mem, previous, node)
    put_word(mem, node, current)

def prepare_frame(mem, base, descriptor):
    """$7E:AA42: initial RTL chain for task entry, exit stub and continuation."""
    put_word(mem, base + 0xFA, 0xAA21)
    put_word(mem, base + 0xF7, (word(descriptor, 0) - 1) & 0xFFFF)
    put_word(mem, base + 0xFD, (word(descriptor, 4) - 1) & 0xFFFF)
    mem[base + 0xFC] = 0x7E
    mem[base + 0xF9] = mem[base + 0xFF] = descriptor[2]

def complete_task(mem):
    """$7E:AA22: queue the current task for its continuation and decrease active count."""
    bank = memoryview(mem)[0x10000:]
    node = word(bank, 0x9E)
    bank[node+2] = 0x10
    put_word(bank, node, word(bank, 0xA4))
    put_word(bank, 0xA4, node)
    put_word(bank, 0x9A, (word(bank, 0x9A)-1)&0xFFFF)

def dispatch_frame(mem, node):
    """$7E:A961: enter a new task or its completion continuation; return target and S."""
    bank = memoryview(mem)[0x10000:]
    status = bank[node+2]
    assert status in (8,16)
    put_word(bank, 0xA0, word(bank, node))
    put_word(bank, node, 0)
    put_word(bank, 0x9E, node)
    stack = word(bank, node+6)
    if status == 16:
        base = stack&0xFF00
        stack = base+0xF6
        mem[base+0xF7:base+0xFA] = mem[base+0xFD:base+0x100]
    bank[node+2] = 1
    target = mem[stack+3]<<16 | ((word(mem,stack+1)+1)&0xFFFF)
    return target, stack+3

def allocate_task_frame(mem,node,parent,descriptor):
    """$7E:AA77: reserve one of twenty task ids/pages and prepare its return chain."""
    bank = memoryview(mem)[0x10000:]
    for index in range(20):
        if bank[0xAA+index]: continue
        task_id = index+2
        bank[0xAA+index] = parent
        bank[node+4] = task_id
        put_word(bank,node+6,(task_id<<8)+0xF6)
        prepare_frame(mem,task_id<<8,descriptor)
        return node
    return 0

def free_task_frame(mem,node):
    """$7E:AAD7: release the id implied by saved S and prepend the task's free record."""
    bank = memoryview(mem)[0x10000:]
    slot = (((word(bank,node+6)-0x200)&0xFF00)>>8)+0xAA
    bank[slot] = 0
    put_word(bank,node,word(bank,0xA6))
    put_word(bank,0xA6,node)
    return slot

def call(c, address, A=None, X=None, step_limit=1_000_000):
    c.S, c.PB, c.PC, c.M, c.XF = 0x1FFF, 0x7E, address, 1, 0
    if A is not None: c.A = A
    if X is not None: c.X = X
    c.push16(0xFFFD)
    start = c.steps
    while (c.PB << 16 | c.PC) != 0x7EFFFE:
        c.step()
        if c.steps - start > step_limit:
            raise RuntimeError('boot task routine timeout')
    return c.steps - start

def initialized(rom):
    cpu.set_rom(rom)
    c = cpu.CPU()
    image, _ = boot_decode.decode(rom, boot_decode.BOOT_SOURCE, boot_decode.BOOT_DEST)
    c.wram[:0x10000] = image
    return c, call(c, 0xAD75)

def validate(rom):
    spawned = []
    for descriptor in (0x6488, 0x5EC3):
        c, steps = initialized(rom)
        priority = c.wram[descriptor + 3]
        entry = int.from_bytes(c.wram[descriptor:descriptor + 3], 'little')
        assert c.rd16(0x7F00A6) == 0x0600
        spawn_steps = call(c, 0xAB88, A=0x7E, X=descriptor)
        assert c.X == 0x0600 and c.rd16(0x7F00A0) == 0x0600
        assert c.rd16(0x7F00A6) == 0x0610 and c.rd16(0x7F009A) == 1
        assert c.wram[0x10603] == priority and c.wram[0x10602] == 8
        spawned.append({'descriptor': '7E%04X' % descriptor, 'entry': '%06X' % entry,
                        'priority': priority, 'task': '7F0600', 'task_id': c.wram[0x10604],
                        'initialization_steps': steps, 'spawn_steps': spawn_steps})
    dispatched = []
    for descriptors in ((0x6488,), (0x5EC3,), (0x5EC3, 0x6488)):
        c, _ = initialized(rom)
        for descriptor in descriptors:
            call(c, 0xAB88, A=0x7E, X=descriptor)
        first = min(descriptors, key=lambda at: c.wram[at + 3])
        target = int.from_bytes(c.wram[first:first + 3], 'little')
        node = c.rd16(0x7F00A0)
        next_node = c.rd16(0x7F0000 | node)
        stack = c.rd16(0x7F0000 | (node + 6))
        c.PB, c.PC, c.X, c.DB, c.M, c.XF = 0x7E, 0xA961, node, 0x7F, 0, 0
        steps = 0
        while (c.PB << 16 | c.PC) != target:
            c.step()
            steps += 1
            if steps > 100:
                raise RuntimeError('new-task dispatch did not reach its entry')
        assert c.rd16(0x7F00A0) == next_node and c.rd16(0x7F0000 | node) == 0
        assert c.rd16(0x7F009E) == node and c.rd8(0x7F0000 | (node + 2)) == 1
        assert c.S == stack + 3 and c.I == 0
        dispatched.append({'descriptors': ['7E%04X' % at for at in descriptors],
                           'entry': '%06X' % target, 'task': '7F%04X' % node,
                           'dispatch_steps': steps, 'entry_stack': c.S,
                           'remaining_head': '7F%04X' % next_node if next_node else None})
    rng = random.Random(0xA8D6)
    image, _ = boot_decode.decode(rom, boot_decode.BOOT_SOURCE, boot_decode.BOOT_DEST)
    cases = 0
    for trial in range(320):
        count = trial % 21
        priorities = sorted(rng.randrange(256) for _ in range(count))
        priority = (0, 255, priorities[0] if priorities else 0, rng.randrange(256))[trial % 4]
        memory = bytearray(rng.randbytes(0x10000))
        nodes = [0x0600 + i * 16 for i in range(count)]
        put_word(memory, 0xA0, nodes[0] if nodes else 0)
        for i, node in enumerate(nodes):
            put_word(memory, node, nodes[i + 1] if i + 1 < count else 0)
            memory[node + 3] = priorities[i]
        new = 0x0800
        memory[new + 3] = priority
        expected = memory[:]
        enqueue(expected, new)
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = memory
        c.DB = 0x7F
        call(c, 0xA8D6, X=new)
        assert c.wram[0x10000:] == expected and c.X == new
        cases += 1
    frame_cases = 0
    for trial in range(100):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        base = (2 + trial % 20) << 8
        descriptor = rng.randbytes(10)
        c.wram[0x1100:0x110A] = descriptor
        c.wram[base + 0xF7:base + 0x100] = rng.randbytes(9)
        expected = c.wram[:]
        prepare_frame(expected, base, descriptor)
        c.Y = 0x1100
        call(c, 0xAA42, X=base)
        assert c.wram[base + 0xF7:base + 0x100] == expected[base + 0xF7:base + 0x100]
        frame_cases += 1
    completion_cases = dispatch_cases = 0
    for trial in range(160):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        node = 0x600+(trial%20)*16
        c.S = 0x1FFF
        c.PB,c.PC,c.M,c.XF = 0x7E,0xAA22,1,0
        c.wr16(0x7F009E,node)
        c.wr16(0x7F009A,trial)
        expected = c.wram[:]
        complete_task(expected)
        expected[c.S] = 0x7F  # PHB setup's scratch byte remains after PLB.
        while c.PC != 0xA948:
            c.step()
            if c.steps>30: raise RuntimeError('task completion timeout')
        assert c.wram == expected and c.S==0x1FFF and c.DB==0x7F and c.I==1
        completion_cases += 1
        for status in (8,16):
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = rng.randbytes(0x10000)
            base = (2+trial%20)<<8
            c.wram[base+0xF7:base+0x100] = rng.randbytes(9)
            c.wr16(0x7F0000|node,0x740)
            c.wr16(0x7F0000|(node+6),base+(0xF6 if status==8 else trial%240))
            c.wr8(0x7F0000|(node+2),status)
            c.PB,c.PC,c.X,c.DB,c.M,c.XF = 0x7E,0xA961,node,0x7F,0,0
            expected = c.wram[:]
            target, stack = dispatch_frame(expected,node)
            for _ in range(40):
                c.step()
                if c.PB<<16|c.PC == target: break
            else: raise RuntimeError('task frame dispatch timeout')
            assert c.wram==expected and c.S==stack and c.I==0
            if status==16: assert c.D==base
            dispatch_cases += 1
    allocation_cases = 0
    for trial in range(240):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        # Fill preceding entries; choose each first-free index and the exhausted state.
        free_index = trial%21
        c.wram[0x100AA:0x100BE] = bytes(rng.randint(1,255) for _ in range(20))
        if free_index<20: c.wram[0x100AA+free_index] = 0
        descriptor = rng.randbytes(10)
        c.wram[0x1800:0x180A] = descriptor
        node,parent = 0x600+(trial%20)*16,rng.randint(1,255)
        expected = c.wram[:]
        result = allocate_task_frame(expected,node,parent,descriptor)
        c.DB,c.Y = 0x7F,0x1800
        call(c,0xAA77,A=parent,X=node)
        # Exclude the caller's top-of-stack scratch; all task pages and bank 7F are compared.
        expected[0x1FE0:0x2000] = c.wram[0x1FE0:0x2000]
        assert c.wram==expected and c.X==result and c.S==0x1FFF
        allocation_cases += 1
    free_page_cases = 0
    for trial in range(240):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        node = 0x600+(trial%20)*16
        saved_stack = ((2+trial%20)<<8)+rng.randrange(256)
        put_word(memoryview(c.wram)[0x10000:],node+6,saved_stack)
        expected = c.wram[:]
        slot = free_task_frame(expected,node)
        c.DB = 0x7F
        call(c,0xAAD7,X=node)
        assert c.wram[0x10000:]==expected[0x10000:] and c.X==slot and c.Y==node
        free_page_cases += 1
    return {'initialization': '7EAD75', 'spawn': '7EAB88', 'queue_insert': '7EA8D6',
            'spawned': spawned, 'queue_model_cases': cases,
            'queue_model_verified': True, 'new_task_dispatch': dispatched,
            'initial_frame_model_cases': frame_cases, 'initial_frame_model_verified': True,
            'completion_model_cases':completion_cases, 'completion_model_verified':True,
            'dispatch_frame_model_cases':dispatch_cases, 'dispatch_frame_model_verified':True,
            'task_page_allocation_model_cases':allocation_cases,'task_page_allocation_model_verified':True,
            'task_page_release_model_cases':free_page_cases,'task_page_release_model_verified':True,
            'hardware_timing_emulated': False}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    print(json.dumps(report, indent=2))
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json') + 1], 'w') as f:
            json.dump(report, f, indent=2)
            f.write('\n')

if __name__ == '__main__':
    main()
