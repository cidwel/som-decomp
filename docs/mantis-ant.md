# Mantis Ant (Secret of Mana USA): boss id 0x57, the first boss

Tags: **[V]** reproduced by running the original 65816 code with the whole game frame (`$C0:B08C`) in `tools/boss_fight.py` / `tools/mantis_ant.py` / `tools/rip_boss.py`, or measured on live objects of those runs. **[C]** read from the disassembly, not executed. Values that were not determined are in section 14; nothing is guessed.

Addressing as in `docs/dark-lich.md`: `$Cx:xxxx` = file offset `((x-0xC0)<<16)|xxxx`. Object fields are offsets from the object (`$7E:E600 + slot*0x200` for the slots of the C2 engine; the boss is slot 0). Seconds = frames / 60.0988. All numbers are also in `data/mantis_ant.json`.

## 1. Summary

- A sprite boss driven by the C2 boss engine (record 0, `$C2:D080`) with native handlers for the decisions and 24 small state scripts. It ticks once per 5 frames (12.02 ticks/s). [V]
- It walks toward the nearest hero, swings its claws when the hero is close (one or two swings, each hitting with attack row 68), jumps toward a hero that is above it (a 301-pixel high leap, no damage), and from a distance either casts spell 0x01, throws a homing projectile (row 99, status 0x0010) or creates a delayed effect object on the hero (row 3). [V]
- Decisions: every 47 ticks (3.9 s) an action, otherwise a movement state picked by distance and direction. The chooser and the action routine were modelled in Python and agree with the real code in 40,000 of 40,000 random worlds, RNG state included. [V]
- No HP-dependent behaviour (the handlers do not read the HP) [C]. Hit reaction: any party hit in a movement state stops it, 21 ticks of hurt (as long as the damage number lives), then an immediate action. [V]
- Death: hit sound 0x94, a 300-frame fade with explosion objects every 20 frames, victory event 0x7F8 from frame 133, 10 EXP to each hero, 100 gold, no item drop. [V]

## 2. Spawn and objects

- Map 260 (the pit arena, 480 x 480 px), object record 0: tile (13, 14), facing down, flag 0x10 range 0-15 (always true), event word 0x4112; id 0x57. Transition 141 enters the map at tile (16, 18). The map-object spawner sees an id in 0x57-0x7F and runs the boss loader (`$C2:0000`, scripts `$C1:61CB` / `$C1:61D3` from the tables `$C2:00EE` / `$C2:0146`, graphics and palette loads, then "create object record 0"). The boss appears at world (208, 224) = 16 * tile. [V: loading map 260 through transition 141 in `boss_fight.py` spawned the boss there by itself]
- Record 0 (`$C2:D080`) [C]: flags 0x1C11, init `$C2:3D48`, chooser `$C2:3D5A`, action `$C2:3D8C`, hurt handler 0 (default), first sequence `$C2:D09A` (state 00), hurt sequence `$C2:D09C` (state 03), state table `$C2:D0C9`. The same record serves the Metal Mantis (0x63): the action routine jumps through `$C2:3D94` by `obj+$42` (0 = Mantis Ant `$C2:3D98`, 1 = `$C2:3DDB`); `obj+$42` = 0 for 0x57 [V].
- Init `$C2:3D48` creates one more object when `obj+$42` = 0: handler `$C2:3E27`, flags 0x2941, slot 4 [V]. It stands at (334, 318), shows animation 0xE7 (two pictures, 2 ticks each, loop), after 16 ticks waits until bit 0 of `$7E:CFFF` is clear and switches to animation 0xE6 [C, positions and animations V]. It is a person sprite at the bottom right of the arena (pictures in the rips). Flag 0x2000 keeps it out of the contact code: it cannot hit or be hit.
- Slots 3 and 5 hold two objects with handler `$C2:311D` (flags 0x2801) that stay inactive during the fight [V]; slot 3 is reused at the end (section 11).
- Combat fields of the live object [V]: HP 150, Agi 5, evade 0, defense 0, accuracy 99, hit sound `obj+$1AF` = 0x94, status immunity 0x7FFC, `obj+$1FB` = 0x40 (boss).

