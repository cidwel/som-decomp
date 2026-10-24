"""Shops, prices and the item id space of the shop / ring menus.
usage: shops.py ROM STATE [OUT.json]
- item ids: 0x7B + armor row (rows 0-62: head 0-20, body 21-41, accessory 42-62), 0xBA + consumable (0-11)
- price table: range table D8:FB84 (start id, base row, pointer), price = word at pointer + 2 * (id - start), 0xFFFF = cannot be sold or bought
- shop lists: shop n (the argument of event command 0x2E, which calls $C0:0048 = buy) -> pointer word at D8:(word D8:FB80) + 2n, item ids up to 0xFF
- price shown ($C0:7CD4): buy ($1847 = 1) = price, doubled (16-bit) when $185B = 0x99; sell ($1847 = 2) = (price / 3) * 2; 0xFFFF stays
The check runs the real $C0:7CA5 for every id in buy, buy with $185B = 0x99 and sell mode and compares with the model. Numbers only are written."""
import sys, os, json, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, combat_env as ce, event_vm

def u16(rom, o): return struct.unpack_from('<H', rom, o)[0]

def price_of(rom, item_id):
    for i in range(4):
        start, base, ptr = (u16(rom, 0x18FB84 + 6 * i + k) for k in (0, 2, 4))
        if item_id >= start:
            return u16(rom, 0x180000 + ptr + 2 * (item_id - start))
    return None

def shown(price, mode, special):
    if price == 0xFFFF: return price
    if mode == 1: return (price * 2) & 0xFFFF if special else price
    if mode == 2: return (price // 3) * 2
    return price

def shops(rom):
    base = u16(rom, 0x18FB80)
    out = []
    for n in range(16):
        p = u16(rom, 0x180000 + base + 2 * n)
        ids = []
        while rom[0x180000 + p] != 0xFF:
            ids.append(rom[0x180000 + p]); p += 1
        out.append(dict(shop=n, items=[dict(id=i, kind='consumable' if i >= 0xBA else 'armor', index=i - 0xBA if i >= 0xBA else i - 0x7B, price=price_of(rom, i)) for i in ids]))
    return out

def shop_events(rom):
    found = []
    for ev in range(0x800):
        try:
            bank, ops = event_vm.decode_event(rom, ev)
        except Exception:
            continue
        for o in ops:
            if o['op'] in ('2E', '0E', '0F'):
                arg = rom[event_vm.b24(bank << 16) + o['off'] + 1] if o['op'] == '2E' else None
                found.append(dict(event=ev, op=o['op'], shop=arg))
    return found

def main():
    rom = romio.rom_from_argv(); state = sys.argv[1]; outp = sys.argv[2] if len(sys.argv) > 2 else None
    env = ce.Env(rom, state); w = env.c.wram
    bad = n = 0
    for item in list(range(0x7B, 0xBA)) + list(range(0xBA, 0xC6)):
        for mode, special in ((1, False), (1, True), (2, False)):
            w[0x1847] = mode; w[0x185B] = 0x99 if special else 0
            env.call(0xC07CA5, A=item, m=0, x=0, DB=0, long=False)
            got = w[0x1822] | w[0x1823] << 8
            exp = shown(price_of(rom, item), mode, special)
            n += 1
            if got != exp:
                bad += 1
                if bad < 5: print('MISMATCH id %02X mode %d special %s rom %d model %d' % (item, mode, special, got, exp))
    print('price routine: %d cases, %d mismatches' % (n, bad))
    sh = shops(rom); ev = shop_events(rom)
    print('shops:', [(s['shop'], len(s['items'])) for s in sh])
    print('events that open a shop (0x2E buy, 0x0E sell, 0x0F third mode):', ev)
    if outp:
        json.dump(dict(source='tools/shops.py: D8:FB80 shop list pointers, D8:FB84 price ranges, $C0:7CD4 shown price; item ids 0x7B + armor row, 0xBA + consumable',
                       sell_rule='(price / 3) * 2', buy_special='price * 2 (16-bit) when $185B == 0x99', shops=sh, shop_events=ev), open(outp, 'w'), indent=1)

if __name__ == '__main__':
    main()
