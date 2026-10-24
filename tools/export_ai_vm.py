"""Export the decoded AI scripts of the ordinary monsters as JSON, for a game engine that interprets them.
usage: export_ai_vm.py ROM OUT.json [IDS]      IDS: comma list of ids and LO-HI ranges (default 0x00-0x53, the ids ai_vm.py models;
                                               the repository copy data/ai_vm_scripts.json is the default)
Script addresses ("pc") are offsets from the script base 0x104F15 of the ROM (the unit the game uses in obj+0x144). For every id the entry pc is
the word at ROM 0x100009 + 16 * id; the error handler restarts the script at entry + 3. One record per reachable instruction (the shared subroutine library
is exported once; "monsters" lists which pcs each id can reach):
  pc, op, name, kind, args (the argument bytes without the jump offset), length (the whole instruction including the jump offset), next (pc of the next
  instruction when the op falls through or returns here after a call), jump (pc jumped to when the condition holds / always for jmp), call (target of a call),
  yields ("always", "maybe" or "never": whether the op ends the AI step), emits (command bytes written to obj+0x140..0x143), and for the cast op "mp_cost"
  (the cost of the attack, a number of the attack table; also for the cast-on-a-side op EA). An undefined op (handler = error handler, e.g. 85) has
  no "next": the script restarts at the entry of the monster + 3.
The keys "entries", "code" (op, len, tgt = jump or call target or -1, args = the six bytes after the op, as ai_vm.py reads them) and "tables" (ROM tables
read outside the script: attack_cost = byte 0 of the attack record 0x102ADF + 0x40 * n used by op E9, flash_palette = byte 0x101000 + 12 * n used by op FC) are the
form read by a port of ai_vm.py; the other keys are the annotated form.
Semantics of every op: docs/monster-ai-opcodes.md; reference implementation: tools/ai_vm.py."""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, aidis, monster_model

HERO_ENTRY = 0x58EA      # AI script of the computer-controlled heroes (object ids 0x80-0x82), docs/hero-ai.md
NPC_ENTRY = 0x54CD       # wander script of most NPC kinds (object-table entry of ids >= 0x83 other than the hero-like ones), docs/npcs.md
ALWAYS = {0xE0, 0xE1, 0xE2, 0xE3, 0xED, 0xEF, 0xE9, 0xEA, 0xEE} | aidis.UNDEF
MAYBE = {0xDF, 0xF3, 0xF4, 0xE4, 0xE5, 0xE6, 0xE7, 0xFD, 0xFE, 0xBE, 0xBF, 0xE8}
EMITS = {0xE0: ['C1', 'arg1', 'arg2', 'arg3'], 0xE2: ['40', 'arg1'], 0xE3: ['C1', 'facing', 'arg1', 'arg2'], 0xED: ['43', 'arg1'], 0xEF: ['81', 'arg1', 'arg2'],
         0xE9: ['44', 'arg1'], 0xEA: ['44', 'arg1'], 0xEE: ['04'], 0xE8: ['02'], 0xDF: ['02'], 0xE1: ['01'], 0xF3: ['06'], 0xF4: ['07'],
         0xE4: ['C1', 'primary', 'arg1', 'arg2'], 0xE5: ['C1', 'primary(tgt2)', 'arg1', 'arg2'], 0xE6: ['C1', 'away primary', 'arg1', 'arg2'],
         0xE7: ['C1', 'away primary(tgt2)', 'arg1', 'arg2'], 0xFD: ['C1', 'alternate', 'arg1', 'arg2'], 0xFE: ['C1', 'away alternate', 'arg1', 'arg2'],
         0xBE: ['C1', 'cardinal', 'arg1', 'arg2'], 0xBF: ['C1', 'away cardinal', 'arg1', 'arg2']}