## 3. Time base [V]

- Flags 0x1C11: high byte 0x1C, `& 3 == 0`, so the boss runs when `$56` = 0: **one tick per 5 frames = 12.02 ticks/s** (`docs/mana-beast.md` section 1). Every state length below is a multiple of 5 frames.
- Action threshold `$2D` = (100 - Agi) / 2 = **47 ticks** (`$C2:3372`). The action counter `$AD` counts ticks; it is reset when an action sequence ends.
- Movement runs on two clocks: the walk states move through their animation script (per tick), the jumps through the per-frame motion routine `$C2:36BC` (velocity per frame).

## 4. Stats (`data/monsters.json` id 87) [V]

Level byte 3, HP 150, MP 20, Str 8, Agi 5, Int/Wis 7, evade 0, defense 0, magic evade 0, magic defense 0, EXP 10, gold 100, spell power 17/17, status immunity 0x7FFC, drop row all 0xFF (no drop). Attack = Str + row power (8 bit): row 68 -> 15, row 99 -> 18, row 3 -> 20; all three rows have accuracy 99.

## 5. State machine

Sequences (`$C2:D09A-D0C8`) and state scripts (`tools/mantis_ant.py ROM static`, decoder `tools/statescript.py`) [C]; lengths measured in ticks over 6 runs of 6,000-12,000 frames [V]. "Cut" = a mode-1 state ends early when `$AD` reaches 47 (`$C2:368F`): a state entered with counter `a` lasts min(length, 47 - a + 1) ticks. Re-picking the running state does not restart it (`$C2:377A`), it just goes on.

| State | Script | What it is | Length | Movement |
|---|---|---|---|---|
| 00 | CLR flip, anim 0A, DURATION 0x0C | idle (two pictures, 3 ticks each) | 13 ticks (65 f, 1.08 s) or cut | none |
| 01, 02 | anim 0B, DURATION 9 | unused by the Mantis Ant | - | - |
| 03 | CLR flip, anim 0C, F4A `$C2:34B9` | hurt | 21 ticks (105 f, 1.75 s) after a real hit, section 9 | none |
| 04 | SET flip, anim 0D, DURATION 0x0C | walk left | 13 ticks or cut | 8 px per 3 ticks = 32.0 px/s left (36 px in 13 ticks) |
| 05 | CLR flip, anim 0D, DURATION 0x0C | walk right | 13 ticks or cut | 32.0 px/s right |
| 06 | anim 0E, DURATION 0x0C | walk down | 13 ticks or cut | 4 px per 3 ticks = 16.0 px/s down (18 px in 13 ticks) |
| 07 | CLR flip, anim 0F, ROW 68 | two claw swings (left, then right) | 11 ticks (55 f, 0.92 s) | none |
| 08 | anim 10, DURATION 9, SPELL 0x0001 | cast spell 0x01 on the target | 10 ticks (50 f, 0.83 s) | none |
| 0A | SET flip, then as 0B | claw swing to the right | 10 ticks (50 f) | none |
| 0B | anim 12, ROW 68 | claw swing to the left | 10 ticks (50 f) | none |
| 0C | anim 13, FRAMES (0, -2, vz 20), then `$66`=1, `$A7`=3, motion `$C2:36BC`, F4A `$C2:3766` | jump straight up | 13 ticks (65 f): ends on the first tick after landing | x 0, y -2 px per frame while airborne |
| 0D | anim 14, DURATION 0x18 | pose (one picture) | 25 ticks (125 f, 2.08 s) or cut | none |
| 0E | anim 15 | crouch before the jump | 6 ticks (30 f) or cut | none |
| 0F | anim 16, `$66`=0, `$A7`=4 | landing | 6 ticks (30 f) or cut | none |
| 10 | CALLNATIVE `$C2:3E7F`, DURATION 3, ROW 99 | throw the homing projectile | 4 ticks (20 f) | none |
| 11 | as 0C with x step -2 | jump up-left | 13 ticks (65 f) | (-2, -2) px per frame |
| 12 | as 0C with x step +2 | jump up-right | 13 ticks (65 f) | (+2, -2) px per frame |
| 13 | anim 0C, SPAWN type 3 at (0, -32), DURATION 0x24, ROW 3 | create the effect object | 37 ticks (185 f, 3.08 s); 38 ticks in 8 of 9 natural runs (section 14) | none |
| 14-17 | spawn types 0x0A / 0x0B, spells 0x021C / 0x0101 | used by the Metal Mantis only | - | - |

