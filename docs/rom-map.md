# ROM map: what is mapped, what is missing, and the steps to finish it

Goal: a complete map of the 2 MiB USA ROM, with every byte classified as code (with its function, M/X state and callers), data (with its format) or padding. The map is the base for a later recompilation of the game code to a native PC program (section 6); the work items below are ordered so that a session told to "continue decompiling" can take the first open item of section 5 and work on it.

Tags as in `docs/rom-combat.md`: **[V]** executed in the interpreter, **[C]** read from the disassembly. Numbers marked *estimate* are judgements, not measurements.

## 1. How to measure

For the audited documented-coverage percentage requested by the project owner, use `tools/rom_progress.py ROM --write` and `docs/progress.md`. That catalogue-based lower bound is separate from the speculative instruction scan below.

```
python3 tools/rom_map.py ROM [--json OUT] [--list-unknown N]
```

- **Code** = instructions reached by `flowdis.py` from the reset vector and from every `JSL` found by a byte scan of the ROM (`22 ll hh bb` with a bank `C0-DF`). A scan hit can be data that looks like a `JSL`, and code reached only through jump tables or RAM is missed, so this figure is an estimate in both directions until step M2 replaces it with traced coverage.
- **Padding** = runs of 32 or more `00` or `FF` bytes outside code.
- **Function** = an entry point (reset vector, `JSL`/`JSR`/`JML`/`JMP abs` target); every instruction belongs to the closest entry before it in the same bank.
- **Documented** = a function containing an address cited as `$Cx:xxxx` in `docs/*.md`; **[V]** = one of those lines carries a `[V]` tag.
- `--list-unknown N` lists the N largest unclassified runs (the work queue of step M7).

## 2. Measured state (2026-10-06, `tools/rom_map.py`)

| Measure | Value |
|---|---|
| Code reached from the vectors alone | 218 B (0.0 %): the boot jumps to RAM, see 3.1 |
| Code reached with the `JSL` scan | 157,038 B = **7.5 %** of the ROM |
| Padding | 1.8 % |
| Not classified (data, or code the scan misses) | 90.7 % |
| Functions found | 1,610 |
| Functions cited in `docs/` | 336 (20.9 %), 15.9 % of the code bytes |
| Functions with a `[V]` line | 161 (10.0 %) |
| Indirect jumps (`JMP (abs)`, `JMP (abs,X)`, `JML [abs]`, `JSR (abs,X)`) in traced code | 243, none resolved yet |
| Addresses cited in `docs/` | 773; 437 of them are not on traced code (data tables, RAM code, or code behind jump tables) |

Per bank (bytes; `fns` = functions, `doc` = cited, `[V]` = with a verified line):

| bank | code | pad | other | fns | doc | [V] | doc code % |
|---|---|---|---|---|---|---|---|
| C0 | 44,977 | 0 | 20,559 | 761 | 251 | 121 | 38.7 |
| C1 | 14,810 | 609 | 50,117 | 168 | 24 | 12 | 13.2 |
| C2 | 6,345 | 66 | 59,125 | 114 | 24 | 15 | 17.2 |
| C3 | 3,224 | 192 | 62,120 | 22 | 5 | 1 | 9.6 |
| C4 | 2,183 | 0 | 63,353 | 9 | 0 | 0 | 0 |
| C5 | 14,536 | 0 | 51,000 | 46 | 0 | 0 | 0 |
| C6 | 17,278 | 2,293 | 45,965 | 32 | 1 | 0 | 2.6 |
| C7 | 10,127 | 3,451 | 51,958 | 174 | 3 | 0 | 1.7 |
| C8 | 2,754 | 2,574 | 60,208 | 33 | 17 | 8 | 52.0 |
| C9-CF | 12,290 | 8,972 | 437,490 | 46 | 0 | 0 | 0 |
| D0 | 6,622 | 1,577 | 57,337 | 102 | 10 | 4 | 9.6 |
| D1 | 5,056 | 2,416 | 58,064 | 11 | 1 | 0 | 31.0 |
| D2-DF | 16,836 | 15,404 | 885,264 | 92 | 0 | 0 | 0 |

Reading the table: C0 is the engine core (frame loop `$C0:B08C`, combat, objects) and is the best covered. C2 (boss engine) and C8 (spell handlers) are known to hold much more code than the scan finds, because their handlers are reached through tables. The figures for C4-C7 and D2-DF are mostly scan noise or code that has not been looked at; step M2 decides which.

## 3. Findings that shape the work

### 3.1 The boot runs from RAM [V, C]
Reset (`$00:8004`) switches to native mode and does `JML $C1:0010` -> `JML $C1:4CE5`. That routine clears the PPU/CPU registers, calls `$C1:4D0F`, which calls the **decompressor `$C1:4C30`** with source `$C7:7C00` and destination `$7E:8000`, and then jumps to **`$7E:AF0B`**: the main program continues from decompressed code in WRAM. The NMI and IRQ vectors point to `$00:0100` and `$00:0104`, also RAM (trampolines written at boot). Consequences:
- A static map of the ROM alone can never be complete: the compressed blocks must be found, decompressed and disassembled at their RAM addresses.
- Verified on 2026-10-08: `$C1:4C30` receives source/destination banks in A and offsets in X/Y, reads a four-byte compressed header at the source, and returns with `RTS`; `$C1:0014` is its `JSL` wrapper. It does **not** take inline arguments. The temporary `RTL` is part of the executable kernel copied to the stack, not the caller-facing return [V, C].
- `tools/boot_decode.py` matches the original routine's 22,227 output bytes and the complete reset path up to `$7E:AF0B`, plus four initialization blocks and 240 generated cases [V]. The initial compressed program occupies 14,436 ROM bytes at `$C7:7C00-$C7:B463`; `rom_map.py` classifies this range separately and excludes scan hits inside it. `flowdis.py` can now follow the recovered image at its RAM addresses. See `docs/boot.md` and `data/boot.json`; the counts in section 2 are the earlier snapshot, before this classification.

