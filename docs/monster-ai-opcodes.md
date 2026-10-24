# The AI bytecode machine of the ordinary monsters: all opcodes of ids 0x00-0x53

Tags: **[V]** executed in the interpreter and the model checked against it, **[C]** read from the disassembly, not executed. Everything in sections 1-4 is **[V]** unless marked: the model `tools/ai_vm.py` was compared with the real AI step `$C1:2552` in 6,000 randomised steps for **each** of the 84 monsters 0x00-0x53 and for 0x54-0x56 (0 mismatches, every reachable instruction executed, both outcomes of every conditional executed; `tools/monster_model.py`), and each modelled op was compared one handler at a time (`tools/ai_ops.py --fuzz`, 400 random cases per op, 112 ops, 0 mismatches; EA also with the monster in slots 4 and 5, `--slot`). `tools/ai_ops.py --new20` runs the cases of section 2 for the ops of ids 0x20-0x53. The scripts and the traces are exported by `tools/export_ai_vm.py` (`data/ai_vm_scripts.json`) and `tools/export_ai_traces.py`.

Earlier documents: the Rabite (`docs/rabite.md`, 33 ops), the Chobin Hood (`docs/monster-3.md`) and the Polter Chair (`docs/monster-13.md`) decode the first 39 ops; this document completes the set used by the scripts of ids 0x00-0x1F (76 distinct ops) and corrects one length (D6, section 5). The scripts of ids 0x20-0x53 (and 0x54-0x56) use the same ops plus four: 75 (target above), EA (cast on a whole side), EE (command 04) and 85, an undefined op that runs the error handler; the other ops they add to the list of section 3 (08, 0A, 0C, 15, 18, 1A, 29, 2A, 2B, 2D, 2E, 60, E5) belong to families already modelled.

## 1. The machine

- The AI step `$C1:2552` (monster in slot Y) calls the op handler `$C1:251A` (table `$C1:2257`, 256 words, undefined ops point at the error handler) up to 256 times; a handler returns FF (continue) or 00 (yield). After the step `$C1:24D7` mirrors the direction bits of a command C1 / 40 when the status byte `obj+0x190` has bit 0x80 (confused), and `obj+0x14D` receives the command byte `obj+0x140`.
- **Error handler `$C1:0100`**: restarts the script at `entry + 3` (`entry` = word at ROM 0x100009 + 16 * id, relative to 0x104F15), clears the four variables, both targets (FF), the flags `obj+0x14C/0x14E` and the call depth, and sets command 0, then yields. It runs for RET at depth 0, for CALL when the depth would reach 16 (so the deepest legal call is the 15th), for an undefined op and when 256 ops ran without a yield.
- State (record offsets): pc `+0x144` (word); variables `var0` = `+0x146` low nibble, `var1` = `+0x146` high, `var2` = `+0x147` low, `var3` = `+0x147` high; saved position `+0x148` (x) and `+0x14A` (y - h); depth `+0x14F`, return words `+0x150 + 2k` (popped words stay in place); current target slot `+0x1AC`, second target slot `+0x1AD` (FF = none); command bytes `+0x140..+0x143`.
- Jump offsets: one byte with bit 7 set (7-bit signed: 0x80-0xBF = +0..+63, 0xC0-0xFF = -64..-1) or two bytes (15-bit signed, big endian, bit 14 is the sign); the target is relative to the first byte after the offset. A conditional op is written `op args offset`.
- **Object reference** (argument of the field ops and of 5F/60): 0-2 hero slot, 0x80 the monster itself, 0x81 the slot in `+0x1AC`, 0x82 the slot in `+0x1AD`; the field address is `record + 0x180 + offset argument`. With an empty target (FF) the handlers read whatever lies below the object table; the model reports this as an error and the scripts guard it (the test steps that start from an injected state which does not satisfy the guard are skipped and counted).
- **Valid hero** (`$C1:054A`): active byte (`+0x00`) == 1, not the monster itself, on screen (x < 256 and y - h < 224, both as 16-bit unsigned), status word `+0x190` has none of the bits 0x8460. "On screen" without the status test (`$C1:0526`) is used for the targets.
- **Distance class** (`$C1:0358`): 1, 2, 4, 8, 0x10, 0x30 for a distance up to 16, 32, 48, 64, 96 px or more (sum of squares compared with 0x100, 0x400, 0x900, 0x1000, 0x2400, 16-bit sum); 8 when a coordinate offset is 256 or more.
- **Direction routine** (`$C1:0404`, `ai_vm.direction`): from the offsets |dx|, |dy| (y minus jump height) it returns two bytes. low byte: high nibble = alternate code (1 right / 2 left, | 4 down / 8 up, always diagonal), low nibble = primary code (the major axis only when (big - small) * 3/4 >= small, else the diagonal). High byte: bits 7-4 = high nibble of the smaller offset, bits 3-0 = the alternate code masked to the major axis (3 horizontal, 0xC vertical; horizontal wins ties). The lane ops test "smaller offset below 16" through `hi & 0xF3` / `0xFC`. An offset of 256 or more is folded to 0x100 - (low byte) with its sign flipped.

## 2. The ops

Length = bytes including the jump offset (1-byte form). "J" = conditional, the jump is taken when the condition holds. Monsters = ids that use the op (section 5).

### Control flow and variables [V]

| op | name | length | meaning |
|---|---|---|---|
| 00 | ret | 1 | pop the return address; depth 0: error handler |
| 7D-9C, A2, A3, C2, C3, D9, DD, DE, F8 | undefined | - | the handler table entry is the error handler `$C1:0100`: restart (effect `restart`). Id 0x34 reaches 85: its start-up code `2E29 if_field_gt 80 02 35` (HP low byte > 0x35) jumps to `2FB2`, the offset byte of the `if_var3_nz` at `2FB1`: a monster 0x34 whose HP low byte is above 0x35 restarts at entry + 3 (`2DE7`), which skips the start-up code |
| 01 | jmp | 2 | jump |
| FF | call | 3 | push pc+3, jump to the big-endian address |
| 02-05 | if_var0..3_nz | 2 | J: var k != 0 |
| 06-09 | if_var0..3_z | 2 | J: var k == 0 |
| 0A-0D | if_var0..3_ne | 3 | J: var k != arg |
| 0E-11 | if_var0..3_eq | 3 | J: var k == arg |
| 12-15 | if_var0..3_gt | 3 | J: var k > arg |
| 16-19 | if_var0..3_lt | 3 | J: var k < arg |
| 1A-1D | inc_var0..3 | 1 | var = (var + 1) & 15 |
| 1E-21 | dec_var0..3 | 1 | var = (var - 1) & 15 |
| 22-24 | var1..3 = var0 | 1 | copy |
| 25-28 | set_var0..3 | 2 | var = arg & 15 |
| 29-2C | rnd_var0..3 | 2 | var = random 0..(arg & 15): none drawn when 0, else bytes of `$C1:26FB` are drawn (low nibble) until one is <= the bound |

### Object fields [V]

| op | name | length | meaning |
|---|---|---|---|
| 2D / 2E | if_field_and_nz / _z | 5 | J: byte(ref, off) & arg3 != 0 / == 0 |
| 2F / 30 | if_field_lt / _gt | 5 | J: byte < arg3 / > arg3 |
| BA / BB | if_word_and_nz / _z | 6 | J: word & word(arg3, arg4) != 0 / == 0 (little endian) |
| BC / BD | if_word_lt / _gt | 6 | J: word < / > word(arg3, arg4) |
| DA / DB / DC | field_or / _and / _set | 4 | byte(ref, off) |= / &= / = arg3 (effect `set`) |

Fields the scripts of 0x00-0x1F read: self `+0x182` HP (BD), `+0x1ED` weapon gauge, `+0x19D`, `+0x1AC` (target slot); target (0x81) `+0x181` level (hero), `+0x190` status word, `+0x19D`, `+0x1B8`, `+0x1BB`, `+0x1BD` (word); second target (0x82) `+0x182` HP, `+0x190`, `+0x19D`. The meaning of `+0x19D`, `+0x1B8`, `+0x1BB`, `+0x1BD` is not known (they are tested against 0 or a constant). Written: self `+0x1ED` (DC: set to 0, and 0x62 by id 0x15).

Ids 0x20-0x53 also read: hero slots 0-2 directly (refs 0, 1, 2: `+0x191`, `+0x182` HP, script 0x5605 of ids 0x20/0x2E/0x3F/0x56); self `+0x186` MP, `+0x1B8`, `+0x1BD` (word), `+0x1E7`, `+0x199` (word), `+0x190` (word); target `+0x180` (id), `+0x1AA` (word), `+0x1AE`, `+0x1B8`, `+0x1BD` (word); second target `+0x1AE`, `+0x1B8`, `+0x1BD` (word), `+0x182`. Written by DC on self: `+0x186` (MP, ids 0x42 0x48), `+0x191` (status high byte), `+0x1AA`, `+0x1AB` (script 0x5605), `+0x1ED`.

### Targets and distances [V]

| op | name | length | meaning |
|---|---|---|---|
| 31 / 49 / 4E / 53 | if_no_hero_16 / 32 / 48 / 64 | 2 | J: no valid hero within the distance |
| 58 | if_no_hero_onscreen | 2 | J: no valid hero on screen |
| A5 / B1 / B4 / B7 | tgt_within_16 / 32 / 48 / 64 | 1 | current target = first valid hero (slot order) within the distance, FF if none |
| 5D | tgt_far | 1 | current target = first valid hero farther than 64 px |
| 34 / 4C / 51 / 56 | if_tgt_not_within_16 / 32 / 48 / 64 | 2 | J: the current target is not on screen or farther |
| 46 | if_tgt_not_band_64 | 2 | J unless the target is on screen and in distance class 8 |
| 5A | if_tgt_not_beyond_64 | 2 | J unless the target is on screen and in class 0x10 or 0x30 |
| 66 / 68 / 6A | if_tgt_not_lane_v64 / v48 / v | 2 | J unless on screen, `hi & 0xF3` == 0 (offset in x below 16, vertical major axis) and class <= 8 / 4 / any |
| 6F / 71 / 73 | if_tgt_not_lane_h64 / h48 / h | 2 | J unless `hi & 0xFC` == 0 (offset in y below 16, horizontal major) and class <= 8 / 4 / any |
| 75 / 77 / 79 / 7B | if_tgt_not_above / below / left / right | 2 | J unless on screen and `hi & 8` / `& 4` / `& 2` / `& 1` (side on the major axis); 75 is used by ids 0x37 and 0x46 |
| 5F / 60 | if_obj_outside / inside | 3 | J if object ref arg1 is outside / inside 8 <= x <= 248 and 8 <= y - h <= 216 (signed 16-bit) |
| 9F | pos_save | 1 | saved position = (x, y - h) |
| 9D / 9E | if_pos_same / moved | 2 | J if the position equals / differs from the saved one |
| 54 | if_no_ally_64 | 2 | J: none of the slots 3-5 (not the monster itself) is valid, has id < 0x80 (`+0x180`) and is within class 8 |
| D8 | tgt2_ally | 1 | second target = such a slot (FF if none) |
| F5 | if_crowd_gt | 3 | J: more than arg of the slots 3-5 (the monster included) are active and on screen |
| C0 / C1 / C4 | tgt2_none / tgt2_cur / tgt2_self | 1 | second target = FF / the current target / own slot |

### Commands [V]; every one writes `obj+0x140..0x143` and yields unless noted

