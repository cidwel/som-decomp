"""Dump complete maps of Secret of Mana (USA) to JSON: the tile layers, attribute entries, tilemap words, palette and characters built by the game's own loader
(map_env.py) plus the static tables (map_tables.py): header, object records, event list, trigger tiles with the transitions they lead to, entries into the map, music.
usage: map_dump.py ROM MAP [MAP ...] OUTDIR [--state STATE]       writes OUTDIR/map_<id>.json
       map_dump.py ROM first-rooms [START_MAP]                      prints the maps reachable from the new-game start (breadth first) with size, music, monsters, exits
library: export(rom, env, tables, map_id) -> dict
Trigger tiles: a tile id >= `trigger_base` (0xC0 - (header byte 3 & 3)) in layer 1 starts event list entry `(id - trigger_base) + entry` of the map (docs/maps.md)."""
import sys, os, json, base64
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, event_vm, map_env, map_tables, map_native

EXIT_CODES = {0: None, 1: 'up', 2: 'down', 3: 'right', 4: 'left'}


def entry_music(rom, ev, seen=None, depth=0):
    seen = set() if seen is None else seen
    if ev in seen or depth > 6 or ev > 0x7FF: return []
    seen.add(ev)
    out = []
    for c in event_vm.decode_event(rom, ev)[1]:
        n = c.get('name')
        if n == 'SOUND' and c['params']['cmd'] == 1: out.append(c['params']['id'])
        elif n in ('GOTO_EVENT', 'CALL_EVENT'): out += entry_music(rom, c['params']['target_event'], seen, depth + 1)
    return out


def run_changes(rom, ev, flags=None, depth=0, what='MAP_CHANGE'):
    """Map transitions (or, with what='MUSIC', music ids) an event requests in order, following GOTO/CALL and IF_FLAG_RANGE with the given flag
    values (default all zero)."""
    flags = flags or {}
    if depth > 12 or not 0 <= ev < 0x800:
        return [ev - 0x800] if 0x800 <= ev < 0xC00 and what == 'MAP_CHANGE' else []
    out = []
    cmds = event_vm.decode_event(rom, ev)[1]
    i = 0
    while i < len(cmds):
        c = cmds[i]
        n = c['name']
        if n == 'IF_FLAG_RANGE':
            p = c['params']
            if not (p['lo'] <= flags.get(p['flag'], 0) <= p['hi']):
                i += 2
                continue
        elif n == 'MAP_CHANGE' and what == 'MAP_CHANGE':
            out.append(c['params']['transition'])
        elif n == 'SOUND' and what == 'MUSIC' and c['params']['cmd'] == 1:
            out.append(c['params']['id'])
        elif n == 'GOTO_EVENT':
            return out + run_changes(rom, c['params']['target_event'], flags, depth + 1, what)
        elif n == 'CALL_EVENT':
            out += run_changes(rom, c['params']['target_event'], flags, depth + 1, what)
        elif n == 'END':
            break
        i += 1
    return out


_SCENES = None


def scene_exits(rom, tables, m):
    """Transitions that scripts perform right after bringing the party into map m (the room is part of a scene: map change in, script, map change out)."""
    global _SCENES
    if _SCENES is None:
        _SCENES = {}
        for ev in range(0x800):
            try:
                cmds = event_vm.decode_event(rom, ev)[1]
            except Exception:
                continue
            seq = [c['params']['transition'] for c in cmds if c['name'] == 'MAP_CHANGE']
            for a, b in zip(seq, seq[1:]):
                _SCENES.setdefault(tables.transition(a)['map'], []).append(dict(event=ev, enter=a, leave=b))
    return _SCENES.get(m, [])


def event_kind(rom, ev):
    """'transition' (0x800-0xBFF), 'exit_script' (a script that changes map without a flag test), 'gated' (flag tests), 'sign' (text only), 'script', 'other'."""
    if 0x800 <= ev < 0xC00: return 'transition'
    if ev >= 0x800: return 'other'
    names = [c['name'] for c in event_vm.decode_event(rom, ev)[1]]
    if any(n.startswith('IF_') for n in names): return 'gated'
    if 'MAP_CHANGE' in names: return 'exit_script'
    if names and names[0] == 'TEXT' and not any(n.startswith('ACTOR') or n == 'FLAG_SET' for n in names): return 'sign'
    return 'script'


