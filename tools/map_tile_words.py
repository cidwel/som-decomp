"""Original map tile attributes and bit-packed tile-word decoding."""
import hashlib
import json
import random
import sys
from pathlib import Path

import combat_env
import hirom_ppu
import map_tables
import romio
from actor_program_calls import store, word

FUNCTIONS = ((0xC2A000,67,'initialize_map_tile_attributes_and_words'),
             (0xC2A043,38,'copy_map_tile_attribute_entries'),
             (0xC2A069,242,'decode_map_tile_word_layers'),
             (0xC2A15B,33,'apply_map_tile_separate_sign_delta'),
             (0xC2A17C,33,'apply_map_tile_signed_six_bit_delta'),
             (0xC2A19D,138,'read_map_tile_absolute_word'),
             (0xC2A227,91,'read_map_tile_six_bit_value'),
             (0xC2A282,102,'update_map_tile_word_attributes'))


class Reader:
    def __init__(self,rom,memory,pairs=4):
        self.rom,self.memory,self.pairs = rom,memory,pairs

    def read(self,offset=0):
        address = ((self.memory[0x12]<<16|word(self.memory,0x10))+offset)&0xFFFFFF
        bank = address>>16
        if bank in (0x7E,0x7F):return self.memory[address-0x7E0000]
        if bank>=0xC0:return self.rom[address&0x1FFFFF]
        raise ValueError('Bit reader requires ROM or WRAM source in this contract')

    def advance(self,amount=1):
        pointer = word(self.memory,0x10)+amount
        store(self.memory,0x10,pointer)
        if pointer>65535:
            if amount==1:self.memory[0x12]=(self.memory[0x12]+1)&255
            else:store(self.memory,0x12,word(self.memory,0x12)+1)

    def pair(self):
        value = self.memory[0]>>6
        self.memory[0] = self.memory[0]<<2&255
        self.pairs -= 1
        if not self.pairs:
            self.pairs = 4
            self.advance()
            self.memory[0] = self.read()
        return value

    def six(self):
        memory = self.memory
        buffer = memory[0]
        if self.pairs>=3:
            memory[0] = buffer>>3|(buffer&3)<<6
            self.pairs -= 3
            if not self.pairs:
                self.pairs = 4
                self.advance()
                memory[0] = self.read()
            return buffer>>2
        prefix = buffer>>2&(60 if self.pairs==2 else 48)
        memory[2] = prefix
        old_pairs = self.pairs
        self.advance()
        following = self.read()
        shifted = (following<<2|following>>7)&255
        memory[0] = shifted if old_pairs==2 else shifted<<2&255
        self.pairs = 3 if old_pairs==2 else 2
        return prefix|(following>>(6 if old_pairs==2 else 4))

    def attributes(self):
        memory = self.memory
        buffer = memory[0]
        if self.pairs>=2:
            field = buffer>>4
            memory[0] = (buffer<<4|buffer>>5&7)&255
            self.pairs -= 2
            if not self.pairs:
                self.pairs = 4
                self.advance()
                memory[0] = self.read()
        else:
            self.advance()
            following = self.read()
            field = buffer>>6<<2|following>>6
            memory[0] = (following<<2|following>>7)&255
            self.pairs = 3
        if field<8:
            memory[1] = field*4
            memory[5] = memory[5]&0xE3|memory[1]
        else:
            memory[1] = field*32&255
            memory[5] = memory[5]&31|memory[1]
        return field

    def absolute(self):
        memory = self.memory
        buffer = memory[0]
        first,second = self.read(1),self.read(2)
        memory[0],memory[1],memory[2] = second,first,buffer
        self.advance(2)
        shift = 8-self.pairs*2
        value = ((buffer>>(shift))<<(8+shift)|first<<shift|second>>(8-shift) if shift else buffer<<8|first)&65535
        if self.pairs==3:memory[0] = second<<2&255
        elif self.pairs==2:memory[0] = (second<<4|second>>5&7)&255
        elif self.pairs==1:memory[0] = second>>3|(second&3)<<6
        store(memory,4,value)
        return value


def delta(memory,value,negative):
    if negative:
        magnitude = 64-value
        memory[1] = magnitude
        store(memory,4,word(memory,4)-magnitude)
    else:
        store(memory,4,word(memory,4)+value)


def decode(rom,memory,header):
    selector = header&63
    if selector>=33:raise ValueError('Only33 original tile streams are established; malformed selectors are not empty streams')
    memory[0] = selector
    table = 0xB4000+selector*3
    store(memory,0x10,word(rom,table))
    store(memory,0x12,word(rom,table+2)|192)
    store(memory,0x14,0xC000)
    store(memory,0x16,0xC800)
    store(memory,0x18,768)
    store(memory,4,0)
    reader = Reader(rom,memory)
    memory[0] = reader.read()
    commands = [0]*4
    extended = [0]*4
    while True:
        command = reader.pair()
        commands[command] += 1
        if command==1:memory[4]=(memory[4]+1)&255
        elif command==2:memory[4]=(memory[4]-1)&255
        elif command==3:
            kind = reader.pair()
            extended[kind] += 1
            if kind<2:
                memory[1] = 0
                value = reader.six()
                delta(memory,value,kind==1)
            elif kind==2:
                reader.attributes()
                value = reader.six()
                delta(memory,value,value>=32)
            else:reader.absolute()
        value = word(memory,4)
        if header&192:
            store(memory,0x18,word(memory,0x18)-1)
            alternate = bool(word(memory,0x18)&32768)
        else:alternate=False
        if header&192==192 and not alternate:continue
        if header&192==64:first,second=alternate,not alternate
        elif header&192==128:first,second=not alternate,alternate
        else:first=second=True
        if first:
            pointer = word(memory,0x14)
            store(memory,0x10000+pointer,value)
            store(memory,0x14,pointer+2)
        if second:
            pointer = word(memory,0x16)
            store(memory,0x10000+pointer,value)
            store(memory,0x16,pointer+2)
        if (word(memory,0x14)==0xC600 and word(memory,0x16)==0xCE00):break
    return dict(pairs=reader.pairs,words=sum(commands),commands=commands,extended=extended,
                accumulator=0xC600 if header&192==64 else 0xCE00)


