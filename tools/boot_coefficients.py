"""Recovered 8-by-8 diagonal coefficient decoding and real image-stream consumption.
usage: boot_coefficients.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_colour,boot_graphics,boot_decode,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def diagonal_offsets():
    order = []
    for diagonal in range(15):
        rows = range(max(0,diagonal-7),min(7,diagonal)+1)
        if not diagonal&1: rows = reversed(rows)
        order.extend(2*(8*row+diagonal-row) for row in rows)
    return order

ORDER = diagonal_offsets()


def decode_block(mem,rom,node,destination,previous):
    """$995C: first coefficient predicts from previous; remaining 63 are direct deltas."""
    put_word(mem,destination,previous&65535)
    dc = (previous+boot_colour.delta(mem,rom,node))&65535
    put_word(mem,destination,dc)
    for offset in ORDER[1:]:
        put_word(mem,destination+offset,boot_colour.delta(mem,rom,node)&65535)
    return dc


def call_block(c,node,destination,previous):
    c.S,c.PB,c.PC,c.M,c.XF,c.D,c.X,c.A = 0x1FFF,0x7E,0x995C,0,0,destination,node,previous
    c.push16(0xFFFD)
    start = c.steps
    while c.PB<<16|c.PC!=0x7EFFFE:
        c.step()
        if c.steps-start>1_000_000: raise RuntimeError('coefficient block timeout')


def verify_real_image(rom):
    """Compare the palette prelude and all 192 six-block image groups with original reads."""
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    expected = initial.wram[:]
    bank = memoryview(expected)[65536:]
    boot_colour.allocate_tree(bank)
    boot_graphics.initialize_staging(bank)
    header = boot_colour.build_tree(expected,rom,0xD2E536)
    stream = 0xE536+3*((header>>8)+1)
    boot_colour.initialize_decoder(bank,0x80,0xD2,stream)
    boot_colour.components(expected,rom,0x80)
    c = cpu.CPU()
    c.wram[:] = initial.wram
    c.DB = 0x7F
    boot_tasks.call(c,0xA061)
    boot_tasks.call(c,0x833E)
    boot_tasks.call(c,0xA090,A=0xD2,X=0xE536)
    c.Y = stream
    boot_tasks.call(c,0xA12E,A=0xD2,X=0x80)
    boot_tasks.call(c,0x83AD,X=0x80)
    assert c.wram[65536:]==bank, 'real coefficient palette prelude'
    fetched = (word(bank,0x80)-stream)&65535
    previous = [header&255,0,0]
    for group in range(192):
        for block in range(6):
            channel = 0 if block<4 else block-3
            destination = 0x1600+0x100*block
            before = word(bank,0x80)
            result = decode_block(expected,rom,0x80,destination,previous[channel])
            call_block(c,0x80,destination,previous[channel])
            assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:] and c.A==result,('real coefficient block',group,block)
            fetched += (word(bank,0x80)-before)&65535
            previous[channel] = result
    used = fetched-bank[0x86]//8
    segments = []
    remaining,offset = min(used,65536),stream
    while remaining:
        size = min(remaining,65536-offset)
        segments.append(dict(source=f'D2{offset:04X}',size=size))
        remaining -= size
        offset = 0
    return dict(tree_source='D2E536',tree_size=3*((header>>8)+1),stream_source=f'D2{stream:04X}',stream_refill_cursor=f'D2{word(bank,0x80):04X}',stream_bytes_fetched=fetched,stream_bytes_consumed=used,stream_segments=segments,bits_remaining=bank[0x86],cached_symbol=bank[0x87],groups=192,blocks_per_group=6,blocks=1152,coefficients=73728,initial_predictors=[header&255,0,0],verification='palette prelude and 1152 sequential original coefficient calls; full WRAM outside caller scratch and full returned DC',scope='coefficient-read projection of the 12-by-16 group loop; transforms, task synchronization and proof of complete asset endpoint remain open')


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,0xC77C00,0x7E8000)
    rng = random.Random(0x995C)
    for trial in range(240):
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        bank = memoryview(memory)[65536:]
        put_word(bank,0x8A,0x3000)
        for index in range(7):
            for bit in range(2): put_word(bank,0x3000+4*index+2*bit,0x3000+4*(2*index+1+bit))
        for index,value in enumerate((0,1,63,64,127,128,129,255)): put_word(bank,0x301C+4*index,value)
        put_word(bank,0x2800,0x5000)
        bank[0x2802] = (0x7E,0x7F,0xC0,0xC1)[trial%4]
        put_word(bank,0x2804,rng.randrange(65536))
        bank[0x2806],bank[0x2807] = trial%17,(0,64,127,128,129,255)[trial%6]
        destination = 0x500+0x80*(trial%12)
        previous = (0,1,0x7FFF,0x8000,0xFFFF,rng.randrange(65536))[trial%6]
        expected = memory[:]
        result = decode_block(expected,rom,0x2800,destination,previous)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = trial%256
        call_block(c,0x2800,destination,previous)
        assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:] and c.A==result and c.D==destination and c.DB==trial%256,('generated coefficient block',trial)
    real = verify_real_image(rom)
    return dict(cases=dict(generated_blocks=240,real_image_sequence=1),verified=True,real_image=real,comparison='all WRAM outside caller scratch 1F80-1FFF and full returned DC; generated D/DB restoration',scope='native M=0/X=0 entry, nonwrapping low-WRAM direct-page output; generated valid tree, RAM/ROM sources, cache/refill and predictor boundaries; real palette followed by all 1152 coefficient blocks; no transform/render/task-completion claim')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
