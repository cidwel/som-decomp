"""Recovered title-parent control-task creation and optional audio request.
usage: boot_parent_control.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_create,boot_parent_dispatch,boot_transform,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


class EchoCpu(cpu.CPU):
    """APU port acknowledgement boundary for the original command80 sender."""
    def __init__(self):
        super().__init__()
        self.echo = 0
        self.port_writes = []

    def rd8(self,address):
        bank,offset = (address>>16)&255,address&65535
        if (bank<64 or 128<=bank<192) and 0x2140<=offset<=0x2143:
            return self.echo if offset==0x2140 else 0
        return super().rd8(address)

    def wr8(self,address,value):
        bank,offset = (address>>16)&255,address&65535
        if (bank<64 or 128<=bank<192) and 0x2140<=offset<=0x2143:
            self.port_writes.append((offset,value&255))
            if offset==0x2140: self.echo = value&255
            return
        super().wr8(address,value)


def ensure_control(mem):
    """$D14C: retain existing control, otherwise request80/20, spawn6492, release input."""
    bank = memoryview(mem)[65536:]
    if bank[0x314]: return []
    writes = []
    if bank[0x316]:
        mem[0x1E00],mem[0x1E01] = 0,0x20
        writes = [(0x2143,mem[0x1E03]),(0x2142,mem[0x1E02]),(0x2141,0x20),(0x2140,0x80),(0x2140,0)]
    node = boot_create.spawn(mem,mem[0x6492:0x649C])
    bank[0x314] = bank[node+4] if node else 0
    boot_parent_dispatch.route_input(bank,5,'release')
    return writes


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    baseline = initial.wram[:]
    rng = random.Random(0xD14C)
    cases = dict(existing_control=0,spawn_without_audio=0,spawn_with_audio=0,no_free_task_record=0)
    for trial in range(320):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        current = word(bank,0x9C)
        put_word(bank,0xA6,word(bank,current))
        put_word(bank,current,0)
        put_word(bank,0x9E,current)
        bank[current+2:current+6] = bytes((1,128,7,1))
        bank[0xAA+5] = 1
        bank[0x314] = rng.randrange(1,256) if trial%4==0 else 0
        bank[0x316] = trial%2
        if trial%4==3: put_word(bank,0xA6,0)
        base = word(bank,0x92)
        bank[base:base+80] = rng.randbytes(80)
        for index in range(5): bank[base+16*index+1] = rng.choice((7,0,1,99))
        memory[0x1E00:0x1E10] = rng.randbytes(16)
        expected = memory[:]
        writes = ensure_control(expected)
        c = EchoCpu()
        c.wram[:] = memory
        c.D,c.DB = 0x300,0x7F
        boot_tasks.call(c,0xD14C)
        boot_transform.compare_memory(c.wram,expected,('parent control',trial))
        assert c.port_writes==writes,('parent audio writes',trial)
        assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x1FFF,1,0),('parent control restore',trial)
        name = ('existing_control','spawn_with_audio','spawn_without_audio','no_free_task_record')[trial%4]
        cases[name] += 1
    return dict(verified=True,cases=cases,comparison='all WRAM outside caller stack1F80-1FFF, ordered APU-port writes and restored D/DB/S/M/X',scope='caller DB7F, real6492 descriptor, available task-frame/timer/heap resources or missing task record; original C30004 command sender and spawn/input-release helpers execute; APU echo supplied, SPC command processing/waveform and complete parent scheduling remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
