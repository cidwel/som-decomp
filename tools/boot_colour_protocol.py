"""Recovered colour-task parent identifiers, raw receive and graphics resize phases.
usage: boot_colour_protocol.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_wait,boot_create,boot_graphics,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def parent_id(mem):
    """$ACD0: root parent 1 or current task's byte +5."""
    node = word(mem,0x9E)
    return mem[node+5] if node else 1


def receive_ready(mem,node,stack):
    """$B2FB with a preloaded ordinary record and no competing ready task."""
    put_word(mem,node+6,stack-11)
    put_word(mem,node,0)
    mem[node+2] = 1
    record = word(mem,node+10)
    put_word(mem,node+10,boot_pool.take_link(mem,record))
    return record


def resize_graphics(mem,image,count):
    """$BEDD: replace graphics workspace 43 with 768 bytes, then reserve count blocks."""
    boot_graphics.release_buffer(mem,0x43)
    boot_graphics.create_buffer(mem,image,0x43,0x300)
    for _ in range(count or 65536): boot_graphics.allocate_block(mem,0x43)


def validate(rom):
    cpu.set_rom(rom)
    initialized,_ = boot_tasks.initialized(rom)
    baseline = initialized.wram[:]
    rng = random.Random(0xB2FB)
    cases = dict(parent_id=0,task_id=0,receive_ready=0,receive_after_delivery=0,resize_graphics=0)
    for trial in range(240):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        put_word(bank,0x9E,0 if trial%3==0 else 0x700)
        bank[0x704],bank[0x705] = rng.randrange(256),rng.randrange(256)
        for name,address,model in (('parent_id',0xACD0,parent_id),('task_id',0xACE9,boot_pool.task_id)):
            c = cpu.CPU()
            c.wram[:] = memory
            c.DB = trial%256
            boot_tasks.call(c,address,A=rng.randrange(65536))
            assert c.wram[65536:]==bank and c.A&255==model(bank) and c.DB==trial%256,(name,trial)
            cases[name] += 1
    for trial in range(320):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        node,record = 0x700,0x2400
        put_word(bank,0x9E,node)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node,0)
        put_word(bank,node+10,record)
        bank[node+2],bank[node+3],bank[node+4] = 1,128,3
        put_word(bank,node+12,0xF84)
        bank[0xF84],bank[0xF85] = trial%3,3
        put_word(bank,0xF86,(trial*257)&65535)
        put_word(bank,record,0 if trial%2 else record+8)
        bank[record+2] = (0,1,3,255)[trial%4]
        expected = bytearray(bank)
        result = receive_ready(expected,node,0x1FFD)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = trial%256
        boot_tasks.call(c,0xB2FB)
        assert c.wram[65536:]==expected and c.X==result and c.DB==trial%256,('receive ready',trial)
        cases['receive_ready'] += 1
    for trial in range(96):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        node,record = 0x700,0x2400
        put_word(bank,0x9E,node)
        put_word(bank,0x9A,1)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node,0)
        put_word(bank,node+10,0)
        bank[node+2],bank[node+3],bank[node+4],bank[node+5] = 1,128,3,1
        bank[0xAB] = 1
        put_word(bank,record,0)
        bank[record+2] = (0,1,3,255)[trial%4]
        expected = memory[:]
        e = memoryview(expected)[65536:]
        put_word(e,node+6,0x03D3)
        e[node+2] = 4
        put_word(e,0xA2,node)
        idle = boot_create.select_next(expected)
        boot_tasks.dispatch_frame(expected,idle)
        boot_wait.append_record(e,record,3)
        put_word(e,idle+10,0xFFFF)
        put_word(e,idle+6,0x02EB)
        e[idle+2] = 2
        boot_tasks.enqueue(e,idle)
        chosen = word(e,0xA0)
        assert chosen==node
        put_word(e,0xA0,word(e,node))
        put_word(e,node,0)
        put_word(e,0x9E,node)
        e[node+2] = 1
        put_word(e,node+10,boot_pool.take_link(e,record))
        c = cpu.CPU()
        c.wram[:] = memory
        c.S,c.PB,c.PC,c.M,c.XF,c.DB,c.D = 0x03E0,0x7E,0xB2FB,1,0,0x7F,0x0300
        c.push16(0xFFFD)
        delivered = False
        for _ in range(20000):
            address = c.PB<<16|c.PC
            if address==0x7EFFFE: break
            if address==0x7EA8C0 and not delivered:
                # Supply one message at the fallback boundary; the original delivery code executes.
                delivered = True
                c.A,c.X = 3,record
                c.push16(0xA8BF)
                c.PC = 0xB258
            c.step()
        else: raise RuntimeError('raw receive delivery timeout')
        assert delivered and c.X==record and c.S==0x03E0,('receive delivery return',trial)
        assert c.wram[65536:]==e,('receive delivery memory',trial)
        cases['receive_after_delivery'] += 1
    prepared = baseline[:]
    boot_graphics.create_buffer(memoryview(prepared)[65536:],prepared,0x43,0x180)
    for trial in range(96):
        memory = prepared[:]
        bank = memoryview(memory)[65536:]
        if trial%3==0:
            bitmap = word(bank,0x32C)
            for index in range(32):
                if not bank[bitmap+index]: bank[bitmap+index] = 0x80
        count = (1,2,31,32,191,192,383,384,385,768,769,1024)[trial%12]
        expected = memory[:]
        resize_graphics(memoryview(expected)[65536:],expected,count)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = (0,0x7E,0x7F)[trial%3]
        boot_tasks.call(c,0xBEDD,X=count,step_limit=5_000_000)
        assert c.wram[65536:]==expected[65536:] and c.DB==(0,0x7E,0x7F)[trial%3],('resize graphics',trial)
        cases['resize_graphics'] += 1
    return dict(cases=cases,verified=True,comparison='entire bank 7F, identifier low A, receive X/restored S and DB where specified',scope='preloaded raw records and one externally supplied message at the fallback boundary, with original delivery/suspension/dispatch/resume; no timer filter; graphics replacement with available heap/PPU records and independent VRAM failure; positive block counts through exhaustion; physical interrupt/message timing and complete colour task remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