| op | name | length | command bytes |
|---|---|---|---|
| E0 | hop | 4 | C1, arg1 (direction), arg2 (animation), arg3 (flag) |
| E2 | pose | 2 | 40, arg1 (animation) |
| E3 | turn_facing | 3 | C1, code of the facing byte `+0x10` (0 up 8, 1 down 4, 2 right 1, other left 2) when `+0x06/+0x07` are 0, arg1, arg2. When the actor moves the sign test reads a byte of the stack page [C]; not used with velocity in any test |
| E4 / E5 | move_toward (target / second target) | 3 | C1, primary code, arg1, arg2; no yield and no command when the target is not on screen |
| E6 / E7 | move_away | 3 | C1, primary code computed from the target to the monster, arg1, arg2 |
| FD / FE | move_toward_alt / away_alt | 3 | the alternate (diagonal) code |
| BE / BF | move_toward_card / away_card | 3 | the cardinal code (`hi & 0xF`) |
| E8 | swing | 1 | gauge `+0x1ED` == 0: `+0x19B` = `+0x1C0` (weapon level nibble), command 02; else continue |
| ED | cmd43 | 2 | 43, arg1 |
| EF | cmd81 | 3 | 81, arg1, arg2 |
| E9 | cast | 3 | success (second target on screen, MP `+0x186` >= attack cost (`$D0:2ADF + 0x40 * arg2`, byte 0), status bit 0x80 clear, `+0x60` != 0xE0): command 44, arg1; `+0x170` = arg2, `+0x176` = 1, `+0x177` = 0, `+0x178` = second target + 1, `+0x179` = `+0x17A` = 0, then `JSL $C0:001B` (effect `cast`). Failure: C1, facing code, 0, 5 |
| EE | cmd04 | 1 | 04 (only byte 0 is written); used by script 0x5605 (ids 0x20, 0x2E, 0x3F, 0x56) |
| EA | cast_all | 3 | cast on a whole side (`$C1:1E98`, id 0x2D: `EA 04 1A`), see below |
| FC | flash | 1 | when `+0x191 & 0xDF` == 0: `+0x1E3` = `+0x1E9`; `+0x1E4` = `(+0x1E4 & 0x80) ^ 0x80`; `+0x1E3` = `+0x1E8` if that bit is now 0; `+0x1E4` |= table byte `$D0:1000 + 12 * n` (n = `+0x1E9` if bit 7 set else `+0x1E8`); `JSL $C0:003C` (effect `flash`); continue |

**EA anim spell** (`$C1:1E98`), written as in `ai_vm.py`:

```
cost = byte 0 of the attack record 0x102ADF + 0x40 * spell
if not (MP(+0x186) >= cost or (+0x60 != 0xE0 and not (+0x190 & 0x80))):     # E9 requires all three; EA's MP test is inverted (BCS)
    cmd = C1, facing code, 0, 5;  pc += 3;  yield                              # +0x176..+0x17A untouched
+0x176..+0x17A = 0
if tgt2 < 3:  side = 0; ok = valid_hero(slot 0)                                # $C1:054A
else:         side = 3; ok = valid(slot 3) and id(slot 3) < 0x80               # $C1:058B; tgt2 = 3, 4, 5 or FF
if not ok: cmd = C1, facing code, 0, 5;  pc += 3;  yield
+0x178, +0x179, +0x17A = side + 1, side + 2, side + 3;  +0x176 = 3
cmd = 44, anim;  +0x170 = spell;  JSL $C0:001B (effect ('cast_all', spell, [side, side + 1, side + 2]));  pc += 3;  yield
```

The two target loops never advance their object pointer (X stays `$E000` / `$E600`): the hero loop tests slot 0 three times and lists the slots 0, 1, 2 whenever hero 0 is valid, whatever the state of heroes 1 and 2; the monster loop tests slot 3 three times. The self test of `$C1:054A` compares X with Y, and Y is incremented after each slot found, so slot 3 is excluded only when the caster itself is in slot 3 (then the cast always fails on the monster side). Second target 0-2 selects the heroes even when the second target itself is invalid; the second target is not tested for being on screen. Checked case by case (`ai_ops.py --new20`) and by the fuzz with the caster in slots 3, 4 and 5.

The flags of the movement commands are the length in frames (docs/monster-3.md section 6). The game routines behind the commands 43, 44 and 81 and the engine calls `$C0:001B` (starts the cast; afterwards it rewrites `+0x170..+0x178`) and `$C0:003C` (object graphic refresh; rewrites `+0x196`, `+0x198`, `+0x199`, `+0x19C`, `+0x1E3`, `+0x1E4`, `+0x1E8`, `+0x1E9`, `+0x1F7`) are not part of the machine; in the tests they are replaced by no-ops and only reported as effects.

## 3. Which monsters use which op

| op | name | ids |
|---|---|---|
| 00 | ret | all (00-53) |
| 01 | jmp | all (00-53) |
| 02 | if_var0_nz | 0A 1E 20 2E 3F |
| 03 | if_var1_nz | 09 0A 1E 39 3A 4C 4F 52 |
| 04 | if_var2_nz | 01 02 04 06 08 09 0A 0B 0C 0E 0F 10 11 12 13 15 18 1C 1D 1E 1F 21 22 23 24 25 26 27 28 29 2A 2B 2F 31 33 34 36 37 38 3A 3B 3D 3E 40 41 43 44 46 47 48 49 4A 4B 4D 4E 4F 50 51 52 |
| 05 | if_var3_nz | all (00-53) |
| 09 | if_var3_z | 00 |
| 0A | if_var0_ne | 20 2E 3F |
| 0B | if_var1_ne | 09 19 1E 30 36 |
| 0C | if_var2_ne | 3A 3B 4B |
| 0D | if_var3_ne | all (00-53) |
| 15 | if_var3_gt | 20 22 2E 36 3F 4D 4F 53 |
| 17 | if_var1_lt | 07 08 0B 13 19 1A 22 26 27 2F 38 3A 40 44 45 4A 4B 4C |
| 18 | if_var2_lt | 4C |
| 1A | inc_var0 | 20 2E 3F |
| 1E | dec_var0 | 0A 1E |
| 1F | dec_var1 | 07 08 0A 0B 13 19 1A 1E 22 26 27 2F 38 3A 40 44 45 4A 4B 4C |
| 20 | dec_var2 | 01 02 04 06 08 09 0A 0B 0C 0E 0F 10 11 12 13 15 18 1C 1D 1E 1F 21 22 23 24 26 27 28 29 2A 2B 2F 31 33 34 36 37 38 3A 3D 3E 40 41 43 44 46 47 48 49 4A 4B 4D 4E 4F 50 51 52 |
| 21 | dec_var3 | 1E 39 3A 41 4D |
| 25 | set_var0 | 0A 1E 20 2E 3F |
| 26 | set_var1 | 07 08 09 0A 0B 13 19 1A 1E 22 26 27 2F 30 36 38 39 3A 40 44 45 4A 4B 4C 4F 52 |
| 27 | set_var2 | 01 02 04 06 08 09 0A 0B 0C 0E 0F 10 11 12 13 15 18 1C 1D 1E 1F 21 22 23 24 25 26 27 28 29 2A 2B 2F 31 33 34 36 37 38 3A 3B 3D 3E 40 41 43 44 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 |
| 28 | set_var3 | 1E 39 3A 41 44 4D |
| 2B | rnd_var2 | 3A 4A 4B |
| 2C | rnd_var3 | all (00-53) |
| 2D | if_field_and_nz | 39 |
| 2E | if_field_and_z | 20 2E 3F 4C |
| 2F | if_field_lt | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2F 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| 30 | if_field_gt | 00 01 02 03 04 05 06 07 08 0A 0B 0C 0D 0E 0F 10 11 12 14 15 16 18 19 1A 1B 1C 1D 1E 1F 20 21 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 31 33 34 35 36 37 38 3A 3B 3C 3D 3E 3F 40 41 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 50 51 52 53 |
| 31 | if_no_hero_16 | all (00-53) |
| 34 | if_tgt_not_within_16 | 04 05 08 09 0A 0C 0D 0E 10 11 12 16 17 1B 1E 1F 20 24 27 2B 2D 2E 30 32 34 35 36 38 3B 3C 3F 41 42 43 44 45 47 48 4B 50 51 53 |
| 46 | if_tgt_not_band_64 | 06 |
| 49 | if_no_hero_32 | all (00-53) |
| 4C | if_tgt_not_within_32 | 00 01 02 04 05 06 08 09 0A 0B 0C 0D 0E 0F 10 12 14 15 16 18 19 1A 1C 1D 1E 1F 20 21 23 24 25 27 28 29 2A 2B 2C 2D 2E 30 31 32 33 34 36 37 38 3B 3C 3D 3E 3F 41 43 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| 4E | if_no_hero_48 | all (00-53) |
| 51 | if_tgt_not_within_48 | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0E 0F 10 11 13 14 15 16 18 19 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2E 2F 30 31 32 33 34 35 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| 53 | if_no_hero_64 | all (00-53) |
| 54 | if_no_ally_64 | 07 0B 0C 11 14 1A 1F 22 39 40 |
| 56 | if_tgt_not_within_64 | 00 01 02 03 04 05 06 07 08 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 18 19 1A 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 32 33 34 35 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| 58 | if_no_hero_onscreen | all (00-53) |
| 5A | if_tgt_not_beyond_64 | 06 12 19 25 28 2B 30 52 53 |
| 5D | tgt_far | all (00-53) |
| 5F | if_obj_outside | 04 05 07 08 09 0A 0B 0C 0F 10 11 12 13 14 15 1A 1B 1D 1E 22 23 25 26 27 29 2B 2C 2D 2F 30 32 33 35 36 37 38 39 3A 3B 3C 40 41 42 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 51 52 53 |
| 60 | if_obj_inside | 2C |
| 66 | if_tgt_not_lane_v64 | 01 05 0B 0E 11 16 1A 1C 20 24 25 29 2E 31 33 34 37 3C 3E 3F 41 43 46 47 48 49 4B 4D 4E 52 53 |
| 68 | if_tgt_not_lane_v48 | 07 1A 24 3A 47 |
| 6A | if_tgt_not_lane_v | 03 0B 0C 0E 11 12 1C 2C 43 |
| 6F | if_tgt_not_lane_h64 | 05 0B 0E 11 16 1A 1C 20 24 25 2E 31 33 34 37 3C 3E 3F 41 43 46 47 48 49 4B 4D 4E 52 53 |
| 71 | if_tgt_not_lane_h48 | 07 0F 1A 1D 24 3A 47 |
| 73 | if_tgt_not_lane_h | 03 0B 0C 0E 11 12 1C 2C 43 |
| 75 | if_tgt_not_above | 37 46 |
| 77 | if_tgt_not_below | 01 29 |
| 79 | if_tgt_not_left | 18 |
| 7B | if_tgt_not_right | 18 |
| 85 | undefined | 34 |
| 9D | if_pos_same | 00 01 02 03 04 05 06 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 33 34 35 36 37 38 39 3B 3C 3D 3E 3F 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| 9E | if_pos_moved | 02 04 06 08 09 0A 0B 0C 0E 0F 10 11 12 13 15 18 1C 1D 1E 1F 22 23 24 26 27 28 2A 2B 2F 31 33 34 36 37 38 3A 3D 3E 40 41 43 44 46 47 48 49 4B 4E 4F 50 52 |
| 9F | pos_save | 00 01 02 03 04 05 06 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| A5 | tgt_within_16 | all (00-53) |
| B1 | tgt_within_32 | all (00-53) |
| B4 | tgt_within_48 | all (00-53) |
| B7 | tgt_within_64 | all (00-53) |
| BA | if_word_and_nz | 02 04 0A 0F 10 12 13 15 2B 3A 3B 42 45 4A 51 |
| BB | if_word_and_z | 07 10 15 1A 22 2B 3B 40 42 49 4A |
| BC | if_word_lt | 1A 1E 20 2E 3F 4C |
| BD | if_word_gt | 00 04 05 06 07 09 0D 12 14 19 1A 1D 1F 20 21 22 23 25 2B 2C 2D 2E 2F 30 32 34 3E 3F 40 43 46 48 49 4C 50 51 52 |
| BE | move_toward_card | 01 03 07 09 0A 0B 0C 0D 0E 0F 10 11 12 13 16 17 19 1A 1C 1D 20 21 22 23 24 25 26 2E 31 33 34 37 39 3A 3C 3D 3E 3F 41 43 44 46 47 48 49 4A 4B 4D 4E 52 |
| BF | move_away_card | 0C 0D 18 1C 21 23 25 33 34 3D 43 48 49 4A 4E |
| C0 | tgt2_none | 04 05 07 09 0A 0B 0C 0E 0F 10 11 12 13 14 15 17 18 19 1A 1B 1C 1D 1E 1F 21 22 23 24 26 29 2A 2B 2C 2D 2F 30 31 32 33 34 35 36 37 39 3A 3B 3C 3D 3E 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 50 51 52 53 |
| C1 | tgt2_cur | 04 05 09 0A 0B 0C 0F 10 11 12 13 14 15 17 1A 1B 1D 1E 22 23 26 29 2B 2C 2D 2F 30 32 33 35 36 37 39 3A 3B 3C 40 41 42 44 45 46 47 48 49 4A 4B 4C 4D 4E 52 53 |
| C4 | tgt2_self | 0E 14 18 19 1C 1F 21 23 24 2A 31 34 36 3D 3E 40 42 43 45 47 48 49 4C 4D 4E 50 51 52 53 |
| D8 | tgt2_ally | 07 0B 0C 11 14 1A 1F 22 39 40 |
| DC | field_set | 03 0A 0E 15 19 1C 1E 1F 20 2E 33 3F 42 48 4B 4E 50 52 |
| E0 | hop | all (00-53) |
| E2 | pose | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2F 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| E3 | turn_facing | all (00-53) |
| E4 | move_toward | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 11 12 13 14 15 16 17 18 1A 1B 1C 1D 1E 1F 20 22 23 24 27 28 29 2A 2B 2C 2D 2E 2F 30 31 34 35 36 37 38 39 3A 3B 3C 3D 3F 40 41 42 43 44 45 46 47 48 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| E5 | move_toward2 | 4D |
| E6 | move_away | 00 02 03 04 05 06 0A 0B 0C 0F 11 16 18 1D 1E 22 25 28 29 2A 2C 30 34 35 37 39 3B 3C 3D 40 41 45 46 4C 4F 51 |
| E8 | swing | 00 01 02 03 04 05 06 07 08 0A 0B 0C 0D 0E 0F 10 11 12 14 15 16 18 19 1A 1B 1C 1D 1E 1F 20 21 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 31 33 34 35 36 37 38 3A 3B 3C 3D 3E 3F 41 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 50 51 52 53 |
| E9 | cast | 04 05 07 09 0A 0B 0C 0E 0F 10 11 12 13 14 15 17 18 19 1A 1B 1C 1D 1E 1F 21 22 23 24 26 29 2A 2B 2C 2F 30 31 32 33 34 35 36 37 39 3A 3B 3C 3D 3E 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 50 51 52 53 |
| EA | cast_all | 2D |
| ED | cmd43 | 07 08 0B 13 1A 1D 22 25 26 27 2F 38 3A 40 42 44 45 4A 4B 4C 4F |
| EE | cmd04 | 20 2E 3F |
| EF | cmd81 | 17 1D 2C 42 48 4F |
| F5 | if_crowd_gt | 07 08 0B 13 1A 22 23 25 26 27 2F 38 3A 40 44 45 4A 4B 4C 4F |
| FC | flash | 01 02 05 06 0B 0E 12 16 18 29 2A 2C 31 34 36 37 3A 3C 3D 43 45 46 48 4D 53 |
| FD | move_toward_alt | 00 01 02 03 04 05 06 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 |
| FE | move_away_alt | 00 02 03 04 05 06 0A 0B 0C 0D 0F 11 14 16 1C 1D 1E 21 22 23 25 26 28 29 2A 2C 30 33 34 35 37 39 3B 3C 3D 40 41 44 45 46 48 49 4A 4C 4D 4F 51 |
| FF | call | all (00-53) |

