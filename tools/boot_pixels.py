"""Recovered image component mixing, byte-range adjustment and four-tile submissions.
usage: boot_pixels.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_tasks,boot_colour,boot_graphics,boot_tiles,boot_transform,boot_dma,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def add8(left,right):
    value = (left+right)&255
    return value,bool((~(left^right)&(left^value))&128)


def subtract8(left,right):
    value = (left-right)&255
    return value,bool(((left^right)&(left^value))&128)


def less8(left,right,overflow):
    """The routine's CMP branches retain V from the preceding byte arithmetic."""
    return bool((left-right)&128)!=overflow


def adjust_components(offsets,brightness):
    """$9E83-$9F30: reproduce excursion selection and three-byte adjustment in reverse order."""
    values = [0,0,0]
    excursion = 0
    overflow = False
    for lane in (2,1,0):
        value,overflow = add8(offsets[lane],brightness)
        values[lane] = value
        if value&128 and less8(value,excursion,overflow): excursion = value
        if value!=63 and not less8(value,63,overflow) and value!=excursion and not less8(value,excursion,overflow): excursion = value
    if not excursion: return [value>>1 for value in values]
    high = not less8(excursion,63,overflow)
    if high: excursion,overflow = subtract8(excursion,63)
    for lane in (2,1,0):
        value = values[lane]
        if high:
            if value!=63 and not less8(value,63,overflow): value,overflow = subtract8(value,excursion)
            else:
                value,overflow = add8(value,excursion)
                if value!=63 and not less8(value,63,overflow): value = 63
        else:
            if less8(value,0,overflow): value,overflow = subtract8(value,excursion)
            else:
                value,overflow = add8(value,excursion)
                if less8(value,0,overflow): value = 0
        values[lane] = value>>1
    return values


def mix_chroma(mem):
    """$9DF5: form overlapping three-component word stores from planes 1A00/1B00."""
    for index in range(64):
        first,second = word(mem,0x1A00+2*index),word(mem,0x1B00+2*index)
        target = 0x1C00+4*index
        put_word(mem,target,second>>1)
        put_word(mem,target+1,(-((first>>3)+(second>>2)))&65535)
        put_word(mem,target+2,first>>1)


