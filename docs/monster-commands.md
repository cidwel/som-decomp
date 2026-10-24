# Commands of the ordinary monsters 0x00-0x53, measured in the real game code

Tags: every number is **[V]**: `tools/monster_commands.py` runs each command through the real op handler and the real per-frame routine `$C0:B08C` (monster in slot 3, `ai_sim` harness, `.zs3` state). Data: `data/monster_commands.json`. Frames are 60.0988 Hz video frames counted from the AI step that issues the command.

Commands (bytes `obj+0x140..0x143`, actor step `$C1:D94F`): `C1 dir,anim,flag` move / hop / turn with ordinary animation `anim` (flag = requested length in frames, 0 = natural length); `40 anim` pose of the attack table; `02` swing, attack animation chosen by `$C1:E40E`; `43 id` creates object `id`; `44 anim` cast pose, the spell is the attack record named by op E9; `81 a,id` turns into object `id`. Which picture is shown when a command starts: `docs/monster-animation-phase.md`.

## Hop profiles

Monsters whose ordinary animations move the same way share a hop profile (`hop_profiles`: per case "direction code, animation, flag" -> frames until free, dx, dy, frames with movement, first and last moving frame, largest step). Long moves (flag 180) that met a wall differ between monsters of one profile; they are listed in `conflicts` and are not a property of the animation.

| profile | monsters |
|---|---|
| 0 | 00 14 3B 45 |
| 1 | 01 29 |
| 2 | 02 03 06 0B 0C 0E 11 1C 1F 25 2A 34 41 43 50 |
| 3 | 04 08 12 27 2B 36 38 3E 4E 4F 52 |
| 4 | 05 19 2C |
| 5 | 07 1A 32 |
| 6 | 09 30 |
| 7 | 0A 15 1E 23 |
| 8 | 0D 2D |
| 9 | 0F 13 1D 22 2F 33 40 49 |
| 10 | 10 31 |
| 11 | 16 |
| 12 | 17 3A 42 4B |
| 13 | 18 3D |
| 14 | 1B 35 4A |
| 15 | 21 51 |
| 16 | 24 28 47 |
| 17 | 26 |
| 18 | 37 46 |
| 19 | 39 |
| 20 | 3F |
| 21 | 48 4D 53 |

## Swing chooser

The chooser (`$C1:E40E`, table `D1:05C0 + 0x20 * id`) takes the distance to the target along the facing axis and puts it in one of four classes; the parity bit `$F4 & 1` picks one of two table columns; bit 7 of `obj+0x1E4` (toggled by op FC) selects the variant half of the table. Class limits (px) for horizontal / vertical facings and the attack animation per class and parity:

| id | monster | limits horizontal | limits vertical | normal (class 0-3: parity 0/1) | variant |
|---|---|---|---|---|---|
| 00 | Rabite | 26 42 58 | 24 40 56 | 3/1 1/1 2/2 2/2 | - |
| 01 | Buzz Bee | 26 42 58 | 24 40 56 | 1/1 1/1 2/2 2/2 | 1/1 1/1 2/2 2/2 |
| 02 | Mushboom | 26 42 58 | 24 40 56 | 2/3 3/4 4/4 4/4 | 5/5 5/5 5/5 5/5 |
| 03 | Chobin Hood | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 04 | Lullabud | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 05 | Iffish | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 06 | Kid Goblin | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 07 | Eye Spy | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 08 | Green Drop | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 09 | Specter | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 0A | Blat | 26 42 58 | 24 40 56 | 2/2 1/1 1/1 1/1 | - |
| 0B | Goblin | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 0C | Water Thug | 26 42 58 | 24 40 56 | 2/2 3/3 1/1 1/1 | - |
| 0D | Polter Chair | 26 42 58 | 24 40 56 | 1/2 1/2 2/2 2/2 | - |
| 0E | Ma Goblin | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 0F | Dark Funk | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | - |
| 10 | Crawler | 30 46 62 | 24 40 56 | 1/1 2/2 2/2 2/2 | - |
| 11 | Ice Thug | 26 42 58 | 24 40 56 | 2/2 3/3 1/1 1/1 | - |
| 12 | Zombie | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 1/1 3/3 3/3 3/3 |
| 13 | Kimono Bird | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 14 | Silktail | 26 42 58 | 24 40 56 | 2/3 1/2 2/2 2/2 | - |
| 15 | Nemesis Owl | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 16 | Pebbler | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 17 | Pumpkin Bomb | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 18 | Steamed Crab | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 1/1 1/1 1/1 1/1 |
| 19 | Chess Knight | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 1A | Wizard Eye | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 1B | Howler | 30 46 62 | 24 40 56 | 2/2 2/2 2/2 2/2 | - |
| 1C | Robin Foot | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 1D | LA Funk | 26 42 58 | 24 40 56 | 3/3 3/3 3/3 3/3 | - |
| 1E | Grave Bat | 26 42 58 | 24 40 56 | 2/2 1/1 1/1 1/1 | - |
| 1F | Werewolf | 26 42 58 | 24 40 56 | 1/3 2/2 4/4 4/4 | - |
| 21 | Evil Sword | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 2/2 | - |
| 22 | Tomato Man | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 23 | Mystic Book | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 24 | Sand Stinger | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 25 | Mad Mallard | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 26 | Emberman | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 27 | Red Drop | 26 42 58 | 24 40 56 | 4/4 4/4 4/4 4/4 | - |
| 28 | Eggatrice | 26 42 58 | 24 40 56 | 1/1 1/1 2/2 2/2 | - |
| 29 | Bomb Bee | 26 42 58 | 24 40 56 | 1/1 1/1 3/3 3/3 | 1/1 1/1 3/3 3/3 |
| 2A | Mushgloom | 26 42 58 | 24 40 56 | 3/3 4/4 2/2 4/4 | 5/5 5/5 5/5 5/5 |
| 2B | Trap Flower | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 2C | Dinofish | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 3/3 3/3 3/3 3/3 |
| 2D | Mimic Box | 26 42 58 | 24 40 56 | 2/2 2/1 1/1 1/1 | - |
| 2F | Kimono Wizard | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 30 | Ghost | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 31 | Metal Crawler | 30 46 62 | 24 40 56 | 1/2 2/2 3/3 3/3 | 4/4 4/4 4/4 4/4 |
| 32 | Spider Legs | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 33 | Weepy Eye | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 34 | Shellblast | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 3/3 3/3 3/3 3/3 |
| 35 | Beast Zombie | 30 46 62 | 24 40 56 | 2/2 2/2 2/2 2/2 | - |
| 36 | Ghoul | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 1/1 3/3 3/3 3/3 |
| 37 | Imp | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 3/3 3/3 3/3 3/3 |
| 38 | Blue Drop | 26 42 58 | 24 40 56 | 5/5 5/5 5/5 5/5 | - |
| 39 | Marmablue | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 3A | Fierce Head | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 1/1 1/1 1/1 1/1 |
| 3B | Griffin Hand | 26 42 58 | 24 40 56 | 2/3 1/1 1/1 1/1 | - |
| 3D | Metal Crab | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 1/1 1/1 1/1 1/1 |
| 3E | Armored Man | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 3F | Shadow X2 | 26 42 58 | 24 40 56 | 24/28 21/28 17/24 14/22 | - |
| 40 | Eggplant Man | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 41 | Captain Duck | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 42 | Nitro Pumpkin | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 43 | Turtlance | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 45 | Basilisk | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | 2/2 2/2 2/2 2/2 |
| 46 | Gremlin | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | 4/4 4/4 4/4 4/4 |
| 47 | Steelpion | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 48 | Dark Ninja | 26 42 58 | 24 40 56 | 3/3 3/3 3/4 4/4 | 2/2 2/2 2/2 2/2 |
| 49 | Whimper | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 4A | Heck Hound | 30 46 62 | 24 40 56 | 2/2 2/2 2/2 2/2 | - |
| 4B | Fiend Head | 26 42 58 | 24 40 56 | 2/2 2/2 2/2 2/2 | - |
| 4D | Dark Stalker | 26 42 58 | 24 40 56 | 3/3 3/3 3/4 4/4 | 2/2 2/2 2/2 2/2 |
| 4E | Dark Knight | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 4F | Shape Shifter | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 50 | Wolf Lord | 26 42 58 | 24 40 56 | 1/3 2/2 4/4 4/4 | - |
| 51 | Doom Sword | 26 42 58 | 24 40 56 | 1/1 1/1 1/2 2/2 | - |
| 52 | Terminator | 26 42 58 | 24 40 56 | 1/1 1/1 1/1 1/1 | - |
| 53 | Master Ninja | 26 42 58 | 24 40 56 | 3/3 3/3 3/4 4/4 | 2/2 2/2 2/2 2/2 |

