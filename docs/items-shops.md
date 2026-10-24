# Items, prices and shops

Tags as in `docs/rom-combat.md`. Tool: `tools/shops.py` (runs the real price routine for every item id in every mode and compares it with the model, dumps the 16 shop lists). Data: `data/shops.json`, `data/prices.json`, `data/armors.json`, `data/weapons.json`, `data/items.json`, `data/item_effects.json`.

## 1. Item ids of the shop and ring menus [V]
- **Armor**: id = `0x7B + row` (rows of `data/armors.json`: head 0-20, body 21-41, accessory 42-62; row 0, 21 and 42 are "nothing"). The inventory byte `$CC00 + slot` holds the row in its low 6 bits (`$C0:7B44`).
- **Consumables**: id = `0xBA + k`, k = 0 Candy, 1 Chocolate, 2 Royal Jam, 3 Faerie Walnut, 4 Medical Herb, 5 Cup of Wishes, 6 Magic Rope, 7 Flammie Drum, 8 Moogle Belt, 9 Midge Mallet, 10 Barrel, 11 (unused) (inventory bytes from `$CC48`, low 5 bits, `$C0:7B52`). Effects: `docs/rom-combat.md` section 16.
- Weapons are not sold; the weapon of each type is upgraded with orbs (`docs/rom-combat.md` 11.4).
- The name strings of the text block (`tools/names.py`, events 0x800-0x94E) are one entry earlier for armor: name index `0x7A + row`.

## 2. Prices [V: 225 of 225 cases]
`$C0:7CA5`: the range table `D8:FB84` has four entries (start id, base row, pointer): 0xBA consumables, 0xA5 accessories, 0x90 bodies, 0x7B heads; price = word at `D8:pointer + 2 * (id - start)`, 0xFFFF = cannot be bought or sold (Magic Rope, Flammie Drum, Moogle Belt, Midge Mallet, item 11). The shown price `$C0:7CD4` depends on the menu mode `$1847`:
| mode | entry | price |
|---|---|---|
| 1 buy | `$C0:0048` (`$C0:6617`) | the table price; doubled (16-bit, so it wraps above 32767) when `$185B` = 0x99 |
| 2 sell | `$C0:004B` (`$C0:663E`) | `(price / 3) * 2` (two thirds, the division done by the hardware divider) |
| 3 | `$C0:004E` (`$C0:6653`) | the table price |
`$185B` is written by `$D0:CDBD` with the object kind (`+0x180`) of the object whose offset the shop entry `$C0:66AE` stores in `$183E` (the NPC that runs the event), so **the buy price is doubled when the shopkeeper is object kind 0x99** [C]. In the rooms built so far the only kind-0x99 shopkeeper is the record 0 of map 279 (event 0x99, shop 1, the travelling merchant); the other shopkeepers are kind 0xCF (normal price).

## 3. Shop lists [V static, C for the event]
The buy menu takes the shop number from the event command 0x2E (`JSL $C0:0048` with Y = argument, `$1840` = Y); `$C0:6AC7` reads the list pointer at `D8:(word D8:FB80) + 2 * n`, and the list is the item ids up to 0xFF. There are **16 shops** (0-15). Event 0x312 is the dispatch: sixteen pairs `IF_FLAG_RANGE 0xFA n..n` + `ACTOR_FX 2E n`, then on to 0x522, so the shop number is event flag 0xFA, which the talk event of each shopkeeper sets with `FLAG_SET 0xFA n` before jumping to 0x310 / 0x312: events 0x300-0x30F set n = 0-15 in order (0x300 also checks story flags first), 0x0DB sets 2 and 0x318 sets 12. Which NPC record reaches which shop is computed from the rooms by the remake's event exporter (`shops_by_npc()` of `rom_event_runner.gd`: map 257 record 6 shop 0, map 261 records 0/1 shops 2/5, map 279 record 0 shop 1) [C]. The lists (consumable k / armor row, price):

| shop | items |
|---|---|
| 0 | c0 c4 c5, head 1, body 22 |
| 1 | c0 c1 c2 c3 c4 c5 c10, head 1 2 3, acc 62 |
| 2 | c0 c4 c5, head 2, body 23, acc 62 |
| 3 | c0 c4 c5, head 2, body 25 27, acc 44 |
| 4 | c0 c4 c5, head 3 4, body 24 25 26, acc 62 44 45 |
| 5 | c0 c4 c5, head 4, body 26 27, acc 44 45 46 |
| 6 | c0 c1 c3 c4 c5, head 4 5, body 26 27, acc 45 46 |
| 7 | c0 c1 c3 c4 c5, head 5 6, body 28, acc 47 |
| 8, 9 | c1 c3 c4 c5, head 7 8, body 29 30, acc 48 |
| 10 | c1 c3 c4 c5, head 7 8 9, body 29 30 31, acc 48 49 50 |
| 11 | c1 c3 c4 c5, head 9 10, body 31 32 33, acc 48 49 50 |
| 12 | c0 c1 c3 c4 c5, head 11, body 34, acc 51 |
| 13 | c1 c3 c4 c5, head 13 14 15, body 36 37, acc 53 54 |
| 14 | c0 c1 c2 c3 c4 c5, head 14 15, body 35 37, acc 52 54 |
| 15 | c0 c1 c2 c3 c4 c5 c10, head 16, body 38, acc 56 |
Prices per entry: `data/shops.json`.

## 4. Item data and how it is checked
| table | where | fields | checked by |
|---|---|---|---|
| armor rows (63) | `0x103ED0 + 10 * row` | flags (+5 Str/Agi/Con/Int by bits 4-1), defense, evade, magic defense, magic evade, equip mask (0x80 boy, 0x40 girl, 0x20 sprite), element resist, status immunity word | `tools/hero_stats.py` against 16 live hero objects [V] |
| player weapon rows (72 = 8 types x 9 grades) | `0x101000 + 12 * row` | type, stat codes (Agi/Con/Int/Wis/Str +0/+1/+5/-5), crit base, hit, power, status word and chance | `tools/hero_stats.py`, `tools/validate_phys.py` [V] |
| consumable effects | `$C0:54E7`, amount byte `0x104152 + 16 * id` | section 1 and `docs/rom-combat.md` section 16 | executed on a hero (`tools/dump_gap_tables.py`) [V] |
| prices | `D8:FB84` | section 2 | `tools/shops.py` [V] |
`tools/godot_vectors.py` exports the three row tables with their prices (`items`) for a port's tests.

## 5. Open
- The shop entry was read, not executed: the 0xFA dispatch and the kind-0x99 doubling are [C].
