# Spell casting: the caster pose, the spark and the spirit, sounds, banner and timeline

What the game does between the moment a hero confirms a spell in the ring menu and the moment the hero is free again: the pose of the caster, the spark and the spirit (Gnome, Undine, Salamando, Sylphid, Luna, Dryad, Shade, Lumina), the sounds, the spell-name banner, the screen effects and what the rest of the party does. There is **one cast sequence for every hero spell** (there is no separate "plain spell" cast): the same pose, the same spark and the same spirit introduction play for the 42 spells; only the spirit and the part after the spirit introduction depend on the spell. Everything was obtained by running the original code in the interpreter from a save state and by reading the disassembly; ROM data and pictures are never stored in this repository.

Tags: **[V]** executed in the interpreter and measured; **[C]** read from the disassembly only. All times are video frames of 1/60.0988 s counted from the frame in which the cast starts (frame 0 = the first frame the pose is drawn); seconds are frames / 60.0988.

Tools:
- `tools/summon_sim.py`: the harness. One video frame = joypad poll, one pass of the main loop `$C0:B08C`, then the NMI handler (tile, palette and OAM DMA into a captured PPU). The ring menu (`$C1:CB38`) runs unmodified: its NMI waits, the sound-busy wait and the V-blank poll are satisfied by hooks and the serial joypad ports `$4016/$4017` return the pad word, so a script of button presses can drive the real menu (`Sim.run_seq`). `Sim.cast(spell, targets)` does what the menu does when it ends, without the ring.
- `tools/rip_summon.py ROM STATE OUTDIR [--hero] [--spells] [--dirs] [--weapon-row] [--level]`: runs the cast and writes, per video frame, the caster pieces, the effect pieces, the effect pieces drawn on the target and the sprites of other objects as separate transparent PNGs, plus the state bytes, palettes, PPU register writes, sound requests, MP and the target's HP (`frames.json`). Output goes outside the repository.
- `tools/summon_report.py trace|merge`: graphics and palette loads of the casts, the banner window uploads, and the merge of the rips into `data/summon_cast.json`.

## 1. Summary

| item | value | tag |
|---|---|---|
| one sequence for all spells | the pose is hero animation code 0x94 (`$D1:3844` entry 0x14 of the ordinary table); the spirit is drawn by the caster's own effect-piece list | V |
| pose, frames 0-19 | one picture held for 20 frames (arms up) | V |
| spark, frames 21-59 | 8 spark pictures of 5 frames (the last one 4), `Gnome` and the others alike; the picture at frame 60 is empty | V |
| sound 0x2D | frame 20 (parameter 0, pan 0x77) | V |
| frame 60 | the spirit graphics (64 tiles) are loaded; state byte `$60` goes 0x20 -> 0x80 | V |
| sound 0x2E | frame 61 | V |
| spirit pictures | from frame 61, one picture per 5 frames; the number of pictures depends on the spirit (section 5) | V |
| the spell starts | **frame 106 (Luna), 111 (Gnome, Dryad), 116 (Undine, Lumina), 121 (Salamando), 126 (Shade), 131 (Sylphid)** = 1.76 to 2.18 s after the cast started | V |
| MP is paid | when the first target is hit: at the same frame for most spells, later for the spells whose effect needs time to reach the target (section 7) | V |
| the hero is free again | 165 to 190 frames for the hostile spells, 230 to 345 for the ally spells (section 7) | V |
| spell-name banner | text `<spell name> Lv.<magic level>` on BG3 (small window at the top left, rows 2-3); **the HDMA channels 0-1 that show it are on in frames 1-120** (up to frame 235 for 13 spells, section 6); the text tiles arrive in frame 16 | V |
| camera, other heroes, monsters | untouched: the camera never moves, monsters keep acting, no input lock but the caster's | V |
| facing | the caster is **not** turned toward the target | V |

## 2. How a cast starts [C, V]

1. The ring menu ends in `$C0:7309-731A`: `$C0:731F` writes the cast request into the caster object: spell id `+0x170`, element index `+0x177` (the spirit: 0 Gnome, 1 Undine, 2 Salamando, 3 Sylphid, 4 Luna, 5 Dryad, 6 Shade, 7 Lumina), number of targets `+0x176`, target list `+0x178..17A` (slot + 1, 0 = empty; hostile spells use the monster slots, ally spells the hero slots). Then `JSL $C0:001B` (`$D0:4D9E`) clears the hit list `+0x172..174` to 0xFF and stores the magic level in `+0x171` (`docs/rom-combat.md` 5.1, `docs/spells-non-damage.md` 1).
2. After the menu returns, `$C1:DB6B` (menu result 1) -> `$C1:DC38` -> **`$C1:88C7`** starts the cast on the hero object: `+0x111` = magic level | 0x80 when more than one target; **`+0x1C` = 0x40 (state), `+0x11` = 0x94 (animation code), `+0x60` = 0x20 (cast phase)**, velocities 0, `+0x30` = 0xFF, `+0x4F` = 0xCE (0xCF for the sprite: palette index for `$C1:859B`); `$C1:8634` loads 64 tiles from `$D4:BA00` into the hero's effect-tile buffer (the spark) and `$C1:85D8` loads its palette [C, V: both calls seen at frame 0]. The routine returns at once if the hero is busy (`+0x1C` or `+0x60` non-zero) or while the menu owns the hero (`$D0` set and `X == $D4`).
3. Everything after that is the hero's animation script and the effect scripts; the main loop only runs the object steps (`docs/graphics.md` section 5). `Sim.cast` reproduces steps 1-2 exactly (the same result as the menu path for the same spell: same phases and sounds [V, spell 3 through the real menu and through `cast`]).