### 3.2 Table dispatch
The AI bytecode machine (`$C1:251A`), the event VM (`$C1:E8D3`), the boss phase table (`$C2:8F51`) and the spell handler table (ROM offset `0x08E801`, handlers in bank C8) all dispatch through tables. The 243 indirect jumps found so far must each be resolved (table base, entry count, flags at the target) and their targets fed back as seeds.

### 3.3 Interpreted content is code too
Monster AI scripts, boss state scripts, event scripts and animation scripts are bytecode. The decoders already exist (`aidis.py`, `statescript.py`, `event_vm.py`, `hero_frames.py`, `ai_vm.py`); their ranges should be classified as "script" with the decoder that reads them.

## 4. Status by area

`Done` = what this repository already has; `Missing` = what is needed for the map; `%` = *estimate* of how much of that area is mapped (located, format known, ranges listed), not how much is documented in prose.

| Area | Done | Missing | % |
|---|---|---|---|
| Header, vectors, bank layout | HiROM 2 MiB, vectors read (`romio.py`, `rom_map.py`) | bank-by-bank purpose table | 60 |
| Boot, decompressor, RAM code | format verified, reset executed to `$7E:AF0B`, five decoded blocks, initial RAM disassembly, initial IRQ trampoline (`boot.md`) | remaining compressed blocks, indirect RAM targets, complete RAM function/data map, full NMI/IRQ handlers | 35 |
| Frame loop and object engine | `$C0:B08C` runs in the interpreter; object layout `$7E:E000 + 0x200*slot` | function list of the loop with names | 50 |
| Combat, stats, statuses, items | formulas verified (`rom-combat.md`, `spells-non-damage.md`, `items-shops.md`) | catalog entries for each routine | 70 |
| Hero control, movement, weapons | `hero-movement.md`, `weapons-*.md`, `glove-attacks.md`, `hit-reactions.md` | catalog entries | 65 |
| Ally AI | `hero-ai.md`, `party_follow.py` | catalog entries | 60 |
| Monster AI bytecode | all opcodes of ids 0x00-0x53 modelled (`monster-ai-opcodes.md`) | script ranges of every id, bosses outside the C2 engine | 60 |
| Boss engine (C2) | Mantis Ant, Dark Lich, Mana Beast | the other bosses, the state-script ranges of each | 25 |
| Spells (cast, handlers, effects) | `summon-cast.md`, `spells-non-damage.md`, spell table | handler table fully resolved, effect graphics | 50 |
| Event VM and cutscenes | opcode table, text engine, three cutscenes | ranges of all event scripts, unused opcodes | 45 |
| Text | encoding and blocks (`text.md`, `dialog_dump.py`) | dictionary/compression ranges listed | 60 |
| Maps | native decoder matching the loader for every map (`maps.md`) | region list of the map data | 70 |
| Graphics | tile/palette/OAM formats, hero and monster rips | locations of every compressed graphics block, mode-7 data, fonts, UI | 25 |
| Sound | SPC700 driver runs (`spc700_cpu.py`), music and effects rendered (`audio.md`) | driver disassembly, sample/sequence ranges listed | 40 |
| Menus (ring menu, status, equipment, shops) | ring menu runs in `summon_sim.py`; prices | menu code, layout and text tables | 15 |
| World map, Flammie, mode 7 | Mana Beast mode 7 export | the world map engine as a whole | 5 |
| Save / SRAM | - | save format, checksum, load/save code | 0 |
| Title, intro, ending, staff roll | ending sequence (`cutscene-ending.md`) | title and intro code | 20 |
| Function catalog (`data/functions.json`) | partial boot-model catalogue | remaining functions and prior models | not measured |
| Region catalog (`data/rom_regions.json`) | audited partial ranges (`docs/progress.md`) | remaining data and code ranges | not measured |

The system percentages above are historical estimates from the initial assessment, not measured decompilation progress. The noisy 7.5% scan figure does not establish the code denominator. Partial function and region catalogues now exist; use `data/progress.json` and `docs/progress.md` for the reproducible documented-range lower bound, with its incomplete-audit warning. A global code-decompilation percentage is still unmeasured.

## 5. Steps (work queue)

Each step names its output; a step is done when its output exists and `rom_map.py` reports it. Take the first open step.

- [x] **M0. Measurement tool.** `tools/rom_map.py` with the per-bank table and the unknown-run list.
- [ ] **M1. Boot and RAM code.** Disassemble `$C1:4C30` and write its decompression format (`docs/boot.md`) with a Python decompressor checked against the routine run in `cpu65816.py`. Find every call of the decompressor (including the far wrapper `$C1:0014`, in ROM and recovered RAM code, plus a run of the boot) and list the compressed blocks with source, size and RAM destination. Disassemble the RAM code at its RAM address (`flowdis.py` on the decompressed image) and add those blocks to `rom_map.py` as "compressed code". Document the NMI and IRQ handlers.
  - **2026-10-08 progress:** format and reset block verified; four further initialization blocks verified; RAM images supported by `flowdis.py`; initial compressed program classified by `rom_map.py`; IRQ trampoline and both entry preludes read. No inline arguments for this decompressor. M1 remains open for the full block/call inventory, RAM map and interrupt handlers. Reproduce with `tools/boot_decode.py ROM --json data/boot.json --disasm /tmp/boot-disasm.txt`.
