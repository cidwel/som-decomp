"""Recovered task wakeup, id lookup, pending-record delivery and registration states.
usage: boot_wait.py ROM [--json OUT.json]
"""
import sys,json,random,romio,boot_decode,boot_tasks,boot_pool,cpu65816 as cpu

word,put_word = boot_tasks.word,boot_tasks.put_word

def wake(mem,node):
    """$7E:AC69: move a status-04 task from waiting to ready, or mark missing as 80."""
    if mem[node+2]!=4: return
    previous = 0xA2
    while word(mem,previous)!=node:
        previous = word(mem,previous)
        if not previous:
            mem[node+2] = 0x80
            return
    put_word(mem,previous,word(mem,node))
    mem[node+2] = 2
    boot_tasks.enqueue(mem,node)

def find_task(mem,task_id):
    """$7E:AD02: first matching id among twenty records, with no status check."""
    task_id &= 255
    if not task_id: return 0
    base = word(mem,0x9C)
    for node in range(base,base+20*16,16):
        if mem[node+4]==task_id: return node
    return 0

def deliver_record(mem,record,task_id):
    """$7E:B2AB: prepend a record to the addressed task's pending chain, waking if empty."""
    put_word(mem,record,0)
    node = find_task(mem,task_id)
    if not node: return 0
    old = word(mem,node+10)
    put_word(mem,node+10,record)
    if old in (0,0xFFFF): wake(mem,node)
    else: put_word(mem,record,old)
    return 255

def append_record(mem,record,task_id):
    """$7E:B258: deliver to an empty task or append to its zero-terminated chain."""
    put_word(mem,record,0)
    node = find_task(mem,task_id)
    if not node: return 0
    old = word(mem,node+10)
    if old in (0,0xFFFF):
        put_word(mem,node+10,record)
        wake(mem,node)
    else:
        while word(mem,old): old = word(mem,old)
        put_word(mem,old,record)
    return 255

def notify_registration(mem,registration):
    """$7E:CC8C: append an FF-tagged record with the registration pointer as payload."""
    record = boot_pool.allocate(mem)
    put_word(mem,record+4,registration)
    mem[record+2] = 255
    append_record(mem,record,mem[registration+1])
    mem[registration] = 1

def tick_registrations(mem,vertical):
    """$7E:CCB7: decrement waiting timers while latched vertical low byte is below DE."""
    base = word(mem,0x302)
    remaining = 32
    for node in range(base,base+32*4,4):
        if next(vertical)&255>=0xDE: break
        if mem[node]==2:
            timer = (word(mem,node+2)-1)&0xFFFF
            put_word(mem,node+2,timer)
            if not timer: notify_registration(mem,node)
        remaining -= 1
    mem[0x304] = remaining


def finish_registrations(mem):
    """$7E:CD05: scan the deferred timer suffix without the PPU counter check."""
    remaining = word(mem,0x304)
    base = word(mem,0x302)+(32-remaining)*4
    for node in range(base,base+remaining*4,4):
        if mem[node]==2:
            timer = (word(mem,node+2)-1)&0xFFFF
            put_word(mem,node+2,timer)
            if not timer: notify_registration(mem,node)


def allocate_registration(mem,owner):
    """$7E:CB86: first inactive four-byte registration; preserve its payload word."""
    base = word(mem,0x302)
    for node in range(base,base+32*4,4):
        if not mem[node]:
            mem[node],mem[node+1] = 1,owner&255
            return node
    return 0

def mark_waiting(mem,node):
    """$7E:CC57: status 2 only when the registration payload word is nonzero."""
    mem[node] = 2 if word(mem,node+2) else 1

def mark_ready(mem,node):
    """$7E:CC43 and CC78: set only the registration's status byte to 1."""
    mem[node] = 1

