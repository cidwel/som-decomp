"""Recovered image-row request, raw acknowledgement and palette/workspace replacement.
usage: boot_image_protocol.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_wait,boot_colour,boot_graphics,boot_colour_protocol,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def request_row(mem,rom,argument,recipient):
    """$9FA4 up to raw receive: opcode low byte 3, argument word at +4."""
    bank = memoryview(mem)[65536:]
    record = boot_pool.allocate(bank)
    put_word(bank,record+3,3)
    put_word(bank,record+4,argument)
    boot_wait.append_record(bank,record,recipient)
    return record


def finish_row(mem,rom,argument,response):
    """$9FD7: any nonzero response word enables palette upload and workspace replacement."""
    bank = memoryview(mem)[65536:]
    count = None
    if word(bank,response+3):
        boot_colour.queue_sample_palette(bank,mem)
        count = ((argument<<1)&255)*32
        boot_colour_protocol.resize_graphics(bank,mem,count)
    boot_pool.release(bank,response)
    return count


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    boot_graphics.create_buffer(memoryview(baseline)[65536:],baseline,0x43,0x180)
    rng = random.Random(0x9FA4)
    cases = dict(no_replacement=0,palette_and_replacement=0)
    maximum = 0
    for trial in range(320):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        current = word(bank,0x9C)
        parent = current+16
        response = 0x2400
        put_word(bank,0x9E,current)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        for node,identity in ((current,3),(parent,7)):
            put_word(bank,node,0)
            bank[node+2:node+6] = bytes((1,128,identity,1))
            put_word(bank,node+10,0)
        put_word(bank,current+10,response)
        put_word(bank,response,0)
        bank[response+2] = (0,3,255)[trial%3]
        replace = trial%2==1
        put_word(bank,response+3,rng.randrange(1,65536) if replace else 0)
        put_word(bank,0x1A,0x5000)
        for index in range(232):
            bank[0x5000+4*index:0x5003+4*index] = bytes(rng.randrange(32) for _ in range(3))
        argument = (1,2,3,6,11,12)[trial%6]|rng.randrange(256)<<8 if replace else rng.randrange(65536)
        recipient = 7|rng.randrange(256)<<8
        expected = memory[:]
        e = memoryview(expected)[65536:]
        sent = request_row(expected,rom,argument,recipient)
        received = boot_colour_protocol.receive_ready(e,current,0x1FF3)
        assert received==response
        count = finish_row(expected,rom,argument,received)
        c = cpu.CPU()
        c.wram[:] = memory
        db = (0,0x7E,0x7F)[trial%3]
        boot_transform.call(c,0x9FA4,destination=0x300,A=argument,X=recipient,data_bank=db,step_limit=5_000_000)
        boot_transform.compare_memory(c.wram,expected,('image row memory',trial))
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,db,0x1FFF,0,0),('image row restore',trial)
        assert e[sent+3]==3 and word(e,sent+4)==argument
        if replace:
            maximum = max(maximum,count)
        cases['palette_and_replacement' if replace else 'no_replacement'] += 1
    return dict(cases=cases,verified=True,maximum_replacement_blocks=maximum,comparison='all WRAM outside caller stack 1F80-1FFF, restored D/DB/S/M/X',scope='native word arguments, preloaded raw responses, available pool/heap/PPU/descriptors, positive replacement counts; original send/receive/scheduler/palette/workspace callees execute; real parent acknowledgement timing and physical DMA remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