## Per monster: poses, casts, created objects, projectiles

### 00 Rabite

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0], poses [0, 5], swing yes.
- pose `40 00`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 05`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].

### 01 Buzz Bee

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5], poses [0], swing yes.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].

### 02 Mushboom

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10], poses [0], swing yes.
- pose `40 00`: 100 frames, displacement (0, 0), sounds [], weapon box frames [].

### 03 Chobin Hood

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5], poses [0], swing yes.
- pose `40 00`: 25 frames, displacement (0, 25), sounds [], weapon box frames [].
- projectile of swing 1 (facing right): launched at frame 30 at offset [10, -11], lives to frame 49, end offset [61, 0], kind 1; damage seen [37, 38].

### 04 Lullabud

Script uses ordinary animations [0, 1, 2, 4], flags [0, 10], poses [0, 4, 6], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [], weapon box frames [[0, 9], [10, 14], [15, 19], [20, 24]].
- pose `40 04`: 20 frames, displacement (0, 0), sounds [158], weapon box frames [[0, 19]].
- pose `40 06`: 5 frames, displacement (0, 0), sounds [], weapon box frames [[0, 4]].
- cast `E9 03 1E`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [199].
- cast `E9 03 1E`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [199].

### 05 Iffish

Script uses ordinary animations [0, 1, 2, 3, 4, 14], flags [0, 5], poses [0, 6], swing yes.
- pose `40 00`: 20 frames, displacement (0, 20), sounds [], weapon box frames [].
- pose `40 06`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 07 07`: command `44 07`, 120 frames, MP spent 3, spell lands at frame [105], sounds [180].
- cast `E9 07 07`: command `44 07`, 120 frames, MP spent 3, spell lands at frame [105], sounds [180].

### 06 Kid Goblin

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 30], poses [4, 5], swing yes.
- pose `40 04`: 45 frames, displacement (0, 0), sounds [63, 63], weapon box frames [].
- pose `40 05`: 70 frames, displacement (0, 0), sounds [63], weapon box frames [].
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -23], lives to frame 49, end offset [0, -15], kind 3; damage seen [31].

### 07 Eye Spy

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 180], poses [0, 3], swing yes.
- pose `40 00`: 80 frames, displacement (0, 0), sounds [171], weapon box frames [[65, 74]].
- pose `40 03`: 45 frames, displacement (0, 0), sounds [61], weapon box frames [[5, 9], [15, 24], [25, 29], [30, 44]].
- cast `E9 02 0A`: command `44 02`, 110 frames, MP spent 1, spell lands at frame [105], sounds [184].
- cast `E9 02 0A`: command `44 02`, 110 frames, MP spent 1, spell lands at frame [105], sounds [184].
- cast `E9 02 0B`: command `44 02`, 110 frames, MP spent 2, spell lands at frame [105], sounds [].
- cast `E9 02 0B`: command `44 02`, 110 frames, MP spent 2, spell lands at frame [105], sounds [].
- create `ED 03`: object 3 appears in a free monster slot (5 frames).

### 08 Green Drop

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 10], poses [0, 6], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [[0, 9], [10, 19], [20, 39]].
- pose `40 06`: 25 frames, displacement (0, 0), sounds [61], weapon box frames [[0, 9], [10, 24]].
- create `ED 08`: object 8 appears in a free monster slot (5 frames).

### 09 Specter

Script uses ordinary animations [0, 1, 2, 3, 4, 11], flags [0, 5, 15, 30, 180], poses [3], swing no.
- pose `40 03`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 01 06`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [].
- cast `E9 01 06`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [].
- cast `E9 01 08`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [174].
- cast `E9 01 08`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [174].

### 0A Blat

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10, 60, 120], poses [0], swing yes.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 16`: command `44 03`, 85 frames, MP spent 2, spell lands at frame [65], sounds [178].
- cast `E9 03 16`: command `44 03`, 85 frames, MP spent 2, spell lands at frame [65], sounds [178].

### 0B Goblin

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10], poses [0, 7], swing yes.
- pose `40 00`: 115 frames, displacement (0, 0), sounds [63, 63], weapon box frames [].
- pose `40 07`: 25 frames, displacement (0, 15), sounds [63], weapon box frames [].
- cast `E9 03 01`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [49, 63].
- cast `E9 03 01`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [49, 63].
- cast `E9 03 02`: command `44 03`, 90 frames, MP spent 1, spell lands at frame [85], sounds [201, 63].
- cast `E9 03 02`: command `44 03`, 90 frames, MP spent 1, spell lands at frame [85], sounds [201, 63].
- cast `E9 03 0B`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [63].
- cast `E9 03 0B`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [63].
- create `ED 0E`: object 14 appears in a free monster slot (5 frames).
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -23], lives to frame 49, end offset [0, -15], kind 3; damage seen [47, 48].

### 0C Water Thug

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10, 30], poses [0], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 07`: command `44 04`, 90 frames, MP spent 3, spell lands at frame [85], sounds [170, 170, 170, 170, 180].
- cast `E9 04 07`: command `44 04`, 90 frames, MP spent 3, spell lands at frame [85], sounds [170, 170, 170, 170, 180].
- cast `E9 04 0B`: command `44 04`, 90 frames, MP spent 2, spell lands at frame [85], sounds [170, 170, 170, 170].
- cast `E9 04 0B`: command `44 04`, 90 frames, MP spent 2, spell lands at frame [85], sounds [170, 170, 170, 170].
- projectile of swing 1 (facing right): launched at frame 15 at offset [10, -11], lives to frame 34, end offset [61, 0], kind 1; damage seen [70, 71].

### 0D Polter Chair

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 60], poses [0], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].

### 0E Ma Goblin

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10], poses [7], swing yes.
- pose `40 07`: 25 frames, displacement (0, 15), sounds [63], weapon box frames [].
- cast `E9 03 05`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [162, 63].
- cast `E9 03 05`: command `44 03`, 90 frames, MP spent 2, spell lands at frame [85], sounds [162, 63].
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -23], lives to frame 49, end offset [0, -15], kind 3; damage seen [48, 49, 50].

### 0F Dark Funk

Script uses ordinary animations [0, 1, 2, 4], flags [0, 15, 60, 180], poses [0], swing yes.
- pose `40 00`: 25 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 0C`: command `44 04`, 120 frames, MP spent 2, spell lands at frame [85, 89, 116], sounds [8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 187].
- cast `E9 04 0C`: command `44 04`, 145 frames, MP spent 2, spell lands at frame [92, 94, 143], sounds [8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187].
- cast `E9 04 11`: command `44 04`, 50 frames, MP spent 4, spell lands at frame [45], sounds [189].
- cast `E9 04 11`: command `44 04`, 50 frames, MP spent 4, spell lands at frame [45], sounds [189].

### 10 Crawler

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 15, 180], poses [0], swing yes.
- pose `40 00`: 65 frames, displacement (0, 30), sounds [], weapon box frames [].
- cast `E9 05 1E`: command `44 05`, 115 frames, MP spent 2, spell lands at frame [110], sounds [199].
- cast `E9 05 1E`: command `44 05`, 115 frames, MP spent 2, spell lands at frame [110], sounds [199].