## 4. Commands issued by the scripts (static)

Command C1: animation ids and flags that appear in the move ops (the direction of E0 and the code of the targeting ops are not listed); 40: pose animations; 02: swing; 04: op EE; 43 / 44 / 81: op arguments (44: animation, attack index; "on a side (EA)": the cast of op EA).

| id | commands |
|---|---|
| 00 | C1 anim 0,1,2,4,5 flag 0; 40 anim 0,5; 02 |
| 01 | C1 anim 0,1,2,4,5 flag 0,5; 40 anim 0; 02 |
| 02 | C1 anim 0,1,2,4,14 flag 0,5,10; 40 anim 0; 02 |
| 03 | C1 anim 0,1,2,4 flag 0,5; 40 anim 0; 02 |
| 04 | C1 anim 0,1,2,4 flag 0,10; 40 anim 0,4,6; 02; 44 (anim,spell) (3,30) |
| 05 | C1 anim 0,1,2,3,4,14 flag 0,5; 40 anim 0,6; 02; 44 (anim,spell) (7,7) |
| 06 | C1 anim 0,1,2,4,14 flag 0,5,30; 40 anim 4,5; 02 |
| 07 | C1 anim 0,1,2,4 flag 0,5,180; 40 anim 0,3; 02; 43 arg 3; 44 (anim,spell) (2,10) (2,11) |
| 08 | C1 anim 0,1,2,4,5 flag 0,10; 40 anim 0,6; 02; 43 arg 8 |
| 09 | C1 anim 0,1,2,3,4,11 flag 0,5,15,30,180; 40 anim 3; 44 (anim,spell) (1,6) (1,8) |
| 0A | C1 anim 0,1,2,4,5 flag 0,5,10,60,120; 40 anim 0; 02; 44 (anim,spell) (3,22) |
| 0B | C1 anim 0,1,2,4,14 flag 0,5,10; 40 anim 0,7; 02; 43 arg 14; 44 (anim,spell) (3,1) (3,2) (3,11) |
| 0C | C1 anim 0,1,2,4,5 flag 0,5,10,30; 40 anim 0; 02; 44 (anim,spell) (4,7) (4,11) |
| 0D | C1 anim 0,1,2,4,5 flag 0,60; 40 anim 0; 02 |
| 0E | C1 anim 0,1,2,4,5,14 flag 0,5,10; 40 anim 7; 02; 44 (anim,spell) (3,5) |
| 0F | C1 anim 0,1,2,4 flag 0,15,60,180; 40 anim 0; 02; 44 (anim,spell) (4,12) (4,17) |
| 10 | C1 anim 0,1,2,4,5 flag 0,5,15,180; 40 anim 0; 02; 44 (anim,spell) (5,30) |
| 11 | C1 anim 0,1,2,4,5,14 flag 0,5,10,180; 40 anim 0; 02; 44 (anim,spell) (4,7) (4,9) (4,11) |
| 12 | C1 anim 0,1,2,4,5,11 flag 0,5,10,60; 40 anim 5; 02; 44 (anim,spell) (4,2) |
| 13 | C1 anim 0,1,2,4,5 flag 0,5,15,180; 40 anim 0,3; 43 arg 22; 44 (anim,spell) (1,18) (1,19) (1,20) |
| 14 | C1 anim 0,1,2,4,5 flag 0,5,120; 40 anim 0,5; 02; 44 (anim,spell) (4,7) (4,8) (4,11) (4,12) |
| 15 | C1 anim 0,1,2,4,5 flag 0,5,10; 40 anim 0; 02; 44 (anim,spell) (2,18) (2,20) |
| 16 | C1 anim 0,1,2,4,14 flag 0,5,10,15; 40 anim 0; 02 |
| 17 | C1 anim 0,1,2,4 flag 0,10,180; 40 anim 0,1,3; 44 (anim,spell) (2,31); 81 arg (5,254) |
| 18 | C1 anim 0,1,2,4,5,8 flag 0,5,15,180; 40 anim 0,4; 02; 44 (anim,spell) (3,21) |
| 19 | C1 anim 0,1,2,4,5 flag 0,5,15,30; 40 anim 0,2; 02; 44 (anim,spell) (3,4) |
| 1A | C1 anim 0,1,2,4 flag 0,5,180; 40 anim 0,3; 02; 43 arg 51; 44 (anim,spell) (2,10) (2,11) (2,38) |
| 1B | C1 anim 0,1,2,3,4,5,14 flag 0,5,60; 40 anim 2; 02; 44 (anim,spell) (5,2) |
| 1C | C1 anim 0,1,2,4,14 flag 0,5,10,60; 40 anim 0; 02; 44 (anim,spell) (2,15) |
| 1D | C1 anim 0,1,2,4 flag 0,15,60,180; 40 anim 0; 02; 43 arg 29; 44 (anim,spell) (4,6) (4,7); 81 arg (5,251) |
| 1E | C1 anim 0,1,2,4,5 flag 0,5,10,120; 40 anim 0; 02; 44 (anim,spell) (3,38) |
| 1F | C1 anim 0,1,2,3,4,5,14 flag 0,5,10,60; 40 anim 0,2; 02; 44 (anim,spell) (8,11) (8,28) |
| 20 | C1 anim 0,1,2,3,4,10,11,12,49 flag 0,5,10,15; 02; 04 |
| 21 | C1 anim 0,1,2,4,5 flag 0,5; 40 anim 0,3,6,7,12; 02; 44 (anim,spell) (4,27) |
| 22 | C1 anim 0,1,2,4 flag 0,5,10,15,60; 40 anim 0,2,3; 43 arg 18; 44 (anim,spell) (1,5) (1,10) (1,11) (1,12) |
| 23 | C1 anim 0,1,2,4,5 flag 0,5,10; 40 anim 0,2,3,4,7,8; 02; 44 (anim,spell) (5,6) (5,8) (5,18) (5,19) (5,41) |
| 24 | C1 anim 0,1,2,4,5,8,14 flag 0,5,10,15; 40 anim 0,3; 02; 44 (anim,spell) (4,5) |
| 25 | C1 anim 0,1,2,4 flag 0,5,10; 40 anim 0,5,7; 02; 43 arg 23 |
| 26 | C1 anim 0,1,2,4,5,14 flag 0,10,120; 40 anim 0,1,5; 02; 43 arg 38; 44 (anim,spell) (4,14) |
| 27 | C1 anim 0,1,2,4,5 flag 0,10; 40 anim 0,6; 02; 43 arg 39 |
| 28 | C1 anim 0,1,2,3,4,7,11,14 flag 0,5,10,15,30,60; 40 anim 0,3; 02 |
| 29 | C1 anim 0,1,2,4,5 flag 0,5,120; 40 anim 0; 02; 44 (anim,spell) (4,13) |
| 2A | C1 anim 0,1,2,4,14 flag 0,5,10; 40 anim 1; 02; 44 (anim,spell) (6,34) |
| 2B | C1 anim 0,1,2,4,5 flag 0,5,10; 40 anim 0,4,7; 02; 44 (anim,spell) (3,8) (3,30) |
| 2C | C1 anim 0,1,2,3,4,5,14 flag 0,5,120; 40 anim 0,6; 02; 44 (anim,spell) (7,6) (7,7); 81 arg (5,44) |
| 2D | C1 anim 0,1,2,4,9,14 flag 0,5,180; 40 anim 0,3,5; 02; 44 on a side (EA) (anim,spell) (4,26) |
| 2E | C1 anim 0,1,2,3,4,10,11,12,49 flag 0,5,10,15; 02; 04 |
| 2F | C1 anim 0,1,2,4,5 flag 0,5,15,180; 40 anim 0,3; 43 arg 49; 44 (anim,spell) (1,6) (1,8) (1,18) (1,19) (1,20) |
| 30 | C1 anim 0,1,2,3,4,11 flag 0,30,180; 40 anim 0,3; 44 (anim,spell) (1,8) (2,6) (2,8) |
| 31 | C1 anim 0,1,2,4,5,14 flag 0,5,10,15,180; 40 anim 0,3; 02; 44 (anim,spell) (5,34) |
| 32 | C1 anim 0,1,2,4 flag 0,5,240; 40 anim 0,2; 44 (anim,spell) (1,0) (1,1) |
| 33 | C1 anim 0,1,2,4 flag 0,5,10,15,120; 40 anim 0,2; 02; 44 (anim,spell) (3,40) |
| 34 | C1 anim 0,1,2,4,7,11 flag 0,5,10,120; 40 anim 3,4,7; 02; 44 (anim,spell) (5,9) (5,11) |
| 35 | C1 anim 0,1,2,3,4 flag 0,60; 40 anim 2; 02; 44 (anim,spell) (5,2) (5,7) |
| 36 | C1 anim 0,1,2,3,4 flag 0,5,10,60; 40 anim 0,3,4; 02; 44 (anim,spell) (4,2) (4,4) |
| 37 | C1 anim 0,1,2,4,5,14 flag 0,5,10,180; 40 anim 0; 02; 44 (anim,spell) (5,12) (5,13) (5,16) |
| 38 | C1 anim 0,1,2,4,5 flag 0,5,10; 40 anim 0,6; 02; 43 arg 56 |
| 39 | C1 anim 0,1,2,3,4 flag 0,60,180; 40 anim 0; 44 (anim,spell) (1,25) (3,26) (3,29) |
| 3A | C1 anim 0,1,2,4,5 flag 0,10,60,240; 40 anim 0,4; 02; 43 arg 30; 44 (anim,spell) (3,13) (3,14) (3,37) |
| 3B | C1 anim 0,1,2,4,5,14 flag 0,5,60,180; 40 anim 0,5; 02; 44 (anim,spell) (4,20) (4,22) (4,30) |
| 3C | C1 anim 0,1,2,4,5,14 flag 0,5,10,15,60; 40 anim 0; 02; 44 (anim,spell) (4,0) |
| 3D | C1 anim 0,1,2,4,8 flag 0,5,15,180; 40 anim 0,1,4; 02; 44 (anim,spell) (3,39) |
| 3E | C1 anim 0,1,2,3,4,5,19,20 flag 0,10,15,60; 40 anim 3; 02; 44 (anim,spell) (2,5) |
| 3F | C1 anim 0,1,2,3,4,10,11,12,49 flag 0,5,10,15; 02; 04 |
| 40 | C1 anim 0,1,2,4 flag 0,5,10,15,60; 40 anim 0,2,3; 43 arg 0,60; 44 (anim,spell) (1,5) (1,10) (1,11) (1,41) |
| 41 | C1 anim 0,1,2,4,14 flag 0,5,15; 40 anim 0,5; 02; 44 (anim,spell) (2,13) |
| 42 | C1 anim 0,1,2,4,5,14 flag 0,5,10,180,240; 40 anim 0,1,3; 43 arg 23; 44 (anim,spell) (2,30) (2,31) (2,34); 81 arg (5,254) |
| 43 | C1 anim 0,1,2,4,5,7,11 flag 0,5,10,120; 40 anim 2,3,4,7; 02; 44 (anim,spell) (5,27) (5,39) |
| 44 | C1 anim 0,1,2,4,5,14 flag 0,10; 40 anim 0,5; 02; 43 arg 68; 44 (anim,spell) (4,6) (4,7) (4,8) |
| 45 | C1 anim 0,1,2,4,14 flag 0,5,60,120,180; 40 anim 0,4; 02; 43 arg 40; 44 (anim,spell) (3,0) (3,1) (3,2) |
| 46 | C1 anim 0,1,2,4,14 flag 0,5,10,180; 40 anim 0; 02; 44 (anim,spell) (5,6) (5,7) (5,36) |
| 47 | C1 anim 0,1,2,4,5,8,14 flag 0,5,10,15; 40 anim 0,3; 02; 44 (anim,spell) (4,1) (4,5) |
| 48 | C1 anim 0,1,2,4,5,14 flag 0,5,10,15,60,180; 40 anim 5,7,8,11; 02; 44 (anim,spell) (6,2) (6,4) (6,15) (6,31); 81 arg (5,254) |
| 49 | C1 anim 0,1,2,4,5,14 flag 0,5,10,15,180; 40 anim 0,2,4; 02; 44 (anim,spell) (3,0) (3,30) (3,34) |
| 4A | C1 anim 0,1,2,3,4,5 flag 0,5,180; 40 anim 3,4; 02; 43 arg 27,53; 44 (anim,spell) (5,17) |
| 4B | C1 anim 0,1,2,4,5 flag 0,5,10,120,240; 40 anim 0,4; 02; 43 arg 77; 44 (anim,spell) (3,13) (3,14) (3,37) |
| 4C | C1 anim 0,1,2,4 flag 0,5; 40 anim 0,2,3,4,6,7,8; 02; 43 arg 55; 44 (anim,spell) (5,34) (5,36) (5,38) |
| 4D | C1 anim 0,1,2,3,4,5 flag 0,5,10,30,60,120; 40 anim 1,11; 02; 44 (anim,spell) (6,7) (6,9) (6,38) |
| 4E | C1 anim 0,1,2,3,4,14 flag 0,5,10,15,60,120; 40 anim 1,3,4; 02; 44 (anim,spell) (2,34) (2,37) |
| 4F | C1 anim 0,1,2,4 flag 0,5,10,30; 40 anim 0,6,9; 43 arg 79; 81 arg (5,0) (5,45) (5,53) (5,64) (5,65) (5,252) |
| 50 | C1 anim 0,1,2,3,4,5,14 flag 0,5,10,60; 40 anim 2,6; 02; 44 (anim,spell) (8,11) (8,27) (8,28) |
| 51 | C1 anim 0,1,2,4,5 flag 0,5,60; 40 anim 0,3,6,8,9,10,11,12; 02; 44 (anim,spell) (4,3) (4,9) (4,15) (4,21) |
| 52 | C1 anim 0,1,2,3,4,5 flag 0,5,10,15,60,180; 40 anim 3,4; 02; 44 (anim,spell) (2,40) (2,41) |
| 53 | C1 anim 0,1,2,3,4,5,14 flag 0,5,10,15,60,120; 40 anim 0,1,5,7,8,11; 02; 44 (anim,spell) (6,3) (6,13) (6,34) |

