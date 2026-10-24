# Native menu icon grid and equipment-preview publication

Five reconstructed bodies cover 138 bytes: D0C8FB/16 publishes icon graphics; C90B/19 selects grid or equipment layout; C91E/45 transfers one equipment row and its optional next-tile overlay; C94B/43 publishes twelve grid tiles; C06977/15 waits for a real vblank, publishes graphics, waits again and publishes their palette. Lower icon expansion/upload and palette models are reused frozen.

Smoke2 and the first full capture10 passed without changes. Directed cases exercise both layouts and direct entry contracts, all three overlay paths (valid, missing descriptor, zero overlay flags), the twelve-icon grid split into eight/four tiles in VRAM6E00/7000, and the complete C06977 caller in both layouts. Actual vblank events execute C0C0A8/RTI; no handler or native callee is bypassed. Descriptor/graphic/palette tables are read from the original ROM at runtime.

All **57/57 instruction starts** across five bodies were observed; their boundaries and immediate widths recover exactly. The capture contains 416 PC/M/X states and all 201 dependency hashes still match. Full WRAM outside observed stack, CPU registers/flags/context and graphics/input/audio/frame peripherals match the original. The captured models/checker/report/coverage are frozen.

Integration spec: `event_menu_icon_grid_check:EventMenuIconGrid:event-menu-icon-grid:event_menu_icon_grid`.

This is the complete graphic/palette publication caller, not the complete interactive C066B5/C0666F menu. Descriptor construction, list geometry, menu phase dispatch and action consumers remain open.

## Frozen hashes

- `tools/event_menu_icon_grid.py`: `765932f38a9746566a2ba513101c9c2f07cb5fa1e275737aa1a47d5ed66e90f0`
- `tools/event_menu_icon_grid_check.py`: `b2f458200c542d66bb40fbb4fa683f8ab281d6cd8499f7478f3c5bf706d8741f`
- `data/event_menu_icon_grid.json`: `b10790e5485206bc22553fb8ffe74a54c529828fad09e73feeab61c60b35046a`
- `data/event_menu_icon_grid.coverage.json`: `cca475c1231136101574c3a7d92c6522a83954ce79e6d9cf2a84d9ddf2ba6f98`
- `data/event_menu_icon_grid.source_audit.json`: `c9b6c7dcfb34aae72e37ae77ce427f5523201aa450f6b158e279ae4372479db3`
