"""Recovered title control task with supplied timer records and PPU shadow service.
usage: boot_control_task.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_pool,boot_wait,boot_receive,boot_colour_protocol,boot_parent_transition,boot_ppu_queue,boot_vram,boot_parent_control,boot_cleanup,boot_transform,boot_image,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def receive_delay(mem,delay,stack):
    """$ABE7 with a preloaded record and only this task ready."""
    current = word(mem,0x9E)
    boot_receive.prepare_receive(mem,current,delay)
    put_word(mem,current+6,stack-12)
    put_word(mem,current,0)
    mem[current+2] = 1
    record = word(mem,current+10)
    put_word(mem,current+10,boot_pool.take_link(mem,record))
    return boot_receive.finish_receive(mem,current,record,delay)


def control_task(mem,stack):
    """$D0CC: optional map transition, final dim, then cleared parent notification."""
    bank = memoryview(mem)[65536:]
    classes = mem[0x603E:0x6072]
    def entry(): return boot_ppu_queue.allocate_entry(bank,classes,0)
    def queue(node,end):
        boot_ppu_queue.append_entry(bank,node)
        return ('queue',end,node,bank[node+2])
    def wait(delay,end):
        record = receive_delay(bank,delay,stack-5)
        return ('wait',end,record,delay)
    if not bank[0x317]:
        while True:
            node = entry()
            if not bank[node+2]: break
            bank[node+2] -= 1
            if not bank[node+2]: break
            yield queue(node,0xD0E9)
            yield wait(1,0xD0EF)
        boot_parent_transition.copy_title_map(mem,0)
        yield ('map',0xD0F7,0,0)
        while True:
            node = entry()
            if bank[node+2]==15: break
            bank[node+2] = (bank[node+2]+1)&255
            value = bank[node+2]
            yield queue(node,0xD10E)
            if value==15: break
            yield wait(1,0xD119)
        yield wait(30,0xD121)
    while True:
        node = entry()
        if not bank[node+2]: break
        bank[node+2] -= 1
        if not bank[node+2]: break
        yield queue(node,0xD133)
        yield wait(4,0xD139)
    yield queue(node,0xD13E)
    parent = boot_colour_protocol.parent_id(bank)
    record = boot_pool.allocate(bank)
    boot_wait.append_record(bank,record,parent)
    yield ('notice',0xD149,record,parent)


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    rng = random.Random(0xD0CC)
    cases = dict(full_map_transition=0,final_dim_only=0,timer_records=0,ordinary_records=0)
    queued = waits = 0
    for done in (0,1,255):
        for brightness in (0,1,2,7,14,15,0x80,0x8F,255):
            for timer in (False,True):
                expected = initial.wram[:]
                bank = memoryview(expected)[65536:]
                current = word(bank,0x9C)
                parent = current+16
                put_word(bank,0xA6,word(bank,parent))
                put_word(bank,current,0)
                put_word(bank,parent,0)
                bank[current+2:current+6] = bytes((1,0,7,3))
                bank[parent+2:parent+6] = bytes((1,128,3,1))
                put_word(bank,current+10,0)
                put_word(bank,parent+10,0)
                put_word(bank,current+12,0xF84)
                bank[0xF84:0xF88] = bytes((1,7,0,0))
                put_word(bank,0x9E,current)
                put_word(bank,0xA0,0)
                put_word(bank,0xA2,0)
                bank[0x317] = done
                source = boot_vram.create_buffer(bank,expected,0x10)
                put_word(bank,0x306,source)
                bank[0x310] = rng.randrange(256)
                mirror = word(bank,0x2E2)
                put_word(bank,mirror,brightness|rng.randrange(256)<<8)
                count = max(0,brightness-1) if done else (brightness+27 if brightness else 29)
                for index in range(count):
                    record = 0x2400+8*index
                    bank[record:record+8] = rng.randbytes(8)
                    put_word(bank,record,record+8 if index+1<count else 0)
                    bank[record+2] = 255 if timer else 5
                    put_word(bank,record+4,0xF84)
                if count: put_word(bank,current+10,0x2400)
                c = cpu.CPU()
                c.wram[:] = expected
                c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x1FFF,0x7E,0xD0CC,1,0,0x300,0x7F
                c.push8(0x7E)
                c.push16(0xFFFD)
                steps = 0
                notice = None
                for kind,end,node,value in control_task(expected,0x1FFC):
                    boot_image.run_until(c,0x7E0000|end)
                    boot_transform.compare_memory(c.wram,expected,('control task',done,brightness,timer,kind,steps))
                    if kind=='queue':
                        assert c.X==node
                        boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
                        boot_image.boundary_call(c,0xC18B)
                        boot_transform.compare_memory(c.wram,expected,'control shadow service')
                        queued += 1
                    elif kind=='wait':
                        assert c.X==node
                        waits += 1
                    elif kind=='notice': notice = node
                    steps += 1
                    c.step()
                boot_image.run_until(c,0x7EFFFE)
                boot_transform.compare_memory(c.wram,expected,'complete control-task return')
                assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
                assert bank[mirror]==0 and word(bank,current+10)==0
                assert notice and word(bank,parent+10)==notice and bank[notice+2:notice+5]==bytes((7,0,0))
                cases['final_dim_only' if done else 'full_map_transition'] += 1
                cases['timer_records' if timer else 'ordinary_records'] += 1
    return dict(verified=True,cases=cases,compared_ppu_updates=queued,compared_waits=waits,comparison='full WRAM outside caller stack1F80-1FFF at every queue/wait/map/notice boundary and return; X on queue/wait and restored D/DB/S/M/X',scope='54 continuous original D0CC calls, real registered map and available resources; only control task ready, parent running, timer/ordinary records preloaded, original C18B shadow service supplied; parent consumption/task cleanup/concurrent scheduling and physical PPU/IRQ timing open')


class TimerCpu(cpu.CPU):
    def rd8(self,address):
        if address in (0x2137,0x213D): return 0
        return super().rd8(address)


def validate_scheduler(rom):
    """Original D14C -> parent D17F suspension -> D0CC -> notice -> parent return."""
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    cases = updates_total = ticks_total = reaped = 0
    for done in (0,255):
        for brightness in (0,1,7,15,0x80,255):
            c = TimerCpu()
            c.wram[:] = initial.wram
            bank = memoryview(c.wram)[65536:]
            parent = word(bank,0x9C)
            put_word(bank,0xA6,word(bank,parent))
            put_word(bank,parent,0)
            put_word(bank,parent+10,0)
            bank[parent+2:parent+6] = bytes((1,128,7,1))
            bank[0xAA+5] = 1
            put_word(bank,parent+12,0xF84)
            bank[0xF84:0xF88] = bytes((1,7,0,0))
            put_word(bank,0x9E,parent)
            put_word(bank,0x9A,1)
            put_word(bank,0xA0,0)
            put_word(bank,0xA2,0)
            bank[0x311:0x318] = bytes((0,0,0,0,0,0,done))
            put_word(bank,0x306,boot_vram.create_buffer(bank,c.wram,0x10))
            bank[0x310] = 0x20
            put_word(bank,word(bank,0x2E2),brightness)
            c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x7FF,0x7E,0xFFFE,1,0,0x300,0x7F
            expected = c.wram[:]
            assert not boot_parent_control.ensure_control(expected)
            boot_image.boundary_call(c,0xD14C)
            assert c.wram[:0x740]==expected[:0x740] and c.wram[0x800:]==expected[0x800:],'scheduler spawn memory'
            child = word(bank,0xA0)
            child_id = bank[child+4]
            assert child_id==bank[0x314]==2
            c.PC,c.X = 0xD17F,0
            c.push16(0xFFFD)
            values,delays = [],[]
            ticks,entries,maps = 0,0,0
            serviced = False
            for _ in range(5_000_000):
                address = c.PB<<16|c.PC
                if address==0x7EFFFE: break
                if address==0x7EA8C0 and not serviced:
                    serviced = True
                    ticks += 1
                    c.push16(0xA8BF)
                    c.PC = 0xCCB7
                elif address==0x7EA8C3: serviced = False
                elif address==0x7ED0CC:
                    assert word(bank,0x9E)==child
                    entries += 1
                elif address==0x7EABE7 and word(bank,0x9E)==child:
                    delays.append(c.X)
                elif address==0x7ECD82: maps += 1
                elif address in (0x7ED0E9,0x7ED10E,0x7ED133,0x7ED13E):
                    assert word(bank,0x9E)==child
                    values.append(bank[c.X+2])
                    boot_image.boundary_call(c,0xC18B)
                c.step()
            else: raise RuntimeError(('control scheduler timeout',hex(c.PB<<16|c.PC)))
            if done:
                expected_values = list(range(brightness-1,-1,-1)) if brightness else [0]
                expected_delays = [4]*max(0,brightness-1)
            else:
                expected_values = list(range(brightness-1,0,-1))+list(range(2 if brightness else 1,16))+list(range(14,-1,-1))
                expected_delays = [1]*(max(0,brightness-1)+(13 if brightness else 14))+[30]+[4]*14
            assert values==expected_values and delays==expected_delays,'scheduler brightness/wait sequence'
            assert ticks==sum(delays) and entries==1 and maps==(0 if done else 1),(done,brightness,ticks,sum(delays),entries,maps)
            assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x7FF,1,0)
            assert c.A&255==0 and c.X and bank[c.X+2]==child_id
            assert bank[0x314]==0 and word(bank,parent+10)==0 and word(bank,0x9E)==parent
            assert bank[word(bank,0x2E2)]==0
            assert word(bank,0xA4)==child and bank[child+2]==16
            notice = c.X
            registration = word(bank,child+12)
            held_notice = bytes(bank[notice:notice+8])
            expected = c.wram[:]
            boot_cleanup.reap_one(expected)
            boot_image.boundary_call(c,0xA9C7)
            assert c.wram[:0x740]==expected[:0x740] and c.wram[0x800:]==expected[0x800:],'scheduled child reaping memory'
            assert word(bank,0xA4)==0 and word(bank,0xA6)==child
            assert word(bank,child+2)==word(bank,child+4)==0 and bank[0xAA+child_id-2]==0
            assert bank[registration]==0 and child_id not in bank[0x1C4:0x2C4]
            assert bytes(bank[notice:notice+8])==held_notice and word(bank,notice)==7
            reaped += 1
            cases += 1
            updates_total += len(values)
            ticks_total += ticks
    return dict(verified=True,cases=cases,compared_ppu_updates=updates_total,original_timer_service_calls=ticks_total,compared_completed_task_reaps=reaped,comparison='full WRAM for D14C spawn outside parent stack; original scheduled composition brightness/wait order, parent return X/lowA, restored caller state and completed child record; full WRAM for A9C7 reaping outside parent stack, retained notice and freed child resources',scope='12 empty-parent-queue cases; actual original suspension, new child dispatch, fallback creation, timer delivery, child completion and parent resume/consumption; original CCB7 service invoked at fallback boundaries with controlled PPU reads, C18B shadow service at queues; no preloaded records or game hooks, original A9C7 reaping supplied after parent return and independently memory-compared; physical IRQ/PPU timing and complete title concurrency open')


def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    report['scheduler_composition'] = validate_scheduler(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