## 5. Corrections and open questions

- D6 (`$C1:0D20`, not used by ids 0x00-0x1F) is a conditional op of length 2; `tools/aidis.py` had it as length 1. All other lengths were re-checked by running every handler on a patched script (`0x80` fill: the advance equals the decoded length for all 256 ops; undefined ops go to the error handler).
- Scripts use no op that is not modelled. Ops modelled but not used by any of the scripts of 0x00-0x53 (22-24, DA/DB, E7, ...) are covered only by the one-handler check; 2D/2E, 60 and E5, unused by 0x00-0x1F, are used by ids 0x20-0x53 and covered by the script checks too.
- `tools/aidis.py` now knows the undefined ops (`aidis.UNDEF`, handler = `$C1:0100`): they do not fall through, so the static walk and the export stop there.
- The randomised worlds of `tools/monster_model.py` write both bytes of the word fields that a script tests on the monster itself (BA-BD with ref 0x80; before only the low byte was drawn): needed for `50BD BA 80 19 00 40` of id 0x51 (bit 6 of `+0x19A`).
- Op EA (section 2) and the undefined 85 of id 0x34 look like script / handler bugs of the game; the model reproduces them.
- Not decoded: the meaning of the fields `+0x19D`, `+0x1B8`, `+0x1BB`, `+0x1BD`, `+0x1AA`, `+0x1AE`, `+0x1E7`; what the commands 04 / 43 / 44 / 81 do in the actor state machine; the graphics refresh behind FC; the sign test of E3 with a moving actor (reads the stack page); the content of the empty-target read.


## Matching CALL/RET and restart sources [V]

`src/rom/actor_script_call.s` (C102B7,65 bytes) and `actor_script_return.s` (C102F8,54 bytes) assemble together as119 bytes. Error restart C10100 adds17 bytes. The shared program restart C1263C (92 bytes) and status-program call C12698 (99 bytes) also match; together with the existing C12599/C125B6 setup they form354 contiguous bytes. These are instruction sources, with no ROM binary inclusion.

`tools/actor_program_calls.py` performs2,560 original-routine comparisons:512 restarts,1,024 status-program calls,512 script CALLs and512 RETs. Full randomized WRAM agrees outside the33-byte native return/local-frame window; native stack balance, D/DB/M/X restoration and script low-A return are checked. Inputs include every byte depth and program id over six actor slots, rather than every cross-product combination.

Restart reads the program pointer at file offset100009+16*id and advances it by three (word wrapping), clears variables146/147, control flags14C/14D, auxiliary flags14E and depth14F, and sets both targets1AC/1AD toFF. The error wrapper additionally clears command140 and yields low A=00. Successful CALL/RET return low A=FF.

CALL writes the return PC before validating the incremented depth. Script CALL saves PC+3 and reads its big-endian operand from file104F16+PC; the status-program helper saves PC unchanged and selects the word at104ED3+((argument*2)&FF). Consequently status-call arguments alias modulo128. For malformed depths the saved-PC offset is150+((depth*2)&FF), so it can overwrite later actor fields, including actor id180, before the error restart reads that id. Both call paths accept depth255 wrapping to0. RET decrements first: depth0 restarts, depth16 decrements to15 and succeeds, and other resulting depths>=16 restart. These original behaviours are preserved, without assigning intended meanings to undefined program ids. Complete interpreter execution, every register return convention and hardware timing remain open.


## Relative flow, PC advance and packed variables [V]

Twenty-five additional instruction sources recover C10111..C102B6 (422 bytes). With the previously recovered error/CALL/RET blocks, the complete C10100..C1032D range assembles contiguously as558 bytes. This component reuses individual sources and adds no bytes to the count.

`tools/actor_program_branches.py` passes71,680 comparisons:65,536 direct C10245 jumps,1,024 C101F7 skips and5,120 calls through the ten wrappers that advance X by1..5 argument bytes before using those helpers. The direct jump tests every16-bit operand PC in the original ROM, covering all256 first bytes, short/long positive/negative forms and PC wrapping. Short form uses signed7-bit displacement; long form uses signed15-bit big-endian displacement. The final PC is after the operand plus displacement for jump, or just after the operand for skip. X returns at the final operand byte for jump and after it for skip; both return full A=FFFF and preserve incoming M. Reads use long ROM indexing, so the two-byte operand at X=FFFF reads the second ROM byte beyond that16-bit index before X itself wraps. Complete randomized WRAM is compared outside the nine-byte deepest native frame, together with full A/X/Y and native stack/D/DB/M/X restoration. ROM content is never patched or saved in the report.

`tools/actor_program_state.py` passes20,992 comparisons:2,048 packed-variable reads,16,384 writes and2,560 PC advances. Variables0/1 occupy the low/high nibbles of146;2/3 occupy147. Readers preserve the high accumulator byte; writers mask to the input low nibble, preserve the other field nibble, and return the written nibble positioned within the byte, also retaining high A. Each writer covers all256 original field bytes crossed with16 relevant input nibbles, with high argument nibbles varied. Their PHD/PHP frames restore the incoming accumulator mode. The five PC-advance helpers instead leave M16: C10111 advances by low incoming A and returns A=0000 (yield); C10121/C1012B/C1013B/C1014B advance by1..4 and return A=FFFF (continue). The one-byte advance also changes X to the actor base; the others retain X. Exact native frame exclusions are2 bytes for advances,5 for reads and6 for writes. Complete WRAM and full returned A/X/Y, S/D/DB/M/X agree. These helpers do not establish the full opcode predicates, dispatcher, controller path or physical timing.


## Matching dispatcher, complete-step control and variable handlers [V]

Fifty-five instruction sources add1,213 ROM bytes: the dispatcher C1251A, step C12552, confusion-direction adjustment C124D7, hero preemption C12457, controller mapping C104D3, facing C10502, fallback command C12534, highest-set-bit helper C12710,39 variable op handlers and eight target/command handlers. All variable operations02..28 now have matching instruction sources;29..2C random-variable selection remain open. The new512-byte `actor_opcode_handler_table.s` reconstructs every pointer at C12257. Named unrecovered entries remain explicit. Its values agree with the previous dispatch catalogue and the independently assembled original table; matching pointer data does not complete every handler.

