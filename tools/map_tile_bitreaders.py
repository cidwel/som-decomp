"""Original tile bit-reader alignment, bank crossings and byte-arithmetic contracts."""
import hashlib
import json
import random
import sys
from pathlib import Path

import combat_env
import hirom_ppu
import map_tile_words
import romio
from actor_program_calls import store, word


def validate(rom):
    rnd = random.Random(0xA227)
    env = combat_env.Env(rom)
    env.c = hirom_ppu.CPU()
    fixtures = [(kind,buffer,pairs,pointer) for kind in ('six','attributes','absolute') for buffer in range(256) for pairs in range(1,5) for pointer in (0x3000,0xFFFF)]
    fixtures += [('absolute',buffer,pairs,0x7FFF) for buffer in range(256) for pairs in range(1,5)]
    fixtures += [(kind,value,sign,previous) for kind in ('separate_delta','signed_delta') for value in range(64) for sign in ((0,1) if kind=='separate_delta' else (0,)) for previous in (0,127,128,255,256,32767,32768,65535)]
    counts = dict(six=0,attributes=0,absolute=0,separate_delta=0,signed_delta=0)
    for trial,(kind,value,pairs,pointer) in enumerate(fixtures):
        c = env.c
        c.wram[:] = rnd.randbytes(0x20000)
        c.vram[:] = rnd.randbytes(65536)
        c.cgram[:] = rnd.randbytes(512)
        c.dma[:] = rnd.randbytes(128)
        c.hw.clear()
        c.hw.update(wa=rnd.randrange(0x20000),m1=rnd.randrange(256),r=rnd.randrange(65536))
        c.va,c.vlatch,c.vmain,c.mdr1 = rnd.randrange(65536),rnd.randrange(65536),rnd.randrange(256),rnd.randrange(256)
        c.ca,c.cphase,c.clatch,c.mdr2 = rnd.randrange(256),rnd.randrange(2),rnd.randrange(256),rnd.randrange(256)
        c.C,c.N,c.Z,c.V = trial&1,trial>>1&1,trial>>2&1,trial>>3&1
        incoming_a = rnd.randrange(65536)&0xFF00|value
        incoming_x,incoming_y = rnd.randrange(256),rnd.randrange(256)
        overflow = c.V
        if kind in ('six','attributes','absolute'):
            c.wram[0] = value
            store(c.wram,0x10,pointer)
            c.wram[0x12] = 0x7E
            incoming_x,incoming_y = pairs,0
        else:
            store(c.wram,4,pointer)
            if kind=='separate_delta':c.wram[1] = pairs
        memory = bytearray(c.wram)
        hardware,dma = dict(c.hw),bytes(c.dma)
        video = bytes(c.vram),bytes(c.cgram),c.va,c.vlatch,c.vmain,c.mdr1,c.ca,c.cphase,c.clatch,c.mdr2
        final_m = 1
        final_x,final_y = incoming_x,incoming_y
        if kind in ('six','attributes','absolute'):
            reader = map_tile_words.Reader(rom,memory,pairs)
            following = reader.read(1)
            if kind=='six':
                entry = 0xC2A227
                result = reader.six()
                carry = value>>1&1 if pairs>=3 else 1 if pairs==2 else following>>3&1
                expected_a = incoming_a&0xFF00|result
                negative,zero = 0,int(result==0)
            elif kind=='attributes':
                entry = 0xC2A282
                field = reader.attributes()
                result = memory[5]
                expected_a = incoming_a&0xFF00|result
                carry,negative,zero = int(field>=8),int(bool(result&128)),int(result==0)
            else:
                entry = 0xC2A19D
                second = reader.read(2)
                result = reader.absolute()
                expected_a = result
                overflow = int(bool(~(pointer^2)&(pointer^((pointer+2)&65535))&32768))
                if pairs==4:
                    final_m,carry,negative,zero = 0,1,0,1
                else:
                    carry = following>>4&1 if pairs==3 else second>>3&1 if pairs==2 else second>>2&1
                    negative,zero = int(bool(result&128)),int(result&255==0)
            final_x = reader.pairs
        else:
            entry = 0xC2A15B if kind=='separate_delta' else 0xC2A17C
            negative_delta = bool(pairs) if kind=='separate_delta' else value>=32
            if kind=='separate_delta':memory[1] >>= 1
            low = pointer&255
            magnitude = 64-value if negative_delta else value
            raw = low-magnitude if negative_delta else low+magnitude
            carry = int(raw>=0) if negative_delta else int(raw>255)
            result = raw&255
            overflow = int(bool((low^magnitude if negative_delta else ~(low^magnitude))&(low^result)&128))
            map_tile_words.delta(memory,value,negative_delta)
            expected_a = incoming_a&0xFF00|result
            flags_value = memory[5] if (negative_delta and not carry or not negative_delta and carry) else result
            negative,zero = int(bool(flags_value&128)),int(flags_value==0)
        db = (0,0x42,0x7E,0xFF)[trial%4]
        env.call(entry,A=incoming_a,X=incoming_x,Y=incoming_y,D=0,DB=db,m=1,x=1,long=False)
        memory[0x1E80:0x1F01] = c.wram[0x1E80:0x1F01]
        assert memory==c.wram,(trial,kind,value,pairs,pointer,'WRAM',[(hex(i),u,v) for i,(u,v) in enumerate(zip(memory,c.wram)) if u!=v][:12])
        assert hardware==c.hw and dma==bytes(c.dma),(trial,'DMA/hardware')
        assert video==(bytes(c.vram),bytes(c.cgram),c.va,c.vlatch,c.vmain,c.mdr1,c.ca,c.cphase,c.clatch,c.mdr2),(trial,'PPU')
        expected = expected_a,final_x,final_y,carry,negative,zero,overflow,0x1F00,0,db,final_m,1
        actual = c.A,c.X,c.Y,c.C,c.N,c.Z,c.V,c.S,c.D,c.DB,c.M,c.XF
        assert actual==expected,(trial,kind,value,pairs,pointer,'CPU',actual,expected)
        counts[kind] += 1
    names = ('map_tile_words.py','hirom_ppu.py','loader_ppu.py','wram_dma.py','actor_program_calls.py','combat_env.py','cpu65816.py','romio.py')
    return dict(verified=True,total_cases=len(fixtures),calls=counts,
                dependencies_sha256={name:hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest() for name in names},
                scope='8704 complete original no-hook helper calls: every256 buffer byte/four remaining-pair alignments at WRAM7E:3000 and7E:FFFF for six-bit reader,attribute update,absolute word;absolute additionally7E:7FFF to test16-bit pointer-add overflow. All64 delta values,eight previous-word carry/borrow/sign boundaries,separate signs and embedded six-bit signs. Full WRAM outside129 stack bytes,unchanged VRAM/CGRAM/DMA/hardware/ports and A/C/N/Z/V/X/Y/S/D/DB/M/X-width. D0,binary arithmetic,M8/X8,four DB contexts,readerY0. Synthetic bytes exist only in volatile WRAM. Arbitrary entry contexts and malformed tile selectors remain open.')


if __name__=='__main__':
    report = validate(romio.load(sys.argv[1]))
    if '--json' in sys.argv:Path(sys.argv[sys.argv.index('--json')+1]).write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
