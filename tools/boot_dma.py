"""Recovered channel-0 transfer scheduling and register programming in the boot IRQ.
usage: boot_dma.py ROM [--json OUT.json]
The DMA harness supplies completion/residual counts for ordinary incrementing transfers; this verifies programming, not timing.
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_heap,boot_create,boot_wait,boot_pool,boot_receive,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def reserve_hdma(mem,node):
    """$8F8F: take the highest free channel, or clear the descriptor's flag."""
    for channel in range(7,-1,-1):
        if mem[0x72+channel]: continue
        task = word(mem,0x9E)
        mem[0x72+channel] = mem[task+4] if task else 1
        mem[node+9] = 1<<channel
        return node
    mem[node+15] = 0
    return 0


def allocate_descriptor(mem,image,argument):
    """$8FC7: immediate allocation/failure; a blocking exhaustion returns None."""
    base = word(mem,0x64)
    for index in range(32):
        node = base+16*index
        if mem[node+15]: continue
        flag,reference = argument&255,argument>>8
        mem[node+15],mem[node+13] = flag,reference
        if 1<=reference<=32:
            slot = word(mem,0x68)+reference-1
            mem[slot] = (mem[slot]+1)&255
        kind = ((flag&7)-1)&255
        for field,table in ((0,0x5EB4),(9,0x5EB9),(1,0x5EBE)):
            mem[node+field] = image[table+kind]
        return reserve_hdma(mem,node) if flag==5 else node
    return 0 if argument>>8==255 else None


def submit(mem,node):
    """$90DA: queue non-05 records or program the HDMA channel selected by a 05 mask."""
    if not node: return []
    if mem[node+15]!=5:
        mem[node+15] |= 128
        count = word(mem,0x6C)
        put_word(mem,word(mem,0x66)+2*count,node)
        mem[0x6C] = (mem[0x6C]+1)&255
        return []
    mask = mem[node+9]
    channel = mask.bit_length()-1 if mask else 255
    base = 0x4300+channel*16
    writes = []
    for register,field in ((0,0),(1,1),(4,4),(2,2)):
        value = word(mem,node+field)
        writes.extend(((base+register,value&255),(base+register+1,value>>8)))
    mem[0x70] |= mask
    if mask==1: put_word(mem,0x7A,node)
    return writes


def program(mem,argument,vertical,blank,residual):
    """$91B8: transfer descriptors within the computed scanline/size budget."""
    count = word(mem,0x6E)
    writes = []
    def byte(address,value): writes.append((address,value&255))
    def wide(address,value): byte(address,value);byte(address+1,value>>8)
    if not count: return writes
    byte(0x420C,0)
    limit = (0x106-argument)&65535
    vector = word(mem,0x66)
    for index in range(count):
        node = word(mem,vector+2*index)
        size = word(mem,node+5)
        work = (((next(vertical)&511)<<7)+size)&65535
        if work>>7>=limit:
            wide(0x4305,0)
            put_word(mem,0x6E,index)
            break
        byte(0x420B,0)
        for field in range(7): byte(0x4300+field,mem[node+field])
        byte(0x2115,mem[node+9])
        kind = mem[node+15]&7
        if kind==1: wide(0x2116,word(mem,node+10))
        elif kind==2: byte(0x2121,mem[node+10])
        elif kind==3:
            for field in range(3): byte(0x2181+field,mem[node+10+field])
        else: wide(0x2102,word(mem,node+10))
        byte(0x420B,1)
        left = next(residual)
        if not next(blank)&128 or left:
            wide(0x4305,0)
            put_word(mem,0x6E,index)
            break
    else:
        if not next(blank)&128 and not mem[0x10]:
            mem[0x6E] = (mem[0x6E]-1)&255
            byte(0x420B,0)
    writes.extend(submit(mem,word(mem,0x7A)))
    byte(0x420C,mem[0x70])
    return writes

def find_vram_buffer(mem,source):
    """$C73B: find the first of four records whose source word +2 matches X."""
    base = word(mem,0x2F4)
    for index in range(4):
        node = base+8*index
        if word(mem,node+2)==source: return node
    return 0


def queue_vram_buffer(mem,image,source):
    """$C870: queue a registered buffer using its page/count bytes, even if absent."""
    record = find_vram_buffer(mem,source)
    destination = (mem[record]<<10)&65535
    size = mem[record+1]<<8
    node = allocate_descriptor(mem,image,1)
    if node is None: return None
    put_word(mem,node+10,destination)
    put_word(mem,node+2,source)
    put_word(mem,node+5,size)
    mem[node+4] = 0x7F
    return submit(mem,node)