`tools/actor_program_dispatch.py` passes10,304 original comparisons over complete randomized WRAM outside65 native return/frame bytes. Cases are512 bit-index,2,048 confusion,1,024 controller-mapping,2,048 preemption,512 facing,512 fallback,2,880 one-op dispatch and768 complete steps. The90 selected opcode values cover00..28, C0/C1/C4, E0/E2/ED/EE/EF/FF and the40 undefined values. Both outcomes of all24 variable predicates are asserted. Complete-step tests include121 actual256-op-loop error restarts across every actor slot, CALL/subroutine/RET, undefined-op restart, variable/target sequences, hop commands, hero preemption and confused direction adjustment. Bytecode is generated only in an in-memory ROM copy; original routine instructions and dispatch pointers stay unchanged. Native S/D/DB/M/X restoration and selected low-A/X returns are checked. Exact flags, every register convention and all other op semantics are outside this comparison.

C104D3 reads the low three bits of the controller-association word beginning at D9+(hero&3), then selects the highest set bit, returning the corresponding actor E000/E200/E400, or X=0 for no bit. C12710 returns the highest set bit index for a general16-bit X (FF for zero), leaving X equal to its bit length. C10502 maps facing0/1/2/other to8/4/1/2. The fallback writes command C1, that direction,0,5. The unknown meanings of record bytes11 and1C are not inferred from their preemption tests.

Hero preemption scans all three hero status words first. If any has a C57B bit, or no mapped actor meets byte11=2 and byte1C=0, it clears control-flags bit2 and allows bytecode to continue. Otherwise it restarts the current hero program, sets command7 on first activation or1 when prior control-flags bit2 was already set, and sets that bit after restart, yielding before the opcode loop. The full step normalizes X with1FFF|E000, selects this gate only belowE600, runs at most256 handlers, mirrors confused C1/40 directions, and finally copies command140 into14D. It restores incoming DB, even when the caller used another bank. Other high bits in the direction byte remain intact; horizontal and vertical pairs are inverted only when a bit in the respective pair is present.

Nine integrated components additionally check joins: controller mapping/facing83 bytes, increment/copy/zero-test235, immediate assignment60, argument comparisons344, target assignment34, command04/pose30, command43/8147, full preemption/step/program management676, and its preceding opcode table plus that program1,188. Component reuse does not increase totals. Complete gameplay, RNG-variable handlers, target/field/distance op handlers, malformed PC boundaries and timing remain unfinished.


## Original random-variable generator path [V]

Nine sources add122 instruction bytes: public RNG vector C00018, mirror C03800, preserving wrapper C03872, actor-bank wrapper C126FB, bounded-nibble helper C116F4 and four handlers C1171D/C11726/C1172F/C11738 (ops29..2C). The earlier matching additive generator is reused. Fixed/random assignment plus argument comparisons now build as481 contiguous bytes; the opcode table through the actor RNG wrapper builds as1,209 bytes. Components do not add duplicate bytes.

`tools/actor_program_random.py` passes9,216 original comparisons:512 public RNG calls,512 actor-wrapper calls,4,096 bounded-helper calls and4,096 original dispatches for the four variables. All argument bytes, all valid generator indices and every variable appear. It uses Claude's independent additive `rng.Rng` model, preserving the complete15-byte generator state, index03F0 and scratch03CC. No RNG or handler execution is replaced. Full randomized WRAM agrees outside65 native return/frame bytes, with S/D/DB/M/X restoration and low-A checked; actor-wrapper input DB aliases and both accumulator widths are included. Test bytecode arguments exist only in a transient ROM copy.

The bound is argument&0F. Bound0 returns0 without drawing or changing the generator. Otherwise low nibbles are drawn until a value<=bound appears; rejected values advance the generator normally. There are79,840 bounded draws,72,160 rejected values and512 zero-bound cases; the largest tested rejection sequence takes45 draws. Bounds are inclusive. In the fixed native stack used by the harness, direct zero-bound helper calls retain high A=1E from TSC, while drawing calls return high A=0F from the generator; dispatch subsequently returns FF to continue. This does not establish every stack placement, invalid index or seed sequence. Exact flags, exhaustive seed space and whole-game timing remain open.

## Complete reference bytes and field comparisons/writes [V]

Twelve sources add351 instruction bytes:87-byte reference helper C11FEB, eight byte/word comparisons at C12042..C1210D and three byte writers C1210E/C12124/C1213A. Helper plus all comparison predicates assemble as291 contiguous bytes. The trailing RTS bytes at C12123/C12139/C1214C are not included: the preceding writers end with an unconditional jump, and these extra bytes have not been established as executable entry points.

`tools/actor_program_fields.py` passes82,432 original comparisons:every256 reference bytes crossed with every256 field offsets (65,536 direct resolutions), then16,896 original-dispatch comparisons for ops2D/2E/2F/30, BA/BB/BC/BD and DA/DB/DC. Both outcomes of all eight predicates are asserted. Complete randomized WRAM agrees outside65 native frame bytes; direct full A/X, dispatch low A and S/D/DB/M/X/Y are checked. Numeric bytecode is generated only in a transient ROM copy, and original instruction/table bytes remain unchanged.

For references<80, the base is `(E000+(reference&7F)*200)&FFFF`; the byte-sized doubling discards the top index bit. Reference80 uses the current actor base. Reference81/82 uses current/second target byte, with the same index masking and word wrapping, so targetFF resolves toDE00 rather than stopping at an inactive-target guard. For every reference>=83 the base is `CA80+((actor_base&0600)>>9)`; after the handler adds0180 this addresses the CC00 global area. Its field meanings remain unknown. The byte field offset is added with word wrapping before the handler's absolute-indexed0180 addition. Offsets80..FF can reach the following actor record; the resolver does not enforce the model's previous record-local bounds. These are actual original behaviours, including undefined/aliased references.

Word predicate arguments are little-endian. Byte/word masks test nonzero or zero, comparisons use unsigned strict< or>, and all use the original variable-length relative offset for either jump or skip. Byte writers OR, AND or replace the referenced byte and advance PC by4, returning FF. Numeric address behaviour is modelled independently in full WRAM; no intended meaning is assigned to unknown global fields or script ids. Complete field semantics, malformed PC boundaries, remaining target/distance/position handlers and whole-game timing remain open.


## Matching coordinate, visibility and saved-position sources [V]

Seventeen additional sources recover818 instruction bytes: Y-height for either register (C1032E/C10343), squared-distance class C10358, direction code C10404, visibility/eligibility and three id-carry predicates (C10526..C105A4), current/second-target lookup and slot extraction (C105A5..C105D9), and ops9D/9E/9F/5F/60 at C1214D..C12225. The complete C10100..C106C4 control/geometry/variable helper range builds contiguously as1,477 bytes. Other new integrated ranges are421-byte geometry,180-byte visibility/target helpers and217-byte position/rectangle handlers. Component reuse adds no bytes to totals.

`tools/actor_program_geometry.py` passes203,776 original comparisons:8,192 height calls,65,536 distance calls,65,536 direction calls,8,192 visibility,8,192 eligibility,24,576 id predicates,2,048 target lookups,1,024 slot extraction and20,480 opcode calls. It uses Claude's established `ai_vm.dist_class`/`direction` models. Distance/direction samples include the256 by128 nonnegative displacement grid plus32,768 edge/height/wrap cases; they do not cover every coordinate cross product. All six distance classes and both outcomes of all four position predicates occur. Complete randomized WRAM agrees outside65 native frame bytes, with full direction/height A, relevant X, low distance/dispatch A, native S/D/DB/M/X/Y, visibility/eligibility Z and id-decision C checked. Validity helpers use their original M8 entry convention; modes alternate only where preserved. Bytecode exists only in a transient ROM copy.

Effective Y is `(position_y-height_byte)&FFFF`. Visibility is active-byte1, unsigned X<256 and effective Y<224. Eligibility additionally excludes the caller's own address and status bits8460. These routines return the decision in Z, not a uniform numeric value: an inactive byte0 can return A=0 while Z is clear because its comparison against1 failed. C1057E/C1058B set carry when visibility/eligibility fails or id>=80; C10598 instead sets carry only for an eligible actor with id>=83. Numeric A alone is insufficient to model these branches.

Distance classes compare the16-bit squared sum against0100/0400/0900/1000/2400. Equal thresholds remain in the smaller class. Any coordinate difference>=256 returns class8 immediately. The squared sum discards carry:dx255/dy24 produces65 after word wrapping and thus class1, a case included in the direct grid. Direction retains the original oversized-offset folding/sign flip, horizontal tie preference, primary/alternate codes and truncated `(big-small)/2+(big-small)/4` diagonal threshold. Full returned direction words match the established model.

Current/second-target lookup treats byteFF as no target; other byte indices alias modulo128 before the word address wraps. It then uses the visibility Z convention. Slot extraction uses the high address byte minusE0, byte wrapping and a right shift; it does not validate alignment or a six-slot range. Position-save records word X and effective Y. Same/changed predicates compare both saved coordinates. Rectangle predicates use signed16-bit coordinates and inclusive8..248 X/8..216 Y, without requiring activity or valid status. They resolve the reference through C11FEB and mask the resulting address withFE00, including the global-reference alias, before reading coordinates. Target-acquisition loops, exhaustive coordinate/register/flag cases and full-game/timing remain open.


## Matching first-candidate distance acquisition [V]

Thirty sources recover946 ROM instruction bytes: nine hero scans, two ally scans, ten no-target query handlers and nine target assignments. Hero scans/queries C10875..C10AEB build as631 contiguous bytes; hero target assignment C1131F..C113AE as144; ally scans/queries C10C9A..C10D32 as153. D8's separate18-byte second-target assignment is also recovered. Components reuse the same blocks and add no duplicate bytes.

`tools/actor_program_acquisition.py` passes61,440 original comparisons (22,528 direct scans,20,480 queries,18,432 assignments), with every candidate and no target observed for each scan, both outcomes of all ten queries and both accumulator widths. Tests include multiple eligible targets where a later candidate is closer than the first, self-exclusion, inactive/invalid-status/nonmonster-id/off-screen candidates and scan exhaustion. Complete randomized WRAM agrees outside65 native return/frame bytes; lowA, direct finalX and S/D/DB/M/X/Y are checked. Existing independent distance/eligibility models are used. Opcode/offset bytes are generated only in a transient ROM copy, leaving routine instructions and dispatch pointers unchanged.

All scans choose the first qualifying slot, not the closest candidate. Hero slots are0,1,2; ally slots3,4,5. Both apply eligibility C1054A, including self-exclusion and status8460, while ally scans additionally require id<80. Direct scans return the selected slot orFF, with X pointing at the selected record; exhausted scans return the pointer just beyond the three-record group. The high accumulator byte and every processor flag are not independently modelled.

Hero tests are exact classes1/2/4/8 (C10875/C108BC/C10903/C1094A), class-bit10 nonzero for beyond class8 (C10991), classes<=2/4/8 (C109C8/C10A11/C10A5A), and any eligible on-screen hero (C10AA3, class<=30). The two ally scans use class<=8 (C10C9A) and class<20 (C10CE3), preserving the established distance classifier's squared-sum wrap and oversized-coordinate class8 behaviour. Query ops31/37/3D/43/49/4E/53/58/54/D6 jump when no candidate is found. Assignment opsA5/A8/AB/AE/5D/B1/B4/B7 clear current target toFF before scanning, then store the chosen hero; D8 similarly writes the second target from the class<=8 ally scan. Each assignment advances PC by1 and continues. D6 additionally stores the chosen class<20 ally as current target on success before skipping its offset; failure jumps and retains the previous target. Its full19-byte handler is preserved. Remaining lane/current-target/side acquisition families and complete game/timing remain open.


### Lane scans recovered from C106C5–C10874

`tools/actor_program_lane_scans.py` models six ordered scans and their six no-target branches. Opcodes $63/$6C scan three records beginning at $E000; $64/$6D scan three raw records beginning at **$E006** and require ID < $80; $65/$6E scan twelve records beginning at $E000 and require ID >= $83. All scans reject self, inactive/off-screen actors and status bits $8460. They return the first qualifying address converted to a slot, or $FF. They do not rank candidates by distance or assign a target.

Vertical tests use direction-high-byte mask $F3; horizontal tests use $FC. The E006/E206/E406 addresses are literal original operands: fields are read relative to those unaligned addresses. Their intended purpose is unknown. The twelve-slot scans include E000 through F600 and leave X=F800 on exhaustion; raw E006 scans leave X=E606. Query failure takes the encoded relative jump; success skips its operand.