def attributes(rom,memory,header):
    base = (header&63)*384
    store(memory,0x10,base)
    store(memory,0x12,base+192)
    for destination,flag in ((0xB800,64),(0xBC00,128)):
        store(memory,0x14,destination)
        source = base+(192 if header&flag else 0)
        for index in range(192):
            identity = rom[0xB0400+source+index]
            memory[0x10000+destination+index*4:0x10000+destination+index*4+4] = rom[0xB0000+identity*4:0xB0004+identity*4]


def initialize(rom,memory,header):
    attributes(rom,memory,header)
    return decode(rom,memory,header)


def validate(rom):
    rnd = random.Random(0xA069)
    tables = map_tables.Tables(rom)
    fixtures = [('selector',selector|flags) for selector in range(33) for flags in (0,64,128,192)]
    fixtures += [('actual_map',header[2]) for map_id in range(511) if (header:=tables.header(map_id)) is not None]
    env = combat_env.Env(rom)
    env.c = hirom_ppu.CPU()
    commands,extended = [0]*4,[0]*4
    total_words = 0
    for trial,(label,header) in enumerate(fixtures):
        c = env.c
        c.wram[:] = rnd.randbytes(0x20000)
        c.vram[:] = rnd.randbytes(65536)
        c.cgram[:] = rnd.randbytes(512)
        c.dma[:] = rnd.randbytes(128)
        c.hw.clear()
        c.hw.update(wa=rnd.randrange(0x20000),m1=rnd.randrange(256),r=rnd.randrange(65536))
        c.va,c.vlatch,c.vmain,c.mdr1 = rnd.randrange(65536),rnd.randrange(65536),rnd.randrange(256),rnd.randrange(256)
        c.ca,c.cphase,c.clatch,c.mdr2 = rnd.randrange(256),rnd.randrange(2),rnd.randrange(256),rnd.randrange(256)
        c.wram[0x1C] = header
        c.C,c.N,c.Z,c.V = trial&1,trial>>1&1,trial>>2&1,trial>>3&1
        memory = bytearray(c.wram)
        hardware,dma = dict(c.hw),bytes(c.dma)
        video = bytes(c.vram),bytes(c.cgram),c.va,c.vlatch,c.vmain,c.mdr1,c.ca,c.cphase,c.clatch,c.mdr2
        result = initialize(rom,memory,header)
        for index in range(4):
            commands[index] += result['commands'][index]
            extended[index] += result['extended'][index]
        total_words += result['words']
        db = (0,0x42,0x7E,0xFF)[trial%4]
        xf = trial&1
        env.call(0xC2A000,A=rnd.randrange(65536),X=rnd.randrange(256 if xf else 65536),Y=rnd.randrange(256 if xf else 65536),D=0,DB=db,m=trial>>1&1,x=xf,long=True)
        memory[0x1E80:0x1F01] = c.wram[0x1E80:0x1F01]
        assert memory==c.wram,(trial,label,header,'WRAM',[(hex(i),u,v) for i,(u,v) in enumerate(zip(memory,c.wram)) if u!=v][:16])
        assert hardware==c.hw and dma==bytes(c.dma),(trial,'DMA/hardware')
        assert video==(bytes(c.vram),bytes(c.cgram),c.va,c.vlatch,c.vmain,c.mdr1,c.ca,c.cphase,c.clatch,c.mdr2),(trial,'PPU')
        expected = result['accumulator'],result['pairs'],0,1,int(bool(db&128)),int(db==0),int(bool(header&64)),0x1F00,0,db,1,1
        actual = c.A,c.X,c.Y,c.C,c.N,c.Z,c.V,c.S,c.D,c.DB,c.M,c.XF
        assert actual==expected,(trial,label,header,'CPU',actual,expected)
    names = ('hirom_ppu.py','loader_ppu.py','wram_dma.py','map_tables.py','actor_program_calls.py','combat_env.py','cpu65816.py','romio.py')
    return dict(verified=True,total_cases=len(fixtures),selector_calls=132,actual_map_calls=394,decoded_words=total_words,commands=commands,extended_commands=extended,
                dependencies_sha256={name:hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest() for name in names},
                scope='526 complete original C2A000 calls: all33 established tile-stream selectors in four layer configurations and all394 actual map headers. Full WRAM outside129 stack bytes, all unchanged VRAM/CGRAM/DMA/hardware/PPU ports and A/C/N/Z/V/X/Y/S/D/DB/M/X-width. No hooks. D0,binary arithmetic,four incoming DB contexts,both incoming widths. Original attributes and streams read at runtime only. Malformed selectors33..63,arbitrary direct helper contexts,full map-header coordinator and rendering/timing remain open.')


if __name__=='__main__':
    report = validate(romio.load(sys.argv[1]))
    if '--json' in sys.argv:Path(sys.argv[sys.argv.index('--json')+1]).write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
