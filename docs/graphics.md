# Hero sprite graphics and the glove attack animations

How the three heroes are drawn (tile pools, palettes, sprite pieces, animation scripts) and every glove attack animation: the four normal attacks and the eight charged attacks, each in the three distance variants the game selects. Timing, boxes, damage and the choice of the variant are measured in `docs/glove-attacks.md`; this document is about the pictures and the data structures behind them. Everything below was obtained by running the original code in the interpreter from a save state (`tools/rip_hero_anims.py`) and by reading the disassembly; ROM data and images are never stored in this repository. The images produced by the tools go to a directory outside the repository that the caller chooses.

Tags: **[V]** executed in the interpreter and checked (a model, a decoder or pixel comparison against it); **[C]** read from the disassembly only. Banks: `$D1:3040` is the HiROM address, the file offset is `(bank - 0xC0) << 16 | address`.

Tools:
- `tools/gfx_decode.py`: 4bpp tile decoding, BGR555 palettes, OAM decoding, sprite rendering and a PNG writer / reader (standard library only).
- `tools/rip_hero_anims.py ROM STATE OUTDIR [heroes] [weapon_row] [attacks] [dirs]`: runs the attacks and writes PNG frames and JSON (section 7).
- `tools/hero_frames.py`: static decoder of the animation tables (no emulation), and a checker that compares it with the JSON written by the ripper (section 5; 6,180 of 6,180 script steps of the 336 ripped animations agree [V]).

## 1. Video set-up

| item | value | tag |
|---|---|---|
| OBJSEL (`$2101`) | `$7E:0091 = 0x63`: sprite sizes 16x16 (small) and 32x32 (large), name base word `0x6000`, second name table at word `0x7000` (gap 0). The code that builds it is `$C2:AAF0-AAFF` (`LDA #$60`, `LSR` x5, `ORA #$60`, `STA $91`, `STA $2101`) | V (value in the save states), C |
| hero pieces | all OAM entries of the heroes use the small size (the size bit of the high OAM table is never set), so every piece is 16x16 | V |
| tile number | 9 bits: OAM tile byte + bit 0 of the attribute byte (name table). Table 1 starts at VRAM word `0x7000`, so tile `0x1C0` is at word `0x7C00` | V |
| OAM | shadow at `$7E:0800` (512 + 32 bytes), copied by DMA in the NMI handler (`$C0:C124-C13B`) | C, V |
| CGRAM | shadow at `$7E:0600` (`$7E:BE00` while `$2A != 0`), copied by DMA in the NMI (`$C0:C0F0-C115`). Sprite palettes are CGRAM rows 8-15 (`128 + 16 * row`) | C, V |
| hero tile uploads | `$C1:950D` (called from the NMI, `$C0:C14E`) reads the tile tables of section 3 and DMAs 32 bytes per tile to VRAM | C, V |
| NMI / frame | the main loop body `$C0:B08C` runs once per NMI (60.0988 Hz); `$56` cycles 0-4. Phase 0: prepare actor depth lists (`$C0:E8D7`; native model in `tools/map_sprite_order.py`, OAM emission is a later consumer), phase 3: animation tick of the actors (`$C0:F4AB`, dispatched from `$C0:B0D3`), phase 4: second piece list (`$C0:F1AE`) | C, V |

All times below are in video frames of 1/60.0988 s. **An actor's animation script advances once per five frames** (phase 3), so every script step lasts a multiple of 5 frames [V, all 336 animations].

## 2. Palettes

- A hero uses one sprite palette row for its body: boy OAM palette 1 (CGRAM row 9), girl 2 (row 10), sprite 3 (row 11) [V]. Colour 0 is transparent; the slot holds filler.
- ROM source of the three rows: 15 colours (indices 1-15, BGR555 little endian, 30 bytes) at `$C8:1F00` (boy), `$C8:1F1E` (girl), `$C8:1F3C` (sprite) (file offsets `0x81F00`, `0x81F1E`, `0x81F3C`). The bytes are identical to the CGRAM shadow rows of an idle hero [V]. Further copies of similar rows are at `0x8202C-0x82D10` (not examined).
- Weapon effect pieces (arcs, flashes) use sprite palette 0 (row 8). While an attack plays, colours 10-15 of that row change every few frames: the routine `$C1:859B` copies a 5-colour set from `$D1:F600 + 10 * n` into the shadow [C]; the captured row cycles through six values and the images keep the value of the frame in which they were recorded [V]. Using weapon row 0 and weapon row 8 gives byte-identical PNGs [V], so the glove-specific flash colour is not produced by the equip refresh `$C0:E9F8` (section 10).
- The PNGs use the plain `c5 * 255 / 31` expansion of the 5-bit channels; the public sprite sheets use `c5 << 3`, so comparisons are made on the 5-bit values.

## 3. Tiles

- 4bpp planar tiles, 32 bytes: row `y` has plane 0 at byte `2y`, plane 1 at `2y+1`, plane 2 at `16+2y`, plane 3 at `17+2y`; bit 7 is the left pixel [V: decoded images are identical to the public sheets].
- **The hero tile pools are not compressed.** Each pool is a de-duplicated set of 8x8 tiles; frames pick tiles one by one (the tile order inside a pool has no relation to the picture layout) [V]:

| hero | pool | file offset |
|---|---|---|
| boy | `$D5:0000-7FFF` | `0x150000` |
| girl | `$D5:8000-FFFF` | `0x158000` |
| sprite | `$D6:0000-7FFF` | `0x160000` |

  The last tile of each 32 KiB window (`7FE0`) is all zero and is used as the "empty" tile [V]. Only the tiles of the glove animations were examined; the pools are 32 KiB windows, the frame data picks the tiles.
- Per hero, `$C0:F66E-F6BE` writes a table of 16 words into WRAM (`$0C00` boy, `$0C20` girl, `$0C40` sprite): a 16-bit offset into the pool for every 8x8 tile of the current frame. Four entries per piece in the order top-left, top-right, bottom-left, bottom-right. A hero therefore shows at most 4 pieces (16 tiles) at a time. The NMI uploads the table to VRAM tile slots (OAM tile numbers): boy `0x1C0-0x1C7` / `0x1D0-0x1D7`, girl `0x1C8-0x1CF` / `0x1D8-0x1DF`, sprite `0x1E0-0x1E7` / `0x1F0-0x1F7`; piece `k` of a hero uses the 2x2 block starting at slot tile `base + 2k` [V: DMA sources and destinations logged for every frame of the 336 animations].
- Table entry formats (`$C0:F66E-F6BE`) [C, V against 6,180 frames]: a word without bit 15 is `(w & 0x3FF0) << 1` (byte offset of one tile in the pool). A word with bit 15 is a run of `(w & 15) + 1` entries: with bit 14 set the offsets `(w << 1) & 0x7FE0` + 0x20 * k (consecutive tiles), with bit 14 clear the same offset repeated.
- **Weapon effect tiles** (the glove arcs, flashes) are 3-byte-per-row graphics in bank `$D4` starting at `$D4:0000` for weapon type 0. The equip refresh (`$C0:EA34`, `JSL $C1:C599` with bank `$D4`, `Y` = source offset = 24 x the word at `$D4:C000 + 4 * weapon type`, `X` = destination, 0x40 tiles) expands them to 4bpp into a per-actor WRAM buffer (`$7E:2000` boy, `$7E:3000` girl, `$7E:4000` sprite). For the heroes the expansion is `$C1:C8A9`: with source bytes `a b c` of a row, plane 0 = `~(b & c) & a`, plane 1 = `~b`, plane 2 = `b ^ c`, plane 3 = `~(b & c)`. A source pixel `(a,b,c)` therefore becomes colour 10 (0,0,0), 14 (0,0,1), 12 (0,1,0), 0 (0,1,1), 11 (1,0,0), 15 (1,0,1), 13 (1,1,0), 0 (1,1,1) [C, from the formulas]. These tiles reach VRAM from the buffer into tile slots `0x144` (boy), `0x168` (girl), `0x18C` (sprite) [V]. The variants `$C1:C5D1` and `$C1:C731` are other colour maps of the same loader and were not used here.

## 4. Choosing the animation of an attack

The attack start is in `$C0:B21C-B2F6`. A tap of B (button edge) starts a normal swing at once (`$C0:B29F`: attack state `+0x1C = 0x20`). While B stays held and the weapon gauge (`+0x1ED`) is zero, the charge stage `+0x19B` rises; releasing B with stage > 0 starts the charged attack (`$C0:B24A`: `+0x1C = 0x80`). The animation id (`+0x11`) comes from `$C1:E40E` [C, V]:

```
distance class d = min over the active monster slots of max(byte +0x50+3h, byte +0x51+3h), >> 4, clamped to 3      ($C1:E4CC; 3 with no monster)
index  = d * 144 + stage * 16 + status_variant * 4 + (target +0x1B1 & 2) + ($F4 & 1)
kind   = $D1:0000[index]                      (576 bytes)
anim   = $D1:0480[weapon_type * 40 + kind]    (320 bytes; for weapon type 0 the table is the identity, so kind == animation id)
```
`status_variant` is 1, 2 or 3 when the target has status bit `0x01`, `0x02` or `0x10` in its `+0x190`; `h` is the hero index. The meaning of the two distance bytes of the monster record was not traced; the thresholds in pixels that this gives (measured with a dummy monster) are in `docs/glove-attacks.md` section 2.2, where "variant n" is the animation id n below and the class value there is `d + 1`.

Results for weapon type 0 (the glove group), read from the tables [C] and observed with the target-less sandbox [V]:

| attack | animation id | selected when |
|---|---|---|
| normal 0 "hook" | 0 | d = 0, `$F4` odd |
| normal 1 "jab" | 1 | d = 0, `$F4` even; d = 1, `$F4` odd |
| normal 2 "kick" | 2 | d = 1, `$F4` even; d >= 2, `$F4` odd |
| normal 3 "lunge" | 3 | d >= 2, `$F4` even |
| charge, stage k = 1..8, variant "near" | 4k | d = 0 |
| charge, variant "mid" | 4k + 1 | d = 1 |
| charge, variant "far" (also no target) | 4k + 2 | d >= 2 |
| ids 7, 11, 15 ... 35 | target with status `0x02` or `0x10` (any distance class; stage 0 and 1 give 7, stage k >= 2 gives 4k + 3); not ripped |
| ids 36-39 | distance class 0, target with status `0x01`, odd `$F4`, stage 0-3; not ripped |

The names hook/jab/kick/lunge describe the pictures; the game has no names. The variants differ in duration and in how far the hero moves: stage 1 near/mid/far = 65 / 70 / 75 frames and 20 / 30 / 50 px of movement for the boy facing right [V].

## 5. Animation data

Actor record: `$7E:E000 + 0x200 * slot`, slots 0-2 = boy, girl, sprite (section 1 of `rom-combat.md`). Fields used here [C, V]:

| offset | meaning |
|---|---|
| `+0x02` / `+0x04` | world x / y (words); the screen position `+0x20/+0x22` is world minus the camera `$A8/$AA` (`$C0:E443-E46E`) |
| `+0x10` | facing: 0 up, 1 down, 2 side, bit 7 = mirrored (left). The script table index uses the low nibble |
| `+0x11` | animation id (section 4) |
| `+0x12` | remaining extra ticks of the current script step |
| `+0x16` | script pointer after the entry just read |
| `+0x1C` | attack state: 0 none, 0x20 normal swing, 0x80 charged attack |
| `+0x20` / `+0x22` | x / y on screen (the foot point) |
| `+0x26` | frame index * 2 |
| `+0x28` | frame flags: bit 7 vertical, bit 6 horizontal mirror |
| `+0x2A` | frame descriptor table (bank `$D1`), `0x2040 + 0x200 * type` (word table `$D0:FFD0` indexed by weapon type) |
| `+0x45` | jump height |
| `+0x65`, `+0x75` | script pointer tables: attack/charge states (`0x3040 + 240 * type`) and ordinary states (`0x37CC`), bank `$D1` |
| `+0x72` | per-hero offset into the piece-list pointer table in bank `$D2`: 0x000 boy, 0x200 girl, 0x400 sprite |
| `+0x74` | low 7 bits: body height 14 (all three heroes); the pieces are drawn that many pixels above the foot point |
| `+0x83` / `+0x84` | piece count of list 1 / list 2 |
| `+0x86`, `+0x8A` | first tile (and attribute byte) of list 2 / list 1: list 2 tiles 0x144, 0x168, 0x18C (the effect tiles), list 1 attribute `0x23` / `0x25` / `0x27` (priority 2, palette 1 / 2 / 3, name table 1) and tiles 0x1C0, 0x1C8, 0x1E0 |
| `+0x90` | list 1: up to 15 OAM-ready entries `x, y, tile, attribute` (the hero body pieces) |
| `+0xD0` | list 2: the ground shadow (tile 0, palette 1, at -8,-8) and, during attacks, the effect pieces |
| `+0x19B` / `+0x19C` | charge stage / weapon level |
| `+0x1E3` | equipped weapon row id (not the weapon type: `$C0:EA41` reads `$D0:1000 + 12 * row`, byte 0 = weapon type) |
| `+0x1ED` | weapon gauge |

Reading a frame (`$C0:F4CB-F6C0`, executed in `$C0:F4AB` every tick):

1. **Script.** The script of an animation is at `$D1:[table + (anim * 3 + (facing & 15)) * 2]` (a word). Entries are 2 bytes: `b0` (bit 7 clear), `b1` = frame index (0-255). Duration: if `b0 & 7` < 4 the step lasts `(b0 & 7) + 1` ticks, otherwise 1 tick. `b0` bits 6 and 5 are the vertical and horizontal flip of the frame; bit 5 is inverted when the actor faces left (+0x10 bit 7), so left uses the right-facing script mirrored. An entry with bit 7 set is an operation (`$C0:F90B`): `FF` ends the script (clears `+0x1C` and the animation id and, after a swing, loads the weapon gauge `+0x1ED`), `FE` repeats the operation on the next tick while the actor's status bits `0x7B` are set, `F1 lo hi` jumps inside the bank; the others are dispatched by the first byte to `$01:D5C0` (`80`-`AF`, for example `90`, `A8`), `$01:D6DC` (`B0`-`EF`), `$01:D52A` (`F0`-`F7`) and `$01:D48D` (`F8` and up, for example `F9 xx yy`); their arguments were not decoded here (`docs/glove-attacks.md` describes the velocity, box and sound operations the glove scripts use) [C, V against the operations met in the traces].
2. **Descriptor.** `$D1:[+0x2A + 2 * frame]` is a word: low byte bits 7-6 = frame flips (XORed with the script flags), high byte `h` selects the piece list: pointer = word at `$D2:[+0x72 + 2 * h]`. The same descriptors serve the three heroes; only the piece lists differ.
3. **Piece list** (bank `$D2`): header byte (low nibble = piece count, 0 means 1; bits 6 and 5 announce a body box and a further box after the pieces, read into `+0xC8-0xCB` and `+0xCC-0xCF` (bit 4 selects byte or nibble coordinates), not used for drawing [C]; the boxes are described in `docs/glove-attacks.md`); the tile words of section 3 (4 per piece); then 2 bytes per piece `lo, hi`: `y = signed 7-bit (lo & 0x7F)`, `x = signed 7-bit (hi & 0x7F)`, bit 7 of `hi` = horizontal flip of the piece; bit 7 of `lo` is not used. With a frame flip the position is mirrored (`v -> -v - 16`) and the flip bit toggled.
4. **Placement.** OAM x = `+0x20` + x; OAM y = `+0x22` - (`+0x74 & 0x7F`) - `+0x45` + y. The pieces get consecutive tile numbers `base, base + 2, ...` (when bit 4 of the number is set 0x10 is added, so a row holds 8 pieces) and the attribute from `+0x8A` / `+0x86` [C].
5. List 2 is built the same way by `$C0:F1CF-F409` from `$D4:[+0x6A]` tables (ground shadow and effect pieces); its coordinates are 4-bit pairs in `$D1:[+0x7E + frame]`.

`tools/hero_frames.py` implements steps 2-4 and its output equals the recorded pieces of all 6,180 script steps in the 336 ripped animations (position, flips, piece count) [V].

## 6. The glove animations

All values were produced by `tools/rip_hero_anims.py` from a save state with the sandbox of section 8 and are identical for the three heroes (timing, movement and jump height of all 112 animations of each hero are equal [V]). "Frames" are video frames from the first script step to the end of the attack state; add `latency_frames` (1-5, depending on where in the five-frame cycle the button is pressed) for the time from the press. The names hook / jab / kick / lunge describe the pictures (hook: a short swinging punch, jab: a straight punch in four pictures, kick: a high side kick, lunge: a step-in punch); the game has no names. Left is the exact mirror image of right in every frame and has the same timing [V, 5,148 of 5,148 right-facing pictures compared]. The "near / mid / far" variants of stages 1-5 differ by a short dash in front of the attack (20 / 30 / 50 px at stage 1) and 5 frames each; stages 6, 7 and 8 are identical in the three variants (the dash is not present).

