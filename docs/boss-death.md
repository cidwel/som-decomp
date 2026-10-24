# Generic boss death (Secret of Mana USA)

Tags: **[V]** reproduced by running the original 65816 code with the whole game frame in `tools/boss_death.py` (on top of `tools/rip_boss.py` / `tools/boss_fight.py`), **[C]** read from the disassembly. Addressing and object fields as in `docs/mantis-ant.md`. Frames are 1/60.0988 s.

Frame 0 = the frame of the lethal hit (HP 0, dead bit `obj+$191` bit 7). **P** = the first frame of death phase 5 (`$C2:0B8B`); everything after it is the same for every boss that uses the generic code, so it is given relative to P. For the bosses of the generic dispatcher P = 10 [V: Mantis Ant, Spikey Tiger, Mech Rider (0x60), Kilroy]; Tropicallo, with its own phase machine, reaches it at frame 370 [V].

## 1. The routines [C, timing V]

The C2 engine runs a boss object through a phase variable `obj+$94` and a tick counter `obj+$96` (one tick per 5 frames). The 15 native records (`$D0:BC34`) all use the dispatcher `$C2:34D8`: phases 0-3 are the state-script machine, phases 4-6 are the death, through the table `$C2:3504` (or through a per-record table `obj+$4C` = record word +0x18 when it is not 0).