def validate(rom):
    cpu.set_rom(rom)
    image,_ = boot_decode.decode(rom,boot_decode.BOOT_SOURCE,boot_decode.BOOT_DEST)
    rng = random.Random(0xAC69)
    cases = dict(wake=0,find_task=0,deliver_record=0,append_record=0,allocate_registration=0,mark_waiting=0,mark_ready=0)
    addresses = dict(wake=0xAC69,find_task=0xAD02,deliver_record=0xB2AB,append_record=0xB258,
                     allocate_registration=0xCB86,mark_waiting=0xCC57)
    for trial in range(240):
        memory = bytearray(rng.randbytes(0x10000))
        put_word(memory,0x9C,0x600)
        for i in range(20): memory[0x600+16*i+4] = 2+i
        node = 0x600+(trial%20)*16
        waiting = [0x600+i*16 for i in range(trial%20) if 0x600+i*16!=node]
        if trial%5==0: waiting = []
        elif trial%5 in (1,2,3):
            position = (0,len(waiting)//2,len(waiting))[trial%5-1]
            waiting.insert(position,node)
        put_word(memory,0xA2,waiting[0] if waiting else 0)
        for i,at in enumerate(waiting):
            put_word(memory,at,waiting[i+1] if i+1<len(waiting) else 0)
        ready = [0x900+i*16 for i in range(trial%12)]
        priorities = sorted(rng.randrange(256) for _ in ready)
        put_word(memory,0xA0,ready[0] if ready else 0)
        for i,at in enumerate(ready):
            memory[at+3] = priorities[i]
            put_word(memory,at,ready[i+1] if i+1<len(ready) else 0)
        memory[node+2] = (4,4,1,2,8,16,0x80)[trial%7]
        put_word(memory,node+10,(0,0xFFFF,0x2408)[trial%3])
        put_word(memory,0x2408,0)
        put_word(memory,0x302,0x4000)
        for i in range(32): memory[0x4000+4*i] = 1
        free_index = trial%33
        if free_index<32: memory[0x4000+4*free_index] = 0
        put_word(memory,0x4002,0 if trial%2 else rng.randint(1,65535))
        task_id = (0,1,memory[node+4],255)[trial%4]
        owner = rng.randrange(256)
        for name in cases:
            expected = memory[:]
            if name=='wake': wake(expected,node)
            elif name=='find_task': result = find_task(expected,task_id)
            elif name=='deliver_record': result = deliver_record(expected,0x2400,task_id)
            elif name=='append_record': result = append_record(expected,0x2400,task_id)
            elif name=='allocate_registration': result = allocate_registration(expected,owner)
            elif name=='mark_waiting': mark_waiting(expected,0x4000)
            else: mark_ready(expected,0x4000)
            c = cpu.CPU()
            c.wram[:0x10000] = image
            c.wram[0x10000:] = memory
            c.DB = rng.randrange(256)
            address = addresses.get(name,(0xCC43,0xCC78)[trial%2])
            a = owner if name=='allocate_registration' else task_id
            x = node if name=='wake' else 0x2400 if name in ('deliver_record','append_record') else 0x4000
            boot_tasks.call(c,address,A=a|(rng.randrange(256)<<8),X=x)
            assert c.wram[0x10000:]==expected,(name,trial)
            if name in ('find_task','allocate_registration'): assert c.X==result,(name,trial,c.X,result)
            if name in ('deliver_record','append_record'): assert c.A&255==result,('delivery result',trial,c.A,result)
            cases[name] += 1
    cases['notify_registration'] = cases['tick_registrations'] = 0
    cases['finish_registrations'] = cases['split_timer_scan'] = 0
    class TimerCpu(cpu.CPU):
        def rd8(self,address):
            if address in (0x2137,0x213D): return self.hwread(address)
            return super().rd8(address)
        def hwread(self,address):
            if address==0x2137:
                self.vertical = next(self.scanlines)
                self.vertical_high = False
                return 0
            if address==0x213D:
                value = self.vertical>>8 if self.vertical_high else self.vertical&255
                self.vertical_high = not self.vertical_high
                return value
            return super().hwread(address)
    for trial in range(160):
        memory = bytearray(rng.randbytes(0x10000))
        put_word(memory,0x9C,0x600)
        put_word(memory,0x9E,0 if trial%2 else 0x600)
        put_word(memory,0x302,0x4000)
        put_word(memory,0x2C6,0x2400)
        put_word(memory,0xA0,0)
        waiting = []
        for i in range(20):
            node = 0x600+16*i
            memory[node+4] = 2+i
            memory[node+2] = 4 if i%2 else 1
            if i%2: waiting.append(node)
            put_word(memory,node+10,0 if i%3 else 0x2800+8*i)
            put_word(memory,0x2800+8*i,0)
        put_word(memory,0xA2,waiting[0])
        for i,node in enumerate(waiting): put_word(memory,node,waiting[i+1] if i+1<len(waiting) else 0)
        for i in range(40): put_word(memory,0x2400+8*i,0x2400+8*(i+1) if i<39 else 0)
        for i in range(32):
            node = 0x4000+4*i
            memory[node] = (0,1,2,2,0x80)[(i+trial)%5]
            memory[node+1] = (0,1,2+i%20,255)[(i+trial)%4]
            put_word(memory,node+2,(0,1,2,65535)[(i+trial)%4])
        for name,address in (('notify_registration',0xCC8C),('tick_registrations',0xCCB7),('finish_registrations',0xCD05),('split_timer_scan',0xCCB7)):
            expected = memory[:]
            processed = trial%33
            # High counter byte is ignored by the original CMP; compare controlled low-byte sequences.
            vertical = [rng.randrange(256)<<8|rng.randrange(222) for _ in range(processed)]
            if processed<32: vertical.append(rng.randrange(256)<<8|rng.randint(222,255))
            if name=='notify_registration': notify_registration(expected,0x4000)
            elif name=='finish_registrations':
                put_word(memory,0x304,32-processed)
                put_word(expected,0x304,32-processed)
                finish_registrations(expected)
            else:
                tick_registrations(expected,iter(vertical))
                if name=='split_timer_scan': finish_registrations(expected)
            c = TimerCpu()
            c.scanlines = iter(vertical)
            c.wram[:0x10000] = image
            c.wram[0x10000:] = memory
            c.DB = 0x7F if name=='notify_registration' else rng.randrange(256)
            boot_tasks.call(c,address,X=0x4000)
            if name=='split_timer_scan': boot_tasks.call(c,0xCD05)
            assert c.wram[0x10000:]==expected,(name,trial)
            cases[name] += 1
    return {'cases':cases,'verified':True,'comparison':'entire bank 7F; lookup/allocation X, delivery A low byte',
            'scope':'valid acyclic ready/waiting lists and record pointers; registration base 4000, task base 0600; timer scanner receives specified latched counter reads, not hardware timing'}

def main():
    report = validate(romio.rom_from_argv())
    if '--json' in sys.argv:
        with open(sys.argv[sys.argv.index('--json')+1],'w') as f:
            json.dump(report,f,indent=2)
            f.write('\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__': main()
