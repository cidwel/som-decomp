# The moon of the final "The End" screen (2026-10-18)

Tags: **[V]** measured by running the original ROM in the snes9x libretro core (`tools/ending_moon.py`, WRAM/SRAM/OAM read from the core); **[C]** read from the decompressed boot program (the `$C7:7C00` stream decoded to `$7E:8000`, see `docs/boot.md`), not single-stepped.

## 1. Finding

The moon that changes is on the last screen of the game: after the staff roll (event `0x4FD`, `docs/cutscene-ending.md`) `PARTY_CMD 0x11` restarts the boot program at `$7E:AF28`, which shows a night sky with a tree silhouette, stars, a shooting star and "The End". The moon there is one of **three sprite sets** (full, gibbous, crescent), chosen **once, when the scene is built**, by a random draw:

`template = random(3)` (`$7E:C288` with limit 3, called from `$7E:938B` in the constructor `$7E:9373`).

The random generator is re-seeded at every start of the boot program (`$7E:AD75`, call at `$7E:ADC1`) from **the four primary save slots**:

`seed = SRAM[$0001] XOR SRAM[$0401] XOR SRAM[$0801] XOR SRAM[$0C01]` (16-bit words = the checksum words at slot+1/slot+2 of the four primary slots, `$30:6001/6401/6801/6C01`); if the XOR is 0 the seed is the constant `0x7524`.

Everything else is deterministic, so the moon shown is a pure function of that XOR. Conditions, stated directly:

