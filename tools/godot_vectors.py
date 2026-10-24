"""Export test vectors for the Godot port: inputs and the results of the Python ROM models (validated against the real routines) for physical hits,
spell damage and healing, the hero stat build, EXP / level-up, weapon-level progress, status durations and monster drops.
usage: godot_vectors.py ROM OUT.json [N=200]
Every vector carries the 15-byte RNG state and index so a port can replay the same draws.  Numbers only: no ROM data other than gameplay numbers."""
import sys, os, json, random
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, rng as R, phys_model as P, magic_model as M, hero_stats as H, weapon_level as W

def rng_state(rnd):
    return [rnd.randrange(256) for _ in range(15)], rnd.randrange(15)

def phys_cases(rnd, n):
    out = []
    for _ in range(n):
        st, ix = rng_state(rnd)
        att_hero = rnd.random() < 0.5
        slot_att = rnd.choice([0, 1, 2]) if att_hero else rnd.choice([3, 4, 5])
        a = dict(E198=rnd.randrange(1, 255), E197=rnd.choice([75, 90, 99, rnd.randrange(30, 100)]), E196=rnd.choice([0, 3, 9, 27, rnd.randrange(60)]),
                 E19B=rnd.randrange(0, 9) if att_hero else 0, B0=rnd.choice([0, 0, 0x10, 0x20, 0x40, 0x80, 0x44]), B0w=0, E191=rnd.choice([0, 0, 0, 2]),
                 E190=rnd.choice([0, 0, 0, 4, 0x10]), AE=rnd.choice([0, 0, 0, 1, 5, 9, 0x10, 0x25]), ED=rnd.choice([0, 0, 0, 5, 30, 60, 99]),
                 E189=rnd.randrange(1, 100), E6=rnd.choice([0, 0, 8, 2]), E194=0, A2=0, A0=0, B1=0, BF=0, CC76=0, hero=att_hero)
        a['B0w'] = a['B0']
        d = dict(A4=rnd.choice([0, 20, 94, 99, rnd.randrange(100)]), A5=rnd.choice([0, 9, 200, 553, rnd.randrange(1000)]), B0=rnd.choice([0, 0, 1, 2, 4, 8, 5]), B0w=0,
                 E191=rnd.choice([0, 0, 0, 2]), E190=rnd.choice([0, 0, 0, 0x10]), E194=0, A2=0, A0=0, B1=rnd.choice([0, 0, 0, 0x10]), BF=rnd.randrange(0, 60), E6=0, hero=not att_hero)
        d['B0w'] = d['B0']
        m8f = rnd.choice([2, 2, 2, 1, 4])
        rg = R.Rng(st, ix)
        ev, df = P.def_terms(d)
        hit, acc = P.hit_test(a, ev, rg)
        dmg, crit = 0, False
        if hit:
            dmg, crit = P.damage(dict(a), d, m8f, acc, ev, df, rg, slot_att, att_hero)
        out.append(dict(rng=st, index=ix, a=a, d=d, m8f=m8f, slot_att=slot_att, hit=bool(hit), acc=acc, damage=dmg, crit=bool(crit)))
    return out

def spell_cases(rom, rnd, n):
    rows = []
    for sid in range(0x2A):
        o = 0x102AD0 + sid * 64
        rows.append(dict(id=sid, power=rom[o + 10], acc=rom[o + 11], elem=rom[o + 12], mp=rom[o + 15]))
    out = []
    for _ in range(n):
        st, ix = rng_state(rnd)
        row = rnd.choice(rows)
        hero = rnd.random() < 0.7
        c = dict(INT=rnd.randrange(1, 100), WIS=rnd.randrange(1, 100), E1FD=rnd.randrange(5, 60), E1FE=rnd.randrange(5, 60), E6=rnd.choice([0, 0, 8]))
        t = dict(MEV=rnd.choice([0, 20, 50, 99, rnd.randrange(100)]), MDEF=rnd.choice([0, 30, 150, rnd.randrange(400)]), RES=rnd.choice([0, 0, 1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80]),
                 WEAK=rnd.choice([0, 0, 1, 2, 4, 8, 0x10, 0x20]))
        level = rnd.randrange(0, 9)
        div = rnd.choice([1, 1, 2, 3])
        rg = R.Rng(st, ix)
        dmg, m8f = M.spell_damage(c, t, row, level, div, hero, rg)
        rg2 = R.Rng(st, ix)
        heal = M.heal_amount(c, t, row, level, div, hero, rg2)
        out.append(dict(rng=st, index=ix, row=row, caster=c, target=t, level=level, divisor=div, hero=hero, damage=dmg, m8f=m8f, heal=heal))
    return out

