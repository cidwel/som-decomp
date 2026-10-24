# Menu palette preparation, graphics transfer and dialogue closure

`EventMenuPaletteGraphics` composes nine complete native entries spanning 314 instruction bytes. Only 241 bytes are new: C070DF (4), C070E3 (9), C070EC (28), C00095 (3), D0CD8E (27), D0CDA9 (9), D0CDB2 (71) and D0CDF9 (90). C00EBF's 73-byte body already exists as `reset_map_menu_state.s`; the new CPU adapter reuses `map_transition_cleanup.menu_state`, improves its composed register/flag contract and receives zero duplicate credit.

The palette-slot selector preserves the accumulator's upper byte and selects one of eight banks using the primary party-mode flag. The OAM selector packs that bank into the original attribute word. Actor palette loading reads the saved actor identity, performs the native signed Mode7 multiply through real 211B/211C/2134 ports, and copies all 16 palette words from the original ROM. The default path copies 15 colors and requests the native EC bit-2 upload. The graphics routine performs all ten 64-byte DMA5 transfers from original ROM graphics to VRAM with the original indexed tile addresses. Dialogue closure preserves incoming D/DB/status and accumulator context while resetting all existing window-state fields.

The twelve-case smoke and first complete 3,584-call capture passed unchanged. Cases include all 256 palette request bytes in both modes through three selector entries (1,536), all 256 actor identities in both modes through both initializer/direct-copy entries (1,024), 128 default-palette cases, all 256 EC bytes, 128 ten-transfer DMA contexts, and 512 public/direct closure calls across D=0/300/1234 and DB=00/7E/7F/42. The Mode7 fixture varies prior latch and matrix values; DMA checks actual VRAM and peripheral mutations. Full WRAM outside the observed stack, CPU/status/S/D/DB, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts.

The capture contains 217 PC/M/X states and 109 dependency fingerprints. Stack watermarks are 1EF7, 1EF8, 1EF9, 1EFA, 1EFB, 1EFD and 1EFE. All nine complete bodies pass instruction-boundary and immediate-width recovery. These files and their dependencies are frozen for parent integration. The interactive menu driver, vblank/input schedule and event opcode 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_palette_graphics.py | d1418cb51e552c4690b82563773dc7bf1475360a919183ab0a237dffa55a4c28 |
| tools/event_menu_palette_selector.py | 4868fd04014ed447e98607f89bc2b73fcaa3c70733eed93bc2f1e49887fd7253 |
| tools/event_dialogue_close.py | 7a9a0e3ccdae766ffacfd718c18e9e2338a2c820021cd846ab16dd5d0049fed5 |
| data/event_menu_palette_graphics.json | e9279f9a5310624eb50aee0bfbe490beb03cff542a695318460c5e5a8c8ae596 |
| data/event_menu_palette_graphics.coverage.json | 9fd38b148fb377b44a4cf30c5ca3167b42643a9d27c96378ece2dcf7287bf345 |
