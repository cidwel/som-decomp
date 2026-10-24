# Hero cutscene poses (animation codes 0x80-0xB5)

What the three heroes draw when an event plays `ACTOR_ANIM` / `ACTOR_ANIM_LOOP` with a code of 0x80 or more: the kneeling pose of the post-Dark-Lich scene, the head shake, the backward step, the pose of the ending and every other pose code that exists. Everything was obtained by running the original code from a save state (`tools/rip_hero_poses.py`, built on the harness of `docs/graphics.md` section 8) and by reading the disassembly. ROM data and pictures are not stored here: the pictures go to a directory outside the repository, the timing and displacement tables are in `data/hero_poses.json`, the post-fight event timeline is in `data/cutscene_lich_postfight.json`.

Tags: **[V]** executed in the interpreter and measured; **[C]** read from the disassembly only.

Tools:
- `tools/rip_hero_poses.py ROM STATE OUTDIR [heroes] [codes] [dirs] [modes]`: applies the command the way the VM does and records the pictures, durations, displacement, jump height and sound requests of every frame (format of `docs/graphics.md` section 7).
- `tools/hero_poses_report.py POSES_DIR OUT.json [md=1]`: merges the output into `data/hero_poses.json` and prints the table of section 3.
- `tools/hero_frames.py ROM pose CODE dir`: static lookup of the script of a pose code.
- `tools/lich_postfight.py ROM STATE OUT.json`: runs event 0x42D (the Dark Lich post-fight event) and writes its timeline.

## 1. How a pose code is looked up

- `ACTOR_ANIM a b` sets `obj+0x1C` = 0x40 (state), `obj+0x11` = b (code), `obj+0x42` = 1 (busy); `ACTOR_ANIM_LOOP` sets state 0x30 and no busy flag (`docs/cutscene-engine.md` section 13.4) [V].
- The per-frame animation routine (`$C0:F4CB`, `$C0:F54C-F585`) reads the script pointer from a word table. With a non-zero state byte and a code of 0x80 or more it uses the **ordinary-state table** `$D1:37CC` (`obj+0x75`) at index `((code & 0x7F) * 3 + facing) * 2`, facing 0 up, 1 down, 2 side. With a code below 0x80 and a non-zero state it uses the weapon table `$D1:3040 + 240 * type` (`obj+0x65`): code 0 is the weapon swing. With state 0 it uses the ordinary table with the full code [C; V: the script the harness runs is the one at that address, `tools/hero_frames.py pose`].
- Left uses the right-facing script mirrored (frame flip XOR, displacement negated) [V, as in `docs/graphics.md` section 5].
- The script format is the one of `docs/graphics.md` section 5 (entries of `b0, b1`: flips and duration, frame index; operations with bit 7). A pose animation lasts from its first step to the end operation `0xFF` [V].
- **End of the script** (`$C0:F90B`, operation 0xFF) [C, V]: state 0x40 clears the state, the code, the busy flag and the velocity (the hero goes back to the idle pose after the last step). **State 0x30** restarts the script from its first entry as long as the event VM is running (`$D0` != 0) and ends it otherwise: a looping pose therefore repeats its script for as long as the event goes on, and in a one-picture script it simply holds the picture. The harness holds `$D0` = 0x82 to reproduce this.
- A hero draws the picture with the **weapon it carries**: the frame descriptor table depends on the weapon type (`obj+0x2A` = `0x2040 + 0x200 * type`). The tables and the timing are identical for all weapon types, only some pieces differ (a sword, an axe, a spear ... in the hand or on the ground). The pictures recorded here are those of the glove group (weapon rows 0-8, no weapon piece) [V: 0x80, 0x8A, 0x9D, 0x9B, 0xA8, 0xA9, 0xAB, 0x8C, 0x94, 0x86 compared for rows 0, 7 (equal) and 16, 25, 34, 43, 52, 61 (differ by the weapon pieces)].
- The three heroes use the same script, so timing and displacement are equal; the pictures differ (their own piece lists) and in codes 0x85, 0x94, 0x9F, 0xA0 and 0xAE the number of distinct pictures differs because some pieces (an emote effect, the hair) change in one hero only [V].

## 2. Measured quantities