### 11 Ice Thug

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 180], poses [0], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 07`: command `44 04`, 90 frames, MP spent 3, spell lands at frame [85], sounds [170, 170, 170, 170, 181].
- cast `E9 04 07`: command `44 04`, 90 frames, MP spent 3, spell lands at frame [85], sounds [170, 170, 170, 170, 181].
- cast `E9 04 09`: command `44 04`, 160 frames, MP spent 2, spell lands at frame [123, 128, 156], sounds [170, 170, 170, 170, 72, 72, 72].
- cast `E9 04 09`: command `44 04`, 185 frames, MP spent 2, spell lands at frame [132, 134, 183], sounds [170, 170, 170, 170, 72, 72, 72].
- cast `E9 04 0B`: command `44 04`, 90 frames, MP spent 2, spell lands at frame [85], sounds [170, 170, 170, 170].
- cast `E9 04 0B`: command `44 04`, 90 frames, MP spent 2, spell lands at frame [85], sounds [170, 170, 170, 170].
- projectile of swing 1 (facing right): launched at frame 15 at offset [10, -11], lives to frame 45, end offset [127, 1], kind 1; damage seen [314, 316, 318, 320].

### 12 Zombie

Script uses ordinary animations [0, 1, 2, 4, 5, 11], flags [0, 5, 10, 60], poses [5], swing yes.
- pose `40 05`: 5 frames, displacement (0, 0), sounds [170], weapon box frames [].
- cast `E9 04 02`: command `44 04`, 120 frames, MP spent 1, spell lands at frame [115], sounds [201, 170].
- cast `E9 04 02`: command `44 04`, 120 frames, MP spent 1, spell lands at frame [115], sounds [201, 170].

### 13 Kimono Bird

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 15, 180], poses [0, 3], swing no.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 03`: 65 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 01 12`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [101, 107, 136], sounds [48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 01 12`: command `44 01`, 165 frames, MP spent 2, spell lands at frame [111, 114, 163], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 01 13`: command `44 01`, 70 frames, MP spent 4, spell lands at frame [65], sounds [].
- cast `E9 01 13`: command `44 01`, 70 frames, MP spent 4, spell lands at frame [65], sounds [].
- cast `E9 01 14`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [178].
- cast `E9 01 14`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [178].
- create `ED 16`: object 22 appears in a free monster slot (5 frames).

### 14 Silktail

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 120], poses [0, 5], swing yes.
- pose `40 00`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 05`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 07`: command `44 04`, 130 frames, MP spent 3, spell lands at frame [125], sounds [180].
- cast `E9 04 07`: command `44 04`, 130 frames, MP spent 3, spell lands at frame [125], sounds [180].
- cast `E9 04 08`: command `44 04`, 130 frames, MP spent 2, spell lands at frame [125], sounds [174].
- cast `E9 04 08`: command `44 04`, 130 frames, MP spent 2, spell lands at frame [125], sounds [174].
- cast `E9 04 0B`: command `44 04`, 130 frames, MP spent 2, spell lands at frame [125], sounds [].
- cast `E9 04 0B`: command `44 04`, 130 frames, MP spent 2, spell lands at frame [125], sounds [].
- cast `E9 04 0C`: command `44 04`, 200 frames, MP spent 2, spell lands at frame [165, 169, 196], sounds [8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 187].
- cast `E9 04 0C`: command `44 04`, 225 frames, MP spent 2, spell lands at frame [172, 174, 223], sounds [8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187].

### 15 Nemesis Owl

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10], poses [0], swing yes.
- pose `40 00`: 75 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 02 12`: command `44 02`, 130 frames, MP spent 2, spell lands at frame [94, 98, 126], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 02 12`: command `44 02`, 155 frames, MP spent 2, spell lands at frame [102, 104, 153], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 02 14`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [178].
- cast `E9 02 14`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [178].

### 16 Pebbler

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10, 15], poses [0], swing yes.
- pose `40 00`: 70 frames, displacement (0, 0), sounds [], weapon box frames [].

### 17 Pumpkin Bomb

Script uses ordinary animations [0, 1, 2, 4], flags [0, 10, 180], poses [0, 1, 3], swing no.
- pose `40 00`: 60 frames, displacement (0, 0), sounds [171], weapon box frames [].
- pose `40 01`: 20 frames, displacement (0, 0), sounds [158], weapon box frames [].
- pose `40 03`: 80 frames, displacement (0, 0), sounds [167], weapon box frames [].
- cast `E9 02 1F`: command `44 02`, 15 frames, MP spent 4, spell lands at frame [10], sounds [].
- cast `E9 02 1F`: command `44 02`, 15 frames, MP spent 4, spell lands at frame [10], sounds [].
- transform: {"op": "EF", "command": [129, 5, 254, 0], "frames": 5}

### 18 Steamed Crab

Script uses ordinary animations [0, 1, 2, 4, 5, 8], flags [0, 5, 15, 180], poses [0, 4], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 04`: 85 frames, displacement (0, 0), sounds [], weapon box frames [[35, 39], [40, 44], [45, 49], [50, 54], [55, 59]].
- cast `E9 03 15`: command `44 03`, 180 frames, MP spent 3, spell lands at frame [143, 148, 176], sounds [72, 72, 72].
- cast `E9 03 15`: command `44 03`, 205 frames, MP spent 3, spell lands at frame [152, 154, 203], sounds [72, 72, 72].

### 19 Chess Knight

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 15, 30], poses [0, 2], swing yes.
- pose `40 00`: 45 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 40 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 04`: command `44 03`, 105 frames, MP spent 3, spell lands at frame [100], sounds [177].
- cast `E9 03 04`: command `44 03`, 105 frames, MP spent 3, spell lands at frame [100], sounds [177].

### 1A Wizard Eye

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 180], poses [0, 3], swing yes.
- pose `40 00`: 80 frames, displacement (0, 0), sounds [171], weapon box frames [[65, 74]].
- pose `40 03`: 45 frames, displacement (0, 0), sounds [61], weapon box frames [[5, 9], [15, 24], [25, 29], [30, 44]].
- cast `E9 02 0A`: command `44 02`, 110 frames, MP spent 1, spell lands at frame [105], sounds [184].
- cast `E9 02 0A`: command `44 02`, 110 frames, MP spent 1, spell lands at frame [105], sounds [184].
- cast `E9 02 0B`: command `44 02`, 110 frames, MP spent 2, spell lands at frame [105], sounds [].
- cast `E9 02 0B`: command `44 02`, 110 frames, MP spent 2, spell lands at frame [105], sounds [].
- cast `E9 02 26`: command `44 02`, 110 frames, MP spent 4, spell lands at frame [105], sounds [205].
- cast `E9 02 26`: command `44 02`, 110 frames, MP spent 4, spell lands at frame [105], sounds [205].
- create `ED 33`: object 51 appears in a free monster slot (5 frames).

### 1B Howler

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 14], flags [0, 5, 60], poses [2], swing yes.
- pose `40 02`: 20 frames, displacement (0, 37), sounds [139, 139], weapon box frames [[0, 4], [5, 9], [10, 14], [15, 19]].
- cast `E9 05 02`: command `44 05`, 80 frames, MP spent 1, spell lands at frame [75], sounds [202].
- cast `E9 05 02`: command `44 05`, 80 frames, MP spent 1, spell lands at frame [75], sounds [202].

### 1C Robin Foot

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10, 60], poses [0], swing yes.
- pose `40 00`: 25 frames, displacement (0, 25), sounds [], weapon box frames [].
- cast `E9 02 0F`: command `44 02`, 175 frames, MP spent 2, spell lands at frame [138, 143, 171], sounds [72, 72, 72].
- cast `E9 02 0F`: command `44 02`, 200 frames, MP spent 2, spell lands at frame [147, 149, 198], sounds [72, 72, 72].
- projectile of swing 1 (facing right): launched at frame 30 at offset [10, -11], lives to frame 49, end offset [61, 0], kind 1; damage seen [106, 107].

