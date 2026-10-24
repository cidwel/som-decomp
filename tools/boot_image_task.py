"""Recovered complete colour-image task, including preparation, messages and teardown.
usage: boot_image_task.py ROM [--parent-rows] [--json OUT.json]
"""
import sys,json,romio,boot_tasks,boot_pool,boot_wait,boot_colour,boot_colour_scene,boot_colour_protocol,boot_image_protocol,boot_transform,boot_image,boot_dma,boot_parent_messages,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def prepare_image_task(mem,rom):
    """$968D-$96D8: parent id, resource setup, real tree/stream/sample/lookup/palette."""
    bank = memoryview(mem)[65536:]
    parent = boot_colour_protocol.parent_id(bank)
    boot_colour_scene.prepare_colour_resources(mem,rom)
    header = boot_colour.build_tree(mem,rom,0xD2E536)
    source = (0xE536+3*((header>>8)+1))&65535
    boot_colour.initialize_decoder(bank,0x80,0xD2,source)
    boot_colour.components(mem,rom,0x80)
    boot_colour.initialize_lookup(bank,mem)
    boot_colour.queue_sample_palette(bank,mem)
    return parent|(header&255)<<8


def send_phase(mem,argument,opcode):
    """$96D9/$96F5: opcode word at +3 sent to low parent id, retaining other payload."""
    bank = memoryview(mem)[65536:]
    record = boot_pool.allocate(bank)
    put_word(bank,record+3,opcode)
    boot_wait.append_record(bank,record,argument)
    return record


def colour_image_task(mem,rom,phase,exchange,complete):
    """$968D: preparation, phase2/raw receive, image body, phase4/raw receive, teardown."""
    argument = prepare_image_task(mem,rom)
    phase(mem,argument,2)
    yield from boot_image.image_groups(mem,rom,argument,0x80,exchange,complete)
    phase(mem,argument,4)
    boot_colour_scene.release_colour_resources(mem)