Sequences: walk = 04, 05, 06 (one state each); jumps = 0E 0C 0F (up), 0E 11 0F (up-left), 0E 12 0F (up-right); idle 00; pose 0D; claws 07, 0A, 0B; projectile = 07 then 10; spell 08; effect 13.

Measured over the six runs [V]: state lengths agree with the rule above in 683 records; 134 longer records are re-picks of the same state (whole further segments); 36 were cut by a party hit; 36 hurt states lasted 105 frames; state 13 lasted 190 frames 8 times (`tools/mantis_ant.py ROM timeline RUN.json ...`, 0 other differences).

Spawn: state 00 for 13 ticks, the first chooser call at frame 65, the first action at frame 240 (4.0 s) in the three runs of `explore` [V].

## 6. Decisions (chooser `$C2:3D5A`, action `$C2:3D98`) [C, model V]

Both refresh the target first (`$C2:3A41`): target = the first hero (slot order 0, 1, 2) with `obj+0` = 1, not dead (`obj+$190` bit 15 clear) and the smallest Manhattan distance |dx| + |dy| (`$C2:3224`); `obj+$A9` = target, `obj+$AB` = direction code from the boss to the target (`$C2:2E50`):

```
dx = hero.x - boss.x, dy = hero.y - boss.y          (16-bit)
quadrant q: 0 (dx>=0, dy>=0), 1 (dx<0, dy>=0), 2 (dx<0, dy<0), 3 (dx>=0, dy<0)
c = 0 if |dy|/2 >= |dx|   (vertical)      c = 1 if |dx|/2 < |dy|   (diagonal)      else c = 2   (horizontal)        (integer halves)
if q is even: c = 2 - c
code = 2q + c, 8 -> 0        0 right, 1 down-right, 2 down, 3 down-left, 4 left, 5 up-left, 6 up, 7 up-right
```

Distance class `k` (`$C2:08BC`) = (d >> 4) - 1 clamped to 0..4 with d = |dx| + |dy|: 0 below 32 px, 1: 32-47, 2: 48-63, 3: 64-79, 4: 80 and more.

`rand(n)` (`$C2:300B`): one byte r of the C2 generator (`$C2:302C`: 55-byte table at `$0306`, both indexes `$033D` / `$033E` advance mod 55, `t[i0] ^= t[i1]` is the result), then (r * (n + 1)) >> 8 (0..n). rand(2) gives 0 for r < 86 (86/256) and 1 or 2 for 85/256 each.

**Chooser** (when a movement state ends and `$AD` < 47, or when the action routine returns "no action"):

```
if k >= 2:            walk[dir]
elif rand(2) != 0:    walk[dir]                    (170/256 = 66.4%)
elif rand(2) == 0:    idle 00                      (86/256 * 86/256 = 11.3%)
else:                 pose 0D                      (86/256 * 170/256 = 22.3%)
walk[dir] = right 05, down-right 05, down 06, down-left 04, left 04, up-left 0E 11 0F, up 0E 0C 0F, up-right 0E 12 0F   (table $DC:E000)
```

**Action** (when `$AD` >= 47 at the end of a state or at a cut):

```
if dir == 6 (straight up): no action (carry set) -> the chooser runs (a jump up), $AD keeps counting
k >= 4:  rand(2) == 0 -> 08 (spell 0x01)   (33.6%)      else 07 then 10 (swing and projectile)   (66.4%)
k == 3:  13 (effect object)
k <= 2:  close[dir] = right 0A, down-right 0A, down 07, down-left 0B, left 0B, up-left 07, (up -), up-right 07   (table $DC:E010)
```

