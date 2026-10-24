# Complete renderer and window completion dispatch

`EventDialogueRenderCore` reconstructs C0111A (37 bytes), all eleven rendering phases and its pause branch, and C012FF (35), the complete ordinary three-vector/controller-seven six-vector window completion dispatcher. Eighteen new dependencies reconstruct window erase, final script continuation, tile orientation, style palette publication, native row raster and tile sequencing. These twenty candidate bodies total 1,083 bytes; source accounting belongs to the manifest integrator.

The native input domain uses D=0, DB=7E, M8/X16 and binary arithmetic. ROM geometry states 0/1/2 supply heights 6/2/2 and widths 28/28/9. Eight original styles, all four pixel orientations, generated glyph rows and ephemeral script input are retained. A158 is initialized to zero by the actual C7502E producer, next to C75029's initialization of A157; arbitrary data in this high byte instead makes native tilemap addressing corrupt the caller's stack. The C004D0 orientation vector order is read directly from C010FA: 04E2, 054D, 0515, 0583.

After correcting that omitted fixture initialization and the model's initially swapped middle orientation vectors, the 41-case smoke and 5,120 native calls passed. The capture comprises 18 helper bodies ×128 contexts, nine completion vectors ×128, eleven render phases ×128, and all 256 pause flag values. Full WRAM outside the actual observed stack, all CPU results/status/S/D/DB, graphics/arithmetic peripherals and audio acknowledgement state agree. No hooks, interrupts or stored ROM/graphics/script payloads are used.

The primary capture has 1,326 PC/M/X states, 121 dependency fingerprints and native stack watermarks from 1EED to 1EFE. Eighteen bodies pass both immediate-width recovery and observation of every instruction start. Two bodies await a separate directed supplement: C00644's CFF8=0 fill branch includes unobserved immediate C0065D, and C00478's reverse sequence has unobserved C004A4/C004A5. The primary tool, four helper modules, report and coverage remain frozen while that supplement is prepared; this primary capture alone is insufficient evidence for recovering all twenty bodies.

The new phase-8 equality contexts execute C0129B with M8/X16. That supplies the previously missing line-completion branch without changing the frozen LineCompletion315 tool or its 5,120-call capture and adds no source credit.

Window construction state 50, controller inputs/polling, numeric selection and the full interactive menu/text coordinator remain separate work. This delivery closes the renderer dispatcher only after its directed dependency supplement, not the entire text engine or event 2E.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_render_core.py | 01853498bbc0083abf549b0948659d984c9bd8adac96ce89cac96d24457f574e |
| tools/event_dialogue_window_clear.py | 02c32e4051cc80fd5e84767116eaa11b84d348d460a4dda78c22aace1fe4a604 |
| tools/event_dialogue_window_tiles.py | ca78faf2fef5d6780e8899cda23cd5e4c589a51495ee3db31cb1bc2d57b8e35d |
| tools/event_dialogue_window_tile_loops.py | dc209c3051cf4078d9c0383672c6e45912ec655273cc6d0b054dd2b88ff5fec4 |
| tools/event_dialogue_window_raster.py | 9853453152b314b1c7d89d84ac02bb682792612887f80bfa2be9a87da9366dd5 |
| data/event_dialogue_render_core.json | 7cbc1f522f3edd80ecd791aa373480731c649961d1f9f6640cbb693d2c079fb9 |
| data/event_dialogue_render_core.coverage.json | 1349be70ff1d4401ae4f71ce5444eceb067974c518d3050f6c0be0bbf26d6c41 |

## Directed supplement closes the dependency evidence

The separate `event_dialogue_render_core_guard.py` smoke (4 cases) and 32 native calls passed unchanged. Sixteen contexts each for C00644 and C00478 explicitly alternate zero/nonzero CFF8 and select reverse phases A15C=5/6. The supplement captures 280 PC/M/X states and leaves the primary tools/report/capture intact. Combined evidence now observes 504/504 instruction starts across all twenty bodies and supplies unambiguous immediate widths for 20/20 sources. C00644 contributes 40 observed starts and C00478 contributes 46. The 188 bytes of these two bodies finish the 1,083-byte candidate group; the supplement itself adds no duplicate source credit. C0129B remains observed in the primary new capture at M8/X16, completing the previous LineCompletion 126/127 gap.

| Supplement artifact | SHA-256 |
|---|---|
| tools/event_dialogue_render_core_guard.py | bcef26051b91a760f3db5b15631a33a0693d231fa207c07696cbe4872762b0cb |
| data/event_dialogue_render_core_guard.json | f1938a28810d8b360be8dbaafb93d7b0584004d54ec0fbb670d0ddbd9c701254 |
| data/event_dialogue_render_core_guard.coverage.json | f5b04dacbdc8f7e364055c3ff80c5cf6897cabf13b1b34efea5df44b3ce1653b |
