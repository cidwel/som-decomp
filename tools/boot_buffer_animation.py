"""Recovered title-buffer colour steps and row animation.
usage: boot_buffer_animation.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_buffer_setup,boot_buffer_rows,boot_receive,boot_pool,boot_image,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def colour(mem,index,field=4):
    """$8B15/$8B5D: copy four indexed source words to live auxiliary buffers."""
    bank = memoryview(mem)[65536:]
    for slot,source in ((0x42,0x5DA0),(0x46,0x5DE0),(0x4A,0x5E20),(0x4E,0x5E60)):
        pointer = word(bank,slot)
        if pointer:
            value = word(mem,source+index)
            offset = pointer+field
            for delta,byte in ((0,value&255),(1,value>>8)):
                target = offset+delta
                # Carry into bank80 reaches its low-WRAM mirror.
                mem[65536+target if target<65536 else target-65536] = byte


def animate(mem,buffer):
    """$8BA5: increment row counter and yield each required8B00 wait count."""
    bank = memoryview(mem)[65536:]
    bank[0x63] = (bank[0x63]+1)&255
    count = bank[0x63]
    if count==0x2B:
        bank[(word(bank,0x52)+3)&65535] = 0
        bank[(word(bank,0x54)+3)&65535] = 2
        yield 1
        put_word(bank,0x5D,0xFFF8)
        yield 1
        put_word(bank,0x5D,0xFFF8)
        for remaining in range(32,0,-1):
            yield 2
            colour(mem,2*(remaining-1))
            if remaining&3==1: put_word(bank,0x5D,(word(bank,0x5D)+1)&65535)
        boot_buffer_rows.row(mem,0x19E,(buffer+0x80)&65535)
        return
    if 0x26<=count<0x2B:
        pointer = word(bank,0x46)
        if word(bank,(pointer+4)&65535)!=word(mem,0x5E1E):
            boot_buffer_rows.row(mem,0x1A0,(buffer+0x80)&65535)
            yield 1
            put_word(bank,0x5D,0xFFF8)
            for remaining in range(32,0,-1):
                yield 2
                colour(mem,2*(32-remaining))
                if remaining&3==1: put_word(bank,0x5D,(word(bank,0x5D)+1)&65535)
            return
        bank[(word(bank,0x52)+3)&65535] = 255
        bank[(word(bank,0x54)+3)&65535] = 0
    yield 1
    put_word(bank,0x5D,0xFFF8)
    for _ in range(8):
        yield 8
        put_word(bank,0x5D,(word(bank,0x5D)+1)&65535)


def receive_wait(mem,count,stack):
    bank = memoryview(mem)[65536:]
    task = word(bank,0x9E)
    boot_receive.prepare_receive(bank,task,count)
    put_word(bank,task+6,stack-30)
    put_word(bank,task,0)
    bank[task+2] = 1
    record = word(bank,task+10)
    put_word(bank,task+10,boot_pool.take_link(bank,record))
    return boot_receive.finish_receive(bank,task,record,count)


def validate(rom):
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0x8BA5)
    cases = dict(colour=0,animation=0)
    waits = 0
    for trial in range(256):
        for address,field in ((0x8B15,4),(0x8B5D,7)):
            expected = initial[:]
            bank = memoryview(expected)[65536:]
            index = (0,2,62,64,0xA300,0xFFF0)[trial%6]
            for number,slot in enumerate((0x42,0x46,0x4A,0x4E)):
                pointer = (0,0x3000+32*number,0xFFFC)[(trial+number)%3]
                put_word(bank,slot,pointer)
                put_word(expected,((0x5DA0+64*number)+index),rng.randrange(65536))
            memory = expected[:]
            colour(expected,index,field)
            c = cpu.CPU();c.wram[:] = memory;c.D,c.DB = 0x300,0x7F
            boot_tasks.call(c,address,X=index)
            boot_transform.compare_memory(c.wram,expected,('colour',trial,field))
            assert c.X==index and (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
            cases['colour'] += 1
    for trial in range(256):
        expected = initial[:]
        bank = memoryview(expected)[65536:]
        task = word(bank,0x9C)
        put_word(bank,0x9E,task)
        put_word(bank,0xA0,0);put_word(bank,0xA2,0);put_word(bank,task,0)
        bank[task+2:task+6] = bytes((1,128,7,1))
        put_word(bank,task+12,0xF84)
        bank[0x96] &= ~64
        boot_buffer_setup.setup(expected)
        bank[0x63] = trial
        pointer = word(bank,0x46)
        if trial%2: put_word(bank,pointer+4,word(expected,0x5E1E))
        buffer = 0x4000
        put_word(bank,task+10,0x7000)
        for index in range(34):
            record = 0x7000+8*index
            put_word(bank,record,record+8 if index<33 else 0)
            bank[record+2] = 255
            put_word(bank,record+4,0xF84)
        c = cpu.CPU();c.wram[:] = expected
        c.S,c.PB,c.PC,c.D,c.DB,c.M,c.XF,c.X = 0x1FFF,0x7E,0x8BA5,0x300,0x7F,1,0,buffer
        c.push16(0xFFFD)
        model = animate(expected,buffer)
        for count in model:
            c.step()
            boot_image.run_until(c,0x7E8B00)
            boot_transform.compare_memory(c.wram,expected,('animation wait',trial,count))
            assert c.X==count
            receive_wait(expected,count,0x1FFF)
            waits += 1
        boot_image.run_until(c,0x7EFFFE)
        boot_transform.compare_memory(c.wram,expected,('animation return',trial))
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
        cases['animation'] += 1
    return dict(verified=True,cases=cases,compared_waits=waits,comparison='full WRAM outside caller stack1F80-1FFF at every wait entry and final return, wait X and restored caller state; standalone colour returned X',scope='all256 incoming row-counter bytes; forward/reverse colour sequences, endpoint equality and row expansion; complete original8BA5 with all callees, preloaded matching timer messages and pause flag cleared; empty-queue concurrency/pause progression, full8D1A composition and physical timing open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2);f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
