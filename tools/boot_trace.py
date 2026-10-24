"""Trace the original reset/title program with bounded hardware events and real SPC code.
usage: boot_trace.py ROM OUT.json [steps=N] [irq_every=N] [pad=N] [pad_at=N] [warm=0|1]
Vblank polls toggle on reads; interrupts are delivered per instruction interval. Not cycle accurate.
Stops at the main-game entry; warm=1 is a probe with empty RAM, not an ending-state restart.
"""
import sys, json, collections, romio, cpu65816 as cpu, boot_audio, rip_hero_anims

class BootCpu(rip_hero_anims.PpuCpu):
    def __init__(self):
        super().__init__()
        self.registers = {}
        self.vblank = self.serial = 0
        self.irq_pending = self.nmi_pending = False
        self.hardware_reads = collections.Counter()
        self.interrupt_entries = []

    def rd8(self, address):
        bank,off = address>>16,address&0xFFFF
        if bank>=0xE0:
            address &= ~0x200000
        if bank<0x40 or 0x80<=bank<0xC0:
            if off==0x4016:
                value = (self.pad >> (15-self.serial))&1 if self.serial<16 else 0
                self.serial += 1
                return value
            if off==0x4017: return 0
        return super().rd8(address)

    def wr8(self, address, value):
        bank,off = address>>16,address&0xFFFF
        if bank<0x40 or 0x80<=bank<0xC0:
            if off==0x4016 and not value&1: self.serial = 0
            if 0x2100<=off<0x4400: self.registers[off] = value&0xFF
        super().wr8(address,value)
        if bank==0x7E or bank<0x40 or 0x80<=bank<0xC0:
            if 0x100<=off<0x108:
                base = off&~3
                opcode = self.rd8(base)
                if (opcode==0x40 and off==base) or (opcode==0x5C and off==base+3):
                    self.interrupt_entries.append({'at_step':self.steps,
                        'interrupt':'NMI' if base==0x100 else 'IRQ',
                        'entry':'RTI' if opcode==0x40 else '%06X'%self.rd24(base+1)})

    def ppu(self, off, value):
        if 0x2180<=off<=0x2183:
            cpu.CPU.hwwrite(self,off,value)
        else:
            super().ppu(off,value)

    def dma(self, mask):
        before = dict(self.ch)
        super().dma(mask)
        for channel in range(8):
            if not mask>>channel&1: continue
            base = 0x4300+channel*16
            count = (before.get(base+5,0)|before.get(base+6,0)<<8) or 0x10000
            if not before.get(base,0)&8:
                source = (before.get(base+2,0)|before.get(base+3,0)<<8)+count
                self.ch[base+2],self.ch[base+3] = source&0xFF,(source>>8)&0xFF
            self.ch[base+5] = self.ch[base+6] = 0

    def hwread(self, off):
        self.hardware_reads[off] += 1
        if off==0x4212:
            self.vblank ^= 0x80
            if self.vblank: self.nmi_pending = True
            return self.vblank
        if off==0x4210:
            value = 0x80 if self.nmi_pending else 0
            self.nmi_pending = False
            return value
        if off==0x4211:
            value = 0x80 if self.irq_pending else 0
            self.irq_pending = False
            return value
        if 0x4300<=off<0x4380: return self.ch.get(off,0)
        return super().hwread(off)

    def interrupt(self, nmi=False):
        assert not self.E
        self.push8(self.PB)
        self.push16(self.PC)
        self.push8(self.P())
        self.I,self.Dm,self.PB = 1,0,0
        self.PC = self.rd16(0xFFEA if nmi else 0xFFEE)
        if nmi: self.nmi_pending = True
        else: self.irq_pending = True