24,576 original comparisons pass, including every candidate and no-target outcome for each scan, both accumulator widths and twelve query outcomes. Full WRAM agrees outside 65 native stack/frame bytes; direct scan X, low A and preserved S/D/DB/M/X/Y are checked. Random cases include invalid activity, status, ID and screen boundaries. This establishes the tested scan/branch behavior, not exhaustive worlds, flags or game timing. Twelve instruction sources assemble to the original 432 bytes; the contiguous component is independently verified.


### Current/second-target geometry conditions recovered from C10F71–C1131E

The 38 handlers are reconstructed as readable predicates in `tools/actor_program_target_conditions.py`, with original matching instruction sources. Each consults $1AC (current) or $1AD (second). $FF means absent; other bytes resolve as `(E000 + (index & 7F) * 200) & FFFF`. The target must be active and on screen, but its status is **not** filtered and a self target is permitted. Failure of visibility or of the condition takes the relative jump; success skips its operand. Both paths advance the actor program counter and return low A=$FF without changing the target.

| Family | Current-target ops | Second-target ops | Condition for skipping the jump |
|---|---|---|---|
| Vertical lane | $66/$68/$6A | $67/$69/$6B | Direction-high mask $F3 clear and distance class <= $08/$04/$30, respectively |
| Horizontal lane | $6F/$71/$73 | $70/$72/$74 | Direction-high mask $FC clear and distance class <= $08/$04/$30, respectively |
| Direction bits | $75/$77/$79/$7B | $76/$78/$7A/$7C | Current masks $08/$04/$02/$01 respectively; **all four second-target handlers use mask $03**, and require a nonzero intersection |
| Exact distance class | $34/$3A/$40/$46 | $35/$3B/$41/$47 | Class equals $01/$02/$04/$08 respectively |
| Bounded distance class | $4C/$51/$56/$59 | $4D/$52/$57/$5B | Class <= $02/$04/$08/$30 respectively |
| Far-distance class bit | $5A | $5C | Class bit $10 is set |

The four repeated second-target direction masks are literal original instructions, not inferred replacements with the current-target masks. Their intended distinction is unknown. The $30 bounded distance conditions admit all classes of the established distance helper; lane versions additionally require alignment. The distance helper's 16-bit squared-sum wrap and class-$08 result for oversized coordinate differences are retained.

77,824 original dispatch comparisons pass over full WRAM except 65 native stack/frame bytes. Both outcomes occur for every handler (76 opcode/outcome pairs); all 256 target bytes, their aliases and $FF, 5,168 self-target cases, invalid status values, both incoming accumulator widths and short/long positive/negative relative operands are covered. Explicit final fixtures isolate inactive targets, x=256, height subtraction underflow, y=255 made visible by height, an oversized source coordinate, and the dx=255/dy=24 squared-sum wrap. Low A and preserved S/D/DB/M/X/Y are checked; high A, returned X, remaining flags, exhaustive worlds and whole-game timing remain outside this validation.

The 38 sources add 942 instruction bytes. They also build as one contiguous component; combined with the existing hero assignments the verified C10F71..C113AE component is 1,086 bytes. Previous lane sources close the C10100..C10AEB control/geometry/variable/initial-scan component at 2,540 bytes. Component reuse adds no bytes to totals. Side-based scans and assignments, remaining movement/command handlers and complete game reconstruction remain open.


### Grouped target searches, assignments and visible-actor count [V]

`tools/actor_program_group_targets.py` supplies readable models and 131,072 original comparisons. Six missing ally searches at C10AEC/C10B33/C10B7A/C10BC1/C10C08/C10C51 require eligibility plus ID < $80 over slots 3–5. Their distance tests are exact classes $01/$02/$04/$08 and bounded classes <= $02/$04. The previously recovered <= $08 search remains at C10C9A. Seven searches at C10D7A/C10DC1/C10E08/C10E4F/C10E96/C10EDF/C10F28 require eligibility plus ID >= $83 across **all twelve slots 0–11**, with exact classes $01/$02/$04/$08 and bounded classes <= $02/$04/$08. ID, rather than a fixed monster-only address group, is the additional filter. Each search returns the first qualifying slot or $FF, leaving X at the selected record or one past the scanned group.

| New search group | No-target branch opcodes | Current-target assignment opcodes | Second-target assignment opcodes |
|---|---|---|---|
| Ally exact classes $01/$02/$04/$08 | $32/$38/$3E/$44 | $A6/$A9/$AC/$AF | $C6/$C9/$CC/$CF |
| Ally bounded classes <= $02/$04 | $4A/$4F | $B2/$B5 | $D2/$D5 |
| Ally bounded class <= $08 (existing search/query) | $54 (existing) | $B8 | $D8 (existing) |
| Twelve-slot monster exact classes $01/$02/$04/$08 | $33/$39/$3F/$45 | $A7/$AA/$AD/$B0 | $C7/$CA/$CD/$D0 |
| Twelve-slot monster bounded classes <= $02/$04/$08 | $4B/$50/$55 | $B3/$B6/$B9 | $D3 for <= $02; no corresponding second-target handlers for <= $04/$08 in this block |

Eight additional second-target assignments reuse the established hero searches: $C5/$C8/$CB/$CE for exact classes $01/$02/$04/$08, $5E for class bit $10, and $D1/$D4/$D7 for bounded classes <= $02/$04/$08. Together these recover 33 new 18-byte assignment handlers. Every assignment clears its destination to $FF, stores the selected slot on success, advances the program counter by one and continues with low A=$FF. Unsuccessful searches therefore clear a previous target. Other target fields stay unchanged.

Current-target operations $A4/$A1/$A0 at C114AB/C114BC/C114C5 respectively select the caller's slot, copy the second target byte, or clear to $FF. Copying does not resolve or validate the byte. The self operation converts the caller address using the original high-byte slot arithmetic. These aligned-caller fixtures cover all twelve caller slots and all 256 copied target values.

C10D33 counts visible actors in records E600/E800/EA00. It does not exclude self, status or ID. Opcode $F5 at C10D63 reads a byte threshold and takes the relative jump when the count is **greater** than that threshold; it skips the offset when count <= threshold. Activity, unsigned x < 256 and unsigned (y-height) < 224 determine visibility. Counts 0/1/2/3 and all 256 threshold bytes are tested.

The successful comparisons comprise 26,624 direct searches, 26,624 queries, 67,584 assignments, 6,144 current-target operations, 2,048 count calls and 2,048 count queries. Every candidate and none is observed for all tested scan families and assignment opcodes; all 26 new no-target query outcomes occur. Canonical multiple matches include a later, closer candidate to verify ordered selection. Full WRAM agrees outside 65 native stack/frame bytes; low A, final direct-search X and S/D/DB/M/X/Y are checked. Invalid activity/status/ID/screen cases, self exclusion, both accumulator widths and signed short/long relative operands are included. High A, other returned X values, every flag, unaligned auxiliary callers, exhaustive worlds and whole-game timing remain outside this validation.

64 matching instruction sources add 1,632 ROM bytes. The ally search/query block now builds contiguously as 582 bytes, the count block as 71, the twelve-slot monster search/query block as 503, and all target assignments/copy/clear operations at C1131F..C11656 as 824. Combined control, geometry, variables, searches, count, conditions and targets at C10100..C11656 build as **5,463 matching bytes**. These contiguous checks reuse sources and do not increase the byte total. Remaining movement/command/effect handlers and complete game reconstruction are still open.


### Explicit-slot distance predicates and C1 direction commands [V]

`tools/actor_program_movement.py` recovers C11899..C11C8D as 18 matching instruction sources (1,013 bytes), with 77,824 original comparisons. Four opcode handlers $36/$3C/$42/$48 take a literal actor byte and skip the relative jump when that actor is active and has exact distance class $01/$02/$04/$08 respectively. Their four unequal-distance counterparts at C11945/C11970/C1199B/C119C6 have no entries in the 256-opcode pointer table; these bodies are tested by direct calls, without asserting normal-game reachability. They skip on **active and unequal**; inactive actors take the jump in both families.

Literal actor-byte resolution is `(E000 + (index & 7F) * 200) & FFFF`, without a $FF absent-target sentinel. These predicates check activity only: screen bounds, status and self are not exclusion filters. Their variable-length signed relative operand follows the literal actor argument. Distance uses the existing exact classifier, including oversized-coordinate class $08 and squared-sum wrap. F9 at C119F1 copies its literal byte into actor field $19B and advances the program counter by two; no additional meaning is inferred for that field.

| Command ops | Target | Direction-code input | Stored direction byte |
|---|---|---|---|
| $E4/$E5 | Current/second | Caller to target | Low code & $0F |
| $E6/$E7 | Current/second | Target to caller | Low code & $0F |
| $BE/$BF | Current | Forward/reverse | High code & $0F |
| $FD/$FE | Current | Forward/reverse | Low code >> 4 |

These eight commands require a non-$FF visible target, without status or self filtering. On success they write command bytes `$C1, direction, argument1, argument2`, advance PC by three and return A=$0000 to yield. On failure they advance by three, leave all command bytes unchanged and return A=$FFFF to continue. Reverse-direction bodies temporarily exchange the source/target registers and restore the caller Y before writing.

**E3 is frame-dependent.** At C11C34/C11C47 the original instructions are `BIT $80` (direct-page memory), not `BIT #$80`. The body first sets D to its native frame. Nonzero actor byte $06 selects horizontal bit $02 when it intersects the byte at D+$80, otherwise $01; nonzero byte $07 selects vertical bit $08 or $04 by the same test. If both bytes are zero, facing $00/$01/$02/other maps to $08/$04/$01/$02. It writes the same four-byte C1 command, advances by three and yields. For the harness's native S=$1F00 dispatcher call, D=$1EF5 and the mask is read at WRAM $1F75. This address is a property of that call frame, not a universal game address. Observer hooks confirm the original reads without bypassing instructions.

The previous `ai_vm.World` model assumed an immediate sign mask $80. It now accepts `velocity_direction_mask`, and 8,192 explicit-mask VM command results agree with the original E3 command and PC. The optional default $80 preserves the previous fixture behavior; exact E3 callers must supply the observed native-frame byte. Older validations that did not supply it do not establish equivalence for other masks. The report fingerprints the revised `ai_vm.py`.

The 77,824 successful comparisons include 16,384 opcode distance queries, 16,384 direct unequal-distance calls, 32,768 target commands, 4,096 F9 writes and 8,192 E3 commands. Both branch/yield outcomes are observed in all applicable families. Full WRAM agrees outside 65 native stack/frame bytes, with full A and S/D/DB/M/X/Y checked. Both incoming accumulator widths are used through dispatch; direct distance calls enter and leave in M8. All 256 literal target/argument bytes and ambient-mask values are sampled, including all facing fallback values with zero velocity. The command constructors are verified here; consuming those commands into actual movement, arbitrary native stack placements, exhaustive worlds/flags/registers and full game timing remain open.

Five new contiguous builds verify the 344-byte explicit-slot predicate block, 669-byte field/command block, full 1,013-byte new range, 1,494-byte fixed/random/variable/slot/command range and 1,528-byte version including the existing hop command. Reused bytes are counted once. Remaining command/effect families and complete game reconstruction remain open.


### Controller-distance gates and local action commands [V]

`tools/actor_program_actions.py` recovers 13 original handlers as 431 matching instruction bytes. It compares 53,248 original dispatch cases over full WRAM outside 65 native stack/frame bytes and also compares 53,248 readable VM cases. `ai_vm.py` gains FA/EC/EB/F7/F0/F1/F6 and corrects F3's global-byte index for aligned actor slots above three.

Both controller gates first search E600/E800/EA00 for any eligible other actor with ID < $80. Controller bytes $D9/$DA/$DB resolve their low three bits to the highest selected hero slot; zero means unbound. Bound hero activity/status/screen visibility is not separately filtered for the distance calculation. Opcode $62 at C11CB0 takes the relative jump when there is an eligible ally and **no bound hero has distance-class bit $20**. If none is eligible or any bound hero is far, it skips. Opcode $F6 at C11CFF takes the jump when there is no eligible ally, or when no bound hero has that bit clear. If an ally is eligible and any bound hero is not far, it skips. These are not simple complements: a mixture of near and far bound heroes makes both skip. Empty bindings alone make $62 jump/$F6 jump if an eligible ally exists. Distance preserves the established squared-sum and oversized-coordinate behavior.

