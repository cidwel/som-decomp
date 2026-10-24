# Hit reactions as played: heroes and monsters in the frame loop

Tags as in `docs/rom-combat.md`: **[V]** measured by running the real frame `$C0:B08C` (`tools/hurt_loop.py`, on a ZSNES save state, `GloveSim` harness), **[C]** read from the disassembly. A "hit" below is bit 0 of the hero's hit mask `E059` (monster slot 3 hit this hero), which the combat tick resolves with the real routines `$C0:4F7B`...; the amount is the normal physical or magic result of `docs/rom-combat.md`. Frames are 60.0988 Hz video frames; heroes and ordinary monsters react on their 5th-frame combat tick, so every time below has a granularity of 5 frames.

## 1. A hero is hit [V]
- The hit is resolved at once into the pending damage `E1F1`; the hero's next combat tick (within 5 frames) applies it: HP drops, the damage number is created, the hero enters the hurt state (`E01C = 0x40`, `E011 = 0x8D`, status word bit 0 `E190 & 1` for one tick) and whatever it was doing (a swing, a charge, walking) is cut.
- Timeline of a single hit (hit flag at frame 10, HP drop at frame 13): the hurt state lasts **110 frames (1.83 s)** (frames 13-123). Pictures (frame descriptor numbers, girl facing down): 54 for 15 frames, 100 for 10, 140 for 5, 78 for 5, 80 for 5, 124 for 15, 98 (lying) for 50, 100 for 5, then 224 (getting up) for 5 after the state byte has returned to 0, then the standing picture (full table in section 8).
- Knockback: starts the frame after the HP drop, 55 px opposite to the facing in 40 frames (`docs/hero-movement.md` section 10). The jump (`E045`): +2 per frame for 5 frames, +1 for 5, hold 15 for 6, -1 for 5, -2 for 5; airborne 25 frames, peak 15 px.
- Sounds: the damage application `$C0:4157` requests the hit sound of the defender `E1AF` (heroes 0x50, parameter 0x0F, pan from the x position) and the hurt animation script requests 0x4F (parameter 0, pan 0x44). A lethal hit requests 0x50 twice instead.
- A hit amount of 0 (a monster hits a hero with more defense) still starts the reaction when the hit connected; a miss (evade) starts nothing and shows no number (`docs/damage-counter.md` section 2). Heroes never show a "0".

## 2. Hits during the hurt state are not lost [V]
- A hit that lands while the target is hurt is resolved immediately (RNG, status roll) and **added to `E1F1`**; the combat tick does not apply `E1F1` while the hurt state runs. When the state ends the sum is applied in one go (capped at 999) and a **new complete hurt cycle** starts.
- Hero hit at frames 10, 30, 60, 90 (10 damage each): HP 718 -> 708 at frame 13, `E1F1` = 10, 20, 30 while hurt, HP 708 -> 678 at frame 118 and a second 110-frame reaction until frame 228.
- A passive monster hit by a glove swing every 25 frames: HP changes only every 105 frames (`E1F1` 6, 31, 37, 62, 68, 93 in between), each time by the whole sum. So fast weapons add up fully on a staggered monster, and a killing blow during the stagger takes effect when the stagger ends.
- Whether a particular contact can land during the reaction depends on the body box: it is empty in some frames of the hurt animation and a 12 x 12 box while lying (`docs/glove-attacks.md` section 2.6).

## 3. Statuses and hits [V]
Hero with one status, one hit (HP loss as for a normal hit unless noted):
| status | effect on the hit |
|---|---|
| 0x0004 slow, 0x0080, 0x0200 pygmy, 0x0800, 0x1000, 0x2000 poison | normal hit and reaction (poison also keeps draining) |
| 0x0010 asleep | damage taken, **the status is cleared** (`$C0:5119`), no reaction (`E01C` stays 0) |
| 0x0020 frozen, 0x0040 petrified, 0x0100 balloon, 0x4000 engulfed (mask `0xC160`) | **damage taken, no reaction**, the status stays |
| 0x0400 | no hit is resolved at all (HP unchanged) |

## 4. Dying [V]
A hit that takes the HP to 0 sets bit 1 of `E190` and the countdown `E1B4 = 32`, plays the knocked-back pose 0x8E (jump 15 px; section 8 measured 30 px sideways in 30 frames, to the left of the screen unless the hero is mirrored, not 20 px) and the hero is held for **160 frames (2.7 s)** (`E1B4` drops by 1 per combat tick); the KO flag `0x8000` and the hand-over to the next hero come at the end. The death hit sound 0x50 is requested twice.

## 5. Monsters
- The hit sound of a monster is its own `E1AF` (`tools/hurt_loop.py sounds`): 0x35 for most, 0x36 ids 06 07 08 0B 1A 27 38 4F, 0x37 ids 01 10 24 29 31 32 47, 0x38 ids 20 2E 3F, 0x50 for id 0x56, 0 for 0x54 and 0x55.
- Hurt state length, knockback and death: `docs/rabite.md` section 7, `docs/monster-3.md`, `docs/monster-13.md`; the stagger accumulation of section 2 holds for every monster.

