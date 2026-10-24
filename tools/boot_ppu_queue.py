"""Recovered persistent/one-shot PPU register queues in the boot IRQ.
usage: boot_ppu_queue.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def nodes(mem,head):
    base = word(mem,0x2D6)
    offset = mem[head+1]
    while offset:
        node = base+offset
        yield node
        offset = mem[node+1]

def allocate_entry(mem,classes,register):
    """$C030: pop a PPU record and seed its value from the selected shadow word."""
    node = word(mem,0x2D8)
    if not node: return 0
    put_word(mem,0x2D8,word(mem,node))
    register &= 255
    put_word(mem,node,register)
    kind = classes[register]
    offset = kind if kind>1 else register
    put_word(mem,node+2,word(mem,word(mem,0x2E2)+offset))
    return node


def append_entry(mem,node):
    """$C097: append a nonzero record to the one-shot byte-offset queue."""
    if not node: return
    mem[word(mem,0x2E0)+1] = (node-word(mem,0x2D6))&255
    mem[node+1] = 0
    put_word(mem,0x2E0,node)


def count_entries(mem):
    """$7E:C0C2: count both lists, excluding their sentinel headers."""
    return sum(1 for head in (0x2DA,0x2DE) for _ in nodes(mem,head))

def register_writes(mem,classes):
    """$7E:C0FD: ordered low/high PPU writes, without consuming either queue."""
    writes = []
    for head in (0x2DA,0x2DE):
        for node in nodes(mem,head):
            register,value = mem[node],word(mem,node+2)
            writes.append((0x2100+register,value&255))
            kind = classes[register]
            if kind: writes.append((0x2100+register+(kind==1),value>>8))
    return writes

def apply_shadow(mem,classes):
    """$7E:C18B: update mirror values, then reclaim the one-shot list."""
    mirror = word(mem,0x2E2)
    for head in (0x2DA,0x2DE):
        previous = head
        for node in list(nodes(mem,head)):
            if head==0x2DE and previous!=head:
                put_word(mem,previous,word(mem,0x2D8))
                put_word(mem,0x2D8,previous)
            register,value = mem[node],word(mem,node+2)
            mem[mirror+register] = value&255
            kind = classes[register]
            if kind==1: mem[mirror+register+1] = value>>8
            elif kind:
                mem[mirror+kind],mem[mirror+kind+1] = value&255,value>>8
            previous = node
        if head==0x2DE and previous!=head:
            put_word(mem,previous,word(mem,0x2D8))
            put_word(mem,0x2D8,previous)
    put_word(mem,0x2DE,0)
    put_word(mem,0x2E0,0x2DE)

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    boot_decode.decode(rom,0xC7B480,0x7E5000,image)
    classes = image[0x603E:0x6072]
    rng = random.Random(0xC18B)
    cases = dict(count_entries=0,register_writes=0,apply_shadow=0)
    class PpuWrites(cpu.CPU):
        def __init__(self):
            super().__init__()
            self.ppu_writes = []
        def wr8(self,address,value):
            if 0x2100<=address<=0x2134: self.ppu_writes.append((address,value&255))
            super().wr8(address,value)
    for trial in range(240):
        memory = bytearray(rng.randbytes(0x10000))
        put_word(memory,0x2D6,0x3000)
        put_word(memory,0x2D8,0x30FC)
        put_word(memory,0x2E2,0x5000)
        counts = (trial%21,(trial*7)%21)
        offset = 4
        for head,count in zip((0x2DA,0x2DE),counts):
            memory[head+1] = offset if count else 0
            for i in range(count):
                node = 0x3000+offset
                memory[node] = (trial+i)%len(classes)
                memory[node+1] = offset+4 if i+1<count else 0
                put_word(memory,node+2,rng.randrange(65536))
                offset += 4
        for name,address in (('count_entries',0xC0C2),('register_writes',0xC0FD),('apply_shadow',0xC18B)):
            expected = memory[:]
            if name=='count_entries': result = count_entries(expected)
            elif name=='register_writes': result = register_writes(expected,classes)
            else: apply_shadow(expected,classes)
            c = PpuWrites()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = memory
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address)
            assert c.wram[0x10000:]==expected,(name,trial)
            if name=='count_entries': assert c.A==result,('count',trial,c.A,result)
            if name=='register_writes': assert c.ppu_writes==result,('writes',trial,c.ppu_writes,result)
            else: assert not c.ppu_writes
            cases[name] += 1
    cases['allocate_entry'] = cases['append_entry'] = 0
    for trial in range(240):
        memory = bytearray(rng.randbytes(65536))
        put_word(memory,0x2D6,0x3000)
        put_word(memory,0x2D8,0 if trial%5==0 else 0x3004)
        put_word(memory,0x3004,0x3008)
        put_word(memory,0x2E2,0x5000)
        put_word(memory,0x2E0,0x2DE if trial%2 else 0x300C)
        register = trial%52
        for name,address in (('allocate_entry',0xC030),('append_entry',0xC097)):
            expected = memory[:]
            node = 0 if trial%5==0 else 0x3004
            if name=='allocate_entry': result = allocate_entry(expected,classes,register)
            else: append_entry(expected,node)
            c = PpuWrites()
            c.wram[:65536] = image
            c.wram[65536:] = memory
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address,A=register,X=node)
            assert c.wram[65536:]==expected and not c.ppu_writes,(name,trial)
            if name=='allocate_entry': assert c.X==result,(name,trial,c.X,result)
            cases[name] += 1
    return {'cases':cases,'verified':True,'comparison':'entire bank 7F; count A and ordered PPU-register writes',
            'configuration_source':'C7B480 -> 7E5000','register_classes':sorted(set(classes)), 'scope':'valid acyclic byte-offset queues, pool 3000 and separate shadow 5000, register offsets 00-33; captured writes, not rendered PPU output'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
