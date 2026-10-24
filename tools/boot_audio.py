"""Execute $C3:0000 through an IPL-port transport model, then use the real SPC driver.
usage: boot_audio.py ROM [--json OUT]
The transport models acknowledgements, not IPL instructions or chip timing.
"""
import sys, json, romio, cpu65816 as cpu, spc700_cpu, sfx_extract, music_extract

class Transport:
    def __init__(self):
        self.input = [0, 0, 0, 0]
        self.output = [0xAA, 0xBB, 0, 0]
        self.ram = bytearray(65536)
        self.phase = 'ready'
        self.counter = -1
        self.destination = 0
        self.blocks = []
        self.apu = None
        self.reads = self.writes = 0

    def write(self, port, value):
        value &= 0xFF
        self.writes += 1
        self.input[port] = value
        if self.phase == 'running':
            self.apu.ports_in[port] = value
            return
        if self.phase == 'start_pending':
            if port == 0:
                self.apu = spc700_cpu.Apu(self.ram, pc=self.destination)
                self.apu.ports_in[:] = self.input
                self.apu.run(60000)
                self.phase = 'running'
            return
        if port != 0:
            return
        if self.phase == 'upload' and value == ((self.counter + 1) & 0xFF):
            self.ram[self.destination] = self.input[1]
            self.destination = (self.destination + 1) & 0xFFFF
            self.blocks[-1]['size'] += 1
            self.counter = value
        else:
            self.destination = self.input[2] | self.input[3] << 8
            if self.input[1]:
                self.blocks.append({'destination': self.destination, 'size': 0})
                self.phase = 'upload'
                self.counter = -1
            else:
                self.phase = 'start_pending'
        self.output[0] = value

    def read(self, port):
        self.reads += 1
        if self.phase != 'running':
            return self.output[port]
        before = list(self.apu.ports_out)
        for _ in range(96):
            self.apu.step()
            if self.apu.ports_out != before:
                self.apu.run(16)
                break
        return self.apu.ports_out[port]

def connect(c, transport):
    original_read, original_write = c.rd8, c.wr8
    def port(address):
        bank, off = address >> 16, address & 0xFFFF
        return off - 0x2140 if (bank < 0x40 or 0x80 <= bank < 0xC0) and 0x2140 <= off <= 0x2143 else None
    def read(address):
        p = port(address)
        return transport.read(p) if p is not None else original_read(address)
    def write(address, value):
        p = port(address)
        if p is not None: transport.write(p, value)
        else: original_write(address, value)
    c.rd8, c.wr8 = read, write

def validate(rom):
    cpu.set_rom(rom)
    c, transport = cpu.CPU(), Transport()
    connect(c, transport)
    c.S = 0x1FFF
    c.push8(0xFE)
    c.push16(0xFFFD)
    c.PB, c.PC = 0xC3, 0
    while (c.PB << 16 | c.PC) != 0xFEFFFE:
        c.step()
        if c.steps > 2_000_000:
            raise RuntimeError('sound boot upload timeout')
    expected, blocks = sfx_extract.boot_ram(rom)
    assert transport.ram == expected
    assert [(r['destination'],r['size']) for r in transport.blocks] == blocks
    assert transport.phase == 'running'
    for i,block in enumerate(transport.blocks):
        source = 0xC30000 + int.from_bytes(rom[0x30008+i*2:0x3000A+i*2],'little')
        block['source'] = '%06X' % source
        block['encoded_size'] = block['size'] + 2
    expected_wram = bytearray(0x20000)
    music_extract.boot_state(rom, expected_wram)
    assert c.wram[0x1E00:0x1F00] == expected_wram[0x1E00:0x1F00]
    return {'routine':'C30000','blocks':transport.blocks,'uploaded_bytes':sum(n for _,n in blocks),
            'steps':c.steps,'port_reads':transport.reads,'port_writes':transport.writes,
            'upload_matches_native_model':True,'sound_variables_match_native_model':True,
            'ipl_instruction_emulation':False,'cycle_accurate':False}

def main():
    rom = romio.rom_from_argv()
    report = validate(rom)
    print(json.dumps(report,indent=2))
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')

if __name__ == '__main__':
    main()
