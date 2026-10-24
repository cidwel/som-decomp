"""Recovered title-parent message handlers for image, tracked tasks and auxiliary buffer.
usage: boot_parent_messages.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_wait,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def image_message(mem,record):
    """$CFE2: return phase1/2/4; otherwise reply, setting +3 only for row byte4."""
    opcode,row = mem[record+3],mem[record+4]
    boot_pool.release(mem,record)
    if opcode in (1,2,4): return opcode
    reply = boot_pool.allocate(mem)
    if row==4: mem[reply+3] = 1
    boot_wait.append_record(mem,reply,mem[0x311])
    return 0


def tracked_message(mem,record):
    """$D023: release the message and clear only the first of twenty matching ids."""
    identity = mem[record+2]
    boot_pool.release(mem,record)
    for node in range(0x318,0x32C):
        if mem[node]==identity:
            mem[node] = 0
            break


def buffer_message(mem,record):
    """$D081: opcode1 returns shared buffer0306; other opcodes clear task id0312."""
    opcode = mem[record+3]
    boot_pool.release(mem,record)
    if opcode!=1:
        mem[0x312] = 0
        return
    reply = boot_pool.allocate(mem)
    put_word(mem,reply+4,word(mem,0x306))
    boot_wait.append_record(mem,reply,mem[0x312])


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xCFE2)
    cases = dict(image_message=0,tracked_message=0,buffer_message=0)
    for trial in range(384):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        current,child = word(bank,0x9C),word(bank,0x9C)+16
        for node,identity in ((current,7),(child,3)):
            put_word(bank,node,0)
            bank[node+2:node+6] = bytes((1,128,identity,7))
            put_word(bank,node+10,0)
        put_word(bank,0x9E,current)
        bank[0x311],bank[0x312] = ((3,3),(0,0),(99,99))[trial%3]
        if trial%4==0:
            put_word(bank,child+10,0x2500)
            put_word(bank,0x2500,0)
        record = 0x2400
        bank[record:record+8] = rng.randbytes(8)
        bank[record+2] = trial%256
        bank[record+3] = trial if trial<256 else (1,2,3,4,0,255,3,rng.randrange(256))[trial%8]
        bank[record+4] = (0,1,3,4,5,11,4,4)[trial%8]
        put_word(bank,0x306,rng.randrange(65536))
        bank[0x318:0x32C] = bytes(rng.choice((bank[record+2],rng.randrange(256))) for _ in range(20))
        for name,address,model in (('image_message',0xCFE2,image_message),('tracked_message',0xD023,tracked_message),('buffer_message',0xD081,buffer_message)):
            expected = memory[:]
            result = model(memoryview(expected)[65536:],record)
            c = cpu.CPU()
            c.wram[:] = memory
            c.D,c.DB = 0x300,0x7F
            boot_tasks.call(c,address,A=rng.randrange(65536),X=record)
            boot_transform.compare_memory(c.wram,expected,(name,trial))
            assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),(name,'restoration',trial)
            if name=='image_message': assert c.A&255==result,(name,'result',trial)
            cases[name] += 1
    return dict(verified=True,cases=cases,comparison='all WRAM outside caller stack1F80-1FFF, restored D/DB/S/M/X, image handler low-A result',scope='caller DB7F required by original absolute accesses; original pool/delivery helpers, available records, live/missing recipients and existing pending chains; scheduler wakeups and complete parent caller/IRQ timing remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
