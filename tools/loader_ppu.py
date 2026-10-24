"""Forced-blank VRAM/CGRAM port data effects for native loader validation.
Reference: bsnes/sfc/ppu/io.cpp and ppu.hpp. Rendering/timing/OAM remain open.
"""
import wram_dma


class CPU(wram_dma.CPU):
    def __init__(self):
        super().__init__()
        self.vram = bytearray(65536)
        self.cgram = bytearray(512)
        self.blank = False
        self.vmain = self.va = self.vlatch = self.mdr1 = self.mdr2 = 0
        self.ca = self.cphase = self.clatch = 0

    def mapped_word(self):
        address = self.va
        mapping = self.vmain >> 2 & 3
        if mapping:
            width = 7 + mapping
            mask = (1 << width) - 1
            address = address & ~mask | (address << 3 & (mask & ~7)) | (address >> (width - 3) & 7)
        return address & 0x7FFF

    def read_vram_word(self):
        if not self.blank:
            raise NotImplementedError('VRAM access outside forced blank requires timing')
        at = self.mapped_word() * 2
        return self.vram[at] | self.vram[at + 1] << 8

    def increment(self):
        self.va = (self.va + (1,32,128,128)[self.vmain & 3]) & 65535

    def ppu_write(self, register, value):
        if register == 0x2100:
            self.blank = bool(value & 128)
        elif register == 0x2115:
            self.vmain = value
        elif register in (0x2116,0x2117):
            if register == 0x2116:
                self.va = self.va & 0xFF00 | value
            else:
                self.va = self.va & 255 | value << 8
            self.vlatch = self.read_vram_word()
        elif register in (0x2118,0x2119):
            if not self.blank:
                raise NotImplementedError('VRAM access outside forced blank requires timing')
            high = register & 1
            self.vram[self.mapped_word()*2 + high] = value
            if high == self.vmain >> 7:
                self.increment()
        elif register == 0x2121:
            self.ca,self.cphase = value,0
        elif register == 0x2122:
            if not self.blank:
                raise NotImplementedError('CGRAM access outside forced blank requires timing')
            if not self.cphase:
                self.clatch = value
            else:
                self.cgram[self.ca*2] = self.clatch
                self.cgram[self.ca*2+1] = value & 127
                self.ca = (self.ca+1)&255
            self.cphase ^= 1
        else:
            raise NotImplementedError(f'PPU write port {register:04X}')

    def ppu_read(self, register):
        if register in (0x2139,0x213A):
            high = register & 1 == 0
            value = self.vlatch >> (8 if high else 0) & 255
            if int(high) == self.vmain >> 7:
                self.vlatch = self.read_vram_word()
                self.increment()
            self.mdr1 = value
            return value
        if register == 0x213B:
            if not self.blank:
                raise NotImplementedError('CGRAM access outside forced blank requires timing')
            at = self.ca*2 + self.cphase
            value = self.cgram[at]
            if self.cphase:
                value = self.mdr2 & 128 | value & 127
                self.ca = (self.ca+1)&255
            self.cphase ^= 1
            self.mdr2 = value
            return value
        raise NotImplementedError(f'PPU read port {register:04X}')

    def wr8(self, address, value):
        address &= 0xFFFFFF
        bank,offset = address>>16,address&65535
        if (bank<0x40 or 0x80<=bank<0xC0) and 0x2100<=offset<0x2140:
            self.ppu_write(offset,value&255)
        else:
            super().wr8(address,value)

    def rd8(self, address):
        address &= 0xFFFFFF
        bank,offset = address>>16,address&65535
        if (bank<0x40 or 0x80<=bank<0xC0) and 0x2100<=offset<0x2140:
            return self.ppu_read(offset)
        return super().rd8(address)

    def dma_read_b(self, offset):
        if offset not in (0x39,0x3A,0x3B,0x80):
            raise NotImplementedError(f'DMA B-bus read port {offset:02X}')
        return self.rd8(0x2100 | offset)

    def dma_write_b(self, offset, value):
        if offset not in (0,0x15,0x16,0x17,0x18,0x19,0x21,0x22,0x80,0x81,0x82,0x83):
            raise NotImplementedError(f'DMA B-bus write port {offset:02X}')
        self.wr8(0x2100 | offset,value)

    def transfer(self, mask):
        patterns = ((0,),(0,1),(0,),(0,0,1,1),(0,1,2,3),(0,1),(0,),(0,0,1,1))
        for channel in range(8):
            if not mask & 1 << channel:
                continue
            base = channel * 16
            control,target = self.dma[base],self.dma[base+1]
            pattern = patterns[control & 7]
            source = self.dma[base+2] | self.dma[base+3] << 8
            bank = self.dma[base+4]
            size = self.dma[base+5] | self.dma[base+6] << 8
            for item in range(size or 65536):
                address = bank << 16 | source
                offset = (target + pattern[item % len(pattern)]) & 255
                valid_b = offset != 0x80 or (address & 0xFE0000 != 0x7E0000 and address & 0x40E000 != 0)
                valid_a = self.valid_a(address)
                if control & 128:
                    value = self.dma_read_b(offset) if valid_b else 0
                    if valid_a:
                        self.wr8(address,value)
                else:
                    value = self.rd8(address) if valid_a else 0
                    if valid_b:
                        self.dma_write_b(offset,value)
                if not control & 8:
                    source = (source + (-1 if control & 16 else 1)) & 65535
            self.dma[base+2] = source & 255
            self.dma[base+3] = source >> 8
            self.dma[base+5] = self.dma[base+6] = 0
