# Actor animation special helpers

## Charge-effect creation: C2BF1D

`tools/actor_animation_special_helpers.py:SpecialHelpers` reconstructs the complete C2BF1D animation operation and its eight actual auxiliaries. The nine bodies span694 instruction bytes. They are ready for independent matching-source recovery; this report alone does not add them to the repository-wide decompilation counter.

| Address | Instruction bytes | Readable method | Purpose |
|---|---:|---|---|
| C2BF1D |102 |initialize |Gate and create the primary and secondary charge-effect records. |
| C2BF83 |125 |eight_tiles |Select and write eight native D4 tile-source offsets. |
| C2C000 |33 |copy_secondary |Copy the overlapping fifteen-byte primary record into two secondary records. |
| C2C021 |44 |primary_record |Prepare orientation/layer and initialize geometry, terrain height and velocity. |
| C2C04D |251 |effect_position |Compute signed effect placement, directional piece offsets and map wrapping. |
| C2C148 |41 |effect_velocity |Derive acceleration from charge stage and initial speeds from effect type. |
| C2C171 |18 |add_terrain |Add the selected terrain height to the effect altitude byte. |
| C2C1D1 |6 |terrain_preserving_actor |Read terrain while preserving actor X. |
| C2C1D7 |74 |terrain |Read layer tile/attribute tables in actual7F WRAM. |

The initializer returns immediately for nonzero actor E061 or zero effect typeD030+X/8. Otherwise it clears E02E, increments E061, preparesD000+X/8 and copies fields1..15 intoD010 andD020. Charge stage>=3 enables the second type with bits50; stage>=6 additionally enables the third with bitsA0. Type2 adjusts the two secondary height/acceleration fields. The routine increments E08D and builds an eight-word tile table at E06C+64 from actual D4:FFC8..FFFF shape tables; a source byteFF writes the native CB00 empty-tile sentinel. This table depends on both type and actor facing.

`effect_position` retains literal byte/word operations: attributes derive from actor E092/E086, altitude includes full wordE045 and the low7bits of wordE074, orientation affects signed piece offsets and attribute flip bits, and map dimensionsDP C0/C2 normalize coordinates after additions. The initial negative worldY correction explicitly clears carry; the later signed adjustments retain carry when adding the extent. Secondary type2 adds2 twice with the carry retained between additions. Do not replace these with unrestricted mathematical modulo or unsigned saturation.

Terrain uses the effect layer bit, wordworldX>>4 and wordworldY masked0FF0 to select a7F layer tile index, then its attribute record in7F:B800 orBC00. Only attribute bits30 are returned. Original scratch words0A/0C/0E, accumulator high-byte residue, carry/overflow and final X/Y restoration are modelled.

## Validation and integration

`data/actor_animation_special_helpers.json` records **4,608 complete original calls**,512 per entry. The successful instruction-width trace is `data/actor_animation_special_helpers.coverage.json` (331 PC/M/X states). Native instructions execute without hooks, including every auxiliary called by C2BF1D. Full randomized128KiB WRAM outside129 caller-stack bytes, CPU A/X/Y/C/N/Z/V/M/X, S/D/DB and static video/arithmetic peripherals agree. Dependencies and current tool/CPU hashes are included in the report.

Domain: D0/DB7E/X16/binary; initializer/geometry/terrain/tiles called with M8, copy with M16. Twelve aligned actor slots; charge stages0,2,3,5,6,8,255; facing0,1,2,128; both map layers; zero/nonzero initialization gates; independently varying direct effect types and facing; signed boundary positions/extents and actual D4 tile/7F attribute reads. Test fixture parameters are synthetic, all ROM reads use the supplied original image. No ROM, raw scripts, graphics or save-state payload is retained.

Integration should merge the successful coverage preserving existing history, recover the nine exact sources listed above, independently assemble/compare them, and only then credit694 new instruction bytes. No shared catalogue, manifest, progress file or source was changed by this agent, and no commit was created.

This closes **charge-effect creation**, not its later movement/collision, the animation interpreter's nonlocal-return handling, every animation, live interrupt timing or full-game scheduling.

## Next assigned dependency: C18707

C18707 is still pending and is not bypassed in this proof. It clears E012/E025/E084; F1-negative exits after clearing E060. The ordinary hero path calls C18898 for directional cast offset, selects real D0:2AA0/2A80 resources and executes C1860A→plane conversion→C185D8→palette copying. The ordinary enemy path calls C18775→C18B82, then either prepares graphic resources viaC18654/C186D1 or enters C18C96 result/publication.

Required missing bodies include C18898,C1860A,C185D8,C18634,C18654,C186D1,C18775,C18B82,C18A61,C18C96 and subsequent C18D12/C18D09/C18DAB; C18C96 also reaches C0E328/C0E351 and C10038. Existing plane conversion and weapon-palette models can be reused, while actor_cast_native.py models a different combat cast setup and does not already prove this presentation chain. The next batch must implement and verify the actual dependencies before crediting C18707 or claiming the special animation interpreter complete.

## Joint source integration: 2026-10-09

Independent ca65/ld65 reconstruction now matches 1,341 blocks and 260 components: 82,054 total source bytes, including 79,496 instructions and 2,558 numeric data bytes; RAM 14,148 and ROM 67,906. This batch adds 1,355 instructions and 8 numeric dispatch bytes, without recounting reused helpers: directional load window 147, boss child definitions 156, actor charge-effect creation 694, descriptor-four callbacks and targeting helpers 358. Their complete original-execution reports remain separate from the matching assembly proof. Palette transition lifetime additionally passes 10,372 original calls but adds no instruction bytes. Documented ROM union is 813,670 / 2,097,152 = 38.79880905151367%, distinct from code decompilation; complete code denominator and full ROM rebuild remain open.