Two details of the request matter: a request with a non-zero `+0x179/17A` left over from an earlier cast makes the spell hit those actors too (the caster itself was knocked down by Earth Slide in an early run), so the target list must be cleared completely; and the spirit is taken from the spell, not from the ring position (`+0x177` only selects the magic level nibble `+0x1C4..1C7`).

## 3. The caster [V]

State bytes during a cast: `+0x1C` = 0x40 from frame 0 until the hero is free; the cast phase `+0x60` goes through the values below (the phase is advanced by the effect script of the spell, the pose script waits for it with the operation `0xFD`):

| `+0x60` | frames | meaning |
|---|---|---|
| 0x20 | 0 .. 59 | pose and spark |
| 0x80 | 60 .. (spell start - 1) | the spirit sequence; at the end of it the spell starts |
| 0xE0 | spells 03, 09, 0C, 0F, 12, 15, 1B, 1D, 27: from the spell start for 51-85 frames | the effect is building up (the caster keeps the pose and the spirit effect continues) |
| 0xC0 | the ally spells 03, 04, 05, 09, 0A, 0B, 0F, 15, 1B, 1C, 1D, 20, 21, 22, 23, 27, 29: from the spell start (or after the 0xE0 phase) for 65-350 frames | the effect runs on the caster or the party; the caster loops pictures 2-7 |
| 0x00 with `+0x1C` still 0x40 | the hostile spells (and the end of every cast): 55-60 frames | the finishing pictures 49 and 37; then `+0x1C` = 0 and the hero is free |
| 0x40 | spells 08, 0B and 21 only, ~98 frames | the caster holds animation code 0xAB (a head turned to the side) while the drained or healed amount is shown |

Pictures of the hero (frame descriptor index = `+0x26 / 2`, `+0x28` = flips), girl facing down; the three heroes use the same script and differ only in the pictures [V]:

| frames | picture (descriptor) | duration |
|---|---|---|
| 0-4 | 180, flags 0x38 | 5 |
| 5-19 | 180, flags 0x34 | 15 |
| 20-54 | 118, 119, 120, 121, 122, 123, 124 | 5 each |
| 55-60 | 125 | 6 |
| 61 on | 0, 1, 2 ... | 5 each, see section 5 for how many; the hold at the end is 9 or 10 frames |
| after the spell started | spells with a 0xE0/0xC0 phase: pictures 0, then 2-7 looping (flags 0x40 on pictures 5 and 7); spells 08, 0B, 21: animation code 0xAB for ~105 frames; the hostile spells without a wait go straight to the finishing pictures | |
| end | 49 (flags 0x36) 40 frames, 37 (flags 0x34) 15 frames, then the hero is idle (animation 0, picture 240) | |

The pictures were ripped for the glove group (weapon row 0: no weapon piece); the first frames show the equipped weapon in the hand when another weapon is equipped (a sword is drawn in frames 0-18 and again after the spell with weapon row 16, the weapon pieces are part of the effect-piece list) [V].

Direction: the up, down and side casts have the same intro; left is the mirror image of right: for **33 of the 42 spells the left cast is, frame for frame, the exact mirror (picture and position about the foot point) of the right cast** [V, girl; the boy and the sprite give the same counts]. The other nine (03, 09, 0C, 0F, 12, 15, 1B, 1D, 27: the spells with a 0xE0 phase) have the same pictures but the left cast lasts 10 frames longer (the effect travels) (Fire Ball and Thunderbolt are the other way round: right 321 and 315 frames, left 307 and 305). Timelines of the ally spells and of the spells with moving effects depend on the direction, see section 7.

## 4. The spark and the sound of the start [V]

Frames 21 to 59 the effect-piece list holds the spark: a small white glow with sparkles that grows in front of the caster (positions about (-6,-7) to (-14,-12) from the foot point) and, in the last pictures, splits into four stars around it. It is the same for every spirit. The sound **0x2D** is requested at frame 20 (just before the spark appears) and **0x2E** at frame 61 (the first spirit picture) [V: `$1E01`, parameter 0, pan byte 0x77].

## 5. The spirits [V]

At frame 60 the script calls `$C1:8654` with the spell: the 64 spirit tiles are read from bank `$D0` and expanded (3 bytes per tile row, `$C1:C599`, see `docs/graphics.md` section 3) into the effect-tile buffer of the hero, and `$C1:859B` loads the spirit's 5-colour set `n` from `$D1:F600 + 10 n` into the colours 10-15 of sprite palette 0.

| spirit (element index) | spells | tiles at `$D0:` | palette set `n` (argument) | spell starts at | pictures of the spirit sequence |
|---|---|---|---|---|---|
| Gnome (0) | 00-05 | DF00 | 0xF0 | 111 (1.85 s) | 10 steps of 5 frames (the last one lasts 9) |
| Undine (1) | 06-0B | E320 | 0xF1 | 116 (1.93 s) | 11 steps (the last 9) |
| Salamando (2) | 0C-11 | E890 | 0xF2 | 121 (2.01 s) | 12 steps (the last 10) |
| Sylphid (3) | 12-17 | EDD0 | 0xF3 | 131 (2.18 s) | 14 steps (the last 10) |
| Luna (4) | 18-1D | F1C0 | 0xF6 | 106 (1.76 s) | 9 steps (the last 9) |
| Dryad (5) | 1E-23 | F430 | 0xF7 | 111 (1.85 s) | 10 steps (the last 9) |
| Shade (6) | 24-26 | F940 | 0xFD | 126 (2.10 s) | 13 steps (the last 9) |
| Lumina (7) | 27-29 | FD30 | 0xF4 | 116 (1.93 s) | 11 steps, the last two return to pictures 7 and 8 |

