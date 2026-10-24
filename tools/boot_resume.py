"""Recovered suspended-task dispatcher branch and native stack restoration.
usage: boot_resume.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_pool,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def resume(mem,node):
    """$7E:A961, status other than 08/10: take pending link and restore saved frame."""
    bank = memoryview(mem)[0x10000:]
    assert bank[node+2] not in (8,16)
    put_word(bank,0xA0,word(bank,node))
    put_word(bank,node,0)
    put_word(bank,0x9E,node)
    stack = word(bank,node+6)
    bank[node+2] = 1
    record = word(bank,node+10)
    link = boot_pool.take_link(bank,record)
    put_word(bank,node+10,link)
    x = 0 if record==0xFFFF else record
    y = node
    for flags in (mem[stack+1],mem[stack+3]):
        if flags&0x10: x,y = x&255,y&255
    direct = word(mem,stack+4)
    flags = (mem[stack+3]&0x7D)|(0x80 if direct&0x8000 else 0)|(2 if direct==0 else 0)
    return dict(A=link,X=x,Y=y,DB=mem[stack+2],D=direct,P=flags,
                target=0x7E0000|((word(mem,stack+6)+1)&0xFFFF),S=stack+7)

def suspend(mem,node,stack,flags,data_bank,direct):
    """$7E:A911 up to A948: save native frame, then queue ready or waiting task."""
    bank = memoryview(mem)[0x10000:]
    saved = stack-5
    mem[saved+1] = flags&0x4D
    mem[saved+2] = data_bank
    mem[saved+3] = flags
    put_word(mem,saved+4,direct)
    put_word(bank,node+6,saved)
    if word(bank,node+10):
        bank[node+2] = 2
        boot_tasks.enqueue(bank,node)
    else:
        bank[node+2] = 4
        put_word(bank,node,word(bank,0xA2))
        put_word(bank,0xA2,node)
    return saved


def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xA97E)
    for trial in range(320):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        node = 0x600+(trial%20)*16
        bank = memoryview(c.wram)[0x10000:]
        bank[node+2] = (0,1,2,4,0x20,0x80,0xFF)[trial%7]
        bank[node+4] = 2+trial%20
        stack = ((2+trial%20)<<8)+0x80
        c.wram[stack-32:stack+8] = rng.randbytes(40)
        # Exercise both saved index widths, interrupt masks and direct-page N/Z.
        c.wram[stack+1] = trial&255
        c.wram[stack+3] = (trial*73)&255
        put_word(c.wram,stack+4,(0,0x8000,rng.randrange(65536))[trial%3])
        put_word(c.wram,stack+6,0xEFFF)
        put_word(bank,node,0x780)
        put_word(bank,node+6,stack)
        record = (0,0xFFFF,0x2400)[trial%3]
        put_word(bank,node+10,record)
        put_word(bank,0x2400,rng.randrange(65536))
        c.PB,c.PC,c.DB,c.M,c.XF,c.X = 0x7E,0xA961,0x7F,0,0,node
        c.D,c.A,c.S = rng.randrange(65536),rng.randrange(65536),0x1FFF
        expected = c.wram[:]
        result = resume(expected,node)
        for _ in range(100):
            c.step()
            if c.PB<<16|c.PC==result['target']: break
        else: raise RuntimeError('resume timeout')
        # Nested calls overwrite scratch below saved S; the saved frame and all other WRAM count.
        expected[stack-32:stack+1] = c.wram[stack-32:stack+1]
        assert c.wram==expected,('memory',trial)
        actual = dict(A=c.A,X=c.X,Y=c.Y,DB=c.DB,D=c.D,P=c.P(),target=c.PB<<16|c.PC,S=c.S)
        assert actual==result,('registers',trial,actual,result)
    for trial in range(320):
        c = cpu.CPU()
        c.wram[:0x10000] = image
        c.wram[0x10000:] = rng.randbytes(0x10000)
        node = 0x600+(trial%20)*16
        bank = memoryview(c.wram)[0x10000:]
        put_word(bank,0x9E,node)
        put_word(bank,node+10,(0,0xFFFF,0x2400)[trial%3])
        nodes = [0x800+16*i for i in range(trial%12)]
        priorities = sorted(rng.randrange(256) for _ in nodes)
        put_word(bank,0xA0,nodes[0] if nodes else 0)
        for i,queued in enumerate(nodes):
            bank[queued+3] = priorities[i]
            put_word(bank,queued,nodes[i+1] if i+1<len(nodes) else 0)
        c.PB,c.PC,c.S,c.DB,c.D = 0x7E,0xA911,((2+trial%20)<<8)+0xC0,rng.randrange(256),rng.randrange(65536)
        c.setP(trial&255)
        expected = c.wram[:]
        saved = suspend(expected,node,c.S,c.P(),c.DB,c.D)
        for _ in range(400):
            c.step()
            if c.PB<<16|c.PC==0x7EA948: break
        else: raise RuntimeError('suspend timeout')
        expected[saved-32:saved+1] = c.wram[saved-32:saved+1]
        assert c.wram==expected and c.S==saved and c.DB==0x7F and c.I==1,('suspend',trial)
    return {'entry':'7EA961','branch':'7EA97E','cases':320,'suspend_cases':320,'verified':True,
            'comparison':'all WRAM except 33 caller-scratch bytes below/at saved S; resume checks A/X/Y/DB/D/P/PC/S; suspend checks S/DB/I',
            'scope':'resume: native dispatcher ABI, DB=7F, M/X=0, valid task/frame, status other than 08/10; suspend: A911 through A948 with valid lists'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
