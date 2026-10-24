# Actor cast presentation and publication

## First dependency block

`tools/actor_cast_publication.py:CastPublication` reconstructs eight complete native dependencies of the C18707 casting animation operation. The **767 instruction bytes** are new source candidates; only source recovery and independent assembly/ROM comparison can add them to the global instruction total. C18707 itself remains open.

| Address | Bytes | Method | Behaviour |
|---|---:|---|---|
| C185D8 |12 |cast_palette |Reload actor fromDP14 and copy the selected E04F five-colour effect palette. |
| C1860A |42 |hero_graphics |Convert64 tiles from D0:DF00+48×DP01, then publish the cast palette. |
| C18634 |25 |secondary_graphics |Convert64 secondary tiles fromD4:BA00 into actor destination offset0800. |
| C18654 |114 |spell_graphics |Select spell/level graphic resource and convert its actual planar data. |
| C186D1 |54 |presentation_record |Select a spell presentation record using E170/E111, preserving the special88 selector. |
| C18898 |47 |directional_offset |Write signed ±24 casting offsets from actor facing. |
| C18A61 |197 |radial_targets |Initialize radial target motion, shared tile slots and facing offsets. |
| C18B82 |276 |three_targets |Prepare three target presentation records, target bindings, delays and directional launch. |

The plane conversion and five-colour palette routines are reused from independently validated readable models, with literal returned registers, arithmetic flags and scratch effects. Their existing bytes receive no additional credit.

C18654 uses `(spell&7F)*64` and selects resource words at offsets2/4/6 according to the high parameter nibble and sign. It converts fromD4 at24×(resource&07FF). Resource bit0800 chooses64 primary plus64 secondary tiles; otherwise it converts127 primary tiles. DP00/08/0A/14, hardware multiplication results from palette copying, final actor X and converter registers are preserved.

C186D1 computes the selected record independently of graphic conversion: ordinary parameter bits0E select8+4×masked parameter, while exactly88 selects30. The final offset is masked3F before being combined with the64-byte spell row. It therefore retains the native wrap when the ordinary selector reaches40.

C18B82 copies type to E110/E120/E130, substitutes the first target for zero secondary target ids, and stores target offsets in E116/E126/E136 using the native low-three-bit decrement and byte shift. Duplicate target suppression occurs for type0 or>=5. Types1..3 prepare staggered delays5/15/25 and directional fields; type4 executes the complete radial setup. The level nibble8 also sets F1bit40. Radial setup preserves word copies and clears, fills sixteen actual C060+actor/2 tile words withCB00, and applies facing-dependent signed offsets with native carry/overflow.

## Proof

`data/actor_cast_publication.json` records **1,024 complete native calls**,128 per entry, without hooks. A successful width trace is saved in `data/actor_cast_publication.coverage.json`. Full randomized128KiB WRAM outside129 caller-stack bytes, A/X/Y/C/N/Z/V/M/X, S/D/DB and static video/arithmetic peripherals agree. Actual D0/D1/D4 resource data and palette words are read from the supplied ROM; no graphics/script payload is stored.

Domain: D0/DB7E/X16/binary, twelve aligned actor offsets, both incoming accumulator widths except the native M8 palette/radial entries, literal spell ids0..98, level nibbles0..15 with both high-bit contexts, four facings0/1/2/128, selected target ids0..6 and valid palette cursors. The direct spell/level fixture sequence is a sample of table combinations, not every possible resource. The report lists the actual presentation types observed. This proves the complete helper bodies in that domain, not all runtime spell trajectories or interrupt timing.

## Coordinator and remaining implementation

The public animation operation C18707 first clears E012/E025/E084. F1-negative clears E060 and returns. The hero path requires C18898 and C1860A/185D8, now reconstructed. The enemy path enters C18775, which calls C18B82 and, for visual presentation, C18654/C186D1 plus palette copying, also now reconstructed. Composition of these wrappers remains to implement and prove.

The nonvisual path C18C96 cannot yet be bypassed or called complete. It resolves primary/secondary targets through C18D12/C18D09 and the real C00054→D04C82→C8E6D4 spell-hit pipeline. Older spell tools validate selected results or a zero-divisor bookkeeping domain; they do not already provide complete CPU/peripheral contracts. Target transfer additionally calls C187C2 and C181F2 to preserve/restore prior effects and motion. Empty or inactive targets must remain literal native guards, not replacement fixtures that claim every active-target path.

Type>=8 also publishes sprites through C0E328/C0E351 and dispatches C10038→C13B3C, which can execute dynamic callbacks. The source and existing models for actor sprite selection/body/effects, sprite ordering and real NMI can be reused, but the outer publication/callback composition is still pending. No hook or omitted callback is introduced by this block.

Next: implement the C18707/C18775 wrapper composition, the target transfer/hit and immediate result paths, then native sprite/callback publication. The complete coordinator, all active-target spell effects, subsequent cast animation, continuous frame scheduling and whole-ROM reconstruction remain open.

## Joint native/cast integration: 2026-10-09

This batch adds 2,232 independently reconstructed instruction bytes and12 numeric dispatch bytes across40 sources: descriptor3 271, descriptor0 245, native initialization/target velocity/math824, cast dependencies755, four-state child137. Cast palette helperC185D8 reuses12 existing bytes and is not credited again. Complete original no-hook reports pass14336/10240/7680/1024/6944 calls respectively. The native math includes hardware-latch multiplication, software signed/unsigned division and integer square root; coincident-target positive vertical velocity and actual status/direction abort returns are retained. Child sequences traverse allfourstates, with real allocation, counter and freeze updates. C18707 itself, returned boss scripts, subsequent linked-child/animation/collision scheduling and full live gameplay remain open.

Joint assembly matches 1,381 blocks/269 contiguous components, 84,298 source bytes: 81,728 instructions and2,570 numeric data; RAM14,148/ROM70,150. All component ranges exclude unrecovered gaps. Documented ROM union815,914/2,097,152=38.90581130981445% is a separate metric. Complete code percentage remains null and full ROM rebuild false.
