"""Readable models of the recovered boot's eight-byte record pool and linked-list operations.
usage: boot_pool.py ROM [--json OUT.json]
The records' payload meaning is still unresolved; this models exact pool/list mutations.
"""
import sys, json, random, romio, boot_decode, boot_tasks, cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def task_id(mem):
    current = word(mem,0x9E)
    return mem[current+4] if current else 1

def allocate(mem):
    """$7E:B1A9: take the free head; the original has no empty-list guard."""
    node = word(mem,0x2C6)
    put_word(mem,0x2C6,word(mem,node))
    put_word(mem,node,0)
    mem[node+2:node+5] = bytes((task_id(mem),0,0))
    return node

def release(mem,node):
    """$7E:B1DD: return a record, ignoring 0 and FFFF."""
    if node in (0,0xFFFF): return
    put_word(mem,node,word(mem,0x2C6))
    mem[node+2] = 0
    put_word(mem,0x2C6,node)

def take_link(mem,node):
    """$7E:B20B: return the old link and replace it with the current task id."""
    if node in (0,0xFFFF): return 0
    link = word(mem,node)
    put_word(mem,node,task_id(mem))
    return link

def release_chain(mem,node):
    """$7E:B23A: consume old links and release every node until a sentinel."""
    while node not in (0,0xFFFF):
        successor = take_link(mem,node)
        release(mem,node)
        node = successor

def clear_page_owner(mem,owner):
    """$7E:B0E8: clear matching owner/usage bytes and lower the search hint."""
    lowest = 256
    for index in range(255,-1,-1):
        if mem[0x1C4+index] != owner: continue
        mem[0xC4+index] = mem[0x1C4+index] = 0
        lowest = index
    if lowest < mem[0xC2]: mem[0xC2] = lowest

def release_records_owner(mem,owner):
    """$7E:B16F: scan 256 eight-byte records and release matching link/owner words."""
    base = word(mem,0x2C4)
    for node in range(base,base+256*8,8):
        if word(mem,node)==owner: release(mem,node)

def clear_registration_owner(mem,owner):
    """$7E:CBDC: clear byte 0 of each of 32 four-byte records with matching byte 1."""
    base = word(mem,0x302)
    for node in range(base,base+32*4,4):
        if mem[node+1]==owner: mem[node] = 0

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xB1A9)
    cases = dict(allocate=0,release=0,take_link=0,release_chain=0)
    for trial in range(240):
        memory = bytearray(rng.randbytes(0x10000))
        current = 0 if trial%3==0 else 0x600+(trial%20)*16
        put_word(memory,0x9E,current)
        if current: memory[current+4] = trial%256
        node = (0,0xFFFF,0x1200)[trial%3]
        put_word(memory,0x2C6,0x1200)
        put_word(memory,0x1200,0x1208)
        for name,address in (('allocate',0xB1A9),('release',0xB1DD),('take_link',0xB20B),('release_chain',0xB23A)):
            original = memory[:]
            if name=='allocate' and trial%5==0:
                put_word(original,0x2C6,0)
            if name=='release_chain':
                count = trial%21
                nodes = [0x1200+8*i for i in range(count)]
                node = nodes[0] if nodes else (0 if trial%2 else 0xFFFF)
                for i,at in enumerate(nodes):
                    put_word(original,at,nodes[i+1] if i+1<count else (0 if trial%2 else 0xFFFF))
                put_word(original,0x2C6,0x1600)
            expected = original[:]
            if name=='allocate': result = allocate(expected)
            elif name=='release': release(expected,node)
            elif name=='take_link': result = take_link(expected,node)
            else: release_chain(expected,node)
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = original
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address,A=rng.randrange(0x10000),X=node)
            assert c.wram[0x10000:]==expected, (name,trial)
            if name=='allocate': assert c.X==result
            if name=='take_link': assert c.A&0xFFFF==result
            if name=='release_chain': assert c.X==0
            cases[name] += 1
    cleanup_cases = dict(clear_page_owner=0,release_records_owner=0,clear_registration_owner=0)
    cleanup = (('clear_page_owner',0xB0E8,clear_page_owner),
               ('release_records_owner',0xB16F,release_records_owner),
               ('clear_registration_owner',0xCBDC,clear_registration_owner))
    for trial in range(160):
        memory = bytearray(rng.randbytes(0x10000))
        owner = trial%256
        put_word(memory,0x2C4,0x2000)
        put_word(memory,0x2C6,0x5000)
        put_word(memory,0x302,0x4000)
        memory[0xC2] = (0,255,128,rng.randrange(256))[trial%4]
        for index in range(256):
            matching = trial%5==0 or (trial%5==2 and rng.randrange(2)) or (trial%5==3 and index in (0,255))
            value = owner if matching else (owner+1)&0xFF
            memory[0x1C4+index] = value
            put_word(memory,0x2000+8*index,value+(0x100 if trial%5==4 else 0))
            if index<32: memory[0x4001+4*index] = value
        for name,address,model in cleanup:
            expected = memory[:]
            model(expected,owner)
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = memory
            c.DB = rng.randrange(256)
            boot_tasks.call(c,address,A=owner|rng.randrange(256)<<8,X=0x740)
            assert c.wram[0x10000:]==expected, (name,trial)
            cleanup_cases[name] += 1
    return {'cases':cases,'cleanup_cases':cleanup_cases,
            'verified':True,'comparison':'entire bank 7F after original routines return',
            'pool_head':'7F02C6','pool_record_size':8,'payload_meaning_resolved':False}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