Frames are video frames (60.0988 Hz). The recording starts at the first frame in which the script has moved off the previous pose; before it the old picture stays for `latency_frames` frames (1 for most codes) [V]. Displacements are the actor world position at every frame, plus the step of the frame in which the script ends (the velocity is cleared after it is applied, `end_move`: 1 px for 0x8C, 3 px for 0x8A); "right" moves along +x, "left" is its mirror, "up" -y, "down" +y. A looping pose that moves leaves the screen and wraps at the map edge (docs/cutscene-engine.md 13.4), so the cycle of a moving pose is taken from the same script run once (`cycle` in the JSON).

## 3. Table of the 54 codes [V]

Frames once = length of the script in state 0x40 for up / down / side (equal for the three heroes). The steps are (frame index, frames) of the down script of the girl; frame indices are entries of the frame descriptor table, not pictures. Move = net actor displacement of one pass (up / down / side). Jump = largest `obj+0x45`.

| code | frames once (up/down/side) | steps (frame index, frames), down | move per cycle px (up / down / side) | jump | sounds (frame, id) |
|---|---|---|---|---|---|
| 0x80 | 20/20/20 | 240:5 237:10 240:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x81 | 30/30/30 | 243:5 244:5 245:5 246:5 245:5 244:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x82 | 40/40/40 | 15:5 16:5 17:5 18:10 17:5 16:5 15:5 | 0,0 / 0,0 / 0,0 | 0 | 4:0x8B 24:0x8B |
| 0x83 | 1/1/1 | 240:1 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x84 | 20/20/20 | 39:5 40:10 39:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x85 | 20/20/20 | 234:5 235:5 236:5 235:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x86 | 65/65/65 | 27:5 27:5 27:5 50:5 50:5 70:5 39:5 40:5 62:15 49:5 50:5 | 0,55 / 0,-55 / -55,0 | 15 |  |
| 0x87 | 65/65/65 | 55:5 55:5 56:15 137:20 67:5 66:5 65:10 | 10,0 / 10,0 / 10,0 | 10 |  |
| 0x88 | 20/20/20 | 224:5 229:10 224:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x89 | 30/30/30 | 243:5 244:5 245:5 246:5 245:5 244:5 | 0,-60 / 0,60 / 60,0 | 0 |  |
| 0x8A | 40/40/40 | 15:5 16:5 17:5 18:10 17:5 16:5 15:5 | 0,-120 / 0,120 / 120,0 | 0 | 4:0x8B 24:0x8B |
| 0x8B | 20/20/20 | 39:5 40:10 39:5 | 0,-20 / 0,20 / 20,0 | 0 |  |
| 0x8C | 20/20/20 | 39:5 40:10 39:5 | 0,20 / 0,-20 / -20,0 | 0 |  |
| 0x8D | 65/65/65 | 27:5 27:5 27:5 50:5 50:5 70:5 39:5 40:5 62:15 49:5 50:5 | 0,55 / 0,-55 / -55,0 | 15 |  |
| 0x8E | 100/100/100 | 29:5 29:5 56:5 56:5 56:5 56:5 55:10 55:5 56:15 137:20 67:5 66:5 65:10 | -20,0 / -20,0 / -20,0 | 15 |  |
| 0x8F | 80/80/80 | 55:5 56:10 55:5 55:5 56:15 137:20 67:5 66:5 65:10 | 10,0 / 10,0 / 10,0 | 10 |  |
| 0x90 | 60/60/60 | 55:5 56:15 137:20 67:5 66:5 65:10 | 10,0 / 10,0 / 10,0 | 10 |  |
| 0x91 | 20/20/20 | 37:5 37:15 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x92 | 15/15/15 | 214:5 214:10 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x93 | 25/25/25 | 65:5 66:5 67:5 66:5 65:5 | -25,0 / -25,0 / -25,0 | 0 |  |
| 0x94 | 115/115/115 | 180:5 180:15 118:5 119:5 120:5 121:5 122:5 123:5 124:5 125:5 49:20 49:20 37:15 | 0,0 / 0,0 / 0,0 | 0 | 19:0x2D |
| 0x95 | 20/20/20 | 85:5 86:10 87:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x96 | 499/499/499 | 240:5 210:5 240:5 210:5 240:5 210:5 240:5 210:5 240:5 240:20 240:20 240:414 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x97 | 5/5/5 | 69:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x98 | 5/5/5 | 69:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x99 | 5/5/5 | 69:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x9A | 5/5/5 | 69:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x9B | 140/140/140 | 51:5 51:20 52:10 53:10 52:5 53:5 52:5 53:5 52:5 53:5 52:20 54:15 46:10 54:5 45:5 51:10 | 0,0 / 0,0 / 0,0 | 0 | 44:0x9D |
| 0x9C | 15/15/15 | 68:5 68:10 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x9D | 5/5/5 | 49:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0x9E | 55/55/55 | 49:5 50:5 50:5 50:5 50:5 50:5 50:5 138:5 139:5 140:5 141:5 | 0,-85 / 0,85 / 85,0 | 30 |  |
| 0x9F | 135/135/105 | 30:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 28:10 48:10 48:10 47:10 | 0,-20 / 0,-20 / 40,20 | 20 |  |
| 0xA0 | 140/140/140 | 30:5 30:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 30:20 30:20 | 0,-445 / 0,-445 / 0,-445 | 0 | 99:0x57 |
| 0xA1 | 40/40/40 | 28:10 48:10 48:10 47:10 | 0,-40 / 0,-40 / 40,0 | 20 |  |
| 0xA2 | 125/125/125 | 139:5 138:5 141:5 140:5 139:5 29:5 29:5 56:5 56:5 56:5 56:5 55:10 55:5 56:15 137:20 67:5 66:5 65:10 | -20,0 / -20,0 / -20,0 | 127 | 24:0x50 |
| 0xA3 | 320/320/320 | 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 219:5 219:15 220:20 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA4 | 15/15/15 | 68:5 68:10 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA5 | 40/40/40 | 216:5 216:5 218:10 216:10 218:10 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA6 | 5/5/5 | 215:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA7 | 45/45/45 | 217:5 217:20 217:20 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA8 | 20/20/20 | 210:5 240:5 210:5 240:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xA9 | 40/40/40 | 204:5 240:5 205:5 240:5 204:5 240:5 205:5 240:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xAA | 20/20/20 | 70:5 70:5 39:10 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xAB | 5/5/5 | 180:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xAC | 100/100/100 | 29:5 29:5 56:5 56:5 56:5 56:5 55:10 55:5 56:15 137:20 67:5 66:5 65:10 | -20,0 / -20,0 / -20,0 | 15 |  |
| 0xAD | 250/250/250 | 224:5 224:20 161:20 160:5 68:5 62:5 62:20 62:20 62:20 62:20 161:10 160:20 160:20 160:20 160:20 160:20 | 0,-15 / 0,-15 / 0,-15 | 0 | 24:0x34 |
| 0xAE | 125/125/125 | 30:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 30:5 31:5 32:5 33:5 32:5 31:5 | 0,20 / 0,20 / 0,20 | 0 |  |
| 0xAF | 5/5/5 | 240:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB0 | 5/5/5 | 248:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB1 | 499/499/499 | 240:5 210:5 240:5 210:5 240:5 210:5 240:5 210:5 240:5 240:20 240:20 240:414 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB2 | 20/20/20 | 240:5 237:10 240:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB3 | 5/5/5 | 0:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB4 | 20/20/20 | 0:5 3:5 0:5 3:5 | 0,0 / 0,0 / 0,0 | 0 |  |
| 0xB5 | 20/20/20 | 0:5 3:5 0:5 3:5 | 0,0 / 0,0 / 0,0 | 0 |  |