Model check [V]: `tools/mantis_ant.py ROM STATE verify 40000 7` builds random worlds on the WRAM of the running fight (boss position, three heroes with random active / dead flags and positions, random RNG table and indexes) and calls the real `$C2:3D5A` and `$C2:3D8C`: returned sequence, target, direction code and the whole RNG state agree with the model in 20,000 of 20,000 chooser calls and 20,000 of 20,000 action calls. Results seen: chooser 05 4,716, 04 4,700, 06 3,045, 0E 0C 0F 3,006, 0E 11 0F 1,693, 0E 12 0F 1,717, 0D 749, 00 374; action 07 10 6,941, 08 3,543, no action 3,164, 13 1,865, 07 1,780, 0B 1,334, 0A 1,373.

Behaviour that follows from it [V, runs]: a hero standing straight above the boss is never attacked; the boss keeps jumping up toward it. A hero 48 px or more away is always approached (walk or jump); closer, it idles or poses a third of the time.

## 7. Attacks [V]

Boxes are `obj+$C0-$C3` (attack) and `obj+$C8-$CB`, `$CC-$CF` (two hurt boxes): x offset, y offset, half width, half height, relative to the boss position; they come from the animation frame. Frames count from the start of the state; flip = `obj+$98` bit 6 (set = facing right).

| Attack | Frames with an attack box | Box | Contacts measured | Row / damage |
|---|---|---|---|---|
| 0A (right) | 20-24, 25-49 | (33, -27, 17, 32), then (8, -2, 37, 18) | first hero at frame 26, the next ones at 31 and 36 (three heroes on one spot: one per tick) | 68: attack 15, hit 99 |
| 0B (left) | the same, mirrored: (-33, -27, 17, 32), (-8, -2, 37, 18) | | 26-41 | 68 |
| 07 (down, two swings) | 20-24 left (-33, -27, 17, 32), 25-39 (-8, -2, 37, 18); 40-44 right (33, -27, 17, 32), 45-54 (8, -2, 37, 18) | | 26, 31, 36, 41 | 68 |
| 10 (projectile) | the projectile object (below) | | | 99: attack 18, status 0x0010 at 99% |
| 13 (effect) | the effect object (below) | | hero 0 at frame 183 of the state, 9 of 9 | 3: attack 20 |
| 08 (spell 0x01) | none | | damage reached the target 189 frames after the state start (9 of 9 single samples in different runs) | spell 0x01, Int 7 + spell power 17 |
| 0C, 11, 12, 0E, 0F (jump) | none | | no contact in 65 jumps | - |

Damage with the heroes' evade and defense forced to 0 (`hero_def=(0, 0)` in the runs): row 68 hits for 14-15, row 99 for 18, row 3 for 20 [V]. With the real late-game heroes of the save state the same hits land for 0 (defense larger than the attack) and the spell for 1; the formula is `docs/rom-combat.md` sections 4 and 5.

