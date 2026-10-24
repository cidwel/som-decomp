# Animation phase across commands of the ordinary monsters

Tags: **[V]** executed: the real 65816 code ran in `tools/cpu65816.py` (the whole per-frame routine `$C0:B08C` of a monster in slot 3 on a ZSNES save state, with the NMI handler that uploads tiles and palettes and DMAs the OAM) and the result was measured; **[C]** read from the disassembly. Evidence: `data/monster_anim_phase.json` (`tools/monster_anim_phase.py`). Method and harness as `docs/monster-3.md` (second monster) and `tools/ai_sim.py` / `tools/rip_monster_anims.py`; the animations themselves are in `docs/monster-animations.md`. No ROM bytes are stored here. Seconds = frames / 60.0988.

## 1. Answer

- **The engine does not restart a monster animation when a new command is issued.** A restart (first picture of the animation, first tick) happens only when (a) the *key* of the animation changed, the key being the pair (facing byte `obj+0x10`, animation id `obj+0x11`), or (b) the animation script ended (looping animations wrap), or (c) a state started or ended (pose `0x40`, swing `0x80`, hurt `0x40` with id `0x88` / `0x89`). A command that issues the **same animation id with the same facing** continues the animation exactly where the previous command left it. [V, C]
- The animation advances in **ticks of 5 frames** (12.02 per second), on the same frames as the AI step of the monster (`frame % 5 == slot - 3`). One tick = one pass of the animation interpreter `$C0:F534`. Pictures last a whole number of ticks. A command of 5 frames therefore shows one tick of the animation. [V: the interpreter ran on the frames `f % 5 = 0 / 1 / 2` in slots 3 / 4 / 5, 96 of 96 passes each]
- **Chobin Hood advance / retreat step** (`E4 / E6 02 05` = `C1 dir, animation 2, flag 5`: 5 frames, 10 px): the side animation 2 is a 20-frame cycle of four 5-frame pictures. The steps show picture 0, 1, 2, 3 of the cycle on four consecutive steps (frame indices `3, 4, 3, 5`), then 0 again; the animation is restarted only after another animation id or facing was used in between. The picture 0 of animation 2 is the same picture as the stand (animation 0), so a port that restarts the animation at every command shows the same static picture on every step while the monster slides 10 px: this is the symptom of the remake. The port must keep the phase. [V, section 4]

## 2. Where the engine decides [C, confirmed by the runs of section 4]

| address | what |
|---|---|
| `$C1:DADD-DB26` | command `C1` (hop / turn): `obj+0x67 = 0x80`; the old word `obj+0x10/0x11` is saved; `obj+0x11` = command byte 2 (animation id); `obj+0x62` = flag byte (frames, counted down every frame), or with flag 0 `obj+0x64 = 0x80` (until the script ends); `obj+0x10` = facing from the direction code (`$C1:DB27`: codes 1, 5, 9 -> 0x02 right, 2, 6, 10 -> 0x82 left, 4 -> 0x01 down, 8 -> 0x00 up). At `$C1:DB0A`: if the **new word equals the old word nothing else happens** (no restart, the velocity is kept); otherwise `obj+0x30 = 0x00FF` (restart request) and the velocity `obj+6 / obj+8` is cleared. |
| `$C0:F534-F53F` | animation interpreter, per tick: `obj+0x10/0x11` (16-bit word) is compared with `obj+0x30` and stored there. **Different: restart** (`$C0:F541`): picture counter, flags cleared, script pointer taken from the table of the object state (`$C0:F550-F585`: state 0 -> ordinary table with the id, otherwise attack table / `id & 0x7F`), first entry fetched in the same tick. **Equal**: `$C0:F590`: if the duration counter `obj+0x12` is not 0 it is decremented and the tick ends (same picture), else the next script entry at `obj+0x16` is fetched (`$C0:F59C-F5B2`: `obj+0x16` = pointer after the entry; the entry shows its picture for `counter + 1` ticks, counter = `obj+0x12`). |
| `$C0:F90B`, `$C0:F8EE` | script end (opcode `FF`): in state 0 `obj+0x30 = 0xFF` and the interpreter is re-entered at once (`JMP $F52D`): the loop restarts in the **same tick**, so the cycle is exactly `sum(picture ticks)` ticks long. In a non-zero state the state ends (`$C0:F955`: state, animation id cleared) and `obj+0x30 = 0xFF`. |
| `$C1:DA00`, `$C1:DA34` | pose command `40 n`: `obj+0x11 = n`, state `0x40`, `obj+0x30 = 0xFF` (always restarts, even if the id and facing are those of the running animation), velocity cleared. The swing command `02` (state `0x80`) and the hit reactions (state `0x40`, ids `0x88`, `0x89`) are states too. |
| `$C0:F8B3` -> `$C1:D942` | the command dispatcher runs only while `obj+0x62`, `obj+0x64`, `obj+0x0A` are 0 (command finished, not in a jump), so a new command is accepted only after the previous one ran out (in every run each command began on the tick after the previous one ended). |

