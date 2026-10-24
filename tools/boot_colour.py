"""Recovered boot bit-tree/delta decoding and colour-component conversions.
usage: boot_colour.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_heap,boot_graphics,boot_copy_queue,boot_dma,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def allocate_tree(mem):
    """$A061: allocate and zero the 1536-byte expanded-tree area."""
    put_word(mem,0x8A,boot_heap.allocate_bytes(mem,0x600,0))


def release_tree(mem):
    """$A07B: free the tree area without clearing its saved pointer."""
    boot_heap.free_units(mem,word(mem,0x8A))


def build_tree(mem,rom,source):
    """$A090: expand relative child-byte pairs and a fixed-offset leaf table."""
    bank = memoryview(mem)[65536:]
    header = boot_copy_queue.read(mem,rom,source)|boot_copy_queue.read(mem,rom,source+1)<<8
    branches = header>>8
    root = word(bank,0x8A)
    leaves = root+0x3FC
    position = source+2
    for index in range(branches or 65536):
        node = root+4*index
        for side in range(2):
            child = boot_copy_queue.read(mem,rom,position+side)
            address = node+4*(child+1)
            if address>=leaves: address = leaves+((address-leaves)>>1)
            put_word(bank,node+2*side,address&65535)
        position += 2
    for index in range(branches+1):
        put_word(bank,leaves+2*index,boot_copy_queue.read(mem,rom,position))
        position += 1
    return header


def initialize_decoder(mem,node,bank,source):
    """$A12E: set the source pointer/bank and clear bit/cache words."""
    put_word(mem,node,source)
    mem[node+2] = bank&255
    put_word(mem,node+4,0)
    put_word(mem,node+6,0)


def symbol(mem,rom,node):
    """$A14E: traverse the word-pointer tree with MSB-first two-byte refills."""
    bank = memoryview(mem)[65536:]
    source = word(bank,node)
    branch = word(bank,0x8A)
    while True:
        if not bank[node+6]:
            put_word(bank,node+6,(word(bank,node+6)+16)&65535)
            address = bank[node+2]<<16|source
            first = boot_copy_queue.read(mem,rom,address)
            second = boot_copy_queue.read(mem,rom,address+1)
            put_word(bank,node+4,first<<8|second)
            source = (source+2)&65535
        put_word(bank,node+6,(word(bank,node+6)-1)&65535)
        bits = word(bank,node+4)
        put_word(bank,node+4,(bits<<1)&65535)
        leaf = word(bank,word(bank,branch+2*(bits>>15)))
        if leaf&0xFF00:
            branch = word(bank,branch+2*(bits>>15))
            continue
        put_word(bank,node,source)
        return leaf


def delta(mem,rom,node):
    """$A1A7: a decoded signed delta or one zero from its cached repetition."""
    bank = memoryview(mem)[65536:]
    value = bank[node+7]
    if not value&128:
        value = symbol(mem,rom,node)
        bank[node+7] = value
    if value&128:
        bank[node+7] = (value-1)&255
        return 0
    return value-128 if value&64 else value


def ramp(mem,rom,node,destination,count):
    """$837E: cumulative byte deltas at four-byte spacing; zero count means 256."""
    bank = memoryview(mem)[65536:]
    value = 0
    for index in range(count or 256):
        value = (value+delta(mem,rom,node))&255
        bank[destination+4*index] = value


def components(mem,rom,node):
    """$83AD: three sequential 232-sample ramps in component lanes 0/1/2."""
    bank = memoryview(mem)[65536:]
    for lane in range(3): ramp(mem,rom,node,word(bank,0x1A)+lane,232)


def quantize(mem,node):
    """$83E2: pack upper four bits of three five-bit components into a cube index."""
    return ((mem[node]&30)>>1)|((mem[node+1]&30)<<3)|((mem[node+2]&30)<<7)


def pack_colour(mem,node):
    """$8411: pack three low five-bit components into a fifteen-bit colour word."""
    return (mem[node]&31)|((mem[node+1]&31)<<5)|((mem[node+2]&31)<<10)


def mark_candidates(mem,offset):
    """$8444: translate 232 component triples, reject overflow and mark empty cells."""
    scratch,source = word(mem,0x18),word(mem,0x1A)
    count = 0
    for index in range(232):
        for lane in range(3):
            value = (mem[source+4*index+lane]+mem[offset+lane])&255
            if value&0xE0: break
            mem[scratch+lane] = value
        else:
            cell = 0x8000+quantize(mem,scratch)
            if not mem[cell]:
                mem[cell] = index+15
                count += 1
    return count


def distinct_offset(mem,node,start):
    """$84AE: compare three component bytes against earlier four-byte records."""
    for current in range(start,node,4):
        if mem[current:current+3]==mem[node:node+3]: return 0
    return 1


def reflect_offsets(mem,node):
    """$84EB: test the distinct sign combinations of one component-offset triple."""
    base = word(mem,0x18)+4
    current = base
    count = 0
    for mask in range(8):
        for lane in range(3):
            value = mem[node+lane]
            mem[current+lane] = (-value)&255 if mask&(1<<lane) else value
        if distinct_offset(mem,current,base):
            count = (count+mark_candidates(mem,current))&65535
            current += 4
    return count


def permute_offsets(mem,node):
    """$8577: generate three cyclic permutations, deduplicating the second."""
    base = word(mem,0x18)+0x24
    mem[base:base+3] = mem[node:node+3]
    count = reflect_offsets(mem,base)
    current = base+4
    mem[current:current+3] = bytes((mem[node+2],mem[node],mem[node+1]))
    if distinct_offset(mem,current,base):
        count = (count+reflect_offsets(mem,current))&65535
        current += 4
        mem[current:current+3] = bytes((mem[node+1],mem[node+2],mem[node]))
        count = (count+reflect_offsets(mem,current))&65535
    return count


def clear_lookup(mem):
    """$8607: clear the entire upper half of bank 7F."""
    mem[0x8000:] = bytes(0x8000)


def initialize_lookup(mem,image):
    """$8621: clear the lookup and try eight configuration offset triples."""
    clear_lookup(mem)
    node = word(mem,0x18)+0x30
    count = 0
    for offset in range(0,24,3):
        mem[node:node+4] = image[0x59E0+offset:0x59E4+offset]
        count = (count+permute_offsets(mem,node))&65535
        if count>=0x8000: return count
    return 0


def queue_sample_palette(mem,image):
    """$8686: pack the 232 samples and queue a source-releasing CGRAM upload."""
    destination = boot_heap.allocate_bytes(mem,0x200,0)
    put_word(mem,0x1C,destination)
    source = word(mem,0x1A)
    for index in range(232):
        put_word(mem,destination+2*index,pack_colour(mem,source+4*index))
    node = boot_dma.allocate_descriptor(mem,image,0x000A)
    put_word(mem,node+2,word(mem,0x1C))
    put_word(mem,node+5,0x1D0)
    mem[node+10],mem[node+4] = 15,0x7F
    boot_dma.submit(mem,node)


def nearest_sample(mem,node,cell,threshold=255):
    """$86F1: cache the first strictly closest modular squared-distance sample."""
    target = bytes(mem[node:node+3])
    source = word(mem,0x1A)
    selected = 0xF7
    for index in range(232):
        distance = 0
        for lane in range(3):
            difference = (mem[source+4*index+lane]-target[lane])&255
            if mem[source+4*index+lane]<target[lane]: difference = (-difference)&255
            distance = (distance+difference*difference)&65535
        if distance<threshold:
            threshold,selected = distance,232-index
    result = (0xF7-selected)&255
    mem[0x8000+cell] = result
    return result


def lookup_sample(mem,node,threshold=255):
    """$87C9: use a populated cube cell or cache a nearest-sample result."""
    cell = quantize(mem,node)
    result = mem[0x8000+cell]
    return (result if result else nearest_sample(mem,node,cell,threshold)),cell


def initialize_workspace(mem,argument,width,height):
    """$87DF: sign-extend two argument bytes and reserve an unfilled 32-byte area."""
    for address,value in ((0x20,argument&255),(0x1E,argument>>8)):
        put_word(mem,address,value|(0xFF00 if value&128 else 0))
    put_word(mem,0x24,width)
    put_word(mem,0x22,height)
    mem[0x26],mem[0x34] = 0,0
    pointer = boot_heap.allocate_units(mem,1)
    put_word(mem,0x30,pointer)
    return pointer


def verify_real_asset(rom,placements=1):
    """Recompute the D2:E536 tree/stream prefix and compare its original reader."""
    initial,_ = boot_tasks.initialized(rom)
    real_asset = None
    for trial in range(placements):
        memory = initial.wram[:]
        bank = memoryview(memory)[65536:]
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = 0x7F
        for _ in range(trial):
            boot_heap.allocate_bytes(bank,128,0)
            boot_tasks.call(c,0xB0A1,A=0,X=128)
        allocate_tree(bank)
        boot_graphics.initialize_staging(bank)
        header = build_tree(memory,rom,0xD2E536)
        stream = 0xE536+3*((header>>8)+1)
        initialize_decoder(bank,0x80,0xD2,stream)
        components(memory,rom,0x80)
        boot_tasks.call(c,0xA061)
        boot_tasks.call(c,0x833E)
        boot_tasks.call(c,0xA090,A=0xD2,X=0xE536)
        c.Y = stream
        boot_tasks.call(c,0xA12E,A=0xD2,X=0x80)
        boot_tasks.call(c,0x83AD,X=0x80)
        assert c.wram[65536:]==bank,('real ROM components',trial)
        real_asset = {'tree_source':'D2E536','header':header,'branches':header>>8,'leaves':(header>>8)+1,
                      'tree_size':3*((header>>8)+1),'stream_source':'D2%04X'%stream,
                      'stream_end':'D2%04X'%word(bank,0x80),'stream_bytes_read':word(bank,0x80)-stream,
                      'stream_used_prefix_bytes':word(bank,0x80)-stream-bank[0x86]//8,'bits_remaining':bank[0x86],'cached_symbol':bank[0x87],'samples':232,'component_lanes':3,
                      'verification':'%d complete original allocation/tree/decoder/component calls at different heap placements'%placements}
    return real_asset


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    rng = random.Random(0xA14E)
    cases = dict(lookup_sample=0,lookup_repeated=0,initialize_workspace=0,clear_lookup=0,initialize_lookup=0,queue_sample_palette=0,nearest_sample=0,real_rom_components=0,constructed_decoder=0,allocate_tree=0,release_tree=0,build_tree=0,initialize_decoder=0,symbol=0,delta=0,ramp=0,components=0,quantize=0,pack_colour=0,mark_candidates=0,distinct_offset=0,reflect_offsets=0,permute_offsets=0)
    def fixture(trial):
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        bank = memoryview(memory)[65536:]
        put_word(bank,0x8A,0x3000)
        for index in range(7):
            for bit in range(2): put_word(bank,0x3000+4*index+2*bit,0x3000+4*(2*index+1+bit))
        for index,value in enumerate((0,1,63,64,127,128,129,255)): put_word(bank,0x301C+4*index,value)
        source_bank = (0x7E,0x7F,0xC0,0xC1)[trial%4]
        node = 0x2800
        put_word(bank,node,0x5000 if source_bank>=0xC0 else 0x4000)
        bank[node+2] = source_bank
        put_word(bank,node+4,rng.randrange(65536))
        bank[node+6] = trial%17
        bank[node+7] = (0,64,127,128,129,255)[(trial//4)%6]
        put_word(bank,0x1A,0x6000)
        return memory,node
    real_asset = verify_real_asset(rom,placements=8)
    cases['real_rom_components'] = 8
    for trial in range(96):
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        bank = memoryview(memory)[65536:]
        put_word(bank,0x8A,0x3000)
        branches = (1,3,7,15,31,63,127,255)[trial%8]
        stream = bytearray((trial&255,branches))
        for index in range(branches):
            for side in range(2):
                child = 2*index+1+side
                virtual = child if child<branches else 255+child-branches
                stream.append(virtual-index-1)
        stream.extend(rng.randbytes(branches+1))
        memory[0x16000:0x16000+len(stream)] = stream
        memory[0x17000:0x17100] = rng.randbytes(256)
        expected = memory[:]
        build_tree(expected,rom,0x7F6000)
        initialize_decoder(memoryview(expected)[65536:],0x2800,0x7F,0x7000)
        results = [delta(expected,rom,0x2800) for _ in range(40)]
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = 0x7F
        boot_tasks.call(c,0xA090,A=0x7F,X=0x6000)
        c.Y = 0x7000
        boot_tasks.call(c,0xA12E,A=0x7F,X=0x2800)
        for result in results:
            boot_tasks.call(c,0xA1A7,X=0x2800)
            assert c.A==result&65535,('constructed delta',trial)
        assert c.wram[65536:]==expected[65536:],('constructed decoder state',trial)
        cases['constructed_decoder'] += 1
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4:0x104],bank[0x1C4:0x204] = bytes([1]*64),bytes([1]*64)
        bank[0xC0] = 64
        put_word(bank,0xC2,64)
        put_word(bank,0x9E,0)
        if trial%3==0: bank[0xC4:0x1C4] = bytes([1]*256)
        expected = bank[:]
        allocate_tree(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xA061)
        assert c.wram[65536:]==expected,('allocate tree',trial)
        cases['allocate_tree'] += 1
        bank = expected[:]
        expected = bank[:]
        release_tree(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xA07B)
        assert c.wram[65536:]==expected,('release tree',trial)
        cases['release_tree'] += 1
        memory = bytearray(rng.randbytes(131072))
        memory[:65536] = image
        b = memoryview(memory)[65536:]
        put_word(b,0x8A,0x3000)
        branches = (1,2,7,31,127,254,255)[trial%7]
        stream = bytes((trial&255,branches))+rng.randbytes(3*branches+1)
        source_bank = 0x7E if trial%2 else 0x7F
        source = source_bank<<16|0x6000
        memory[(source_bank-0x7E)*65536+0x6000:(source_bank-0x7E)*65536+0x6000+len(stream)] = stream
        expected = memory[:]
        result = build_tree(expected,rom,source)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xA090,A=source_bank,X=0x6000)
        assert c.wram[65536:]==expected[65536:] and c.A==result,('build tree',trial,c.A,result)
        cases['build_tree'] += 1
        bank = bytearray(rng.randbytes(65536))
        expected = bank[:]
        argument,offset = rng.randrange(65536),rng.randrange(65536)
        initialize_decoder(expected,0x2800,argument,offset)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB,c.Y = rng.randrange(256),offset
        boot_tasks.call(c,0xA12E,A=argument,X=0x2800)
        assert c.wram[65536:]==expected,('initialize decoder',trial)
        cases['initialize_decoder'] += 1
    for trial in range(240):
        memory,node = fixture(trial)
        for name,address in (('symbol',0xA14E),('delta',0xA1A7)):
            expected = memory[:]
            result = symbol(expected,rom,node) if name=='symbol' else delta(expected,rom,node)
            c = cpu.CPU()
            c.wram[:] = memory
            c.DB = 0x7F
            boot_tasks.call(c,address,X=node)
            assert c.wram[65536:]==expected[65536:] and c.A&255==result&255,(name,trial,c.A,result)
            if name=='delta': assert c.A==result&65535,(name,trial,c.A,result)
            cases[name] += 1
    for trial in range(96):
        memory,node = fixture(trial)
        expected = memory[:]
        count = (0,1,16,232)[trial%4]
        ramp(expected,rom,node,0x6000,count)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB,c.Y = 0x7F,0x6000
        boot_tasks.call(c,0x837E,A=count,X=node)
        assert c.wram[65536:]==expected[65536:],('ramp',trial)
        cases['ramp'] += 1
        expected = memory[:]
        components(expected,rom,node)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x83AD,X=node)
        assert c.wram[65536:]==expected[65536:],('components',trial)
        cases['components'] += 1
    for trial in range(320):
        memory = bytearray(rng.randbytes(65536))
        node = 0x4000
        for name,address,model in (('quantize',0x83E2,quantize),('pack_colour',0x8411,pack_colour)):
            result = model(memory,node)
            c = cpu.CPU()
            c.wram[:65536] = image
            c.wram[65536:] = memory
            c.DB = 0x7F
            boot_tasks.call(c,address,X=node)
            assert c.wram[65536:]==memory and c.X==result,(name,trial,c.X,result)
            cases[name] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x18,0x4000)
        put_word(bank,0x1A,0x5000)
        bank[0x8000:0x9000] = bytes(4096) if trial%3==0 else bytes(0 if rng.randrange(3) else rng.randrange(1,256) for _ in range(4096))
        bank[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
        bank[0x6000:0x6003] = bytes((0,1,255,31,32,128)[(trial+i)%6] for i in range(3))
        expected = bank[:]
        result = mark_candidates(expected,0x6000)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0x8444,X=0x6000)
        assert c.wram[65536:]==expected and c.A==result,('mark candidates',trial,c.A,result)
        cases['mark_candidates'] += 1
        node = 0x7000+4*(trial%9)
        if trial%3==0 and node>0x7000: bank[node:node+3] = bank[0x7000:0x7003]
        result = distinct_offset(bank,node,0x7000)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB,c.Y = 0x7F,0x7000
        boot_tasks.call(c,0x84AE,X=node)
        assert c.wram[65536:]==bank and c.A&255==result,('distinct offset',trial)
        cases['distinct_offset'] += 1
    for trial in range(48):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x18,0x4000)
        put_word(bank,0x1A,0x5000)
        bank[0x8000:0x9000] = bytes(4096) if trial%3==0 else bytes(0 if rng.randrange(3) else rng.randrange(1,256) for _ in range(4096))
        bank[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
        bank[0x6000:0x6003] = bytes(((0,0,0),(1,2,3),(3,3,3),(0,2,2),(31,32,255),(128,0,1))[trial%6])
        for name,address,model in (('reflect_offsets',0x84EB,reflect_offsets),('permute_offsets',0x8577,permute_offsets)):
            expected = bank[:]
            result = model(expected,0x6000)
            c = cpu.CPU()
            c.wram[:65536] = image
            c.wram[65536:] = bank
            c.DB = 0x7F
            boot_tasks.call(c,address,X=0x6000)
            assert c.wram[65536:]==expected and c.A==result,(name,trial,c.A,result)
            cases[name] += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = bytes(rng.randrange(32 if trial%2 else 256) for _ in range(928))
        bank[0x6000:0x6003] = bytes(rng.randrange(32 if trial%2 else 256) for _ in range(3))
        cell = rng.randrange(4096)
        high = (0,1,15,255)[trial%4]
        expected = bank[:]
        result = nearest_sample(expected,0x6000,cell,255|(high<<8))
        c = cpu.CPU()
        c.wram[:65536],c.wram[65536:] = image,bank
        c.wram[0x1FF2] = high
        c.DB,c.Y = 0x7F,0x6000
        boot_tasks.call(c,0x86F1,X=cell)
        assert c.wram[65536:]==expected and c.A&255==result,('nearest sample',trial,c.A,result)
        cases['nearest_sample'] += 1
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = bytes(rng.randrange(32 if trial%2 else 256) for _ in range(928))
        bank[0x6000:0x6003] = bytes(rng.randrange(32 if trial%2 else 256) for _ in range(3))
        cell = quantize(bank,0x6000)
        bank[0x8000+cell] = 0 if trial%3 else rng.randrange(1,256)
        high = (0,1,15,255)[trial%4]
        expected = bank[:]
        result,index = lookup_sample(expected,0x6000,255|(high<<8))
        c = cpu.CPU()
        c.wram[:65536],c.wram[65536:] = image,bank
        c.wram[0x1FED] = high
        c.DB = 0x7F
        boot_tasks.call(c,0x87C9,X=0x6000)
        assert c.wram[65536:]==expected and c.A&255==result and c.X==index,('lookup sample',trial,c.A,result,c.X,index)
        cases['lookup_sample'] += 1
        if trial%3:
            result,index = lookup_sample(expected,0x6000,255|(high<<8))
            c.wram[0x1FED] = high
            boot_tasks.call(c,0x87C9,X=0x6000)
            assert c.wram[65536:]==expected and c.A&255==result and c.X==index,('repeated lookup',trial)
            cases['lookup_repeated'] += 1
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4:0x104],bank[0x1C4:0x204] = bytes([1]*64),bytes([1]*64)
        bank[0xC0] = 64
        put_word(bank,0xC2,64)
        put_word(bank,0x9E,0 if trial%2 else 0x600)
        bank[0x604] = trial%22
        if trial%3==0: bank[0xC4:0x1C4] = bytes([1]*256)
        argument = (0,0x7F80,0x80FF,0xFF00,0x8080,0x0102)[trial%6]
        width,height = rng.randrange(65536),rng.randrange(65536)
        expected = bank[:]
        result = initialize_workspace(expected,argument,width,height)
        c = cpu.CPU()
        c.wram[:65536],c.wram[65536:] = image,bank
        c.DB,c.Y = (0,0x7E,0x7F)[trial%3],height
        original_db = c.DB
        boot_tasks.call(c,0x87DF,A=argument,X=width)
        assert c.wram[65536:]==expected and c.X==result and c.DB==original_db,('initialize workspace',trial)
        cases['initialize_workspace'] += 1
    for trial in range(32):
        bank = bytearray(rng.randbytes(65536))
        expected = bank[:]
        clear_lookup(expected)
        c = cpu.CPU()
        c.wram[:65536],c.wram[65536:] = image,bank
        c.DB = (0,0x7E,0x7F)[trial%3]
        boot_tasks.call(c,0x8607)
        assert c.wram[65536:]==expected,('clear lookup',trial)
        cases['clear_lookup'] += 1
    for trial in range(24):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x18,0x4000)
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
        expected = bank[:]
        result = initialize_lookup(expected,image)
        c = cpu.CPU()
        c.wram[:65536],c.wram[65536:] = image,bank
        c.DB = 0x7F
        boot_tasks.call(c,0x8621,step_limit=5_000_000)
        assert c.wram[65536:]==expected and c.A==result,('initialize lookup',trial,c.A,result)
        cases['initialize_lookup'] += 1
    baseline_cpu,_ = boot_tasks.initialized(rom)
    baseline = baseline_cpu.wram[:]
    for trial in range(96):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = rng.randbytes(928)
        if trial%3==0: bank[word(bank,0x64)+15] = 0x81
        expected = memory[:]
        queue_sample_palette(memoryview(expected)[65536:],image)
        c = cpu.CPU()
        c.wram[:] = memory
        c.DB = 0x7F
        boot_tasks.call(c,0x8686)
        assert c.wram[65536:]==expected[65536:],('queue sample palette',trial)
        cases['queue_sample_palette'] += 1
    return {'cases':cases,'real_asset':real_asset,'verified':True,'comparison':'entire bank 7F; decoded low A, signed-delta A and packed/quantized X',
            'scope':'240 cache hit/miss lookups, 160 repeated lookups, 320 unfilled workspace initializations; 32 full upper-bank clears, 24 configuration lookup initializations, 96 sample palette producers and 160 nearest fallbacks; 8 real ROM tree/stream component runs, 96 constructed depth-1-to-8 tree/decoder sequences and 960 tree lifecycle/initialization cases; 48 full sign-reflection and 48 cyclic-permutation cases; 160 translated-candidate and 160 earlier-triplet deduplication cases; generated valid full depth-3 word-pointer tree; symbols 00/01/3F/40/7F/80/81/FF; RAM/ROM bit sources and varied refill/cache state; 96 ramps and three-channel runs; remaining tree/stream producers remain open'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
