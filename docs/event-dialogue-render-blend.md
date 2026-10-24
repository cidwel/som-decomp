# Complete dialogue background masks, glyph planes and palette composition

`EventDialogueRenderBlend` reconstructs eight complete entries, 338 new instruction bytes: C0151A first bitplane wrapper (7), C01521 second bitplane loop (24), C01539 mask-pair row composer (101), C0159E background-style selector (27), C00DFC palette-copy helper (46), C00968 three-bank palette publication (82), C0040F primary-window phase increment (4), and C014EB complete glyph-composition phase (47). The four mask bodies reside in `event_dialogue_tile_masks.py`; the composed model/checker is in `event_dialogue_render_blend.py`. Existing font/parser/cursor dependencies are reused unchanged. Manifest interval/model searches found no prior sources for the eight bodies.

Each bitplane processes fourteen native pairs of tile groups. The composer preserves the unusual original rule: the complement of the even pixel's glyph mask is reused for the adjacent odd pixel before OR with its own glyph byte. The second half skips sixteen bytes and repeats with the original ROM background masks. Style selection computes the native pattern index from the WRAM style list. Palette publication copies three six-byte ROM color groups, rewrites both shared highlight colors and sets the final color 7C1F. The full C014EB phase composes both planes, advances its byte phase and publishes the actual palette/message flag when dialogue state is 1. Both controller-7 phase increments are retained.

Ten smoke cases and the first complete 8,192-call capture passed unchanged. Each entry has 1,024 calls spanning every style/phase byte in four state/controller contexts, uniform and randomized glyph masks, original ROM masks, both bitplanes, palette banks and complete active-state palette publication. Native ABI is D=0, DB=7E, M8/X16, binary. Full WRAM outside observed stack, CPU/status/S/D/DB, decimal mode, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts and no persisted ROM/graphics payload.

The capture contains 159 PC/M/X states and 114 dependency fingerprints. Stack watermarks are 1EF6, 1EF8, 1EFA, 1EFC, 1EFD and 1EFE. All eight complete bodies pass instruction-boundary and immediate-width recovery. Tools, report and capture are immutable for independent assembly. The next coherent block is complete tile-map/graphics-buffer publication and window phases; the general dialogue coordinator, interactive menu and event 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_render_blend.py | 5c0ef4aabeb629709e32b06679be187a3749080e72c18e08a48054be27656337 |
| tools/event_dialogue_tile_masks.py | 0776a0de738b24a290c9d1eb9b21e81a32a7bdb883200658b54a013ef0fb9ae5 |
| data/event_dialogue_render_blend.json | 07670a2cb5a7b04d94bb67ec36e6dce0667242dcb8b2947e023c8d26a074f9d7 |
| data/event_dialogue_render_blend.coverage.json | 0105d1f62deaee37e322f7cacdc91c7f769b83741e13933106c99afcdc092c8b |