### 1D LA Funk

Script uses ordinary animations [0, 1, 2, 4], flags [0, 15, 60, 180], poses [0], swing yes.
- pose `40 00`: 25 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 06`: command `44 04`, 50 frames, MP spent 2, spell lands at frame [45], sounds [].
- cast `E9 04 06`: command `44 04`, 50 frames, MP spent 2, spell lands at frame [45], sounds [].
- cast `E9 04 07`: command `44 04`, 50 frames, MP spent 3, spell lands at frame [45], sounds [180].
- cast `E9 04 07`: command `44 04`, 50 frames, MP spent 3, spell lands at frame [45], sounds [180].
- create `ED 1D`: object 29 appears in a free monster slot (5 frames).
- transform: {"op": "EF", "command": [129, 5, 251, 0], "frames": 5}

### 1E Grave Bat

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10, 120], poses [0], swing yes.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 26`: command `44 03`, 85 frames, MP spent 4, spell lands at frame [65], sounds [205].
- cast `E9 03 26`: command `44 03`, 85 frames, MP spent 4, spell lands at frame [65], sounds [205].

### 1F Werewolf

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 14], flags [0, 5, 10, 60], poses [0, 2], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 20 frames, displacement (0, 38), sounds [153], weapon box frames [[0, 19]].
- cast `E9 08 0B`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [].
- cast `E9 08 0B`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [].
- cast `E9 08 1C`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [185].
- cast `E9 08 1C`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [185].

### 21 Evil Sword

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5], poses [0, 3, 6, 7, 12], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [[25, 29]].
- pose `40 03`: 40 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 06`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0C`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 1B`: command `44 04`, 125 frames, MP spent 3, spell lands at frame [91, 96, 121], sounds [72, 72, 72].
- cast `E9 04 1B`: command `44 04`, 150 frames, MP spent 3, spell lands at frame [98, 101, 147], sounds [72, 72, 72].

### 22 Tomato Man

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 10, 15, 60], poses [0, 2, 3], swing no.
- pose `40 00`: 15 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 225 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 03`: 70 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 01 05`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [162].
- cast `E9 01 05`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [162].
- cast `E9 01 0A`: command `44 01`, 140 frames, MP spent 1, spell lands at frame [135], sounds [184].
- cast `E9 01 0A`: command `44 01`, 140 frames, MP spent 1, spell lands at frame [135], sounds [184].
- cast `E9 01 0B`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [].
- cast `E9 01 0B`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [].
- cast `E9 01 0C`: command `44 01`, 210 frames, MP spent 2, spell lands at frame [171, 177, 206], sounds [8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 8, 187].
- cast `E9 01 0C`: command `44 01`, 235 frames, MP spent 2, spell lands at frame [181, 184, 233], sounds [8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187].
- create `ED 12`: object 18 appears in a free monster slot (5 frames).

### 23 Mystic Book

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10], poses [0, 2, 3, 4, 7, 8], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 80 frames, displacement (0, 0), sounds [156], weapon box frames [].
- pose `40 03`: 65 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 04`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 60 frames, displacement (0, 0), sounds [156], weapon box frames [].
- pose `40 08`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 05 06`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [5], sounds [86].
- cast `E9 05 06`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [5], sounds [86].
- cast `E9 05 08`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [5], sounds [174].
- cast `E9 05 08`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [5], sounds [174].
- cast `E9 05 12`: command `44 05`, 160 frames, MP spent 2, spell lands at frame [46, 50, 76], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 56, 80, 79].
- cast `E9 05 12`: command `44 05`, 185 frames, MP spent 2, spell lands at frame [52, 55, 102], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 80, 79].
- cast `E9 05 13`: command `44 05`, 90 frames, MP spent 4, spell lands at frame [5], sounds [22].
- cast `E9 05 13`: command `44 05`, 90 frames, MP spent 4, spell lands at frame [5], sounds [22].
- cast `E9 05 29`: command `44 05`, 90 frames, MP spent 4, spell lands at frame [5], sounds [165].
- cast `E9 05 29`: command `44 05`, 90 frames, MP spent 4, spell lands at frame [5], sounds [165].

### 24 Sand Stinger

Script uses ordinary animations [0, 1, 2, 4, 5, 8, 14], flags [0, 5, 10, 15], poses [0, 3], swing yes.
- pose `40 00`: 60 frames, displacement (0, 0), sounds [171], weapon box frames [[40, 44]].
- pose `40 03`: 50 frames, displacement (0, 0), sounds [11], weapon box frames [[5, 9], [10, 49]].
- cast `E9 04 05`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [162].
- cast `E9 04 05`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [162].

### 25 Mad Mallard

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 10], poses [0, 5, 7], swing yes.
- pose `40 00`: 35 frames, displacement (0, 0), sounds [171], weapon box frames [].
- pose `40 05`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- create `ED 17`: object 23 appears in a free monster slot (5 frames).

### 26 Emberman

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 10, 120], poses [0, 1, 5], swing yes.
- pose `40 00`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 01`: 30 frames, displacement (0, 0), sounds [17], weapon box frames [[0, 14], [15, 29]].
- pose `40 05`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 0E`: command `44 04`, 115 frames, MP spent 3, spell lands at frame [110], sounds [].
- cast `E9 04 0E`: command `44 04`, 115 frames, MP spent 3, spell lands at frame [110], sounds [].
- create `ED 26`: object 38 appears in a free monster slot (5 frames).

### 27 Red Drop

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 10], poses [0, 6], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [[0, 9], [10, 19], [20, 39]].
- pose `40 06`: 25 frames, displacement (0, 0), sounds [61], weapon box frames [[0, 9], [10, 24]].
- create `ED 27`: object 39 appears in a free monster slot (5 frames).

### 28 Eggatrice

Script uses ordinary animations [0, 1, 2, 3, 4, 7, 11, 14], flags [0, 5, 10, 15, 30, 60], poses [0, 3], swing yes.
- pose `40 00`: 175 frames, displacement (0, 0), sounds [81, 81, 81], weapon box frames [].
- pose `40 03`: 30 frames, displacement (0, 0), sounds [], weapon box frames [[0, 14]].

### 29 Bomb Bee

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 120], poses [0], swing yes.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 0D`: command `44 04`, 325 frames, MP spent 0, spell lands at frame [], sounds [].
- cast `E9 04 0D`: command `44 04`, 325 frames, MP spent 0, spell lands at frame [], sounds [].

### 2A Mushgloom

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10], poses [1], swing yes.
- pose `40 01`: 30 frames, displacement (0, 0), sounds [], weapon box frames [[15, 19], [20, 24]].
- cast `E9 06 22`: command `44 06`, 75 frames, MP spent 6, spell lands at frame [65], sounds [165].
- cast `E9 06 22`: command `44 06`, 75 frames, MP spent 6, spell lands at frame [65], sounds [165].

### 2B Trap Flower

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10], poses [0, 4, 7], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [], weapon box frames [[0, 9], [10, 14], [15, 19], [20, 24]].
- pose `40 04`: 20 frames, displacement (0, 0), sounds [158], weapon box frames [[0, 19]].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [[0, 4]].
- cast `E9 03 08`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [174].
- cast `E9 03 08`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [174].
- cast `E9 03 1E`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [199].
- cast `E9 03 1E`: command `44 03`, 100 frames, MP spent 2, spell lands at frame [95], sounds [199].