def combine_components(mem,source,chroma):
    """$9E3D up to its tile call: expand one chroma quadrant over a luminance block."""
    for pixel in reversed(range(64)):
        row,column = divmod(pixel,8)
        at = (chroma&0xFF00)|((chroma+32*(row//2)+4*(column//2))&255)
        offsets = mem[at:at+3]
        brightness = (word(mem,source+2*pixel)>>2)&255
        values = adjust_components(offsets,brightness)
        mem[source+4*pixel:source+4*pixel+3] = bytes(values)


def combine_tile(mem,rom,source,chroma,threshold_high=0):
    """$9E3D: component expansion/adjustment followed by complete tile submission."""
    combine_components(mem,source,chroma)
    return boot_tiles.convert_tile(mem,rom,source,0x7E,threshold_high)


def combine_group(mem,rom,check_nearest=False):
    """$9F74: mix two chroma planes, expand four quadrants and submit four tiles."""
    mix_chroma(mem)
    bank = memoryview(mem)[65536:]
    maximum = 0
    for source,chroma in ((0x1600,0x1C00),(0x1700,0x1C80),(0x1800,0x1C90),(0x1900,0x1C10)):
        combine_components(mem,source,chroma)
        if check_nearest:
            samples = word(bank,0x1A)
            for pixel in range(64):
                target = source+4*pixel
                if bank[0x8000+boot_colour.quantize(mem,target)]: continue
                distance = min(sum((bank[samples+4*index+lane]-mem[target+lane])**2 for lane in range(3))&65535 for index in range(232))
                assert distance<255,('real colour threshold domain',distance)
                maximum = max(maximum,distance)
        boot_tiles.convert_tile(mem,rom,source,0x7E)
    return maximum


def validate(rom):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    initial.DB = 0x7F
    boot_tasks.call(initial,0x809B,A=0x43,X=0x300)
    baseline = initial.wram[:]
    rng = random.Random(0x9E3D)
    cases = dict(mix_chroma=0,combine_tile=0,combine_group=0,real_image_group=0)
    for trial in range(240):
        memory = baseline[:]
        memory[0x1A00:0x1C00] = rng.randbytes(512)
        expected = memory[:]
        mix_chroma(expected)
        c = boot_transform.Mode7Cpu()
        c.wram[:] = memory
        boot_transform.call(c,0x9DF5,data_bank=0)
        boot_transform.compare_memory(c.wram,expected,('mix chroma',trial))
        cases['mix_chroma'] += 1
    for trial in range(160):
        memory = baseline[:]
        bank = memoryview(memory)[65536:]
        source,chroma = (0x1600,0x1700,0x1800,0x1900)[trial%4],(0x1C00,0x1C80,0x1C90,0x1C10)[trial%4]
        memory[source:source+256] = rng.randbytes(256)
        memory[0x1C00:0x1D00] = rng.randbytes(256)
        put_word(bank,0x1A,0x5000)
        bank[0x5000:0x53A0] = bytes(rng.randrange(32) for _ in range(928))
        bank[0x8000:0x9000] = bytes(4096) if trial%3==0 else bytes(rng.randrange(1,247) for _ in range(4096))
        high = (0,1,15,255)[trial%4]
        expected = memory[:]
        combine_tile(expected,rom,source,chroma,high)
        c = boot_transform.Mode7Cpu()
        c.wram[:] = memory
        c.wram[0x1FC9] = high
        c.Y = chroma
        boot_transform.call(c,0x9E3D,X=source,data_bank=0,step_limit=5_000_000)
        boot_transform.compare_memory(c.wram,expected,('combine tile',trial))
        cases['combine_tile'] += 1
    for trial in range(64):
        memory = baseline[:]
        memory[0x1600:0x1D00] = rng.randbytes(1792)
        bank = memoryview(memory)[65536:]
        bank[0x8000:0x9000] = bytes(rng.randrange(1,247) for _ in range(4096))
        expected = memory[:]
        combine_group(expected,rom)
        c = boot_transform.Mode7Cpu()
        c.wram[:] = memory
        boot_transform.call(c,0x9F74,data_bank=0)
        boot_transform.compare_memory(c.wram,expected,('combine group',trial))
        cases['combine_group'] += 1
    original = boot_transform.Mode7Cpu()
    original.wram[:] = baseline
    original.DB = 0x7F
    boot_tasks.call(original,0xA061)
    boot_tasks.call(original,0x833E)
    boot_tasks.call(original,0xA090,A=0xD2,X=0xE536)
    original.Y = 0xE6BC
    boot_tasks.call(original,0xA12E,A=0xD2,X=0x80)
    boot_tasks.call(original,0x83AD,X=0x80)
    boot_tasks.call(original,0x8621,step_limit=5_000_000)
    expected = original.wram[:]
    put_word(expected,0x116,0x80)
    put_word(expected,0x110,6)
    put_word(expected,0x112,0)
    put_word(expected,0x114,0)
    expected[0x1D00:0x1D40] = expected[0x5FCA:0x600A]
    expected[0x1D40] = 0
    original.wram[:] = expected
    maximum = 0
    for group in range(192):
        boot_transform.decode_image_group(expected,rom)
        maximum = max(maximum,combine_group(expected,rom,check_nearest=True))
        boot_transform.call(original,0x9DB6,data_bank=0)
        boot_transform.call(original,0x9F74,data_bank=0,step_limit=5_000_000)
        boot_transform.compare_memory(original.wram,expected,('real image pixels',group))
        cases['real_image_group'] += 1
        # Supply the transfer-completion boundary; original cleanup releases all four sources.
        e = memoryview(expected)[65536:]
        e[0x6E] = 4
        boot_dma.cleanup(e)
        original.wram[0x1006E] = 4
        boot_tasks.call(original,0x92E9)
        boot_transform.compare_memory(original.wram,expected,('real pixel source cleanup',group))
    return dict(cases=cases,verified=True,comparison='all WRAM outside caller stack scratch 1F80-1FFF',real_image=dict(groups=192,tiles=768,pixels=49152,maximum_missing_cell_nearest_distance=maximum,stream_refill_cursor=f'D2{word(memoryview(expected)[65536:],0x80):04X}'),scope='native low-WRAM component buffers, exact word/byte shifts and retained arithmetic V across CMP; complete four-tile submissions; real decode/scale/transform/component/palette-index/bitplane/descriptor groups with supplied completion boundaries; nearest distances below255 prove independence from retained threshold high bytes for real misses; physical DMA payload and whole task/message timing remain open')


def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
