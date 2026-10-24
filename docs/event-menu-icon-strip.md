# Native twelve-icon strip and public publication wrapper

Two reconstructed bodies cover110bytes: D0C8A3/88 expands twelve icon descriptors, applies the native eight/four tile spacing, constructs the upper icon palette and transfers its128bytes to CGRAM; D0C856/22 saves D/DB/P, calls the real menu context normalizer C064A4, resolves twelve descriptors, invokes the complete strip and restores context. Frozen icon expansion, upload, palette and descriptor preparation are reused intact.

Smoke2 and the first full capture5 passed without changes. Cases include forced publication, a vblank already in progress, a normal public wrapper, foreign DB7F/D0300 context and an incoming byte-index context. The original loads descriptor/graphics/color tables at runtime, executes both64byte icon transfers for all twelve tiles and the palette DMA. No native callee is bypassed.

All **51/51 instruction starts**, both exact boundaries and all immediate widths have original execution evidence. Capture425 PC/M/Xstates; all203dependency hashes match. Full WRAM outside the observed stack, CPU flags/registers/context and PPU/DMA/VRAM/CGRAM/input/audio state match. Models/checker/report/capture are frozen.

Integration spec: `event_menu_icon_strip_check:EventMenuIconStrip:event-menu-icon-strip:event_menu_icon_strip`.

The complete interactive menu remains unfinished. Inventory/shop descriptor producers, list geometry, menu phase dispatch and action consumers are subsequent contracts.

## Frozen hashes

- `tools/event_menu_icon_strip.py`: `61cdaabffd2b1f44975e0cc030ef8ba33ad5ba1c467e4bf6322f8d56399a4f66`
- `tools/event_menu_icon_strip_check.py`: `2ed6296c5f18d1eb99c45dfbc865699ef57f559e9facf27b3191b4f0fc23fdf4`
- `data/event_menu_icon_strip.json`: `eb373893209f9353e6f4a6973b37f6be4e3912a0074ae3edff928741cc74f8db`
- `data/event_menu_icon_strip.coverage.json`: `90600c267629446023d0385298032663962f61f402382199ce3bfcb156dcf277`
- `data/event_menu_icon_strip.source_audit.json`: `3b1933331f46f6c510c36fab721613d6b4906a403ab396136430bcc45e341494`