What the spirit pictures look like (effect pieces of the caster, frame 61 on, positions relative to the caster's foot point; the step is 5 frames each):
- Gnome: the green-hatted gnome rises from the ground in front of the caster (below it when facing down), waves its arms; positions from (-11, +11) to (-12, +5) [V].
- Undine: a water drop that grows into a splash and a puddle; (-4, 0) down to (-12, +22) and back to (-10, -3).
- Salamando: a pink orb (with the purple palette set 0xF2) in front of the caster; the flame spirit itself is drawn in the next phase.
- Sylphid, Luna, Dryad (a seed that grows into a palm tree), Shade (a thin dark pillar), Lumina (white diamonds) likewise.
Pixel comparison with the public spirit sheets (frames of the old GameMaker project, 5-bit colours): **Gnome 7 of 7, Undine 10 of 10, Sylphid 8 of 8, Dryad 10 of 10 and Lumina 11 of 11 frames are found pixel for pixel** among the ripped effect pictures; Salamando 11 of 12 match in shape (the colours of the public sheet are the red-orange phase, the build-up phase is purple); Luna 5 of 7 and Shade 4 of 12 (the remaining pictures belong to the later spell animations that were not part of this comparison); the spark 5 of 8 [V, `tools/compare_sheet.py`-style comparison].

Every other part of the sequence is identical for the heroes: only the pictures of the body differ. The effect pictures are drawn with the caster's effect list and the effect palette, so the spirit appears at the same place for the three heroes.

## 6. The spell-name banner [C, V]

The cast builds a message in the message buffer `$7E:FE00` at frame 0 (`$C0:5AFD`): code 0x60, code 0x56 + spell id (the spell name, event text 0x800 + id), " Lv." and the magic level digit [C, V: bytes `60 56 0C 80 A6 96 BF BA` for Fire Ball at level 5]. The banner therefore reads **`<spell name> Lv.<level>`** (level 0-8). It is drawn on BG3 (mode 1, BG3 map at VRAM word `$5800`, 2bpp tiles): the glyph tiles are uploaded in frame 1 (`$4880`), the window map in six steps in frames 2-7, the text tiles of the second half in frame 16, and the text is visible on tile rows 2-3 (a small window at the top left of the screen, 16-pixel-high glyphs in white on a dark-blue striped box) from frame 16 [V: BG3 rendered from the captured VRAM and CGRAM, `FIREBALL Lv.5` for spell 0C].

The window is shown through **HDMA channels 0 and 1**: the NMI handler re-enables them (`$420C` = 3) every frame while the message is up and leaves them off otherwise [V: last write to `$420C` of every frame]. The channels are on in **frames 1 to 120** for 29 of the 42 spells and longer for the other 13 (first and last frame in `data/summon_cast.json` `trace.banner_window.hdma_on`; last frame in brackets): 02 (170), 04 (235), 05 (180), 07 (175), 10 and 11 (180), 14, 16 and 17 (190), 18 and 1A (165), 1C (230), 1E (170); the closing steps then come 6 frames before the last frame The six map uploads in frames 114-119 are the closing animation of the box; the BG3 tiles stay in VRAM after the window has closed [V]. The HDMA table itself is set up outside the cast (the harness does not run the HDMA), so the shape of the window gradient was not rendered; the on/off frames are exact.

## 7. When the spell lands and when the hero is free [V]

"Spell starts" is the first frame in which the phase `+0x60` leaves 0x80 (section 5); "MP paid" is the first frame in which the caster's MP changes (the handler `$C8:E6D4` ran for the first target); "free" is the first frame in which `+0x1C` and `+0x60` are 0. Ranges are over 3 heroes x 4 directions with the target 70 px away; they differ with the direction (the effect travels: ally spells depend on the facing) and with the distance to the target (Fire Ball: MP paid at 145-185, free at 240-270 for targets between 30 and 110 px).

| spell | spirit | target flags | MP | spell starts | MP paid | free | sound ids requested after the start |
|---|---|---|---|---|---|---|---|
| 00 | gnome | 81 | 3 | 111 (1.85 s) | 110-111 | 170-170 | 35 4A B0 |
| 01 | gnome | 81 | 2 | 111 (1.85 s) | 110-111 | 170-170 | 31 35 55 |
| 02 | gnome | 81 | 1 | 111 (1.85 s) | 110-111 | 170-170 | CA CB |
| 03 | gnome | 01 | 4 | 111 (1.85 s) | 116-137 | 290-310 | 48 |
| 04 | gnome | 01 | 3 | 111 (1.85 s) | 110-111 | 235-235 | B1 |
| 05 | gnome | 01 | 2 | 111 (1.85 s) | 110-111 | 220-240 | A2 |
| 06 | undine | 81 | 2 | 116 (1.93 s) | 115-116 | 175-175 | 56 |
| 07 | undine | 81 | 3 | 116 (1.93 s) | 115-116 | 175-175 | 35 B5 |
| 08 | undine | 81 | 2 | 116 (1.93 s) | 115-116 | 175-175 | 35 AE |
| 09 | undine | 01 | 2 | 116 (1.93 s) | 121-142 | 295-315 | 48 |
| 0A | undine | 01 | 1 | 116 (1.93 s) | 115-116 | 310-310 | B8 |
| 0B | undine | 01 | 2 | 116 (1.93 s) | 115-116 | 310-320 | 06 |
| 0C | salamando | 81 | 2 | 121 (2.01 s) | 134-175 | 240-260 | 08 35 BB |
| 0D | salamando | 81 | 4 | 121 (2.01 s) | 120-121 | 180-180 | C6 |
| 0E | salamando | 81 | 3 | 121 (2.01 s) | 120-121 | 180-180 | C5 |
| 0F | salamando | 01 | 2 | 121 (2.01 s) | 126-147 | 300-320 | 48 |
| 10 | salamando | 81 | 3 | 121 (2.01 s) | 120-121 | 180-180 | 35 49 |
| 11 | salamando | 81 | 4 | 121 (2.01 s) | 120-121 | 180-180 | 35 39 BD |
| 12 | sylphid | 81 | 2 | 131 (2.18 s) | 144-185 | 250-270 | 30 35 38 |
| 13 | sylphid | 81 | 4 | 131 (2.18 s) | 130-131 | 190-190 | 35 C3 |
| 14 | sylphid | 81 | 2 | 131 (2.18 s) | 130-131 | 190-190 | AC B2 |
| 15 | sylphid | 01 | 3 | 131 (2.18 s) | 136-157 | 310-330 | 48 |
| 16 | sylphid | 81 | 2 | 131 (2.18 s) | 130-131 | 190-190 | 05 B2 |
| 17 | sylphid | A0 | 1 | 131 (2.18 s) | 130-131 | 190-190 | A1 |
| 18 | luna | 81 | 5 | 106 (1.76 s) | 105-106 | 165-165 | B2 |
| 19 | luna | 81 | 1 | 106 (1.76 s) | 105-106 | 165-165 | AE |
| 1A | luna | 81 | 8 | 106 (1.76 s) | 105-106 | 165-165 | C2 |
| 1B | luna | 01 | 3 | 106 (1.76 s) | 111-132 | 285-305 | 48 |
| 1C | luna | 01 | 2 | 106 (1.76 s) | 105-106 | 230-230 | B9 |
| 1D | luna | 00 | 2 | 106 (1.76 s) | 111-132 | 250-270 | BE BF |
| 1E | dryad | 81 | 2 | 111 (1.85 s) | 110-111 | 170-170 | C7 |
| 1F | dryad | 81 | 4 | 111 (1.85 s) | 110-111 | 170-170 | 35 C6 |
| 20 | dryad | 40 | 1 | 111 (1.85 s) | 110-111 | 520-520 | D2 D3 |
| 21 | dryad | 01 | 10 | 111 (1.85 s) | 110-111 | 345-345 | D3 D4 |
| 22 | dryad | 01 | 6 | 111 (1.85 s) | 110-111 | 300-300 | A5 |
| 23 | dryad | 40 | 1 | 111 (1.85 s) | 110-111 | 520-520 | D2 D3 |
| 24 | shade | 81 | 8 | 126 (2.10 s) | 125-126 | 185-185 | 35 B3 |
| 25 | shade | 81 | 2 | 126 (2.10 s) | 125-126 | 185-185 | 0F 35 C6 |
| 26 | shade | 81 | 4 | 126 (2.10 s) | 125-126 | 185-185 | CD D0 |
| 27 | lumina | 01 | 5 | 116 (1.93 s) | 121-142 | 295-315 | 48 |
| 28 | lumina | 81 | 8 | 116 (1.93 s) | 115-116 | 175-175 | C0 C1 |
| 29 | lumina | 01 | 4 | 116 (1.93 s) | 115-116 | 305-305 | A5 |

(Sound ids are the `$1E01` effect ids of `docs/audio.md`, usable as `sfx_XX`; the parameter byte is 0x0F, the pan byte 0x77, or 0x70 for the second request of a pair.) The exact frames of every request are in `data/summon_cast.json`.

A hostile spell frees the hero at about 1.0 s after the spell started (the finishing pictures 49 and 37 last 55 frames); the damage lands later than that when the effect needs time to reach the target (Fire Ball and the other travelling effects). The spells that last longer than 300 frames keep the caster in the pose until their effect script is done. A caster that is knocked down by its own spell (animation 0x8D, the early runs with a stale target list) does not occur with a clean request [V].

## 8. Screen effects, the rest of the party, the camera [V]

- **Colour math** ($2131 CGADSUB, $2132 COLDATA): none during the introduction. Fifteen spells use it from the frame after the spell started: the writes step the fixed colour up by one every 5 frames and back down (for example spell 06: subtract mode `$A3` (BG1, BG2 and the backdrop, no sprites) with the fixed colour 0xE1..0xE9 = grey 1-9, then down again). Modes and fixed colours per spell are in `data/summon_cast.json` (`color_math`: frame, `$2131`, `$2132`): 06 grey subtract (frames 117-272), 0D grey subtract, 0E green+blue subtract (0xC1..), 13 sylphid grey subtract steps of 3, 1A blue subtract (0x82...), 1F green+blue, 20/23 red+blue (0xA2...), 24 and 25 grey **add** (`$23`), 28 grey subtract. Because the sprite bit (bit 4) of `$2131` is never set, the heroes, monsters and spirits are not darkened; only the background is.
- **Brightness** (`$2100` = 0x0F), **BG scrolls**, **mosaic**, **windows** are never written during a cast [V]; the HDMA channels 0-1 are on all the time (HUD gradient) and not part of the cast.
- **Camera**: `$A8/$AA` never change during a cast of any of the 42 spells [V].
- **Palette of the caster**: the hero's body palette changes only when a spell affects the hero (stone saber turns the caster grey for the duration of the effect); the effect colours 10-15 of sprite palette 0 cycle as set by `$C1:859B` (arguments seen: 0x30 at the map load, 0xCE at frame 0, 0x20 at 60, 0xF0-0xFD with the spirit, 0x80-0xB8 with the spell).
- **Party and monsters**: the other heroes and the monsters are not paused: in a recorded run with three heroes and monsters on the map, the monsters kept moving and animating from the first frame of the cast [V]. Only the caster is locked (`+0x1C` = 0x40); there is no global input lock (`$D0`, `$F1`, `$2A` stay 0).
- **A hero hit by an ally spell is held** (2026-10-06, `tools/target_lock.py`, `data/summon_target_lock.json`): the girl cast each of the 14 ally spells (target flags 01) on the boy, who was the controlled hero with the pad held: from the frame the effect reaches him he is in `+0x1C` = 0x40, `+0x60` = 0xC0 and does not move (pad left, up or down: 0 px, against 50 px in the same frames without the spell), then he walks again [V]. The hold starts on frame 0 of the clock of the spell_land rips (Cure Water: hold at 119, heal at 218 = 119 + 99, the rip's `hit`) and lasts 49-219 frames depending on the spell and, for spells 04, 05, 0B, 21, 22 and 29, on the magic level (Cure Water 84 / 94 / 139 frames at levels 0-3 / 4-7 / 8; the sabers 88 at every level). So only the rest of the party and the monsters stay free; the caster and the target are both held.
- **Facing**: `+0x10` does not change during the cast, whatever the position of the target [V]. The spirit is drawn on the side the caster faces.

## 9. The pose-script operations [C, V]

The hero's pose script (`$D1:5D4E` up, `$5D70` down, `$5D92` side) is the format of `docs/graphics.md` section 5: `b0 b1` pictures and operations with bit 7 set, run by `$C0:F90B` (operations `FB`-`FF`) and by `$C1:D5C0` (`80`-`AF`), `$C1:D6DC` (`B0`-`EF`), `$C1:D52A` (`F0`-`F7`), `$C1:D48D` (`F8`, `F9`). The script is `8A  A7  1C B5  1A B5  F9 2D 00  18 7E ... 18 85  83  FD  1B 2F  1B 2F  1A 26  FF` (girl, up); the other two directions use the same operations with other pictures. What each operation does:

| op | handler | effect | tag |
|---|---|---|---|
| `8A` | `$C1:D65F` | `$49` = 0: the draw attribute byte `$49` that `8B` sets to 0xE0 and `8C` to 0x60 (`88` clears the flip bits of `+0x0E`, `89` deactivates the actor: `+0x00` = 0) | C |
| `A7` | `$C1:D682` | one of the velocity presets `8F`-`AA`: the three bytes `vx, vy, vz` at `$7E:C700 + 4 * (op - 0x8F)` are stored in `+0x06/07/08` unless they are 0x80. In the saved state `A7` is (0x80, 0x80, 0xFC): the hero's velocities stay 0 and it gets z velocity -4 | C (table read from the state's WRAM) |
| `F9 id param` | `$C1:D4DE` | sound request: `$1E00` = 2, `$1E01` = id, `$1E02` = param, `$1E03` = pan from the hero's screen x (`$C1:D503`: both nibbles = x >> 4), then `JSL $C3:0004`. `F9 2D 00` is the sound at frame 20 | C, V |
| `82`, `83` | `$C1:D617` | restore the base colour set: `+0x104` = 0, `$C1:859B` with `+0x69` (the palette index saved at the cast start) | C |
| `84`-`87` | `$C1:D621` | set the mirror/rotation bits of `+0x0E` (`(op - 0x83) ^ 3`) and `+0x39` = 0x10 | C |
| `FD` | `$C0:F9B0` | the **cast synchronisation point**: if `+0x60` is 0 the script goes on; if `+0x60` is 0x20 it stores the script pointer and calls `$C1:8707` (start of the spirit: loads the spirit tiles and colour set, `+0x60` = 0x80) and keeps the step; with any other value the step is repeated every tick. The script therefore holds on `FD` for the whole spirit sequence and the effect and leaves it when the effect has cleared `+0x60`; the finishing pictures (`1B 2F 1B 2F 1A 26`: picture 49 for 40 frames, picture 37 for 15 frames) follow | C, V (hook on `$C1:8707` at frame 60, phase changes) |
| `FE` | `$C0:F976` | repeat while the actor has one of the status bits 0x7B | C (`docs/graphics.md`) |
| `FC` | `$C0:F993` | wait while `+0x60` & 0x40 or the actor's status bits 0x03 are set | C |
| `FB` | `$C0:F987` | `JSL $02:BF1D` then continue | C |
| `FF` | `$C0:F90B` | end of the script (state 0x40: clears the state and the animation code) | C, V |

The spirit start `$C1:8707` (called by `FD`) reads the spell's graphics row: `$D0:2AA0 + 64 * spell` (word stored in `+0xFC`, the spirit's own animation script pointer) and the element row `$D0:2A80 + 4 * element`: byte 0 = the colour-set index (`| 0xF0` for the boy and the girl, `>> 4 | 0xF0` for the sprite: 0x80 -> 0xF0 ... 0xDD -> 0xFD, 0x44 -> 0xF4), byte 1 = tile source: the 64 tiles are read from `$D0:DF00 + 48 * byte1` (`$C1:860A`; 0x00, 0x16, 0x33, 0x4F, 0x64, 0x71, 0x8C, 0xA1 give DF00, E320, E890, EDD0, F1C0, F430, F940, FD30), word at +2 = `+0x6A` [C, V against the loads of section 5]. The colour sets themselves are at `$D1:F600 + 10 n`.