| attack | anim id | frames, up / down | frames, left / right | seconds, up-down / left-right | pictures per direction | net movement px, boy: up / down / left / right | farthest point px (up, down, left, right) | max jump |
|---|---|---|---|---|---|---|---|---|
| hook | 0 | 20 / 20 | 20 / 20 | 0.333 / 0.333 | 2-2 | 0,-10; 0,10; -10,0; 10,0 | 10, 10, 10, 10 | 0 |
| jab | 1 | 20 / 20 | 20 / 20 | 0.333 / 0.333 | 4-4 | 0,-5; 0,5; -5,0; 5,0 | 5, 5, 5, 5 | 0 |
| kick | 2 | 25 / 25 | 20 / 20 | 0.416 / 0.333 | 3-3 | 0,0; 0,0; 0,0; 0,0 | 0, 0, 0, 0 | 0 |
| lunge | 3 | 25 / 25 | 25 / 25 | 0.416 / 0.416 | 3-3 | 0,-10; 0,10; -10,0; 10,0 | 10, 10, 10, 10 | 0 |
| charge near, stage 1 | 4 | 70 / 70 | 65 / 65 | 1.165 / 1.082 | 8-8 | 0,-20; 0,20; -20,0; 20,0 | 20, 20, 20, 20 | 0 |
| charge mid, stage 1 | 5 | 75 / 75 | 70 / 70 | 1.248 / 1.165 | 9-9 | 0,-30; 0,30; -30,0; 30,0 | 30, 30, 30, 30 | 0 |
| charge far, stage 1 | 6 | 80 / 80 | 75 / 75 | 1.331 / 1.248 | 9-9 | 0,-50; 0,50; -50,0; 50,0 | 50, 50, 50, 50 | 0 |
| charge near, stage 2 | 8 | 80 / 80 | 80 / 80 | 1.331 / 1.331 | 33-34 | 0,-35; 0,35; -35,0; 35,0 | 35, 35, 35, 35 | 0 |
| charge mid, stage 2 | 9 | 85 / 85 | 85 / 85 | 1.414 / 1.414 | 34-35 | 0,-45; 0,45; -45,0; 45,0 | 45, 45, 45, 45 | 0 |
| charge far, stage 2 | 10 | 90 / 90 | 90 / 90 | 1.498 / 1.498 | 34-35 | 0,-65; 0,65; -65,0; 65,0 | 65, 65, 65, 65 | 0 |
| charge near, stage 3 | 12 | 110 / 110 | 105 / 105 | 1.83 / 1.747 | 43-43 | 0,-20; 0,20; -20,0; 20,0 | 20, 20, 20, 20 | 10 |
| charge mid, stage 3 | 13 | 115 / 115 | 110 / 110 | 1.914 / 1.83 | 44-44 | 0,-30; 0,30; -30,0; 30,0 | 30, 30, 30, 30 | 10 |
| charge far, stage 3 | 14 | 120 / 120 | 115 / 115 | 1.997 / 1.914 | 44-44 | 0,-50; 0,50; -50,0; 50,0 | 50, 50, 50, 50 | 10 |
| charge near, stage 4 | 16 | 125 / 125 | 120 / 120 | 2.08 / 1.997 | 33-33 | 0,-15; 0,35; -35,0; 35,0 | 30, 35, 35, 35 | 10 |
| charge mid, stage 4 | 17 | 130 / 130 | 125 / 125 | 2.163 / 2.08 | 34-34 | 0,-25; 0,45; -45,0; 45,0 | 40, 45, 45, 45 | 10 |
| charge far, stage 4 | 18 | 135 / 135 | 130 / 130 | 2.246 / 2.163 | 34-34 | 0,-45; 0,65; -65,0; 65,0 | 60, 65, 65, 65 | 10 |
| charge near, stage 5 | 20 | 150 / 150 | 140 / 140 | 2.496 / 2.329 | 91-94 | 0,-30; 0,30; -30,0; 30,0 | 30, 30, 30, 30 | 10 |
| charge mid, stage 5 | 21 | 155 / 155 | 145 / 145 | 2.579 / 2.413 | 92-95 | 0,-40; 0,40; -40,0; 40,0 | 40, 40, 40, 40 | 10 |
| charge far, stage 5 | 22 | 160 / 160 | 150 / 150 | 2.662 / 2.496 | 92-95 | 0,-60; 0,60; -60,0; 60,0 | 60, 60, 60, 60 | 10 |
| charge near, stage 6 | 24 | 150 / 150 | 150 / 150 | 2.496 / 2.496 | 135-150 | 9,0; 9,0; -9,0; 9,0 | 30, 30, 40, 40 | 0 |
| charge mid, stage 6 | 25 | 150 / 150 | 150 / 150 | 2.496 / 2.496 | 135-150 | 9,0; 9,0; -9,0; 9,0 | 30, 30, 40, 40 | 0 |
| charge far, stage 6 | 26 | 150 / 150 | 150 / 150 | 2.496 / 2.496 | 135-150 | 9,0; 9,0; -9,0; 9,0 | 30, 30, 40, 40 | 0 |
| charge near, stage 7 | 28 | 140 / 140 | 140 / 140 | 2.329 / 2.329 | 85-88 | 0,-105; 0,105; -105,0; 105,0 | 115, 115, 115, 115 | 20 |
| charge mid, stage 7 | 29 | 140 / 140 | 140 / 140 | 2.329 / 2.329 | 85-88 | 0,-105; 0,105; -105,0; 105,0 | 115, 115, 115, 115 | 20 |
| charge far, stage 7 | 30 | 140 / 140 | 140 / 140 | 2.329 / 2.329 | 85-88 | 0,-105; 0,105; -105,0; 105,0 | 115, 115, 115, 115 | 20 |
| charge near, stage 8 | 32 | 200 / 200 | 200 / 200 | 3.328 / 3.328 | 120-125 | 0,-75; 0,95; -95,0; 95,0 | 105, 95, 95, 95 | 10 |
| charge mid, stage 8 | 33 | 200 / 200 | 200 / 200 | 3.328 / 3.328 | 120-125 | 0,-75; 0,95; -95,0; 95,0 | 105, 95, 95, 95 | 10 |
| charge far, stage 8 | 34 | 200 / 200 | 200 / 200 | 3.328 / 3.328 | 120-125 | 0,-75; 0,95; -95,0; 95,0 | 105, 95, 95, 95 | 10 |

Totals: 3 heroes x 4 directions x (4 normal + 8 stages x 3 variants) = **336 animations and 20,610 distinct pictures** (boy 6,670, girl 6,970, sprite 6,970). The normal attacks last 0.333-0.416 s, the charged attacks 1.08-3.33 s. A hero has at most 4 body pieces and at most 4 effect pieces on screen at a time. The longest picture sequences are stage 6 (135-150 pictures, two-step alternations) and stage 8 (120-125). "Net movement" is the displacement at the end of the attack state, "farthest point" the largest displacement during it (px, boy): in the up versions of stages 4 and 8 the hero moves part of the way back, so the net value is smaller. Stage 6 shifts the hero by 9 px along x whatever the facing. The jump height column is the largest value of `+0x45` (the sprite is drawn that many pixels above the foot point).

## 7. Output files

`OUTDIR/<hero>/<attack>_<level>_<dir>_<nn>.png` and `<attack>_<level>_<dir>.json`, plus `OUTDIR/index.json`.

- `<hero>` boy / girl / sprite; `<attack>` hook, jab, kick, lunge (level 0) or charge / chargemid / chargenear (level 1-8); `<dir>` up, down, left, right.
- One PNG per distinct picture (consecutive identical frames are merged), RGBA with colour 0 transparent, 1:1 pixels, every PNG of an animation has the same size (union box of the animation). `origin` in the JSON is the foot point (actor position) inside the PNG. Effect pieces are included; the ground shadow is not.
- JSON: `frames[]` (file, `start_frame`, `frames` = duration in video frames, `seconds` = frames / 60.0988, actor position and movement, animation id, script position, palettes of the sprite rows used, pieces with `list` 90 or D0, `dx`, `dy` relative to the foot point, tile, palette, priority, flips, `ground_shadow`), `script_steps[]` (every change of script position / frame index with its duration and PNG), `per_frame` (PNG index, actor movement and jump height for every video frame), `latency_frames` (frames between the button press and the first script step, during which the previous pose stays), `start_world_position` and `movement_during_latency` (world coordinates `+0x02/+0x04`), `distance_class`, `total_frames`, `total_seconds`. All offsets are world pixels (the screen scroll is not included).

## 8. Running it

```
python3 tools/rip_hero_anims.py /path/to/rom.sfc /path/to/state.zs3 /path/to/outdir "" 0 "" "" 128,112
python3 tools/hero_frames.py    /path/to/rom.sfc check /path/to/outdir
python3 tools/hero_frames.py    /path/to/rom.sfc sprite 0 3 side
python3 tools/compare_sheet.py  /path/to/sheet.png /path/to/outdir boy
```
(the empty arguments of the first command mean "all heroes", "all attacks", "all directions"). A full run takes about 10 minutes per hero. The state must be a ZSNES v143 save state taken during play with the three heroes active (object slots 0-2 non-zero in `+0x00`).

What the tool does to the save state (all of it only inside the interpreter) [V]:
- deactivates every other actor (so there is no monster and no partner), makes the hero the pad-1 hero (`$D9`, `$D4`) and presses B through the joypad registers (`$4218/$4219`); the polling is stubbed, the NMI handler `$C0:C0A8` runs once per frame with the DMA and PPU register writes captured;
- sets the hero position (`+0x02`, `+0x04` = screen position + camera `$A8/$AA`) 40-45 px behind the centre of the lunges, opposite to the facing, and the facing `+0x10`;
- equips weapon row `row` (`+0x1E3`, `+0x1E4`, `+0x1E8`, weapon level `+0x19C` = 8, charge limit `$CC7D+slot` = 8) and runs the engine's own refresh `$C0:E9F8` (this loads the animation tables, the frame-table pointers and the effect tiles of section 3), clears the attack, status and gauge fields, runs 30 frames;
- removes everything that would shorten a lunge: the party window `$C0:D6C8` (section 9 of `hero-movement.md`) is replaced by an RTS and the solid-tile codes of the tile attribute table are cleared (`$7F:B800`, bytes b0 and b2). Without this the stage 7 and 8 attacks stop at the screen window `x 56-199, y 72-175` [V];
- forces the distance class by overriding the result of `$C1:E4CC` at `$C1:E418`, and the `$F4` parity by choosing the press frame; a charged attack is produced by holding B (the stage rises by itself, every 90 frames after the first; about 185 frames for the first with the boy), snapshotting the state when each stage is reached and releasing B from the snapshot.

Two different save states (a boss arena and a field map) gave identical PNGs and durations for the boy [V]. All three heroes give identical timing, movement and jump height in all 112 animations; the split of the video frames into runs of identical pictures differs for the girl and the sprite in some animations only because their pieces are different pictures.

## 9. Validation against public sprite sheets [V]