- [ ] **M2. Traced coverage.** Add a trace hook to `cpu65816.py` that records every executed `PB:PC` with its M and X flags (ROM and RAM, addresses only, no ROM bytes). Run the existing harnesses with it (`lich_sim.py`, `boss_fight.py`, `event_runs.py`, `summon_sim.py`, `hero_movement.py`, `map_env.py`, `music_extract.py`, ...) and merge the traces into `data/coverage.json`. `rom_map.py` then reports three tiers: executed, reached statically from executed code/resolved observed dispatches, additional candidates. Most harnesses need a ZSNES v143 save state; only its WRAM is read (`zsnes_state.py`, file offset `0xC13`). The states used so far (map id = `$7E:00DC`, 9 bits): `.zs3` map 246 (Dark Lich arena), `.zs2` map 255 (before the Mana Beast arena), `.zs1` map 56, `.z10`-`.z12` map 195, `.zst` not in a map (WRAM still filled with 0x55, early boot). More states are not a blocker: the harnesses already move the party to any map through the game's own transitions, and a new state is just a copy of an existing file with the WRAM at `0xC13` replaced by the interpreter's WRAM after such a run.
- [ ] **M3. Indirect jumps and inline arguments.** For each of the 243 indirect jumps (and those that M1/M2 add), find the table and its length and add the targets as seeds; list the routines that take inline arguments and teach `flowdis.py` their argument length. Output: `data/dispatch.json`.
- [ ] **M4. Function catalog.** `data/functions.json`: entry, bank, size, M/X at entry, callers, callees, inline-argument size, name, doc reference, status (`unknown`, `named`, `documented`, `verified`). Seed it from the 773 citations in `docs/`. `rom_map.py` reads it for the documented and verified counts.
- [ ] **M5. Region catalog.** `data/rom_regions.json`: every non-code range with type (`table` with row size and count, `compressed`, `graphics`, `palette`, `map`, `text`, `music`, `sample`, `script` with its decoder, `padding`) and the tool that reads it. Start with the tables the notes already name (monster records `0x101C00`, spell rows `0x102AD0`, NPC scripts `0x104F15`, the `data/*.json` sources) and the ranges that `map_native.py`, `text_decode.py`, `music_extract.py` and `sfx_extract.py` read.
- [ ] **M6. Scripts.** Mark the ranges of all monster AI scripts, boss state scripts, event scripts and animation scripts with the existing decoders.
- [ ] **M7. Close the gaps.** Work down `rom_map.py --list-unknown` until the unclassified part is below 1 %, then give each remaining function a name.

Next action: continue M1 from `docs/boot.md`: resolve the remaining RAM targets and decompressor calls through `$C1:0014`, and finish the interrupt handlers.

2026-10-08 continuation: `$7E:AD75` and both `$7E:AB88` descriptor calls now execute to return; the task priority insertion at `$7E:A8D6` has an independently checked readable model (320 cases). Continue with the real task entries `$7E:CD50` and `$7E:934F`, the dispatcher and interrupts. The partial region catalogue now covers 794 map pieces, map graphics/palettes/attributes, all 2,048 events, 10,626 AI instruction boundaries, gameplay fields and boot/sound payloads. Four interpreter dispatch tables (375 entries) are resolved in `data/dispatch.json`; their targets extend the static walk and their pointer arrays no longer look like code. Twenty-seven execution/model runs are merged. The task stack/completion/dispatch and eight-byte record-pool operations have independently checked models; IRQ/NMI restoration and trampoline writes are checked. M1-M5 remain open for remaining callees, contexts, tables, functions and ROM bytes.

## 6. After the map: recompilation (outline)