def run(rom, steps=1_000_000, irq_every=5000, pad=0, pad_at=0, warm=False):
    cpu.set_rom(rom)
    c = BootCpu()
    c.E,c.S = 1,0x01FF
    c.PC = int.from_bytes(rom[0xFFFC:0xFFFE],'little')
    if warm:
        c.E,c.PB,c.PC,c.XF = 0,0xC1,0x4CFA,0
    sound = boot_audio.Transport()
    boot_audio.connect(c,sound)
    blocks, tasks = [], []
    transfers = set()
    hot = collections.Counter()
    interrupts = collections.Counter()
    game_entry = None
    game_entry_state = None
    for tick in range(steps):
        c.pad = pad if tick>=pad_at else 0
        address = c.PB<<16|c.PC
        if address==0xC00009 and game_entry is None:
            game_entry = tick
            game_entry_state = {'map':c.rd16(0x7E00DC)&0x1FF,'event_flags_0':c.rd8(0x7ECF00),
                                'event_flags_4E':c.rd8(0x7ECF4E),'stack':c.S}
            break
        if address==0xC14C30:
            blocks.append({'at_step':tick,'source':'%06X'%((c.A&0xFF)<<16|c.X),
                           'destination':'%06X'%((c.A>>8)<<16|c.Y)})
        if address==0x7EAB88:
            pointer = (c.A&0xFF)<<16|c.X
            tasks.append({'at_step':tick,'descriptor':'%06X'%pointer,
                          'entry':'%06X'%c.rd24(pointer),'priority':c.rd8(pointer+3)})
        hot[address] += 1
        opcode = c.rd8(address)
        m,x = c.M,c.XF
        c.step()
        if opcode in (0x20,0x22,0x4C,0x5C,0x6C,0x7C,0xDC,0xFC):
            transfers.add((address,c.PB<<16|c.PC,opcode,m,x,c.M,c.XF))
        if (tick+1)%irq_every==0 and not c.E:
            control = c.registers.get(0x4200,0)
            if control&0x20 and not c.I:
                c.interrupt()
                interrupts['IRQ'] += 1
            elif control&0x80:
                c.interrupt(nmi=True)
                interrupts['NMI'] += 1
    names = {0x20:'JSR',0x22:'JSL',0x4C:'JMP',0x5C:'JML',0x6C:'JMP (abs)',
             0x7C:'JMP (abs,X)',0xDC:'JML [abs]',0xFC:'JSR (abs,X)'}
    return {'steps':c.steps,'instruction_budget':steps,
            'stop_reason':'main game entry' if game_entry is not None else 'instruction budget',
            'initial_wram':'zero-filled; warm probe lacks ending state',
            'irq_interval_instructions':irq_every,'pad':pad,'pad_at':pad_at,'warm':warm,
            'cycle_accurate':False,'vblank_poll_model':'toggle on read',
            'apu_boot_transport':'acknowledgement model, then original SPC700 driver',
            'final_pc':'%06X'%(c.PB<<16|c.PC),'game_entry_step':game_entry,
            'game_entry_state':game_entry_state,'final_map':c.rd16(0x7E00DC)&0x1FF,
            'interrupts':dict(interrupts),'apu_phase':sound.phase,'decompressor_calls':blocks,'task_creations':tasks,
            'interrupt_entry_writes':c.interrupt_entries,
            'final_cpu':{'S':c.S,'DB':c.DB,'M':c.M,'X':c.XF,'I':c.I,
                         'interrupt_control':c.registers.get(0x4200,0)},
            'scheduler':{'active_count':c.rd16(0x7F009A),'current':c.rd16(0x7F009E),
                         'runnable':c.rd16(0x7F00A0),'waiting':c.rd16(0x7F00A2),'completed':c.rd16(0x7F00A4)},
            'task_records':[{'offset':node,'link':c.rd16(0x7F0000|node),
                             'status':c.rd8(0x7F0000|(node+2)),'priority':c.rd8(0x7F0000|(node+3)),
                             'id':c.rd8(0x7F0000|(node+4)),'stack':c.rd16(0x7F0000|(node+6)),
                             'wait':c.rd16(0x7F0000|(node+0xA))}
                            for node in range(0x600,0x740,0x10)],
            'hardware_reads':{'%04X'%o:n for o,n in sorted(c.hardware_reads.items())},
            'most_frequent_pcs':[{'pc':'%06X'%a,'visits':n} for a,n in hot.most_common(12)],
            'control_transfers':[{'pc':'%06X'%a,'target':'%06X'%b,'instruction':names[op],
                                  'M':m,'X':x,'target_M':tm,'target_X':tx}
                                 for a,b,op,m,x,tm,tx in sorted(transfers)]}

def main():
    rom = romio.rom_from_argv()
    options = dict(arg.split('=',1) for arg in sys.argv[2:])
    report = run(rom,steps=int(options.get('steps','1000000'),0),
                 irq_every=int(options.get('irq_every','5000'),0),pad=int(options.get('pad','0'),0),
                 pad_at=int(options.get('pad_at','0'),0),
                 warm=bool(int(options.get('warm','0'))))
    with open(sys.argv[1],'w') as f:
        json.dump(report,f,indent=2)
        f.write('\n')
    print(json.dumps({key:report[key] for key in ('steps','final_pc','game_entry_step','interrupts','apu_phase')},indent=2))

if __name__ == '__main__':
    main()
