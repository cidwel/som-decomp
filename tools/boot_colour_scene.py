"""Recovered colour-scene resource preparation, templates and teardown.
usage: boot_colour_scene.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_colour,boot_graphics,boot_heap,boot_vram,boot_dma,boot_copy_queue,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def release_registered_buffer(mem,source):
    """$C826: clear registration source/page/count and free both resources."""
    node = boot_dma.find_vram_buffer(mem,source)
    saved = word(mem,node+2)
    put_word(mem,node+2,0)
    boot_heap.free_units(mem,saved)
    page = word(mem,node)
    put_word(mem,node,0)
    boot_vram.release_pages(mem,page&255)


def copy_map_template(mem,rom,destination):
    """$9763: copy 256 configuration bytes from 7E:50C0 into bank 7F."""
    boot_copy_queue.copy_pointer(mem,rom,0x7E50C0,0x7F0000|destination,256)


def initialize_scene_template(mem):
    """$991C: copy 64 configuration bytes into low WRAM and append one zero byte."""
    mem[0x1D00:0x1D40] = mem[0x5FCA:0x600A]
    mem[0x1D40] = 0


def prepare_scene(mem,rom):
    """$BE5B: create colour graphics/BG resources, arrange tiles, and queue the map."""
    bank = memoryview(mem)[65536:]
    boot_graphics.create_buffer(bank,mem,0x43,0x180)
    source = boot_vram.create_buffer(bank,mem,0x10)
    put_word(bank,0x2D4,source)
    value = 0
    for pair in range(12):
        row = source+0x580-0x80*pair
        for column in range(16):
            at = row+4*column
            for offset,increment in ((0,0),(0x40,1),(0x42,2),(2,3)):
                put_word(bank,at+offset,value+increment)
            value += 4
    copy_map_template(mem,rom,source+0x600)
    boot_dma.queue_vram_buffer(bank,mem,source)


def release_scene(mem):
    """$BF10: release the remembered BG buffer and graphics registration 43."""
    release_registered_buffer(mem,word(mem,0x2D4))
    boot_graphics.release_buffer(mem,0x43)


def prepare_colour_resources(mem,rom):
    """$964B: compose scene, expanded tree, staging and low-WRAM template setup."""
    prepare_scene(mem,rom)
    bank = memoryview(mem)[65536:]
    boot_colour.allocate_tree(bank)
    boot_graphics.initialize_staging(bank)
    initialize_scene_template(mem)


def release_colour_resources(mem):
    """$9660: release staging, tree and scene; $994D has no memory effect."""
    bank = memoryview(mem)[65536:]
    boot_graphics.release_staging(bank)
    boot_colour.release_tree(bank)
    release_scene(bank)


def checked_call(memory,address,model,rom=None,A=None,X=None,db=0x7F):
    expected = memory[:]
    if rom is None: model(expected)
    else: model(expected,rom)
    c = cpu.CPU()
    c.wram[:] = memory
    c.DB = db
    boot_tasks.call(c,address,A=A,X=X)
    assert c.wram[:0x1F80]==expected[:0x1F80] and c.wram[0x2000:]==expected[0x2000:],('colour scene',hex(address))
    assert c.DB==db,('colour scene DB',hex(address))
    return c.wram[:]


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xBE5B)
    cases = dict(release_registered_buffer=0,copy_map_template=0,initialize_scene_template=0,template_release=0,prepare_scene=0,release_scene=0,prepare_colour_resources=0,release_colour_resources=0)
    registered = baseline[:]
    bank = memoryview(registered)[65536:]
    for index in range(4): boot_vram.create_buffer(bank,registered,0x10+4*index)
    for trial in range(240):
        memory = registered[:]
        bank = memoryview(memory)[65536:]
        node = word(bank,0x2F4)+8*(trial%4)
        source = word(bank,node+2)
        put_word(bank,node+4,rng.randrange(65536))
        put_word(bank,node+6,rng.randrange(65536))
        checked_call(memory,0xC826,lambda m:release_registered_buffer(memoryview(m)[65536:],source),X=source,db=(0,0x7E,0x7F)[trial%3])
        cases['release_registered_buffer'] += 1
        memory = baseline[:]
        destination = 0x4000+2*(trial%64)
        memory[65536+destination:65536+destination+256] = rng.randbytes(256)
        checked_call(memory,0x9763,lambda m,r:copy_map_template(m,r,destination),rom,X=destination,db=(0,0x7E,0x7F)[trial%3])
        cases['copy_map_template'] += 1
        memory[0x1D00:0x1D80] = rng.randbytes(128)
        checked_call(memory,0x991C,initialize_scene_template,db=(0,0x7E,0x7F)[trial%3])
        cases['initialize_scene_template'] += 1
    for trial in range(16):
        checked_call(baseline,0x994D,lambda m:None,db=trial*17)
        cases['template_release'] += 1
    for trial in range(96):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        bitmap = word(bank,0x32C)
        if trial%3==0: bank[bitmap:bitmap+32] = bytes([0x80])*32
        else: bank[bitmap:bitmap+trial%8] = bytes([0x80])*(trial%8)
        prepared = checked_call(memory,0xBE5B,prepare_scene,rom,db=(0,0x7E,0x7F)[trial%3])
        cases['prepare_scene'] += 1
        checked_call(prepared,0xBF10,lambda m:release_scene(memoryview(m)[65536:]),db=(0,0x7E,0x7F)[trial%3])
        cases['release_scene'] += 1
        prepared = checked_call(memory,0x964B,prepare_colour_resources,rom,db=(0,0x7E,0x7F)[trial%3])
        cases['prepare_colour_resources'] += 1
        checked_call(prepared,0x9660,release_colour_resources,db=(0,0x7E,0x7F)[trial%3])
        cases['release_colour_resources'] += 1
    return dict(cases=cases,verified=True,comparison='all WRAM outside caller stack scratch 1F80-1FFF and DB restoration',scope='real boot/configuration image; matched registered buffers including page zero; retained record fields and template tails; available heap/descriptor/PPU records, independent VRAM success/exhaustion; all original callees execute; source pointers and pending descriptor payloads retained by teardown; no physical DMA or complete scene/task timing')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