The route proven on other SNES games (snesrev's zelda3 and sm): game logic as C, the hardware emulated, the ROM supplied by the user at build time.

1. **Lift**: generate C from the function catalog, one C function per 65816 function, registers as variables, WRAM as an array, M/X resolved per instruction from the catalog.
2. **Hardware layer**: PPU, DMA/HDMA and the SPC700 + DSP emulated (licence-compatible emulator code); the ROM's graphics, music and data loaded from the user's ROM.
3. **Frame-by-frame check**: the PC build and a reference (the interpreter here, or an emulator) run the same inputs; WRAM is compared every frame and the first difference names the function to fix.
4. **Clean-up**: rewrite the generated C into readable C one function at a time, starting from the functions already verified in `docs/`.

Progress measure for that phase: functions whose generated C passes the frame check, then functions rewritten by hand.

## 7. Open questions

- Whether any other code is decompressed to RAM after the boot (overlays per game mode: world map, menus, battle).
- How much of the C4-C7 and D2-DF scan hits is real code.

2026-10-08 memory/scheduler continuation: three task-owner scans, the 128-byte-unit heap (allocation/suffix release/fill), complete reaping of one finished task, suspended-task restoration and suspension through the common scheduling continuation add 2,016 original-routine comparisons. Both dispatcher branches have models. Waiting-list wakeups, the empty-run-list fallback, registration/pending-record payloads and remaining IRQ callees are still open. These refine the already catalogued compressed boot block; audited ROM coverage remains 684,079 bytes (32.6194%).

2026-10-08 waiting/timer continuation: task-id lookup, waiting-list wakeup, prepend/append pending-record delivery and task-timer registration/scanning/notification add 2,000 original-routine comparisons. The task +0A queue and four-byte timer format are resolved. Twenty harness runs are merged. Remaining M1 includes the empty-ready-list creation fallback, full task creation, other record payloads and other active IRQ callees; ROM coverage stays 32.6194%.

2026-10-08 creation continuation: complete task creation/spawn and next-task selection add 800 comparisons, including partial-allocation failures, descriptor workspace size/fill source and empty-ready-list fallback. Remaining M1 includes the fallback task body, timer/message consumers and other active IRQ callees. Twenty-one runs are merged; audited ROM coverage remains 32.6194%.

2026-10-08 receive continuation: timer setup and receive phases, 96 empty-queue timed waits through the live fallback, IRQ-use release and fallback outer return add 1,232 comparisons. The two FF notification-consumption policies are resolved. Twenty-two harness runs are merged; remaining work includes other message payloads/callers and remaining active IRQ callees. Audited ROM coverage remains 32.6194%.

2026-10-08 IRQ queue continuation: deferred timer completion/split scan and PPU queue counting/writes/mirror reclamation add 1,040 comparisons. Twenty-seven execution/model runs are merged. Remaining IRQ work includes controller messages, other transfer queues and full active-handler composition; audited ROM coverage stays 32.6194%.

2026-10-08 input continuation: interface detection and standard-controller edge/message generation add 560 full-bank comparisons. Two RAM indirect tables (eight entries) are recorded in `data/boot_input.json`; their alternate-interface readers and reset transfer remain open. Twenty-four runs are merged, with audited ROM coverage still 32.6194%.

2026-10-08 alternate-input continuation: eight reader entries, all interface/index selections, full interface updates and input-reset transfer add 1,344 comparisons. The two RAM pointer tables are fully followed for the five supported indices; cache-bank and saved-P effects are retained. Reset execution beyond the vector, input-message consumers and other active IRQ workloads remain open. Twenty-five runs are merged; audited ROM coverage stays 32.6194%.

2026-10-08 memory-copy continuation: pool/queue initialization, allocation, append, release and execution add 1,280 comparisons with all original copy helpers executing. Inline/pointer interpretation, direct/MVN wrap and overlap, and short-odd first-byte effects are documented. Queue producers, non-WRAM destinations/extreme odd counters and remaining DMA/IRQ workload remain open. Twenty-six runs are merged; audited ROM coverage remains 32.6194%.

2026-10-08 DMA continuation: channel-0 programming, descriptor release and processed-vector/workspace cleanup add 720 comparisons. Time-budget/retry bookkeeping and ordered hardware writes are reconstructed with controlled reads/completion results. Nonzero HDMA callback, additional modes/transfer effects and descriptor producers remain open. Twenty-seven runs are merged; audited ROM coverage stays 32.6194%.

2026-10-08 HDMA/preparation continuation: transfer submission and HDMA channel setup add 240 comparisons, low-byte count staging 240 and deferred/immediate pass preparation 160. The existing 320 programming cases now include nonzero HDMA callbacks. All 1,360 transfer cases pass, comparing the full bank and ordered register writes where applicable. Descriptor producers, hardware payload/timing and full active IRQ composition remain open; audited ROM coverage stays 32.6194%.

2026-10-08 transfer-allocation continuation: highest-free HDMA ownership (240), descriptor allocation/immediate exhaustion (320) and original one-tick exhaustion/retry through preparation, fallback and timers (96) add 656 comparisons. This resolves argument reference/flag roles, table selection, high-byte-FF failure policy and the no-rollback HDMA failure effect. Transfer models now total 2,016 passing cases. Repeated unreclaimable waits, descriptor payload producers and hardware transfer/IRQ timing remain open; audited ROM coverage stays 32.6194%.

2026-10-08 transfer-producer continuation: real configuration loading corrects a zero-table weakness in the isolated DMA/PPU harnesses; all 2,016 prior transfer and 720 PPU cases pass again, now with actual table classes. OAM shadow producer (320), composed OAM pass (160), four-entry VRAM lookup (320) and VRAM buffer producer (320) add 1,120 comparisons. Transfer total is 3,136. Missing registration falls through to bank-7F 0000/0001 rather than aborting. Hardware payload/timing, further producers and active IRQ composition remain open; audited ROM coverage stays 32.6194%.

2026-10-08 VRAM lifecycle continuation: page allocation/release and registration selection (960), complete buffer creation/cleanup (320) and PPU entry allocation/append (480) add 1,760 comparisons. Creation links RAM size, 2-KiB VRAM pages and BG/scroll queue settings, retaining RAM/VRAM/PPU failure effects. Cleanup retains its table pointer and skips page zero. Twenty-eight runs are merged; bitmap edge cases, further producers and active IRQ/hardware composition remain open. Audited ROM coverage stays 32.6194%.

2026-10-08 palette continuation: slot allocation/release (480), colour copy (320), forward/reverse transfer producers (640) and composed allocation/copy/upload (160) add 1,600 comparisons. First-colour free marker, encoded copy count/offset, CGRAM group index and reverse 213B descriptor with immediate first-word clear are resolved. Twenty-nine runs are merged. Producer exhaustion waits, hardware payload/timing and remaining consumers/producers are open; audited ROM coverage stays 32.6194%.

2026-10-08 graphics-producer continuation: graphics slot selection (320), complete workspace/VRAM/base-setting creation (240), full graphics/palette/background scene preparation (96) and constant-palette upload (320) add 976 comparisons. The complete BA7F producer is composed from independently checked models and verified with all original callees, including palette exhaustion. Thirty runs are merged; further families/edge cases, active IRQ composition and actual hardware payload/rendering remain open. Audited ROM coverage stays 32.6194%.

2026-10-08 graphics-lifecycle continuation: full buffer release (240), cyclic workspace-block allocation (320), VRAM-address tag-word lookup (320), block release (320) and composed block roundtrips (160) add 1,360 comparisons. Full-word format comparisons, adjacent-byte effects, zero-task owners and page-zero release are preserved. Graphics tool total is 2,016. Thirty runs remain merged; invalid workspace/tag layouts, further producers and active IRQ/hardware composition are open. Audited ROM coverage stays 32.6194%.

2026-10-08 block-submission continuation: individual graphics transfer descriptors (320), allocation/submission composition (160), source-retention/free policy at an explicit completion boundary (160), auxiliary buffer allocation (200) and release (200) add 1,040 comparisons. Source-bank, destination, format-nibble size and high-argument cleanup policy are resolved; partial allocation failure and retained auxiliary pointers are preserved. Graphics total is 3,056. Thirty runs remain merged; auxiliary consumers, exhausted producer waits and physical DMA/IRQ effects remain open. Audited ROM coverage stays 32.6194%.

2026-10-08 colour-lookup continuation: bit-tree symbols and signed/zero-run deltas (480), cumulative ramps/three-channel decoding (192), component conversions (640), translated-candidate marking/deduplication (320) and full sign/cyclic-permutation groups (96) add 1,728 comparisons. Auxiliary sample/scratch roles and the 4096-cell colour lookup are identified. Thirty-one runs are merged; real tree/stream producers and lookup consumers remain open. Synthetic valid trees/offsets establish code models, not a claim that real asset streams were fully catalogued. Audited ROM coverage stays 32.6194%.

2026-10-08 real colour-tree continuation: tree allocation/release/construction/initialization (960), constructed decoder compositions (96) and real D2E536/D2E6BC component runs at eight heap placements add 1,064 comparisons. The 390-byte tree and 351-byte consumed stream prefix add 741 new ROM bytes, bringing audited coverage to 32.6548%. The final unused refill byte is excluded. Thirty-one runs remain merged; full caller lifecycle, further stream consumers and complete code denominator remain open.

Colour lookup consumers add 312 original-routine comparisons: complete clear (32), initialization from eight real configuration offsets (24), packing/submission of 232 palette samples (96) and nearest-sample fallback (160). The retained stack threshold high byte, strict tie rule and modular distance arithmetic are preserved. Colour total is 3,104. Audited ROM coverage remains 32.6548% because these routines are within the previously counted compressed program. Cache consumer composition and complete task lifecycle remain open.

Colour cache/workspace continuation adds 720 comparisons: cache hit/miss (240), repeated lookup (160) and unfilled auxiliary reservation (320). Cached zero remains a miss; sign extension, byte-only clears and unfilled allocation/failure effects are preserved. Colour total is 3,824. ROM coverage remains 32.6548%; full tile packing/transfer caller and complete task lifecycle remain open.

Planar-tile continuation adds 338 comparisons: raw temporary copy/graphics submission (240), full 64-pixel eight-bit conversion/submission (96) and real colour tree/stream/lookup/palette/tile compositions (2). Caller-bank data, bank-7F cache, bank-00 source mirror and literal pointer arithmetic are preserved. Thirty-two runs are merged. ROM coverage remains 32.6548%; complete task/scene and physical DMA/IRQ effects remain open.

Colour scene/resource continuation adds 1,120 original comparisons: registered-buffer release (240), two configuration template copies (480), template-release bank restoration (16), complete scene setup/release (192) and complete colour resource setup/release (192). The 768-index map layout, page-zero release, retained cursor/pointer fields and unchanged pending descriptors are reconstructed. Thirty-three runs are merged; ROM coverage remains 32.6548%. Complete task synchronization, resource-failure aliasing and physical DMA/IRQ effects remain open.

Colour protocol continuation adds 992 comparisons: parent/current identifiers (480), preloaded raw receive (320), complete fallback/original-delivery/resume (96) and graphics workspace replacement (96). Raw receive preserves timer state and returns FF-tagged records; graphics replacement preserves exhausted allocation effects. Thirty-four runs are merged. ROM coverage remains 32.6548%; full image generation, parent-task synchronization and physical IRQ/DMA timing remain open.

Coefficient continuation adds 240 constructed block comparisons and one complete real palette/coefficient read sequence containing 1,152 individually compared blocks (73,728 coefficients). DC predictor progression and alternating diagonal word stores are recovered. The consumed D2E6BC prefix grows from 351 to 5,953 bytes, adding 5,602 new ROM bytes. Coverage is now 690,422 / 2,097,152 = 32.9219%; execution-verified regions occupy 42,359 bytes (2.0198%) within that union. Thirty-five runs are merged. Transforms, complete asset endpoint and full task/rendering synchronization remain open.

Coefficient-transform continuation adds 912 original comparisons/compositions (240 scaling, 320 transforms, 160 complete block paths and 192 real six-block groups), plus 512 separate functional Mode-7 hardware-contract checks. All 1152 real blocks now include original scaling and two-pass integer transforms, with exact multiplier writes and saved DC progression. Thirty-six runs are merged. ROM coverage remains 32.9219%; component/colour conversion, full task synchronization and physical PPU/IRQ/DMA timing remain open.

Image-component continuation adds 656 original comparisons/compositions: 240 chroma mixes, 160 complete tile expansions/submissions, 64 constructed groups and 192 real image groups. All 768 tiles/49,152 pixels now include decoding, scaling, integer transform, component mixing, palette selection, planar conversion and descriptor submission. Original descriptor cleanup uses explicitly supplied completion counts. A caller-bank sample-source assumption was corrected and all 338 tile comparisons repeated with distinct bank fixtures, replacing that trace without double counting. Thirty-seven runs are merged. Audited ROM coverage remains 690,422 / 2,097,152 = 32.9219%; physical DMA and full task/message timing remain open.

Image-row protocol continuation adds 320 complete original comparisons: 160 zero-response calls and 160 palette/workspace replacement calls through 768 blocks. The opcode/argument overlap, low-byte parent addressing, raw response-word decision and exact hardware count `((argument << 1) & FF) * 32` are reconstructed. Thirty-eight runs are merged. Audited documented ROM coverage remains 690,422 / 2,097,152 = 32.9219%; full parent/image task, zero-count positive response and physical transfer timing remain open.

Complete image-body continuation verifies one continuous original A009 call: twelve row exchanges, 192 six-block groups, 768 tiles/49,152 pixels and 781 descriptor completions. Preparation, predictor initialization, row-dependent reservation renewal, every group and final restored caller state agree with the readable model. Parent responses and descriptor completion are explicitly supplied boundaries; physical transfer and the surrounding 968D task remain open. Thirty-nine runs are merged. Audited documented ROM coverage remains 690,422 / 2,097,152 = 32.9219%, because this body occupies already counted compressed program bytes.

Complete colour-image task continuation verifies continuous original 968D setup, phase2 receive/release, the complete image body, phase4 receive/release and teardown/RTL. Two phase exchanges, twelve row exchanges, 192 groups/768 tiles/49,152 pixels and 781 descriptor completions agree. Final task-owned heap pages and pending descriptors are zero; fourteen outgoing messages remain in exact order for the unexecuted parent. Parent launch is located at D23E/D244 via descriptor5F12; its wait/response logic and physical IRQ/DMA remain open. Forty runs are merged. Audited documented ROM coverage stays 690,422 / 2,097,152 = 32.9219%; code is within the already counted compressed program.

Parent-message continuation adds 1,152 original comparisons for image/phase handling, first-match tracked-id release and shared-buffer replies. The actual image parent sends a positive renewal reply only for row byte4, reserving 256 preceding tile blocks; other row replies are zero, and phase1/2/4 return without automatically replying. This refines the earlier explicitly supplied image-task boundary sequence, which is not claimed as real parent logic. Forty-one runs are merged. Audited documented ROM coverage remains 690,422 / 2,097,152 = 32.9219%; complete parent loop/phase acknowledgement and physical IRQ/DMA remain open.

Original parent-row continuation verifies another complete 968D task using actual CFE2-generated responses for all twelve rows and original phase-record consumption. Only row4 renews resources; 771 descriptor completions are supplied, and final task-owned heap pages, pending descriptors and queued parent messages are all zero. AEC4 receive/filter reconstruction adds 480 original calls across ordinary records, FE cancellation/discard and timer notifications. Forty-three runs are merged. Audited documented ROM coverage remains 690,422 / 2,097,152 = 32.9219%; phase acknowledgement, complete parent/pause scheduling and physical IRQ/DMA remain open.

Parent-dispatch continuation adds 1,440 complete original comparisons: four controller ownership/pressed/released-mask helpers (960) and D17F receive/handler loops (480). Ordered sender dispatch, continued row/buffer/input/tracked handling, returned phase opcodes, unreleased control-record returns and cancellation with an existing control task are reconstructed. Original D0AE claims all controllers and installs F0F0 pressed masks. Forty-four runs are merged. Audited documented ROM coverage stays 690,422 / 2,097,152 = 32.9219%; new-control creation, pause/empty-queue scheduling and the surrounding parent caller remain open.

Control/fade continuation adds 512 complete original comparisons: D14C control creation/retention/missing-record handling (320) and continuous D1DA fades/control terminations (192), with 6,936 individually compared PPU updates. The original command80 sender runs with supplied APU echoes; original C18B shadow service runs at explicit boundaries. Zero-brightness allocated-record retention and literal80/8F decrements are preserved. Forty-six runs are merged. Audited documented ROM coverage remains 690,422 / 2,097,152 = 32.9219%; physical SPC/PPU/IRQ timing and the surrounding parent caller remain open.

Parent transition continuation adds448 complete original comparisons: continuous D20D fade-in/control termination (192,684 compared PPU updates) and CD82 title-map copy/submission (256, including both real configuration maps). Literal brightness returns, retained unqueued allocation, 928-entry maps/192-byte retained tails and final descriptor/vector registers are recovered. Forty-seven successful runs are merged; no new unique instruction states are added because the routines were previously sampled. Audited documented ROM coverage stays690,422 /2,097,152=32.9219%; actual complete decompilation remains unmeasured. Physical PPU/IRQ timing and the surrounding parent task remain open.

Title-parent continuation adds two continuous D23E success calls and one initial-fade control abort, including90 compared PPU updates and four original music loads with a running SPC driver. Controlled records/shadow service and unexecuted concurrent children are explicit limits. Forty-eight successful traces contain28,154 PC/M/X states,19,085 ROM PCs and8,384 RAM PCs. Audited documented ROM coverage remains32.9219%; complete decompilation remains unmeasured.

Title-parent control-exit continuation replaces the prior three-case trace with15 passing continuous calls: two successes and13 aborts covering all seven dispatch/transition exits, including partial fades. Across all calls363 PPU shadow updates and16 native song loads are compared. Unreleased control notices, image-task retention, no text launch, partial brightness and music-request ordering match the original. Supplied arrival/service boundaries remain explicit; control producer execution, concurrency, resource exhaustion and physical timing remain open. The48-run coverage union is unchanged; audited documented ROM coverage remains32.9219%, not a complete decompilation percentage.

Control-task continuation reconstructs D0CC-D14B, the complete descriptor6492 task. All54 isolated calls pass (18 map transitions/36 final-dim-only, 3902 compared PPU updates and3848 waits). Twelve further original scheduler compositions create the child through D14C, suspend an empty-queue parent in D17F, execute the child/fallback/timer delivery, complete the child and return its unreleased notice to the parent;983 further PPU updates and2600 real CCB7 service calls agree. Retained initial dim allocations, matching-timer release versus ordinary-record retention, exact final zero queueing, map choice and completed-child status are documented. Shadow/timer service boundaries remain supplied; full image/text/title concurrency, reaping, resource exhaustion and physical timing remain open. Forty-nine successful runs retain28,154 PC/M/X states,19,085 ROM PCs and8,384 RAM PCs: these paths were sampled earlier, but now have independent memory/behaviour comparisons. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured.

Control cleanup/title-window continuation adds12 full-WRAM original A9C7 reap comparisons after actual scheduled parent/control return, verifying released task/page/timer/heap resources and preservation of the parent-held notice. CE6B-CFE1 has a new readable producer model with336 original comparisons (14 widths x12 centres xnew/existing HDMA), including copy-queue table generation, PPU shadow service, returned bounds and ordered registration writes. Fifty successful traces contain28,339 PC/M/X states,19,085 raw ROM PCs and8,569 RAM PCs; the185 new states are RAM-program branches, not additional ROM bytes. Executed ROM instruction bytes remain39,293, static-only63,024 and candidate-only76,140. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured. Complete D2FC animation, title/image/text concurrency, exhausted resources and physical HDMA/PPU/IRQ timing remain open.

Title-opening caller continuation reconstructs D2FC-D347. All66 continuous original calls pass: two complete32-step animations and64 step-specific control aborts with new/existing HDMA. The1,120 windows and1,120 dispatches compare full WRAM after launch, producers, waits, original copy/shadow service and return, including actual class42 scroll high-byte seeds, ordered HDMA writes and X/lowA. Parent priority/preloaded records and service boundaries explicitly exclude concurrent child execution and physical timing. Fifty-one successful traces contain28,378 PC/M/X states,19,085 ROM PCs and8,608 RAM PCs;39 new states belong to the recovered RAM program. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured. D348 word-scroll continuation, descriptor5EA0 child execution, full title/image/text concurrency and physical timing remain open.

Title scroll/expansion continuation reconstructs D348-D376 and D377-D3A9. The word scroll passes86 continuous original calls (eight complete/78 aborts), including all62 ordinary early exits and one unbroken65,536-decrement cycle with65,535 original CC8C deliveries. All68,466 PPU updates/68,458 dispatches agree, including literal full returnFF70 or0. Window expansion passes254 original calls (two complete127-step expansions/252 aborts), with16,256 windows/16,254 dispatches and the endpoint determined by returned top16 rather than width. Supplied shadow/copy/timer service and available resources bound these comparisons. Fifty-three successful traces contain28,434 PC/M/X states,19,085 ROM PCs and8,659 RAM PCs. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured. D3AA teardown/ACAC task stop, title child concurrency, exhausted-resource/pause/cancellation and physical timing remain open.

Title teardown/task-stop continuation reconstructs ACAC-ACCF and D3AA-D3E9. All720 original comparisons pass:480 id-stop requests (336 missing/144 existing) and240 complete teardowns, with20 mixed/duplicate/missing tracked ids, linked/unlinked waiting nodes, all eight HDMA channels and varied references. Full WRAM, lookup/final X, caller restoration and original PPU shadow service agree. Status10 requests wake waiting targets if linked but do not themselves enqueue completion/reap or decrement active count; teardown releases030E, queues register2C bit0 clear and clears0318..032B. Fifty-four successful traces retain28,434 PC/M/X states,19,085 ROM PCs and8,659 RAM PCs; these paths had prior execution samples but now have composed readable-model comparisons. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured. Buffer-child8D1A/continuation8DA0 lifecycle, stopped-task dispatch/cleanup, title concurrency, exhaustion and physical timing remain open.

Buffer-cleanup/forced-stop continuation reconstructs88CF-88E6,8CA6-8D19 and8DA0-8DAB. All480 entry calls pass (160 each), checking seven descriptor/three heap releases, retained pointer fields and five queued register defaults with original shadow service. Thirty-two original ready/waiting descriptor5EA0 stop compositions pass from AB88/ACAC through A961's8DA0 continuation, AA22 completion and supplied original C18B/A9C7 service; full memory outside active stack, restored continuation/frame, active count and freed child record/page/timer/workspace agree. Resources are prepared at an explicit boundary; normal8D1A body and natural parent concurrency remain open. Fifty-eight traces contain28,970 PC/M/X states,19,085 ROM PCs and9,180 RAM PCs; new samples are RAM-program states. Audited documented ROM coverage remains690,422 /2,097,152=32.9219%; complete decompilation remains unmeasured. Normal buffer-task preparation/processing, full title concurrency, resource exhaustion and physical timing remain open.

Title row expansion8820 and auxiliary-table preparation886E add512 original comparisons (320 rows/192 tables), including caller stack-dependent descriptor reference bytes. Fifty-eight successful traces now contain28,970 PC/M/X states,19,085 ROM PCs and9,180 RAM PCs. These additions are within the already audited compressed boot program; documented ROM coverage remains690,422 /2,097,152=32.9219%, and complete decompilation remains unmeasured. Normal buffer-task setup/composition and physical timing remain open.

Normal title-buffer setup88E7-8A53 adds96 complete original comparisons, including seven HDMA submissions, five raw copies, six queued defaults and original setup-shadow/cleanup-shadow services. Fifty-eight successful traces contain28,970 PC/M/X states,19,085 ROM PCs and9,180 RAM PCs. These are additional RAM program states within already counted ROM ranges; documented ROM coverage remains32.9219% and complete code decompilation remains unmeasured. Normal buffer-task message/animation composition is the next open title path.

Matching source reconstruction now exists separately in `src/boot/`: nine ca65 files independently generate1,093 bytes identical to the decompressed boot program (8820/886E/88CF/88E7/8B15/8B5D/8BA5/8CA6/8DA0). `tools/verify_source.py` assembles without ROM byte inputs and compares afterward; `data/source_build.json` records source/result fingerprints. This is partial assembly reconstruction, not a full ROM rebuild or a measured high-level decompilation percentage. Compressed ROM recomposition and the remaining program/assets remain open.

Row-colour/animation recovery adds512 isolated colour comparisons and256 continuous8BA5 calls covering all counter bytes and2,377 wait boundaries, with matching timer messages preloaded and pause cleared. Fifty-eight successful traces contain28,970 PC/M/X states,19,085 ROM PCs and9,180 RAM PCs. Independently assembled matching sources now total1,093 bytes across nine routines; these decoded RAM bytes have no established whole-code denominator and are separate from32.9219% documented ROM coverage.

Matching source reconstruction has expanded from1,093 to13,954 bytes across166 independently assembled boot routines. These include title control, task/record/heap/timer operations, input readers, display/copy/transfer queues, VRAM/palette/graphics resources and the complete previously modelled image coefficient/colour pipeline. `data/source_build.json` confirms each source/result fingerprint and exact comparison against the original decoded boot program. Assembly receives no original ROM bytes as inputs. This remains matching assembly reconstruction; full compressed-ROM recomposition, assets and the rest of the game are unfinished, so no whole-game decompilation percentage is inferred.

The ABAD body extent was corrected from63 to58 bytes: ABE6 is its RTS and ABE7 is the adjacent supplied-delay entry. Its zero-record branch shares the epilogue atAC3F. Blocks are checked for overlap before assembly/counting. Transfer-pass91B8 is not yet incorporated: immediate92BC lacks execution-width evidence in the retained trace. Its behaviour model remains available; this source gap is explicit.

The ROM decompressor is now reconstructed as four ca65 sources spanningC14C00-C14CE4: six shift-selector distance masks, the42-byte stack-execution loop template, the144-byte setup routine and the37-byte token reader. The setup copies and patches the loop banks/entry point; the token reader consumes a lookahead byte before checking the output end, reads backreference distance operands and discards three return-address bytes at termination. These sources also assemble as one contiguous229-byte component; every byte matches the supplied USA ROM. Block and component counts are deduplicated.

The matching-source total is14,183 bytes:13,954 expanded RAM bytes and229 direct ROM bytes, including six numeric mask bytes. No expanded RAM bytes are added to the ROM-coverage numerator. `tools/rom_progress.py` audits report/manifest/source/ROM hashes before adding direct-ROM source ranges as matching-source evidence, distinct from execution-verified regions. Full ROM recomposition, assets and complete code decompilation remain unfinished.

The audited documented-ROM union now covers690,651 /2,097,152=32.9328%, after229 independently assembled decompressor ROM bytes were added. The14,183 matching-source byte total mixes expanded boot-code and direct ROM spaces and is not divided by ROM size as a decompilation percentage.

Startup adds36 complete original cold/native/warm entry comparisons and one successful trace. Fifty-nine traces now contain28,981 PC/M/X states,19,096 ROM PCs and9,180 RAM PCs. Sources now reconstruct14,492 bytes across179 blocks, including integrated ROM loader/decompressor and entry-wrapper components; reused component bytes are counted once. Documented ROM coverage now totals690,766 /2,097,152=32.9383%, with16,524 ranges. Execution-verified region coverage remains42,359 bytes; matching-source evidence remains separate. Full code decompilation and complete ROM reconstruction are not achieved.

Physical-combat reconstruction adds1,298 direct ROM bytes in16 independently assembled sources and three integrated components. Total matching source bytes are15,790 across195 blocks (14,148 RAM/1,642 ROM, including six mask constants). A96-case branch-execution probe resolves missing instruction widths but does not independently validate side effects. Sixty successful traces contain29,031 PC/M/X states,19,145 ROM PCs and9,180 RAM PCs. Whole-game decompilation remains unmeasured.

The current audited documented-ROM union is692,064 /2,097,152=33.0002% after1,298 matching physical-combat ROM source bytes were added. This is a documented/matching-range lower bound, not the complete code-decompilation percentage.

Spell reconstruction adds530 instruction bytes and84 handler-pointer bytes in nine sources. The matching-source total is16,404 bytes across204 blocks (14,148 RAM/2,256 ROM), including90 data bytes. The handler-pointer table was already documented and does not inflate the ROM union. New numeric boundary evidence adds260 comparisons and one successful trace. Sixty-one traces contain29,034 PC/M/X states,19,148 ROM PCs and9,180 RAM PCs. Audited documented ROM bytes now total692,594 /2,097,152=33.0255%, with16,549 ranges; complete code decompilation remains unmeasured.
