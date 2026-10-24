# Complete cast sprite workspace and emission composition

The readable CastSprites model implements native workspace initialization, depth ordering, complete HUD/ordinary actor/shadow/boss emission and the cast emission wrapper. It reuses actual existing render contracts. This is software sprite preparation; no hardware display or NMI timing is claimed. C10038 temporary entities and C18707 remain open.

| Entry | Candidate instruction bytes | Role |
|---|---:|---|
| C0E328 | 4 | Cast sprite emission long wrapper |
| C0E32C | 37 | Cast sprite workspace emission |
| C0E351 | 4 | Workspace initialization long wrapper |
| C0E355 | 45 | Initialize map sprite workspace |
| C0E38E | 65 | Emit HUD and both actor groups and bosses |
| C0E3CF | 63 | Emit one ordinary/boss actor |
| C0E8D7 | 285 | Sort both sprite actor groups by depth |

The503 candidate bytes are assessed against existing exact matching sources during integration. Existing initialization/ordering/render sources receive no duplicate credit.

Initialization sets software OAM offscreen, clears its high-bit workspace and invokes real ordering. Ordering scans the original12actor range or shorter sixactor range under ED/5C, picks a group from actor field0B and retains exact comparison/insertion behavior and shifted depth/actor arrays. Its CPU contract preserves the actual final registers,16bit arithmetic and bank restoration flags.

C0E38E invokes the real HUD emitter, traverses each actor list in reverse order, then executes actual alternating boss emission when5C is negative. C0E3CF preserves original actor guards and boss selection, optional effect selection, saved X and ordinary update→shadow composition. The cast wrapper saves ED, temporarily sets40, initializes and emits with its original OAM cursors and restores ED. No native call is replaced by a hook.

## Evidence and scope

1,280 complete original calls passed:128for each of six wrappers/body entries,512for ordering. Coverage contains1,645 PC/M/X states. Comparisons include all WRAM outside129 temporary caller-stack bytes, fullCPU/S/D/DB, peripherals and ordered audio. Domain: D0/DB7E/X16/binary,both M widths;12aligned actors;bounded actual HUD and ordinary sprite pieces;inactive/live/signed actor guards;both depth groups;ED/5C short/full scans;original boss ActorFrame fixture domain including its actual callbacks. No NMI is required.

The main fixture uses E060zero for boss actors. A separate supplementary harness covers the active E060 boss effect selection route without modifying this stable implementation. The extreme C0E97C shift entry requires a group larger than natural12actor capacity; its prior exact matching source is reused, not credited as newly executed here.

Declared dependency and coverage tool hashes match current source. ROM tables and sprite assets remain runtime-only. The remaining coordinator work requires real spell entity allocation, construction, scheduling and callbacks.
