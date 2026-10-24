# What an ordinary monster does beyond its AI script: statuses, hit reactions, casting poses, idle

Tags: **[V]** executed (the real 65816 code ran in `tools/cpu65816.py`: the per-frame routine `$C0:B08C` on a ZSNES save state, with the NMI handler, or single routines); **[C]** read from the disassembly, not executed. What is not known is in section 9. Ordinary monsters are object ids 0x00-0x1F (decimal 0-31, the ids of the ripped animation directories; all ids below are **decimal** unless written 0x..); ordinary table = 21 animations (0-20), attack table = 4-10 animations depending on the monster (`tools/rip_monster_anims.py`, `docs/monster-3.md` section 13). Frames are video frames (60.0988 Hz). Numbers only: no ROM bytes.

Companion data: `data/monster_anim_use.json` (all numbers of this document, per monster). Probes: `tools/monster_anim_probe.py`.

## 1. Summary

1. **Idle is animated for 15 of the 32 monsters.** Between AI commands the actor is in state 0 with animation 0, and animation 0 loops (the script ends and restarts). It has 2 or 4 pictures with period 10-50 frames for ids 0, 1, 4, 5, 8, 9, 10, 15, 19, 20, 21, 23, 24, 29, 30 (section 3); the other 17 have one static picture. A turn command (`C1 dir 0`) plays the same loop for its natural length [V].
2. **Status poses are done in two places.** The engine (a) swaps the object id or the appearance record, adds overlay pieces and starts a pose (sleep: ordinary 10 played as 0x8A, held), and (b) *calls a script subroutine at pc 0x648E* through a vector table (`D0:4ED3`) for the statuses 0x0020, 0x0040, 0x0100, 0x4000: the subroutine issues the commands that show the pose (petrified: ordinary 19 looped, then 20 once; frozen: object 0x83 and turns in place; balloon: turns in place; burning: spins up-right-down-left every 5 frames). Details and the unaffected statuses in section 4 [V].
3. **Reaction codes of a monster** ($C0:4EBC, 4F1E, 4F4F, 4E6B, 3BE8): 8 (0x88 hurt), 9 (0x89 knock-back), 10 (0x8A sleep), 12/13/14 (0x8C/0x8D/0x8E miss, one in three each), 18 (0x92 heal), plus a one-time ordinary 0 pose (0x80, 5 frames) when a freezing status starts. Nothing else: ordinary 6, 7, 11, 15, 16, 17 are never written by an engine reaction, a status or any of the 42 spells (section 5, 7) [V].
4. **The hit stun is a script hold, not a timer.** The hurt scripts contain the hold op FC (wait while the damage-number overlay `+0x60 = 0x40` runs, frames 5-102) followed by FE (wait while status & 0x7B). That is why the AI resumes at frame 105 for a short hurt script and at `103 + remainder` for the knock-back scripts. This answers the open question in `docs/monster-3.md` section 17 (the "+70") [V trace, C bytes].
5. **There is no flash on the monster when it is hit.** CGRAM row 5 (the body palette) is constant for 160 frames after small and big hits; the only palette that changes is row 4 (the damage digits, frames 5-102). The casting flash is an animation-script palette cycle of the *cast pose* (`E9`/`EA` ops, command 0x44), listed per monster in section 6 [V].
6. Spells never put a monster into a tumbling or blown pose. Every one of the 42 hero spells, cast on a monster in slot 3, holds the monster in ordinary 0 / state 0x40 (`+0x60 = 0xC0`) for 46-346 frames while the effect runs and then gives the normal reaction 0x88 (damage), 0x92 (Cure Water), 0x8A (Sleep Flower) or the status of the section 4 (section 5) [V].

## 2. How the engine picks the animation (summary of what is needed here)

- Object bytes: facing `+0x10` (0 up, 1 down, 2 right, 0x82 left), animation id `+0x11`, state `+0x1C`. The table is chosen at `$C0:F550-F585`: state 0 -> ordinary table with the full id; state != 0 and id < 0x80 -> attack table; state != 0 and id >= 0x80 -> ordinary table with `id & 0x7F` [C, `docs/monster-3.md` section 13]. The script restarts when the word `+0x10/+0x11` changes or `+0x30` is set to 0xFF [C].
- End of a script (`$C0:F90B`, op FF): state 0 -> restart (loop); state 0x40 -> state, id, velocities cleared (back to idle); states 0x80 and 0x20 first load the cooldown gauge `+0x1ED = (100 - Agi)/2 + 50` (when `+0x61` is 0) and then clear like 0x40 [C, as `docs/rabite.md` section 5.3].
- Hold ops inside animation scripts (`$C0:F976-F9B0`) [C]: FC = hold while `+0x60 & 0x40` or `+0x190 & 3`; FE = hold while `+0x190 & 0x7B` (0x01, 0x02, 0x08, 0x10, 0x20, 0x40); both rewind the script pointer and retry next frame. In the ripper (`+0x60 = 0`, no status) they never hold.
- Command executor `$C1:D94F` (section 6.1) [C].

