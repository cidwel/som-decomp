"""Readable model of the boot IRQ's one-task completion cleanup.
usage: boot_cleanup.py ROM [--json OUT.json]
Runs the original body and all callees; compares bank 7F mutations with the composed model.
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_pool,boot_heap,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def reap_one(mem):
    bank = memoryview(mem)[0x10000:]
    node = word(bank,0xA4)
    if not node: return
    put_word(bank,0xA4,word(bank,node))
    owner = bank[node+4]
    boot_pool.clear_page_owner(bank,owner)
    boot_pool.clear_registration_owner(bank,owner)
    boot_pool.release_chain(bank,word(bank,node+0xA))
    boot_pool.release_records_owner(bank,owner)
    workspace = word(bank,node+8)
    if workspace: boot_heap.free_units(bank,workspace)
    put_word(bank,node+2,0)
    put_word(bank,node+4,0)
    boot_tasks.free_task_frame(mem,node)

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xA9C7)
    for trial in range(160):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        bank = memoryview(c.wram)[0x10000:]
        bank[0xC4:0x2C4] = bytes(512)
        bank[0xC4],bank[0x1C4] = 1,1
        put_word(bank,0xC2,128)
        put_word(bank,0x2C4,0x2000)
        put_word(bank,0x2C6,0x27F8)
        put_word(bank,0x302,0x4000)
        put_word(bank,0x9E,0)
        node = 0x600+(trial%20)*16
        owner = 2+trial%20
        put_word(bank,0xA4,0 if trial%5==0 else node)
        put_word(bank,0xA6,0x600+((trial+4)%20)*16)
        successor = 0 if trial%3==0 else 0x600+((trial+1)%20)*16
        put_word(bank,node,successor)
        bank[node+2],bank[node+4],bank[node+5] = 16,owner,1
        put_word(bank,node+6,(owner<<8)+rng.randrange(256))
        workspace = 0 if trial%4==0 else 0x3000
        put_word(bank,node+8,workspace)
        for n in range(3):
            bank[0xC4+0x60+n] = 3-n
            bank[0x1C4+0x60+n] = owner if trial%2 else 1
        for n in range(256):
            put_word(bank,0x2000+8*n,owner if n%7==0 else 1)
        put_word(bank,0x27F8,0)
        chain = [0x2000+8*n for n in range(trial%7)]
        for n,at in enumerate(chain):
            put_word(bank,at,chain[n+1] if n+1<len(chain) else (0xFFFF if trial%2 else 0))
        put_word(bank,node+0xA,chain[0] if chain else 0)
        for n in range(32): bank[0x4001+4*n] = owner if n%3==0 else 1
        expected = c.wram[:]
        reap_one(expected)
        boot_tasks.call(c,0xA9C7)
        assert c.wram[0x10000:]==expected[0x10000:],trial
    return {'entry':'7EA9C7','cases':160,'verified':True,
            'comparison':'entire bank 7F; original cleanup callees execute without hooks',
            'scope':'one completion per call, empty/nonempty lists, owned resources and workspace variants'}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