def queue_oam(mem,image):
    """$B804: queue the 544-byte OAM shadow when its source pointer is nonzero."""
    source = word(mem,0x2CC)
    if not source: return []
    node = allocate_descriptor(mem,image,0xFF04)
    if not node: return []
    mem[node+4] = 0x7F
    put_word(mem,node+2,source)
    put_word(mem,node+5,0x220)
    put_word(mem,node+10,0)
    return submit(mem,node)


def stage(mem):
    """$9193: copy only the low pending-count byte into the pass count."""
    mem[0x6E] = mem[0x6C]


def prepare(mem,vertical,blank,residual):
    """$9164: defer the count or immediately program and reclaim pending transfers."""
    if not word(mem,0x64) or not mem[0x6C]: return []
    if not mem[0x10]:
        stage(mem)
        return []
    put_word(mem,0x6E,word(mem,0x6C))
    writes = program(mem,0x107,vertical,blank,residual)
    cleanup(mem)
    return writes


def release_descriptor(mem,node):
    """$9066: release its reference byte and exact HDMA-kind-5 ownership, then mark free."""
    if not node: return
    reference = mem[node+13]
    if 1<=reference<=32:
        slot = word(mem,0x68)+reference-1
        count = (mem[slot]-1)&255
        mem[slot] = count if count>1 else 0
    if mem[node+15]==5:
        mask = mem[node+9]
        mem[0x70] &= mask^255
        channel = (mask.bit_length()-1)&7
        mem[0x72+channel] = 0
        if mask==1: put_word(mem,0x7A,0)
    mem[node+15] = 0