def monster_spell_cases(rom, rnd, per):
    """spells cast by ordinary monsters: caster stats, spell powers (record bytes 18/19) and magic level from the record, E1E6 = $CFFB = 0"""
    out = []
    for mid in range(0x57):
        o = 0x101C00 + mid * 29
        rec = rom[o:o + 29]
        c = dict(INT=rec[6], WIS=rec[7], E1FD=rec[18], E1FE=rec[19], E6=0)
        level = rec[26] & 15
        for _ in range(per):
            st, ix = rng_state(rnd)
            sid = rnd.randrange(0x2A)
            ro = 0x102AD0 + sid * 64
            row = dict(id=sid, power=rom[ro + 10], acc=rom[ro + 11], elem=rom[ro + 12])
            t = dict(MEV=rnd.choice([0, 30, 60, rnd.randrange(100)]), MDEF=rnd.choice([0, 50, 150, rnd.randrange(400)]), RES=rnd.choice([0, 0, 4, 0x10]), WEAK=rnd.choice([0, 0, 8, 0x20]))
            div = rnd.choice([1, 1, 3])
            dmg, m8f = M.spell_damage(c, t, row, level, div, False, R.Rng(st, ix))
            out.append(dict(monster=mid, rng=st, index=ix, row=row, target=t, level=level, divisor=div, damage=dmg))
    return out

def item_rows(rom):
    """armor rows (0x103ED0 + 10 * id), player weapon rows (0x101000 + 12 * id), consumable effect bytes (0x104152 + 16 * id) and prices"""
    import shops
    armors = []
    for i in range(63):
        r = rom[0x103ED0 + 10 * i:0x103ED0 + 10 * i + 10]
        armors.append(dict(row=i, flags=r[0], defense=r[1], evade=r[2], mdef=r[3], mev=r[4], equip=r[5], resist=r[6], immunity=r[7] | r[8] << 8, price=shops.price_of(rom, 0x7B + i)))
    weapons = []
    for i in range(72):
        r = rom[0x101000 + 12 * i:0x101000 + 12 * i + 12]
        weapons.append(dict(row=i, type=r[0], stat_a=r[1], stat_b=r[2], crit=r[6], hit=r[7], power=r[8], status=r[9] | r[10] << 8, chance=r[11]))
    consumables = [dict(id=k, effect=rom[0x104152 + 16 * k], price=shops.price_of(rom, 0xBA + k)) for k in range(12)]
    return dict(armors=armors, weapons=weapons, consumables=consumables)

def stat_cases(rom, rnd):
    weapons = [16, 26, 35, 44, 53, 62, 71, 8]
    heads = [-1, 20, 16]
    bodies = [-1, 38, 39, 41]
    accs = [-1, 43, 61]
    out = []
    for hero in range(3):
        for level in (0, 9, 29, 59, 79, 98):
            for _ in range(6):
                wp = rnd.choice(weapons)
                armors = (rnd.choice(heads), rnd.choice(bodies), rnd.choice(accs))
                ids = tuple(a if a >= 0 else {0: 0, 1: 21, 2: 42}[i] for i, a in enumerate(armors))
                human = rnd.random() < 0.5
                s = H.build(rom, hero, level, wp, ids, 0, None if human else rom[0x473F])
                out.append(dict(hero=hero, level=level + 1, weapon_row=wp, armors=list(armors), human=human, stats=s))
    return out

def exp_cases(rom, rnd, n):
    ex = [rom[0x104B58 + 3 * L] | rom[0x104B58 + 3 * L + 1] << 8 | rom[0x104B58 + 3 * L + 2] << 16 for L in range(99)]
    out = []
    for _ in range(n):
        level = rnd.choice([0, 1, 5, 40, 64, 97, 98]); exp0 = rnd.randrange(0, 40000); gain = rnd.choice([1, 12, 250, 4000, 12345, 9999999])
        e = min(exp0 + gain, 9999999); lv = level
        while lv < 98 and e >= ex[lv]: lv += 1
        out.append(dict(level=level + 1, exp=exp0, gain=gain, new_level=lv + 1, new_exp=e))
    return out

