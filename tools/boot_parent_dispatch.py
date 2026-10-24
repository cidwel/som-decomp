"""Recovered controller ownership/masks and title-parent message dispatch.
usage: boot_parent_dispatch.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_parent_receive,boot_parent_messages,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def route_input(mem,selector,operation,value=0):
    """$A351/$A3A5/$A3FC/$A45F: one controller or owned/all five controllers."""
    selector &= 255
    owner = boot_pool.task_id(mem)
    base = word(mem,0x92)
    for index in range(5):
        node = base+16*index
        if selector<5 and index!=selector: continue
        if operation=='claim': mem[node+1] = owner
        elif operation=='release':
            if selector<5 or mem[node+1]==owner: mem[node+1] = 0
        elif selector<5 or mem[node+1]==owner:
            put_word(mem,node+(8 if operation=='pressed' else 10),value)


def input_task_completed(mem,record):
    """$D0AE: release notice, claim all input, install pressed masks and mark0316."""
    boot_pool.release(mem,record)
    route_input(mem,5,'claim')
    route_input(mem,5,'pressed',0xF0F0)
    mem[0x316] = 1


def dispatch(mem,delay,stack):
    """$D17F with preloaded input and no new control-task creation."""
    while True:
        record,value = boot_parent_receive.receive(mem,delay,stack-5)
        if not record:
            if value: return 0,value
            # D14C does nothing when a control task already exists.
            if not mem[0x314]: raise ValueError('new control-task creation is outside this model')
        else:
            sender = mem[record+2]
            if sender==mem[0x312]: boot_parent_messages.buffer_message(mem,record)
            elif sender==mem[0x314]:
                mem[0x314] = 0
                return record,0
            elif sender==mem[0x315]: input_task_completed(mem,record)
            elif sender==mem[0x311]:
                result = boot_parent_messages.image_message(mem,record)
                if result: return 0,result
            else: boot_parent_messages.tracked_message(mem,record)
        delay = 0


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xD17F)
    cases = dict(claim=0,release=0,pressed=0,released=0,dispatch=0)
    for trial in range(240):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        node = word(bank,0x9C)
        put_word(bank,0x9E,0 if trial%4==0 else node)
        bank[node+4] = (0,3,7,255)[trial%4]
        base = word(bank,0x92)
        bank[base:base+80] = rng.randbytes(80)
        for index in range(5): bank[base+16*index+1] = rng.choice((boot_pool.task_id(bank),0,3,99))
        selector = (0,1,2,3,4,5,255,rng.randrange(65536))[trial%8]
        value = rng.randrange(65536)
        for name,address in (('claim',0xA351),('release',0xA3A5),('pressed',0xA3FC),('released',0xA45F)):
            expected = memory[:]
            route_input(memoryview(expected)[65536:],selector,name,value)
            c = cpu.CPU()
            c.wram[:] = memory
            c.D,c.DB = 0x300,rng.randrange(256)
            db = c.DB
            boot_tasks.call(c,address,A=selector,X=value)
            boot_transform.compare_memory(c.wram,expected,(name,trial))
            assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,db,0x1FFF,1,0),(name,'restore',trial)
            cases[name] += 1
    for trial in range(480):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        node,child = word(bank,0x9C),word(bank,0x9C)+16
        for task,identity in ((node,7),(child,3)):
            put_word(bank,task,0)
            bank[task+2:task+6] = bytes((1,128,identity,1))
            put_word(bank,task+10,0)
        put_word(bank,0x9E,node)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node+12,0xF84)
        bank[0x96] &= ~64
        bank[0x311:0x316] = bytes((3,1,0,2,4))
        put_word(bank,0x306,rng.randrange(65536))
        bank[0x318:0x32C] = rng.randbytes(20)
        prefix = trial%6
        put_word(bank,node+10,0x2400)
        for index in range(prefix+1):
            record = 0x2400+8*index
            bank[record:record+8] = rng.randbytes(8)
            put_word(bank,record,record+8 if index<prefix else 0)
            bank[record+2] = (3,1,4,99,254)[index%5]
            bank[record+3] = 3 if index%5==0 else rng.choice((0,1,2,255))
            bank[record+4] = 4 if index%5==0 else 1
        finish = trial%4
        if finish==0:
            bank[record+2],bank[record+3] = 3,(1,2,4)[trial%3]
        elif finish==1: bank[record+2] = 2
        else:
            bank[record+2] = 255
            put_word(bank,record+4,0xF84)
        delay = (0,1,4,256,65535)[trial%5]
        expected = memory[:]
        result,value = dispatch(memoryview(expected)[65536:],delay,0x1FFD)
        c = cpu.CPU()
        c.wram[:] = memory
        c.D,c.DB = 0x300,0x7F
        boot_tasks.call(c,0xD17F,X=delay)
        boot_transform.compare_memory(c.wram,expected,('dispatch',trial))
        assert c.X==result and c.A&255==value,('dispatch result',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),('dispatch restore',trial)
        cases['dispatch'] += 1
    return dict(verified=True,cases=cases,comparison='all WRAM outside caller stack1F80-1FFF and restored D/DB/S/M/X; dispatch X/lowA',scope='controller fields with five valid records, low-byte selectors/root or live owner; original D17F preloaded message chains with no pause/competing tasks; all receive/handler/pool/input helpers execute; cancellation uses existing control task, new control-task creation and full parent caller/physical timing open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
