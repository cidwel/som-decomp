"""Recovered title-parent sequence through both songs, maps, fades and task launches.
usage: boot_title_sequence.py ROM [--json OUT.json]
"""
import sys,json,romio,boot_tasks,boot_create,boot_pool,boot_wait,boot_parent_dispatch,boot_parent_transition,boot_parent_fade,boot_vram,boot_dma,boot_ppu_queue,boot_image,music_extract,boot_audio,sfx_extract,spc700_cpu,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word


def start_task(mem,descriptor):
    node = boot_create.spawn(mem,mem[descriptor:descriptor+10])
    return mem[65536+node+4] if node else 0


def title_sequence(mem,stack,wait,transition,song):
    """$D23E: image launch, second map/fade, input wait, two songs and first map/text."""
    bank = memoryview(mem)[65536:]
    bank[0x311] = start_task(mem,0x5F12)
    boot_parent_transition.copy_title_map(mem,0x3A0)
    if not transition(mem,True): return
    while not bank[0x316]:
        _,result = wait(mem,1,stack-5)
        if not result: return
    song(mem,0x2D,0x0B,0x0F)
    record,result = wait(mem,0x7FFF,stack-5)
    if not result: return
    boot_pool.release(bank,record)
    reply = boot_pool.allocate(bank)
    boot_wait.append_record(bank,reply,bank[0x311])
    _,result = wait(mem,0x10E,stack-5)
    if not result: return
    if not transition(mem,False): return
    boot_parent_transition.copy_title_map(mem,0)
    _,result = wait(mem,30,stack-5)
    if not result: return
    song(mem,0x2C,0x0F,0x0F)
    if not transition(mem,True): return
    bank[0x317] = 1
    bank[0x312] = start_task(mem,0x5EAA)


def compare(actual,expected,label):
    """The music loader's private variables1E04-1FFF are outside this parent model."""
    differences = [i for i in range(len(actual)) if actual[i]!=expected[i] and not (0x1E04<=i<0x2000 or 0x740<=i<0x800)]
    assert not differences,(label,[hex(i) for i in differences[:24]],len(differences))