Nothing else writes the key for state-0 animations, so the whole decision is: *restart iff the (facing, id) word differs from the one seen at the previous tick, or the script wrapped, or a state interrupted*.

## 3. The rule for a port

State to keep per monster: `key` (facing byte, animation id; last value seen by the interpreter), `n` (ticks since the last restart), `tick_acc` (time accumulator). Everything else (script pointer, frame index, remaining duration of the picture) is a function of `(key, n)`.

```
TICK = 5 / 60.0988                       # seconds; same accumulator as the AI step
func update(delta):
    tick_acc += delta
    while tick_acc >= TICK:
        tick_acc -= TICK
        ai_step()                         # may issue a command: it only sets facing / animation id / timer / velocity
        animation_tick()

func animation_tick():
    if state != 0:                        # pose 0x40 / swing 0x80 / hurt: own script, played from its start
        play_state_script(); key = NONE   # NONE forces a restart when state 0 returns
        return
    k = (facing_byte, anim_id)            # right 0x02, left 0x82 (mirror), down 0x01, up 0x00; diagonal codes use the horizontal facing
    if k != key: key = k; n = 0 else: n += 1
    picture = cycle[k][n % len(cycle[k])]  # the ripped animation: pictures of the 5-frame ticks of one period
```

Equivalent with the ripped animations (`docs/monster-animations.md`, `ord NN`, recorded for one period from the restart): keep `frame_offset` in video frames; on a tick `frame_offset = 0` if the key changed (or a state ended / started), else `frame_offset += 5`; draw `per_frame.file_index[frame_offset % total_frames]` for the next 5 frames. The command flag only decides when the AI step runs next; it does not touch the animation. The displacement is unaffected by the phase (the velocity is set by the animation script and kept when the key is unchanged): 10 px per 5-frame advance step in both cases [V: `dx` of every step in the JSON, `counterfactual_*` case].

## 4. Evidence

### 4.1 Harness

`tools/monster_anim_phase.py ROM STATE OUT.json [ids]` creates the monster with the game spawner (`ai_sim.Sim`), runs `$C0:B08C` per frame plus the NMI handler, and per video frame records the sprite pieces owned by the monster together with the VRAM data of their tiles (a picture is a set of tiles uploaded by the game: the tile numbers stay the same), animation id, facing, state, script pointer `obj+0x16`, frame index `obj+0x26 / 2`, duration counter `obj+0x12`, the restart word `obj+0x30` and whether `$C0:F541` ran. The **frame index is the picture**: in all natural runs every (frame index, mirror) pair had exactly one drawn picture (`picture_vs_frame_index` in the JSON, 0 pairs with more than one). The ripped animation lists the pictures as runs of equal frame indices (`per_frame.file_index`); the same numbering is in `timelines[...].run`.

Natural runs: the monster's own AI with hero 0 held at a fixed offset from the monster (re-applied every frame, so the distance class stays the same for as long as wanted); at AI steps the monster is moved back by 32 px when it is 25 px from its start, which keeps it and the hero on screen (the script's "blocked" test compares the position with the one saved before the last hop and never saw equality). Offsets: far (85, 45), (-85, -45) (advance), near (30, 10), (-35, -5) (retreat), mid (60, 15), and a mixed 75-s schedule of nine offsets with two small hits (hurt reaction). For the Polter Chair the hero first stands 10 px away for 200 frames (it sleeps until then). Forced runs: the AI step is replaced by a command list as in `tools/ai_cmds.py`. **No natural run had an AI step without a command** (`free_steps` = 0 for all 5 monsters and 6 scenarios): there is no wait between commands in these scripts; the harness-made free steps are in 4.3.