## 10. What releases the caster [C, V]

The pose waits on `FD` until the cast phase `+0x60` is cleared. For the spells that launch effect objects the clearing is done by the **release check `$C1:8D80`**, called once per tick while the phase is 0xE0/0xC0: it reads three counters of the caster, `+0x110`, `+0x120` and `+0x130`, one per group of effect objects the spell launched; the hero is released (`+0x60` = 0, then `$C0:E9F4` re-initialises the animation tables) in the tick in which all three are zero [C; V: Fire Ball sets them to (2, 2, 2) at frame 121, they go to (2, 0, 2) at 175, (2, 0, 0) at 186, (0, 0, 0) at 195 and the hero is free at 196, exactly the frame of the release check]. A counter drops when an effect object hits or leaves: the release time is therefore the **flight time of the slowest launched object**, which depends on the distance and the direction to the target.

Which spells depend on the target position [V, `summon_report.py release ... survey`, 13 target positions facing down]: **only Fire Ball (0C) and Thunderbolt (12)**; the other 23 hostile spells that were surveyed (00 01 02 06 07 08 0D 0E 10 11 13 14 16 17 18 19 1A 1E 1F 24 25 26 28, plus the 1C buff) are released at the same frame whatever the target (`data/summon_release.json` `survey`). For the two spells the hero-free frame (and the MP-paid frame) over a 10-pixel grid of target positions (dx -100..100, dy -100..60, the caster's own square left out; `summon_report.py release ... dense FACING`) and the four facings is in `data/summon_release.json` `grid`. The values move in steps of 5 frames (the effect scripts run every fifth frame) and are **not smooth**: a target straight ahead flies differently from one 20 pixels aside (Fire Ball facing down: (0, 40) free at 205, (20, 20) at 250, (0, -70) at 255, (±10, -70) at 250). Example, Fire Ball, facing down, the first measurement on a 40-pixel grid [frame the hero is free]:

| dy \ dx | -100 | -60 | -20 | 20 | 60 | 100 |
|---|---|---|---|---|---|---|
| -100 | 260 | 255 | 260 | 260 | 260 | 270 |
| -60 | 260 | 245 | 240 | 245 | 255 | 275 |
| -20 | 265 | 250 | 235 | 245 | 255 | 275 |
| +20 | 275 | 255 | 240 | 250 | 260 | 285 |
| +50 | 270 | 250 | 235 | 245 | 260 | 280 |

The rule that turns the position into a flight time (object speed and homing) lives in the effect object scripts and was not decoded; the grid is the measurement.

**Ally spells cast on another hero** are different: when the caster is not in the target list the sequence has no wait for the effect on the caster and ends like a hostile cast: spells 04 05 0A 0B 1C 21 22 29 are free at 165-175 frames (the 310-345 of the self casts), the saber-type spells 03 09 0F 15 1B 27 at 230-260 frames, and the free frame of those six depends on the position of the target hero (grid in `data/summon_release.json` `ally_grid`). A cast on all allies (the caster is among them) is a self cast [V]. The pictures of the first 110 frames are the same in both cases.

## 11. The equipped weapon [V]

The pose draws the **equipped weapon** with pieces of the caster's second list (list 2, `+0xD0`), the same list that holds the spark and the spirit. The weapon's tiles (64 tiles of the weapon type, bank `$D4`, loaded by the equip refresh `$C0:E9F8`) sit in the first half of the caster's effect-tile buffer; the spirit load at frame 60 overwrites them, so **from frame 60 until the spirit leaves (and the weapon tiles are reloaded, `$C1:C599` from `$D4:0480` for the glove group)** no weapon is drawn, and the pieces only exist where the frame descriptor has them: the weapon in the hand in frames 0-19 (for the sword of the girl: a piece of 11 pixels at (3, -26) from the foot in the first 3 frames, then a 13-pixel piece at (-17, -17)), the weapon held when the pose ends and in the idle stance. The weapon pieces depend on (weapon type, hero, direction, animation code, descriptor index, flips, frames since the picture started) and not on the spell: **0 shape conflicts between the five casts ripped per hero, direction and weapon type** (the same animation key and frame inside the key gives the same piece position and outline; 4,084 comparisons differ in colour only, the effect colours cycle). Spells 20 and 23 (the weapon change of `docs/spells-non-damage.md` section 9) change the equipped weapon during the cast and are the exception. Ripped with `rip_summon.py --weapon-row ROW --baseline GLOVE_RIPDIR` (rows 9, 18, 27, 36, 45, 54, 63 = first weapon of the sword, axe, spear, whip, bow, boomerang, javelin types; the glove group rows 0-8 draw nothing): the weapon layer is the set of list-2 pieces that the glove cast of the same frame does not have. Whether a weapon piece is in front of or behind the body is the OAM order of the entries: both cases occur (in the first frame of the girl's sword cast the weapon entry has OAM index 3 against 4-7 for the body: in front; from frame 3 it has 7 against 3-6: behind).