def validate(rom,input_waits=1,abort_stage=None,abort_updates=0):
    cpu.set_rom(rom)
    initial,_ = boot_tasks.initialized(rom)
    expected = initial.wram[:]
    bank = memoryview(expected)[65536:]
    current = word(bank,0x9C)
    put_word(bank,0xA6,word(bank,current))
    put_word(bank,current,0)
    put_word(bank,current+10,0)
    put_word(bank,current+12,0xF84)
    bank[current+2:current+6] = bytes((1,0,7,1))
    bank[0xAA+5] = 1
    bank[0xF84:0xF88] = bytes((1,7,0,0))
    put_word(bank,0x9E,current)
    put_word(bank,0xA0,0)
    put_word(bank,0xA2,0)
    bank[0x96] &= ~64
    bank[0x311:0x318] = bytes((0,0,0,0,4,0,0))
    source = boot_vram.create_buffer(bank,expected,0x10)
    put_word(bank,0x306,source)
    bank[0x310] = 0x20
    mirror = word(bank,0x2E2)
    put_word(bank,mirror,0)
    music_extract.boot_state(rom,expected)
    # Current task has higher priority than launched children; only the parent is dispatched.
    events = [(2,2,0)]+[(255,0,0)]*(13+input_waits)+[(4,0,0)]+[(255,0,0)]*34
    for index,(sender,opcode,row) in enumerate(events):
        record = 0x2400+8*index
        put_word(bank,record,record+8 if index+1<len(events) else 0)
        bank[record+2],bank[record+3] = sender,opcode
        put_word(bank,record+4,0xF84 if sender==255 else row)
    put_word(bank,current+10,0x2400)
    c = cpu.CPU()
    c.wram[:] = expected
    transport = boot_audio.Transport()
    transport.apu = spc700_cpu.Apu(sfx_extract.boot_ram(rom)[0])
    transport.apu.run(60000)
    transport.phase = 'running'
    boot_audio.connect(c,transport)
    c.S,c.PB,c.PC,c.M,c.XF,c.D,c.DB = 0x7FF,0x7E,0xD23E,1,0,0x300,0x7F
    c.push16(0xFFFD)
    fades = iter(((0xD252,0xD255,0xD258,True),(0xD2AF,0xD2AF,0xD2B2,False),(0xD2E2,0xD2E2,0xD2E5,True)))
    waits = iter(((0xD292,0xD295),(0xD2A8,0xD2AB),(0xD2BF,0xD2C2)))
    songs = iter(((0xD28B,0xD28F),(0xD2DE,0xD2E2)))
    updates = 0
    loaded = []
    input_wait_count = 0
    fade_count = 0
    interrupted = False
    def interrupt(stage):
        nonlocal interrupted
        if stage!=abort_stage: return
        assert not interrupted
        interrupted = True
        # Supply a control completion at this boundary; its record is retained by D17F.
        for memory in (expected,c.wram):
            target = memoryview(memory)[65536:]
            target[0x314] = 6
            put_word(target,current+10,0x4000)
            target[0x4000:0x4008] = bytes((0,0,6,0,0,0,0,0))
    def transition(mem,up):
        nonlocal updates,fade_count
        stage = ('fade-in','fade-out','final-fade')[fade_count]
        fade_count += 1
        step_updates = 0
        start,call,end,direction = next(fades)
        assert up==direction
        if start!=call:
            boot_image.run_until(c,0x7E0000|start)
            c.step()
        boot_image.run_until(c,0x7E0000|call)
        compare(c.wram,mem,'parent map before fade')
        if abort_updates==0: interrupt(stage)
        c.step()
        def apply(image):
            boot_ppu_queue.apply_shadow(memoryview(image)[65536:],image[0x603E:0x6072])
            boot_image.boundary_call(c,0xC18B)
            compare(c.wram,image,'title PPU shadow service')
            if step_updates==abort_updates: interrupt(stage)
        model = (boot_parent_transition.fade_in if up else boot_parent_fade.fade)(mem,0x7F8,apply)
        while True:
            try: node,value = next(model)
            except StopIteration as done:
                _,result = done.value
                break
            if c.PC in (0xD236,0xD203): c.step()
            boot_image.run_until(c,0x7ED236 if up else 0x7ED203)
            compare(c.wram,mem,('title fade',up,value))
            assert c.X==node
            updates += 1
            step_updates += 1
        boot_image.run_until(c,0x7E0000|end)
        compare(c.wram,mem,'title fade return')
        return result
    def wait(mem,delay,stack):
        nonlocal input_wait_count
        if delay==1:
            start,end = 0xD267,0xD26A
            input_wait_count += 1
        else: start,end = next(waits)
        boot_image.run_until(c,0x7E0000|start)
        interrupt({1:'input',0x7FFF:'phase',0x10E:'hold',30:'map-wait'}[delay])
        result = boot_parent_dispatch.dispatch(memoryview(mem)[65536:],delay,stack)
        c.step()
        boot_image.run_until(c,0x7E0000|end)
        compare(c.wram,mem,('title timed wait',delay))
        return result
    def song(mem,identity,p2,p3):
        start,end = next(songs)
        mem[0x1E00:0x1E04] = bytes((1,identity,p2,p3))
        boot_image.run_until(c,0x7E0000|start)
        compare(c.wram,mem,('title song request',identity))
        c.step()
        boot_image.run_until(c,0x7E0000|end,limit=50_000_000)
        mem[0x1E00] = 0
        compare(c.wram,mem,('title native music loader return',identity))
        loaded.append(identity)
    title_sequence(expected,0x7FD,wait,transition,song)
    boot_image.run_until(c,0x7EFFFE)
    compare(c.wram,expected,'complete title-parent return')
    assert (c.D,c.DB,c.S,c.M,c.XF)==(0x300,0x7F,0x7FF,1,0)
    stages = {'fade-in':(0,abort_updates,0),'input':(0,15,1),
              'phase':(1,15,input_waits),'hold':(1,15,input_waits),
              'fade-out':(1,15+abort_updates,input_waits),'map-wait':(1,30,input_waits),
              'final-fade':(2,30+abort_updates,input_waits)}
    song_count,update_count,wait_count = stages[abort_stage] if abort_stage else (2,45,input_waits)
    assert loaded==[0x2D,0x2C][:song_count] and updates==update_count
    assert interrupted==bool(abort_stage)
    assert bank[0x317]==(0 if abort_stage else 1) and bank[0x311]==2 and bank[0x312]==(0 if abort_stage else 3)
    assert input_wait_count==wait_count and word(bank,current+10)==0
    if abort_stage:
        assert bank[0x314]==0 and bank[0x4002]==6
    return dict(verified=True,abort_stage=abort_stage,updates_before_abort=abort_updates if abort_stage in ('fade-in','fade-out','final-fade') else None,input_wait_calls=input_wait_count,compared_ppu_updates=updates,executed_song_ids=loaded,final_task_ids=dict(image=bank[0x311],text=bank[0x312]),comparison='WRAM outside music-loader private variables1E04-1FFF and caller stack0740-07FF at every wait/fade/music/map boundary and final return; request bytes, descriptor/queue effects and restored caller state',scope='continuous original D23E success/control-abort paths; native music loader and real SPC driver execute where reached; parent higher priority than children, preloaded completion/phase/timer records, control record supplied at selected boundary, explicit C18B service; child execution and physical IRQ/video/audio timing open; music workspace not reconstructed by parent model')


def main():
    rom = romio.rom_from_argv()
    runs = [validate(rom,1),validate(rom,2)]
    for stage in ('fade-in','input','phase','hold','fade-out','map-wait','final-fade'):
        for count in ((0,7,14) if stage in ('fade-in','fade-out','final-fade') else (0,)):
            runs.append(validate(rom,abort_stage=stage,abort_updates=count))
    report = dict(verified=all(r['verified'] for r in runs),cases=dict(complete_parent_sequence=2,control_abort=13),runs=runs)
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