### 4.2 Chobin Hood advance and retreat (`E4 / E6 02 05`)

Advance, hero 85 px right and 45 px below (distance 96): first 12 AI steps [V, `natural.far_85_45`]; commands issued: C1 --- 02 05 x233; 233 AI steps in the run, 233 of them `C1 ... 02 05`

| step | frame | command | key before -> after | restart on its tick | picture (frame index) | step displacement x / y |
|---|---|---|---|---|---|---|
| 0 | 65 | `C1050205` (C1 RD a2 f5) | 0101 -> 0202 | yes | 3 | 10 / 0 |
| 1 | 70 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 4 | 10 / 0 |
| 2 | 75 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 3 | 10 / 0 |
| 3 | 80 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 5 | 10 / 0 |
| 4 | 85 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | yes | 3 | 10 / 0 |
| 5 | 90 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 4 | 10 / 0 |
| 6 | 95 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 3 | 10 / 0 |
| 7 | 100 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 5 | 10 / 0 |
| 8 | 105 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | yes | 3 | 10 / 0 |
| 9 | 110 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 4 | 10 / 0 |
| 10 | 115 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 3 | 10 / 0 |
| 11 | 120 | `C1050205` (C1 RD a2 f5) | 0202 -> 0202 | no | 5 | 10 / 0 |

Retreat, hero 30 px right and 10 px below (distance 32): first 12 AI steps [V, `natural.near_30_10`]; commands issued: C1 --- 02 05 x233; 233 AI steps in the run, 233 of them `C1 ... 02 05`

| step | frame | command | key before -> after | restart on its tick | picture (frame index) | step displacement x / y |
|---|---|---|---|---|---|---|
| 0 | 65 | `C1020205` (C1 L a2 f5) | 0101 -> 0282 | yes | 3 | -10 / 0 |
| 1 | 70 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 4 | -10 / 0 |
| 2 | 75 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 3 | -10 / 0 |
| 3 | 80 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 5 | -10 / 0 |
| 4 | 85 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | yes | 3 | -10 / 0 |
| 5 | 90 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 4 | -10 / 0 |
| 6 | 95 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 3 | -10 / 0 |
| 7 | 100 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 5 | -10 / 0 |
| 8 | 105 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | yes | 3 | -10 / 0 |
| 9 | 110 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 4 | -10 / 0 |
| 10 | 115 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 3 | -10 / 0 |
| 11 | 120 | `C1020205` (C1 L a2 f5) | 0282 -> 0282 | no | 5 | -10 / 0 |

Per video frame over 4 consecutive advance steps (steps 2-5 of the run, frames 75-94 of the run, command `C1050205`, key `0202`) [V, `natural.far_85_45.evidence_frames`]:

| frame since step 2 | 0-4 | 5-9 | 10-14 | 15-19 |
|---|---|---|---|---|
| frame index (picture) | 3 | 5 | 3 | 4 |
| picture index in the cycle (ripped `ord 02`) | 2 | 3 | 0 | 1 |
| script pointer `obj+0x16` | 9BEC | 9BEE | 9BE7 | 9BEA |
| restart `$C0:F541` on the tick | no | no | yes | no |
| actor x at the first frame of the step (relative) | 0 | 10 | 20 | 30 |

Frame by frame: frame index `3 3 3 3 3 5 5 5 5 5 3 3 3 3 3 4 4 4 4 4`; restart `00000000001000000000` (frame 10 is the wrap of the cycle, the first picture appears again), displacement `0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38` px (2 px per frame, the same on every step).

The longest run in the advance scenario is **233 consecutive identical `C1050205` steps** (all steps of the 1200 frames after the first); frame index on consecutive steps: `3 4 3 5 3 4 3 5 3 4 3 5 3 4 3 5 ...`; each fourth step wraps. The retreat scenarios (hero left and right) give 233 and 233 consecutive steps with the same sequence on the left side (key `0282`, mirrored) and the right side (key `0202`). Over the six natural runs of this monster 1904 animation ticks were compared with the rule, 0 differences.