| Opcode | Local action | PC advance / result |
|---|---|---|
| $E1 | Write command $01 | One / yield |
| $E8 | If gauge $1ED is zero, copy $1C0 to $19B and write command $02 | One / yield on zero, otherwise continue |
| $DF | If gauge is zero, clear flag $14C bit $01 and write command $02 | One / yield on zero, otherwise continue |
| $FA | If gauge is zero, copy literal argument to $19B and write command $02 | Two / yield on zero, otherwise continue |
| $EC | Write command $03 | One / yield |
| $F4 | If flag bit $01 is set, clear it and write command $07 | One / yield on set, otherwise continue |
| $F3 | If global byte is nonzero and flag bit $01 is clear, set the bit and write command $06 | One / yield on change, otherwise continue |
| $EB | Write `$C0, argument1, argument2, clamp(((x_low + 8) // 16), 1, 15)` | Three / yield |
| $F7 | Write command $82 and two argument bytes; preserve command byte $143 | Three / yield |
| $F0/$F1 | Copy literal byte to current/second target, without lookup or validation | Two / continue |

F3 at C11DCD computes its index from the full aligned caller address: the global byte is at `$CC7D + slot`. The earlier readable VM used `slot & 3`; it now uses the full slot. The tested callers cover slots 0–11. Unaligned and wrapped caller addresses are not represented by this VM fixture. EB at C11F66 reads only the **low byte** of actor x ($20), despite the position being a word. The high byte is ignored; the original shifts/add/clamps give scale values 1–15. No further meaning is assigned to that command's scale here.

The tests cover all 512 three-controller binding patterns, all twelve aligned caller slots, both controller branch outcomes, conditional yield/continue outcomes, all 256 flag/argument/low-x values with varied high-x, gauge/global-byte edges and signed short/long relative offsets. Separate fixtures observe actual DF/F4 bit clearing, rather than only re-clearing a zero bit. Low A is checked for frame-preserving query wrappers and full A for other handlers; S/D/DB/M/X/Y are checked. The revised readable VM reproduces PC, targets, selected flag/stage writes and command fields for each case; its source fingerprint is recorded. Native effects/command consumption, arbitrary frames/unaligned callers, exhaustive input cross-products/flags/registers and complete game timing remain open.

Six additional contiguous builds verify 328-byte controller/action and 166-byte action/flag blocks, the 1,886-byte fixed/random/conditions/direction/actions/pose range C116B8..C11E15, a 124-byte command block C11F37..C11FB2, the 26-byte literal-target block and a 317-byte literal-target/reference-condition block C11FD1..C1210D. Component reuse adds no bytes to the total. Casting, native effects and remaining command families still require reconstruction.


### Single/group casting through the native API [V]

`tools/actor_program_casting.py` now follows the original E9/EA dispatch through **the real C0001B API and all its RNG/message callees**. `tools/actor_cast_native.py` supplies an independent full-WRAM model of that native entry. Both harnesses clear every bypass hook. They compare 8,192 opcode cases, 2,048 direct MP-helper cases and 4,096 native API cases: **14,336 original comparisons**, with 2,689 native calls from the opcode fixtures.

E9 at C11E47 requires a non-$FF visible second target, unsigned MP >= the literal spell cost, status bit $80 clear and sprite/state byte $60 != $E0. It writes command $44 and the animation byte, spell byte $170, element index $177=0, requested count $176=1 and one-based target byte $178=(second+1)&FF, clearing $179/$17A. Target status and self are not exclusion filters. Failure writes the established facing C1 command with arguments 0/5. Both paths advance PC by three and yield A=$0000.

EA at C11E98 preserves the earlier model's original quirks. Its acceptance gate is **MP >= cost OR (status bit $80 clear AND byte $60 != $E0)**. On acceptance it clears $176..$17A. Second-target bytes below three select the hero group; all other bytes, including $FF, select the ally group. The loop never advances X: it repeatedly tests only E000 or E600. For aligned callers, a valid first actor produces all three one-based requested slots 1/2/3 or 4/5/6, even if the later actors are invalid; invalid/self first candidates produce no request. The ally first candidate additionally needs ID < $80. Success sets count three, command/animation/spell and calls the native API. A failed gate or empty selection yields the facing C1 fallback. Clearing the request block happens only after gate acceptance, and remains visible on an empty-selection fallback. PC always advances by three.

C11E2C reads the spell argument, computes its 64-byte table index and returns the 8-bit MP subtraction result with unsigned carry (MP >= cost). Its high A is the high byte of the computed index; direct M8 calls check full A, X and carry. C11E16 sets X to the caller address, enters the native API with Y at the caller, and restores Y/D/DB/M around the call. The API returns directly through the original shared combat epilogue; no effect call is substituted in these comparisons.

The native chain C0001B -> C03803 -> C03862 -> D04D9E normalizes caster/target context, clears the caster's hit-list bytes $172..$174 to $FF and reads the established element level/progress. D04EAC chooses the effective level at $171. When actor type bits $C0 are set and raw level is eight, it draws the original additive RNG and lowers the effective level to seven unless `(draw >> 1) + 1 < progress`. The direct API cases observe 384 draws: 141 lower the level and 243 retain it. Other levels bypass the draw. Raw level/progress scratch bytes remain available independently of the selected effective level.

C03F69 uses the **sign bit of the wrapped MP-cost result**, rather than unsigned carry, to decide whether to queue the cast-level message. It does not debit MP here. Successful message construction uses the raw level at $39D, not the potentially lowered effective level. The reverse allocator C05D08 decrements byte $3A2, resets to slot eleven when the decremented byte is negative, clears thirty bytes, writes its prefix and increments $39F. Normal slots 0–11 and the malformed previous-index $80 -> slot $7F case are compared over full WRAM, including indexed writes that carry into the next RAM bank. Native byte-decimal formatting preserves its original signed subtraction loops for the tested out-of-range level bytes. ROM text is read only at runtime; encoded message payloads are not saved.

Native API fixtures compare full A/X/Y/S/D/DB/M/X over twelve aligned caster/target slots, both accumulator widths and two incoming D/DB values, all 256 spell bytes, hero/nonhero profiles, valid RNG indices 0–14 and element indices 0–7, level-eight RNG branches, signed MP outcomes and queue wrap. Opcode fixtures compare full A/S/D/DB/M/X/Y, all 256 target/animation/spell bytes, aliases/$FF, target/status/ID/activity/screen/MP/sprite guards, single/group/fallback paths and both accumulator widths. Full WRAM agrees outside 65 native stack/frame bytes. These routines prepare requests, levels, hit bookkeeping and messages; later command consumption, spell execution and MP debit, arbitrary frames/unaligned callers, exhaustive cross-products/flags and complete game timing remain open.

Thirteen new matching instruction sources add 507 ROM bytes; the already recovered 19-byte message-clear routine is reused and its validation strengthened. Four new contiguous builds cover 289-byte script casting, the 2,299-byte fixed/random/condition/command/action/casting range C116B8..C11FB2, the 306-byte native setup/progress/read/selection range D04D9E..D04ECF and the 62-byte reverse message allocation/clear block. Audited documented ROM coverage gains only 504 bytes because three new source bytes overlap an already documented range. Component and catalogue overlaps are counted once. Native target effects and the remaining actor commands still require work.

## Native appearance inputs and remaining charge-stage predicate

`tools/actor_appearance_inputs.py` reconstructs C047DD..C048E6, FB at C11657 and F2 at C12226. Its16,384 original comparisons execute the original instructions without bypass hooks, comparing randomized full WRAM outside65 native stack bytes. Native helpers require D=0300, DB=7E, M8/X16 and scratch03BD=actor offset; script dispatch restores both tested accumulator widths and caller context.

C047DD copies actor-kind table byte D0000F + id*16 to1AF, keeps only appearance flag bits0E, then classifies sprite1E7. Sprites20/2E/3F set bit01; other sprites below80 copy CFFB to1E6, with55/56 setting bit10 and status low byte190=20, and57..7F setting bit40. Sprites80..82 set bit80 and copy CFFC;83..FF set bit20. These are literal native branches, including the flag clearing.

C04860 initializes four bank-D0 pointers at03C0/03C3/03C6/03C9. The latter three offsets are10 times actor bytes1E2/1E1/1E0 respectively. Bit40 returns before changing03C0. Otherwise03C0 is12 times1E8 or1E9, selected by bit80 of1E4. Appearance flag bit80 additionally replaces1E4 with the byte at D01000 plus that offset. Table contents are read from the supplied ROM at runtime.

FB copies the low nibble of146 (variable zero) to19B and advances one byte. F2 uses the shared global byte CC7D + ((actor address &0600)>>9), so aligned actor slots share four entries. A nonzero argument jumps when global <=19B; zero jumps when global >19B. Both use the following signed relative operand and continue. All256 argument/field bytes and short/long forward/backward operand forms are sampled.

Matching sources add323 bytes; helpers build together as265 bytes and final position/rectangle/charge predicates as266 bytes. This checkpoint validates inputs to the larger C0457C appearance refresh. Its remaining attribute calculations, command consumption, physical rendering, arbitrary frames/unaligned actors, exhaustive cross-products and game timing remain open.

## Complete appearance refresh and FC native composition

`tools/actor_appearance_refresh.py` now reconstructs the complete C0003C API and FC command, composing the previous appearance-input model with seven new readable attribute helpers. The22,528 original comparisons contain4,096 full native API calls,4,096 script dispatch calls and2,048 calls per new helper. Every native helper executes normally, including hardware multiply/divide accesses; the harness clears all bypass hooks. Full WRAM is compared outside65 stack bytes, along with S/D/DB/M/X width, native X and non-early fullA/Y, and script fullA/Y. Twelve aligned actor slots and both API/script M widths are sampled; native entry DB=7E/42 and D=0300/1234 are restored.

The API establishes D=0300, DB=7E and the masked actor offset in03BD, with its slot in03BA. After classifying appearance, bits30 cause an early context-restoring return. Other paths set bit04 of1FA. The ordinary path reads the selected packed appearance level, loads base attributes, prepares pointers, applies packed adjustments, reduces/clamps the five base bytes, derives palette attributes, copies palette bytes6/11, rearranges attribute bit pairs, marks1AB bits12 and caps final values. The special bit40 path reclassifies, loads base attributes and pointers, clamps, rearranges bits and marks1AB, then loads a seven-byte record from D0BDC1 +1E3*7. It copies1C0 to both19B and19C before the final caps. No MP or damage-resolution semantics are inferred from these appearance routines.

C0474F selects the29-byte base record with1E7, except status byte191 bit08 and id180 below80 select the id instead. Its overlapping word stores are preserved, including1A5 after1A4/1A6 and1E8/1E9 palette selectors. C048E6 uses1E4 for hero flag80 and literal selector1 otherwise. Odd selectors use the low nibble; even use the high nibble. Slot zero additionally clears CC76 and, when both CC78/CC79 and E1E4==1 hold, sets195=80 and computes CC76 as the sum of eight progression bytes divided by100 plus the average of eight packed level nibbles. Scratch high bytes left by word-to-byte transitions are preserved.

C049AA adds one quarter of189 to palette byte7, wrapping before its99 cap, and adds188 to palette byte8 with byte wrapping. When the word CC78 and byte19D are both zero, it clears195 and replaces199 with palette word9. It copies palette byte5 to194 and returns the combined palette flag without storing that return value into1E4. C04A53 swaps the three low bit pairs of193 into1A1, copies193 into1A3 and clears1A2.

C04AFF decodes five two-bit adjustments: the low two bits of palette byte2 for188, then descending bit pairs of palette byte1 for189..18C. Numeric C04B79 contains0,+1,+5,-5; addition wraps each byte. C04BBE first subtracts one sixteenth of189 if status190 bit08 is set, then clamps188..18C to1..99. C04BF9 caps the words1A8/1A5 at999 and bytes1A4/1A7 at99.