Reading the pictures by eye (girl; other heroes analogous):

| code | picture |
|---|---|
| 0x80 | standing, facing the direction, one picture for 20 frames (the pose the VM holds with a loop) |
| 0x81 / 0x89 | stepping in place, six pictures in 30 frames; 0x89 additionally moves the actor 2 px per frame |
| 0x82 / 0x8A | running in place, seven pictures in 40 frames, sound 0x8B (footstep) at frames 4 and 24; 0x8A moves 3 px per frame in the facing direction (120 px in 40 frames) |
| 0x83, 0x88, 0x84, 0xB2 | standing variants (1 picture, or a 3-picture sway of 20 frames) |
| 0x8B / 0x8C | slow walk (3 pictures, 20 frames): 0x8B moves 1 px per frame **forward** (20 px), **0x8C 1 px per frame backwards** (the step back of the Dark Lich scene: 20 px in 20 frames, facing stays) |
| 0x85 | an emote ("!") effect over a hopping pose, 20 frames |
| 0x86, 0x8D | knocked down and back: jump of up to 15 px, 55 px of travel away from the facing, 65 frames, rolling over and getting up |
| 0x87, 0x8F, 0x90 | collapsing into a ball and getting up (65, 80, 60 frames), a 10 px shift, jump 10 |
| 0x8E, 0xAC, 0xA2 | thrown backwards 20 px with a jump of 15 (100 frames); 0xA2 is the same with a larger initial arc (125 frames, jump 127) |
| 0x91, 0x92, 0x97-0x9A, 0xA6, 0xAB, 0xB0, 0xB3, 0xAF | one-picture poses held for 5-45 frames (bowed / turned head poses, 0xAB = head turned to the side, held; 0xAF = two standing pictures) |
| 0x93 | stumbling 24 px to the left (5 pictures, 25 frames) |
| 0x94 | a sequence with a flash effect (115 frames, sound 0x2D at frame 19) |
| 0x95 | a three-picture leap-like pose of 20 frames |
| **0x9B** | **kneeling and crying: crouch (25 frames), then a 140-frame loop of nine pictures that raise and lower the hands, sound 0x9D at frame 44** |
| **0x9D** | **crouching on one knee with the head down: one picture held (5 frames per pass); this is the pose the post-Dark-Lich event gives the girl** |
| 0x9C, 0xA4 | arms spread, one picture |
| 0x9E | a 55-frame leap of 84 px with a jump of 30 |
| 0x9F, 0xA0, 0xAE | back view with bobbing, long run (105-140 frames); 0xA0 sound 0x57 at 99 |
| 0xA1 | a 40-frame leap of 40 px with a jump of 20 |
| 0xA3 | a 320-frame bowed pose (three-step 20-frame cycle) |
| 0xA5, 0xA7 | head-bowed pictures held 40 and 45 frames |
| 0xA8 | **standing, small head movement (two pictures alternating, 20 frames)**; used by all heroes in the ending |
| 0xA9 | **shaking the head: eight pictures in 40 frames (head turns left, centre, right, centre, twice)** |
| 0xAA | bowed / looking down, 20 frames |
| 0xAD | a 250-frame sequence (kneeling, then raising the arms and waiting) with sound 0x34 at frame 24, moves 15 px up |
| 0xB4, 0xB5 | four-picture 20-frame shuffle |
| 0x96, 0xB1 | never end in state 0x40 (they loop on a one-picture hold): NPC-style codes |