### 2C Dinofish

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 14], flags [0, 5, 120], poses [0, 6], swing yes.
- pose `40 00`: 20 frames, displacement (0, 20), sounds [], weapon box frames [].
- pose `40 06`: 30 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 07 06`: command `44 07`, 120 frames, MP spent 2, spell lands at frame [105], sounds [].
- cast `E9 07 06`: command `44 07`, 120 frames, MP spent 2, spell lands at frame [105], sounds [].
- cast `E9 07 07`: command `44 07`, 120 frames, MP spent 3, spell lands at frame [105], sounds [180].
- cast `E9 07 07`: command `44 07`, 120 frames, MP spent 3, spell lands at frame [105], sounds [180].
- transform: {"op": "EF", "command": [129, 5, 44, 0], "frames": 5}

### 2D Mimic Box

Script uses ordinary animations [0, 1, 2, 4, 9, 14], flags [0, 5, 180], poses [0, 3, 5], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [], weapon box frames [[0, 24]].
- pose `40 03`: 55 frames, displacement (0, 0), sounds [76], weapon box frames [].
- pose `40 05`: 5 frames, displacement (0, 0), sounds [], weapon box frames [[0, 4]].
- cast `E9 04 1A`: command `44 04`, 275 frames, MP spent 8, spell lands at frame [65], sounds [194].
- cast `E9 04 1A`: command `44 04`, 275 frames, MP spent 8, spell lands at frame [65], sounds [194].

### 2F Kimono Wizard

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 15, 180], poses [0, 3], swing no.
- pose `40 00`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 03`: 65 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 01 06`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [].
- cast `E9 01 06`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [].
- cast `E9 01 08`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [174].
- cast `E9 01 08`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [174].
- cast `E9 01 12`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [101, 107, 136], sounds [48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 01 12`: command `44 01`, 165 frames, MP spent 2, spell lands at frame [111, 114, 163], sounds [48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56, 48, 56, 48, 48, 48, 48, 48, 48, 48, 48, 48, 56].
- cast `E9 01 13`: command `44 01`, 70 frames, MP spent 4, spell lands at frame [65], sounds [].
- cast `E9 01 13`: command `44 01`, 70 frames, MP spent 4, spell lands at frame [65], sounds [].
- cast `E9 01 14`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [178].
- cast `E9 01 14`: command `44 01`, 70 frames, MP spent 2, spell lands at frame [65], sounds [178].
- create `ED 31`: object 49 appears in a free monster slot (5 frames).

### 30 Ghost

Script uses ordinary animations [0, 1, 2, 3, 4, 11], flags [0, 30, 180], poses [0, 3], swing no.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [64], weapon box frames [].
- pose `40 03`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 01 08`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [174].
- cast `E9 01 08`: command `44 01`, 25 frames, MP spent 2, spell lands at frame [20], sounds [174].
- cast `E9 02 06`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [].
- cast `E9 02 06`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [].
- cast `E9 02 08`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [174].
- cast `E9 02 08`: command `44 02`, 60 frames, MP spent 2, spell lands at frame [55], sounds [174].

### 31 Metal Crawler

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 15, 180], poses [0, 3], swing yes.
- pose `40 00`: 65 frames, displacement (0, 30), sounds [], weapon box frames [].
- pose `40 03`: 50 frames, displacement (0, 38), sounds [], weapon box frames [[0, 4], [5, 9], [10, 14], [15, 19], [20, 24], [25, 29], [30, 34], [35, 39], [40, 44], [45, 49]].
- cast `E9 05 22`: command `44 05`, 115 frames, MP spent 6, spell lands at frame [110], sounds [165].
- cast `E9 05 22`: command `44 05`, 115 frames, MP spent 6, spell lands at frame [110], sounds [165].

### 32 Spider Legs

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 240], poses [0, 2], swing no.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 190 frames, displacement (0, 0), sounds [171], weapon box frames [[10, 19], [35, 44]].
- cast `E9 01 00`: command `44 01`, 100 frames, MP spent 3, spell lands at frame [60], sounds [176].
- cast `E9 01 00`: command `44 01`, 100 frames, MP spent 3, spell lands at frame [60], sounds [176].
- cast `E9 01 01`: command `44 01`, 100 frames, MP spent 2, spell lands at frame [60], sounds [49].
- cast `E9 01 01`: command `44 01`, 100 frames, MP spent 2, spell lands at frame [60], sounds [49].

### 33 Weepy Eye

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 10, 15, 120], poses [0, 2], swing yes.
- pose `40 00`: 65 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 50 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 28`: command `44 03`, 105 frames, MP spent 8, spell lands at frame [100], sounds [].
- cast `E9 03 28`: command `44 03`, 105 frames, MP spent 8, spell lands at frame [100], sounds [].

### 34 Shellblast

Script uses ordinary animations [0, 1, 2, 4, 7, 11], flags [0, 5, 10, 120], poses [3, 4, 7], swing yes.
- pose `40 03`: 65 frames, displacement (0, 38), sounds [170, 170, 170, 170, 170], weapon box frames [[0, 4], [5, 54], [55, 59]].
- pose `40 04`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 05 09`: command `44 05`, 160 frames, MP spent 2, spell lands at frame [123, 128, 156], sounds [72, 72, 72].
- cast `E9 05 09`: command `44 05`, 185 frames, MP spent 2, spell lands at frame [132, 134, 183], sounds [72, 72, 72].
- cast `E9 05 0B`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [85], sounds [].
- cast `E9 05 0B`: command `44 05`, 90 frames, MP spent 2, spell lands at frame [85], sounds [].

### 35 Beast Zombie

Script uses ordinary animations [0, 1, 2, 3, 4], flags [0, 60], poses [2], swing yes.
- pose `40 02`: 20 frames, displacement (0, 37), sounds [139, 139], weapon box frames [[0, 4], [5, 9], [10, 14], [15, 19]].
- cast `E9 05 02`: command `44 05`, 80 frames, MP spent 1, spell lands at frame [75], sounds [202].
- cast `E9 05 02`: command `44 05`, 80 frames, MP spent 1, spell lands at frame [75], sounds [202].
- cast `E9 05 07`: command `44 05`, 80 frames, MP spent 3, spell lands at frame [75], sounds [181].
- cast `E9 05 07`: command `44 05`, 80 frames, MP spent 3, spell lands at frame [75], sounds [181].

### 36 Ghoul

Script uses ordinary animations [0, 1, 2, 3, 4], flags [0, 5, 10, 60], poses [0, 3, 4], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [170, 170, 170, 170], weapon box frames [[0, 9], [10, 19], [20, 29]].
- pose `40 03`: 60 frames, displacement (0, 0), sounds [28, 170], weapon box frames [[0, 4], [5, 9], [10, 19], [20, 29], [30, 34], [35, 39], [40, 44], [45, 54]].
- pose `40 04`: 115 frames, displacement (0, -40), sounds [170], weapon box frames [[100, 114]].
- cast `E9 04 02`: command `44 04`, 120 frames, MP spent 1, spell lands at frame [115], sounds [202, 170].
- cast `E9 04 02`: command `44 04`, 120 frames, MP spent 1, spell lands at frame [115], sounds [202, 170].
- cast `E9 04 04`: command `44 04`, 120 frames, MP spent 3, spell lands at frame [115], sounds [177, 170].
- cast `E9 04 04`: command `44 04`, 120 frames, MP spent 3, spell lands at frame [115], sounds [177, 170].

### 37 Imp

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 180], poses [0], swing yes.
- pose `40 00`: 80 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 05 0C`: command `44 05`, 185 frames, MP spent 2, spell lands at frame [149, 153, 181], sounds [158, 158, 158, 158, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 8, 8, 8, 8, 8, 187].
- cast `E9 05 0C`: command `44 05`, 210 frames, MP spent 2, spell lands at frame [157, 159, 208], sounds [158, 158, 158, 158, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187, 8, 187, 8, 8, 8, 8, 8, 8, 8, 8, 8, 187].
- cast `E9 05 0D`: command `44 05`, 115 frames, MP spent 4, spell lands at frame [110], sounds [158, 158, 158, 158].
- cast `E9 05 0D`: command `44 05`, 115 frames, MP spent 4, spell lands at frame [110], sounds [158, 158, 158, 158].
- cast `E9 05 10`: command `44 05`, 115 frames, MP spent 3, spell lands at frame [110], sounds [158, 158, 158, 158, 73].
- cast `E9 05 10`: command `44 05`, 115 frames, MP spent 3, spell lands at frame [110], sounds [158, 158, 158, 158, 73].
- projectile of swing 1 (facing right): launched at frame 15 at offset [10, -10], lives to frame 35, end offset [66, 2], kind 1; damage seen [141, 142].
- projectile of pose 2 (facing right): launched at frame 15 at offset [10, -10], lives to frame 34, end offset [61, 1], kind 1; damage seen [94, 95].

