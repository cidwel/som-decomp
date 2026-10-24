"""Recovered complete twelve-row image body with explicit parent/transfer boundaries.
usage: boot_image.py ROM [--json OUT.json]
"""
import sys,json,romio,boot_tasks,boot_pool,boot_wait,boot_colour,boot_colour_scene,boot_colour_protocol,boot_image_protocol,boot_transform,boot_pixels,boot_dma,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def initialize_image(mem,argument,decoder):
    """$A024-$A031: decoder pointer and three initial DC predictors."""
    put_word(mem,0x116,decoder)
    put_word(mem,0x110,argument>>8)
    put_word(mem,0x112,0)
    put_word(mem,0x114,0)


def image_groups(mem,rom,argument,decoder,exchange,complete):
    """$A009: twelve row exchanges, each followed by sixteen four-tile groups."""
    initialize_image(mem,argument,decoder)
    for row in range(12):
        exchange(mem,rom,row,argument)
        for column in range(16):
            _,writes = boot_transform.decode_image_group(mem,rom)
            maximum = boot_pixels.combine_group(mem,rom,check_nearest=True)
            yield row,column,writes,maximum
            complete(mem)


def run_until(c,address,limit=5_000_000):
    start = c.steps
    while c.PB<<16|c.PC!=address:
        c.step()
        if c.steps-start>limit: raise RuntimeError(('image body timeout',hex(c.PB<<16|c.PC),hex(address)))


def boundary_call(c,address,A=None,X=None):
    """Invoke an original helper at a supplied boundary, preserving the interrupted registers."""
    names = 'A X Y S D DB PB PC N V Z C M XF I Dm E'.split()
    saved = {name:getattr(c,name) for name in names}
    c.push16((c.PC-1)&65535)
    c.PB,c.PC = 0x7E,address
    if A is not None: c.A = A
    if X is not None: c.X = X
    run_until(c,saved['PB']<<16|saved['PC'])
    result = c.X
    for name,value in saved.items(): setattr(c,name,value)
    return result


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    expected = initial.wram[:]
    bank = memoryview(expected)[65536:]
    boot_colour_scene.prepare_colour_resources(expected,rom)
    header = boot_colour.build_tree(expected,rom,0xD2E536)
    boot_colour.initialize_decoder(bank,0x80,0xD2,0xE6BC)
    boot_colour.components(expected,rom,0x80)
    boot_colour.initialize_lookup(bank,expected)
    boot_colour.queue_sample_palette(bank,expected)
    c = boot_transform.Mode7Cpu()
    c.wram[:] = initial.wram
    boot_tasks.call(c,0x964B)
    boot_tasks.call(c,0xA090,A=0xD2,X=0xE536)
    c.Y = 0xE6BC
    boot_tasks.call(c,0xA12E,A=0xD2,X=0x80)
    boot_tasks.call(c,0x83AD,X=0x80)
    boot_tasks.call(c,0x8621,step_limit=5_000_000)
    boot_tasks.call(c,0x8686)
    boot_transform.compare_memory(c.wram,expected,'complete image prelude')
    current,parent = word(bank,0x9C),word(bank,0x9C)+16
    for node,identity in ((current,3),(parent,7)):
        put_word(bank,node,0)
        bank[node+2:node+6] = bytes((1,128,identity,1))
        put_word(bank,node+10,0)
    put_word(bank,0x9E,current)
    put_word(bank,0xA0,0)
    put_word(bank,0xA2,0)
    c.wram[:] = expected
    completed = 0
    def cleanup(mem):
        nonlocal completed
        b = memoryview(mem)[65536:]
        count = word(b,0x6C)
        assert count in (1,2,4),('completion count',count)
        put_word(b,0x6E,count)
        boot_dma.cleanup(b)
        put_word(memoryview(c.wram)[65536:],0x6E,count)
        boundary_call(c,0x92E9)
        boot_transform.compare_memory(c.wram,mem,('image completion',completed))
        completed += count
    cleanup(expected)
    argument = (header&255)<<8|7
    c.S,c.PB,c.PC,c.M,c.XF,c.D,c.A,c.X,c.DB = 0x1FFF,0x7E,0xA009,0,0,0x300,argument,0x80,0x7F
    c.push16(0xFFFD)
    requests = []
    def exchange(mem,rom,row,recipient):
        run_until(c,0x7EA03B)
        b = memoryview(mem)[65536:]
        response = boot_pool.allocate(b)
        put_word(b,response+3,1 if row else 0)
        boot_wait.append_record(b,response,3)
        actual = boundary_call(c,0xB1A9)
        assert actual==response,('reply allocation',row)
        put_word(memoryview(c.wram)[65536:],actual+3,1 if row else 0)
        boundary_call(c,0xB258,A=3,X=actual)
        requests.append(boot_image_protocol.request_row(mem,rom,row,recipient))
        returned = boot_colour_protocol.receive_ready(b,current,0x1FE7)
        assert returned==response
        count = boot_image_protocol.finish_row(mem,rom,row,returned)
        assert count==(row*64 if row else None)
        c.step()
        run_until(c,0x7EA03E)
        boot_transform.compare_memory(c.wram,mem,('image row exchange',row))
        if row: cleanup(mem)
    groups,maximum = 0,0
    for row,column,writes,distance in image_groups(expected,rom,argument,0x80,exchange,cleanup):
        run_until(c,0x7EA043)
        c.multiply_writes.clear()
        c.step()
        run_until(c,0x7EA049)
        boot_transform.compare_memory(c.wram,expected,('whole image group',row,column))
        assert c.multiply_writes==writes,('whole image multiplier writes',row,column)
        groups += 1
        maximum = max(maximum,distance)
    run_until(c,0x7EFFFE)
    boot_transform.compare_memory(c.wram,expected,'whole image return')
    assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,0,0)
    assert len(requests)==12 and groups==192 and completed==781
    return dict(verified=True,cases=dict(complete_image=1,row_exchanges=12,image_groups=groups),real_image=dict(tiles=groups*4,pixels=groups*256,completed_descriptors=completed,maximum_missing_cell_nearest_distance=maximum,stream_refill_cursor=f'D2{word(bank,0x80):04X}'),comparison='all WRAM outside caller stack 1F80-1FFF after prelude, each row/group/completion and return; ordered multiplier writes and restored D/DB/S/M/X',scope='continuous original A009 body and all original callees; explicit preloaded response at each row and supplied descriptor completion after submissions; original parent generation, IRQ scheduling and physical DMA payload/timing remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
