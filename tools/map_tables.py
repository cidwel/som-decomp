"""Static map tables of Secret of Mana (USA): map header and object records, event lists, transition (exit/entry) table, tile piece lists.
All tables are in bank $C8 (ROM offset 0x080000): $C8:7000 map -> header/object pointer, $C8:5000 map -> tile piece list, $C8:4000 map -> event list,
$C8:3000 transition -> (map, start tile, flags). Nothing is stored: every function reads the ROM given on the command line.
usage: map_tables.py ROM list                 one line per map that has a header (id, size of the first piece, header bytes, counts)
       map_tables.py ROM map ID [ID ...]      header, objects, events and exits of the maps as JSON on stdout
       map_tables.py ROM trans [N ...]        transition table entries
       map_tables.py ROM graph START_MAP      maps reachable from START_MAP through exits (event lists, scripts)
library: Rom(rom).map(id) -> dict"""
import sys, os, json, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, event_vm

B8 = 0x080000          # ROM offset of bank $C8
N_MAPS = 0x200


class Tables:
    def __init__(self, rom):
        self.rom = rom

    def w(self, a): return struct.unpack_from('<H', self.rom, B8 + a)[0]
    def b(self, a): return self.rom[B8 + a]

    def obj_ptr(self, m): return self.w(0x7000 + 2 * m)
    def piece_ptr(self, m): return self.w(0x5000 + 2 * m)
    def event_ptr(self, m): return self.w(0x4000 + 2 * m)

    def header(self, m):
        """8 header bytes of a map, or None if the map has no header of its own (its pointer equals the previous one, or the next map's)."""
        p = self.obj_ptr(m)
        if m + 1 < N_MAPS and self.obj_ptr(m + 1) < p + 8: return None
        h = list(self.rom[B8 + p:B8 + p + 8])
        return None if h == [255] * 8 else h              # map 511 is the end marker of the table

    def objects(self, m):
        p = self.obj_ptr(m)
        n = (self.obj_ptr(m + 1) - p - 8) // 8
        out = []
        for i in range(n):
            r = self.rom[B8 + p + 8 + 8 * i:B8 + p + 16 + 8 * i]
            out.append(dict(index=i, flag=r[0], flag_min=r[1] >> 4, flag_max=r[1] & 15, tile_x=r[2] & 0x7F, tile_y=r[3] & 0x7F,
                            facing=('up', 'down', 'left', 'right')[r[4] >> 6], layer=(r[4] >> 4) & 3, bit3=(r[4] >> 3) & 1, low3=r[4] & 7,
                            id=r[5], event_word=r[6] | r[7] << 8, raw=r.hex()))
        return out

    def events(self, m):
        a, b = self.event_ptr(m), self.event_ptr(m + 1)
        return [self.w(a + 2 * i) for i in range((b - a) // 2)]

    def pieces(self, m):
        """Tile piece list of a map: 5-byte records, with a 0xFE (layer 1) or 0xFF (layer 2) prefix byte on the first piece of each layer."""
        a, b = self.piece_ptr(m), self.piece_ptr(m + 1)
        out = []
        while a < b:
            pre = None
            if self.b(a) >= 0xFE: pre = self.b(a); a += 1
            r = [self.b(a + i) for i in range(5)]
            out.append(dict(prefix=pre, flag=r[0], flag_min=r[1] >> 4, flag_max=r[1] & 15, x=r[3] >> 1, y=r[4] >> 1,
                            piece=r[2] | (r[3] & 1) << 8 | (r[4] & 1) << 9, raw=bytes(r).hex()))
            a += 5
        return out

    def transition(self, n):
        o = B8 + 0x3000 + 4 * n
        w0 = self.rom[o] | self.rom[o + 1] << 8
        return dict(n=n, map=w0 & 0x1FF, tile_x=self.rom[o + 1] >> 1, tile_y=self.rom[o + 2] >> 1, byte2=self.rom[o + 2], flags=self.rom[o + 3])

    def event_exits(self, ev, seen=None, depth=0):
        """Transitions reached by event ev (id < 0x800: MAP_CHANGE commands of the script and of the events it jumps to or calls; 0x800-0xBFF: that transition)."""
        seen = set() if seen is None else seen
        if ev in seen or depth > 8: return []
        seen.add(ev)
        if 0x800 <= ev < 0xC00: return [ev - 0x800]
        if ev >= 0xC00 or ev > 0x7FF: return []
        out = []
        for c in event_vm.decode_event(self.rom, ev)[1]:
            nm = c.get('name')
            if nm == 'MAP_CHANGE': out.append(c['params']['transition'])
            elif nm in ('GOTO_EVENT', 'CALL_EVENT'): out += self.event_exits(c['params']['target_event'], seen, depth + 1)
        return out

    def trigger_event(self, m, tile_id):
        """Event of a trigger tile id: the game indexes the word list without a bound, so a map with a short (or empty) list reads the next map's words."""
        h = self.header(m)
        return self.w(self.event_ptr(m) + 2 * ((tile_id - (0xC0 - (h[3] & 3))) + ((h[3] & 4) >> 2)))

    def map_info(self, m):
        h = self.header(m)
        ev = self.events(m)
        info = dict(map=m, header=h, objects=self.objects(m), events=ev, pieces=self.pieces(m))
        if h:
            first = (h[3] & 4) >> 2                          # bit 2 of header byte 3: the first event word is the map entry event
            base = 0xC0 - (h[3] & 3)                         # first trigger tile id
            info.update(entry_event=ev[0] if first and ev else None, trigger_base=base)
            info['triggers'] = [dict(tile_id=base + i, event=e, transitions=sorted(set(self.event_exits(e)))) for i, e in enumerate(ev[first:])]
            info['entry_transitions'] = sorted(set(self.event_exits(ev[0]))) if first and ev else []
        return info


def main():
    rom = romio.rom_from_argv()
    t = Tables(rom)
    cmd = sys.argv[1]
    if cmd == 'list':
        for m in range(N_MAPS):
            h = t.header(m)
            if not h: continue
            ps = t.pieces(m)
            print(m, 'hdr', bytes(h).hex(), 'pieces', len(ps), 'objs', len(t.objects(m)), 'events', len(t.events(m)))
    elif cmd == 'map':
        print(json.dumps([t.map_info(int(a, 0)) for a in sys.argv[2:]], indent=1))
    elif cmd == 'trans':
        for n in (map(lambda a: int(a, 0), sys.argv[2:]) or range(0x400)):
            print(t.transition(n))
    elif cmd == 'graph':
        start = int(sys.argv[2], 0)
        seen = {start}; todo = [start]
        while todo:
            m = todo.pop(0)
            i = t.map_info(m)
            tr = set(i.get('entry_transitions', []))
            for x in i.get('triggers', []): tr |= set(x['transitions'])
            print(m, '->', sorted((n, t.transition(n)['map']) for n in tr))
            for n in tr:
                d = t.transition(n)['map']
                if d not in seen: seen.add(d); todo.append(d)


if __name__ == '__main__':
    main()