## 3. Idle and "wait" (question 1)

After every command the actor goes back to state 0, animation 0 (`$C0:EB91`/`$C0:FC09` clear `+0x11` when the command counter `+0x0A` ends; `$C0:F955` after a pose) and the animation loops [C]. Run [V]: a Rabite with the real AI for 600 frames spends its frames in (animation / state) = 0/0 (130), 1/0x80 (swing, 50), 2/0 (175), 3/0x80 (40), 5/0 (205): never any other id.

So the remake must loop ordinary 0 whenever the AI is not in a command, and play it for the whole length of the waits `E3 00 xx` / `E4 00 xx` (flag = frames, e.g. 0x3C = 60, 0xB4 = 180, 0x78 = 120). The pictures of ordinary 0 (down facing, from the rips; the other facings have the same timing):

| id | ordinary 0: loop frames | pictures (frames each) | animated |
|---|---|---|---|
| 0 | 20 | 10/10 | yes |
| 1 | 10 | 5/5 | yes |
| 2 | - | 1 static | no |
| 3 | - | 1 static | no |
| 4 | 30 | 15/15 | yes |
| 5 | 20 | 10/10 | yes |
| 6 | - | 1 static | no |
| 7 | - | 1 static | no |
| 8 | 30 | 15/15 | yes |
| 9 | 30 | 15/15 | yes |
| 10 | 40 | 10/10/10/10 | yes |
| 11 | - | 1 static | no |
| 12 | - | 1 static | no |
| 13 | - | 1 static | no |
| 14 | - | 1 static | no |
| 15 | 50 | 15/10/15/10 | yes |
| 16 | - | 1 static | no |
| 17 | - | 1 static | no |
| 18 | - | 1 static | no |
| 19 | 50 | 15/10/15/10 | yes |
| 20 | 20 | 10/10 | yes |
| 21 | 40 | 10/10/10/10 | yes |
| 22 | - | 1 static | no |
| 23 | 40 | 10/10/10/10 | yes |
| 24 | 30 | 15/15 | yes |
| 25 | - | 1 static | no |
| 26 | - | 1 static | no |
| 27 | - | 1 static | no |
| 28 | - | 1 static | no |
| 29 | 50 | 15/10/15/10 | yes |
| 30 | 40 | 10/10/10/10 | yes |
| 31 | - | 1 static | no |

Loop frames = the length of the animation script in state 0 (the ripper records one period). The 17 static monsters (2, 3, 6, 7, 11-14, 16-18, 22, 25-28, 31) show one picture; ids 18 and 25 have a 20-30 frame script that repeats the same picture.

## 4. Status poses and appearances (question 2)

Method: the status word is put through the real `$C8:E301` (as the combat tick does) on a monster in slot 3, then frames run with the real per-frame routine; objects, pieces and CGRAM are recorded (`tools/monster_anim_probe.py status`). With `--ai` the real script runs [V]. Immunity words (`data/monsters.json`): **every** record 0-31 is immune to 0x0200, 0x0400 and 0x1000, so those three never occur on an ordinary monster; other bits per id (e.g. id 13 is immune to 0x0020 and loses it at once).

### 4.1 Mechanisms