def weapon_cases(rnd, n):
    out = []
    for _ in range(n):
        caps = [rnd.randint(0, 8) for _ in range(8)]
        heroes = []
        for i in range(3):
            heroes.append(dict(type=rnd.randint(0, 7), level=rnd.randint(1, 98), alive=rnd.random() < 0.85,
                               nib=[rnd.randint(0, 8) << 4 | rnd.randint(0, 8) for _ in range(4)], prog=[rnd.randint(0, 98) for _ in range(8)]))
        killer = rnd.randint(0, 2)
        heroes[killer]['alive'] = True
        mon_level = rnd.randint(0, 120)
        before = json.loads(json.dumps(heroes))
        W.model_kill(heroes, caps, mon_level, killer)
        out.append(dict(caps=caps, monster_level=mon_level, killer=killer, before=before, after=heroes))
    return out

def status_cases(rnd, n):
    out = []
    for _ in range(n):
        v = rnd.choice([61, 100, 300, 999, rnd.randrange(0, 1000)]); md = rnd.choice([0, 50, 150, rnd.randrange(500)])
        d = (v >> 2) - (md >> 1)
        d = max(20, d & 0xFF) if d >= 0 else 20
        out.append(dict(value=v, mdef=md, units=d, ticks=4 * d - 3))
    return out

def drop_cases(rom, rnd, per):
    out = []
    tbl = list(rom[0x430D:0x4315])
    for mid in range(0x54):
        r = list(rom[0x103A50 + 5 * mid:0x103A50 + 5 * mid + 5])
        if r[0] == 0xFF: continue
        lvl = rom[0x101C00 + mid * 29]
        for _ in range(per):
            st, ix = rng_state(rnd)
            g = R.Rng(st, ix)
            a8 = (g.byte() & 0x3F) + 1
            drop = bool(r[0] & 0x40) or (r[0] & 0x3F) >= a8
            cls = None
            if drop:
                a4 = g.below(3)
                if lvl >= 10:
                    a4 = 2
                    if lvl >= 15: a4 = 3
                    if lvl >= 25: a4 = 4
                    if lvl >= 30: a4 = 5
                    if lvl >= 36:
                        a4 = 6
                        if g.byte() < 0x20: a4 = 7
                cls = tbl[a4]
            g2 = R.Rng(st, ix)
            rr = g2.byte() & 0x3F
            carry = rr >= ((r[2] >> 3) & 7); mode = r[2] >> 6
            kind, v = {0: ('gold', r[3] if carry else r[4]), 1: ('item', r[3] if carry else r[4]), 2: ('gold', r[3]) if carry else ('item', r[4]),
                       3: ('item', r[3]) if carry else ('gold', r[4])}[mode]
            out.append(dict(monster=mid, level=lvl, rng=st, index=ix, chest=drop, trap_class=cls, contents_kind=kind, contents_value=v, contents_rng=[st, ix]))
    return out

def magic_level_cases(rnd, n):
    """Spell-level progress of one first hit (validate_magic_level.model, checked against $D0:4DCD); $ED bit 7 set as in play."""
    import validate_magic_level as VM
    out = []
    for _ in range(n):
        L = rnd.randrange(9); prog = rnd.choice([rnd.randrange(100), 99, 95, 91]); cap = rnd.choice([0, 1, 3, 5, 7, 8, 8, 8])
        out.append(dict(level=L, progress=prog, cap=cap, out=list(VM.model(L, prog, cap, True))))
    return out


def main():
    rom = romio.rom_from_argv(); out = sys.argv[1]; n = int(sys.argv[2]) if len(sys.argv) > 2 else 200
    rnd = random.Random(20261006)
    data = dict(source='tools/godot_vectors.py: results of the validated Python models of docs/rom-combat.md',
                phys=phys_cases(rnd, n), spell=spell_cases(rom, rnd, n), stats=stat_cases(rom, rnd), exp=exp_cases(rom, rnd, 80),
                weapon_progress=weapon_cases(rnd, 150), status=status_cases(rnd, 60), drops=drop_cases(rom, rnd, 6), monster_spell=monster_spell_cases(rom, random.Random(77), 4), items=item_rows(rom), magic_level=magic_level_cases(random.Random(4), 300))
    json.dump(data, open(out, 'w'), separators=(',', ':'))
    print({k: len(v) for k, v in data.items() if isinstance(v, (list, dict))})

if __name__ == '__main__':
    main()