## 6. Other findings
- No regeneration: 3600 frames (60 s) without a hit leave HP unchanged [V].
- A hit that arrives while the hero is casting (`E01C = 0x40`, `E060` non-zero) was consumed without any damage in three attempts (hit flag set at frames 5, 70, 120 of a cast); a flag set at the very end of the cast stayed pending until the cast ended and then did no damage either, while the same hit after the cast hurt normally [V, small sample; the reason was not traced].
- Forced crits (`E1AE` high nibble, Moon Energy) skip both the crit roll and the weapon-gauge reduction: 300 random hits with high nibbles 0..2, gauge values and flat guard on the real routines matched `phys_model.py` (`tools/validate_phys.py` itself only randomises the low nibble) [V]. The flat guard (`E1B1` bit 4) is applied after the defense roll, which is therefore still drawn from the RNG.
- Hero spell availability: the hero objects of the save states carry spell levels for seven of the eight spirits for the girl (Shade 0) and the boy-less sprite (Lumina 0), and none for the boy; the menu routine that filters the spells per hero was not found (`E1C4-E1C7` are not read by it) [open].
- Items on the field: the heal numbers show the pending amount, not the HP actually gained (`docs/damage-counter.md`).

## 7. Reproduce
```
python3 tools/hurt_loop.py "$R" "$S"            # all sections
python3 tools/hurt_loop.py "$R" "$S" hero lump  # chosen sections
python3 tools/godot_vectors.py "$R" vectors.json 200   # model results for a port's tests
```

## 8. Frame-by-frame capture [V]
`tools/rip_hero_hurt.py ROM STATE OUTDIR [hero,..] [dir,..] [JSON]` runs the `hurt_loop.py` harness (GloveSim, hit mask `E059` bit 0 set before video frame 10, defence 20, hero at screen 128,112, the dummy monster far to the right, no solid tiles and no party window as in `rip_hero_anims.py`) with the PPU capture of `rip_hero_anims.py`, for each hero (boy, girl, sprite) and facing (up, down, right; left was run once and is the mirror: same pictures with the flip bit, displacement x negated). Two runs per case: **hit** (400 HP, 130 frames) and **lethal** (5 HP, until the harness stops, 173 frames = hit at 13 + 160 held). Every frame it stores the picture the game draws (OAM + VRAM + CGRAM, list 90 = the body; the ground shadow, the damage number and the HUD marks of list D0 are left out; the jump lift `+0x45` is subtracted so the picture is the pose), the actor world x/y relative to the start, `+0x45`, `E011`, `E01C`, the descriptor byte `+0x26`, HP and the sound requests with their frame. PNGs go to OUTDIR (`<hero>/<hero>_<nnn>.png`, 26 distinct pictures per hero shared by all facings and both runs, one canvas size per hero, never in the repo); `data/hero_hurt.json` holds run-length lists `[value, frames]` (`pictures`, `descriptor`, `dx`, `dy`, `z`, `e011`, `e01c`, `hp`), `sounds` = `[frame, id, param, pan]`, the damage number frame span and a `summary`, no pixels. The three heroes give the same timing, displacement, jump, states and sounds; only the pictures differ.

Data reproduces the known numbers: HP drop at frame 13, hurt state (`E01C = 0x40`) 110 frames (13-123), knockback 55 px opposite to the facing in 40 frames (frames 14-53), jump peak 15, airborne 24 frames with non-zero height (25 from take-off to landing), two sounds at frame 13, in all 9 hero/facing cases.

Picture sequence of the hit run (descriptor `+0x26` x frames, identical for the three heroes; the pictures differ per hero), frame 0 on:
| step | up | down | right (left = mirror) |
|---|---|---|---|
| standing before the hit (13 frames: hit flag at 10, HP drop at 13) | 82 x13 | 78 x13 | 86 x13 |
| hurt, struck | 56 x15 | 54 x15 | 58 x15 |
| | 96 x10 | 100 x10 | 92 x10 |
| | 142 x5 | 140 x5 | 144 x5 |
| | 82 x5 | 78 x5 | 86 x5 |
| | 84 x5 | 80 x5 | 88 x5 |
| | 126 x15 | 124 x15 | 128 x15 |
| lying | 94 x50 | 98 x50 | 90 x50 |
| | 96 x5 | 100 x5 | 92 x5 |
| getting up (state byte already 0, `E011` = 0 for one frame) | 226 x5 | 224 x5 | 228 x5 |
| standing | 82 | 78 | 86 |

The state is `E011 = 0x8D` (141) for frames 13-122 (110 frames), then 0 for one frame, then 3. Each facing uses 8 distinct pictures in the hit run (the standing pose is reused after the first three hurt steps); the first hurt step of right (descriptor 58) is the same picture as the first hurt step of the lethal run (index 8 of every hero).

Displacement table of the hit run, relative to the start (dx = 0 for up and down, dy = 0 for right; sign: up +y is down the screen, the hero is thrown opposite to the facing: up -> +y, down -> -y, right -> -x, left -> +x): frames 14-18 3 px per frame (15), frames 19-23 2 px per frame (25), frames 24-53 1 px per frame (55), then still. Jump `+0x45`: 0 until frame 13, then 2, 4, 6, 8, 10 (frames 14-18), 11, 12, 13, 14 (19-22), 15 for 6 frames (23-28), 14, 13, 12, 11 (29-32), 10, 8, 6, 4, 2 (33-37), 0 from frame 38. The damage number is drawn in frames 18-115. HP drops 400 -> 390 at frame 13.

Lethal run (5 HP; sound 0x50 twice at frame 13 with pan 128 and 136, no 0x4F): HP 5 -> 0 at frame 13, `E011 = 0x8E` (142) and `E01C = 0x40` for 160 frames (13-172). Pictures: facing picture for 13 frames, descriptor 58 for 10 frames, 112 for 20, then 110 (lying) for the remaining 130, the same three pictures for every hero facing (indexes 8, 9, 10). The displacement is purely horizontal whatever the facing: 1 px per frame for 30 frames (frames 14-43), 30 px in all (towards the left of the screen; +30 when the hero is mirrored, i.e. faces left). The jump has no plateau: 2, 4, 6, 8, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 8, 6, 4, 2 (19 frames, peak 15).