### 38 Blue Drop

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10], poses [0, 6], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [[0, 9], [10, 19], [20, 39]].
- pose `40 06`: 25 frames, displacement (0, 0), sounds [61], weapon box frames [[0, 9], [10, 24]].
- create `ED 38`: object 56 appears in a free monster slot (5 frames).

### 39 Marmablue

Script uses ordinary animations [0, 1, 2, 3, 4], flags [0, 60, 180], poses [0], swing no.
- pose `40 00`: 160 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 01 19`: command `44 01`, 65 frames, MP spent 1, spell lands at frame [40], sounds [174].
- cast `E9 01 19`: command `44 01`, 65 frames, MP spent 1, spell lands at frame [40], sounds [174].
- cast `E9 03 1A`: command `44 03`, 60 frames, MP spent 8, spell lands at frame [55], sounds [].
- cast `E9 03 1A`: command `44 03`, 60 frames, MP spent 8, spell lands at frame [55], sounds [].
- cast `E9 03 1D`: command `44 03`, 130 frames, MP spent 2, spell lands at frame [96, 100, 126], sounds [190, 190, 190, 190, 190, 190, 190, 190, 190, 191, 190, 191, 190, 190, 190, 190, 190, 191].
- cast `E9 03 1D`: command `44 03`, 155 frames, MP spent 2, spell lands at frame [102, 105, 152], sounds [190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 191, 190, 191, 190, 190, 190, 190, 190, 190, 190, 190, 190, 191].

### 3A Fierce Head

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 10, 60, 240], poses [0, 4], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [], weapon box frames [[0, 4], [5, 14], [15, 24], [25, 34]].
- pose `40 04`: 40 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 03 0D`: command `44 03`, 60 frames, MP spent 4, spell lands at frame [55], sounds [].
- cast `E9 03 0D`: command `44 03`, 60 frames, MP spent 4, spell lands at frame [55], sounds [].
- cast `E9 03 0E`: command `44 03`, 60 frames, MP spent 3, spell lands at frame [55], sounds [].
- cast `E9 03 0E`: command `44 03`, 60 frames, MP spent 3, spell lands at frame [55], sounds [].
- cast `E9 03 25`: command `44 03`, 60 frames, MP spent 2, spell lands at frame [55], sounds [15].
- cast `E9 03 25`: command `44 03`, 60 frames, MP spent 2, spell lands at frame [55], sounds [15].
- create `ED 1E`: object 30 appears in a free monster slot (5 frames).

### 3B Griffin Hand

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 60, 180], poses [0, 5], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 05`: 10 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 14`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [178].
- cast `E9 04 14`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [178].
- cast `E9 04 16`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [178].
- cast `E9 04 16`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [178].
- cast `E9 04 1E`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [199].
- cast `E9 04 1E`: command `44 04`, 115 frames, MP spent 2, spell lands at frame [95], sounds [199].

### 3D Metal Crab

Script uses ordinary animations [0, 1, 2, 4, 8], flags [0, 5, 15, 180], poses [0, 1, 4], swing yes.
- pose `40 00`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 01`: 80 frames, displacement (0, 0), sounds [], weapon box frames [[50, 59], [60, 69]].
- pose `40 04`: 85 frames, displacement (0, 0), sounds [], weapon box frames [[35, 39], [40, 44], [45, 49], [50, 54], [55, 59]].
- cast `E9 03 27`: command `44 03`, 180 frames, MP spent 5, spell lands at frame [143, 148, 176], sounds [72, 72, 72].
- cast `E9 03 27`: command `44 03`, 205 frames, MP spent 5, spell lands at frame [152, 154, 203], sounds [72, 72, 72].

### 3E Armored Man

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 19, 20], flags [0, 10, 15, 60], poses [3], swing yes.
- pose `40 03`: 20 frames, displacement (0, 0), sounds [8], weapon box frames [].
- cast `E9 02 05`: command `44 02`, 65 frames, MP spent 2, spell lands at frame [60], sounds [162].
- cast `E9 02 05`: command `44 02`, 65 frames, MP spent 2, spell lands at frame [60], sounds [162].

### 3F Shadow X2

Script uses ordinary animations [0, 1, 2, 3, 4, 10, 11, 12, 49], flags [0, 5, 10, 15], poses [], swing yes.

### 40 Eggplant Man

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 10, 15, 60], poses [0, 2, 3], swing no.
- pose `40 00`: 15 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 225 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 03`: 70 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 01 05`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [162].
- cast `E9 01 05`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [162].
- cast `E9 01 0A`: command `44 01`, 140 frames, MP spent 1, spell lands at frame [135], sounds [184].
- cast `E9 01 0A`: command `44 01`, 140 frames, MP spent 1, spell lands at frame [135], sounds [184].
- cast `E9 01 0B`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [].
- cast `E9 01 0B`: command `44 01`, 140 frames, MP spent 2, spell lands at frame [135], sounds [].
- cast `E9 01 29`: command `44 01`, 140 frames, MP spent 4, spell lands at frame [135], sounds [165].
- cast `E9 01 29`: command `44 01`, 140 frames, MP spent 4, spell lands at frame [135], sounds [165].
- create `ED 00`: object 0 appears in a free monster slot (5 frames).
- create `ED 3C`: object 60 appears in a free monster slot (5 frames).

### 41 Captain Duck

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 15], poses [0, 5], swing yes.
- pose `40 00`: 35 frames, displacement (0, 0), sounds [171], weapon box frames [].
- pose `40 05`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 02 0D`: command `44 02`, 55 frames, MP spent 4, spell lands at frame [50], sounds [114].
- cast `E9 02 0D`: command `44 02`, 55 frames, MP spent 4, spell lands at frame [50], sounds [114].

### 42 Nitro Pumpkin

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 180, 240], poses [0, 1, 3], swing no.
- pose `40 00`: 60 frames, displacement (0, 0), sounds [171], weapon box frames [].
- pose `40 01`: 20 frames, displacement (0, 0), sounds [158], weapon box frames [].
- pose `40 03`: 80 frames, displacement (0, 0), sounds [167], weapon box frames [].
- cast `E9 02 1E`: command `44 02`, 15 frames, MP spent 2, spell lands at frame [10], sounds [199].
- cast `E9 02 1E`: command `44 02`, 15 frames, MP spent 2, spell lands at frame [10], sounds [199].
- cast `E9 02 1F`: command `44 02`, 15 frames, MP spent 4, spell lands at frame [10], sounds [].
- cast `E9 02 1F`: command `44 02`, 15 frames, MP spent 4, spell lands at frame [10], sounds [].
- cast `E9 02 22`: command `44 02`, 15 frames, MP spent 6, spell lands at frame [10], sounds [165].
- cast `E9 02 22`: command `44 02`, 15 frames, MP spent 6, spell lands at frame [10], sounds [165].
- create `ED 17`: object 23 appears in a free monster slot (5 frames).
- transform: {"op": "EF", "command": [129, 5, 254, 0], "frames": 5}

### 43 Turtlance