Each frame was compared pixel by pixel (5-bit colours, in the sheet orientation or mirrored) with the public sprite sheets of the glove animations ("Glove (Randi)" for the boy, "Glove (Popoi)" for the sprite, "Primm" for the girl, from The Spriters Resource). For a frame with effect pieces the effect palette colours are left out of the comparison (the sheets show one palette phase). Result with `tools/compare_sheet.py` (frames with fewer than 40 body pixels would be skipped; none occurred): **boy 6,670 of 6,670, girl 6,970 of 6,970, sprite 6,970 of 6,970 distinct pictures are found pixel for pixel in the sheets**, including every up and down picture (the girl's sheet is a collection of loose sprites, not organised by attack and direction, but it holds every picture). On average 95-96 % of the opaque pixels of a picture take part (the rest are effect colours). Negative controls: changing one pixel of a picture, or looking for a boy picture in the girl's sheet, finds nothing. The effect pieces themselves were compared separately for the sprite hero by replacing the six cycling effect colours by one marker colour on both sides (union of body and effect pieces: exact for the frames tried; the sheets do not show the colour cycle). What the sheets cannot tell is the timing, the order and the movement, which come only from the game code.

## 10. Open questions

- The operations of the animation scripts (`90`, `A8`, `F9 xx yy`, `F0`-`F8`): arguments and effects (sounds, hit timing, spawning) were not decoded here; `docs/glove-attacks.md` has what the glove scripts use.
- Variants 4k+3 and 36-39 (target with a status) were not ripped; they can be produced by forcing `$00` at `$C1:E45C`.
- How the monster record fills the two distance bytes at `+0x50+3h` / `+0x51+3h` (units, axis).
- The flash colour per glove (the public sheet says it depends on the glove): rows 0 and 8 gave identical colours here; `$D1:F600` holds the colour sets but the code that picks the set for a glove was not traced.
- The HUD sprites (charge gauge), HDMA, colour math and window effects are not emulated and are not in the images; any full-screen flash of the highest charge levels is therefore missing.
- The charge-up pose while B is held (a single static pose at every stage in this capture) and the stage-up flash were not ripped.
- Weapon types other than 0 share the same tables (section 4) and should work with `weapon_row` 9-71, but only the glove group was run.
- The meaning of bits 4 and 3 of `b0` in a script step and of the value `+0x89` that is written when `b0 & 7 >= 4`.

## Complete frame tile coordinator C1950D [V]

`tools/actor_frame_upload.py` reconstructs the complete C1950D coordinator through C1B032, including the three five-entry dispatch tables at C19548/C19552/C1955C. These tables contain instruction addresses, not graphics payloads. Word0056 selects phases0..4; byte00ED zero chooses the third table, otherwise byte005C negative chooses the second, and nonnegative chooses the first. The entry saves D, selects D4300, sets VMAIN80 and initializes channels4..7 to mode1/target2118 with zero high length bytes. DB0 is the tested NMI calling convention.

Each tile pair uses two halves separated by0100 VRAM words. Each half starts four32-byte DMA transfers in channel order4..7. The first half reads source words at offsets0/2/8/A from the16-byte pointer record; the second uses4/6/C/E. Pointer and source address wrap are preserved. Normal tiles take the bank from actor+82; auxiliary tiles use WRAM7E. Counts come from the low bytes of actor+83/+84 and consume two counts per pair, with odd counts still uploading the final pair. The final capped pair leaves the original X residual, rather than decrementing it once more. Auxiliary actor+8D low-byte flags clear themselves, preserve the high byte and force pair4 even if the ordinary auxiliary count was zero.

| Family and phases | Actors and maximum pairs | Pointer tables | Initial VRAM word targets |
|---|---|---|---|
| All families, phase3 | Heroes0/1/2 normal:2 each; then hero0 auxiliary:5 | C00/C20/C40; C60 | 7C00/7C80/7E00;7440 |
| All families, phase4 | Heroes1/2 auxiliary:5 each | CB0/D00 | 7680/78C0 |
| Nonnegative005C, phases0/1/2 | One boss at slot3/4/5:6 normal pairs, then5 auxiliary | E60/EC0/F20;D60/DB0/E00 | 6400/6680/6A00;6C80/6EC0/7200 |
| Zero00ED, phases0/1/2 | Three separate actors3..5/6..8/9..11:2 normal pairs each | E60+20*(slot-3) | 6400+80*(slot-3)+100*floor((slot-3)/2) |
| Negative005C, phases0/1/2 | Guarded slot3/4/5 auxiliary:5; conditional C20009 first | D60/DB0/E00 | 6C80/6EC0/7200 |

Numbers in this table are hexadecimal except actor indices, phase indices and pair counts. Across pair boundaries the destination skips the pages reserved for the second halves: `target = base + pair*64 + ((pair + ((base//64)&3))//4)*256`, with decimal constants in this formula. The ordinary boss phases process one six-pair actor, whereas the zero00ED phases process three separately enabled actors and banks.

For the negative005C family, actor+60 zero or positive with actor+61 zero calls the complete original C20009 and returns immediately with M16/X16. A negative actor+60 skips that call and proceeds to auxiliary tiles. A positive actor+60 with nonzero+61 clears+61, saves the selected actor index, calls C20009 with M8/X16, restores the index and uploads auxiliary tiles with M16/X8. The model composes the verified boss uploader and RNG; the interpreter executes their actual instructions without bypass hooks.

One inherited hardware effect matters: C20009's pending high-plane upload can leave channel7 at target2119. The following auxiliary transfer retains that target, so alternate bytes reach VRAM high and Mode7 select211A. `tools/actor_ppu.py` is an isolated extension that records these211A writes and stores the exposed selection bits with maskC3; historical peripheral runtimes are unchanged. Residual native stack writes are also reconstructed because subsequent WRAM tile pointers can read that very call frame.

`data/actor_frame_upload.json` records15,840 complete native comparisons: all256 count/flag bytes, all four incoming M/X combinations, three families, five phases, plus mixed actor-enable masks. Full WRAM outside129 call-frame bytes, VRAM, CGRAM, DMA, arithmetic hardware, static PPU state, ordered peripheral writes and final CPU registers/flags agree. Stack bytes read by DMA are included through their resulting video effects. The tested domain uses D0/0300/1234/FFFF, DB0, binary arithmetic, forced blank, valid55-byte RNG indices and sampled ROM mirrors/WRAM banks, with source wrapping. Invalid phase indices, unsupported buses, rendered frames, OAM, live HDMA/interrupt delivery and timing remain open. Graphics payloads stay in volatile memory.

The complete NMI now composes these actor transfers with palette, OAM, map tiles, HUD, scroll andmenu updates. `tools/map_nmi_frame.py` passes4,160 full native handlers through RTI, including64 whole-bank menu transfers. `tools/nmi_ppu.py` and the independent port vectors reconstruct static OAM uploads from0800..0A1F; main-loop sprite emission/evaluation/rendering remain open. See `docs/maps.md` and `data/map_nmi_frame.json` for the tested interrupt-frame andbus scope.

Frame-screen effects C08B5E andall scene-camera callees are now reconstructed. Full brightness/mosaic/blink/centering models pass167,936 direct native calls,and32 continuous fade/NMI sequences cover28,412 frames. This proves static register/colour effects andbrightness publication,including the8F black endpoint; rendered effects andmain-loop sprite emission remain open. See `docs/maps.md` andtheeffect/fade reports.


## Complete party HUD sprite emission

C1E61D (4-byte long wrapper), C1E621 (71-byte dispatcher) and C1E668 (60-byte emitter) now reconstruct as a contiguous 135-byte component. This is the first call in main-frame OAM consumer C0E38E. The dispatcher emits no sprites when CF00 is zero, byte52 is nonzero, or E8 equals3. Otherwise each nonzero anchor at0A55/0A65/0A75 selects the corresponding actor attribute byte E093/E293/E493 and tile01E8/01EA/01EC. It does not inspect actor ID or HP here.

The emitter takes the anchor from A's high byte and the attribute from A's low byte. Screen X is `(((anchor&31)-2)*8)&255`; Y is fixed C7. Tile/attribute word is `inputY | 3000 | ((attribute&0E)<<8)`. It writes both words at0800/0802 plus the word cursor7C, then advances that cursor and returned Y by four. Byte59 shifts left twice; carry is original bit6, and on carry byte5A increments with byte wrap and byte59 becomes1. Bit7 is discarded rather than acting as carry for that second shift. No hardware OAM or video writes occur here.

`data/map_hud_sprites.json` records 70,656 complete original calls without bypass hooks: all65,536 anchor/attribute pairs,4,096 dispatch calls across all E8 bytes/four incoming widths/presence masks,1,024 long-wrapper calls,all256 phase bytes and prepared software-OAM cursor boundaries0/4/1F8/1FC/200. Full WRAM outside129 native call-frame bytes,unchanged complete static video/DMA/PPU/hardware and final CPU agree. Direct emitter requires M8/X16; dispatcher accepts all widths. D0/DB0/binary arithmetic and valid buffer placement define the scope. Overflow beyond the OAM workspace,outer emission chains,rendering and live interrupt scheduling remain open.


## Complete actor ground-shadow selector and clipped emitter

C0E760..C0E806 selects shadow pieces; C0E807..C0E889 clips and writes them into software OAM. The 167-byte selector and 131-byte helper build as a contiguous 298-byte component. The separate 12-byte C0E382 timer decrements its M8 input twice, stores actor+0F, clears carry for negative results and otherwise compares with 1. Its encoded immediate and return assume M8; word entry is not covered by that model.

The selector stores FFF8 as vertical offset 04. It returns when actor+0F is nonzero, actor+0E is negative, or actor+74 is nonnegative. CF01 bit2 suppresses the actor matching word D4; bit1 without bit2 suppresses slots below 0600. Attribute bits 30 come from override +8E shifted four times when nonzero, or byte +8B otherwise. Size +89 low two bits select these tile/offset sequences:

| Size | Tiles and horizontal offsets |
|---|---|
| 0 | 0200 at -8 |
| 1 | 0202 at -16, 4202 at 0 |
| 2 | 0204 at -16, 4204 at 0 |
| 3 | 0206 at -24, 0208 at -8, 4206 at 8 |

Every selected piece invokes the original helper, including pieces rejected or blocked by capacity. The helper ORs its tile with global word 98 and attributes 0E. Y clipping accepts 0..223 and -16..-1; more negative values add extent C2 once and must land below 224. X accepts 0..255 and -32..-1; more negative values add extent C0 once and must land below 256. Arithmetic is 16-bit with original carry and overflow. There is no repeated modulo normalization.

Vertical clipping returns M16. After accepted Y, its low byte is stored in scratch 08; horizontal clipping can then return M16. Cursor >=0200 returns M8 after CPY without a sprite write. Accepted pieces write X/Y and tile words at 0800+cursor, advance word 7C by four, and retain returned Y at the previous cursor. For nonzero X high byte, the packed high-OAM byte at 0A00+byte5A is XORed with byte59. Packing phase 59 shifts left twice, using original bit6 as carry; on carry, 5A increments with byte wrap and 59 becomes 1. Hardware OAM and video remain unchanged until a later transfer.

`data/map_actor_shadows.json` verifies 104,080 complete original calls without bypass hooks: 5,776 two-axis signed/viewport/extent/capacity boundary cases, all 256 CF01/override bytes across 128 guard/size/width contexts (32,768 calls), and all 65,536 accumulator values for the M8 timer. Twelve actor slots, all size variants, negative-X high OAM and capacity guards occur. Full WRAM outside 129 stack bytes, unchanged static peripherals and final CPU agree. Scope: D0/DB7E/X16, binary arithmetic; piece M16, selector either M, timer M8. Rendering, live interrupt scheduling and remaining body/boss emission chains are open.

## Complete ordinary actor body preparation and piece emission

C0E5CE..C0E63F (114 bytes) prepares an ordinary actor body; C0E640..C0E6CE (143 bytes) consumes its packed four-byte pieces. Together they independently assemble as 257 contiguous bytes. The preparer reads actor offset 14, skips odd F4 frames when actor+0E bit6 requests blinking, and sets word 02 to actor+83 low nibble. Zero returns M16 before emission. The list pointer is actor offset OR E090. Scratch 04 takes actor+20; scratch 06 is actor+22 minus `(word(actor+74)&7F)+word(actor+45)`, retaining the original 16-bit carry and overflow.

Actor+0D is a byte jitter counter. Nonzero values subtract 10(hex), clamping a borrow to zero. Surviving bit0 after subtraction toggles the horizontal scratch low byte with `(F4&1)*2`; bit1 toggles the vertical scratch low byte. These are XOR operations on low bytes. The preparer preserves the original shift/carry/flag residue and calls the original list consumer.

Each piece is a signed X byte, signed Y byte and tile/attribute word. Cursor >=0200 returns immediately without decrementing the count or advancing the piece pointer. Y clipping accepts 0..223 and -16..-1; X accepts 0..255 and -16..-1. This consumer has no map-extent wrapping and uses a narrower negative-X range than the shadow helper.

When Y succeeds, its byte is written immediately to 0801+cursor. If X then fails, that Y write remains while the cursor and other sprite bytes stay unchanged. An accepted piece writes X and tile, uses literal XOR with byte59 for nonzero X high byte, and advances cursor/Y by four. Packing phase 59 and byte5A retain the same two-shift/original-bit6 semantics as the shadow and HUD paths.

After each processed or clipped piece, only low byte 02 decrements. Zero on entry therefore underflows and processes 256 pieces unless capacity returns sooner; it is not an empty-list sentinel. High byte 03 is preserved. X advances four only when another piece is requested, so the final pointer remains at the last processed piece. An OAM-full return leaves the current count and pointer intact.

`data/map_actor_body_sprites.json` verifies 100,352 complete original calls without bypass hooks: all 65,536 signed-byte offset pairs at prepared screen boundaries; all 256 jitter counters across 128 blink/phase/count-nibble contexts (32,768 calls); and all 256 raw list counts across eight clipping/capacity contexts (2,048 calls). Full WRAM outside 129 stack bytes, unchanged static peripherals and final CPU agree. Scope: D0/DB7E/X16, binary arithmetic, both incoming M widths, prepared valid actor/list memory. Alternate/effect-body selection, boss emission, rendering, timing and full main-frame scheduling remain open.

## Continuous software sprites through original NMI publication

`map_sprite_publication.py` composes the existing HUD emitter, ordinary bodies, ground shadows and complete original NMI handler. All 256 mixed contexts pass one HUD, twelve body, twelve shadow and one NMI call each: 6,656 native calls, comparing full memory, peripherals and CPU after every call. EC8 requests OAM alone; palette, menu and graphics DMA are disabled for this proof.

Every one of the 544 software OAM bytes is compared with published hardware OAM, including initial high-table bytes, XOR packing, clipped partial writes and capacity residue. The caller supplies actor pointer restoration and interrupt frames explicitly. This does not prove whole main-loop scheduling, live vector delivery or rendered sprites. Reports preserve hashes and evidence; graphics payloads remain in volatile memory.


## Complete effect-list preparation and three-part merging

C19017..C191E0 independently reconstructs as a contiguous 458-byte component: 160-byte merged-list preparation, 79-byte append helper, 132-byte single-effect preparation and 87-byte direction selection. `map_actor_effect_sprites.py` passes 49,152 complete original calls without bypass hooks: 8,192 direction calls, 16,384 single-effect preparations, 8,192 append calls and 16,384 merged preparations.

C19106 reads the type at E110+Y. Type zero returns carry clear before scratch changes. Types 1..3 also return early when E114+Y is nonzero. Other paths first prepare count from actor+84 low nibble and coordinates from actor+20/+22, effect offsets E118/E11A and height `(actor+74)&7F` plus word actor+45. The vertical calculation retains carry between its two final additions. Workspace pointer begins at `(actoroffset>>1) OR C000`.

Type 1 returns carry set only for nonzero count. Types 2/3 replace count with 3 and select a piece offset from E112+Y. Type 4 ORs word E11C+Y into the workspace pointer and replaces count with byte E113+Y shifted right twice; carry reports whether that count is nonzero. Types >=5 return carry clear after the preparatory scratch changes. No pointer sum is substituted for the original OR operations.

Direction selection at C1918A uses these byte ranges:

| Direction byte | Workspace offset ORed into X |
|---|---|
| 00..0F or F0..FF | 18 |
| 10..2F | 48 |
| 30..4F | 24 |
| 50..6F | 54 |
| 70..8F | 3C |
| 90..AF | 30 |
| B0..CF | No change |
| D0..EF | 0C |

For B0..CF it returns directly, retaining M8, A and scratch 00. Other ranges write a zero-extended offset to word 00 and return M16 with X/A equal to the pointer OR result. Thus the effect preparer's successful return width depends on direction.

C19017 proceeds only when the OR of the three part types equals 3. It copies one coordinate word from C06C+(actoroffset>>1) to C060/C064/C068 at that workspace offset, preserving other record bytes. Actor+10 orientation is interpreted with its original byte sign: zero chooses vertical -24, one vertical +24, other positive values horizontal +24, and negative bytes horizontal -24. Height and position arithmetic preserves wrap and carry.

Each append helper accepts only type 3, zero E114 and E113 below 50(hex). Classification uses Y's low byte: part 0 subtracts 8 from Y; part 10 adds 8 to X and 5 to Y; other tested part 20 subtracts 8 from X and adds 8 to Y. Byte arithmetic wraps. Accepted parts increment byte 02 and advance X by four. Final merged preparation returns M16 with X at `(actoroffset>>1) OR C060` and carry indicating a nonzero word count.

Tests cover all raw type/direction/orientation/duration bytes, all 64 combinations of the three low type values, guard/count boundaries, twelve actor slots, three part offsets and position/height/pointer boundaries. Full WRAM outside 129 stack bytes, unchanged static peripherals and CPU agree at D0/DB7E/X16 with binary arithmetic. Direct direction entry requires M8; other entries accept both M widths. This prepares software lists; the forwarding consumer is checked separately below.

## Complete list duplication and mirrored coordinate preparation

C2AB54 (85 bytes) and C2ABA9 (33 bytes) independently assemble as 118 contiguous bytes. The copier reads byte count 02 as a zero-extended word and transfers each four-byte record through two ordered word reads/stores, advancing X/Y by four. Source/destination overlap and 7E/7F bank crossing preserve that order. Zero count underflows the word counter and copies 65,536 records, with index wrap.

The duplicator starts the destination at actor offset shifted right once, saves its initial source, and calls the original copier twice. It restores the source between passes, so the positive-count result contains two copies. It doubles only byte 02, then transforms the first copy's X/Y bytes. Positive values 71..7F(hex) clamp to 70; bytes 80..FF keep their raw values. Each coordinate becomes `~((value+0F)&FF) & FF`, and attribute byte +3 XORs C0. The second copy remains untransformed. Final X/A is the original destination OR C000; returned Y is the second copier's advanced source.

Word count zero performs two 65,536-record copies but only 256 byte-count mirror iterations. Native stack return addresses and changing counter pushes can be read as source data; the model reconstructs those writes before copying. It does not replace these cases with an empty list.

`map_actor_mirrored_sprites.py` passes 10,235 complete original calls: all 256 coordinate bytes across 32 opposite-coordinate/attribute/width contexts; every positive byte count in four source contexts for both copier and duplicator; two zero-count helper calls and one zero-count duplicate. Full WRAM outside 129 native frame bytes, copied stack residues, unchanged peripherals and final CPU agree. Scope is D0/DB7E/X16, binary arithmetic, both incoming M widths and prepared actor offsets/source memory.

## Complete alternate-body selection and effect forwarding

C0E6CF (145 bytes), C0E88A (60 bytes) and C0E8C6 (17 bytes) close the 777-byte contiguous range C0E5CE..C0E8D6 with the existing body/shadow sources. `map_actor_alternate_sprites.py` passes 20,481 complete calls: 8,192 alternate-body cases, 8,192 effect forwarders, 4,096 epilogues and one directed full zero-count mirrored caller. Every original helper executes; no callee is bypassed.

Input sprite code 5 selects the actor's E0D0 list with count from E116 low nibble. Its height expression includes 60(hex), preserving carry and the absence of a presumed SEC before the final position addition. Other codes copy and mirror that list. Counts >=6 clamp to 5 and move the source to E0D0+(original low nibble-5)*4; smaller counts retain their raw value and E0D0 source. Coordinate origin can come from the actor selected by word E10C when actor+28 bits30 equal30. This path retains the comparison carry through its coordinate arithmetic, rather than normalizing it away.

C0E88A forwards parts at actor offsets 0/10/20 through C19106, emits each list only when carry is set, then prepares and conditionally emits the merged C19017 list. The shared C0E8C6 epilogue reloads actor offset 14. Slots >=0600 with negative byte5C return; other paths run the complete ordinary body preparer/emitter.

Tests compare full WRAM outside 129 stack bytes, unchanged static peripherals and final CPU across selector/type/flag bytes, valid actor/retarget/list addresses, count/position/height/carry/capacity boundaries and widths. Alternate entry requires M8; forwarding/epilogue accept both widths, at D0/DB7E/X16 and binary arithmetic. The zero-count full caller preserves native frame bytes in its copied workspace. Outer C0E40E actor updates, boss emission, full main-frame scheduling, live interrupts, rendering and timing remain open.


## Complete three-record auxiliary actor sprites

C2C3C1..C2C525 independently assembles as a contiguous 357-byte component: 36-byte three-record entry, 160-byte worker, 68-byte animation helper and 93-byte camera-position helper. C0E324 adds a four-byte long wrapper around the existing packed-list emitter. `map_actor_auxiliary_sprites.py` passes 37,888 complete original calls: 8,192 position cases, 8,192 animation cases, 16,384 workers, 4,096 triple entries and 1,024 long wrappers. No callee is bypassed.

The entry preserves X and processes three 16-byte records beginning at D000+(actoroffset>>3), in order. Type zero and types with any bit F8 set return without emission. Type 2 produces two pieces; other accepted types 1/3..7 produce one. Types >=3 with byte +7 zero animate their tile only when F4 low two bits are zero. The four animation phases `(F4>>2)&3` mask tile/attributes with 3FFC, then select: base, base+2 with 8000, base with 4000, or base+2. Original carry and return-width differences remain observable.

Record byte +1 bit7 selects primary or secondary camera origins. Position subtracts that origin; an unsigned borrow permits adding primary extent C0/C2 once. The corrected coordinate is stored only when below 384 horizontally or320 vertically. Otherwise the original subtraction result remains. The helper returns M16 with its actual arithmetic/compare flags, preserving X/Y.

A one-piece record uses its own packed coordinates and tile at D00C+Y. Type 2 copies those words to the workspace at `(Y&03C0) OR D038`, preserving ordered writes. Byte +1 low two bits select the second piece's displacement and attribute flip: down (+16 Y, XOR80), up (-16 Y, XOR80), right (+16 X, XOR40), or left (-16 X, XOR40). Coordinate changes are byte operations with wrap. Both paths execute C0E324 and the complete original C0E640 emitter.

Tests cover all raw type/flag/tile-low bytes, all512 combinations of three low type values, phase/extent/position/capacity/count contexts, twelve actor slots and both incoming M widths. Full WRAM outside129 stack bytes, unchanged static peripherals and final CPU agree. Scope: D0/DB7E/X16, binary arithmetic, valid record/workspace indices; direct animation requires M8. Rendering and outer actor/boss scheduling remain separate.

## Complete actor screen update and sprite-list selection

C0E40E..C0E4C0 (179 bytes) updates actor screen coordinates and transient sprite state; C0E4C1..C0E5CD (269 bytes) selects and emits its lists. With earlier ordinary/alternate/effect/shadow sources, C0E40E..C0E8D6 now independently builds as one contiguous1,225-byte component. Interior entry C0E5F5 is directly tested as a75-byte body-preparation tail within the existing C0E5CE source; those bytes are not counted again.

Actor+0B bit7 selects primary A8/AA or secondary AC/AE camera origins. World +02/+04 subtract those origins into +20/+22. Borrow correction adds primary extents C0/C2 once, accepting corrected coordinates only below384/320. The update then advances nonzero actor+0F through the original visibility timer and returns early when carry reports the timer's retained suppression condition.

Negative actor+0E suppresses further processing. Low bits1/2 use actor+39 as a decay counter: decrementing to zero clears the low nibble of +0E; otherwise even F4 frames XOR the coordinate low bytes with masks derived from +0E bits0/1. Odd frames retain coordinates. The original status/shift/carry flags and byte wrap are preserved. Nonzero actor+61 calls all three auxiliary records unless ED bit6 suppresses that call.

The list selector starts with actor+84 low nibble as byte count02. Zero, ED guards and slot/eligibility guards route through the existing epilogue. Actor+60 selects major paths: E0 forwards all three effects and their merge;20 emits ordinary/effect lists in the order selected by actor+24 sign;40/80 emit offset effect coordinates; other values inspect blink status, effect type/flags and actor+28. Type>=5 with E114 bit6 selects the complete alternate/mirrored path. Actor+28 bits20/10 can select another actor's coordinate origin through E10C; otherwise fixed effect coordinates are centered by adding128/112.

Both ordinary/effect orderings preserve the original C0E5F5 tail, which recomputes height and jitter while retaining the supplied list pointer and count. This is not replaced with a simple list emission. All paths retain their exact count widths, partial OAM writes, capacity residue, return modes and carry-sensitive height calculations.

`map_actor_sprite_update.py` passes68,937 complete calls:32,768 selectors,32,768 full updates,1,352 paired camera-boundary updates,2,048 direct body-tail contexts andone full zero-count mirror after active auxiliary emission. Every original timer, auxiliary worker, effect/mirror/body helper executes without hooks. Full WRAM outside129 call-frame bytes, unchanged static peripherals and final CPU agree at D0/DB7E/X16, binary arithmetic, prepared valid actor/target/list memory. Update/selector accept both M widths; direct tail requires M16. Generic mirrored contexts use positive counts; the directed zero case retains the original large copy.

The zero-count caller can copy previously returned auxiliary frames into its sprite workspace. Its model therefore reproduces those PHX/PHA, helper return addresses and long-call bank bytes before the later copy, in addition to the copier's own changing counter pushes. This tests persistent effects of the original stack without masking copied sprite data. Outer C0E3CF/C0E38E sorted-list and boss dispatch, live interrupts, rendered sprites and timing remain open.

## Complete boss piece lists and software OAM

C21F80..C221B2 contains a complete 563-byte boss piece-list renderer and eight helpers. C221B3 adds four regenerated two-bit clearing masks; D97F2D..D97F34 adds eight regenerated horizontal-high-bit/size masks shared by the packed OAM writers. The first range plus its clearing table assembles as one contiguous 567-byte component. `map_boss_sprites.py` passes 28,672 complete original calls without bypassing any callee:

| Entry | Behaviour | Calls |
|---|---|---:|
| C21F80 | Complete boss piece-list consumer | 2,048 |
| C21FB5 | Reverse piece traversal and height adjustment | 2,048 |
| C22005 | Camera-relative boss position | 4,096 |
| C2206D / C22081 | Normal / background piece emission | 2,048 each |
| C22095 / C220C0 | Horizontal / vertical clipping | 4,096 each |
| C220ED / C22150 | Normal / background attributes and packed OAM | 4,096 each |

These routines use direct page 0200 and data bank 7E, unlike the ordinary actor emitter's direct page zero. Actor address is word 0287. The list header is at `F800 + ((actor-E600)>>2)`, giving a 128-byte workspace stride for each of the nine 512-byte boss actor records. The header is a byte count followed by four-byte pieces: signed X offset, signed Y offset, and a word containing tile and attributes. The consumer uses the last piece first. The tests include every byte count, all nine actor addresses and both priority paths; the direct reverse helper also tests positive count 256. The renderer returns after position preparation when its header count is zero.

C22005 copies actor+2B/+32 to actor+02/+04 and scratch 028F/0291. Low two bits of the **incoming** scratch 028D select no camera subtraction (zero) or one of three camera origin pairs (1..3). X subtracts its selected origin without a wrap correction. Y subtracts its origin; if unsigned `(extent-112)` is below that origin, it adds the selected vertical extent once. Actor+98 bit20 suppresses the actor+22 store, while scratch Y still updates. Actor+45 receives the low byte of `actor+66>>1`. The renderer refreshes 028D from actor+98 only after this helper and only for a nonempty list; this ordering is preserved.

C21FB5 adjusts scratch Y by `~(actor+66>>1)`, equivalent to subtracting the halved height and one with word wrap. Actor+70 bit08 chooses the background attribute writer. The current output slot is word 0295; accepted pieces increment it and word 0266. Rejected pieces decrement word 0285, which began as the original count. Each attempt moves the source back four bytes, then compares accepted count with the shrinking target. Thus every original piece is considered, while only accepted pieces consume output slots. The renderer advances its global slot word 027F by the remaining count. It contains no output-capacity guard.

Horizontal clipping adds the signed byte offset to scratch X and implements its original signed-branch arithmetic, normally accepting coordinates -32..255. It writes a **word** at 0800+slot*4, then saves the coordinate in 0299. Vertical clipping similarly accepts -32..223. Its word store at 0801+slot*4 overlaps the low tile byte. A vertical rejection still writes word 00E0 there and shrinks the count; a horizontal rejection performs no OAM coordinate store. These partial writes, word wrap and malformed-coordinate branch behaviour are compared rather than replaced by idealized bounds checks.

The normal attribute writer ORs tile/attributes with 2000; the background writer clears that bit with DFFF. Both retain the original attribute word in 029B. They clear the slot's two bits in the high OAM table at 0A00, set the horizontal high bit from the saved X coordinate's high byte, then set the size bit from original attribute bit2000. Clearing priority in the background writer therefore does not clear sprite size. The packing code narrows both accumulator and indexes to bytes, retaining the accumulator high byte, and restores word widths on return. Its final X/Y and flags remain observable outputs.

`map_boss_sprite_publication.py` adds 512 continuous sequences and 5,120 original calls: nine boss list consumers followed by the complete native C0C0A8 NMI body through RTI. Full WRAM outside 129 call-frame bytes, all static peripheral state and the full CPU are checked after every call. The resulting **544 bytes** of software OAM match hardware OAM exactly after the original transfer. Tests preserve random initial OAM, all four packing phases, camera layers, both priority variants and mixed visible/clipped pieces. EC8 suppresses the other upload families. Actor selection and the interrupt frame are supplied explicitly; this does not establish the outer boss control/animation dispatcher, full sorted actor emission, vector delivery, rendered output or timing.

## Boss camera alignment and vertical integration

C2102B (129 bytes) and C21226 (53 bytes) now have readable models in `map_boss_motion.py` and independently matching sources. The direct test runs 73,728 original calls: 8,192 complete camera calls with the real C22005 position helper, and 65,536 vertical integrations. No callee is bypassed. Camera cases cover all flag bytes, signed clamp/extent boundaries, several values of the direct-page XOR word and all nine source/final actor selections. Height cases cover every low position word with directed high position, velocity and acceleration values. Full WRAM outside 129 call-frame bytes, static peripherals and returned CPU agree at D0200/DB7E/M16/X16 with binary arithmetic.

The camera helper starts with the incoming X actor and saves actor+2B to 0FB0. Word 0FB2 becomes `actor+32 + ((actor+66>>1) XOR word02C7) + 1`, with word wrap. The XOR operand is at **02C7**, because direct page is 0200; assuming an unconditional negation would lose its actual parameter. It then chooses the scroll pair B0/B2 when scratch028D bit04 is set, or B4/B6 when it is clear. Horizontal scroll is the word negation of `0FB0 + 0FB4 - primary_origin_A8`, also stored in 0FBE before any limit is applied.

Only the B4/B6 branch checks the original signed arithmetic after adding 272 and subtracting 416. In its ordinary signed domain it retains -272..143; other values force horizontal scroll to FEF0 (-272). Word 0FBE still retains the unbounded result. This is a scroll-plane limit, not the sprite clipping rule. The model preserves the actual branches for word-wrap boundary inputs.

For vertical scroll, scratch0295 begins at primary Y origin AA. If unsigned `(C2-224)` is below AA, it instead becomes `AA-C2`. Word 0FBC becomes `0FB2 + 0FB6 - scratch0295`; its word negation goes to the selected vertical scroll field. Finally X reloads from scratch0287 and the real C22005 helper prepares screen coordinates. The incoming actor used for alignment and this final selected actor can therefore differ; direct tests retain that distinction.

C21226 adds actor velocity +C4/+C6 to position +64/+66 as two words, carrying the low addition into the high addition. If the resulting high word is negative, it zeros **all four** position/velocity words. It then adds acceleration 0FC0/0FC2 to the current velocity, again carrying between words. A landing can consequently finish with nonzero velocity from the newly applied acceleration; the routine does not return immediately after resetting the four fields. Final A/flags come from the high velocity addition, while X/Y remain unchanged.

`map_boss_motion_sequences.py` adds 256 persistent 16-step sequences: 4,096 steps and 16,384 complete original calls through vertical integration, camera alignment, boss piece emission and the native NMI/RTI transfer. Numerical position and velocity persist between steps. Full WRAM, all static peripherals and the full CPU are compared after every call; each step also checks all 544 published OAM bytes. Tests include all flag bytes, both priority variants, nine actor addresses, four packing phases and mixed signed/fractional/landing/extent cases. Actor/slot selection and the interrupt frame are supplied explicitly, with EC8 suppressing unrelated uploads. The outer boss animation/command dispatcher, complete sorted frame, vector delivery, rendered output and timing remain open.

## Complete boss palette command consumer

C210AC..C211F3 now has a readable complete command consumer/dispatcher and five handlers, adding **328 matching instruction bytes** in nine sources. Together with the existing C2102B camera helper it assembles as a contiguous 457-byte component. The existing 51-byte C226F9 palette copier is reused without another byte credit. Its interior C22700 entry is now catalogued and directly tested, with `source_parent_entry=C226F9`.

`map_boss_palette_commands.py` passes 23,680 complete original calls: 4,096 consumers, 4,096 dispatchers, 4,096 seven-color copies, 4,096 direct reloads, 4,096 cached reloads, 1,920 color rotations and 1,280 direct group handlers. Every original callee executes without bypass hooks. Tests cover all command bytes, all byte copy parameters and palette identities, all 120 ascending color intervals across sixteen slots, nine actors, early/complete palette groups and primary/secondary ordering. Full WRAM outside 129 call-frame bytes, all static peripherals and final CPU agree at D0200/DB7E/X16 with binary arithmetic. The reload entry is checked at M16; the other direct commands are checked at M8; consumer and cached reload accept both incoming M widths. Palette group indices are prepared within 0..15; zero ends a group.

The consumer checks actor+100 before reading any secondary command. If it is zero, it returns M16 without processing actor+102. Otherwise it dispatches nonzero actor+102 first, packing its parameter +103 in A's high byte and setting Y to actor+2. It then **rereads** actor+100 and its parameter +101, so a secondary handler can alter the primary command used in that same call. Primary Y is the current X actor. Group handlers walk up to four consecutive palette slot bytes from actor+18, stopping at zero or when X's low two bits roll over. Saved Y identifies which command byte to clear/update; it is pulled into X, not restored to Y. Actual Y residues from palette helpers therefore remain visible.

| Command | Result |
|---|---|
| 80 | Reload each slot from its cached identity at 033F+slot, then clear the selected command byte |
| B0 | Copy seven colors from the parameter-selected C8 source to each slot, then clear the selected command byte |
| B4 | Rotate the parameter-selected color interval in every slot; retain the command for subsequent updates |
| C0 | Reload every slot with palette identity 1, then change the selected command byte to C1 |
| C1 | Write 80 to the primary command at actor+100, regardless of secondary Y |
| Other bytes | Return from dispatch without a palette change or command-byte clear |

B0's helper preserves color zero and copies seven words into 0602+slot*32. It computes the source with the original shifts, SBC and ADC carry chain: parameter 1..255 selects C8:(1000+30*parameter), while parameter zero selects **C8:0FFF**, not 1000. It writes only byte0278 for the source bank before constructing word0276. Stores remain ordered; neither a normalized pointer formula nor a presumed carry reset is substituted. The ordinary reload copies sixteen words through the original D0BB24 pointer lookup to 0600+(slot&15)*32, using fixed source bank C2 and native long-read bank carry. The cached entry stores the identity byte before taking that path.

The B4 parameter's high nibble is the first color and low nibble the last. For first<last, the last word is saved in scratch0295, preceding words shift upward in descending address order, then the saved word replaces the first. Transparent color zero is included when the interval begins there; the original routine does not skip it. Group handlers preserve their palette-index cursor through each rotate/copy call, but not the resulting Y or accumulator high byte. C0/C1/80 normally advance through three updates to a cleared command; an active secondary command can change that progression.

`map_boss_palette_wrapped_intervals.py` also executes **all 136 equal/reversed nibble intervals** through C21187's final RTS. Equal endpoints copy 32,768 words; reversed endpoints copy `32768-(first-last)` words, wrapping the sixteen-bit X/Y indices and carrying absolute-indexed WRAM reads/writes into bank7F. Across all cases this is 4,455,768 ordered word copies. The independent model matches the entire 128 KiB WRAM with **no stack exclusion**, all static peripherals and full CPU before and after RTS. These copies modify the supplied return address; the report records the observed changed targets. The original RTS is reproduced literally, without promising a return to the intended caller. This does not establish whether such parameters occur during gameplay or what the outer B4 caller subsequently executes after its saved stack values are changed.

`map_boss_palette_publication.py` adds 256 persistent three-step command/NMI sequences, 768 steps and 1,536 complete original calls. Every step compares full WRAM outside 129 native frame bytes, static peripherals and the full CPU, then checks all **512 CGRAM bytes** against the software palette with the original high-byte mask. EC4 requests only the palette upload from 0600; caller-supplied actor/interrupt/upload selection remains explicit. Commands and colors persist between steps. Outer boss animation, full sorted frame scheduling, vector delivery, rendering and timing remain open. No palette payload is saved.

## Boss contact with party actors and animation reset helpers

`map_boss_actor_contacts.py` adds six complete readable helpers and **294 matching instruction bytes**: C2125B (71), C212A2 (64), C212E2 (93), C21394 (25), C23182 (21) and C23766 (20). The three contact routines plus the existing C21226 height integrator assemble as one contiguous 281-byte component. All **40,960 original calls** pass without bypass hooks: 8,192 full party checks, 4,096 single-actor preparations, 16,384 contact-flag merges, and 4,096 each of animation reset, parent following and landing completion. Full WRAM outside 129 call-frame bytes, all static peripherals and returned CPU agree at D0200/DB7E/M16/X16 with binary arithmetic. The tests include all eight active-party combinations, word identity guards, all flag/shape/selector/direction bytes, signed/extent/height boundaries, all 256 animation low ids with sixteen high bytes, parent self-reference and positive/zero/negative landing cases.

C2125B accepts a boss only when actor+98 bit10 is set, its unsigned height word +66 is below 64, and word +1E is nonzero. It prepares center X from +2B and center Y from +32 plus +A5, preserving word wrap. Twice +1E indexes byte horizontal/vertical radii through D97F09/D97F0A. It then processes E000, E200 and E400 in order, finally reloads X from scratch0287 and clears carry. Guard exits also clear carry but retain their literal accumulator/index/flag residues.

C212A2 requires the hero's **word** at +00 to equal 1; a low byte of 1 with a nonzero high byte is rejected. It copies hero +02/+04 into scratch0256/025E, and word +06 into025A. Hero+89 low two bits plus one select the hero radii, zero-extended into0258/0260. A rejected hero leaves its flags untouched; the active path executes the complete C212E2 helper.

The merge clears scratch024A, then compares wrapped word absolute X/Y distances with unsigned sums of the corresponding radii. Equality is accepted. Negating 8000 retains 8000; the model preserves this original word boundary rather than using an unbounded signed absolute value. Only a two-axis overlap permits direction bits: X difference XOR **word0259** tests bit15 before adding mask1, while Y difference XOR word025A tests bit15 before adding mask2. Word0259 overlaps the zero high byte of radius0258 and the low direction byte at025A. This means horizontal direction uses bit7 of the hero's low +06 byte; vertical direction uses bit7 of its high +06 byte. The helper byte-ORs the mask into hero+29, preserving every existing bit even when there is no contact. It does not inflict damage or clear previous contact bits. Final X is the hero address; Y is preserved; return widths are word widths with the original byte-operation flag residues.

C21394 selects the supplied word animation id at actor+9A, sets timer word+9E to1 and script cursor word+9C to0, clears only byte+5A, then sets frame descriptor bank byte+A2 toCA. Adjacent bytes are preserved. Final A is00CA, with the byte-load N flag still set despite returning M16; incoming carry/overflow are unchanged. This seed/reset routine is complete, while the frame-script interpreter remains open.

C23182 is a real actor+90 callback target: the original setter at C2314B/C2314E loads3182 and stores it in that field. The reconstructed callback loads the parent address from child+B0 into Y, copies parent+2B to child+2B, and stores parent+32 plus parent+A5 into child+32 with the original word carry/overflow. X remains the child and Y the parent. The direct tests include a child referring to itself; they do not claim the whole surrounding boss state machine is decompiled.

C23766 reads word height+66. A positive height returns carry clear without writes. Zero or a negative word clears +64, +66 and callback word+90, then returns carry set. A and N/Z still describe the originally loaded height, since the zero stores do not alter them. This completion test is distinct from the C21226 velocity/acceleration integration.

The wider C211F4 actor+90 dispatcher has several boss-specific callback targets, not just the common frame animation helper C213AD. Static inspection also identifies a script-supplied callback assignment at C2382F..C23838, so a list of immediate pointer setters alone cannot establish every target. These findings guide the remaining callback/animation VM audit. Full C211F4/C20F91/C2133F dispatch, frame geometry/cache consumers, full sorted actor emission, live gameplay reachability, interrupt delivery, rendering and timing remain open. No ROM or geometry payload is saved.

## Boss state operands, orientation and spell targets

`boss_state_fields.py` reconstructs 18 complete original entrypoints: seventeen state operand/orientation commands and the C2396D spell-target helper. They add **448 matching instruction bytes**. The 22-entry C237CC..C237F7 command pointer table adds 44 regenerated numeric bytes; unknown native/spawn/combat/audio handlers remain explicitly named as unrecovered targets. The table and C237F8..C238CA direct commands assemble as a contiguous 255-byte component. This does not imply the complete C2377A/C237C7 interpreter or its remaining handlers are modelled.

All **100,352 original calls** pass without bypass hooks: seventeen entries each have 2,048 cases, and spell targeting covers every one of the 65,536 parameter words. Tests compare full WRAM outside 129 native frame bytes, unchanged static peripherals and returned CPU at D0200/DB7E/M16/X16 with binary arithmetic. Generated scripts use WRAM banks7E/7F, long effective-address bank carry, low-bank mirrors/zero unmapped reads and sixteen-bit Y wrap. The real C21394 animation-reset callee executes. Raw script operands remain volatile.

| Opcode / entry | Reconstructed operation |
|---|---|
| 00 / C237F8 | Read a word animation id, advance Y by2 and run the original animation reset |
| 01 / C23802 | Write six consecutive words to actor+3A/+3C/+3E/+40/+C4/+C6, advancing Y by12 |
| 02 / C2382F | Assign word actor+90 from the script; this is a data-driven motion callback |
| 03..05 / C23839/C23843/C2384D | Set word fields +48/+4A/+14 |
| 06..0B / C23857..C238A4 | Set, toggle or clear orientation bits40/80 in word+98 |
| 0C..0D / C238A5/C238AF | Set word+1E3 and word+A7 |
| 0E / C238B9 | Prepare spell targets and set word+80 to1; preserve the advanced script cursor across the helper |
| 11 / C23922 | Read an actor-relative offset and a value, then store the value through wrapped word pointer0233 |
| 15 / C2395C | Replace script pointer word0230 and set Y to word02C5; preserve pointer bank0232 |

Every actor-selecting handler reloads X from scratch0287. Word operands are read from `bank0232:pointer0230 + Y` with full long-address carry; only Y's subsequent increments wrap to sixteen bits. Reads and stores retain their original order. The relative store can write wordFFFF across the WRAM bank boundary; it does not truncate the second byte to the start of bank7E. The jump uses direct-page C5 at **02C5**, not global00C5. The forced orientation handlers mask then OR their bit, even though the final bit value could be described more simply; their CPU flags and operand-free cursor behaviour are preserved.

C2396D saves the word parameter in0295, writes its low byte to actor+170, and clears only bytes+177..+17A. Bit0100 selects multiple targets; bit0200 selects the boss side. Single-party targeting writes count1 and byte `(actor+A9)+1`, using byte INC so carry is retained. Single-boss targeting writes count1 and byte `scratch028B+4`, using CLC/ADC so byte overflow changes carry. Higher parameter bits do not change this selection, but can remain observable in accumulator-high-byte residues.

Multiple-party mode scans E000/E200/E400; multiple-boss mode scans **only E600/E800/EA00**, despite the boss pool having nine slots. Eligibility is low identity byte+00 equal to1 and sign bit8000 of word+190 clear. A nonzero identity high byte is allowed here, unlike the whole-word identity guard in the boss contact helper. Eligible target identifiers are1..3 for party or4..6 for bosses, compacted into actor+178 onward. Count is written to byte+176. No-eligible cases still clear the four target-buffer bytes and write count0. Byte+17B and other neighbouring fields are preserved. This prepares a spell request; it does not execute the spell or prove its gameplay effect.

The C238B9 wrapper advances Y by2, saves it across the real target helper, then writes word+80=1 and restores Y with word-index flags. Direct helper cases cover all 65,536 parameter words, activity/high-identity/health-sign combinations, target-index byte wrap and incoming carry/overflow. Orientation and all ordinary field commands cover every low operand/flag byte with bank/index/width contracts stated above.

The source pointer table preserves all 22 original destinations. The companion projectile model below now covers opcode 0F at C238CB. The remaining dependencies are other native destinations called by opcode 10 at C2390F. Opcode 13 attack-row preparation is verified below. The Mantis launch/native call protocol and opcode 14 CPU sound request are now verified below within their stated domains. Opcode dispatch itself does not validate an arbitrary byte against this table's size; undefined-index control flow remains a separate audit. The next work is to reconstruct these real dependencies and run complete original state-loader/script chains before claiming the VM or the boss callback target inventory complete.

### Boss/projectile graphics list loader C22476

`tools/boss_projectile_graphics.py` reconstructs the complete 77-byte loader with its real C224F1 expansion dependency. The incoming word identity indexes a byte at D0BAC0; the loader multiplies that selector by four, walks byte resource identifiers at D0BADF until FF, and obtains each source low pointer from D0BB0C + 2*resource. It sets source bank DB, destination bank 7F and expands 1024 bytes into 7000 + 1024*(listcursor & 3), clearing both history words before each resource. The expander performs overlapping word writes; its final lookahead byte is retained. Empty lists leave initial Y/V intact. Nonempty lists leave Y equal to the last byte-history value, and the terminating comparison leaves A=00FF, C=1, N=0, Z=1. No DMA or hardware upload occurs in this entry.

496 complete original calls without hooks cover identities 0..30 (the 31 adjacent selector bytes before D0BADF), each with all 16 initial C/N/Z/V combinations and randomized 128 KiB WRAM/X/Y. Full WRAM outside 129 native stack bytes, static peripherals and final CPU agree. Real lists contain 0..3 resources; repeated quadrant writes preserve native order. The model does not mask the incoming word identity: selectors outside the tested 0..30 domain, the enclosing projectile creator, rendering and live frame scheduling remain unverified. No original compressed or expanded graphics are saved. See `data/boss_projectile_graphics.json` for counts and dependency hashes.

### Complete boss projectile creation C233BE and state opcode 0F

`tools/boss_projectiles.py` reconstructs the 122-byte C233BE creator and its 68-byte C238CB state operand wrapper, including the real C20D53 allocator, C22476 graphics loader/C224F1 history expansion and C22700 palette copier. The creator adds word offsets to the parent coordinates, then subtracts the parent's unsigned height divided by two from Y. It saves the parent address and maps the target word's low two bits to E000/E200/E400/E600; it also preserves the entire original target word. Flags are `(parent+98 & 3) | AA20`, so allocation scans only slots 3..8. On success it writes position, parent B0, target address B2, projectile identity B4 and original target word B8. DCE683 supplies the allocator definition pointer. DCE6C1 supplies both field B6 and the palette identity copied into software palette slot 15. These are numeric metadata tables, not saved graphics assets.

Allocation failure leaves the already prepared scratch fields and allocator scratch intact, but does not write projectile fields or load graphics/palette. The parent may occupy the slot that gets allocated: coordinate calculations precede initialization, and the model preserves that order. The state wrapper consumes three byte operands (identity, signed X offset, signed Y offset), mirrors the sign-extended word X offset when parent flag 0040 is set, and restores the advanced script Y and DP87 actor X after the complete creator returns. In particular, mirroring byte 80 yields positive word 0080. Target selection reads the full parent+A9 word.

The native comparison report covers all 31 tested identities with every one of the 64 occupancy masks for the six eligible slots (1984 complete creator calls), plus 496 selector/context and 512 signed-byte/mirror wrapper calls. Full randomized 128 KiB WRAM outside 129 native stack bytes, static peripherals and final CPU agree. Wrapper cases include WRAM script banks 7E/7F, 16-bit cursor wrap and long bank carry. This closes creation and opcode 0F in the tested identity domain, not subsequent projectile motion/collision, the full state VM, other commands or live frame execution. See `data/boss_projectiles.json`; no original script, palette or graphics payload is saved.

### Mantis Ant native launch and state opcode 10 call protocol

`tools/boss_native_projectile.py` reconstructs C23E7F (87 bytes), opcode 10 at C2390F (14 bytes) and its indirect jump helper C2391D (5 bytes). This adds an original-execution comparison to Claude's Mantis Ant launch description in `docs/mantis-ant.md`. The launch saves parent coordinates, the full target word at parent+A9 and parent address. The word direction at parent+AB is multiplied by four with native 16-bit wrap, indexing signed XY velocity pairs at DCE028. It allocates an object with definition pointer 3ED6 and flags 2801, scanning slots 3..8. A successful object receives coordinates (parent X - 12, parent Y + 4), velocity words 3C/40, target A9 and parent B0. Both success and failure restore X from DP87, which need not equal the incoming parent. Later motion, animation and collision in C23ED6 are not executed by this launch.

Opcode 10 loads the actor from DP87, consumes a word callback pointer, saves the advanced script Y, calls the indirect helper, then restores Y and actor X. The helper stores the pointer in DP33 and jumps through absolute 0233 in program bank C2; the target returns through the helper's existing call frame. Its model currently implements the actual Mantis destination C23E7F and explicitly rejects unmodelled targets. This verifies the calling protocol with a real allocating callback, not the complete native target inventory.

3,072 complete original calls without bypass hooks pass: 2,048 direct launches (eight directions, four aliases introduced by high-word shift wrap and all 64 eligible-slot masks), 512 indirect helper calls and 512 opcode calls. Full randomized 128 KiB WRAM outside 129 native stack bytes, static peripherals and final CPU agree, including coordinate boundaries, target word preservation, failures, parent/allocated-slot alias and DP87 restoration. Script words are read from banks 7E/7F with cursor wrap and long bank carry. The initial eight XY velocity pairs contribute 32 independently assembled numeric bytes; no graphical or script payload is saved. See `data/boss_native_projectile.json`. Other native targets, the combat dependency, full state VM and live frame scheduling remain open; actor and sound commands are verified below.

### Boss sound request and non-music CPU sender

`tools/boss_sound_requests.py` reconstructs C230E3 (26 bytes), C230FD (13 bytes), state opcode 14 at C2394F (13 bytes), public audio jump C30004 (3 bytes), C30160 save/dispatch/restore (56 bytes) and C3059F packet sender (64 bytes). C230E3 always requests command 02, uses only the low byte of the sound operand and copies the incoming X word into parameter bytes 1E02/1E03. The state command consumes a word, advances script Y by two, supplies X=000F and restores actor X from DP87. C230FD instead submits the low byte of A as the command.

The sender clears byte 1E00 before dispatch. Command zero sends nothing. Commands 02..6F and 80..FF send, in order, parameter bytes to 2143, 2142 and 2141, the command to 2140, then zero to 2140 after acknowledgement. F0/F1 additionally preserve the previous nonnegative cached command and parameter word into 1E09/1E0A, then set 1E05=FF. A/X/Y, D/DB and incoming register widths are restored. C/V are preserved, while final N/Z come from the restored DB byte because PLD/PLB execute after PLP; at the tested DB=7E they are both zero. Music command 01 and indirect command selectors 70..7F branch into other, unmodelled driver paths. The source block describes the dispatcher, not a model of those music paths.

15,840 complete original calls without instruction bypass hooks pass: 3,824 public sender calls, 3,824 generic requests, 4,096 boss parameter requests and 4,096 state commands. All 256 low sound bytes and all 239 non-music command bytes are tested in 16 contexts, including high-byte samples, all incoming C/N/Z/V combinations, randomized 128 KiB WRAM/X, cache boundary values, script banks 7E/7F, word cursor wrap and long bank carry. Full WRAM outside 129 native stack bytes, unchanged static peripherals, ordered port writes and final CPU agree.

APU port acknowledgements are supplied at an explicit input boundary, with delays of 0/1/3/7 reads and an initial port byte different from the outgoing command. This verifies the original CPU handshake and state changes; it does not verify SPC instructions, playback, waveforms, console timing or indefinite busy-port behavior. The existing `boot_audio.py` separately executes the original SPC driver after boot upload; this new comparison does not replace that evidence. See `data/boss_sound_requests.json`. The combat command, other native callbacks, full state VM and live scheduling remain open; external actor commands are verified below. No audio payload is saved.

### Complete external actor commands and boss opcode 12

`tools/actor_external_commands.py` reconstructs the public C18003 jump, C1CB12 context wrapper, the entire contiguous C1D5CB..C1D941 command/parameter/palette block and boss C23934/C23963. The existing 61-byte C1859B weapon palette copier executes as a real dependency and contributes no new source bytes. The external API takes a word with low-byte parameter and high-byte command. It saves P/D/DB, switches to direct page zero and data bank 7E, dispatches, then restores the caller's P/D/DB. X is the actor offset relative to E000. Returned A/Y reflect the literal selected path.

The low dispatcher implements actor visibility/status flags, global state 49, weapon palette reload, motion templates from WRAM C700 and fields 36/37. Command 80 restores fifteen cached colours from DF00 plus the actor's palette offset, or stores a deferred actor command when 5C has its high bit set and X is at least 0600. Command 8D prepares a C0 weapon palette interval through the high dispatcher. Motion templates use byte 80 as an unchanged-field sentinel, retain facing and direction-bit transforms, and are read from WRAM rather than assumed ROM assets.

The high dispatcher handles deferred/immediate actor palette reloads and colour intervals, global screen requests, encoded motion values, and child actor positioning. C0..C7 prepare weapon palette fields and copy five colours; C8..CF prepare ordinary palette fields and copy fifteen colours unless deferred. D0 decodes two signed-magnitude nibbles, normalizes encoded negative zero and applies actor facing to X. D1/D2 encode an incoming signed byte, D3 stores field 08, and D4 conditionally moves the child indexed by actor+5E when its status byte is 00 or 40. Unhandled commands retain the original no-op paths. These operations preserve native byte overflow and write order.

The C1D6DC script entry reads a byte parameter at script pointer + 1, advances only the pointer's low word by two, then enters the high dispatcher. C1D8F3 clears the actor's word 100 and copies fifteen cached colour words. C1D90D multiplies the parameter by 30 through the original CPU hardware registers, copies fifteen C8:1000 palette words to software palette memory and retains scratch/cursor results. Indexed accesses carry into bank 7F and Y wraps as a word. Neither helper itself publishes colours to CGRAM.

The boss helper reads selected actor X from absolute 0362. A negative selection skips the external call. Opcode 12 reads a word operand, advances and saves script Y, calls the original 01:8003 ROM mirror, then restores Y and actor X from DP87. The validation checks all 65,536 public command/parameter words and all 65,536 words through this complete boss chain, alongside direct byte-dispatch, parameter-reader, palette-helper and negative-selection cases. The report compares full randomized 128 KiB WRAM outside 129 native stack bytes, all static peripherals including multiplication state and final CPU, without instruction bypass hooks. Public entry contexts include both accumulator widths, D=0000/0200 and DB=00/7E/7F; private entries use their native zero direct page, and boss entries use D=0200/DB=7E.

See `data/actor_external_commands.json` for exact counts and dependency hashes. Live palette publication, hardware timing, arbitrary actor offsets/stack frames, other native boss targets, the combat command dependency and the full state VM remain open. No original palette or script payload is saved.


A separate `tools/actor_external_command_edges.py` audit adds 16,384 complete native calls, varying all 256 commands across eight parameter boundaries, both facing bits, both deferred modes and hero/boss actor offsets independently. This includes the D2 negative-zero branch and palette interval boundaries. Together `data/actor_external_commands.json` and `data/actor_external_command_edges.json` record 169,216 passing calls.

Source recovery uses observed immediate-width states from equivalent low-bank ROM mirrors when generating canonical C0..DF source addresses. C1CB12 actually calls 01:D5CB/01:D6EF; those immutable ROM aliases contain the same physical bytes. This supplies width evidence without inventing canonical executed PCs or changing recorded execution coverage. Branches missing from either alias still require an actual original trace; the independent edge audit supplies those traces here.


### Complete boss attack-row preparation and state opcode 13

`tools/boss_attack_commands.py` reconstructs the public C0006C and secondary C03854 jumps, the sixteen-byte C045D6 context/row prefix and the fifteen-byte C23940 operand handler. The 105-byte C045E6 continuation and all classification, base-attribute, pointer, clamp, bit-pair and cap helpers already have matching sources. This closes the real dependency with those original callees executing, rather than bypassing it. Claude's earlier `validate_boss_attacks.py` checked the five attack-table output fields for the 115 documented rows; the new proof checks the entire randomized memory, static peripherals and final CPU.

The loader takes only the low byte of the row operand, saves P/D/DB and normalizes actor X with mask 1FFF. It sets direct page 0300 and data bank 7E, writes the row to actor+1E3/+1E8, reclassifies the sprite and rebuilds its base attributes. This path always proceeds through table preparation even for classifications which make the ordinary appearance refresh return early. It prepares armor pointers and any classification-dependent weapon pointer, clamps base stats, reorders resistance bits and sets actor+1AB bits12. The seven-byte attack row supplies flags, accuracy, power, status and status chance; attack power is the native byte sum of row power and clamped strength. Charge stage and level both receive the entire actor+1C0 byte, not a decoded nibble. Numeric word/byte defensive fields are then capped.

Final A is 0363, and X/Y are the normalized actor offset. P/D/DB are restored; C/V and register widths come from saved P, while N/Z come from the final PLD and therefore describe the incoming direct-page word. The final multiplication registers retain row times seven. Opcode 13 consumes a word with full long-address carry, saves its advanced Y, selects actor X from DP87, invokes the real loader and restores Y and DP87 X. Its final N/Z consequently describe restored actor X.

The new report covers 16,384 complete native calls: 4,096 each through the public jump, secondary jump, direct loader and opcode. It spans all 256 row and sprite bytes, twelve aligned actor offsets and full-address aliases, both incoming accumulator widths, four D/DB contexts, all initial C/N/Z/V combinations, classification/palette choices and script-bank/cursor boundaries. Full 128 KiB randomized WRAM outside 129 native stack bytes, unchanged peripherals except explicitly modelled multiplication, CPU and S/D/DB agree without hooks. Byte row selectors beyond the 115 documented records are tested as literal ROM reads, without asserting that gameplay uses them. See `data/boss_attack_commands.json`. This prepares attack attributes; it does not execute damage or collisions. Remaining native callback targets, complete state VM composition, arbitrary actor offsets and live timing remain open. No original attack/script payload is saved.


### Boss native reciprocal contact marker C23CAB

`tools/boss_native_contacts.py` reconstructs the 61-byte C23CAB callback and extends the native-call model with its actual target, keeping the previously recovered Mantis launch. The callback transforms the full actor+A9 word with XBA, a word shift and E000 addition to obtain a target address. It transforms the incoming boss offset relative to E600 into an index, reads a byte at C205F0+index and ORs it into target+59. It then transforms the target relative to E000, reads the corresponding lookup byte and ORs it into selected actor+5A. The selected actor comes from DP87, which may differ from the incoming actor. Stores and DP87 reloads retain their original order.

The lookup is not a computed `1 << index`: the first eight bytes are 01/02/04/08/10/20/40/80, while index eight reads the following A5 instruction byte. The native code neither bounds that index nor masks the target operand's high byte. The model preserves these literal reads, word wrapping, XBA low-byte flags, bank-carry writes and any overlap with scratch. This evidence alone does not establish gameplay use of out-of-table indices or a defect. The callback marks relationships; it does not perform collision geometry or apply damage.

12,288 complete original calls pass without hooks: 4,096 direct callbacks, 4,096 indirect C2391D calls and 4,096 C2390F opcode chains. All 256 low target bytes, high-byte samples 00/01/7F/80/FF, all nine aligned boss offsets, randomized existing marks, all incoming C/N/Z/V combinations and distinct DP87 restoration are covered. Full randomized 128 KiB WRAM outside 129 stack bytes, static peripherals, final CPU and restored S/D/DB agree. Script fixtures cover banks 7E/7F, word cursor wrap and long carry. See `data/boss_native_contacts.json`; arbitrary actor offsets, widths and live timing remain open.

`tools/boss_state_inventory.py` separately records static references from the fifteen original descriptor tables, with source/hash provenance and no script payload. Their boundaries are inferred from exact adjacency to the minimum referenced program address: 736 entries lead to 1,829 distinct command positions, 61 native call sites and 37 distinct native destinations. Following 77 distinct jump sites assumes DP02C5=0; all roots terminate under that assumption. Only C23CAB and C23E7F currently have complete native-call models. The report explicitly leaves runtime inventory incomplete: valid state limits, nonzero jump cursors, native script mutations and descriptor init/chooser/action/hurt callbacks still need original execution evidence. These static positions are not added to progress. See `data/boss_state_inventory.json`.


### Native direct palette load and transition-object creation

`tools/boss_native_palette_effects.py` adds C265DD (10 bytes), C265ED (35 bytes) and their real C2272D effect creator (31 bytes). C265DD loads palette identity 0038 into software slot 15 through the existing C226F9 copier and updates its cached identity. It does not publish colours to CGRAM. C265ED adds 0078 to the incoming actor's full word 7E, with sixteen-bit wrapping, caches only the low byte in slot 14, and passes the full result as the transition target identity. It requests a duration-0020 transition for slot 14, then always submits sound 0086 with parameter word 000F through the original CPU audio sender.

C2272D saves A/X/Y and allocates with definition 274C and flags 6000, scanning the six eligible pool slots 3..8. Success writes the original Y to new actor+9E, X to +9C and A to +9A. X remains the allocated actor, Y remains 6000, and A is restored; allocator scratch and object initialization remain visible. Failure restores all three incoming registers but preserves failure carry and allocator scratch. C265ED performs the slot-14 cache write before allocation and issues the sound even when the pool is full. No transition callback executes during creation: C2274C and its palette-animation phases still require reconstruction and execution comparisons.

6,400 complete original calls pass without hooks: 1,024 direct creators, 256 direct palette loads, 1,024 transition callbacks, 2,048 indirect calls and 2,048 full opcode-10 chains. All 64 eligible-slot masks and 16 C/N/Z/V contexts are covered for allocation paths, with nine boss offsets, full-word parameter boundaries, randomized incoming effect registers and WRAM scripts in banks 7E/7F across word-cursor wrap and long carry. There are 4,032 successful allocations, 64 failures and 15,360 ordered APU port writes. The report compares full randomized 128 KiB WRAM outside 129 native stack bytes, all static peripherals, CPU/S/D/DB and port-write order. APU acknowledgement delays 0/1/3/7 reads remain explicit input boundaries, without SPC playback or physical timing proof. See `data/boss_native_palette_effects.json`.

`NativePaletteEffects` admits these two callbacks alongside the previously recovered C23CAB and C23E7F. Four of the 37 statically referenced native destinations now have complete models in their stated domains; the remaining targets, dynamic inventory, music dependency C230C2, palette publication, transition animation and full state VM remain open. The structural inventory report has been refreshed against the new matching sources. No palette or audio payload is saved.


### Complete palette-transition phase machine and software division

`tools/boss_palette_animation.py` reconstructs C2274C..C22A58, its two seven-entry phase tables and real software division C22CBF/C22D69. Together with the already recovered creator C2272D, this is an independently assembled contiguous 812-byte component. The new sources add 852 instruction bytes and 28 numeric pointer bytes. The model requires the native zero sentinel at DP02C5, M16/X16, D0200 and DB7E; the native C2001B initialization path explicitly clears that sentinel at C20030. The new validation does not execute that outer initialization or establish every later writer.

A duration of zero immediately copies the target palette, or a selected target colour, and returns carry set. A nonzero duration dispatches actor+94 through seven phase pointers, choosing the full/single-colour table from actor+9E bit8000. Full initialization expands sixteen packed colours into 48 channel words at actor+100 and target words at actor+160. Each channel has eight fractional bits: blue, green and red components occupy bits8..12. Four subsequent phases derive increments for four colours each, using signed `(target-current)/duration`. Single-colour mode expands three channels at actor+30/+36, uses bits8..11 of mode as the colour index and the low nibble as palette slot, then advances through three spacer phases. Whole-palette initialization uses its original mode-word transform without substituting the single-colour masks.

The stepping phase adds increments to all current channel words, packs their high five bits into software palette memory and decrements duration. When it reaches zero, the next invocation copies the exact target colours, preserving original target bits and eliminating accumulated truncation error. The arithmetic truncates signed division toward zero; no floating-point interpolation, channel clamp or bit15 preservation is substituted during intermediate packing. Original pointer updates, eight-bit channel-loop indices, scratch mutations and returned CPU flags are preserved. The model rejects phases outside the seven entries; native out-of-table dispatch is a separate audit.

C22CBF implements unsigned word division in sixteen software shift/subtract iterations, without hardware division registers. It destroys the dividend, produces quotient at DP56 and remainder at DP5E, and restores saved P before returning the zero sentinel. X ends at zero and Y loses its high byte after index narrowing. Zero divisors return A=FFFF without producing new outputs. C22D69 normalizes signed magnitudes, calls that original divider, and corrects quotient/remainder signs with literal word arithmetic, including 8000 and zero-divisor effects. Its A and flags retain native pop/subtract residues rather than a conventional quotient return.

9,760 complete original calls without hooks pass: 256 calls each to eighteen phase/channel entries, 2,048 each to the unsigned and signed dividers, and 1,056 calls in 64 complete transition sequences. Cases span all sixteen slots and colour indices, all 256 sampled palette identities, phase0..6, zero/nonzero durations, signed boundaries and all incoming C/N/Z/V combinations. Sequences cover full/single modes and durations1/2/7/32, reload the frame caller's actor X before each invocation, and retain the model's entire state through completion. Full randomized 128 KiB WRAM outside129 native stack bytes, static peripherals, final CPU and S/D/DB agree. See `data/boss_palette_animation.json`.

This closes the palette object's phase machine in its native tested domain, not hardware CGRAM publication, actual frame scheduling, nonzero sentinel contexts, arbitrary pointer aliasing or the full boss state VM. No original palette payload is saved. The two pointer tables contain numeric targets only.


### Boss attack variant and target control/status native callbacks

`tools/boss_native_target_status.py` adds four complete native-call destinations: C26183 (23 bytes), C261D0 (61), C2620D (53) and C26242 (49). The three target routines form a contiguous 163-byte component. The model extends the existing native palette/contact/projectile model and reuses the verified full attack-row preparation, with all original game callees executing.

C26183 reloads actor X from DP87 and tests the complete actor+42 word. Zero selects attack row25; every nonzero word selects26, including values with a zero low byte. It then invokes the original C0006C attribute rebuild, preserving its normalized X/Y, hardware multiplication and context residues. This is row preparation, not damage resolution.

The target routines use the full actor+A9 word: XBA, a word shift and E000 addition produce Y. C261D0 requires target+60=0, target+0E=0 and target+1E5 different from24. On success it writes24 to1E5, ORs mask01 into the low status byte at190 and sets1B4 to20. On any failed guard it instead increments the word at DP36 and writes1 to the incoming boss's word7E. This increment wraps atFFFF. C2620D requires target+60=0, target+11=A4 and target+0E=0; it sets0E mask80, status mask01 and1B4=20. Skipped paths preserve their literal returned A/flags.

C26242 first sets boss word7E to1. If target+60=0 and the **boss's low byte190** has its sign bit clear, it writes0E to target+1E5. It always writes1 to target+1B4 and clears target+0E bit80, regardless of that guard. The existing combat documentation identifies low status bits and1B4 as countdown/control fields; these new calls prove their writes and conditions, not the entire associated grab, removal, recovery or damage sequence. The target calculation does not clamp A9 to three hero identifiers.

49,152 original calls without bypass hooks pass:4,096 per callback directly, another4,096 per callback through C2391D and another4,096 through complete opcode10 C2390F. Tests vary all256 byte values independently across60/0E/11/1E5 guards, nine boss offsets, actual hero targets and sampled full-word transforms, all C/N/Z/V combinations, zero/nonzero word variants, all256 sprite/identity bytes for attribute rebuilding, boss status-byte sign and DP87 selection distinct from incoming actor. Retry-counter fixtures explicitly cover0000/0001/7FFF/8000/FFFE/FFFF. Opcode scripts cover banks7E/7F, long carry and word cursor wrap. Full randomized128KiB WRAM outside129 native stack bytes, static peripherals including multiplication, final CPU and S/D/DB agree. Recorded original PCs confirm both attack variants, successful/skipped status paths and the retry body. See `data/boss_native_target_status.json`.

Eight of the37 statically referenced native destinations now have complete models in their stated domains. C26273 still calls the unmodelled music dependency through C2629C/C230C2, and C26292 still requires external C0003F. The remaining targets, complete state VM, dynamic inventory and live scheduling remain open. No original script or asset payload is saved.


### Native identity reset, random velocity and paired palette callbacks

`tools/boss_native_identity.py` reconstructs C26292 (10 bytes): it reloads the selected actor from DP87, requests identity7A through the real C0003F API and returns that routine's normalized actor offset. The dependency already had matching source and a complete memory model in `actor_identity_change.py`; this proof strengthens its positive-identity domain with final CPU and hardware-latch comparison. All128 identities00..7F are checked in sixteen contexts, covering ordinary flags00, special flags01/40 and early classification10. The negative identity paths retain their earlier memory proof and are explicitly rejected by this new CPU model.

For positive identities, the final hardware multiply is the identity times five for drop metadata. Final X/Y are the incoming actor address masked1FFF. A retains that product's high byte and the final appearance flag byte, or D2 for the flagged exceptional sprites. The API restores original widths and C/V, while final N/Z describe restored D from PLD. Identity7A therefore returns A0240. It clears/rebuilds the attribute subrecord, not the entire allocated boss object. 14,336 original calls pass without hooks:2,048 positive API calls and4,096 each through C26292, indirect C2391D and complete opcode10. Full randomized WRAM outside129 stack bytes, static peripherals including multiply latches, CPU/S/D/DB agree. API fixtures include sixteen aligned slots/full-address aliases, both accumulator widths, D0/0200/0300/1234 and DB00/7E/7F/42; native and script contexts remain M16/X16/D0200/DB7E. See `data/boss_native_identity.json`.

`tools/boss_native_shared_dependencies.py` adds four more destinations using existing real dependencies. C261B1 (31 bytes) draws twice from C2300B with inclusive bound2, subtracts1 from each result, stores the two words in DP95/97 and writes them to selected actor+3C/+40. The results are FFFF/0000/0001; it retains both RNG pool mutations, hardware latches, index narrowing and final flags. C273AD (10 bytes) stores incoming actor+32 in global035C and clears word0358, without assigning a broader gameplay role to that global.

C24437 (48 bytes) returns immediately when the incoming actor's complete word42 is zero. Otherwise it caches palette1C in slot13 and1D in slot14, and attempts two duration10 transition objects through C2272D. C24477 (43 bytes) always caches1E/1F in slots13/14 and attempts two duration16 transitions; its literal operands use target identity1E for **both** objects. The cached second identity and actual second target therefore differ. No correction or bug classification is substituted. On enabled paths both allocations are attempted even when the first fails; partial/full pool exhaustion and cache writes remain visible.

27,507 original direct/indirect/opcode10 calls pass without hooks:9,075 random-velocity calls across all55×55 valid initial pool-index pairs,12,288 coordinate-save calls and6,144 paired-palette calls across all64 eligible-slot occupancy masks and sixteen contexts. There are10,080 successful effect allocations and672 failures. Full randomized128KiB WRAM outside129 stack bytes, static peripherals, CPU and S/D/DB agree, including all C/N/Z/V, nine boss offsets, word variant samples0/1/0100/FFFF, distinct DP87 selection and script7E/7F long-carry/cursor-wrap cases. See `data/boss_native_shared_dependencies.json`.

These five callbacks add142 matching instruction bytes. The random callback extends the previous target-control component backward to C261B1, yielding194 contiguous bytes; identity C26292 remains a separate block because the intervening C26273 dependency is still open. Thirteen of37 static native destinations now have complete models in their stated domains. Music-dependent callbacks, remaining native targets, dynamic inventory, full state VM and live scheduling remain open. No original asset or script payload is saved.


### Native mirrored projectile launch C273E6 and palette C27273

`tools/boss_native_leaping_projectile.py` reconstructs the complete 112-byte launch and 10-byte cached palette wrapper. The original launch snapshots the incoming boss's word coordinates, target A9 and parent pointer before allocation. It prepares horizontal offset30, vertical offset-40 and velocities4/-4. Orientation bit0040 applies literal XOR with DP02C7 followed by INC to horizontal offset and velocity; only sentinelFFFF yields ordinary negation. The model preserves other sentinel values rather than replacing this with a sign calculation.

The original allocator C20D53 receives definition7456 and flagsB801, scanning eligible slots3..8. Success writes position, full target word, horizontal/vertical velocity and parent B0, then calls C27273 to load palette58 into software slot15 through real C226F9. Snapshot order handles an allocated slot aliasing the parent. Failure skips object-field/palette writes while preserving preparation/allocator scratch effects. Both paths reload X from DP87, which need not select the incoming boss. The palette wrapper copies32 software palette bytes and updates the cache; this call does not publish CGRAM.

All6,144 original full-state comparisons pass without instruction bypass hooks: both callbacks through direct, indirect and complete opcode10 paths, all64 slot occupancy masks,16 facing/status contexts,nine boss actors,coordinate boundaries,full target words,distinct DP87,script banks7E/7F andlong pointer/Y wrap. Allocation succeeds3,024 times and fails48 times. Randomized128KiB WRAM outside129 stack bytes,static peripherals,CPU registers/flags/widths and S/D/DB agree atM16/X16/D0200/DB7E,binary arithmetic. Creation and palette loading are proved in this domain; subsequent definition7456 initialization,motion,collision,rendering and full state-machine/frame execution remain open. See `data/boss_native_leaping_projectile.json`.


### Boss target placement, indexed contacts and selected-actor reset

`tools/boss_native_target_position.py` reconstructs six complete callbacks (289 instruction bytes) and their original callees:

- C252B7(56) first executes real C2620D hold, then always copies boss2B/32 into target2/4. Only a zero target word190 allows further control setup; target byte60 and0E must also be zero. It writes control24,ORs190 with01 andtimer1B4=20. A successful initial hold already changes190, preventing this second setup.
- C252F0(57) uses the incoming boss's full A9 word directly as an index into C205F0, ORing the byte into that boss's59. It then reloads DP87, transforms that selected boss's A9 into a target pointer, derives the selected boss index from `(DP87-E600)>>1` plus XBA and ORs its lookup byte into target5A. This differs from C23CAB's direction/owner assignment. Numeric lookup reads beyond the first eight masks are preserved, without interpreting them as valid gameplay indices.
- C25329(43) performs the target/status release of C26242, including conditional control0E,unconditionaltimer1 andclearing target0E bit80, but does not write boss7E=1.
- C25586(28) clears the incoming boss's word60, then invokes C23963 with8A00. A nonnegative global0362 selects an actor offset and runs the real external API, whose command8A clears global0049; a negative selected word skips that command. Both paths load cached palette2F into software slots13/14. Final X is the second palette's doubled identity, not the boss pointer (the opcode10 caller restores its own X).
- C255A2(65) transforms full A9 into a target pointer and rejects target word190 bitsC568 or nonzero byte60. Eligible targets receive control07,status190 OR01,timer20,and coordinates boss2B+16/boss32+1. The horizontal ADC sets C/V; the following INC keeps them. This helper is not among the37 statically referenced opcode10 targets.
- C255E3(40) always advances target word4 by2. It conditionally writes control0E when target byte60 is zero, then unconditionally writes timer1B4=1. Coordinate addition precedes the guard and retains its C/V through byte stores.

All73,728 no-hook original calls pass:4,096 per callback on each direct/indirect/full opcode10 path,including all256 byte values in16 guard/status contexts,nine boss actors,full target-word samples,distinct incoming/DP87 actors,coordinate wrap boundaries andselected actor offsets0/0200/0600/1E00 ornegative8000/FFFF. WRAM,static peripherals,CPU/widths and S/D/DB agree atM16/X16/D0200/DB7E,binary. Each comparison excludes129 caller-stack bytes. Synthetic target pointers in1D00..1F00 use caller S1700 instead of1F00 to keep target fields separate from call frames; return-address corruption when targets alias the stack is outside this proof. The real hold,external actor API andpalette-cache callees execute without bypass hooks. Whole grab/release gameplay,other callbacks,dynamic/descriptor inventory,full state VM andlive rendering/timing remain open. See `data/boss_native_target_position.json`.


### Boss direction quantizers and bounded direction-table acceleration

`tools/boss_direction_geometry.py` reconstructs the shared geometry used by definition7456 and other boss routines. C20941/C20965(36 bytes each) mask incoming identity to its low byte, derive target baseE000+(identity<<9) with16-bit wrap,copy target2/4 andselected DP87 boss2B/32 into the coordinate workspace,andinvoke the eight-way orfine-direction routine. This differs from callbacks that transform the full A9 word.

The contiguous273-byte C22E50..C22F60 contains both quantizers andsix shared helpers. C22EA0(15) subtracts coordinate pairs withindependent SEC. C22EAF(29) derives a quadrant from signed word differences and swaps the two lower quadrants. C22ECC(23) negates negative differences using DP02C5 as the subtraction origin,retaining8000 overflow. C22EE3(17) compares the absolute axes;C22EF4(38) classifies usinghalf-axis unsigned comparisons,including equality. C22E50(39) reflects that classification andcombines it withtwice the quadrant;an exact output8 reloads C5.

C22F1A(71) uses the existing original software division C22CBF. It divides the larger absolute axis bythe smaller,clamps the quotient to31,andadds/subtracts it around31. A zero smaller X takes a fixed31 fallback inone branch;whenboth axes arezero,the opposite zero-divisor branch retains prior scratch56 before the clamp. C22E77(41) reflects this value around63 onalternate quadrants,combines it with64 times the quadrant,andreloads C5 foroutputs at least256. No trigonometric replacement ornew scaling is substituted. The software divider changes X tozero andkeeps only Y's low byte onits nonzero-divisor path;zero division preserves them. DP02C5=0 is the verified native contract for this composition.

C232BC(87) computes the negative word velocity limit,derives tableY fromactorAB<<2,reads two word accelerations through the long DP0C pointer andadds them toactor3C/40. It stores each sum before testing its sign. A nonnegative sum compares unsigned against the positive limit; a negative sum compares unsigned against the computed negative limit. The order,word overflow andC/N/Z/V returned bythe final vertical comparison/store are retained,includingnonstandard limits such as8000/FFFF. Pointer reads carry across banks,while the Y increment itself wraps16 bits.

The validation covers eleven complete original routines with180,736 no-hook full-state calls. Each has4,096 randomized native contexts. Both quantizers additionally checkevery256x256 signed-byte difference pair and144 word-boundary pairs across16 C/N/Z/V contexts. Target wrappers coverall256 low identities andsampled high bytes;nine boss slots,16 acceleration rows withhigh-index aliases,coordinate/velocity/limit boundaries andWRAM7E/7F long pointer carry are included. Full128KiB WRAM outside129 stack bytes,static peripherals,CPU/widths and S/D/DB must agree atM16/X16/D0200/DB7E,binary,C5zero. These are geometry prerequisites;definition7456's complete update,collision,rendering andframe/state-machine execution remain open. See `data/boss_direction_geometry.json`.


### Boss projectile collision shapes, party scan and parent contacts

`tools/boss_projectile_collision.py` reconstructs ten complete collision helpers (651 instruction bytes). The eight C205F0 index masks are regenerated as `1<<index` (8 numeric bytes), not copied as a payload. Original word lookups at the last mask can read a following instruction byte; that value is preserved rather than synthesizing another mask.

C20779(78) rejects a zero wordC2, then snapshots boss2B, computes boss32 minus the unsigned half ofword66, stores height66 and sign-extends C0..C3 into secondary-box fields56..5C. C206FE(123) rejects only whenboth wordsCA/CE arezero. It uses the incoming boss forcoordinates andfirst shape C8..CB,but reloads DP87 forsecond shape CC..CF. C207C7(142) transforms incoming Y into a party pointer,requires low identity byte1 (a nonzero high byte is accepted),and rejects a target already marked in selected boss5A. It stores party height45 doubled andexpands signed C8..CF offsets/extents forboth party boxes,restoring Y between expansions. Sign-extended negative radii,word wrap andpartial scratch updates remain literal.

C206EF(15) compares the word absolute height difference against129,including8000 negation overflow. C206C5(42) normally returns that rejection carry,but inverts it when `(party0B|boss0B)&3` equals3. C205F8/C20690(53 each) compare absolute X/Y differences to unsigned summed radii,includingequality. Zero radii OR returns no overlap. C20690 tests the second box andC205F8 tests the first;their register/scratch/carry residues are retained.

C205BF(49) prepares the selected boss secondary box andscans three party slots inascending order. It requires eligible/unmarked identity,height acceptance,no second-box overlap,andfirst-box overlap. It stops at the first successful slot,orreturns clearcarry afterall three fail. Scratch24 records the selected index or3 aftera complete unsuccessful scan (a missing boss box returns earlier).

C23CE8(76) executes the real scan,then rejects a duplicate target bit inparent5A. A new hit ORs the target bit into parent5A andthe parent boss bit into party59. The latter lookup is performed while M16,soits high byte survives subsequent M8 operations andthe final M16 return. Parent index8 reads the following instruction bytes;this literal read does not establish gameplay eligibility. C23F64(20) returns setcarry immediately fornegative parent word190,otherwise returns the real contact result. A negative parent leaves X pointing at the parent;success through the scan returns X to DP87,while intermediate duplicate/no-hit paths retain the original residues before the outer wrapper's restore.

All54,784 original calls pass without bypass hooks:4,096 perroutine plus4,608 directed cases each forscan,parent contacts andparent status. Everyroutine exercises both carry outcomes. The cases coverall256 shape/flag byte values,nine boss/selected/parent slots,three heroes,all8 active-party masks,first-box miss,second-box exclusion,height rejection,duplicate parent marks,negative parent status andzero/high-only shape guard words. Height comparison includes127/128/129/130 andword sign/wrap boundaries. Full randomized128KiB WRAM outside129 stack bytes,static peripherals,CPU/widths and S/D/DB agree atM16/X16/D0200/DB7E,binary,valid actor pointers,Y/DP24 indices0..2 forsingle-party entry. Actual damage,projectile state/resource/motion/rendering andfull state VM/live frame scheduling remain open. See `data/boss_projectile_collision.json`.


### Complete three-state projectile definition C27456

`tools/boss_leaping_projectile_states.py` reconstructs the157 instruction bytes ofC27456..C274F8 andits three numeric state pointers(6 bytes). The associated direction tables add64 numeric bytes: eight animation ids atDCE525,eight orientation words atDCE535,and eight pairs ofaccelerations atDCE545. Accelerations are the eight compass combinations of0/+2/-2;animation ids repeat106/105/104/105,andorientation bits replace onlyactor98 bits00C0.

C27456(8) reads incoming actor94,shifts it to a word-table index andjumps tostates0/1/2. Each state reloads the selected actor fromDP87. C27464(28) increments that selected actor's word94 (includingwrap),seeds animation104,clears wordB2,sets wordidentity0=1 andmotion callback90=3F4C,thenreturns clearcarry. Incoming actor andselected actor maydiffer.

C27480(110) masks selected A9 toits low identity byte throughreal C20941,saves the eight-way target direction inAB anduses it toadd direction-table accelerations,clamping velocity withlimit4 throughC232BC. It derives a second direction fromthe resulting velocity usingC22E50,seeds the corresponding animation andreplaces orientation bits00C0 fromthe numeric table. It copiesYposition32 intofield22 beforecalling the real C23F64 parent/collision chain.

A clearcarry contact result returns withoutchanging state94 orcallback90. Setcarry seeds animation15C usingthe X left bythe contact chain,thenexpands actualresource27 throughoriginal C224C3/C224F1,reloads DP87,increments selected state94 andclears callback90. A negative parent word190 leaves X pointing atthat parent,soits animation is seeded beforethe selected projectile isreloaded. This order is preserved withouta gameplay correction. Resource27 has2048 logical output bytes into7F7000;native overlapping word stores andthe finalextra byte are compared overfullWRAM. Its returned accumulator/index/flags are included inthe complete caller comparison. No compressed/decoded resource is saved.

C274EE(11) returns setcarry onlywhen selected word9E iszero;other values return clearcarry. The native state domain0..2 is verified;out-of-range dispatch reads are notclaimed. Motion callback3F4C,terrain composition,animation interpretation andglobal actor removal/rendering are separate remaining work.

All9,984 complete original calls pass withoutinstruction bypass hooks:4,096 initializations,4,096 terminal calls,512 randomized updates,768 dispatcher cases,256 directed updates and64 persistent four-call sequences(256 calls). There are377 real resource expansions. Cases includenine incoming/selected/parent slots,all256 low target identities withsampled high bytes,all16 C/N/Z/V contexts,counter/coordinate/velocity/timer boundaries,all8 party masks,collision misses,duplicate parent marks andnegative parent status. Full randomized128KiB WRAM outside129 stack bytes,static peripherals,CPU/widths and S/D/DB agree atM16/X16/D0200/DB7E,binary,C5zero. Persistent sequences followinit→contact transition→waiting→completion;the final9Ezero is anexplicit supplied input,not an animation-VM proof. See `data/boss_leaping_projectile_states.json`.


### Projectile motion callback C23F4C and full terrain composition

`tools/boss_projectile_terrain_motion.py` reconstructs the24-byte motion callback assigned bydefinition7456 andextends theexisting terrain model withcomplete CPU flags/static peripheral effects. C23F4C separately adds3C/40 tocoordinates2B/32 (each withCLC),storesboth sums,andthenexecutes real C215B7. A terrain-bound failure therefore occurs afterthe coordinate writes. C215B7's initial bounds operate onthe incoming actor;its valid layer/probe paths later reload DP87 andmaywrite a different selected actor.

The readable terrain composition covers C215B7,C21683,C216B6,C21706 andnative-M8 C22AA6. It retainswrapped Y+actorA5,extent lookup,independent layer/status offsets toWRAM7F tile/attribute pointers,thelow-byte hardware row product,word-indexed tile/attribute reads andordered positive-X/negative-X/positive-Y/negative-Y probes. Blocking changesactor5B/4E andpreserves the accumulator high byte in the M8 LSR→TAX mask lookup;that high byte can select beyondthe small direction mask table. The multiply model checks the complete operand latch/product fields aswell astheWRAM product bytes. FinalC/N/Z/V,widths andX/Y restoration agree withthe native code.

All90,944 original full-state calls pass withoutbypass hooks. Each ofthe six routines has4,096 native contexts,andC22AA6 additionally checksall65,536 byte operand pairs. Cases coverall256 extent/accumulator-high values,16 actor/selected offsets,all16 C/N/Z/V contexts,layer selection,bounds,coordinate/velocity/Y-adjustment word boundaries,WRAM7F long-pointer carry andfour probe directions. Full128KiB WRAM outside129 stack bytes,static peripherals,CPU and S/D/DB agree atD0200/DB7E/X16,binary (M16 exceptnative multiplication helperM8).

Sixty-four persistent13-call sequences(832 calls) compareactualcreationC273E6,initialization,four motion/update pairs,contact transition,waiting andterminal completion. They retainmemory between calls andexecute realallocation,palette,terrain,collision andresource callees. Actor selection,parent negative status andfinalanimationword9Ezero are supplied caller inputs;global frame scheduling andanimation interpretation remain open. Only C23F4C's24 bytes addsource/ROM credit;allterrain sources are reused. See `data/boss_projectile_terrain_motion.json`.


### Boss animation command-to-frame interpreter and all26 commands

The complete contiguous component C213EB..C21A80 now has readable models and independently matching sources. Its1686 bytes comprise1270 newly recovered instructions,52 regenerated command pointers and364 previously recovered terrain instructions reused without duplicate credit. The two models are `tools/boss_animation_movement.py:AnimationMovement` and `tools/boss_animation_commands.py:AnimationCommands`.

C213EB selects the stream pointer from DBF9A8 using the incoming actor's animation9A,then reloads selected actor DP87 and its word cursor9C. The stream bank remains DP78. Odd bytes01..33 dispatch the26 commands through C21425/C2142E; an even byte begins a three-byte frame record. The record writes A0,A1 and byte9E,then stores the advanced word cursor9C. Commands can alter the cursor,pointer or selected fields before the next record. The numeric dispatch pointers are derived from the recovered handler names.

The command set includes six orientation operations; collision-aware movement; selected-actor restore; absolute jump; relative actor parent assignment; animation replacement; sound request; byteA2 assignment; rewind; conditional party control; mirrored party positioning; two motion/rate formats; two object creation formats; work-buffer DMA; two mode-bit operations; selected external actor command; and word22/88 assignments. C21978 is the shared creation-position helper. Byte motion rates use two byte shifts plus byte addition,so5*parameter wraps at256 and retains the original accumulator high byte.

Movement C214AA consumes two signed byte offsets. Horizontal/vertical orientation negates each byte before sign extension,so80 remains80 under byte negation. It attempts horizontal andvertical movement separately through real terrain andparty checks. A rejected axis is undone before attempting a two-pixel slide on the other axis;actor4E bits select slide direction. Zero offsets still perform the checks. The final Y restore supplies N/Z while A/C/V retain the last operation's effects.

C21723 tests only actors with word98 bit10 andunsigned height66 below64. It requires exact full-word party identity1 andnonnegative word190,then compares unsigned summed radii against wrapped absolute coordinate differences. Equality hits;absolute8000 retains its overflow. On a hit,C217A9 ORs `party_index<<4` into actor5B:slot0 contributes zero,rather than a synthesized bitmask. First-hit order andscratch/register residues are preserved.

C2186C mirrors sign-extended word offsets,which differs from movement's byte-first mirroring at80. The two creation commands snapshot animation,position,height,parent andoffset fields,then call the actual allocator for definition31D4. One derives flags from actor98,the other reads explicit flags. Both perform their seven field stores unconditionally after allocation:failure leaves X=9 andthe stores still execute at that low WRAM base. This native failure behavior is retained. C219CE uses fixed-source DMA7 to repeat the byte at C20D52 into1024 bytes at WRAM1BC00;the source pointer remains0D52,the transfer count becomes zero andthe WRAM port pointer advances to1C000. No work-buffer orROM asset payload is stored.

Movement validation already completed110592 no-hook original calls,including all65536 offset-byte pairs;that proof was reused. The larger command block adds7040 directed original calls:256 each for20 routines andthe parser,plus64 real dispatcher calls for eachof26 commands. The parser cases execute generated command sequences through frame-record stores. Real terrain,allocation,APU packet sender,selected actor API andDMA callees execute. Full128KiB WRAM outside129 caller-stack bytes,static peripherals,CPU flags/widths andS/D/DB agree atM16/X16/D0200/DB7E,binary. Reports are `data/boss_animation_movement.json` and `data/boss_animation_commands.json`.

The command proof samples all256 byte parameters,four orientation patterns,nine selected boss slots,three party targets,status guards,coordinate boundaries,WRAM7E/7F streams andY wrap. Animation replacement samples ids0..255;relative parent assignment tests offset0;external actor command tests8A plus negative selected-actor skip. Allocation success andfailure are both observed. SPC acknowledgement is supplied at the port boundary;SPC execution andtiming are outside this proof. The outer animation tick C213AD,graphics preparation C21A81/C21C37,global scheduling,rendering andwhole-ROM completion remain open.


### Complete boss animation tick, graphics cache and frame geometry

`tools/boss_animation_graphics.py:AnimationGraphics` reconstructs21 routines:the62-byte outer tick C213AD andthe graphics preparation span C21A81..C21F7F. The new contribution is1339 instruction bytes plus two generated piece-size constants(16/32) at C21EE9. Together with the previously recovered command interpreter,this creates a complete contiguous3027-byte source component C213AD..C21F7F. No graphic,frame orcompressed tile payload is saved.

The tick branches on actor98's word sign. Both paths set stream bankDP78=C1 anddecrement only byte9E whennonzero. A transition from1 to0 calls the real command-to-frame parser. Negative actor98 always prepares the graphics cache andframe geometry,includingtimer0 andnon-expiring timers;nonnegative actor98 prepares geometry onlyafter expiry. Thus an already-zero timer is not automatically reseeded oradvanced. Actor selection andreturned width/flags follow the real callees.

C21A81 chooses the regular cache path when actor98 bit1000 isset,andthe background cache otherwise. C21A91/C21ACA read the frame's byte count,then scan four-byte records with byte X/Y indexes. C21B2D derives the cache key from graphic id bits01E0 andthe halved low nibble. Regular-key search begins atslot0; background-key search begins at30. Both retain their native count/comparison residues. Regular allocation accepts negative slot markers other thanFE/80;background allocation requires exactly80. Searches stop at4D.

The two enqueue routines update the key-to-slot andslot-to-key mappings before checking the byte transfer count atDPCA against22. A full queue therefore leaves those mapping writes intact andreturns carry set. On success,they append source/destination word pairs at0E7D/0E7F,advance the appropriate cache cursor andreturn clearcarry. The source address derives from the shifted graphic id withthe native2000 adjustments;the destination derives from D97F35's slot word times16 plus6000. Byte-index truncation,word shifts andpartial failure effects are retained.

C21C37 chooses frame layout from the frame header's sign. A foreground frame writes the piece count to the buffer selected byDP89,then generates four-byte records containing mirrored X/Y offsets andtile attributes. Uncached pieces choose size16/32 fromattribute bit5;cached pieces use16. Horizontal andvertical mirroring subtract the offset andpiece size using byte arithmetic. Tile attributes retain direct orcached tile selection,the literal actorA3 transformation andorientation XOR. The numeric size table is regenerated as1<<4 and1<<5.

The shape trailer contains three independently optional extent/position pairs,stored into actorCA/C8,C2/C0 andCE/CC. Zero extent omits its position word andleaves the previous position untouched. Orientation subsequently mirrors allthree stored position bytes regardless ofwhether that shape was supplied. This preserves stale-position and80-negation behavior rather than normalizing missing shapes.

A background frame supplies two scroll offsets,then six-byte block records(position,byte width/height andC1 source pointer),followed by the same shape trailer. C21CCF derives the WRAM7F tilemap pointer atBC00,uses the real hardware multiply helper fordimensions,andselects doubled versus single byte width from actor98 bit4. It writes scroll/camera scratch fields beforedecoding. A zero source-mode byte copies literal bytes;nonzero mode uses eight-bit masks tochoose a literal byte orthe byte fromtwo output positions earlier. The two history bytes start atzero. Row output advances the tilemap pointer by64 andthe source cursor retains its C1 bank. The existing C22005 coordinate/height preparation executes beforethe tile output.

All3024 complete original calls agree withoutbypass hooks:21 routines×128 directed contexts,128 additional actual animation104/105/106 expiry calls,and16 persistent13-call sequences(208 calls). Each sequence executes actual projectile creation,initialization andfirst-frame tick,then a caller-supplied seed15C,its eight actual animation ticks,andthe native terminal check. Animation15C itself produces word9Ezero after8 ticks inall16 sequences;the terminal input is no longer forced tozero. The seed transition remains an explicit caller input,so this does not establish the full collision-driven projectile lifetime.

The comparison covers randomized128KiB WRAM outside129 caller-stack bytes,static peripherals,CPU flags/widths andS/D/DB atD0200/DB7E/binary,using each helper's native M/X mode. Directed contexts include cache hit/miss/free/full andthe22-transfer limit,four orientations,coordinate/attribute boundaries,optional shape words,foreground/background geometry andboth background source modes. Background dimensions sample1..3 by1..2,with actual C1 source pointers trial*17;this is not an audit ofevery background asset. Real CA frames andC1 animation streams for104/105/106/15C execute,andSPC acknowledgements are supplied at the APU port boundary. Rendering,SPC timing,global scheduling andevery real-animation trajectory remain open. See `data/boss_animation_graphics.json`.

While composing these paths,the command test fixture was corrected towrite actual allocator slot bytes at0E60 rather than9E60. The prior command proof used randomized0E60 andalready observed both allocation outcomes;the refreshed7040-call proof now controls the slot patterns deliberately. Models andexisting sources are unchanged,andno extra source/ROM credit is assigned for this correction.


### Boss selected-object emission, alternating pass and callback handoff

`tools/boss_actor_frame.py:ActorFrame` adds442 instruction bytes in10 routines. The selected emission entry C20006/C2023A andalternating entry C2000C/C20250 save callerP/D/DB,establish D0200/DB7E/M16/X16,execute their real bodies andrestore the incoming context. Selected emission takes the actor offset relative toE000 inX;the tested boss offsets are0600..1600 in0200 steps. The alternating wrapper also accepts incoming byte indexes because its body establishes word indexes before scanning.

C20F91 derives selected actorDP87 andits F800 piece-buffer pointerDP89 fromthat offset,saves flags98 intoDP8D,andaligns the camera whenbit0008 isset. GlobalED bit0040 suppresses the remaining work unlessactor98 bit1000 isalso set. Eligible calls consume palette commands beforeexecuting height/motion dispatch. Word70 bit0004 then controls a second alternation:bit0002 iscleared andthe routine returns whenalready set;otherwise bit0002 is set andemission proceeds. The callback therefore canrun on a step that subsequently skips drawing.

Emission initializes the shared sprite cursor from global7C>>2,packed-high state from0059,andlimit0080,thenexecutes the original C21F80 renderer andits clipping/attribute callees. It writes the advanced cursor back asglobal7C,updates0059/005A using the native packing lookup,andsets0FAC=1. These globals andpartial OAM writes are included in the comparison,not inferred froma count alone.

C2133F scans allnine E600..F600 slots. A zero word8C skips the slot. Otherwise,globalED bit0040 forces emission;withthat flag clear,the routine XORs word8C with0002 andemits onlywhen the resulting bit0002 isset. It preserves the loop index across the real callback andrenderer. Allslots share the sprite cursor,so ordering andclipped-piece count changes affect the later slots. This pass writes final7C and0FAC butdoes not duplicate the selected routine's0059/005A update.

C211F4 integrates height first whenword70 bit0001 isset. It then suppresses callback dispatch forglobal7ECFFF bit0001,global1D04 bit0040,oractor60's low byteC0. A nonzero word90 isstored intoDP76 andtail-dispatched throughthat pointer. The callback's final registers/flags are therefore part ofthe outer result. The verified real targets are C23F4C motion,C213AD animation,C23182 parent following,C23766 landing,C273AD global-Y snapshot,C27273 palette58 andC261B1 RNG. Script-supplied andother dynamic callback targets are not a closed inventory.

C20E42 snapshots camera coordinates whenactor98 bit0008 isset,usingthe native half-height/XOR adjustment,andcalls the recovered animation tick onlywhenbit0800 isset. C20F83 increments word96 andAD,then tail-dispatches definition8E;the current comparison domain isdefinition7456 states0..2. C20E6A reloads77 cache-marker bytes froma C1 pointer through the WRAM data port,includinglong-pointer bank carry,thenresets regular/background cache cursors to0/30. It returns M8/X16 andleaves the WRAM port pointer at0FA2. No cache-marker payload is saved.

The proof contains5760 no-hook original calls:512 directed cases pernew routine plus16 persistent eight-tick sequences(640 calls). Each persistent tick executes definition counters/state,animation handoff,selected public emission,alternating public emission andthe original NMI handler throughRTI. All544 OAM bytes match the generated WRAM buffer aftereach of128 supplied interrupts:69632 bytes published. These cases keep state between calls;the caller explicitly sets slotselection,resets sprite/transfer cursors andsupplies the interrupt frame. EC08 suppresses other uploads,so this composition proves OAM publication rather than the boss graphics-queue VRAM transfer path.

Full randomized128KiB WRAM outside129 caller-stack bytes,static peripherals andCPU/S/D/DB agree. Internal entries use D0200/DB7E/M16/X16 exceptthe M8 marker reader. Public wrappers sample D0/0200/0300/1234,DB0/7E/7F/42,both accumulator widths andboth incoming index widths forthe alternating pass. Directed cases include allthree callback gates,height integration beforegating,mode-bit skip/draw transitions,nine actors,palette commands andthe seven real callback bodies. The NMI comparison also checks complete native register restoration. Unchanged exhaustive helper proofs are reused.

The contiguous C20F83..C21F7F source component now spans4093 bytes;the public wrappers add a44-byte component andcamera/animation/marker helpers an89-byte component. This does not close C20DB2's full pool update:ordinary objects additionally require C20E9B relative-party geometry andC20F27's contact/damage/API chain. Every definition/callback target,global scheduling,damage,live rendering/timing andwhole-ROM reconstruction remain open. See `data/boss_actor_frame.json`.


### Boss contact masks, primary-party shape and relative geometry

`tools/boss_actor_collision.py:ActorCollision` reconstructs seven routines (529 instruction bytes). C2052E and C2058F execute the original primary and secondary scanners, then mark both participants. Primary contact ORs the boss-slot mask into party5A and the party-slot mask into boss59; secondary contact writes party59 and boss5A. The original first-hit priority, scratch fields and final register/carry state are preserved.

C2055E prepares the boss's two collision boxes and scans three party slots. C20855 accepts an identity whose low byte is1, rejects an existing party5A mask for the boss slot and requires nonzero wordC2. It snapshots party coordinates and doubled height, sign-extends the four primary-shape bytes into words and adds the coordinate offsets. It advances Y through the four bytes and leaves X8 after expansion. Rejected paths retain their actual partial scratch/register changes.

C2062D checks an existing mask before the secondary boss box. Zero combined radii reject the box; otherwise unsigned summed extents are compared inclusively against the absolute word coordinate differences. The native absolute value of8000 remains8000. A hit sets party5A and executes the actual sound request C230E3 with A0/X0; the external APU acknowledgement is supplied, while the original sender instructions and packet writes execute.

The exclusion helper derives its party address from incoming A by XBA/ASL/addE000. C2055E does not reload DP24 after C206C5: the height calculation leaves its absolute height difference in A, which becomes the exclusion helper's input. This can refer to a different party slot or another word-derived address. The reconstruction preserves that native flow rather than substituting the intended scan index. Scratch values, mask writes and sound side effects are compared in the enclosing original scan.

C20E9B stores three relative-distance triplets at actor50..58. Each axis uses signed word subtraction, absolute magnitude and an unsigned clamp to128. Negative horizontal and vertical differences set direction bits80 and40 respectively. Only words52 and55 are cleared first: byte58 can retain an earlier value when neither direction is negative for the third party. The model preserves that stale byte and the incoming-versus-selected actor distinction; final X is reloaded fromDP87.

C20F59 accepts contact classification high bytes8 or9. It updates actor34 as `old | ((old & 70) << 1) | 1` and writes C0 to actor100; other classes return without these writes. It preserves the actual accumulator-width residue and flags.

The report verifies5376 complete no-hook calls (768 per routine),686 actual sound requests recorded in `data/boss_actor_collision.json`. Comparisons cover randomized128KiB WRAM except129 caller-stack bytes, static peripherals, CPU/S/D/DB and all APU packet writes. Native domain is D0200/DB7E/M16/X16/binary, nine boss slots and three direct party indices; the composed scanner also preserves its height-derived exclusion address. Cases cover active/marked slots, first/second overlap and rejection, height flags, all256 shape bytes and reaction classes, and signed/clamped word boundaries. Unchanged earlier collision and sound proofs are reused.

Sources form a910-byte contact/scanner component atC2052E..C208BB and a140-byte relative-geometry component. These routines prepare the full pool update but do not complete damage classification C0002D/C03815 or application018015, nor prove all global callbacks or live scheduling.
