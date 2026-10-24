"""Recovered complete title window-opening sequence with original message waits.
usage: boot_title_reveal.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_create,boot_ppu_queue,boot_copy_queue,boot_dma,boot_title_window,boot_parent_dispatch,boot_image,boot_transform

word,put_word = boot_tasks.word,boot_tasks.put_word


def reveal(mem,stack,service):
    """$D2FC: register0E, descriptor5EA0, widths2..64 and three-count dispatches."""
    bank = memoryview(mem)[65536:]
    node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],0x0E)
    bank[node+2] = 0x2F
    boot_ppu_queue.append_entry(bank,node)
    task = boot_create.spawn(mem,mem[0x5EA0:0x5EAA])
    bank[0x312] = bank[task+4] if task else 0
    yield ('launch',0xD31E,0,[])
    for width in range(2,65,2):
        _,_,writes = boot_title_window.window(mem,width,0x70)
        yield ('window',0xD336,width,writes)
        service(mem)
        record,result = boot_parent_dispatch.dispatch(bank,3,stack-8)
        yield ('wait',0xD33C,record,[])
        if not result: return 0
    return result


def validate(rom):
    initial,_ = boot_tasks.initialized(rom)
    rng = random.Random(0xD2FC)
    cases = dict(complete=0,control_abort=0)
    windows = waits = 0
    for existing in (False,True):
        for stop in (None,*range(1,33)):
            expected = initial.wram[:]
            bank = memoryview(expected)[65536:]
            current = word(bank,0x9C)
            put_word(bank,0xA6,word(bank,current))
            put_word(bank,current,0)
            bank[current+2:current+6] = bytes((1,0,7,1))
            bank[0xAA+5] = 1
            put_word(bank,current+12,0xF84)
            bank[0xF84:0xF88] = bytes((1,7,0,0))
            put_word(bank,0x9E,current)
            put_word(bank,0xA0,0)
            put_word(bank,0xA2,0)
            bank[0x96] &= ~64
            bank[0x311:0x318] = bytes((0,0,0,0,4,0,0))
            put_word(bank,0x30C,0x3000)
            bank[0x3000:0x3020] = rng.randbytes(32)
            mirror = word(bank,0x2E2)
            put_word(bank,mirror+0x2C,rng.randrange(65536))
            put_word(bank,mirror+expected[0x603E+0x0E],rng.randrange(65536))
            if existing:
                descriptor = boot_dma.allocate_descriptor(bank,expected,5)
                put_word(bank,0x30E,descriptor)
                boot_dma.submit(bank,descriptor)
            else: put_word(bank,0x30E,0)
            count = stop or 32
            for index in range(count):
                record = 0x2400+8*index
                bank[record:record+8] = rng.randbytes(8)
                put_word(bank,record,record+8 if index+1<count else 0)
                bank[record+2] = 255
                put_word(bank,record+4,0xF84)
            put_word(bank,current+10,0x2400)
            c = boot_title_window.RegisterCpu()
            c.wram[:] = expected
            c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB,c.X = 0x1FFF,0x7E,0xD2FC,1,0,0x300,0x7F,rng.randrange(65536)
            c.push16(0xFFFD)
            pending_writes = []
            seen = []
            def service(mem):
                boot_copy_queue.run_queues(mem,rom)
                boot_image.boundary_call(c,0xC9E5)
                boot_transform.compare_memory(c.wram,mem,'reveal scanline table service')
                boot_ppu_queue.apply_shadow(memoryview(mem)[65536:],mem[0x603E:0x6072])
                boot_image.boundary_call(c,0xC18B)
                boot_transform.compare_memory(c.wram,mem,'reveal shadow service')
            model = reveal(expected,0x1FFD,service)
            while True:
                try: kind,end,value,writes = next(model)
                except StopIteration as done:
                    result = done.value
                    break
                boot_image.run_until(c,0x7E0000|end)
                boot_transform.compare_memory(c.wram,expected,('title reveal',existing,stop,kind,value))
                pending_writes.extend(writes)
                assert c.writes==pending_writes
                if kind=='window':
                    seen.append(value)
                    windows += 1
                    if len(seen)==stop:
                        # Supply a control completion at this selected wait boundary.
                        for mem in (expected,c.wram):
                            target = memoryview(mem)[65536:]
                            target[0x314] = 6
                            target[word(target,current+10)+2] = 6
                elif kind=='wait':
                    assert c.X==value
                    waits += 1
                c.step()
            boot_image.run_until(c,0x7EFFFE)
            boot_transform.compare_memory(c.wram,expected,('complete reveal',existing,stop))
            assert c.A&255==result==(0 if stop else 1)
            assert c.X==(0x2400+8*(count-1) if stop else 66)
            assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0)
            assert seen==list(range(2,2*count+1,2)) and bank[0x312]==2
            assert word(bank,current+10)==0 and bank[0x314]==0
            assert word(bank,0x2FE)==0 and bank[0x2DE+1]==0
            cases['control_abort' if stop else 'complete'] += 1
    return dict(verified=True,cases=cases,compared_windows=windows,compared_dispatches=waits,comparison='full WRAM outside caller stack1F80-1FFF at launch/window/wait/service/return boundaries; ordered HDMA writes, dispatch X, final lowA and restored caller state',scope='66 continuous original D2FC calls, two complete32-step animations and64 control exits; valid table/new or existing HDMA and available resources, parent priority higher than launched child, preloaded timers and supplied control completion; original C9E5/C18B service at step boundaries; physical timing, child execution, exhaustion/pause/cancellation and complete title concurrency open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
