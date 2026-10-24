# NPCs: spawn, wander script, talk and contact events

Tags as in `docs/rom-combat.md`. Map object records: `docs/maps.md` section 10 and `docs/cutscene-engine.md` section 5. Script addresses (pc) are offsets from ROM `0x104F15`, as in `docs/monster-ai-opcodes.md`.

## 1. Spawn [V]
- Records with object id >= 0x80 are NPC kinds. They go through the same spawner as monsters (`$C0:DE3B`): the record bytes +4/+5 are copied to `obj+0x3C/0x3D` and the event word +6/+7 to `obj+0x3E` (`$C0:DE5F`) [V: `obj+0x3E` holds the event word after the spawn for records 131#6, 128#0, 259#0].
- The AI entry is the object-table word at ROM `0x100009 + 16 * id`, as for monsters. Every NPC kind used in the first rooms has entry **0x54CD**, except 0x8A and 0x8B, which have the AI-hero entry 0x58EA (`docs/hero-ai.md`) [V: table read for the 33 kinds; spawned objects start at that pc].

## 2. The wander script (entry 0x54CD) [V]
- `54CD: CALL 6516` (var1 = random 0..3), then `54D0: CALL 6519; JMP 54D0`.
- `6519`: var3 = random 0..15. If var3 = 0: stand (`E0 dir,0,0x3C`: animation 0 for 60 frames) facing up / down / right / left by var1. Otherwise var0 = random 0..3 picks a direction and the routine at `655A / 6576 / 6592 / 65AE` walks it: up to 6 steps of `E0 dir,1,0x0A` (walk animation 1 for 10 frames); before each step `9D` compares the own position with the one saved by `9F`, and a step that did not move (blocked) ends the walk.
- Direction codes 1 right, 2 left, 4 down, 8 up. One step is 10 frames, so the AI is asked again every 10 frames while walking and after 60 frames when standing.
- Measured in the frame loop: walking moves 1 px per frame [V: NPC 0xC5 / 0xB7 / 0xC0, 600 frames]. The trace check: `tools/export_ai_traces.py ROM STATE OUT 0xC0 N` writes real-ROM steps of the script; 300 steps, 0 disagreements with `ai_vm.py`. `export_ai_vm.py` exports the script under the key `npc`.
- The 600-frame measurements above spawned the kinds at a fixed spot of the save state's map, not from their own records. With their real records many of these NPCs never run the script at all (next point).

### 2.1 Static NPCs: record byte +3 bit 7 switches the AI off [V]
- **Rule for the port: an object spawned from a map record runs its AI only when bit 7 of record byte +3 (the y tile byte) is 0.** With the bit set the object never leaves its entry pc: it keeps the spawn facing (record +4 bits 7-6), the spawn position and animation 0 for as long as the map is loaded. It can still be talked to (the talk scan `$C0:B851` does not test it). The bit is not part of the y tile (`tile_y = byte & 0x7F`).
- Code [C, read; the effect V below]: the record copy `$C0:DD55` builds the flags byte `$C807 + 16n = (rec[3] & 0x80) | ((rec[2] & 0x80) >> 1)`; the spawner copies it to `obj+0x44` (`$C0:DEC4`). The per-object step `$C0:F8B3` calls the AI (`JSL $01:D942` -> `$C1:0028` -> AI step `$C1:2552`) only when `$52 | $FF | $F1` = 0, `$E8` bit 2 = 0, `obj+0x00` bit 7 = 0, and, for slots 3+, **`obj+0x44` bit 7 = 0** and the object is not `$3A` (the NPC of the running talk event). Heroes (slots 0-2) are gated by `obj+0x0F`, `obj+0x191` bit 7 and `$4E` instead. The only other writer of `obj+0x44` is a block store at `$C2:A329`; no event command was found that changes it [C].
- `obj+0x44` bit 6 (record byte +2 bit 7, also masked off the x tile) exempts the object from the off-screen removal `$C0:FC2E` (an object more than 64 px outside the screen is otherwise removed or parked once `$BC` reaches 10, or 4 when `$ED` bit 7 is set) [C]. It does not affect the AI.
- Measured in the real frame loop, objects spawned by the game from their records (`load_map` of the transition, flags 0, `$D0`/`$F1` held at 0), 600 frames, hook on `$01:D942` [V]:

| map (transition) | record: kind, bytes +2/+3 | `obj+0x44` | AI calls | result |
|---|---|---|---|---|
| 128 (after the opening, event 0x106) | #0 0xD8 `9F BB` | C0 | 0 | pc stays 0x54CD; facing, position, animation unchanged for 1200 frames, also with the camera on it |
| 128 | #1 0xDB `9E 9B`, #2 0xD7 `9F BB` | - | - | bit 7 of +3 set: static by the rule (not spawned in this run) |
| 256 (0) | #0 0x8A, #1 0xC0 Elliott, #2 0xC1 Timothy, +3 = `88` | 80 | 0 | static |
| 131 (14) | #0 0xC0, #1 0xC1, #2 0xC9, #8 0xC7, #9 0xC4 (+3 bit 7 set) | C0 | 0 | static, pc 0x54CD |
| 131 | #6 0xCA `8A 15`, #7 0xC5 `94 1F` | 40 | 45 / 55 | walk (296 / 385 distinct states) |
| 144 (6) | #0 0xB7 `8C 95`, #5 0xB7 `AB 93` | C0 | 0 | static |
| 144 | #1 0xC4, #2 0xC5, #3 0xBC, #4 0xCA, +3 bit 7 clear | 40 | 52-60 | walk (357-539 states) |
| 257 (88) | 0xC5, 0xC6 (+3 bit 7 clear) | 40 | 55 / 60 | walk |
| 159 | all 9 records (0xCE, 0xD4-0xD6, 0xD9-0xDE) have +3 bit 7 set | - | - | static by the rule (record bytes only, not run) |
| 257, 259 (92) | 0xCF shop keepers (+3 bit 7 clear) | 40 / 00 | 44-45 | the script runs, but every walk is blocked: they only turn (4 states) |

- Port: export the bit per NPC. In `tools/build_rom_map.py` (Godot repo), `o["raw"]` of `map_tables.objects()` is the 8 record bytes as hex, so `static = int(o["raw"][6:8], 16) & 0x80 != 0`; set `wanders = entry == 0x54CD and not static`. Monster records carry the same bit (202 of 1717 monster records across the ROM have it) and the same gate applies to them, since they also sit in slots 3+ [C for monsters: same code path, not run].

## 3. Talk and contact [C]
Event word: low 12 bits = event id; **bits 12-14 of the high byte (`word >> 8 & 0x70`) = how it starts**.
- Talk scan `$C0:B851` (A button, hero in X, objects of slots 3+ in Y): only objects with `obj+0x3D` bit 7 (id >= 0x80) and no state (`obj+0x1C | obj+0x60` = 0). Type 0x40 allows a distance of 8 along the hero's facing, types 0x50 and 0x60 allow 0x1C (talking over a counter); the across-axis limit is 1 (boxes must overlap). Both must be on the same layer (`obj+0x0B`) and close in height (`obj+0x45` sum < 4). Type 0x60 also requires the NPC to face the hero. The NPC is then stopped (`obj+0x0A`, `+0x1C`, `+0x11` = 0), turned to the hero (facing reversed), and the event `word & 0xFFF` starts (`$C0:B9AA`, `JSL $01:E76D`). Nothing happens while an event runs (`$D0` != 0).
- Measured on the sword of map 128 (kind 0xD8, type 0x60, facing `E010` 0 = up) with the real frame loop after the opening, the hero put on the sword's layer (`+0x0B`) and height (`+0x45`) and **B** pressed for two frames (talk and attack share the B edge latch `$CC` bit 3; A is the run): the event starts (`$C0:B9AA`) only with the hero facing down (the reverse of the NPC's facing; a value test, the hero may stand on either side), for an offset along that axis of 0 to 35 px **in either direction** (36 refused) and across it of at most 10 px (11 refused). Facing up, right or left it never starts. [V: `talk_sword.py` grid, scratch tool]
- Contact `$C1:CF4D` (hero walking into the object): types 0x10, 0x20 and 0x30; 0x30 requires the two to face each other; the event starts at `$C1:CFD8` (`word & 0xFFF`).
- Not decoded: bit 7 and bit 12 of the word (0x8000, 0x1000), the exact distance units of `obj+0x50/0x52` and the 0x10 / 0x20 conditions.

## 4. Kinds in the first rooms
0x8A, 0x8B, 0x99, 0xA0, 0xA6, 0xAC, 0xB7, 0xBB, 0xBC, 0xC0, 0xC1, 0xC4-0xCA, 0xCE, 0xCF, 0xD3-0xDE, 0xEB. Their animations are ripped like monsters (`tools/rip_monster_anims.py ... --only ord`): ordinary animation 0 is standing, 1 walking, in the four facings.