- It does **not** depend on story flags, party, items, play time, the in-game clock, the order of events, button input, frame timing of the ending, or the Mana Beast fight. The ending script reads no flags (`docs/cutscene-ending.md` section 3), and no flag is read by the scene.
- It depends **only** on the checksum words of the four primary save slots at the moment of the restart. Saving the game (any slot) changes a checksum and therefore usually the moon (about 1/3 of the changes keep it). Backup slots (`$1000..$1FFF`) are not read.
- With a SRAM where the four words XOR to 0 (no saves in an emulator that fills SRAM with identical bytes, e.g. snes9x's 0x60 fill) the seed is `0x7524` and the moon is the **gibbous** one. All 65,536 possible seeds give: full 22,337, gibbous 21,758, crescent 21,441 (model, section 4).
- Once the scene exists the moon never changes: no code touches those four sprites later (the moon area changes only when the shooting star passes, frames +2315..+2333 of one run, and for one-frame star twinkles).

## 2. The three moons [V]

Pictures (PNG, outside the repo, `~/.local/state/som-decomp/ending-moon-20261018/`): `moon_variants_full_frame.png` (the whole screen for the three seeds: full / gibbous / crescent), `moon_variants_zoom.png` (4x crop), `ending_scenes_sheet1.png`, `ending_scenes_sheet2.png` (all 17 maps of the ending, 150 and 600 frames after each load, plus the final screen), `map150_layer_toggles.png`.

| template | seed examples (XOR of the four words) | look | OAM entries seen (tile, flip bits 7-6) |
|---|---|---|---|
| 0 | 1, 7, 0xFFFF | full moon, round | tile 27 four times, flips 3, 2, 1, 0 |
| 1 | 0 (= 0x7524), 0x1234 | gibbous / oval | tiles 40, 41, 42 and tile 27 with flip 3 |
| 2 | 2..6, 0xBEEF | thin crescent | tiles 43, 43, 44, 45 (the first two are the same sprite position, so three distinct tiles) |

The sprites are objects, not BG: disabling the core's layer 5 (sprites) removes the moon and the stars, the tree and the sky gradient stay [V]. The four sprites are at x = 200 and 208, y = 80 and 88 in every template (shadow OAM entries 108-111 of the buffer at `7F:[7F:02CC]` = `7F:2180` in these runs).

Template table: `$7E:5EEE`, 3 x 12 bytes, three bytes per sprite (y - 0x38, x, tile in bits 0-5 and OAM flip bits in 6-7) [V: bytes read from WRAM]:

```
T0: 18 C8 1B | 18 D0 5B | 20 C8 9B | 20 D0 DB
T1: 18 C8 28 | 18 D0 29 | 20 C8 2A | 20 D0 DB
T2: 18 D0 2B | 18 D0 2B | 20 C8 2C | 20 D0 2D
```

## 3. The code [C, with [V] from the experiments]

- `$7E:AF28` (the warm entry, `docs/boot.md`): `$AD75` (resource init), task `$7E:934F` through `$AB88`, `$A88F`, `$AE28`, then `JMP $AF0B`.
- `$7E:AD75` (around `$ADB0`): `LDA $30:6001`, `EOR $30:6401`, `EOR $30:6801`, `EOR $30:6C01`, `TAX`, `JSR $C2D9`. At the SRAM layout of `docs/ui-native-loaded-game-save-validation.md` the word at slot+1/+2 is the slot checksum (sum of the bytes slot+3..slot+0x2BA).
- `$7E:C2D9` seeds the 15-byte ring `7F:02E5..02F3` (cursor `7F:02E4`) with a 16-bit LFSR: X = 0 becomes `0x7524`; the step is `s = (s & 0x4001) in (0, 0x4001) ? s >> 1 : (s | 0x8000) >> 1`; a byte is taken (`(s >> 1) & 0xFF`) whenever bit 0 of the new `s` is set; if the OR of the 15 bytes is not `0xFF` the whole fill is repeated from the current `s`.
- `$7E:C25B` advances the ring (`ring[new] = ring[old] - ring[new]`, cursor wraps at 15); `$7E:C288` draws a value below a limit with a power-of-two mask and rejection (limit 0 = 256, limit 1 returns 0 without advancing).
- Order of draws until the moon (the model reproduces the emulator for 300 random seeds, so no other draw comes before): the 16-star constructor `$7E:945D` (per star `draw(256)` for x, `draw(0x68)` + 0x38 for y, `draw(4)` + 0x1C for the tile), then `$7E:9373`: `draw(3)` selects the template, `template * 12` indexes `$7E:5EEE`, four sprites are published by `$B7B9`.
- The randomly placed stars come from the same stream, so the star field is also a function of the seed. The later twinkling (`$7E:95FE`, `draw(0x10+)` every few frames) and the shooting star use draws that depend on timing, after the moon exists.

## 4. Experiments [V]

Method: run event `0x4FD` (set `$D1/$D2/$D3` = `95 4D CA`, `$D0` = 1) from a field state of the companion fixtures, run 25,400 frames (map 107, before the restart), save the state, then for each case reload it, poke SRAM, run 1,300 frames and read the shadow OAM. (`python3 tools/ending_moon.py ROM CORE FIELD_STATE OUTDIR --random N`.) The WRAM map was taken from the same states, map id in `$DC`: the ending reaches 8, 180, 148, 149, 150, 108, 147, 146, 106, 151, 105, 152, 153, 104, 103, 102, 101, 107 (map changes at frames 907-25008 of this run, a few hundred frames earlier than the harness times of `docs/cutscene-ending.md`).

| experiment | result |
|---|---|
| SRAM as the core initialises it (all 0x60: XOR = 0, seed 0x7524) | gibbous (T1) |
| slot-0 word = 1 / 7 / 0xFFFF, others 0 | full (T0) |
| slot-0 word = 2, 3, 4, 5, 6 / 0xBEEF | crescent (T2) |
| word 0x7524 alone | gibbous (same as seed 0) |
| word 0x1234 alone | gibbous |
| 300 random quadruples of words (every fifth with only slot 0 set) | model `predict(XOR)` equals the emulator in **300 of 300**; split 112 / 99 / 89 |
| bytes `slot0+0`, `slot0+3`, `slot0+0x100`, `slot0+0x2BB`, backup `0x1001` changed | no change of the moon |
| slot-1 word 0x6061 (XOR = 1) | full, as predicted |
| slot-3 word 0x0160 (XOR = 0x6100) | full, as predicted |
| ending started with 0, 3, 11 and 37 idle frames first, with A / START+B / X+L pressed in a 3-of-7 pattern all the way | same moon for the same SRAM words, for all three seeds tried (0x7524-default, 1, 2: 12 runs) |
| moon crop watched for 6,000 frames after the screen appeared | only the shooting star (+2315..+2333) and one-frame star blinks change it; the moon pixels never change |

Party, flags, play time and story counters are not read by `$AD75` / `$C2D9` (only the four SRAM words above are); they were not varied one by one, because the model fed with only the XOR already reproduces 300 of 300 emulator results.

## 5. Other "moons" in the ending

- Map 150 (the daytime sky scene, frames 9062-9707 in this run): two small crescent moons are painted into the daytime cloud layer (BG2: disabling layer 2 removes clouds and crescents, `map150_layer_toggles.png`). They are static map art; I did not look for a condition because nothing varies in the map data (maps are fixed) [V: seen, not varied].
- The map-107 scene (the last field map) shows no moon; the moon belongs to the restart screen after it.

## 6. Confidence

- **High** (emulator-verified and modelled): the moon is one of three sprite sets, picked by `random(3)` at scene creation, and the random seed is the XOR of the four primary slot checksum words (default 0x7524 when 0). 300/300 random SRAM cases and the specific controls agree with the model; timing and input of the ending do not change it.
- **Medium**: the identification of the SRAM words as the slot checksums (read from the existing save-validation documentation, the code only loads `$30:6001/6401/6801/6C01`); real saves therefore change the moon as soon as a slot's payload changes (not tested with the game's own save routine in this run, only with SRAM pokes).
- **Not covered**: real hardware's SRAM contents with no saves (a physical cartridge may hold something other than the emulator's 0x60 fill; the result is then still `f(XOR)`), and non-vanilla ROMs (the Magno translation was not run).

## 7. Open points

- The ROM location of the code is inside the compressed `$C7:7C00` stream; the routines were read from the decoded image (`$7E:9373`, `$7E:AD75`), not single-stepped with the project interpreter.
- Whether the title screen path (`$7E:AF0B`) draws a moon: not looked at.
- The twinkle / shooting-star schedule (random, timing dependent) is not modelled.