## 12. Magic level, several targets [V]

**Level.** The cast level (`+0x171`, 0-8; the stored level is 8 only with the probability of `docs/spells-non-damage.md` section 1, otherwise 7) selects the version of the effect, never the pose or the spirit sequence: the caster's pictures up to the spell start, the start frame and the MP-paid frame (except Fire Ball and Thunderbolt) are the same at every level. What changes [V, `data/summon_levels.json`, every spell at levels 0-8, the girl facing down, target 70 px away]:
- the **sound requests** of the effect change with the level (more launches, more hits): in steps of two levels (0-1, 2-3, 4-5, 6-7) for Fire Ball (0C), Flame (0E) and the Sylphid spell 13; between levels 0-3 and 4-7 for 00 02 06 07 0B 0D 11 14 1A 1F 25 26 (and 12 between 0-1 and 2-7); every spell has its own set at level 8;
- the **free frame** differs only for 05 (220 at levels 0-3, 240 from 4), 0B (310 at 0-3, 320 at 4-7) and, **at level 8, for 28 of the 42 spells**: the caster keeps the last spirit picture while the large version of the effect runs, so the hero is free 15 to 245 frames later (00: 290 instead of 170, 01: 400, 02: 380, 06: 360, 07: 435, 0E: 435, 11: 370, 12: 370, 13: 350, 21: 440, 22: 350, 29: 355; 1C is unchanged at 230); the spirit sequence, the spell start and the first 110 frames are identical [V, the girl's pictures of spells 00-0B compared at level 8 and level 2: the hold picture lasts longer].
- the **colour math** of eleven spells changes with the level (06, 0D, 0E, 13, 1A, 1F, 20, 23, 24, 25, 28: the fixed colour steps grow, for example 06 subtracts grey 1, 2, 3 ... at levels 0-3 and 2, 4, 6 ... above) (`color_math` of `data/summon_levels.json`: every write of `$2131`/`$2132`);
- **Seven spells at level 8 (0C, 0D, 10, 1F, 24, 25, 28)** start a blocking screen-effect routine (`$C1:28xx-3Bxx`, which waits in `$C1:2FE4` for the alternative NMI handler `$C1:2F5E` and for a free slot of an object pool of 0x20 entries) in frame 116-126 that the harness does not run: their level-8 timeline is not known (`stuck` in the data). Before it waits the routine writes `$2131` = 0x43 and `$2132` = 0xE0 (a colour-math step) [V].

**Several targets.** With two or three targets the pictures of the caster and the spirit, the phases and the free frame do not change; the sound requests of the hit (the id of the spell's hit sound) are issued once per target one frame apart: Earth Slide with three targets requests 0xB0 at frames 112, 113, 114 and 0x4A at 202, 203, 204; the saber-type ally spells with three targets request 0x48 at 165, 176, 176 [V, `sw/t2` and `sw/t3` rips of the girl facing down]. A cast on several allies includes the caster and is a self cast.

## 13. Output files

`tools/rip_summon.py` writes `OUTDIR/<label>/s<ID>_<dir>/frames.json` (`meta`: hero, spell, facing, hostile, foot point, frames, seconds, spell start, MP-paid frame, idle frame, sounds, element index, weapon row; `frames[]`: k, `st60`, `st1C`, anim, descriptor index, flags, script pointer, MP, HP, positions, sprite palette rows, the layers `caster`, `fx`, `hero` (caster and effect pieces together in OAM order), `weapon` (with `--baseline`), `target`, `other` (file, x, y relative to the foot point, size), the pieces with tile numbers, the PPU register writes) and the PNGs `c<n>.png`, `f<n>.png`, `h<n>.png`, `w<n>.png`, `t<n>.png`, `o<n>.png` (RGBA, colour 0 transparent, cropped). Options: `--hero`, `--spells`, `--dirs`, `--level N` (forces `+0x171`), `--weapon-row ROW`, `--baseline GLOVE_RIPDIR`, `--targets N`, `--target-dx/--target-dy`, `--ally-slot N --ally-dx/--ally-dy`, `--label`, `--quiet N` (frames without effect pieces before the rip stops, 45), `--hurt` (hero targets at half HP). Every frame also holds the targets' screen foot points `tfoot`, HP `thp`, status word `tstat`, their combat bytes `+0x180-0x1FF` when they change (`tbytes`) and the effect pieces with the slot that drew them (`own`). `tools/summon_report.py`:
- `merge` writes `data/summon_cast.json`: per spell the spirit, hostile flag, spell start, MP-paid frame, idle frame, phases, sounds, colour-math timeline, caster run list (girl facing down) and the spread over the three heroes and four directions; `trace` adds the graphics and palette loads and the banner window (uploads and the HDMA on/off frames);
- `release` writes the hero-free / MP-paid frame over a grid of target positions (`data/summon_release.json`: `grid` for Fire Ball and Thunderbolt, `ally_grid` for the six saber-type ally spells, `survey` for the other hostile spells);
- `levels` writes one magic level of every spell (`data/summon_levels.json`);
- `sounds` writes every sound request of a hero in the four directions, or with 2 / 3 targets (`data/summon_sounds.json`).

```
python3 tools/summon_report.py trace ROM STATE trace.json
python3 tools/rip_summon.py ROM STATE OUTDIR --hero girl --spells all --dirs down,up,right,left
python3 tools/summon_report.py merge OUTDIR trace.json data/summon_cast.json
python3 tools/summon_report.py release ROM STATE grid.json 0x0C                # or: 3,9 ally   /  0,1,2 survey
python3 tools/summon_report.py levels ROM STATE lv5.json 5
python3 tools/summon_report.py sounds ROM STATE girl.json girl                  # girl 3: three targets
```
The state must hold the three heroes (a ZSNES v143 state taken in play; the usual saves have no MP for the boy, the ripper tops up the MP). A full rip of the 42 spells for one hero and direction takes about 4 minutes on an idle machine.

## 14. Open questions

- The rule that turns the target position into the flight time of the Fire Ball and Thunderbolt effect objects (speed, homing, hit test of the effect scripts) was not decoded; `data/summon_release.json` is the measurement (10-pixel grid, four facings, steps of 5 frames). The same holds for the six saber-type ally spells cast on another hero (40-pixel grid). The flight path of those effect objects was ripped for one target position only (section 15).
- The seven level-8 casts that start a blocking screen effect (section 12); what that effect is (it writes `$2131` = 0x43, `$2132` = 0xE0 and waits for an object pool) and how long it lasts.
- The HDMA table of the banner window was not read (the harness does not run HDMA): the on/off frames are exact, the shape and gradient of the window are not.
- The operations `FB` (`JSL $02:BF1D`) and the velocity preset table of `8F`-`AA` beyond `A7` were read, not exercised; the colour-set table at `$D1:F600` was not dumped.
- Casts at levels 0-8 were swept for the girl facing down only; the other directions and heroes were compared at the default level.
- The pictures are for the glove group, plus the weapon pieces of the other seven weapon types (section 11); the weapon change spells 20 and 23 and the Mana Magic pair were not ripped.

## 15. When the spell lands [V]

Ripped with `rip_summon.py --quiet 120 --max 900 --hurt`: every spell cast by the girl facing down, against a monster 70 px above her (hostile spells), on herself and on the boy 40 px to her right (ally spells).

**Where the pieces come from.** After the spell starts the effect is drawn by three kinds of objects:
- the **target's own second list** (`+0xD0` of the monster or hero that is hit): the rock of Earth Slide, the gems, the ice, the acid, the flames, the bolts, the balloon, the heal sparkles on a hero target. Their places do not follow the target: when the monster shakes on the hit (its foot point moves by one pixel every other frame) the pieces stay put;
- **effect objects** that are not actors (OAM entries written outside any actor's lists): the fire balls of Fire Ball, the sparks of Thunderbolt, the saber spells' flight from the spirit to the hero, the beam of Lucent Beam, the orbs of Moon Energy;
- the **caster's second list**, for the spells cast on the caster (the buffs, the heals) and for Energy Absorb, whose drained light comes back to the caster.
In the sprite list the pieces on a hero target come before the effect objects, which come before the caster's own pieces: the target pieces are drawn in front [V, OAM indices at the spell start + 66, saber cast on the boy].

**When the spell takes effect.** The handler (`$C8:E6D4`) runs at the start for nearly every spell (section 7: MP paid), and status words are set there [V: Speed Down 0x0004, Silence 0x0080, Balloon 0x0100, Change Form 0x0800, Sleep 0x0010 appear in `+0x190` in the start frame]. The **HP** of the target changes later, together with the damage-number sound 0x35, when the effect script releases the pending value: frames after the start (girl, level 5, target 70 px away): 00 126, 01 141, 06 161, 07 131, 08 126, 0C 151, 0D 196, 0E 211, 10 111, 11 121, 12 121, 13 136, 1F 231, 24 201, 25 206, 28 186; Cure Water (0B) heals 99 frames after the start, on the caster and on another hero alike, Revivifier (21) 129. With several targets every target is hit one frame after the previous one (HP changes 237, 238, 239 for Earth Slide), and so are its pieces [V, three monsters].

**How long.** Frames from the start to the last piece: 00 115, 01 126, 02 206, 06 116, 07 126, 08 227 (the absorbed light returns to the caster at 134-227), 0C 145, 0D 136, 0E 161, 10 101, 12 74, 13 131, 14 116, 17 146, 18 61, 19 121, 1A 86, 1E 61, 1F 196, 24 196, 25 191, 26 106, 28 101; the ally spells 64-139 frames on another hero (the saber spells 139) and 65-345 on the caster (Cure Water 202, Revivifier 232, the weapon change of 20/23 345). Three spells end in a **status loop** that the status keeps drawing: Blaze Wall (11, the burning flames, with the drain sound 0x39 every 20 frames), Balloon (16, from frame 56) and the saber spells on another hero (the glow on the weapon).

The data of the remake (`data/databases/spell_land.json` of the Godot project, made by its `tools/pack_spell_land.py` from these rips) keeps, per spell and per variant (hostile or on the caster / on another hero), the run lists of the three layers on the ROM frame clock from the spell start, the caster-to-target offset of the rip, the HP frame and the end. Not recovered: how the effect objects of Fire Ball, Thunderbolt and the sabers home on a target at another place (only the 70-px path was ripped; the remake moves that path onto the actual line), the level-8 versions of the effects, and the other heroes' and directions' casts (the target pieces do not depend on the caster's facing; the effect objects do).
