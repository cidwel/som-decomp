# Native name-entry helpers

[V] Seven complete bodies cover 377 instruction bytes: C7503D (66), C750E0 (57), C75119 (47), C75148 (26), C75162 (31), C75181 (65), C751C2 (85). The readable model is `tools/event_menu_name_helpers.py`.

C7503D emits four OAM corners at the selection cursor, retaining native byte overflow and flags. C750E0 converts the pixel cursor to a tile-grid offset; an empty tile leaves carry set and preserves the previous pair, while a nonempty tile records consecutive top/bottom glyph tiles and clears carry. C75119 clears that pair and publishes it to the name workspace through shared tail C75124, setting the tile-publication bit.

C75162 compares the selected hero name with the other two twelve-byte names, stopping at the first exact match. C75181 checks all twelve bytes and preserves the incoming difference flag unless a difference sets it. C751C2 clears 384 bytes in each of three hero extension records, seeds ids 80/81/82 and name-entry flags, and restores the incoming data bank.

The smoke7 and first complete84-case original comparisons both returned successfully. Cases exercise empty/nonempty/wrapped tile values, OAM coordinate overflow, all heroes, identical names and differences at the first or last byte, and restored DB0/7E/7F/42 in the initializer. They compare full memories, peripherals, registers, flags and calling context outside the observed native stack; no replacement callees or interrupt hooks are used. D0, M8/X16 and binary arithmetic are the tested contracts; other helpers require DB7E.

Evidence: `data/event_menu_name_helpers_proof.json` and its `.coverage.json`; captured dependency SHA256 values are recorded in the report. The full interactive name page, input loop, name encoding/save checksum and other C7 page coordinators remain open. The instruction-start audit observes every own start with unambiguous immediate widths; all seven source bodies independently assemble byte for byte.

Own instruction starts: 175/175. Original instructions executed across84 cases:33,558.

SHA256 fingerprints:
- `tools/event_menu_name_helpers.py`: `0c84472961e24d57ce09616923fbb5df6b88b7a8e9f4ddbac132dfdd1a4abd6f`
- `tools/event_menu_name_helpers_proof.py`: `e653879664c21298a90cc55026b28b9a50f5bdba493e28e5f914ea2f009e3d23`
- `data/event_menu_name_helpers_proof.json`: `6fe7302b3bafd696c2c4a0ce2ff8a1cf9266e9211dd822a74c27ca4bb3f07ed9`
- `data/event_menu_name_helpers_proof.coverage.json`: `7235d0143c83160c4935867fa2b5e4d2120ab774347c3cc117f995ae5e87dda6`
- `data/event_menu_name_helpers_source_audit.json`: `37ee3b44c26d4b06ed827c4b77622e592fa8471954f9bc874b434c09b92ebf30`
