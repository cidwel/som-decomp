# Native menu graphics and text tiles — verified

## Verified checkpoint — 2026-10-10

328 complete graphics original calls plus60 complete text-tile original calls;157/157 and66/66 own starts;363+134 matching instruction bytes. Zero-length ROM DMA is tested; full-bank zero-length WRAM DMA is outside the contract because it copies the live native stack. Every new source body independently assembles exactly to the original ROM. Own captured widths and current proof/dependency hashes pass data/event_native_menu_source_audit.json. Full C01D97 interaction, asynchronous timing and rendered pixels remain open. Preparation notes below describe the earlier pre-verification state, superseded by this checkpoint.


`event_menu_graphics.py` reconstructs 363 matching instruction bytes in twelve
entry ranges: the full packed glyph grid, its single-byte bitplane expansion,
ROM/WRAM tile and palette transfers, four description-row uploads, workspace
clears and background/scroll setup. Shared DMA suffixes are represented once.
The model uses the real peripheral bus, including DMA length zero, address wrap
and the ordered VRAM/CGRAM writes.

`event_menu_text_tiles.py` reconstructs another 134 matching instruction bytes
in five complete bodies: the actual ROM grid at D2D880, the 32-row doubled text
layout, half-row assembly, its border clears and tile upload. ROM data is read
at runtime; no glyph payload is stored here.

The frozen comparisons pass328 graphics calls and60 text-tile calls, with
157/157 and66/66 own instruction starts. Each source body assembles exactly.
Zero-length ROM DMA exercises the full65536-byte bus transfer; zero-length
WRAM DMA is outside the contract because it copies the live native stack.
The actual menu callers use nonzero WRAM tile/palette lengths.

Full C01D97 interaction, font-script composition and rendering timing remain
open. C0281E construction is now verified by event_menu_constructor.py.
Hashes, proof counts and credit are recorded in
`data/event_menu_screen_preparation.json` and the own-source audit.
