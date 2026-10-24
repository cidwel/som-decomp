"""Recovered title HDMA teardown and task-id stop requests.
usage: boot_title_teardown.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_wait,boot_ppu_queue,boot_dma,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def stop_task(mem,task_id):
    """$ACAC: first id match, wake status04 if possible, then set status10."""
    node = boot_wait.find_task(mem,task_id)
    if node:
        boot_wait.wake(mem,node)
        mem[node+2] = 16
    return node


def teardown(mem):
    """$D3AA: release030E HDMA, clear register2C bit0, stop/clear20 tracked ids."""
    bank = memoryview(mem)[65536:]
    boot_dma.release_descriptor(bank,word(bank,0x30E))
    put_word(bank,0x30E,0)
    node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],0x2C)
    bank[node+2] &= 254
    boot_ppu_queue.append_entry(bank,node)
    for slot in range(0x318,0x32C):
        stop_task(bank,bank[slot])
        bank[slot] = 0


def fixture(initial,rng,trial):
    memory = initial[:]
    bank = memoryview(memory)[65536:]
    base = word(bank,0x9C)
    ready,waiting = [],[]
    for index in range(20):
        node = base+16*index
        put_word(bank,node,0)
        bank[node+2:node+6] = bytes(((0,1,2,4,8,16,128)[(trial+index)%7],rng.randrange(256),index+2,1))
        if bank[node+2]==4 and (trial+index)%3: waiting.append(node)
        elif bank[node+2] in (2,8,16): ready.append(node)
    if trial%5==0: bank[base+4] = bank[base+16*9+4] = 200
    ready.sort(key=lambda node:bank[node+3])
    for head,chain in ((0xA0,ready),(0xA2,waiting)):
        put_word(bank,head,chain[0] if chain else 0)
        for index,node in enumerate(chain): put_word(bank,node,chain[index+1] if index+1<len(chain) else 0)
    put_word(bank,0x9E,0)
    return memory


def validate(rom):
    cpu.set_rom(rom)
    initialized,_ = boot_tasks.initialized(rom)
    initial = initialized.wram[:]
    rng = random.Random(0xD3AA)
    cases = dict(stop_missing=0,stop_existing=0,teardown_without_hdma=0,teardown_with_hdma=0)
    for trial in range(480):
        expected = fixture(initial,rng,trial)
        bank = memoryview(expected)[65536:]
        selector = (0,255,2+trial%20,200)[trial%4] | rng.randrange(256)<<8
        memory = expected[:]
        node = stop_task(bank,selector)
        c = cpu.CPU()
        c.wram[:] = memory
        direct,data_bank = rng.randrange(65536),rng.randrange(256)
        c.D,c.DB = direct,data_bank
        boot_tasks.call(c,0xACAC,A=selector)
        boot_transform.compare_memory(c.wram,expected,('stop task',trial))
        assert c.X==node and (c.D,c.DB,c.S,c.M,c.XF)==(direct,data_bank,0x1FFF,1,0)
        cases['stop_existing' if node else 'stop_missing'] += 1
    for trial in range(240):
        expected = fixture(initial,rng,trial)
        bank = memoryview(expected)[65536:]
        for slot in range(0x318,0x32C): bank[slot] = rng.choice((0,255,200,*range(2,22)))
        mirror = word(bank,0x2E2)
        put_word(bank,mirror+0x2C,rng.randrange(65536))
        existing = trial%2
        if existing:
            channel = (trial//2)%8
            for higher in range(channel+1,8): bank[0x72+higher] = 99
            descriptor = boot_dma.allocate_descriptor(bank,expected,5)
            put_word(bank,0x30E,descriptor)
            boot_dma.submit(bank,descriptor)
            reference = trial%33
            bank[descriptor+13] = reference
            if reference: bank[word(bank,0x68)+reference-1] = rng.randrange(256)
        else: put_word(bank,0x30E,0)
        memory = expected[:]
        teardown(expected)
        c = cpu.CPU()
        c.wram[:] = memory
        c.D,c.DB = 0x300,0x7F
        boot_tasks.call(c,0xD3AA)
        boot_transform.compare_memory(c.wram,expected,('title teardown',trial))
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0) and c.X==0x32C
        assert word(bank,0x30E)==0 and not any(bank[0x318:0x32C])
        boot_ppu_queue.apply_shadow(bank,expected[0x603E:0x6072])
        boot_tasks.call(c,0xC18B)
        boot_transform.compare_memory(c.wram,expected,'teardown shadow service')
        assert bank[mirror+0x2C]&1==0
        cases['teardown_with_hdma' if existing else 'teardown_without_hdma'] += 1
    return dict(verified=True,cases=cases,comparison='full WRAM outside caller stack1F80-1FFF; task lookup X, teardown final X, caller restoration and original PPU shadow service',scope='480 ACAC calls with low-byte selectors, missing/first duplicate ids, statuses00/01/02/04/08/10/80 and linked/unlinked waiting nodes; 240 continuous D3AA calls with20 tracked ids, available PPU resources, absent/present kind05 descriptor across all eight channels and varied references; wake/list/descriptor/PPU helpers execute; status10 requests do not themselves link completion/reap or decrement active count; live stopped-task dispatch, physical HDMA/IRQ timing and exhaustion open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