def cleanup(mem):
    """$92E9: release processed descriptors/workspaces, compact the pointer vector."""
    processed = word(mem,0x6E)
    if not processed: return
    vector = word(mem,0x66)
    for index in range(processed):
        node = word(mem,vector+2*index)
        if mem[node+15]&8: boot_heap.free_units(mem,word(mem,node+2))
        release_descriptor(mem,node)
    remaining = (word(mem,0x6C)-processed)&65535
    source = vector+((processed*2)&255)
    mem[vector:vector+2*remaining] = mem[source:source+2*remaining]
    put_word(mem,0x6C,remaining)
    put_word(mem,0x6E,0)


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    rng = random.Random(0x91B8)
    class DmaCpu(cpu.CPU):
        def __init__(self):
            super().__init__()
            self.writes = []
            self.registers = {}
        def rd8(self,address):
            if address==0x2137:
                self.counter = next(self.vertical)
                self.high = False
                return 0
            if address==0x213D:
                value = self.counter>>8 if self.high else self.counter&255
                self.high = not self.high
                return value
            if address==0x4212: return next(self.blank)
            if 0x4300<=address<=0x4306: return self.registers.get(address,0)
            return super().rd8(address)
        def wr8(self,address,value):
            if address in (0x420B,0x420C) or 0x4300<=address<=0x437F or 0x2100<=address<=0x2133 or 0x2180<=address<=0x2183:
                self.writes.append((address,value&255))
                self.registers[address] = value&255
                if address==0x420B and value&1:
                    count = (self.registers.get(0x4305,0)|self.registers.get(0x4306,0)<<8) or 65536
                    left = next(self.residual)
                    source = (self.registers.get(0x4302,0)|self.registers.get(0x4303,0)<<8)+count-left
                    self.registers[0x4302],self.registers[0x4303] = source&255,source>>8&255
                    self.registers[0x4305],self.registers[0x4306] = left&255,left>>8
            super().wr8(address,value)
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        count = trial%9
        put_word(bank,0x6E,count)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x7A,0 if trial%3==0 else 0x2800)
        put_word(bank,0x6C,trial%20)
        bank[0x280F] = (0,5,5)[trial%3]
        bank[0x2809] = (1,2,128,255)[trial%4]
        bank[0x10] = trial%2
        for index in range(count):
            node = 0x2000+16*index
            put_word(bank,0x1000+2*index,node)
            bank[node],bank[node+1] = rng.randrange(8),rng.randrange(0x34)
            put_word(bank,node+2,0x6000+index*128)
            bank[node+4] = 0x7E
            put_word(bank,node+5,(8,64,127,128,256)[(trial+index)%5])
            bank[node+15] = (trial+index)%8
        argument = (0,0x106,0x107,rng.randrange(256))[trial%4]
        vertical = [rng.randrange(512) for _ in range(count)]
        blank = [128 if (trial+i)%3 else 0 for i in range(count+1)]
        residual = [1 if (trial+i)%7==0 else 0 for i in range(count)]
        expected = bank[:]
        writes = program(expected,argument,iter(vertical),iter(blank),iter(residual))
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.vertical,c.blank,c.residual = iter(vertical),iter(blank),iter(residual)
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x91B8,A=argument)
        assert c.wram[65536:]==expected and c.writes==writes,('DMA program',trial,c.writes,writes)
    reserve_cases = allocate_cases = 0
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        occupancy = 255 if trial==0 else trial&255
        bank[0x72:0x7A] = bytes(1 if occupancy&(1<<i) else 0 for i in range(8))
        put_word(bank,0x9E,0 if trial%3==0 else 0x1800)
        bank[0x1804] = (0,1,2,21,255)[trial%5]
        expected = bank[:]
        result = reserve_hdma(expected,0x2000)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0x8F8F,X=0x2000)
        assert c.wram[65536:]==expected and c.X==result,('reserve HDMA',trial)
        reserve_cases += 1
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x64,0x2000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x9E,0 if trial%3==0 else 0x1800)
        bank[0x1804] = (0,1,2,21,255)[trial%5]
        occupancy = 255 if trial%17==0 else trial&255
        bank[0x72:0x7A] = bytes(1 if occupancy&(1<<i) else 0 for i in range(8))
        for index in range(32): bank[0x200F+16*index] = 1
        hole = trial%33
        if hole<32:
            bank[0x200F+16*hole] = 0
            if hole<31: bank[0x200F+16*(hole+1)] = 0
        reference = 255 if hole==32 else (0,1,2,32,33,255)[(trial//8)%6]
        flag = (0,1,2,3,4,5,6,7,8,13,255)[trial%11]
        argument = reference<<8|flag
        if 1<=reference<=32: bank[0x3000+reference-1] = (0,1,2,255)[trial%4]
        expected = bank[:]
        result = allocate_descriptor(expected,image,argument)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x8FC7,A=argument,X=rng.randrange(65536))
        assert c.wram[65536:]==expected and c.X==result,('allocate descriptor',trial,c.X,result)
        allocate_cases += 1
    retry_cases = 0
    initial,_ = boot_tasks.initialized(rom)
    class RetryCpu(DmaCpu):
        def rd8(self,address):
            if address in (0x2137,0x213D): return 0
            return super().rd8(address)
    for trial in range(96):
        memory = initial.wram[:]
        bank = memoryview(memory)[65536:]
        node,registration = 0x700,0xF84
        descriptor = 0x2000+16*(trial%32)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x1800)
        put_word(bank,0x6C,1)
        put_word(bank,0x7A,0)
        put_word(bank,0x1000,descriptor)
        bank[0x10] = 1
        for index in range(32): bank[0x200F+16*index] = 1
        bank[descriptor],bank[descriptor+1] = trial%8,0x18
        put_word(bank,descriptor+2,0x5000)
        bank[descriptor+4] = 0x7F
        put_word(bank,descriptor+5,64)
        bank[descriptor+13] = 0
        put_word(bank,0x9E,node)
        put_word(bank,0x9A,1)
        put_word(bank,0xA0,0)
        put_word(bank,0xA2,0)
        put_word(bank,node,0)
        put_word(bank,node+10,0)
        put_word(bank,node+12,registration)
        bank[node+2],bank[node+3],bank[node+4],bank[node+5] = 1,128,3,1
        bank[0xAB] = 1
        bank[registration],bank[registration+1] = 1,3
        put_word(bank,registration+2,0)
        argument = (0,1,32,33)[trial%4]<<8 | (1,2,3,4,5,13)[trial%6]
        expected = memory[:]
        e = memoryview(expected)[65536:]
        writes = prepare(e,iter([0]),iter([128,128]),iter([0]))
        boot_receive.prepare_receive(e,node,1)
        put_word(e,node+6,0x03C8)
        e[node+2] = 4
        put_word(e,0xA2,node)
        idle = boot_create.select_next(expected)
        boot_tasks.dispatch_frame(expected,idle)
        boot_wait.tick_registrations(e,iter([0]*32))
        if not word(e,idle+10): put_word(e,idle+10,0xFFFF)
        put_word(e,idle+6,0x02EB)
        e[idle+2] = 2
        boot_tasks.enqueue(e,idle)
        chosen = word(e,0xA0)
        assert chosen==node
        put_word(e,0xA0,word(e,chosen))
        put_word(e,chosen,0)
        put_word(e,0x9E,chosen)
        e[chosen+2] = 1
        consumed = word(e,chosen+10)
        put_word(e,chosen+10,boot_pool.take_link(e,consumed))
        boot_receive.finish_receive(e,chosen,consumed,1)
        result = allocate_descriptor(e,expected,argument)
        c = RetryCpu()
        c.wram[:] = memory
        c.blank,c.residual = iter([128,128]),iter([0])
        c.S,c.PB,c.PC,c.M,c.XF,c.DB,c.D,c.A = 0x03E0,0x7E,0x8FC7,1,0,0x7F,0x0300,argument
        c.push16(0xFFFD)
        serviced,ticks = False,0
        for _ in range(20000):
            address = c.PB<<16|c.PC
            if address==0x7EFFFE: break
            if address==0x7EA8C0 and not serviced:
                serviced = True
                ticks += 1
                c.push16(0xA8BF)
                c.PC = 0xCCB7
            elif address==0x7EA8C3: serviced = False
            c.step()
        else: raise RuntimeError('descriptor retry timeout')
        assert ticks==1 and c.X==result and c.S==0x03E0,('retry return',trial,ticks,c.X,result,c.S)
        assert c.wram[65536:]==e and c.writes==writes,('retry memory/writes',trial)
        retry_cases += 1
    oam_cases = oam_pass_cases = 0
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x6C,(0,1,255,256)[trial%4])
        put_word(bank,0x2CC,0 if trial%5==0 else 0x5000)
        for index in range(32): bank[0x200F+16*index] = 1
        hole = trial%33
        if hole<32: bank[0x200F+16*hole] = 0
        expected = bank[:]
        writes = queue_oam(expected,image)
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xB804)
        assert c.wram[65536:]==expected and c.writes==writes,('queue OAM',trial)
        oam_cases += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x6C,0)
        put_word(bank,0x6E,0)
        put_word(bank,0x7A,0)
        put_word(bank,0x2CC,0 if trial%5==0 else 0x5000)
        bank[0x10] = 1
        for index in range(32): bank[0x200F+16*index] = 1
        hole = trial%33
        if hole<32: bank[0x200F+16*hole] = 0
        expected = bank[:]
        writes = queue_oam(expected,image)
        writes.extend(prepare(expected,iter([0]),iter([128,128]),iter([0])))
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        c.vertical,c.blank,c.residual = iter([0]),iter([128,128]),iter([0])
        boot_tasks.call(c,0xB804)
        boot_tasks.call(c,0x9164)
        assert c.wram[65536:]==expected and c.writes==writes,('OAM pass',trial)
        oam_pass_cases += 1
    vram_lookup_cases = vram_cases = 0
    for trial in range(320):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x2F4,0x1800)
        put_word(bank,0x64,0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,(0,1,255,256)[trial%4])
        for index in range(4):
            put_word(bank,0x1802+8*index,0x5000+index*0x100)
            bank[0x1800+8*index],bank[0x1801+8*index] = rng.randrange(256),rng.randrange(256)
        source = 0x5000+(trial%5)*0x100
        if trial%7==0: put_word(bank,0x181A,source)
        for index in range(32): bank[0x200F+16*index] = 1
        bank[0x200F+16*(trial%32)] = 0
        result = find_vram_buffer(bank,source)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0xC73B,X=source)
        assert c.wram[65536:]==bank and c.X==result,('VRAM lookup',trial)
        vram_lookup_cases += 1
        expected = bank[:]
        writes = queue_vram_buffer(expected,image,source)
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0xC870,X=source)
        assert c.wram[65536:]==expected and c.writes==writes,('queue VRAM buffer',trial)
        vram_cases += 1
    submit_cases = 0
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x66,0x1000)
        put_word(bank,0x6C,(0,1,255,256,511,1023)[trial%6])
        node = 0 if trial%7==0 else 0x3000
        bank[0x300F] = (0,1,5,8,13,255)[(trial//6)%6]
        bank[0x3009] = (1,2,4,128,3,255)[trial%6]
        expected = bank[:]
        writes = submit(expected,node)
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x90DA,X=node)
        assert c.wram[65536:]==expected and c.writes==writes,('submit',trial)
        submit_cases += 1
    stage_cases = prepare_cases = 0
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        expected = bank[:]
        stage(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = 0x7F
        boot_tasks.call(c,0x9193)
        assert c.wram[65536:]==expected,('stage',trial)
        stage_cases += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        total = trial%9
        put_word(bank,0x64,0 if trial%5==0 else 0x2000)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x6C,total)
        put_word(bank,0x7A,0)
        bank[0x10] = trial%2
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        for index in range(total):
            node = 0x2000+16*index
            put_word(bank,0x1000+2*index,node)
            bank[node],bank[node+1] = index%8,0x18
            put_word(bank,node+2,0x5000+index*128)
            bank[node+4] = 0x7F
            put_word(bank,node+5,64)
            bank[node+13],bank[node+15] = 0,1
        vertical = [rng.randrange(512) for _ in range(total)]
        blank,residual = [128]*(total+1),[0]*total
        expected = bank[:]
        writes = prepare(expected,iter(vertical),iter(blank),iter(residual))
        c = DmaCpu()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.vertical,c.blank,c.residual = iter(vertical),iter(blank),iter(residual)
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x9164)
        assert c.wram[65536:]==expected and c.writes==writes,('prepare',trial,c.writes,writes)
        prepare_cases += 1
    cleanup_cases = release_cases = 0
    for trial in range(240):
        bank = bytearray(rng.randbytes(65536))
        put_word(bank,0x68,0x3000)
        node = 0 if trial%8==0 else 0x2000
        if node:
            bank[node+13] = (0,1,2,32,33,255)[trial%6]
            bank[node+15] = (0,1,5,8,13,255)[(trial//6)%6]
            bank[node+9] = (0,1,2,4,128,rng.randrange(256))[trial%6]
            if 1<=bank[node+13]<=32: bank[0x3000+bank[node+13]-1] = (0,1,2,3,255)[trial%5]
        expected = bank[:]
        release_descriptor(expected,node)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x9066,X=node)
        assert c.wram[65536:]==expected,('descriptor release',trial)
        release_cases += 1
    for trial in range(160):
        bank = bytearray(rng.randbytes(65536))
        total = trial%21
        processed = trial%(total+1)
        put_word(bank,0x66,0x1000)
        put_word(bank,0x68,0x3000)
        put_word(bank,0x6C,total)
        put_word(bank,0x6E,processed)
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,255)
        for index in range(total):
            node = 0x2000+16*index
            put_word(bank,0x1000+2*index,node)
            bank[node+13] = 1+index%32
            bank[node+15] = (0,5,8,13)[(trial+index)%4]
            bank[node+9] = 1<<(index%8)
            workspace = 0x5000+index*128
            put_word(bank,node+2,workspace)
            unit = workspace>>7
            bank[0xC4+unit],bank[0x1C4+unit] = 1,2
        expected = bank[:]
        cleanup(expected)
        c = cpu.CPU()
        c.wram[:65536] = image
        c.wram[65536:] = bank
        c.DB = rng.randrange(256)
        boot_tasks.call(c,0x92E9)
        assert c.wram[65536:]==expected,('cleanup',trial)
        cleanup_cases += 1
    return {'cases':320,'reserve_cases':reserve_cases,'allocate_cases':allocate_cases,'retry_cases':retry_cases,'oam_cases':oam_cases,'oam_pass_cases':oam_pass_cases,'vram_lookup_cases':vram_lookup_cases,'vram_cases':vram_cases,'submit_cases':submit_cases,'stage_cases':stage_cases,'prepare_cases':prepare_cases,'release_cases':release_cases,'cleanup_cases':cleanup_cases,'verified':True,'comparison':'entire bank 7F and ordered DMA/PPU/HDMA-enable register writes',
            'configuration_source':'C7B480 -> 7E5000', 'scope':'immediate descriptor allocation and 96 exhaustion/retry cases through real fallback/timer service; valid pool base, 32 descriptors; descriptor count 0-8, channel 0 incrementing modes 0-7, controlled vertical/blank reads; HDMA callback null/05 descriptor; nonzero masks; specified complete/partial DMA results; not timing or destination rendering'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
