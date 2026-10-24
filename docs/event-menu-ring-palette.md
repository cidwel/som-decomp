# Native ring-menu palette animation

Four complete bodies cover290 bytes: D0CBF6/27 dispatches category1 weapon animation; CC11/104 updates every third frame from original D9FEF4 colors and cached palette; CC79/93 rotates enabled packed-row colors every sixth frame and toggles blink every twelfth; CCD6/66 rotates one five-word row and preserves disabled colors. CD18/CDA9 remain frozen existing helpers and receive no new credit.

Smoke2 and the first full9 passed without changes: category bypass, weapon cadence/wrap, packed cadence/rotation, both blink toggles, enabled/disabled row rotation. Full original callees, WRAM outside observed stack, CPU/context and graphics/audio/input/arithmetic peripherals match.

Audit: **129/129 instruction starts**; every immediate width and body boundary matches source. All 215 dependency hashes are unchanged. No hooks or ROM/assets are persisted. The list constructor and seven-phase interactive menu remain open.

Integration spec: `event_menu_ring_palette_check:EventMenuRingPalette:event-menu-ring-palette:event_menu_ring_palette`.

## Frozen hashes

- `tools/event_menu_ring_palette.py`: `01b434a5e2330759d58d799ed63b1389ce756cf6770ae8d37bc41d4a577e78ec`
- `tools/event_menu_ring_palette_check.py`: `157877ead9fa2bc8c1126ab34008dd83b0d556b57f27d7d11bfdaf062db8c36c`
- `data/event_menu_ring_palette.json`: `a6847333fa76396bd3f33488b475fb8ee104f3125d0d37f8d74cb9b749549f8f`
- `data/event_menu_ring_palette.coverage.json`: `49dea784e426ac3bbe41d90590791a8e7ff210db52b7fe27673620f04887f844`
- `data/event_menu_ring_palette.source_audit.json`: `296962cefce947e508864b3d12dfc129f2870f0271244f49204075871e0588c9`