Not hero poses: 0x81 ... also occur with NPC and boss actor ids in other tables (`other` events of section 4), those codes use the object's own table.

## 4. Where the events use them [C]

Static scan of all 2,048 events (`ACTOR_ANIM` 0x31 = A, `ACTOR_ANIM_LOOP` 0x34 = L) for actor arguments 0-3 (the controlled hero or heroes 1-3). Event ids in hex.

| code | events (hero actors) |
|---|---|
| 0x80 | 002 006 007 106 1B2 1CE 1FD 22E 250 400 42D 4E1 4E8 55E 592 5F8 6F8 780 781 |
| 0x82 | 167 5F8 |
| 0x83 | 051 558 |
| 0x87 | 5F8 |
| 0x88 | 106 |
| 0x89 | 28A 4E8 4FD |
| 0x8A | 42D 4A4 4FD 558 |
| 0x8B | 1BE 400 4FD 5F8 |
| 0x8C | 060 10C 133 167 193 1B2 29B 3DE 4E1 4E6 4E8 581 59D |
| 0x8D | 083 258 293 529 52B 558 592 |
| 0x8E | 42D |
| 0x94 | 581 |
| 0x95 | 6FB |
| 0x99 | 555 |
| 0x9B | 002 |
| **0x9D** | **106 42D** |
| 0x9E | 4E8 6FC 6FD 6FE |
| 0x9F | 6F7 |
| 0xA0 | 106 |
| 0xA2 | 0F7 101 |
| 0xA3 | 33B 33C 33D |
| 0xA4 | 127 5F8 |
| 0xA5 | 1F6 29B |
| 0xA6 | 22E 28B 3AA 592 5F8 |
| 0xA7 | 250 28A 4E2 4E8 559 55E 5F8 |
| 0xA8 | 056 058 059 05A 05E 581 |
| 0xA9 | 057 05B 05C 05D 05F |
| 0xAA | 1CE 2FD 5F8 7F5 7F6 7F7 |
| 0xAB | 41B 4FD 558 5F8 |
| 0xAD | 103 |
| 0xAE | 10C 526 669 |
| 0xB0 | 1B2 |

