# Dialogue font row lookup and parser phase composition

`EventDialogueFontRows` reconstructs four complete entries, 156 new instruction bytes: C013CD empty-line layout update (48), C01664 glyph row lookup (84), C01150 row-fetch phase callback (7), and C0113F complete parser phase callback (17). The latter 17 bytes are a new callback at C0113F, not the shared render-origin helper C0197C. C0197C remains inside the existing NumericWindow C0193F/90 body and is reused without additional source credit.

Row lookup expands all 32 glyph indices into their twelve original ROM bitmap rows, using literal sixteen-bit index arithmetic and long-bank carry. The empty-line branch handles the real controller-5 exception, advances line coordinates and tile origin, resets rendering state and requests the original next phase. C0113F sets message flag 1D04.0, executes the full verified font parser including its nonlocal line unwind, and advances its byte phase counter. The initial ten-case smoke caught a transcribed flag address 1D00 instead of the literal 1D04; only the new callback model was corrected. The repeated smoke and first full capture then passed unchanged.

The 4,096-call capture has 1,024 calls per entry, spanning all 256 glyph/phase bytes with four count/controller contexts, empty and nonempty rows, controller 5, full word line heights, and bounded glyph streams with widths 1/2/16/32. Native ABI is D=0, DB=7E, M8/X16, binary. Full WRAM outside observed stack, CPU/status/S/D/DB, decimal mode, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts.

The capture contains 162 PC/M/X states, 112 dependency fingerprints and stack watermarks 1EF6/1EF8/1EFA/1EFC. All four complete bodies pass instruction-boundary and immediate-width recovery. Tools, report and capture are immutable for independent assembly. Full rendering publication, dialogue coordinator, interactive menu and event 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_font_rows.py | c10173558677afcc0f934aa4e4be4dd85afa36dc7b1a0c186769cdeaeb4e1854 |
| data/event_dialogue_font_rows.json | ca903ef3c57b73145846f6ffde40927504c86dfe2424255a4c5d2643cd39f5e1 |
| data/event_dialogue_font_rows.coverage.json | d8973918d8f6b7e3223ba4afa7e1c3c8476119ba4f4f5788f37a62b04c0c2bf8 |