- **Homing projectile** (state 10, `$C2:3E7F`): an object with handler `$C2:3ED6`, flags 0x2801, created at (boss x - 12, boss y + 4) with velocity `$DC:E028[dir]` (x, y in px per frame: right (2, 2), down-right (2, 2), down (0, 2), down-left (-2, 2), left (-2, 2), up-left (-2, 2), up (0, 2), up-right (2, 2)) [C], animation 0x17. On each active call, B2 increments; if the new byte is below3 the native branch clears it and re-aims at the target hero (therefore every active call from the normal initial zero; values at least3 skip re-aiming): velocity += `$DC:E048[dir]` (right (4, 0), down-right (4, 4), down (0, 4), down-left (-4, 4), left (-4, 0), up-left (-4, -4), up (0, -4), up-right (4, -4)), each component clamped to -4..4 px per frame (`$C2:32BC`), moved every frame by `$C2:3F4C` [C]; it ends at its contact (`$C2:3CE8` sets the hero's hit mask) or when the target is dead [C]. Measured flights: 5 to 50 frames before the contact, 37 flights [V]. Contacts are credited to the boss with row 99.
- **Effect object** (state 13, SPAWN type 3): handler `$C2:998D`, flags 0xAA21, created at (boss x, boss y - 32) with animation 0x15F (pictures growing, about 80 frames), then it moves onto the target hero and plays animation 0x160 until the hit at frame 183 of the state (only the target hero is hit) [V]. Sounds 0x83 at frame 2, 0xA9 at frame 87.
- **Jumps**: vertical speed starts at 20 px per frame (`obj+$C6`), gravity 0xB0/256 = 0.6875 px per frame per frame, height `obj+$66` up to 301 px (the boss leaves the screen), 59 frames in the air; the ground motion is the FRAMES step per frame while airborne, blocked by walls with sliding (`$C2:152B`, `$C2:1571`). Displacements measured: 0C 64-116 px up, 11 and 12 up to 110-124 px diagonally [V].

## 8. Sounds [V]

Sound requests (`$1E00` = 2, id in `$1E01`) per state, frame from the state start:

| State | Sounds |
|---|---|
| 0A, 0B | 0x08 at 20 |
| 07 | 0x08 at 20 and 40 |
| 08 | 0x31 at 48 |
| 0E | 0x4B at 20 |
| 0F | 0x4A at 0 |
| 13 | 0x83 at 2, 0xA9 at 87 |
| boss hit by a hero weapon | **0x94** in the frame the damage is applied (36 of 36 hits; 0x94 is the boss's `obj+$1AF`) |
| death | 0x94 at the lethal hit, 0x15 every 20 frames from 31 to 251 and at 312, section 11 |

Sounds 0x4F / 0x50 are the heroes' own hit sounds (`docs/hit-reactions.md`), 0x24 the hero swing.

## 9. Hit reaction [V]

- Weapon hits are possible while a hurt box exists (`obj+$CA | obj+$CE` != 0): body box (0, -27, 16, 21) in most pictures, a second box on the raised claw; during 0D only the second box (1, -26, 23, 22); during 13 only (0, -25, 15, 19); during 08 the body box is present in 15 of 50 frames. See the rips for every frame.
- A hit in a mode-1 state (00, 04, 05, 06, 0D, the jump states): mode 2 after 1 tick, hurt state 03 from the next tick, `$2D` set to 0, so the action routine runs when 03 ends. 03 lasts while the damage number of the hit is shown: 21 ticks (105 frames) in 36 of 36 real hits, exactly as the Dark Lich (`docs/dark-lich-hands.md` 5.3). Then the action: in the run the hero stood below, so 07 followed every time (36 of 36).
- Injected hit flag (no damage number): 00, 05, 06, 0D -> mode 2 at +5, 03 at +10, the action at +15 frames. In mode 0 (actions 0A, 13) the flag is ignored and the state runs on.
- The damage itself is applied in every state (damage 2, 6 and 12 in the measured hits).

## 10. Graphics [V]

- Drawn with sprites (OBJ), not with a background layer: 12 pieces (two 32x32, ten 16x16) in palette row 5, OBJSEL 0x63 (16/32 px sizes). The ground shadow (tiles 0, 6, 8, palette row 1) is drawn every other frame (flicker), split off in the rips.
- Animation scripts (`tools/mb_anim.py ROM 0A,...,17`): 0A idle (2 pictures, 3 ticks each), 0D walk (moves 4 px per step in the script), 0E walk down, 0F double swing, 12 swing, 13 jump, 14 pose, 15 crouch, 16 land, 17 projectile; 0xE6 / 0xE7 the person at (334, 318).
- `tools/rip_boss.py ROM STATE 57 OUTDIR SEQ,... hero=208,330 home=208,240 shadow=0,6,8` forces each sequence through the real chooser and records every frame (pictures as transparent PNGs, pieces, boxes, height, sounds); `death` records the death. Rips of this document: `/tmp/som-scratch/boss/mantis/rip` (31 sequences, both facings) and `/tmp/som-scratch/boss/mantis/rip_death` (800 frames) on the author's machine; nothing is in the repository.
- Check against the public sheet of The Spriters Resource (snes/secretofmana, asset 1503): of the boss pictures, 72 of 122 are found pixel for pixel; the other 50 are jump frames where the boss is partly off the screen (cut pictures) and cast frames; the effect object 22 of 30; the death sequence 8 exact and 5 under a recolouring of 46 pictures (the fade uses palette changes) [V].

## 11. Death [V]

Measured with a lethal hit at boss HP 5 (`mantis_ant.py ... natural 4 6000 kill5`), frames from the hit:

| Frame | Event |
|---|---|
| 0 | HP 0, dead bit, sound 0x94 |
| 5 | state 03 with animation 0C; the boss stays in state 03 to the end |
| 5-309 | 46 pictures: palette flashes and a fade of the boss sprite |
| 30, 50, 70 | explosion objects in slots 6, 7, 8 (animation 0x15C), each reappears every 60 frames at a new random offset; sound 0x15 every 20 frames (31-251) |
| 133 | event 0x7F8 starts (VM: freeze 0x06 at 133, then a sound request 0x80 / 0x80 at 138, music command 1 id 0x18 at 348, id 0x17 at 723, sound 0x07 at 878) |
| 310 | boss no longer drawn (animation 0) |
| 312 | slot 3 becomes an object with handler `$C2:3ADB` (a large expanding picture, 224 x 64, until frame 682); sound 0x15 |

Rewards [V]: every hero +10 EXP (record byte), gold +100 (`$7E:CC6A` word 0x86B3 -> 0x8717), no item (drop row 0xFF). The event then waits at a party-gather command, which never completes in the harness because the party AI is switched off; the rest of the event (and when event 0x112 of the map record runs) is in section 14.

## 12. Implementation recipe (Godot)

1. One logic tick every 5 frames (12.02 Hz); animations and the jump physics per frame (60.0988 Hz).
2. Keep `ad` (ticks since the last action) and `thr` = 47. At the end of each state sequence: if the last sequence was an action, `ad` = 0; if `ad >= thr` run the action rule, else the chooser rule (section 6). A movement state (chooser states and the jump sequence states) also ends when `ad` reaches `thr`; re-choosing the running state continues it.
3. Use the exact `rand` of section 6 (or any uniform byte r with the same (r * 3) >> 8 mapping) and the 8-direction code of section 6; the target is the nearest living hero by |dx| + |dy|.
4. States, lengths, boxes, sounds and movement from sections 5, 7 and 8 and `data/mantis_ant.json` (`rips` has per-frame timelines of every sequence: picture index, attack and hurt boxes, displacement, height, sounds).
5. Hit: in a movement state go to hurt for 105 frames (or the life of your damage number), then run an action at once; actions are not interrupted.
6. Death at HP 0: hurt pose, 300-frame fade with explosions every 20 frames, then victory.

## 13. Tools

- `tools/boss_fight.py ROM STATE 57 FRAMES [seed=N] [hero=X,Y] [ai=1] [hits=1]`: the fight on map 260 (party sent through transition 141, boss spawned by the game), heroes pinned and immortal, one line per state start.
- `tools/mantis_ant.py`: `static`, `verify N SEED` (model against the real chooser and action), `run` (fights with relocated heroes), `natural` (the leader swings at the boss: hurt statistics, death), `inject`, `timeline`, `build` (writes `data/mantis_ant.json`).
- `tools/rip_boss.py`: rips (forced sequences, death) and `sheet` (comparison with a sheet you provide).

## 14. Open questions

- State 13 lasts 38 ticks instead of the 37 of its script in 8 of 9 natural occurrences and 37 in one; the reason was not traced.
- What the person object at (334, 318) is in the story, and who clears bit 0 of `$7E:CFFF`.
- The rest of the victory event 0x7F8 after the party gather, when the map-record event 0x112 runs and when the boss object is removed (not reached in the harness with the party AI off).
- The meaning of the sound ids beyond their use here, and of the sound request 0x80 / 0x80 at frame 138 of the death.
- The 224 x 64 object of slot 3 at the end of the death (handler `$C2:3ADB`) was ripped but not decoded.
- Behaviour with lag on real hardware.
