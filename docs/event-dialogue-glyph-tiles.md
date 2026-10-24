# Dialogue glyph bitmap expansion and overlap

`EventDialogueGlyphTiles` reconstructs six complete native entries, 201 new instruction bytes: C015B9 bitmap expansion/border merging (115), C0162C shifted bitmap overlap (55), C01663 no-op return (1), C01157 phase advance after no-op (7), C0115E expansion phase callback (7), and C01165 shifted composition/cursor-clear phase callback (16). Physical interval and model searches found no prior source for these bodies.

Expansion consumes all 384 bytes of 32 twelve-row glyphs, doubles row bytes into the native 32-byte tile layout, clears tile borders and merges neighboring plane bytes. Shifted composition uses the original ROL/LSR carry chain across rows and glyphs, retaining prior tile bits. Phase callbacks preserve native byte overflow and clear both upload cursors on the shifted phase. No renderer, upload or frame wait is bypassed in these complete memory-only bodies.

Eight smoke cases and the first complete 2,624-call capture passed unchanged. Five entries have 512 calls each, covering every phase byte with both incoming carries, uniform glyph patterns 00/01/7F/80/FF/AA/55/81, randomized 384-byte glyphs and existing 1,024-byte tile buffers. The native no-op has 64 register/status contexts. ABI is D=0, DB=7E, M8/X16, binary. Full WRAM outside observed stack, CPU/status/S/D/DB, decimal mode, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts.

The capture has 105 PC/M/X states, 110 dependency fingerprints and stack watermarks 1EFC/1EFE. All six bodies pass complete instruction-boundary and immediate-width recovery. Tool, report and capture are immutable for independent assembly. Full bitmap/font phase composition, general dialogue coordinator, interactive menu and opcode 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_glyph_tiles.py | 446f6e2a57131f0e8c209600588dc570eacc1cb11387fb5b2920882677076d23 |
| data/event_dialogue_glyph_tiles.json | eb57723626d3a0e3d7c7186f533b6ac0a3b5a55aec3ceb55c35cb9c152990512 |
| data/event_dialogue_glyph_tiles.coverage.json | 3e3086939fb1a26d75c37ab0e0044145bd1843e166faaf25f850ac59e35af078 |