FC skips the refresh when191 &DF is nonzero. Otherwise it toggles the high bit of1E4 while clearing the other bits, chooses1E9 or1E8, stores that byte in1E3, merges the selected table flag into1E4, and calls the real native API with the caller actor. The API can subsequently replace appearance fields, so a local palette-toggle-only model is insufficient to reproduce the complete command. FC always advances one byte and continues; script Y and context are restored.

Sixteen instruction sources plus one numeric table add1,017 matching ROM bytes. All606 sources and86 contiguous builds verify independently, including the7,859-byte script region C10100..C11FB3. Physical PPU rendering, arbitrary native frames/unaligned actor callers, exhaustive cross-products and unlisted registers/flags remain open. Opcode61/C11FC8 and its C00024 native call are the next unlabelled dispatch path.

## Full native attribute rebuild required by opcode61

Opcode61 at C11FC8 calls the visible-current-target helper and C00024. That API reaches C8E1ED, selects an effect using a caster byte1C8 table and invokes full status application at C8E301. The latter rebuilds attributes via C04530, whose complete memory model is now in `tools/actor_stats_native.py`. Opcode61 is not yet marked reconstructed: status/appearance/attack-row/message composition remains to be completed.

C00036/C0381E/C04530 normalizes actor context and classifies appearance. Flag20 returns immediately. Nonhero paths enter the existing appearance attribute body at C04597; they do not set the refresh-only bit04 of1FA. Hero flag80 loads level attributes from D04210 + ((sprite1E7-80)*0318 + level181*8), with16-bit index wrapping. It copies maxHP, maxMP and five base attributes, then a three-byte experience record from D04B58 + level*3. Controller comparison reads actual D9/DA/DB low nibbles; the slot+1 value skips3. Unbound actors use a16-byte table at C0473F indexed by CC7A+slot, applying packed0,+1,+2,-1 changes to the first three attributes with byte wrapping.

The hero rebuild prepares palette/armor pointers, reads packed weapon level, applies each armor flag and weapon adjustment, clamps base attributes, computes attack/palette fields and weapon accuracy, combines armor elemental resistance, computes defenses/immunity, caps final values, then stores palette byte11. Armor flag bits10/08/04/02 affect the first four attributes. The sign is selected by BIT absolute0040: when the flag byte intersects that WRAM byte, the delta is-2; otherwise+5. This is not an immediate bit40 test.

Weapon accuracy is byte-wrapped(3*19C + palette byte6), halved when the raw1E4 byte is greater than4. Armor resistance ORs the three row bytes6, stores1A3, rearranges low bit pairs into1A1 and clears1A0/1A2. Physical/magic evasion are byte-wrapped quarter-AGI/WIS plus the three armor bytes2/4. Defense/magic defense use word sums of CON/WIS and armor bytes1/3. Immunity ORs three armor words7 and0800. Scratch byte/word writes are preserved in the full model.

The prior `tools/hero_stats.py` now wraps AI additions and byte armor/weapon sums, uses the original unsigned1..99 clamp, and accepts optional armor_sign_mask (default0). A probe using ordinary levels0..98 and valid equipment found no differences in4,096 samples. Extending raw level bytes through255 exposed the signed-clamp error: for example hero2, raw level101, weapon17 and armor30/40/50 produced CON99/defense394 in the native-compatible model versus1/296 before correction. This is an out-of-normal-level input; it does not claim a reachable level101. The corrected prior model matches15 fields in3,092 original native API cases, including wider raw table inputs.

The complete20,480-case harness executes every original callee without bypass hooks, comparing full WRAM outside65 native stack bytes and fullX/S/D/DB/M/X width. Twelve aligned slots, hero/ordinary/special/early paths, human/AI bindings, all256 armor sign masks and varied raw level/equipment bytes are tested; native entry D/DB and both accumulator widths are restored. Existing recovery tests also pass512 direct,64 rebuild and12 program cases. Seven new code sources plus one16-byte numeric table add600 matching bytes, reusing the public jumps. All614 blocks and88 components verify, including the1,448-byte contiguous helper range. Unlisted flags/registers, arbitrary frames/unaligned actors, exhaustive cross-products, physical rendering and the full status-consumption composition remain open.

## Complete status-application memory model

`tools/status_native.py:apply` reconstructs C8E301 with the original status filters, recovery, full C04530 rebuild, appearance/attack-row selection, transformation RNG, controller update and message production. Its8,192 comparisons include4,096 complete calls and four sets of1,024 direct helper calls. The harness clears bypass hooks; all native callees execute. Full randomized WRAM outside129 native stack bytes and S/D/DB/M/X width match, for twelve aligned slots, selected prior status flags, random added/immunity words, varied appearance classes, valid RNG/message indices and both early/continuation outcomes. Unlisted registers/flags and exhaustive cross-products are not claimed.

The pipeline masks additions and current status against immunity, computes new bits relative to saved1EE, marks changed appearance, records removed bits and performs death recovery when needed. It stores the pre-filter status in1EE, applies the three original exclusivity filters, then retains only added bits surviving those filters. Petrification halves HP and adds one; sleep marks the secondary flag. Newly surviving4560 bits mark1FB bit02. Duration uses signed16-bit(power/4 - magic_defense/2), then the low byte and a minimum20; no unbounded integer duration is substituted. Four timer groups are written only when their new bits survive. Death bookkeeping, controller-bit refresh, native rebuild, appearance and attack-row selection follow in original order.

Recovery clears the status/new/pending words, preserves the literal D9/DA/DB immediate comparisons from C8E441 and resets the actor program when their slot value fails. The slot2 program reset invokes the real stat rebuild; the readable model reproduces this intermediate rebuild as well as the final one. Random nonhero transformation updates RNG scratch/state, id and flags, rebuilds native attributes, then chooses the current weapon row before the final attack-row helper.

C03F28/C03F2C copies CC6D..CC6F into low-memory EE..F0, examines party slots2,1,0 and XORs03 in a controller-indexed byte for actors whose status low byte has bit80 and whose byte2C is nonzero. The routine tests that low-byte bit literally; it is not generalized to a death-bit test. Binding index3 maps back to2.

C05A87 suppresses messages for sprite1E7 >=83. Otherwise it scans newly added status bits from15 down to0 using C05DBB's16 numeric text pointers. Nonhero bit15 is suppressed. Each selected bit allocates a30-byte forward queue slot, writes markerC0 and actor name tokens, stores target/status metadata at offsets16/18, then copies zero-terminated text from the supplied ROM. The queue increments its count byte and wraps its tail only when the increment equals12. No message text is persisted in the report/source. All scratch mask/pointer writes are modelled. Message production occurs only while one of the three party actors is active with nonzero HP.

The trace contains actual recovery/program reset, RNG transformation, death, early return, controller and status-message branch PCs. Three code sources plus the32-byte pointer table add215 matching bytes. All618 sources and90 components pass independent assembly. These comparisons strengthen the already matching status sources from selected-field evidence to a complete memory-state model within the stated contracts. Physical rendering, malformed RNG/queue indices, arbitrary native frames, misaligned actors and the complete opcode61 effect dispatch remain open.

## Opcode61 native selected-effect composition

`tools/actor_selected_effect.py` reconstructs opcode61 at C11FC8, its C11FB3 wrapper and C00024/C0380C/C0386E/C8E1ED native path for selectors0..7. All16,384 original comparisons pass without bypass hooks:8,192 native calls and8,192 script dispatches, comparing full randomized WRAM outside129 stack bytes and restored S/D/DB/M/X width; script fullA/Y also agree. Twelve aligned callers,16 aligned native target offsets, all256 raw target bytes, first-party override, both accumulator widths and native D/DB restoration are included. Arbitrary selectors and the event-selector8 path are not modelled.

The native API swaps the incoming registers before caster/target normalization. It scans the first three party records and uses the first with1FB bit04 set, ignoring activity/visibility; absent such a record it retains the supplied target. It records caster slot in target1EC, clears low status bits0/1, pending word1F1, byte59 and flag04, and computes03:96 as the low byte of twice the target level word181. Caster byte1C8 selects the effect table.

Selectors0/7 do nothing locally. Selector1 draws a byte, scales it into three choices and ORs0200/1000/0010 into target status. Selectors2/4 set pending1F1 to byte-wrapped(level181 + (RNG &7)) +1. Selector3 sets high status bit20; selector5 sets low status bit40. Selector6 either copies currentHP to pending1F1 and clears pending1F3 when RNG &7 ==0, or sets currentHP=1, marks global380 bit40 and queues runtime text at6303. The successful original trace contains both selector6 branches. Every case then executes full C8E301 status application, including its native rebuild and message callees. Text is read from the supplied ROM without storing payloads in the sources/reports.

Opcode61 calls the current-target helper unconditionally before the native API. The helper's visibility result is not used to skip the call. Raw target bytes produce wrapped lookup addresses, then the API masks the supplied address to1FFF. FF preserves the dispatcher index X=00C2 rather than returning a sentinel;32 no-party-override cases execute the effect on E0C2. The packed-level reader therefore reads from E1C0 + its scratch03D0 index after the low byte is overwritten by selector/2, not from the misaligned actor plus selector/2. The shared readable helper has been corrected accordingly; its aligned appearance/stat/status regressions all pass.

The PC increment happens after the effect. If recovery resets the caller's program, opcode61 increments that new PC. Keeping the original pre-effect PC would overwrite native recovery bookkeeping. The model reproduces this behavior and always continues with fullA=FFFF, restored callerY and context.

The table actually has nine entries. Selector8 at C8E2F6 loads A=0500 | caster byte1C9 and calls018000, the mirrored C1:8000 jump to event entry C1E753. That event path and arbitrary selector values remain open; the current readable model raises for them. The pointer is structurally documented and independently assembled, but its body is not counted as reconstructed in this checkpoint.

Fourteen code sources and two numeric tables add319 matching bytes. All634 blocks and92 contiguous components verify, including8,227 bytes at C10100..C12123. The fresh `tools/actor_opcode_sources.py` audit checks every original opcode destination against verified code sources:256 entries cover217 distinct targets, with no missing source destinations. This does not mean that all native/event dependencies or actor-command consumers are finished. Physical rendering, arbitrary frames, other misaligned offsets, malformed queues/RNG and exhaustive registers/flags/cross-products remain open.

Reproduce the destination-source audit after `make verify-source` with `python3 tools/actor_opcode_sources.py ROM --json data/actor_opcode_sources.json`. It rejects stale manifest, ROM or source hashes.

## Ninth selected effect completed through original event request

Selector8 at C8E2F6 is now reconstructed and independently assembled. `tools/actor_selected_effect.py:effect` invokes the readable numeric event-request model using0500 | caster byte1C9. Its16,384 fresh original native/API opcode61 comparisons cover all nine selectors0..8, actual mirrored018000 event entry, busy/deferred/started request branches, actor preparation and original status/recovery/rebuild/message callees. Full randomized WRAM outside129 stack bytes, context restoration and script fullA/Y agree. The32 absent-target00C2 cases remain covered. Selectors beyond the documented nine-entry table still raise in the readable model.

`tools/event_request_native.py` adds8,192 complete original request comparisons, all2,048 numeric ids and256 event-state bytes. It distinguishes idle00 (accept pointer/state01 and prepare actor), deferredFF (accept pointer/state01 and return) and busy states (preserve pointer/state, clear scratchCC/CD/CE). It does not substitute a queue or immediately execute the requested event script. Detailed actor/controller/animation writes and reproduction commands are in `docs/cutscene-engine.md`. Event command formats>=0800 and later interpretation remain to reconstruct.

Seven sources add245 matching bytes. The contiguous selected-effect/status build now spans596 bytes at C8E1ED..C8E441. All641 blocks/94 components and the256-entry/217-destination opcode-source audit pass. Mirrored event PCs are recorded as bus-address coverage; physical source bytes are counted once. Arbitrary selector/actor-offset/frame inputs, malformed queues/RNG, exhaustive cross-products, unlisted registers/flags and physical rendering remain open.