Picture sequence of the Chobin advance (animation 2, right / left, up and down use their own frame indices): **steps 1-4 after a turn (or after any other key): `3, 4, 3, 5`; steps 5-8: `3, 4, 3, 5`; ...** One picture per step, 5 frames each. Other facings (`timelines` of the JSON): up (key `0200`) `6, 7, 6, 8`, down (`0201`) `0, 1, 0, 2`, the diagonal codes use the right / left cycle. Stand (animation 0): one picture (`3` side, per facing in the JSON), a one-tick loop that "restarts" on every tick without visible change.

### 4.3 Forced experiments (Chobin Hood, animation 2; command `C1 dir a2 f5` = 5 frames)

Every step shows the frame indices of its ticks; `*` marks a tick on which the restart path `$C0:F541` ran; `|` separates AI steps; `R L D U` are the direction codes 1 2 4 8, `RD` = code 5 and so on. All commands were preceded by a `C1 R a0 f5` turn. [V, `monsters.3.forced`]

**Same id, same facing, 14 steps of 5 frames (then free steps)** (`a02_same_id_same_face`)

```
C1 R a0 f5     x1  key 0001->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x10 key 0202->0202 state 00  4 | 3 | 5 | *3 | 4 | 3 | 5 | *3 | 4 | 3
free           x5  key 0202->0202 state 00  5 | *3 | 4 | 3 | 5
```

