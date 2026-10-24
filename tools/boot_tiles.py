"""Recovered colour-to-eight-bit tile packing and temporary graphics submission.
usage: boot_tiles.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_graphics,boot_colour,boot_heap,boot_copy_queue,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def queue_tile(mem,rom,argument,source):
    """$BF2A: copy 64 bytes to raw temporary RAM and submit graphics kind 43."""
    bank = memoryview(mem)[65536:]
    temporary = boot_heap.allocate_units(bank,1)
    source_bank = argument&255
    for index in range(64):
        offset = (source+index)&65535
        if source_bank==0 and offset<0x2000:
            value = mem[offset]
        else:
            value = boot_copy_queue.read(mem,rom,source_bank<<16|offset)
        bank[temporary+index] = value
    destination = boot_graphics.allocate_block(bank,0x43)
    node = boot_graphics.queue_block(bank,mem,0xFF7F,destination,temporary)
    return destination,node


def lookup_colour(data,cache,node,threshold_high):
    """The target uses caller DB; samples and cache always use bank 7F."""
    cell = boot_colour.quantize(data,node)
    result = cache[0x8000+cell]
    if result: return result,threshold_high
    threshold = 255|(threshold_high<<8)
    source = word(cache,0x1A)
    for index in range(232):
        distance = sum((cache[source+4*index+lane]-data[node+lane])**2 for lane in range(3))&65535
        if distance<threshold:
            threshold,result = distance,index+15
    cache[0x8000+cell] = result
    return result,threshold>>8


def convert_tile(mem,rom,source,output_bank=0x7E,threshold_high=0):
    """$9D1E: compact 64 colour indices, pack eight bitplanes and queue them."""
    bank = memoryview(mem)[65536:]
    output = memoryview(mem)[(output_bank-0x7E)*65536:(output_bank-0x7E+1)*65536]
    for index in range(64):
        at = source+4*index
        result,threshold_high = lookup_colour(output,bank,at,threshold_high)
        output[source+index] = result
    for row in range(8):
        for plane in range(8):
            bits = 0
            for column in range(8):
                at = source+row*8+column
                bits = (bits<<1)|(output[at]&1)
                output[at] >>= 1
            output[source+0xC0+row*2+(plane//2)*16+(plane&1)] = bits
    transfer_source = ((source+78)&0xFF00)|((source+0xC0)&255)
    return queue_tile(mem,rom,0,transfer_source)


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    initial.DB = 0x7F
    boot_tasks.call(initial,0x809B,A=0x43,X=0x80)
    baseline = initial.wram[:]
    rng = random.Random(0xBF2A)
    cases = dict(queue_tile=0,convert_tile=0,real_colour_pipeline=0)
    for trial in range(240):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        source_bank = (0x7E,0x7F,0xC0,0xC1,0)[trial%5]
        source = 0x1000 if source_bank==0 else 0x5000
        if source_bank in (0x7E,0x7F):
            base = (source_bank-0x7E)*65536+source
            memory[base:base+64] = rng.randbytes(64)
        elif source_bank==0: memory[source:source+64] = rng.randbytes(64)
        slot = boot_graphics.slot_address(bank,0x43)
        workspace = word(bank,slot+6)
        bank[workspace:workspace+trial%16] = bytes([1])*(trial%16)
        if trial%7==0: bank[workspace:workspace+128] = bytes([1])*128
        expected = memory[:]
        argument = source_bank|(rng.randrange(256)<<8)
        destination,node = queue_tile(expected,rom,argument,source)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = (0,0x7E,0x7F)[trial%3]
        original_db = c.DB
        boot_tasks.call(c,0xBF2A,A=argument,X=source)
        assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:],('queue tile',trial,destination,node)
        assert c.DB==original_db,('queue tile bank restoration',trial)
        cases['queue_tile'] += 1
    for trial in range(96):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        source = (0x800,0x920,0xA80,0xBC0)[trial%4]
        output_bank = 0x7E if trial%2 else 0x7F
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
        bank[source:source+256] = bytes(rng.randrange(32) for _ in range(256))
        if output_bank==0x7E:
            put_word(memory,0x1A,0x5200)
            memory[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
            memory[source:source+256] = bank[source:source+256]
        bank[0x8000:0x9000] = bytes(4096) if trial%3==0 else bytes(rng.randrange(1,247) for _ in range(4096))
        high = (0,1,15,255)[trial%4]
        expected = memory[:]
        destination,node = convert_tile(expected,rom,source,output_bank,high)
        c = cpu.CPU()
        c.wram[:] = memory
        c.wram[0x1FD9] = high
        c.DB = output_bank
        boot_tasks.call(c,0x9D1E,X=source,step_limit=5_000_000)
        assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:],('convert tile',trial,destination,node)
        assert c.DB==output_bank,('convert tile bank restoration',trial)
        cases['convert_tile'] += 1
    for trial in range(2):
        expected = baseline[:]
        bank = memoryview(expected)[65536:]
        c = cpu.CPU()
        c.wram[:] = baseline
        c.DB = 0x7F
        for _ in range(trial):
            boot_heap.allocate_units(bank,1)
            boot_tasks.call(c,0xB081,X=128)
        boot_colour.allocate_tree(bank)
        boot_graphics.initialize_staging(bank)
        boot_colour.build_tree(expected,rom,0xD2E536)
        boot_colour.initialize_decoder(bank,0x80,0xD2,0xE6BC)
        boot_colour.components(expected,rom,0x80)
        boot_colour.initialize_lookup(bank,expected)
        boot_colour.queue_sample_palette(bank,expected)
        boot_tasks.call(c,0xA061)
        boot_tasks.call(c,0x833E)
        boot_tasks.call(c,0xA090,A=0xD2,X=0xE536)
        c.Y = 0xE6BC
        boot_tasks.call(c,0xA12E,A=0xD2,X=0x80)
        boot_tasks.call(c,0x83AD,X=0x80)
        boot_tasks.call(c,0x8621,step_limit=5_000_000)
        boot_tasks.call(c,0x8686)
        samples = word(bank,0x1A)
        assert all(bank[samples+4*index+lane]<32 for index in range(232) for lane in range(3)), 'real sample component domain'
        source = 0x900+0x20*trial
        for memory in (expected,c.wram):
            actual_bank = memoryview(memory)[65536:]
            actual_samples = word(actual_bank,0x1A)
            memory[source:source+256] = actual_bank[actual_samples:actual_samples+256]
            memory[0x5000:0x53A0] = actual_bank[actual_samples:actual_samples+928]
            put_word(memory,0x1A,0x5000)
        high = (0,15)[trial]
        convert_tile(expected,rom,source,0x7E,high)
        c.DB = 0x7E
        c.wram[0x1FD9] = high
        boot_tasks.call(c,0x9D1E,X=source,step_limit=5_000_000)
        assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:],('real colour pipeline',trial)
        cases['real_colour_pipeline'] += 1
    return dict(cases=cases,verified=True,comparison='all WRAM outside caller stack scratch 1F80-1FFF; DB restoration',scope='two real D2E536 tree/D2E6BC stream to lookup/palette/tile compositions at different heap placements; available RAM and descriptors; graphics workspace fragmentation/exhaustion; source banks 7E/7F/C0/C1 and low bank-00 WRAM mirror; tile samples are five-bit components, caller output DB 7E/7F, cache hits/misses and retained threshold high bytes; no physical DMA payload or timing')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
