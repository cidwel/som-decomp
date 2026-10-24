# The computer-controlled heroes (ally AI)

Tags as in `docs/rom-combat.md`. Tool: `tools/hero_ai.py` (listing, randomised check of the model against the real AI step, test vectors for a port). Model: `tools/ai_vm.py` (the monster AI machine, extended with the ops below).

## 1. Where it runs [V]
- A hero that no pad drives (the bit of its slot is clear in all of `$D9-$DB`) runs the **same AI bytecode machine as the monsters** (`docs/monster-ai-opcodes.md`): the object step `$C0:F8E9` calls `$C1:D942` -> `$C1:0028` -> `$C1:2552` when the hero is free (not swinging, not hurt, not casting), once per combat tick (every 5th frame, 12.02 Hz). The command bytes `+0x140..0x143` are then executed by `$C1:D942`.
- Script entry: word at ROM `0x100009 + 16 * id` for the hero ids 0x80, 0x81, 0x82 = **0x58EA for all three** (relative to the script base 0x104F15). 894 instructions, 51 distinct ops. The script never casts a spell (no op E9/EA): **AI heroes only walk, attack and charge**.
- Verified: 6,000 randomised steps (hero in slot 1; random heroes, monsters with monster and non-monster ids, distances in every class, blocking statuses, weapon types, gauge, charge stage, flag `+0x14C`, settings `$CC73/$CC7D`, pad bindings, injected machine states): **0 mismatches** between `ai_vm.py` and the real `$C1:2552`, all 894 instructions executed, 426 of 438 branch outcomes seen.

## 2. Settings: the action grid and the charge level [V/C]
- The ring-menu action grid (4 x 4 cells, cell = 4 * row + column) writes, for the hero `Y` (`$C7:6CA7`): `$CC73 + Y` = behaviour from the table `$C7:6D8B` = `0 0 2 2 / 0 0 2 2 / 1 1 3 3 / 1 1 3 3` (columns 2-3 add 2, rows 2-3 add 1), `$CC7A + Y` = the cell itself (it selects the stat tweak of `docs/rom-combat.md` section 3: table `$C0:473F` = `35 04 04 17 32 00 00 23 32 00 00 23 35 04 04 17`, 2-bit fields Str/Agi/Con adding 0/+1/+2/-1), and `$CC7D + Y` = the charge level chosen in the menu (clamped to the weapon level, `$C7:6C18`).
- New game (`$C0:578A-57AC`): behaviour 3 and cell 15 for all three heroes, charge level 0.
- The script reads them through the object reference 0xFF (and any > 0x82): `$C1:2010` addresses `$CA80 + (slot & 3) + 0x180 + offset` = `$CC00 + slot + offset`, so `IF30 FF 73 n` tests `$CC73 + slot`.
- The four behaviours are four sub-scripts (behaviour 0: `5C06`, 1: `5E08`, 2: `61D8`, 3: `605E`), each split by the weapon type `+0x1E4`: glove, sword/axe, and the rest (spear, whip, bow, boomerang, javelin, which use the cardinal/lane tests 66, 6F, 46 to line up with the target).

## 3. The ops the hero script adds [V]
| op | length | meaning |
|---|---|---|
| 32 / 4A / 4F | 2 | J: no valid monster (slots 3-5, active, on screen, no status of 0x8460, id `+0x180` < 0x80) within 16 / 32 / 48 px (54 = 64 px is the monster op) |
| A6 / B2 / B5 / B8 | 1 | current target = first such monster (slot order) within 16 / 32 / 48 / 64 px, FF if none |
| A0 | 1 | current target = FF |
| 62 | 2 | J: a valid monster exists and no pad-bound hero (highest bit of each of `$D9-$DB`) is farther than 96 px (distance class 0x30) |
| E1 | 1 | command 01 (follow), yield |
| DF | 1 | gauge `+0x1ED` == 0: clear `+0x14C` bit 0, command 02 (attack), yield; else continue |
| F3 | 1 | `$CC7D + slot` != 0 and `+0x14C` bit 0 clear: set the bit, command 06 (press and hold), yield; else continue |
| F4 | 1 | `+0x14C` bit 0 set: clear it, command 07 (let go), yield; else continue |
| F2 | 3 | arg 0: J when `$CC7D + slot` > charge stage `+0x19B`; arg != 0: J when not |

The frame of the script: `5913` (called before every decision) checks op 62; when it falls through (no monster, or the human-driven hero is more than 96 px away) the hero is told to **follow** (E1), lets go of a charge (F4) and drops its target. Otherwise it picks the nearest band that has a monster (16, 32, 48 px, else 64 px, none beyond) and faces it (E4 03 05).

## 4. What the commands do for a hero [V, `$C1:D942`, measured with injected commands]
| command | effect |
|---|---|
| 00 | nothing: the current movement goes on |
| 01 | clears the C1 movement flag `+0x67`, which hands the hero back to the party follow of section 5 |
| 02 | attack: a normal swing, or the charged attack of the current stage `+0x19B` when it is above 0 (charged attack animation, E011 = 8, ~50 frames) |
| 06 | press and hold the attack button: a normal swing now, then the charge counts (`$C0:B330`, cap `$CC7D + slot`) once the weapon gauge is empty |
| 07 | let go: the stage returns to 0, no attack |
| C1 dir anim frames | `E011` = anim, facing from dir (horizontal wins on a diagonal), `E062` = frames. The velocity comes from the animation script and lasts until another command changes it: anim 0x0A run 3 px/frame along dir; 0x0B walk 1 px/frame along dir; 0x0C walk 1 px/frame backwards (away from dir, facing kept); 0x13 1 px/frame along x only, backwards for a right/up/down facing; 0x00 stand, 0x03 stand ready |

The C1 arguments used by the script: `E4 03 05` (face the target), `E4/FD/BE 0B 0A` (walk towards it), `E4/FD 0A 0A/05` and `E0 xx 0B 0A` (run / hop sideways), `E6/FE/BF 0A ..` and `E4/FD 0C 0A` (back off), `E4 13 00` (step back after a swing).

## 5. Following the leader [V: `tools/party_follow.py`, 3,000 random cases of the step `$C0:F124`, 0 mismatches]
Every frame (`$C0:EEC0`) the two partners of the pad-bound hero run the steering step when they are free (`+0x2C`, `+0x1C`, `+0x60` and the C1-movement flag `+0x67` all 0, active, `+0x0A` = 0). Order: leader 0 -> partners 2 then 1; leader 1 -> 0 then 2; leader 2 -> 0 then 1.
- Target = the leader's position; per-axis dead zone 32 px for the first partner and 64 px for the second (0 for both while the party gathers, `$4E`, or with the leader's `+0x0B` bit 3); when the leader moves along one axis only, the dead zone of the other axis is 0, so the partners line up behind it.
- Per axis: `s = |d| - dead` (the shorter way round the map); no motion if `s <= 0`, `s` px per frame if `s < 4`, else `max(3, the leader's speed on that axis)`.
- A partner whose step stays blocked counts in `+0x2D`; at 6 it calls the path step `$01:B729` (not modelled).

## 6. Open
- How the action-grid cursor maps to the row/column wording of the menu (the cell numbering above is the index stored by the menu).
