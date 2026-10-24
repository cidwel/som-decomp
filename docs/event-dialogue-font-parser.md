# Complete native dialogue font parser and insertion commands

`EventDialogueFontParser` reconstructs the complete contiguous C016B8..C01935 block, 638 new instruction bytes. This includes the parser, emission helper and all ten text command families: no-op, three original ROM name lists, actor names from WRAM, number-list clearing, word/byte glyph positions, appended numeric positions and saved numeric/script positions. Manifest interval and model searches found no previous complete source for this block. Legacy `text_decode.py` documents the encoding and compares observed glyph prefixes, but does not provide the native CPU/state contract reconstructed here.

The native parser fills 33 blank glyph positions, computes remaining line width, reads the actual script bank/pointer, emits single glyphs or ROM pairs, dispatches insertion commands, restores saved scripts and stops at actual page/end/line conditions. It preserves literal overlapping word stores and the distinction between word and byte position commands. Input 5F takes the original pair branch: subtraction underflows the 16-bit pair-table offset, and its long indexed read carries into the next ROM bank. The legacy pair decoder does not reproduce this edge; the new model preserves the actual original addressing and flags.

Line completion uses the original nonlocal stack unwind. C017C7 jumps to C0179E, where PLX consumes the emitter's JSR return frame; X therefore holds 1726 or 172D according to the original call site. The parser restores its caller's DB and stores the current script cursor before returning. The fixture does not bypass this path or call the helper only under a non-full-line guard.

The twelve-case smoke and first complete 5,120-call capture passed unchanged. Five families have 1,024 cases each: every lead byte, all ten insertion commands with varied argument bytes, full-line streams, saved-script return, and every message flag byte. Four contexts span line widths 1/2/16/32 and both full-line C6 guard states. ROM name/pair tables are read at runtime; generated WRAM names are terminated, and no ROM/script payload is saved. Native ABI is D=0, DB=7E, M8/X16, binary. Full WRAM outside observed stack, CPU/status/S/D/DB, decimal mode, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts.

The capture contains 293 PC/M/X states and 111 dependency fingerprints. Stack watermarks are 1EF5, 1EF6, 1EF8, 1EFB and 1EFC. Every instruction boundary and immediate width in the complete 638-byte block passes source recovery. Tool, report and capture are immutable for independent assembly. The bitmap renderer, general dialogue coordinator, interactive menu and event 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_font_parser.py | dd7977b339892c6e2b8b63f03b42696606772eec1c996ee6422b5d1775798192 |
| data/event_dialogue_font_parser.json | 44959cc11dcd1d8cb6d32e11f612d71405372fc6611a81deabfb0e8721011499 |
| data/event_dialogue_font_parser.coverage.json | 7f765de8bca6085379da92e24aaf86493d396a83637addeba6d1c6a2ca44e444 |
