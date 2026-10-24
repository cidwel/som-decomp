"""2 MiB SoM HiROM E0..FF mirrors for the forced-blank loader runtime.
Reference: bsnes Bus::map size mirroring and HiROM board ROM windows.
Other CPU/peripheral behavior remains inherited from loader_ppu.
"""
import cpu65816
import loader_ppu


class CPU(loader_ppu.CPU):
    def rd8(self,address):
        address &= 0xFFFFFF
        if address>>16>=0xE0:
            return cpu65816.ROM[address&0x1FFFFF]
        return super().rd8(address)