def validate(rom,parent_rows=False):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    expected = initial.wram[:]
    bank = memoryview(expected)[65536:]
    current,parent = word(bank,0x9C),word(bank,0x9C)+16
    for node,identity in ((current,3),(parent,7)):
        put_word(bank,node,0)
        bank[node+2:node+6] = bytes((1,128,identity,7))
        put_word(bank,node+10,0)
    put_word(bank,0x9E,current)
    put_word(bank,0xA0,0)
    put_word(bank,0xA2,0)
    if parent_rows: bank[0x311] = 3
    c = boot_transform.Mode7Cpu()
    c.wram[:] = expected
    c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0x968D,1,0,0x300,0
    c.push8(0x7E)
    c.push16(0xFFFD)
    completed = 0
    requests,phases = [],[]
    def cleanup(mem):
        nonlocal completed
        b = memoryview(mem)[65536:]
        count = word(b,0x6C)
        assert count in (1,2,4),('task completion count',count)
        put_word(b,0x6E,count)
        boot_dma.cleanup(b)
        put_word(memoryview(c.wram)[65536:],0x6E,count)
        boot_image.boundary_call(c,0x92E9)
        boot_transform.compare_memory(c.wram,mem,('task completion',completed))
        completed += count
    def supply_response(mem,value):
        b = memoryview(mem)[65536:]
        response = boot_pool.allocate(b)
        put_word(b,response+3,value)
        b[response+2] = 255
        boot_wait.append_record(b,response,3)
        actual = boot_image.boundary_call(c,0xB1A9)
        assert actual==response
        a = memoryview(c.wram)[65536:]
        put_word(a,actual+3,value)
        a[actual+2] = 255
        boot_image.boundary_call(c,0xB258,A=3,X=actual)
        return response
    def process_parent(mem,record):
        b,a = memoryview(mem)[65536:],memoryview(c.wram)[65536:]
        assert word(b,parent+10)==record and word(a,parent+10)==record,'parent pending head'
        saved_db = c.DB
        put_word(b,0x9E,parent)
        put_word(a,0x9E,parent)
        c.DB = 0x7F
        successor = boot_pool.take_link(b,record)
        boot_image.boundary_call(c,0xB20B,X=record)
        put_word(b,parent+10,successor)
        put_word(a,parent+10,successor)
        result = boot_parent_messages.image_message(b,record)
        boot_image.boundary_call(c,0xCFE2,X=record)
        put_word(b,0x9E,current)
        put_word(a,0x9E,current)
        c.DB = saved_db
        boot_transform.compare_memory(c.wram,mem,'parent image handler composition')
        return result
    def phase(mem,argument,opcode):
        start,end = (0x96D9,0x96ED) if opcode==2 else (0x96F5,0x9709)
        boot_image.run_until(c,0x7E0000|start)
        boot_transform.compare_memory(c.wram,mem,('task phase entry',opcode))
        response = supply_response(mem,0x8000|opcode)
        phases.append(send_phase(mem,argument,opcode))
        b = memoryview(mem)[65536:]
        assert boot_colour_protocol.receive_ready(b,current,0x1FF1)==response
        boot_pool.release(b,response)
        c.step()
        boot_image.run_until(c,0x7E0000|end)
        boot_transform.compare_memory(c.wram,mem,('task phase receive/release',opcode))
        if parent_rows: assert process_parent(mem,phases[-1])==opcode
        if opcode==2: cleanup(mem)
    def exchange(mem,rom,row,recipient):
        boot_image.run_until(c,0x7EA03B)
        b = memoryview(mem)[65536:]
        if parent_rows:
            requests.append(boot_image_protocol.request_row(mem,rom,row,recipient))
            c.step()
            boot_image.run_until(c,0x7E9FD4)
            assert process_parent(mem,requests[-1])==0
            response = word(b,current+10)
        else:
            response = supply_response(mem,1 if row else 0)
            requests.append(boot_image_protocol.request_row(mem,rom,row,recipient))
        assert boot_colour_protocol.receive_ready(b,current,0x1FDB)==response
        count = boot_image_protocol.finish_row(mem,rom,row,response)
        renewal = row==4 if parent_rows else bool(row)
        assert count==(row*64 if renewal else None)
        c.step()
        boot_image.run_until(c,0x7EA03E)
        boot_transform.compare_memory(c.wram,mem,('task row',row))
        if renewal: cleanup(mem)
    groups,maximum = 0,0
    for row,column,writes,distance in colour_image_task(expected,rom,phase,exchange,cleanup):
        boot_image.run_until(c,0x7EA043)
        c.multiply_writes.clear()
        c.step()
        boot_image.run_until(c,0x7EA049)
        boot_transform.compare_memory(c.wram,expected,('task group',row,column))
        assert c.multiply_writes==writes,('task hardware writes',row,column)
        groups += 1
        maximum = max(maximum,distance)
    boot_image.run_until(c,0x7EFFFE)
    boot_transform.compare_memory(c.wram,expected,'complete image task teardown/RTL')
    assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0,0x1FFF,1,0)
    assert len(requests)==12 and len(phases)==2 and groups==192 and completed==(771 if parent_rows else 781)
    pending = []
    record = word(bank,parent+10)
    while record:
        pending.append(record)
        record = word(bank,record)
    assert pending==([] if parent_rows else [phases[0],*requests,phases[1]]),'parent message order'
    owned_pages = sum(owner==3 for owner in bank[0x1C4:0x2C4])
    assert owned_pages==0 and word(bank,0x6C)==0 and word(bank,0x6E)==0,'task resource teardown'
    return dict(verified=True,parent_row_handler_executed=parent_rows,final_resources=dict(task_owned_heap_pages=owned_pages,pending_descriptors=word(bank,0x6C),parent_queued_messages=len(pending)),cases=dict(complete_task=1,phase_exchanges=2,row_exchanges=12,image_groups=groups),real_image=dict(tiles=768,pixels=49152,completed_descriptors=completed,maximum_missing_cell_nearest_distance=maximum,stream_refill_cursor=f'D2{word(bank,0x80):04X}'),comparison='full WRAM outside caller stack 1F80-1FFF at every phase/row/group/cleanup and final teardown/RTL; ordered multiplier writes and restored D/DB/S/M/X',scope=('continuous original 968D task; original parent CFE2 and record-link helper executed at explicit context boundaries for all fourteen outgoing messages; row replies generated by originals with renewal only at row4; phase replies and descriptor completions supplied; whole parent loop/scheduler/IRQ/DMA timing open' if parent_rows else 'continuous original 968D task and all callees, initialized resources with live current/parent task ids; preloaded FF-tagged responses allocated/delivered through originals at explicit boundaries; descriptor completion counts supplied; original parent-task response logic and physical IRQ/DMA payload/timing remain open'))


def main():
    report = validate(romio.rom_from_argv(),'--parent-rows' in sys.argv)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