Codes 0x81, 0x84-0x86, 0x96, 0xAF, 0xB1, 0xB2 are only used with other actor numbers (NPCs and objects).

## 5. The post-Dark-Lich event (0x42D) [V]

The event started by the death of the Dark Lich (map record 2 of maps 245/246, word 0x442D; run from a save state in map 246 with flag 0x4E set to 6 by `tools/lich_postfight.py`; `data/cutscene_lich_postfight.json`). Heroes: actor 1 boy, 2 girl, 3 sprite. Times in frames from the start of the event (the VM steps every fifth frame). The girl's poses:

| frame | s | what |
|---|---|---|
| 0 | 0.00 | freeze, first text block, wait for a button; flag 0x4E 6 -> 7; raw sound command 0x80 (event 0x748); formation event 0x47D (boy 16 px left, sprite 16 px right, all face up) |
| 153 | 2.55 | girl: `ACTOR_ANIM_LOOP` 0x80 (standing); music 0x38 (event 0x738); text; wait 32 ticks |
| 358 | 5.96 | **girl: `ACTOR_ANIM_LOOP` 0x8A (running in place, 3 px per frame)**, `WAIT_IDLE`, 2 ticks: she runs **from (261, 437) to (261, 395), 42 px up in 14 frames (3 px per frame)**, footstep sounds 0x8B |
| 373 | 6.21 | girl: loop 0x80 again, standing at (261, 395); two text blocks with 32-tick waits |
| 553 | 9.20 | `ACTOR_WALK actor 2 up 0`: stop (state 0, ordinary idle) |
| 753 | 12.53 | **girl: `ACTOR_ANIM_LOOP` 0x9D = the kneeling pose** (facing up, at (261, 395)); wait 48 ticks (240 frames), three text blocks (a press each) |
| 1053 | 17.52 | music 0x31 (event 0x731); frame 1058: `MAP_CHANGE` transition 47, fade out; the pose ends with the map change |
| 1115 | 18.55 | map 246 reloaded, party on the start tile (280, 426); event 0x480 (formation 0x47F): shake (`SCREEN 2`) and sound 0x16 (event 0x784) |
| 1569 | 26.11 | **sprite: `ACTOR_ANIM` 0x8E (thrown backwards), 100 frames**, from (296, 426) to (276, 426), jump 15; then the dialogs, boy and girl turn to face each other (right / left), the sprite turns down, flag 0x4E 7 -> 8, event ends at frame 2164 |

So the real kneeling is **one picture** (code 0x9D, a crouch with the head down) shown instantly at frame 753 and held for the rest of the scene by the loop state; there is no kneeling-down transition in this event. The only cry-like animation in the table is code 0x9B (never used by the post-fight event; its only user is event 0x002).

## 6. The other scenes of the Lich and the ending

- Dark Lich arena scene (`docs/cutscene-dark-lich.md`): the girl's step back is 0x8C (20 frames, 20 px backwards, 3 pictures), then 0xA9 (the head shake, 40 frames, 8 pictures) from the canned event 0x05C, then the held pose 0x80.
- Ending (`docs/cutscene-ending.md`): all heroes 0xA8 (20 frames, two pictures alternating, followed by a 40-frame wait) and 0xAB (a held pose in the looping state, set at frame 1058 for the boy and the girl); the girl's 0xA9 shake at frame 20509; 0xA8 again at the other canned events (0x056, 0x058-0x05A).

## 7. Open questions

- The pieces of the **weapon** in each pose (sword on the ground in the kneeling pose etc.) were not ripped: only the glove group (no weapon piece) is in the images; the tables are equal for all weapon types, the descriptor table is `0x2040 + 0x200 * type`.
- The operations of the pose scripts (`83`, `86`, `88`, `99`-`9E`, `A7`, `AA`, `F9` ... with arguments) were not decoded; the effects that were measured are the displacement, jump height and sound requests of the table.
- Position values of 0xA0 (a long run) wrap at the map edge in the harness and are not meaningful beyond the first 100 frames; looping poses of 0x96 and 0xB1 have no end.
- Pose codes of 0xB6 and above and the codes below 0x80 in state 0x40 (weapon table, code 0 the swing) were not ripped.
- Facing left of 0x9F is not the mirror of right in the harness table (105 frames for the side script versus 135 for up/down): the side script is a different, shorter script; left is its mirror.