def export(rom, ids=None):
    ids = list(range(monster_model.LAST_ID + 1)) if ids is None else ids
    mons = {}; pcs = set()
    for mid in ids:
        entry = monster_model.entry_of(rom, mid)
        reach = sorted(monster_model.static_reach(rom, entry))
        mons[str(mid)] = dict(entry=entry, restart=entry + 3, pcs=reach)
        pcs |= set(reach)
    hero_reach = sorted(monster_model.static_reach(rom, HERO_ENTRY))
    mons['hero'] = dict(entry=HERO_ENTRY, restart=HERO_ENTRY + 3, pcs=hero_reach)
    pcs |= set(hero_reach)
    npc_reach = sorted(monster_model.static_reach(rom, NPC_ENTRY))
    mons['npc'] = dict(entry=NPC_ENTRY, restart=NPC_ENTRY + 3, pcs=npc_reach)
    pcs |= set(npc_reach)
    ins = []; used = set()
    for pc in sorted(pcs):
        op = rom[aidis.BASE + pc]
        ln, text, tgt, ft = aidis.decode(rom, pc)
        name, kind, _ = aidis.INFO[op]
        used.add(op)
        a = [rom[aidis.BASE + pc + 1 + i] for i in range(ln - 1)]
        d = dict(pc=pc, op=op, name=name, kind=kind)
        # arguments: count from the op family
        nargs = nargs_of(op)
        d['args'] = a[:nargs]
        d['length'] = ln
        if op == 0xFF: d['call'] = tgt; d['next'] = pc + ln
        elif op == 0x01: d['jump'] = tgt
        elif op == 0x00 or op in aidis.UNDEF: pass
        elif tgt is not None: d['jump'] = tgt; d['next'] = pc + ln
        else: d['next'] = pc + ln
        d['yields'] = 'always' if op in ALWAYS else 'maybe' if op in MAYBE else 'never'
        if op in EMITS: d['emits'] = EMITS[op]
        if op in aidis.UNDEF: d['emits'] = ['00']
        if op in (0xE9, 0xEA): d['mp_cost'] = rom[0x102ADF + a[1] * 0x40]
        ins.append(d)
    ops = {'%02X' % op: dict(name=aidis.INFO[op][0], kind=aidis.INFO[op][1], desc=aidis.INFO[op][2]) for op in sorted(used)}
    code = {}
    for d in ins:
        pc = d['pc']
        code[str(pc)] = dict(op=d['op'], len=d['length'], tgt=d.get('jump', d.get('call', -1)), args=[rom[aidis.BASE + pc + 1 + i] for i in range(6)])
    tables = dict(attack_cost={str(i): rom[0x102ADF + i * 0x40] for i in range(256)}, flash_palette={str(i): rom[0x101000 + 12 * i] for i in range(256)})
    return dict(entries={k: v['entry'] for k, v in mons.items()}, code=code, tables=tables, about='Decoded AI scripts of monsters 0x%02X-0x%02X' % (min(ids), max(ids)) + ' and of the AI heroes (key hero) and the NPC wander script (key npc) (tools/export_ai_vm.py). pc = offset from the script base 0x104F15. See docs/monster-ai-opcodes.md.',
                script_base='0x104F15', monsters=mons, instructions=ins, ops=ops)


def nargs_of(op):
    """number of argument bytes between the opcode and the jump offset"""
    if op in aidis.N0: return 0
    if op in aidis.N1: return 1
    if op in aidis.N3: return 3
    if op in aidis.N4: return 4
    return aidis.FIX.get(op, 1) - 1 if op != 0xFF else 0


def main():
    rom = romio.rom_from_argv(); out = sys.argv[1]
    d = export(rom, monster_model.parse_ids(sys.argv[2]) if len(sys.argv) > 2 else None)
    with open(out, 'w') as f: json.dump(d, f, separators=(',', ':'))
    print('%d instructions, %d ops, %d monsters -> %s' % (len(d['instructions']), len(d['ops']), len(d['monsters']), out))


if __name__ == '__main__':
    main()