| mechanism | where | effect |
|---|---|---|
| appearance swap | `$C8:E52F` (object id, called from E301), `$C8:E5FF` (appearance record `+0x1E3`) [C]; `+0x1FA` bit 0 / 2 = reload graphics / palette (`$C1:939C`) [C] | status 0x0020 -> `+0x180 = 0x83`; 0x0800 -> `+0x180` = one of 0, 2, 4, 6, 8, 12, 22, 23 (table `$C8:E5F3`, random); otherwise `+0x180 = +0x1E7` (original). Record `+0x1E3`: 0x4000 -> 0xF6; 0x0100 -> 0xF2 + (0, 1, 2 for the level `$9D` < 4, < 8, else); 0x0200 -> 0xFA, 0x0400 -> 0xF5; 0x0020/0x0040/0x1000 -> 0x00 [C]; these records add the overlay pieces of the second piece list (rows 4) [V for 0x0100, 0x4000] |
| one-time pose | the combat tick `$C0:3AC8` (E1FB bit 1, set by E301 when a bit of 0x4560 is new) | reaction code 2 / parameter 0: state 0x40, animation 0x80 (ordinary 0, one 5-frame step), velocities zero [V] |
| sleep pose | tick `$C0:3BCC` (E1B1 bit 0 set by `$C8:E4B5`) | code 2 / parameter 0x0A: animation 0x8A, state 0x40 [V] |
| status vector | tick `$C0:3E80` computes the new status bits; with `+0x2C & 0xF == 0` and a new bit in 0x5760 (0x0020, 0x0040, 0x0100, 0x0200, 0x0400, 0x1000, 0x4000), else a new bit in 0x4160, it sets `+0x1FB` bit 3; `$C0:3F08` then calls `JSL $C1:0024` (= `$C1:2698`) with A = 2 for a monster (A = 1 if `+0x1FB` bit 7 is set) | the script pc is pushed on the call stack and replaced by the word at `D0:4ED3 + 2A`: **0x648E** for monsters (0x6378 for the heroes' party AI) [C], observed at frame 15 of every run with the real AI [V] |

The routine at pc 0x648E (also the entry script of object 0x83) [C, listed with `tools/aidis.py`; executed with the real AI of id 0 for 0x0040, 0x0020, 0x4000, 0x0100]: `BB 80 10 60 41`: return at once unless status & 0x4160; then per status the loop of the next table, and RET (the script continues where it was) when the bit is gone.

### 4.2 Per status

| status (source) | animation id / state | palette | advances? | AI | measured [V] |
|---|---|---|---|---|---|
| 0x0004 (spell 2) | unchanged | unchanged | - | runs | no change at all |
| 0x0008 | cleared by the exclusivity cascade | - | - | - | - |
| **0x0010 sleep** (spell 30, status roll of weapon rows) | **0x8A = ordinary 10 in state 0x40**, held on its last picture (script ops FC, FE) while the status lasts; cleared by a damaging hit (`$C0:5119`) | unchanged | the pose plays to its end (one picture, 20-25 frames), then holds | blocked (state 0x40) | id 0 with the real AI: 8a/40 for 380 frames, then the script restarts |
| **0x0020 frozen** (spell 9, Ice Saber) | the object becomes **0x83** (a snowman-like picture set: 4 pieces 16x16, tiles 64/66/68/70 at (-16,-30), (0,-30), (-16,-14), (0,-14), palette row 5 = the 0x83 set), then pc 0x648E: `E3 00 00` (ordinary 0 turn commands of the 0x83 table) while set, `E3 01 0A` once at the end | row 5 replaced | no: one picture | script 0x648E | id 83 for 385 frames, then id restored and the original script restarts at its entry |
| **0x0040 petrified** (spell 3, Stone Saber) | pc 0x648E: **ordinary 19 (`E3 13 00`) looped** while set (one command = the natural length of the animation: 15 frames for id 0), **ordinary 20 (`E3 14 00`) once** when it ends; state 0, facing kept | **row 5 changes while 19 plays** (id 0: grey) and returns with 20; ids whose entries 19 and 20 are the idle picture (section 4.3) look unchanged | 19 holds one picture | script 0x648E | id 0: anim 13 from frame 30 to 389, anim 14 for 20 frames, then the saved script continues |
| 0x0080 silence (spell 20) | none; the cast ops E9 and EA test `+0x190 & 0x80` and fail while it is set (the script then turns 5 frames instead, `docs/monster-ai-opcodes.md`) [C] | - | - | runs | no change of the picture |
| **0x0100 balloon** (spell 22) | body: ordinary 0 turn commands (20 frames) while set; 7 extra pieces of the second piece list above the head (tiles 200, 202, 204, 206, 224, 226, 228; 9 pieces at level 8), palette row 4 | row 4 = balloon colours | balloon static; body loops ordinary 0 | script 0x648E | pieces at dy -72..-79 above the foot (depends on the body) |
| 0x0200, 0x0400, 0x1000 | ordinary monsters are immune | - | - | - | - |
| **0x0800 change form** (spells 24, 26) | the object id changes to one of 8 (0, 2, 4, 6, 8, 12, 22, 23): that object's pictures, palette and animations; `+0x1FA` = 7 reloads graphics, palette and the script | the new object's | its idle loop | the new object's script [C] | Chobin Hood -> ids 8, 23 and 4 in three runs; the picture is the new monster's idle loop |
| 0x2000 poison (spell 7) | none | - | - | runs | 1 HP lost on every 4th tick |
| **0x4000 burning** (spells 15, 17) | pc 0x648E: `E0 8 0 5`, `E0 1 0 5`, `E0 4 0 5`, `E0 2 0 5` repeated: facing up, right, down, left, ordinary 0, 5 frames each (a 20-frame spin) | row 5 unchanged; flame = 4 pieces 16x16 (tiles 200-206, palette row 4) over the body, flipped horizontally every 10 frames | spinning body, flickering flame | script 0x648E | id 0: faces 0, 2, 1, 0x82 every 5 frames for the whole duration; HP -1 per 20 frames |

Timer: `d = max(20, (damage value >> 2) - mdef/2)`, 77 ticks for d = 20 = 385 frames (`docs/rom-combat.md` section 12) [V: sleep, frozen, petrified, burning and balloon ended at frames 380-390]. While a status is on, hurt/knock-back/heal/miss reactions are suppressed (`$C0:4EBC` tests 0xC578, `$C0:4E6F` tests 0xC57D); the damage-number overlay still runs.

### 4.3 Ordinary 10, 18, 19, 20 per monster (frames / distinct pictures, down facing, from the rips)

| id | ordinary 10 (sleep) | ordinary 19 (petrify) | ordinary 20 (petrify end) | ordinary 18 (heal) |
|---|---|---|---|---|
| 0 | 20 f / 1 pic | 15 f / 1 pic | 20 f / 2 pic | 20 f / 2 pic |
| 1 | 20 f / 1 pic | 80 f / 1 pic | 55 f / 28 pic | 10 f / 2 pic |
| 2 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 3 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 4 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 30 f / 2 pic |
| 5 | 20 f / 1 pic | 15 f / 1 pic | 65 f / 9 pic | 20 f / 2 pic |
| 6 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 7 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 8 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 30 f / 2 pic |
| 9 | 20 f / 1 pic | 80 f / 1 pic | 70 f / 13 pic | 30 f / 2 pic |
| 10 | 20 f / 1 pic | 80 f / 1 pic | 50 f / 38 pic | 40 f / 4 pic |
| 11 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 12 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 13 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 14 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 15 | 20 f / 1 pic | 80 f / 1 pic | 30 f / 26 pic | 50 f / 4 pic |
| 16 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 17 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 18 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 30 f / 1 pic |
| 19 | 20 f / 1 pic | 80 f / 1 pic | 30 f / 26 pic | 50 f / 4 pic |
| 20 | 20 f / 1 pic | 15 f / 1 pic | 20 f / 2 pic | 20 f / 2 pic |
| 21 | 20 f / 1 pic | 80 f / 1 pic | 50 f / 38 pic | 40 f / 4 pic |
| 22 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 23 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 40 f / 4 pic |
| 24 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 30 f / 2 pic |
| 25 | 20 f / 1 pic | 15 f / 1 pic | 65 f / 9 pic | 20 f / 1 pic |
| 26 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 27 | 20 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 28 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |
| 29 | 20 f / 1 pic | 80 f / 1 pic | 30 f / 26 pic | 50 f / 4 pic |
| 30 | 20 f / 1 pic | 80 f / 1 pic | 50 f / 38 pic | 40 f / 4 pic |
| 31 | 25 f / 1 pic | 10 f / 1 pic | 10 f / 1 pic | 5 f / 1 pic |

"10 f / 1 pic" for 19 and 20 is the ripper's 10-frame cut-off of a static picture: those entries show the idle picture (the id 3 entry 19 is the same script as entry 0). The palette of the pose is recorded per picture in the rip JSON (`palettes`).

## 5. Hit reactions (question 3)

The reaction code is stored in `+0x1E5` by `$C0:4F6E` and consumed by the next combat tick (`$C0:3B61`), which returns code 2 with the animation id `0x80 | code`; `$C1:80D4` writes `+0x11 = 0x80 | code`, state 0x40, zeroes the velocities and forces a restart (`+0x30 = 0xFF`) [C]. Codes written (monster side: `+0x1FB & 0x81 == 0`):

| code | animation id | written by | when | measured |
|---|---|---|---|---|
| 8 | 0x88 | `$C0:4EBC` (HP damage), `$C0:4F1E` (MP damage) | damage <= max HP/4 (MP damage: `+0x187`/4 >= damage); status & 0xC578 suppresses it | all 32 ids [V] |
| 9 | 0x89 | same | damage above that; for the lethal hit `$C0:4EA9` also writes code + 1 (`+0x190 = 2`, countdown 0x20) but it is never shown: the run with a lethal hit has the death object (id 0xFF) from frame 0 and animation 0 | all 32 ids [V]; knock-back 0-45 px opposite to the facing |
| 10 | 0x8A | tick `$C0:3BCC` | sleep applied | [V] |
| 12, 13, 14 | 0x8C, 0x8D, 0x8E | `$C0:4E6B` from `$C0:4FE0` (hit test failed) and `$C0:5176` (damage 0 after defense) | `0x0C + (rnd * 3 >> 8)`; skipped while `+0x175 != 0` or status & 0xC57D | 0x8C measured; 0x8D/0x8E from the code and the rips [V/C] |
| 18 | 0x92 | `$C0:4F4F` from pending HP heal (`+0x1F3`, `$C0:404A`) and MP heal (`+0x1F6`, `$C0:4113`) | Cure Water (spell 11) and items [V] | 105 frames for all 32 ids (held by FC while the overlay runs) |

The party-side codes (0x0D, 0x0E hurt, 0x0F wake, 0x11-0x13 miss, 0x2B heal, 0x2F KO) are written only when `+0x1FB & 0x81 != 0` and never reach an ordinary monster [C].

The hit sound, EXP and gold are in `docs/monster-3.md` sections 9-11. What each reaction looks like: animation 8 / 9 / 12-14 of the ripped sets `hurt08`, `hurt09`, `hurt12-14`; the holds of the first two make the real durations longer than the rip:

- Small hit (0x88): picture, then FC hold until the overlay ends, then FE, end. **AI free at frame 105** for 18 ids (0, 2, 3, 6, 7, 11-14, 16, 17, 20, 22, 23, 26-28, 31); 115-175 frames for the 14 ids whose script plays on after the hold (1, 4, 5, 8, 9, 10, 15, 18, 19, 21, 24, 25, 29, 30).
- Big hit (0x89): the knock-back moves from frame 6 (1 px/frame, then 2 px/frame), a jump arc, a hold, then the script continues: AI free at 105-175 frames; displacement and peak per id below. Ids 7 and 26 do not move.
- No palette flash: the body palette row 5 is identical in all frames [V]; the changing row is row 4 (the damage digits, frames 5-102). No piece is hidden on a non-lethal hit.

| id | max HP (harness) | small hit: AI free at frame | big hit: AI free at frame | knock-back (dx,dy) px, peak | miss 12 / 13 / 14: frames, hop |
|---|---|---|---|---|---|
| 0 | 20 | 105 | 160 | (0,-40) peak 40 | 25 (0,0) / 30 (0,-16) / 30 (0,-16) |
| 1 | 65 | 160 | 160 | (0,-30) peak 30 | 20 (0,1) / 20 (0,-11) / 20 (0,-11) |
| 2 | 60 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 3 | 60 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 4 | 36 | 115 | 145 | (0,-30) peak 35 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 5 | 140 | 170 | 170 | (0,-40) peak 40 | 15 (0,-1) / 25 (0,-6) / 25 (0,-6) |
| 6 | 64 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 7 | 100 | 105 | 105 | (0,0) peak 0 | 15 (0,3) / 15 (0,-3) / 15 (0,-3) |
| 8 | 40 | 115 | 145 | (0,-30) peak 35 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 9 | 200 | 175 | 175 | (0,-30) peak 30 | 20 (0,1) / 10 (0,-18) / 10 (0,-18) |
| 10 | 55 | 155 | 155 | (0,-30) peak 30 | 20 (0,1) / 20 (0,-11) / 20 (0,-11) |
| 11 | 130 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 12 | 145 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 13 | 128 | 105 | 140 | (0,-30) peak 30 | 25 (0,0) / 35 (0,-15) / 35 (0,-15) |
| 14 | 150 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 15 | 100 | 135 | 135 | (0,-30) peak 30 | 20 (0,-1) / 20 (0,-11) / 20 (0,-11) |
| 16 | 100 | 105 | 175 | (0,-45) peak 45 | 20 (0,0) / 15 (0,0) / 20 (0,-10) |
| 17 | 440 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 18 | 150 | 115 | 145 | (0,-30) peak 35 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 19 | 160 | 135 | 135 | (0,-30) peak 30 | 20 (0,-1) / 20 (0,-11) / 20 (0,-11) |
| 20 | 130 | 105 | 160 | (0,-40) peak 40 | 25 (0,0) / 30 (0,-16) / 30 (0,-16) |
| 21 | 122 | 155 | 155 | (0,-30) peak 30 | 20 (0,1) / 20 (0,-11) / 20 (0,-11) |
| 22 | 186 | 105 | 145 | (0,-30) peak 35 | 30 (0,0) / 25 (0,-15) / 25 (0,-15) |
| 23 | 160 | 105 | 130 | (0,-30) peak 35 | 20 (0,0) / 20 (0,0) / 20 (0,0) |
| 24 | 110 | 135 | 175 | (0,-45) peak 45 | 25 (0,0) / 10 (-18,0) / 10 (-18,0) |
| 25 | 135 | 170 | 170 | (0,-40) peak 40 | 15 (0,-1) / 25 (0,-6) / 25 (0,-6) |
| 26 | 200 | 105 | 105 | (0,0) peak 0 | 15 (0,3) / 15 (0,-3) / 15 (0,-3) |
| 27 | 190 | 105 | 130 | (0,-45) peak 45 | 20 (0,0) / 30 (0,-24) / 30 (0,-24) |
| 28 | 125 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |
| 29 | 100 | 135 | 135 | (0,-30) peak 30 | 20 (0,-1) / 20 (0,-11) / 20 (0,-11) |
| 30 | 210 | 155 | 155 | (0,-30) peak 30 | 20 (0,1) / 20 (0,-11) / 20 (0,-11) |
| 31 | 140 | 105 | 145 | (0,-20) peak 25 | 25 (0,0) / 25 (0,-16) / 25 (0,-16) |

Columns: AI free = first frame with state 0 and animation 0 after a pending-damage hit (`+0x1F1` = 1 and max HP/4 + 1; the real resolver gives the same codes: `docs/monster-3.md` section 9); the next AI step is on the next frame with `frame mod 5` = slot phase. Knock-back and miss hops are of the rip (`actor_dx/dy` of the down facing; left/right/up scale by the facing: opposite to the facing).

## 6. Commands, casting and attack animations (question 4)

### 6.1 The command executor `$C1:D94F` (bytes `+0x140..+0x143`) [C]

| command | what the actor does | script ops (`docs/monster-3.md` 4, `tools/aidis.py`) |
|---|---|---|
| 0x40 p | state 0x40, **attack table animation p**, velocities zero, `+0x64 = 0x80` | E2 |
| 0x44 p | same as 0x40 and `$C1:88C7`; the op first checks the monster's MP against the spell cost and that it is not KO (`$C1:1E2C`), loads the spell id into `+0x170`, runs the cast routine `$C0:001B` | E9 (one target), EA (all targets): arguments animation, spell id |
| 0x43 id | creates a new object with id `id` in a free slot | ED |
| 0x81 a id | the actor turns into object `id` (`+0x180`, `+0x3D`), graphics and script reloaded | EF |
| 0xC0 a b c | sound request | EB |
| 0xC1 dir anim len | state 0, **ordinary animation `anim`**, facing from `dir`, length `len` | E0, E3, E4, E6, FD, FE, BE, BF |
| 0x02 | swing: state 0x80, **attack animation chosen by `$C1:E40E`** | E8, DF, FA |
| 0x04 | removes the object | - |
| 0x01 | stop (velocities zero, ordinary 0) | - |

The swing animation is `D1:05C0 + id * 0x20 + (0x10 if +0x1E4 bit 7) + index`, with `index` (16 columns) from the distance class `$C1:E4CC`, the target's status and the parity of `$F4` [C]; the Rabite's 1/2/3 by distance are in `docs/rabite.md` 5.3. Per monster the set of animations it can reach is in the table below (the second value is the variant set for `+0x1E4` bit 7: the AI op FC "flash" (ids 1, 2, 5, 6, 11, 14, 18, 22, 24, `docs/monster-ai-opcodes.md`) toggles that bit together with the recolour records `+0x1E8`/`+0x1E9`, so the variant half is reached at run time by those monsters; the harness spawns have the bit clear).

### 6.2 Which attack animation each monster can run and which cast poses flash

Columns: attack animations in the table; pose 40 (E2) asked by the script; cast pose 44 (E9/EA) asked by the script, with the spell ids (hex); swing set (in brackets: the script has no swing op); attack animations that no path asks for; attack animations of the rip whose picture palette changes during the animation (the casting flash is the one the cast ops ask for, e.g. id 3: animation 2; id 4: animation 3).

| id | attack anims in table | pose 40 (E2) | cast 44 (E9/EA): anim (spell ids) | swing 02: normal / variant | not requested | changing palette in the rip |
|---|---|---|---|---|---|---|
| 0 | 8 | 0,5 | - | 1,2,3 / 1,2,3 | 4,6,7 | 4 |
| 1 | 5 | 0 | - | 1,2 / 1,2 | 3,4 | 2,3,4 |
| 2 | 8 | 0 | - | 2,3,4 / 5 | 1,6,7 | 5,6 |
| 3 | 5 | 0 | - | 1 / 1 | 2,3,4 | 2 |
| 4 | 8 | 0,4,6 | 3(1E) | 1 / 1 | 2,5,7 | 3 |
| 5 | 9 | 0,6 | 7(07) | 1 / 2 | 3,4,5,8 | 2,3,7 |
| 6 | 8 | 4,5 | - | 1 / 2 | 0,3,6,7 | 1,2,3,6 |
| 7 | 5 | 0,3 | 2(0A/0B) | 1 / 1 | 4 | 1,2 |
| 8 | 10 | 0,6 | - | 1 / 1 | 2,3,4,5,7,8,9 | 7 |
| 9 | 5 | 3 | 1(06/08) | (1) / 1 | 0,2,4 | 0,2,3 |
| 10 | 5 | 0 | 3(16) | 1,2 / 1,2 | 4 | 3 |
| 11 | 8 | 0,7 | 3(01/02/0B) | 1 / 2 | 4,5,6 | 1,2,3,6 |
| 12 | 7 | 0 | 4(07/0B) | 1,2,3 / 1,2,3 | 5,6 | 4 |
| 13 | 4 | 0 | - | 1,2 / 1,2 | 3 | - |
| 14 | 8 | 7 | 3(05) | 1 / 2 | 0,4,5,6 | 1,2,3,6 |
| 15 | 6 | 0 | 4(0C/11) | 2 / 2 | 1,3,5 | 2,3,4 |
| 16 | 8 | 0 | 5(1E) | 1,2 / 1,2 | 3,4,6,7 | 4,5 |
| 17 | 7 | 0 | 4(07/09/0B) | 1,2,3 / 1,2,3 | 5,6 | 4 |
| 18 | 8 | 5 | 4(02) | 2 / 1,3 | 0,6,7 | 4 |
| 19 | 4 | 0,3 | 1(12/13/14) | (1) / 1 | 2 | 1 |
| 20 | 8 | 0,5 | 4(07/08/0B/0C) | 1,2,3 / 1,2,3 | 6,7 | 4 |
| 21 | 4 | 0 | 2(12/14) | 1 / 1 | 3 | 2 |
| 22 | 10 | 0 | - | 1 / 2 | 3,4,5,6,7,8,9 | 4 |
| 23 | 6 | 0,1,3 | 2(1F) | (1) / 1 | 4,5 | - |
| 24 | 7 | 0,4 | 3(15) | 2 / 1 | 5,6 | 1,3 |
| 25 | 4 | 0,2 | 3(04) | 1 / 1 | - | 3 |
| 26 | 5 | 0,3 | 2(0A/0B/26) | 1 / 1 | 4 | 1,2 |
| 27 | 7 | 2 | 5(02) | 2 / 2 | 0,1,3,4,6 | 5 |
| 28 | 5 | 0 | 2(0F) | 1 / 1 | 3,4 | 2 |
| 29 | 6 | 0 | 4(06/07) | 3 / 3 | 1,2,5 | 2,3,4 |
| 30 | 5 | 0 | 3(26) | 1,2 / 1,2 | 4 | 3 |
| 31 | 9 | 0,2 | 8(0B/1C) | 1,2,3,4,5,6 / 1,2,3,4,5,6 | 7 | 3,4,8 |

- **Casting flash** = the palette cycle of a cast pose (command 0x44): 4 palette states of row 5 stepped every 1-5 frames (id 3 animation 2: sequence 0,1,1,1,1,2,2,2,2,0,0,0,0,3,3,3,3,... over 100 frames). It runs for the whole animation (100 frames for id 3) and the spell is cast by the monster object itself when the ops reach it. Monsters with a cast op: 4, 5, 7, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31 [V for the animations, C for the command].
- Attack animations 3 and 4 are therefore: 3 = cast pose of ids 4, 10, 11, 14, 24, 25, 30 and pose 40 of ids 7, 9, 19, 23, 26 and a swing for ids 0, 2, 12, 17, 20, 29, 31 (the "far/mid" bites); 4 = cast pose of ids 12, 15, 17, 18, 20, 29, pose 40 of ids 4, 6, 24 and the swing of ids 2 and 31. The spawn leap of the Chobin Hood is pose 40 / animation 0.
- Commands 0x43 (ED): ids 7 (object 3), 8 (8), 11 (14), 19 (22), 26 (51), 29 (29); command 0x81 (EF `05 xx`): ids 23 (-> object 0xFE) and 29 (-> 0xFB), the two death-effect objects. Both are issued by the monster's own script.

## 7. Where each animation can be requested (question 5)

Ordinary table (state 0 with the full id; state 0x40 with 0x80 | id for reactions). "Script" = asked by a hop / turn op of an ordinary monster's script (static walk of ids 0-31, `tools/monster_anim_probe.py scan`).

| ordinary id | requested by | notes |
|---|---|---|
| 0 | idle (state 0 after every command); script C1 anim 0 (all 32 ids); one-time status pose 0x80; frozen / balloon / burning loops | looped [V] |
| 1 | script (all 32): hop | |
| 2 | script (all 32): dash / hop | |
| 3 | script: ids 5, 9, 27, 31 | |
| 4 | script (all 32) | |
| 5 | script: ids 0, 1, 8, 10, 12, 13, 14, 16, 17, 18, 19, 20, 21, 24, 25, 27, 30, 31 (back-step) | |
| 6, 7 | **unknown**: no script, reaction, status or spell requests them (6 and 7 are 25-90 frame moves in the rips) | |
| 8 | reaction 0x88 (hurt); script: id 24 | |
| 9 | reaction 0x89 (knock-back, lethal hit) | |
| 10 | reaction 0x8A (sleep) | |
| 11 | script: ids 9 and 18 | |
| 12, 13, 14 | reaction 0x8C-0x8E (miss); animation 14 also by script ids 2, 5, 6, 11, 14, 17, 22, 27, 28, 31 | |
| 15, 16, 17 | **unknown**: no request found (they are the 110-155 frame tumbling poses; not asked by any script of ids 0-31, any status, any reaction code of `$C0:4EBC/4E6B/4F4F` or any of the 42 spells cast on a monster) | resting place of the pictures the public sheets lack |
| 18 | reaction 0x92 (heal) | |
| 19 | petrified (status 0x0040), `E3 13 00` in the 0x648E routine | grey palette where the pose differs |
| 20 | end of petrified, `E3 14 00` | |

Attack table (state 0x40 / 0x80); sizes 4-10 per monster:

| attack id | requested by |
|---|---|
| 0 | pose 40 of 27 ids (spawn / wake pose and similar: 0-5, 7, 8, 10-13, 15-17, 19-26, 28-31); not by the swing chooser |
| 1 | swing (most monsters); pose 40: id 23; cast: ids 9, 19 |
| 2 | swing (ids 0, 1, 2, 10, 12, 13, 15-18, 20, 24, 27, 30, 31 ...); pose 40: ids 25, 27, 31; cast: ids 7, 21, 23, 26, 28 |
| 3 | swing: ids 0, 2, 12, 17, 20, 29, 31; pose 40: ids 7, 9, 19, 23, 26; cast: ids 4, 10, 11, 14, 24, 25, 30 |
| 4 | swing: ids 2, 31; pose 40: ids 4, 6, 24; cast: ids 12, 15, 17, 18, 20, 29 |
| 5-9 | pose 40 (5: ids 0, 6, 18, 20; 6: ids 4, 5, 8; 7: ids 11, 14), cast (5: 16, 27; 7: 5; 8: 31), swing (id 31: 5, 6; variant of id 2: 5); the rest **unknown**: see "not requested" in the table of 6.2 |

## 8. Verified and read

- **[V]**: idle loops and the animation/state histogram of a real Rabite run; all the status appearances and traces of section 4 (ids 3, 0 and 13 for the id changes, pieces and palette rows; id 0 with the real AI for 0x0010, 0x0020, 0x0040, 0x0100, 0x4000); the reaction codes 8, 9, 0x92, 0x8C and the mp-damage path; AI-free frames of all 32 ids; the absence of a body palette change and the digit palette change; the 42 spell casts on a Chobin Hood (`tools/summon_sim.py` `spawn_monster`, `cast`, 520 frames each: only the animations 0 / state 0x40 hold, 0x88, 0x92, 0x8A and the statuses 0x4000, 0x0100, 0x0800, 0x0080, 0x0004 appeared; no spell produced any other animation id).
- **[C]**: the code paths of the reaction codes, the hold ops, the status vector and the 0x648E routine (listing), the command executor, the swing table, the immunity effects on 0x0200/0x0400/0x1000.

## 9. Open questions (no values are claimed)

1. Ordinary animations 6, 7, 15, 16, 17 (and the second half of the attack animations marked "not requested") have no requester in the ordinary-monster paths examined: scripts of ids 0-31, the combat tick, 42 spells on a monster. They may belong to party-side or boss objects, cutscenes (the event VM sets actor animations) or object ids above 31.
2. `+0x1FB & 0x81` (bit 0 and bit 7): bit 7 = party hero; bit 0 not identified. All 32 spawned ordinary monsters have `+0x1FB = 0`.
3. Statuses 0x0200, 0x0400, 0x1000 and 0x0800 on monsters that are not immune (ids above 31 were not examined); the appearance records 0xFA, 0xF5 and the 0x1000 value were not rendered.
4. Simultaneous statuses (cascade order is in `docs/rom-combat.md` section 12; the poses of two statuses at once were not run), a hit on a sleeping monster, and the real AI of the monsters that Change Form creates (the new script was not run).
5. Which of the miss reactions 0x8D and 0x8E the game rolls in a given hit: the harness RNG state gave 0x8C every time; the formula is `0x0C + (rnd * 3 >> 8)` [C].
6. Screen-wide flashes (PPU colour math) on a hit were not examined; only sprite palette rows were recorded.
7. The meaning of `+0x2C & 0xF` in the status-vector condition (which statuses call 0x648E while the actor moves).
8. Death: the corpse object (0xFF/0xFB/0xFE) and its animations are in `docs/monster-3.md` section 10 for ids 3 and 13; not repeated for the other ids.

## 10. Tools

- `tools/monster_anim_probe.py ROM STATE status ID MASK FRAMES [--ai] [--level N]`, `hit ID dmg|heal|mp|miss VALUE FRAMES`, `scan ROM [out.json]`.
- `tools/rip_monster_anims.py` (pictures), `tools/ai_sim.py`, `tools/summon_sim.py` (the 42 casts), `tools/aidis.py` (script listing), `tools/disasm65.py`, `tools/flowdis.py`.
- The measured per-monster values are in `data/monster_anim_use.json`.