def export(rom, env, tables, m, phases=0):
    entry = next((n for n in range(0x400) if tables.transition(n)['map'] == m), None)
    d = env.load(m, transition=entry)
    d['load_transition'] = entry
    nat = map_native.decode_layers(rom, m)
    d['layer1'] = map_native.apply_markers(nat['layer1'], d['attr1'])         # the loader's work buffer can be overwritten by object set-up, the pieces cannot
    d['layer2'] = map_native.apply_markers(nat['layer2'], d['attr2']) if nat['layer2'] else None
    d['width'], d['height'], d['width2'], d['height2'] = nat['width'], nat['height'], nat['width2'], nat['height2']
    info = tables.map_info(m)
    h = info['header']
    d['header'] = h
    if phases:
        d['phases'] = [dict(vram=base64.b64encode(v).decode(), palette=list(p)) for v, p in env.animation_phases(phases)]
    d['header_fields'] = dict(graphics_set=h[0] & 0x3F, tile_anim=bool(h[0] & 0x40), scroll_anim=bool(h[0] & 0x80), palette_set=h[1] & 0x7F, palette_anim=bool(h[1] & 0x80),
                              tileset=h[2] & 0x3F, flags=h[3], entry_event_present=bool(h[3] & 4), object_palettes=h[7])
    d['trigger_base'] = info['trigger_base']
    d['entry_event'] = info['entry_event']
    d['events'] = info['events']
    d['pieces'] = info['pieces']
    d['music'] = entry_music(rom, info['entry_event']) if info['entry_event'] is not None else []
    d['objects'] = info['objects']
    base = info['trigger_base']
    pos, pos2 = {}, {}
    for y, row in enumerate(d['layer1']):
        for x, t in enumerate(row):
            if t >= base: pos.setdefault(t, []).append((x, y))
    for y, row in enumerate(d['layer2'] or []):
        for x, t in enumerate(row):
            if t >= base: pos2.setdefault(t, []).append((x, y))
    trig = []
    for tid in sorted(set(t['tile_id'] for t in info['triggers']) | set(pos) | set(pos2)):
        ev = tables.trigger_event(m, tid)
        tr = [dict(n=n, **{k: v for k, v in tables.transition(n).items() if k != 'n'}) for n in sorted(set(tables.event_exits(ev)))]
        trig.append(dict(tile_id=tid, event=ev, transitions=tr, tiles=pos.get(tid, []), tiles2=pos2.get(tid, []), kind=event_kind(rom, ev)))
    d['triggers'] = trig
    d['entry_transitions'] = [tables.transition(n) for n in info['entry_transitions']]
    d['scene_exits'] = scene_exits(rom, tables, m)
    d['music_start'] = run_changes(rom, info['entry_event'], what='MUSIC') if info['entry_event'] is not None else []
    d['entry_changes'] = [tables.transition(n) for n in run_changes(rom, info['entry_event'])] if info['entry_event'] is not None else []
    d['entries'] = [dict(t, exit_code=EXIT_CODES.get(t['flags'] & 31, 'other'), layer=2 if t['byte2'] & 1 else 1)
                    for t in (tables.transition(n) for n in range(0x400)) if t['map'] == m]
    return d


def first_rooms(rom, start=256):
    t = map_tables.Tables(rom)
    seen, order, todo = {start}, [], [start]
    while todo:
        m = todo.pop(0)
        i = t.map_info(m)
        h = i['header']
        tr = set(i.get('entry_transitions', []))
        for x in i.get('triggers', []): tr |= set(x['transitions'])
        monsters = sorted({o['id'] for o in i['objects'] if o['id'] < 0x57})
        order.append((m, h, monsters, sorted((n, t.transition(n)['map']) for n in tr)))
        for n in tr:
            dst = t.transition(n)['map']
            if dst not in seen: seen.add(dst); todo.append(dst)
    return order


def main():
    rom = romio.rom_from_argv()
    if sys.argv[1] == 'first-rooms':
        for m, h, mon, ex in first_rooms(rom, int(sys.argv[2]) if len(sys.argv) > 2 else 256)[:40]:
            print(m, bytes(h).hex() if h else None, 'monsters', mon, 'exits', ex)
        return
    args = sys.argv[1:]
    state = None
    if '--state' in args:
        i = args.index('--state'); state = args[i + 1]; del args[i:i + 2]
    out = args[-1]; maps = [int(a, 0) for a in args[:-1]]
    os.makedirs(out, exist_ok=True)
    env = map_env.MapEnv(rom, state)
    tables = map_tables.Tables(rom)
    for m in maps:
        d = export(rom, env, tables, m)
        json.dump(d, open(os.path.join(out, 'map_%d.json' % m), 'w'))
        print(m, '%dx%d tiles' % (d['width'], d['height']), 'music', d['music'], 'objects', len(d['objects']), 'triggers', len(d['triggers']))


if __name__ == '__main__':
    main()