Script uses ordinary animations [0, 1, 2, 4, 5, 7, 11], flags [0, 5, 10, 120], poses [2, 3, 4, 7], swing yes.
- pose `40 02`: 85 frames, displacement (30, 0), sounds [166, 166, 166, 166, 80, 79, 166, 166, 166, 166, 166, 166, 1], weapon box frames [[0, 84]].
- pose `40 03`: 65 frames, displacement (0, 38), sounds [170, 170, 170, 170, 170], weapon box frames [[0, 4], [5, 54], [55, 59]].
- pose `40 04`: 20 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 05 1B`: command `44 05`, 160 frames, MP spent 3, spell lands at frame [123, 128, 156], sounds [72, 72, 72].
- cast `E9 05 1B`: command `44 05`, 185 frames, MP spent 3, spell lands at frame [132, 134, 183], sounds [72, 72, 72].
- cast `E9 05 27`: command `44 05`, 160 frames, MP spent 5, spell lands at frame [123, 128, 156], sounds [72, 72, 72].
- cast `E9 05 27`: command `44 05`, 185 frames, MP spent 5, spell lands at frame [132, 134, 183], sounds [72, 72, 72].

### 45 Basilisk

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 60, 120, 180], poses [0, 4], swing yes.
- pose `40 00`: 60 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 04`: 85 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 00`: command `44 03`, 135 frames, MP spent 3, spell lands at frame [130], sounds [176].
- cast `E9 03 00`: command `44 03`, 135 frames, MP spent 3, spell lands at frame [130], sounds [176].
- cast `E9 03 01`: command `44 03`, 135 frames, MP spent 2, spell lands at frame [130], sounds [49].
- cast `E9 03 01`: command `44 03`, 135 frames, MP spent 2, spell lands at frame [130], sounds [49].
- cast `E9 03 02`: command `44 03`, 135 frames, MP spent 1, spell lands at frame [130], sounds [202].
- cast `E9 03 02`: command `44 03`, 135 frames, MP spent 1, spell lands at frame [130], sounds [202].
- create `ED 28`: object 40 appears in a free monster slot (5 frames).

### 46 Gremlin

Script uses ordinary animations [0, 1, 2, 4, 14], flags [0, 5, 10, 180], poses [0], swing yes.
- pose `40 00`: 80 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 05 06`: command `44 05`, 115 frames, MP spent 2, spell lands at frame [110], sounds [158, 158, 158, 158].
- cast `E9 05 06`: command `44 05`, 115 frames, MP spent 2, spell lands at frame [110], sounds [158, 158, 158, 158].
- cast `E9 05 07`: command `44 05`, 115 frames, MP spent 3, spell lands at frame [110], sounds [158, 158, 158, 158, 181].
- cast `E9 05 07`: command `44 05`, 115 frames, MP spent 3, spell lands at frame [110], sounds [158, 158, 158, 158, 181].
- cast `E9 05 24`: command `44 05`, 115 frames, MP spent 8, spell lands at frame [110], sounds [158, 158, 158, 158, 179].
- cast `E9 05 24`: command `44 05`, 115 frames, MP spent 8, spell lands at frame [110], sounds [158, 158, 158, 158, 179].
- projectile of swing 2 (facing right): launched at frame 15 at offset [10, -10], lives to frame 37, end offset [81, 0], kind 1; damage seen [332, 335, 336, 339].
- projectile of pose 1 (facing right): launched at frame 15 at offset [10, -10], lives to frame 34, end offset [61, 1], kind 1; damage seen [111, 112].

### 47 Steelpion

Script uses ordinary animations [0, 1, 2, 4, 5, 8, 14], flags [0, 5, 10, 15], poses [0, 3], swing yes.
- pose `40 00`: 60 frames, displacement (0, 0), sounds [171], weapon box frames [[40, 44]].
- pose `40 03`: 50 frames, displacement (0, 0), sounds [11], weapon box frames [[5, 9], [10, 49]].
- cast `E9 04 01`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [49].
- cast `E9 04 01`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [49].
- cast `E9 04 05`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [162].
- cast `E9 04 05`: command `44 04`, 100 frames, MP spent 2, spell lands at frame [95], sounds [162].

### 48 Dark Ninja

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 15, 60, 180], poses [5, 7, 8, 11], swing yes.
- pose `40 05`: 135 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 08`: 45 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0B`: 20 frames, displacement (0, 20), sounds [], weapon box frames [].
- cast `E9 06 02`: command `44 06`, 50 frames, MP spent 1, spell lands at frame [45], sounds [201].
- cast `E9 06 02`: command `44 06`, 50 frames, MP spent 1, spell lands at frame [45], sounds [201].
- cast `E9 06 04`: command `44 06`, 50 frames, MP spent 3, spell lands at frame [45], sounds [177].
- cast `E9 06 04`: command `44 06`, 50 frames, MP spent 3, spell lands at frame [45], sounds [177].
- cast `E9 06 0F`: command `44 06`, 120 frames, MP spent 2, spell lands at frame [81, 87, 116], sounds [72, 72, 72].
- cast `E9 06 0F`: command `44 06`, 145 frames, MP spent 2, spell lands at frame [91, 94, 143], sounds [72, 72, 72].
- cast `E9 06 1F`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [].
- cast `E9 06 1F`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [].
- transform: {"op": "EF", "command": [129, 5, 254, 0], "frames": 5}
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -22], lives to frame 50, end offset [7, -14], kind 5; damage seen [143, 146, 147, 148].

### 49 Whimper

Script uses ordinary animations [0, 1, 2, 4, 5, 14], flags [0, 5, 10, 15, 180], poses [0, 2, 4], swing yes.
- pose `40 00`: 65 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 02`: 50 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 04`: 110 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 03 00`: command `44 03`, 105 frames, MP spent 3, spell lands at frame [100], sounds [176].
- cast `E9 03 00`: command `44 03`, 105 frames, MP spent 3, spell lands at frame [100], sounds [176].
- cast `E9 03 1E`: command `44 03`, 105 frames, MP spent 2, spell lands at frame [100], sounds [199].
- cast `E9 03 1E`: command `44 03`, 105 frames, MP spent 2, spell lands at frame [100], sounds [199].
- cast `E9 03 22`: command `44 03`, 105 frames, MP spent 6, spell lands at frame [100], sounds [165].
- cast `E9 03 22`: command `44 03`, 105 frames, MP spent 6, spell lands at frame [100], sounds [165].

### 4A Heck Hound

Script uses ordinary animations [0, 1, 2, 3, 4, 5], flags [0, 5, 180], poses [3, 4], swing yes.
- pose `40 03`: 35 frames, displacement (0, 0), sounds [80, 79], weapon box frames [[20, 34]].
- pose `40 04`: 55 frames, displacement (0, 0), sounds [218], weapon box frames [].
- cast `E9 05 11`: command `44 05`, 80 frames, MP spent 4, spell lands at frame [75], sounds [189].
- cast `E9 05 11`: command `44 05`, 80 frames, MP spent 4, spell lands at frame [75], sounds [189].
- create `ED 1B`: object 27 appears in a free monster slot (5 frames).
- create `ED 35`: object 53 appears in a free monster slot (5 frames).

### 4B Fiend Head

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 10, 120, 240], poses [0, 4], swing yes.
- pose `40 00`: 40 frames, displacement (0, 0), sounds [], weapon box frames [[0, 4], [5, 14], [15, 24], [25, 34]].
- pose `40 04`: 40 frames, displacement (0, 0), sounds [61], weapon box frames [].
- cast `E9 03 0D`: command `44 03`, 60 frames, MP spent 4, spell lands at frame [55], sounds [].
- cast `E9 03 0D`: command `44 03`, 60 frames, MP spent 4, spell lands at frame [55], sounds [].
- cast `E9 03 0E`: command `44 03`, 60 frames, MP spent 3, spell lands at frame [55], sounds [].
- cast `E9 03 0E`: command `44 03`, 60 frames, MP spent 3, spell lands at frame [55], sounds [].
- cast `E9 03 25`: command `44 03`, 60 frames, MP spent 2, spell lands at frame [55], sounds [15].
- cast `E9 03 25`: command `44 03`, 60 frames, MP spent 2, spell lands at frame [55], sounds [15].
- create `ED 4D`: object 77 appears in a free monster slot (5 frames).

### 4D Dark Stalker

Script uses ordinary animations [0, 1, 2, 3, 4, 5], flags [0, 5, 10, 30, 60, 120], poses [1, 11], swing yes.
- pose `40 01`: 80 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0B`: 20 frames, displacement (0, 20), sounds [], weapon box frames [].
- cast `E9 06 07`: command `44 06`, 50 frames, MP spent 3, spell lands at frame [45], sounds [181].
- cast `E9 06 07`: command `44 06`, 50 frames, MP spent 3, spell lands at frame [45], sounds [181].
- cast `E9 06 09`: command `44 06`, 120 frames, MP spent 2, spell lands at frame [81, 87, 116], sounds [72, 72, 72].
- cast `E9 06 09`: command `44 06`, 145 frames, MP spent 2, spell lands at frame [91, 94, 143], sounds [72, 72, 72].
- cast `E9 06 26`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [205].
- cast `E9 06 26`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [205].
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -22], lives to frame 60, end offset [0, -14], kind 5; damage seen [302, 308, 309, 311, 313, 315].