- **Entry** (`$C2:35CC` / `$C2:366F`): in hurt mode (`obj+$82` = 2) with the dead bit set (`$C2:34B0`) the phase becomes 4.
- **Phase 4** `$C2:0AFD`: waits until `obj+$60` (low byte) is 0, then phase 5 and `$C2:0B14`: `obj+$60` = 0x20, age 0, palette effect 0x49 (`$C2:26F9`) on each palette row listed in `obj+$18..$1B` (the boss rows), `$C2:24C3` with 0x27, `$C2:3963` with 0x8B00.
- **Phase 5** `$C2:0B8B` (52 ticks): at age 24 `$C2:0C11` with event **0x7F8** (the fixed victory event; it also sets bit 7 of the pad byte of the controlling hero) and `JSL $C0:006F` (the rewards, section 6); at every age multiple of 4 below 52 `$C2:0C33` (one explosion); at age 52 phase 6, `obj+$A7` = 0, `$C2:3963` with 0x8A00.
- **Phase 6** `$C2:0BCE` (`$C2:0B50` is the same without the hook): at age 8 the record hook `obj+$78` (record word +0x14; an `RTS` in every record but Snap Dragon's, which overrides the phases anyway) and `$C2:3A9A`: the boss shows animation 0 (or 0x133 when `obj+$98` bit 3 is set), the **particle burst** object (handler `$C2:3ADB`, flags 0x2A21) is created at (boss x, boss y + `obj+$62`) and a helper (handler `$C2:3C78`, flags 0x2100) that clears the burst bitmap every tick for 84 ticks. From age 128 the phase waits until no pad byte `$D9-$DB` has bit 7 (no event running) and `$1D04` bit 5 is clear (no text window), then runs the map-record event `obj+$72` through `$C2:0C11` and returns carry set: **the boss object is removed in that frame**.

Users of these routines [C]: all 15 native records except the overrides below; Tropicallo, Brambler and Boreal Face (handler `$C2:44A8`, phases 0x0E/0x0F/0x10 = `0AFD`, `0B8B`, `4AEA` -> `0B50`); Wall Face and Doom's Wall (`$C2:7AF4`, phases 4/5/6 = `0AFD`, `0B8B`, `7C22` -> `0B50`); Jabberwocky and Hydra (they switch to the death handler `$C2:59DD` = `0AFD`, `0B8B`, `0B50`); Lime Slime and Dread Slime (`$C2:8455`, own phase 4 `$C2:8817` = `0AFD` + `0B14`, then `0B8B`, `0B50`); Mech Rider (record 7 override `$C2:EB63`: own phase 4 with animation 0x10A, a copy of `0B8B` at `$C2:72C1`, then `0BCE`). The Dark Lich (record 8) uses the generic phases; event 0x7F8 tests flag 0x4E = 6 and then skips the poses and the second music (section 4).

Not generic [C]: record 5 (Snap Dragon, Tonpole, Biting Lizard; override `$C2:DD4F`): animation 0xAE, at age 36 the map-record event and the rewards directly, no explosions, no burst, no event 0x7F8; record 10 (Great Viper, Dragon Worm; override `$C2:ED17`): fade phase, 24 ticks, the object itself becomes an explosion (animation 0x15C), then rewards and the map-record event, no 0x7F8; the Mana Beast (`$C2:8F33`, `docs/cutscene-ending.md` section 2): its own explosions through `$C2:0C33`, event 0x42F, no 0x7F8.

Per-boss data: the record words +0x14 (hook), +0x16 (`obj+$62`, burst height: Mantis Ant -24, Spikey Tiger -16, Kilroy -32, Mech Rider -48, Dark Lich 0, most others -32), +0x18 (phase override), the hurt animation the boss shows during the death, its palette rows, and the map-record event (`map record word & 0xFFF`, e.g. 0x112 for the Mantis Ant, 0x1B9 Tropicallo, 0x1E2 Spikey Tiger, 0x42D Dark Lich).

## 2. Timeline [V]

| frame | what |
|---|---|
| 0 | HP 0, dead bit, hit sound (`obj+$1AF`, 0x94 for the four bosses run) |
| P-5 | phase 4 (hurt pose kept to the end) |
| P | phase 5: boss palette rows start a fire colour cycle (one step per 5 frames) |
| P+20 k, k = 1..12 | explosion attempt (section 3) |
| P+120 | event 0x7F8 started, pad locked, rewards given |
| P+123 | first VM step of 0x7F8 (section 4) |
| P+134 - P+289 | white fade up, held to P+393, down to P+544 (section 4) |
| P+260 | phase 6 |
| P+300 | boss no longer drawn; burst object created; sound 0x15 at P+302 |
| P+305 - P+671 | burst pictures (section 5); object gone at P+672 |
| P+998 | 0x7F8 ends (with an immediate party gather) |
| P+1000 | boss object removed, map-record event started (first VM step P+1003) |

The boss removal depends on the end of 0x7F8 (the party gather waits for the party AI); it is never earlier than P+900.

## 3. Explosion objects [V; placement C, checked on 12 placements]

`$C2:0C33`: palette effect 0x48 on OBJ palette 7 (CGRAM row 15: colours 1-8 = 0010 0018 001F 01BF 029F 035F 03FF 7FFF), then an object with handler `$C2:3197` in the first free engine slot of 3..8 (no free slot: nothing, no sound) at **x = boss x + 32 - rand(64), y = boss y - 64 + rand(64)**, `rand(n)` = `$C2:300B` = (r * (n + 1)) >> 8 with r a byte of the C2 generator (`docs/mantis-ant.md` section 6): dx in [-32, 32], dy in [-64, 0]. The object plays animation 0x15C (`$C1:7B09`: sound 0x15, eight pictures). Spawned at frame s: sound 0x15 at s+1, picture 0 for 1 frame at s+5, pictures 1-7 for 5 frames each, slot free at s+41. With three free slots the 12 attempts give 12 explosions, two visible at a time; Kilroy, whose parts hold the slots, gets fewer [V].

## 4. Event 0x7F8 [V, runs of four bosses]

FREEZE (P+123); event 0x748 = raw sound command 0x80/0x80 (P+128); `SCREEN 6` 0x7FFF (P+133): every colour component of CGRAM rows 1-15 and colour 0 of row 0 gets + k (capped at 31), k = (f - (P+134)) // 5, so the screen is white at P+289; WAIT 40 ticks; music id 0x18 (P+338); flags 0x70-0x72 = 0, then +1 for each dead hero (events 0x334-0x336, test of `obj+$191` bit 7); living heroes: status words cleared and HP refilled (0x418-0x41A); if flag 0x4E = 6 (Dark Lich) GOTO 0x7F9 (fade back, wait 64 ticks, event 0x41B, END); else living heroes loop animation 0xAA (P+388), `SCREEN 7` (P+388: k falls by one every 5 frames from P+394, 0 at P+544), WAIT 64 ticks, event 0x7C0 = music id 0x17 (P+713) and WAIT 16 ticks; a one-line text window (block of 13 bytes, P+798); event 0x41B (P+833): FREEZE, all three heroes animation 0xAB, status words cleared, HP and MP refilled, sound effect 0x07 (P+868); WAIT 20 ticks; the window closes (P+978, gone at P+992); GATHER (P+993); END (P+998 when the party is together).

## 5. The particle burst (`$C2:3ADB`) [V]

Drawn with sprites, not a BG layer: no HDMA, window, mosaic or mode 7 register changes during the death (HDMA is only switched on for the text windows). Init: OBJ palette 7 colour 14 = 0x001F (red), colour 15 = 0x7FFF (white); 256 particles at `$7F:2000` (x, y, vx, vy, 8.8 fixed point), all at (0, 0); per particle two random bytes r1, r2: speed m = cos(r2) * 0x2C0 >> 8, vx = m * cos(r1) >> 8, vy = m * sin(r1) >> 8 with the sine of `$C2:2A67` (1024 steps per turn, table `$D9:7DE0`); r1 < 256 is the first quadrant only. Each tick (every 5 frames, ages 1-74) the first 256 - 3 * age particles move; one whose x reaches 128 px or whose y reaches 64 px is no longer drawn; the others are plotted into a 128 x 64 4bpp bitmap at `$7F:6000` (colour 15 for odd particles, 14 for even ones), which goes to OBJ tiles 32-47 (+ rows). 14 sprites of 32 x 32 (priority 3, palette 7) show the top 128 x 32 of it four times: as is at (0..127, -1..30) from the object, mirrored horizontally at (-96..-1) (only 96 px of it), mirrored vertically above: a 224 x 64 picture. The model (`boss_death.py` `burst_init` / `burst_tick`) gives the real particle table (256 of 256) and the real bitmap in 73 of 73 ticks.

Pictures (rip): picture 0 at P+305 (2 frames), picture k at P+307 + 5 (k - 1) for 5 frames, k = 1..73, last frame P+671. The white fade of section 4 is on top: the burst is all white until about P+390.

## 6. Rewards [V]

EXP and gold are added at P+120 (Mantis Ant: +10 EXP per hero, +100 gold, frame 130 of a natural kill), in the frame that starts 0x7F8 (`JSL $C0:006F` after `$C2:0C11`, [C] for the attribution). No message shows them; the only text of the sequence is the window of section 4. With the lethal damage injected (`boss_death.py`) no reward is given.

## 7. Tool

`python3 tools/boss_death.py ROM STATE BOSS_ID OUTDIR [frames=N]`: lethal hit after 30 frames, party AI back on after the hit; writes `timeline.json` (per frame: boss phase/age/animation, every engine object, VM commands, sounds, pads, palettes, PPU register writes), `summary.txt`, `burst_atlas.png` / `burst.json` and `explosion_atlas.png` / `explosion.json` (pictures in the unfaded palette). `boss_death.py ROM verify STATE BOSS_ID` checks the burst model. The lethal injection did not kill Wall Face, Snap Dragon, Great Viper, Hydra, the Dark Lich or the Mana Beast (their death needs another hit path); they are covered by the code reading only.

## 8. Open questions

- What `$C2:3963` (0x8B00 at P, 0x8A00 at P+260; `JSL $01:8003`) and `$C2:24C3` (0x27) do.
- The meaning of the raw sound command 0x80/0x80 and of music ids 0x18 and 0x17.
- The party-gather length with the heroes far apart (it moves the boss removal later).