**Same id, facing changes: R R L L R R D D U U R R, then the diagonal codes RD RD RU RU LD LD LU LU** (`a02_face_change`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 L a2 f5     x1  key 0202->0282 state 00  *3
C1 L a2 f5     x1  key 0282->0282 state 00  4
C1 R a2 f5     x1  key 0282->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 D a2 f5     x1  key 0202->0201 state 00  *0
C1 D a2 f5     x1  key 0201->0201 state 00  1
C1 U a2 f5     x1  key 0201->0200 state 00  *6
C1 U a2 f5     x1  key 0200->0200 state 00  7
C1 R a2 f5     x1  key 0200->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 RD a2 f5    x2  key 0202->0202 state 00  3 | 5
C1 RU a2 f5    x2  key 0202->0202 state 00  *3 | 4
C1 LD a2 f5    x1  key 0202->0282 state 00  *3
C1 LD a2 f5    x1  key 0282->0282 state 00  4
C1 LU a2 f5    x2  key 0282->0282 state 00  3 | 5
C1 R a2 f5     x1  key 0282->0202 state 00  *3
free           x5  key 0202->0202 state 00  4 | 3 | 5 | *3 | 4
```

**Other id in between: a2 a2 a0 a0 a2 a2 a0 a2** (`a02_other_id_a00`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a0 f5     x1  key 0002->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
free           x5  key 0202->0202 state 00  4 | 3 | 5 | *3 | 4
```

**Other id in between: a2 a2 a1 a1 a2 a2 a1 a2** (`a02_other_id_a01`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 R a1 f5     x1  key 0202->0102 state 00  *3
C1 R a1 f5     x1  key 0102->0102 state 00  4
C1 R a2 f5     x1  key 0102->0202 state 00  *3
C1 R a2 f5     x1  key 0202->0202 state 00  4
C1 R a1 f5     x1  key 0202->0102 state 00  *3
C1 R a2 f5     x1  key 0102->0202 state 00  *3
free           x5  key 0202->0202 state 00  4 | 3 | 5 | *3 | 4
```

**Commands shorter and longer than the cycle: flags 5 10 5 15 5 0 5 5 20 5 5 (flag 0 = natural length, 20 frames)** (`a02_mixed_flags`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f10    x1  key 0202->0202 state 00  4 3
C1 R a2 f5     x1  key 0202->0202 state 00  5
C1 R a2 f15    x1  key 0202->0202 state 00  *3 4 3
C1 R a2 f5     x3  key 0202->0202 state 00  5 | *3 | 4
C1 R a2 f20    x1  key 0202->0202 state 00  3 5 *3 4
C1 R a2 f5     x2  key 0202->0202 state 00  3 | 5
free           x5  key 0202->0202 state 00  *3 | 4 | 3 | 5 | *3
```

**Two full-length commands (flag 0, 20 frames) then 5-frame commands** (`a02_full_length_then_5`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f0     x1  key 0002->0202 state 00  *3 4 3 5
C1 R a2 f0     x1  key 0202->0202 state 00  *3 4 3 5
C1 R a2 f5     x3  key 0202->0202 state 00  *3 | 4 | 3
free           x5  key 0202->0202 state 00  5 | *3 | 4 | 3 | 5
```

**Three 5-frame commands, then AI steps that give no command (harness)** (`a02_free_steps`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x2  key 0202->0202 state 00  4 | 3
free           x8  key 0202->0202 state 00  5 | *3 | 4 | 3 | 5 | *3 | 4 | 3
```

**Pose commands (`40 0`, state 0x40, 25-frame leap) between two runs of the walk** (`state_pose_between`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x2  key 0202->0202 state 00  4 | 3
40 pose 0      x1  key 0202->0002 state 40  *4 4 4 3 3
40 pose 0      x5  key 0002->0002 state 40  *4 4 4 3 3 | *4 4 4 3 3 | *4 4 4 3 3 | *4 4 4 3 3 | *4 4 4 3 3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x3  key 0202->0202 state 00  4 | 3 | 5
free           x10 key 0202->0202 state 00  *3 | 4 | 3 | 5 | *3 | 4 | 3 | 5 | *3 | 4
```

**A turn and a swing (`02`, state 0x80, 40 frames) between two runs of the walk** (`state_swing_between`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x2  key 0202->0202 state 00  4 | 3
C1 R a0 f0     x1  key 0202->0002 state 00  *3
02 swing       x1  key 0002->0102 state 80  *23 23 24 24 24 24 25 25
C1 R a2 f5     x1  key 0102->0202 state 00  *3
C1 R a2 f5     x3  key 0202->0202 state 00  4 | 3 | 5
free           x12 key 0202->0202 state 00  *3 | 4 | 3 | 5 | *3 | 4 | 3 | 5 | *3 | 4 | 3 | 5
```

**Counterfactual: `obj+0x30 = 0xFF` written with every command (a port that restarts per command); the model mismatch is expected here** (`counterfactual_restart_every_command_a02`)

```
C1 R a0 f5     x1  key 0202->0002 state 00  *3
C1 R a2 f5     x1  key 0002->0202 state 00  *3
C1 R a2 f5     x7  key 0202->0202 state 00  *3 | *3 | *3 | *3 | *3 | *3 | *3
free           x5  key 0202->0202 state 00  4 | 3 | 5 | *3 | 4
```

Results: the same id and facing continue the cycle (`3 | 4 | 3 | 5 | *3 ...`), also across commands of different length (10, 15, 20 frames, flag 0) and across steps without a command; right <-> left, up <-> down, right -> down restart (first picture, `*`); the diagonal codes 5 and 9 (facing byte 0x02, right) continue a run of code 1 and the codes 6 and 10 (0x82, left) continue a run of code 2, entering the other side restarts; another animation id between (stand, walk 1, 4, 5) restarts on entering and on leaving; poses and swings restart themselves and the walk that follows restarts at its first picture (the key is 0xFF after a state). In the counterfactual run every step shows `*3`: **the same picture on every step with the same 10 px displacement**.

### 4.4 Rule check on every tick of all runs

`check_model` replays the rule on every tick of every natural and forced run: restart when the key differs from the previous state-0 tick, when a non-zero state intervened, otherwise the next tick of the cycle measured in isolation for that key (`timelines`, a 50-tick forced command per key; all cycles periodic). A trace starts checking at its first observed restart. Ticks in a non-zero state (pose, swing, hurt) are skipped. Counted: ticks compared; picture differences; restart-flag differences.

| monster | ticks compared | picture mismatches | restart mismatches | key changed -> restart | same key, carried on | same key, cycle wrap | first tick after a state | ticks in other states (skipped) |
|---|---|---|---|---|---|---|---|---|
| 3 Chobin Hood | 2094 | 0 | 0 | 41 | 1312 | 706 | 35 | 234 |
| 13 Polter Chair | 2120 | 0 | 0 | 301 | 1089 | 659 | 71 | 567 |
| 0 Rabite | 2290 | 0 | 0 | 206 | 1850 | 191 | 43 | 225 |
| 20 Silktail | 2099 | 0 | 0 | 143 | 1691 | 209 | 56 | 416 |
| 1 Buzz Bee | 2342 | 0 | 0 | 295 | 1154 | 858 | 35 | 112 |
| total | 10945 | 0 | 0 | | | | | |

"Same key, carried on" counts every tick inside a command and across commands; the step-level table is next.

### 4.5 What the scripts do at step level (all natural runs, `C1` steps in state 0)

| monster | AI steps | `C1` steps whose key changed (all restarted) | same key as before, cycle wrap (restart because the script ended) | same key as before, **carried on mid-cycle** | animations the script moves with (cycle ticks) |
|---|---|---|---|---|---|
| 3 Chobin Hood | 1916 | 26 | 665 | 1196 | a2: 4 |
| 13 Polter Chair | 587 | 280 | 259 | 0 | a5: 4, a4: 4 |
| 0 Rabite | 352 | 160 | 166 | 0 | a5: 6, a2: 7 |
| 20 Silktail | 313 | 108 | 155 | 25 | a2: 7, a1: 6 |
| 1 Buzz Bee | 1013 | 237 | 771 | 0 | a5: 2, a2: 2 |

- **Chobin Hood (3)**: advance, retreat and the other hops use flag 5 on animation 2 (cycle 4 ticks), so the carried-on steps are 3 of 4 steps of a run. Turns (`C1 dir a0`) are one-picture loops.
- **Silktail (20)**: the carried-on steps are 5-frame commands of animation 0 (`C1 d a0 f5`, a four-tick stand cycle `0 0 1 1`: pictures change every second step); a port that restarts per command would never show picture 1 of the idle during these.
- **Rabite (0), Buzz Bee (1), Polter Chair (13)**: hops use flag 0 (natural length of the animation: the command lasts until the script ends), so every hop starts at the first picture whether or not the engine restarts. Same id and facing again after a full-length hop is a cycle wrap; the phase never carries between hops. Their short commands are one-picture stands (Chair, Rabite stand-ups) or the 2-tick Buzz Bee flutter.

### 4.6 After a state

Every pose, swing and hurt reaction (state `0x40` / `0x80`) ends with the key 0xFF: the ordinary animation that follows starts at its first picture (`first tick after a state` column above: every one of them was a restart). Hit reactions are animations 8 / 9 of the ordinary table played in state 0x40 with the id `0x80 | n` (docs/monster-3.md section 13); the two small hits of each mixed run gave these states (`states_seen` contains 64) and the restart after them.

## 5. Notes for the remake

1. Run the animation on the AI-step clock (every 5 frames = 83.2 ms), not on a per-command clock; the tick happens whether or not a command was issued (an AI step without command, which these scripts never make, would continue the cycle and keep the velocity).
2. Remember `key` and `n` between commands. Reset `n` only when (facing byte, animation id) changes, when the cycle wraps (modulo), or when a pose / swing / hurt / death state ran. Left and right are different keys (mirroring), up / down / side are different keys; diagonal direction codes are the horizontal facing.
3. The first tick of a restart shows the first picture of the animation; the command that causes the restart is on that same tick (the picture of the step is the first of the cycle, not the second).
4. Hop movement is independent: 2 px per frame on frames 1-5 of each step whether or not the picture advances.

## 6. Limits

- Slot 3 only for the animation timeline (the tick phase of slots 4 and 5 was measured: `f % 5 = 1, 2`). Animations of states other than 0 were not studied beyond "they run their own script from the start and the key is reset afterwards".
- `obj+0x41` (a count that `$C0:F4FB` decrements before the tick, forcing a restart each time) was 0 on every frame of 5 x 2,200 frames of natural AI runs (the only write is the state-end code `$C0:F95E`, with 0); the monsters and states where it can be non-zero were not examined.
- Terrain collision, jumps and projectile frames are as in the per-monster documents.
