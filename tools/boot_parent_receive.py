"""Recovered parent receive/filter entry outside its pause branch.
usage: boot_parent_receive.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_receive,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def receive(mem,delay,stack):
    """$AEC4: timer-aware receive, discard FE notices or return FE byte4=1 cancellation."""
    node = word(mem,0x9E)
    while True:
        timer = delay if delay else None
        boot_receive.prepare_receive(mem,node,timer)
        put_word(mem,node+6,stack-18)
        put_word(mem,node,0)
        mem[node+2] = 1
        record = word(mem,node+10)
        put_word(mem,node+10,boot_pool.take_link(mem,record))
        record = boot_receive.finish_receive(mem,node,record,timer)
        if not record: return 0,1
        value = (mem[record+2]-254)&255
        if value: return record,value
        cancel = mem[record+4]==1
        boot_pool.release(mem,record)
        if cancel: return 0,0
        delay = 0


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xAEC4)
    cases = dict(ordinary=0,cancel=0,timer_notice=0)
    for trial in range(480):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        node,registration = word(bank,0x9C),0xF84
        put_word(bank,0x9E,node)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node,0)
        bank[node+2:node+6] = bytes((1,128,7,1))
        put_word(bank,node+12,registration)
        bank[0x96] = rng.randrange(256)&~64
        bank[registration:registration+4] = rng.randbytes(4)
        prefix = trial%4
        put_word(bank,node+10,0x2400)
        for index in range(prefix+1):
            record = 0x2400+8*index
            bank[record:record+8] = rng.randbytes(8)
            put_word(bank,record,record+8 if index<prefix else 0)
            bank[record+2] = 254
            bank[record+4] = rng.choice((0,2,3,255))
        name = ('ordinary','cancel','timer_notice')[trial%3]
        if name=='ordinary': bank[record+2] = rng.randrange(254)
        elif name=='cancel': bank[record+4] = 1
        else:
            bank[record+2] = 255
            put_word(bank,record+4,registration)
        delay = (0,1,4,256,0x7FFF,0xFFFF)[trial%6]
        expected = memory[:]
        result,value = receive(memoryview(expected)[65536:],delay,0x1FFD)
        c = cpu.CPU()
        c.wram[:] = memory
        c.D,c.DB = 0x300,rng.randrange(256)
        db = c.DB
        boot_tasks.call(c,0xAEC4,X=delay)
        boot_transform.compare_memory(c.wram,expected,('parent receive',trial))
        assert c.X==result and c.A&255==value,('parent receive result',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,db,0x1FFF,1,0),('parent receive restore',trial)
        cases[name] += 1
    return dict(verified=True,cases=cases,comparison='all WRAM outside caller stack1F80-1FFF, X/lowA and restored D/DB/S/M/X',scope='pause bit40 of bank7F0096 clear; preloaded chains with zero to three discarded FE records, byte4 cancellation or timer notifications; original AE37 no-pause/ABAD/ABE7/timer/scheduler/pool helpers execute; pause branch, empty queue/IRQ timing and whole parent loop open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