### 4E Dark Knight

Script uses ordinary animations [0, 1, 2, 3, 4, 14], flags [0, 5, 10, 15, 60, 120], poses [1, 3, 4], swing yes.
- pose `40 01`: 60 frames, displacement (0, 0), sounds [8, 8, 8], weapon box frames [[40, 44]].
- pose `40 03`: 20 frames, displacement (0, 0), sounds [8], weapon box frames [].
- pose `40 04`: 80 frames, displacement (0, 38), sounds [8, 8, 8, 8], weapon box frames [].
- cast `E9 02 22`: command `44 02`, 65 frames, MP spent 6, spell lands at frame [60], sounds [165].
- cast `E9 02 22`: command `44 02`, 65 frames, MP spent 6, spell lands at frame [60], sounds [165].
- cast `E9 02 25`: command `44 02`, 65 frames, MP spent 2, spell lands at frame [60], sounds [15].
- cast `E9 02 25`: command `44 02`, 65 frames, MP spent 2, spell lands at frame [60], sounds [15].

### 4F Shape Shifter

Script uses ordinary animations [0, 1, 2, 4], flags [0, 5, 10, 30], poses [0, 6, 9], swing no.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 06`: 25 frames, displacement (0, 0), sounds [61], weapon box frames [].
- pose `40 09`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- create `ED 4F`: object 79 appears in a free monster slot (5 frames).
- transform: {"op": "EF", "command": [129, 5, 0, 0], "frames": 5}
- transform: {"op": "EF", "command": [129, 5, 45, 0], "frames": 5}
- transform: {"op": "EF", "command": [129, 5, 53, 0], "frames": 5}
- transform: {"op": "EF", "command": [129, 5, 64, 0], "frames": 5}
- transform: {"op": "EF", "command": [129, 5, 65, 0], "frames": 5}
- transform: {"op": "EF", "command": [129, 5, 252, 0], "frames": 5}

### 50 Wolf Lord

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 14], flags [0, 5, 10, 60], poses [2, 6], swing yes.
- pose `40 02`: 20 frames, displacement (0, 38), sounds [153], weapon box frames [[0, 19]].
- pose `40 06`: 45 frames, displacement (0, 0), sounds [], weapon box frames [[25, 44]].
- cast `E9 08 0B`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [].
- cast `E9 08 0B`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [].
- cast `E9 08 1B`: command `44 08`, 165 frames, MP spent 3, spell lands at frame [125, 132, 161], sounds [72, 72, 72].
- cast `E9 08 1B`: command `44 08`, 190 frames, MP spent 3, spell lands at frame [136, 138, 188], sounds [72, 72].
- cast `E9 08 1C`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [185].
- cast `E9 08 1C`: command `44 08`, 95 frames, MP spent 2, spell lands at frame [90], sounds [185].

### 51 Doom Sword

Script uses ordinary animations [0, 1, 2, 4, 5], flags [0, 5, 60], poses [0, 3, 6, 8, 9, 10, 11, 12], swing yes.
- pose `40 00`: 50 frames, displacement (0, 0), sounds [], weapon box frames [[25, 29]].
- pose `40 03`: 40 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 06`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 08`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 09`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0A`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0B`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0C`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- cast `E9 04 03`: command `44 04`, 125 frames, MP spent 4, spell lands at frame [91, 96, 121], sounds [72, 72, 72].
- cast `E9 04 03`: command `44 04`, 150 frames, MP spent 4, spell lands at frame [98, 101, 147], sounds [72, 72, 72].
- cast `E9 04 09`: command `44 04`, 125 frames, MP spent 2, spell lands at frame [91, 96, 121], sounds [72, 72, 72].
- cast `E9 04 09`: command `44 04`, 150 frames, MP spent 2, spell lands at frame [98, 101, 147], sounds [72, 72, 72].
- cast `E9 04 0F`: command `44 04`, 125 frames, MP spent 2, spell lands at frame [91, 96, 121], sounds [72, 72, 72].
- cast `E9 04 0F`: command `44 04`, 150 frames, MP spent 2, spell lands at frame [98, 101, 147], sounds [72, 72, 72].
- cast `E9 04 15`: command `44 04`, 125 frames, MP spent 3, spell lands at frame [91, 96, 121], sounds [72, 72, 72].
- cast `E9 04 15`: command `44 04`, 150 frames, MP spent 3, spell lands at frame [98, 101, 147], sounds [72, 72, 72].

### 52 Terminator

Script uses ordinary animations [0, 1, 2, 3, 4, 5], flags [0, 5, 10, 15, 60, 180], poses [3, 4], swing yes.
- pose `40 03`: 20 frames, displacement (0, 0), sounds [8], weapon box frames [].
- pose `40 04`: 80 frames, displacement (0, 38), sounds [8, 8, 8, 8], weapon box frames [].
- cast `E9 02 28`: command `44 02`, 65 frames, MP spent 8, spell lands at frame [60], sounds [].
- cast `E9 02 28`: command `44 02`, 65 frames, MP spent 8, spell lands at frame [60], sounds [].
- cast `E9 02 29`: command `44 02`, 65 frames, MP spent 4, spell lands at frame [60], sounds [165].
- cast `E9 02 29`: command `44 02`, 65 frames, MP spent 4, spell lands at frame [60], sounds [165].

### 53 Master Ninja

Script uses ordinary animations [0, 1, 2, 3, 4, 5, 14], flags [0, 5, 10, 15, 60, 120], poses [0, 1, 5, 7, 8, 11], swing yes.
- pose `40 00`: 90 frames, displacement (0, 0), sounds [], weapon box frames [[5, 34]].
- pose `40 01`: 80 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 05`: 135 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 07`: 5 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 08`: 45 frames, displacement (0, 0), sounds [], weapon box frames [].
- pose `40 0B`: 20 frames, displacement (0, 20), sounds [], weapon box frames [].
- cast `E9 06 03`: command `44 06`, 120 frames, MP spent 4, spell lands at frame [81, 87, 116], sounds [72, 72, 72].
- cast `E9 06 03`: command `44 06`, 145 frames, MP spent 4, spell lands at frame [91, 94, 143], sounds [72, 72, 72].
- cast `E9 06 0D`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [].
- cast `E9 06 0D`: command `44 06`, 50 frames, MP spent 4, spell lands at frame [45], sounds [].
- cast `E9 06 22`: command `44 06`, 50 frames, MP spent 6, spell lands at frame [45], sounds [165].
- cast `E9 06 22`: command `44 06`, 50 frames, MP spent 6, spell lands at frame [45], sounds [165].
- projectile of swing 2 (facing right): launched at frame 10 at offset [10, -22], lives to frame 76, end offset [2, -14], kind 5; damage seen [563, 574, 575, 582, 586].

## Open questions

- Not measured (the harness timed out or the run takes too long): 20 2E 3C 44 4C.
- Command 0x81 (transform into the death-effect objects 0xFE / 0xFB) was executed, the later life of those objects was not followed.
- Objects created by command 0x43 above 0x1F (Wizard Eye creates 0x33) are not described here.
- Wall collision of long moves (see `conflicts`).
