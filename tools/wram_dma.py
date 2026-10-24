"""WRAM-port DMA data effects; timing, HDMA and PPU DMA remain unsupported.
Reference: bsnes/sfc/cpu/dma.cpp and cpu/io.cpp in bsnes-emu/bsnes.
"""
import cpu65816


class CPU(cpu65816.CPU):
    def __init__(self):
        super().__init__()
        self.dma = bytearray(128)

    def hwread(self, address):
        if 0x4300 <= address < 0x4380:
            offset = address - 0x4300
            if offset & 15 == 15:
                offset -= 4
            return self.dma[offset]
        return super().hwread(address)

    def rd8(self, address):
        address &= 0xFFFFFF
        bank, offset = address >> 16, address & 65535
        if (bank < 0x40 or 0x80 <= bank < 0xC0) and offset == 0x2180:
            pointer = self.hw.get('wa',0) & 0x1FFFF
            value = self.wram[pointer]
            self.hw['wa'] = (pointer + 1) & 0x1FFFF
            return value
        return super().rd8(address)

    def hwwrite(self, address, value):
        if 0x4300 <= address < 0x4380:
            offset = address - 0x4300
            if offset & 15 == 15:
                offset -= 4
            self.dma[offset] = value
        elif address == 0x420B:
            self.transfer(value)
        elif address == 0x420C and value:
            raise NotImplementedError('HDMA timing is not implemented')
        else:
            super().hwwrite(address,value)

    @staticmethod
    def valid_a(address):
        return not (address & 0x40FF00 == 0x2100 or address & 0x40FE00 == 0x4000 or
                    address & 0x40FFE0 == 0x4200 or address & 0x40FF80 == 0x4300)

    def transfer(self, mask):
        for channel in range(8):
            if not mask & 1 << channel:
                continue
            base = channel * 16
            control, target = self.dma[base], self.dma[base + 1]
            if target != 0x80 or control & 7 not in (0,2,6):
                raise NotImplementedError('Only fixed WRAM-port B-bus DMA is implemented')
            source = self.dma[base + 2] | self.dma[base + 3] << 8
            bank = self.dma[base + 4]
            size = self.dma[base + 5] | self.dma[base + 6] << 8
            for item in range(size or 65536):
                address = bank << 16 | source
                valid_b = address & 0xFE0000 != 0x7E0000 and address & 0x40E000 != 0
                valid_a = self.valid_a(address)
                if control & 128:
                    value = self.rd8(0x2180) if valid_b else 0
                    if valid_a:
                        self.wr8(address,value)
                else:
                    value = self.rd8(address) if valid_a else 0
                    if valid_b:
                        self.wr8(0x2180,value)
                if not control & 8:
                    source = (source + (-1 if control & 16 else 1)) & 65535
            self.dma[base + 2] = source & 255
            self.dma[base + 3] = source >> 8
            self.dma[base + 5] = self.dma[base + 6] = 0
