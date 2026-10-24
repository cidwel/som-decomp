"""Recovered boot graphics-buffer registration and VRAM destination setup.
usage: boot_graphics.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_heap,boot_vram,boot_ppu_queue,boot_dma,boot_palette,boot_pool,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def slot_address(mem,flags):
    """$805F: select an eight-byte graphics registration from packed flag bits."""
    index = ((flags>>2)|(flags>>4))&7
    return (word(mem,0x16)+8*index)&65535


def create_buffer(mem,image,flags,size):
    """$809B: allocate workspace/pages and queue the graphics base-register update."""
    slot = slot_address(mem,flags)
    workspace = boot_heap.allocate_bytes(mem,size,0)
    put_word(mem,slot+6,workspace)
    put_word(mem,slot+4,workspace)
    kind = flags&3
    mem[slot+2] = kind
    scaled = (size<<(kind-1 if kind else 15))&65535
    pages = (((scaled+127)&65535)&0xFF80)>>7
    mem[slot+1] = pages&255
    page = boot_vram.allocate_pages(mem,((flags&0xFC)<<8)|(pages&255))
    mem[slot] = page
    bits = page>>2
    family = flags&0xFC
    if family==0x80: register,mask,bits = 1,0xF8,bits>>1
    elif family==0x40: register,mask = 0xB,0xF0
    elif family==0x44: register,mask,bits = 0xB,0x0F,(bits<<4)&255
    elif family==0x48: register,mask = 0xC,0xF0
    else: register,mask,bits = 0xC,0x0F,(bits<<4)&255
    node = boot_ppu_queue.allocate_entry(mem,image[0x603E:0x6072],register)
    mem[node+2] = (mem[node+2]&mask)|bits
    boot_ppu_queue.append_entry(mem,node)
    return (mem[slot]<<10)&65535


def release_buffer(mem,flags):
    """$81AA: clear page/count and workspace fields, then free both resources."""
    slot = slot_address(mem,flags)
    workspace = word(mem,slot+6)
    page = mem[slot]
    put_word(mem,slot+6,0)
    put_word(mem,slot,0)
    boot_heap.free_units(mem,workspace)
    boot_vram.release_pages(mem,page)


def allocate_block(mem,flags):
    """$81D6: cyclic first-free byte scan, tag it with the current task, return VRAM."""
    slot = slot_address(mem,flags)
    start,current = word(mem,slot+6),word(mem,slot+4)
    length = (mem[slot+1]<<8)>>mem[slot+2]
    candidate = current
    while mem[candidate]:
        candidate += 1
        if candidate>=start+length: candidate = start
        if candidate==current: return 0xFFFF
    mem[candidate] = boot_pool.task_id(mem)
    put_word(mem,slot+4,candidate)
    offset = ((candidate-start)<<5)&65535
    kind = word(mem,slot+2)
    if kind!=3:
        offset >>= 1
        if kind!=2: offset >>= 1
    page = mem[slot]<<2
    base = ((page&255)<<8)|(page>>8)
    return (base+offset)&65535


def address_tag(mem,address):
    """$D6B3: read a tag word from the bitmap page containing a VRAM address."""
    return word(mem,word(mem,0x32C)+((address&0xFC00)>>10))


def release_block(mem,address):
    """$8277: resolve the registration from the page tag, clear its workspace byte."""
    slot = slot_address(mem,address_tag(mem,address)&255)
    kind = word(mem,slot+2)&3
    offset = ((address-(mem[slot]<<10))&65535)>>3
    if kind!=1: offset >>= 1
    if kind not in (1,2): offset >>= 1
    target = (word(mem,slot+6)+offset)&65535
    put_word(mem,slot+4,target)
    mem[target] = 0
    return target


def queue_block(mem,image,argument,destination,source):
    """$82D4: submit one graphics block, optionally releasing its source on cleanup."""
    node = boot_dma.allocate_descriptor(mem,image,9 if argument>>8 else 1)
    if node is None: return None
    slot = slot_address(mem,address_tag(mem,destination)&255)
    size = (8<<(word(mem,slot+2)&15))&65535
    put_word(mem,node+5,size)
    put_word(mem,node+10,destination)
    put_word(mem,node+2,source)
    mem[node+4] = argument&255
    boot_dma.submit(mem,node)
    return node


def initialize_staging(mem):
    """$833E: allocate zero-filled 52-byte and 1024-byte staging buffers."""
    put_word(mem,0x18,boot_heap.allocate_bytes(mem,0x34,0))
    put_word(mem,0x1A,boot_heap.allocate_bytes(mem,0x400,0))


def release_staging(mem):
    """$8363: release both staging pointers without clearing them."""
    boot_heap.free_units(mem,word(mem,0x18))
    boot_heap.free_units(mem,word(mem,0x1A))


def prepare_scene(mem,rom):
    """$BA7F: graphics, palette and background-map producers composed without hooks."""
    bank = memoryview(mem)[65536:]
    destination = create_buffer(bank,mem,0x49,0x200)
    for source,offset in ((0x2000,0),(0x3000,0x800)):
        node = boot_dma.allocate_descriptor(bank,mem,1)
        put_word(bank,node+10,(destination+offset)&65535)
        put_word(bank,node+2,source)
        put_word(bank,node+5,0x1000)
        bank[node+4] = 0x7E
        boot_dma.submit(bank,node)
    palette = boot_palette.allocate_palette(bank,0)
    boot_palette.copy_colours(mem,rom,palette,0x7E5150,0x7E12)
    group = boot_palette.queue_palette(bank,mem,palette)
    value = (((group<<2)|0x20)&255)<<8
    buffer = boot_vram.create_buffer(bank,mem,0x19)
    at = buffer
    for _ in range(14):
        for _ in range(16):
            put_word(bank,at,value)
            put_word(bank,at+0x20,value^0x100)
            at += 2
            value = (value+1)&65535
        at += 0x20
    for _ in range(0x640):
        put_word(bank,at,0x210F)
        at += 2
    boot_dma.queue_vram_buffer(bank,mem,buffer)
    for register,value in ((0x12,0xFFC8),(0x11,0)):
        node = boot_ppu_queue.allocate_entry(bank,mem[0x603E:0x6072],register)
        put_word(bank,node+2,value)
        boot_ppu_queue.append_entry(bank,node)


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    rng = random.Random(0x809B)
    cases = dict(slot_address=0,create_buffer=0,prepare_scene=0,release_buffer=0,allocate_block=0,address_tag=0,release_block=0,block_roundtrip=0,queue_block=0,allocate_queue_block=0,initialize_staging=0,release_staging=0,queued_source_cleanup=0)
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        flags = rng.randrange(256)
        expected = slot_address(bank,flags)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0x805F,A=flags)
        assert c.wram[65536:]==bank and c.A==expected,('graphics slot',trial,c.A,expected)
        cases['slot_address'] += 1
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        bank[0x1900:0x1960] = bytes(96) if trial%7 else bytes([0x40]*96)
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4:0x104],bank[0x1C4:0x204] = bytes([1]*64),bytes([1]*64)
        bank[0xC0] = 64
        put_word(bank,0xC2,64)
        put_word(bank,0x9E,0)
        if trial%17==0: bank[0xC4:0x1C4] = bytes([1]*256)
        put_word(bank,0x2D6,0x6000)
        put_word(bank,0x2D8,0x6004)
        put_word(bank,0x6004,0x6008)
        put_word(bank,0x2E2,0x7000)
        put_word(bank,0x2E0,0x2DE)
        put_word(bank,0x2DE,0)
        flags = (0x40,0x44,0x48,0x4C,0x80)[trial%5] | (1+(trial//5)%3)
        size = (64,128,256,512)[(trial//15)%4]
        expected = bank[:]
        result = create_buffer(expected,image,flags,size)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x809B,A=flags,X=size)
        assert c.wram[65536:]==expected and c.X==result and c.A==result,('graphics buffer',trial,c.A,c.X,result)
        cases['create_buffer'] += 1
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        put_word(bank,0x9E,0 if trial%3==0 else 0x1A00)
        bank[0x1A04] = (0,1,2,21,255)[trial%5]
        flags = (0x41,0x42,0x43,0x45,0x49,0x81)[trial%6]
        slot = slot_address(bank,flags)
        kind = flags&3
        bank[slot],bank[slot+1],bank[slot+2],bank[slot+3] = 1+trial%20,1,kind,0 if trial%2 else rng.randrange(1,256)
        start,length = 0x4000,256>>kind
        put_word(bank,slot+6,start)
        put_word(bank,slot+4,start+trial%length)
        bank[start:start+length] = bytes(rng.randrange(1,256) if rng.randrange(3) else 0 for _ in range(length))
        if trial%7==0: bank[start:start+length] = bytes([1]*length)
        expected = bank[:]
        result = allocate_block(expected,flags)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x81D6,A=flags)
        assert c.wram[65536:]==expected and c.X==result,('allocate block',trial,c.X,result)
        cases['allocate_block'] += 1
        page = bank[slot]
        bank[0x1900+page] = flags&0xFC
        address = (page<<10)+((trial%length)<<3)
        expected_tag = address_tag(bank,address)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        boot_tasks.call(c,0xD6B3,X=address)
        assert c.wram[65536:]==bank and c.A==expected_tag,('address tag',trial)
        cases['address_tag'] += 1
        expected = bank[:]
        result = release_block(expected,address)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x8277,X=address)
        assert c.wram[65536:]==expected and c.X==result,('release block',trial,c.X,result)
        cases['release_block'] += 1
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        bank[0x1900:0x1920] = bytes(16*(1+i//4) for i in range(32))
        flags = (0x41,0x45,0x49,0x4D,0x81)[trial%5]
        slot = slot_address(bank,flags)
        bank[slot],bank[slot+1] = trial%32,trial%16
        workspace = 0 if trial%5==0 else 0x5000
        put_word(bank,slot+6,workspace)
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        if workspace: bank[0xC4+0xA0],bank[0x1C4+0xA0] = 1,3
        expected = bank[:]
        release_buffer(expected,flags)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x81AA,A=flags)
        assert c.wram[65536:]==expected,('release graphics buffer',trial)
        cases['release_buffer'] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        put_word(bank,0x9E,0)
        flags = 0x40|(1+trial%3)
        slot = slot_address(bank,flags)
        kind = flags&3
        page = 1+trial%20
        bank[slot],bank[slot+1],bank[slot+2],bank[slot+3] = page,1,kind,0
        bank[0x1900+page] = 0x40
        start,length = 0x4000,256>>kind
        hole = (trial*7)%length
        bank[start:start+length] = bytes([1]*length)
        bank[start+hole] = 0
        put_word(bank,slot+6,start)
        put_word(bank,slot+4,start+trial%length)
        expected = bank[:]
        address = allocate_block(expected,flags)
        result = release_block(expected,address)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x81D6,A=flags)
        actual_address = c.X
        boot_tasks.call(c,0x8277,X=actual_address)
        assert actual_address==address and c.X==result and c.wram[65536:]==expected,('block roundtrip',trial)
        assert result==start+hole and expected[result]==0
        cases['block_roundtrip'] += 1
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,(0,1,255,256)[trial%4])
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        destination = (trial%32)<<10 | (trial*13)&0x3FF
        family = (0x40,0x44,0x48,0x4C,0x80)[trial%5]
        bank[0x1900+(destination>>10)] = family
        slot = slot_address(bank,family)
        put_word(bank,slot+2,(rng.randrange(256)<<8)|(trial%16))
        argument = (0,1,128,255)[(trial//16)%4]<<8 | (0x7E,0x7F,0xC0,0xFF)[trial%4]
        source = rng.randrange(65536)
        expected = bank[:]
        queue_block(expected,image,argument,destination,source)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB,c.Y = rng.randrange(256),source
        boot_tasks.call(c,0x82D4,A=argument,X=destination)
        assert c.wram[65536:]==expected,('queue block',trial)
        cases['queue_block'] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        put_word(bank,0x9E,0)
        flags = 0x40|(1+trial%3)
        slot = slot_address(bank,flags)
        kind,page = flags&3,1+trial%20
        bank[slot],bank[slot+1],bank[slot+2],bank[slot+3] = page,1,kind,0
        bank[0x1900+page] = 0x40
        start,length = 0x4000,256>>kind
        hole = (trial*7)%length
        bank[start:start+length] = bytes([1]*length)
        bank[start+hole] = 0
        put_word(bank,slot+6,start)
        put_word(bank,slot+4,start+trial%length)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,trial%8)
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        argument = 0x7F if trial%2 else 0x017F
        source = 0x5000+trial%128
        expected = bank[:]
        destination = allocate_block(expected,flags)
        node = queue_block(expected,image,argument,destination,source)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x81D6,A=flags)
        actual_destination = c.X
        c.Y = source
        boot_tasks.call(c,0x82D4,A=argument,X=actual_destination)
        assert actual_destination==destination and c.wram[65536:]==expected,('allocate and queue block',trial)
        assert word(expected,node+10)==destination and word(expected,node+5)==(8<<kind)
        cases['allocate_queue_block'] += 1
    for trial in range(200):
        bank = bytearray(rng.randbytes(65536))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4:0x104],bank[0x1C4:0x204] = bytes([1]*64),bytes([1]*64)
        bank[0xC0] = 64
        put_word(bank,0xC2,64)
        put_word(bank,0x9E,0 if trial%2 else 0x1B00)
        bank[0x1B04] = 3
        if trial%3!=2:
            bank[0xC4:0x1C4] = bytes([1]*256)
            if trial%3==1: bank[0x104] = 0
        expected = bank[:]
        initialize_staging(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x833E)
        assert c.wram[65536:]==expected,('initialize staging',trial)
        cases['initialize_staging'] += 1
        bank = bytearray(rng.randbytes(65536))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        for unit in range(64,74): bank[0xC4+unit],bank[0x1C4+unit] = (66-unit if unit<66 else 74-unit),3
        put_word(bank,0x18,0 if trial%5==0 else 0x2000)
        put_word(bank,0x1A,(0,0x2000,0x2100)[trial%3])
        expected = bank[:]
        release_staging(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x8363)
        assert c.wram[65536:]==expected,('release staging',trial)
        cases['release_staging'] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x16,0x1800)
        put_word(bank,0x32C,0x1900)
        bank[0x1901] = 0x40
        slot = slot_address(bank,0x40)
        put_word(bank,slot+2,1+trial%3)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x6C,0)
        put_word(bank,0x6E,0)
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        source = 0x5000+128*(trial%4)
        unit = source>>7
        bank[0xC4+unit],bank[0x1C4+unit] = 1,3
        argument = 0x7F if trial%2 else 0x017F
        expected = bank[:]
        node = queue_block(expected,image,argument,0x400,source)
        put_word(expected,0x6E,1)
        boot_dma.cleanup(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB,c.Y = rng.randrange(256),source
        boot_tasks.call(c,0x82D4,A=argument,X=0x400)
        put_word(c.wram,65536+0x6E,1)
        boot_tasks.call(c,0x92E9)
        assert c.wram[65536:]==expected,('queued source cleanup',trial)
        assert expected[0xC4+unit]==(1 if trial%2 else 0) and expected[node+15]==0
        cases['queued_source_cleanup'] += 1
    initialized,_ = boot_tasks.initialized(rom)
    for trial in range(96):
        memory = initialized.wram[:]
        bank = memoryview(memory)[65536:]
        bitmap = word(bank,0x32C)
        for index in range(trial%5): bank[bitmap+index] = 0x10
        palette_base = word(bank,0x2D2)
        for index in range(trial%9): put_word(bank,palette_base+32*index,0)
        expected = memory[:]
        prepare_scene(expected,rom)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = 0x7F
        boot_tasks.call(c,0xBA7F)
        assert c.wram[65536:]==expected[65536:],('prepare scene',trial)
        cases['prepare_scene'] += 1
    return {'cases':cases,'verified':True,'comparison':'whole bank 7F; slot A, creation A/X, allocated/released block X and page-tag A',
            'configuration_source':'C7B480 -> 7E5000','scope':'staging creation/release including partial allocation failure; source cleanup after a supplied completed-count boundary; 320 graphics-block submissions with format nibble 0-15 and 160 allocation/submission compositions; descriptor data includes zero wrapped size, not 64-KiB hardware transfer; block kinds 1-3, valid cyclic workspace spans, page zero release, all-occupied return FFFF and 160 allocation/release roundtrips; 96 complete BA7F scene-preparation cases with all original callees, controlled bitmap/palette occupancy and palette exhaustion; packed slot flags; creation families 40/44/48/4C/80, kinds 1-3 and workspace sizes 64/128/256/512; controlled valid pools with RAM/VRAM failure; kind 0 and zero page count unverified'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
