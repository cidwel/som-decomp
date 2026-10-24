# Native menu icon palette construction

Seven reconstructed bodies cover 220 bytes: D0CB1F/13 chooses the page; CB2C/3 selects the upper page and falls through; CB2F/115 builds rows; CBA2/29 reads enabled or disabled colors; CBBF/13 appends a color; CBD6/32 caches the selected 128-byte page; CD18/15 calculates its address. D0CBCC..CBD6 is a ten-byte disabled-color table, excluded from executable source credit.

## Evidence and domain

Smoke3 and the first full capture11 passed without corrections. The directed calls cover both palette pages, twelve rows with separators at row3/6/9, a three-row page, missing descriptors with disabled colors, enabled/disabled helper calls, append, cache and page selection. Colors come from original ROM tables at runtime. The produced row count is positive (1..12); zero is not represented as an ordinary terminating call.

The original bodies and callees execute without hooks. The proof compares CPU registers/flags/return context, all WRAM outside the observed stack and PPU/DMA/VRAM/CGRAM/input/audio state. All **108/108 instruction starts** across seven bodies have execution evidence, their boundaries and immediate widths recover exactly, and the capture contains 113 PC/M/X states. All 200 dependency hashes match. Models/checker/report/capture are frozen; source assembly and physical interval accounting belong to the root integrator.

Integration spec: `event_menu_icon_palette_check:EventMenuIconPalette:event-menu-icon-palette:event_menu_icon_palette`.

Grid/equipment-preview publication, the descriptor producer and the complete interactive menu remain separate unfinished contracts.

## Frozen hashes

- `tools/event_menu_icon_palette.py`: `66d3d139395e301c8127aa378556800807b9fd720f39aa5a4bbd96e7353303ee`
- `tools/event_menu_icon_palette_check.py`: `6fff7f9467e1eaedcd6cfafb3c8274c836564f90132df244bb7eaac874efa3cb`
- `data/event_menu_icon_palette.json`: `14e3acf588db8bcfad55a705ed3c28dd4ad79a511647e6e762af584304517a8e`
- `data/event_menu_icon_palette.coverage.json`: `7fd21f542b8b4b9e9d765eaccb282d8aeab76329eb979486894566dc343679e0`
- `data/event_menu_icon_palette.source_audit.json`: `70ea2901a6d774bd5bba69502e2cf0a069a268944a7c92529f3388b370fbd827`
