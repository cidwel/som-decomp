# Native menu ring projection and visibility

Eight bodies cover 192 candidate instruction bytes: D9FC00/80 dispatches four angle quadrants, FC50/4 negates and falls through, FC54/8 adds the vertical center, FC5C/23 selects the complementary quarter-wave, FC73/1 transfers the index, FC74/28 performs the actual SNES multiplier calculation. C06D37/30 selects a neighboring row with native byte wrap and preserved comparison flags; C06E8D/18 returns carry for x>=256 or y>=232. The original D97DE0 quarter-wave table stays in the ROM.

Smoke3 and the first complete capture21 passed without corrections. Cases cover every quadrant at axis and nonzero angles, direct helpers, both wrap directions and visibility/clipping. Full WRAM outside the observed stack, CPU/context, arithmetic ports and graphics/input/audio peripherals match.

Audit: **93/93 instruction starts**, every immediate width and all body boundaries reproduce source exactly. All 210 dependency hashes match. The outer seven-phase dispatcher and interactive C0666F/C066B5 menu remain open. No hooks or ROM/assets are persisted.

Integration spec: `event_menu_ring_geometry_check:EventMenuRingGeometry:event-menu-ring-geometry:event_menu_ring_geometry`.

## Frozen primary hashes

- `tools/event_menu_ring_projection.py`: `2152a6d2231334bffc9c71636c8c311ee4d8ad0bea99ae0dc2015fcbd7e567d4`
- `tools/event_menu_ring_geometry.py`: `1ed7ae7e75b6b3ab532f8f73a50f32c1fe408cb590151576e68a37d9c4a06d28`
- `tools/event_menu_ring_geometry_check.py`: `8f5330a77272c3fbae42e101deceaaff9b7786301484fca6c6e6add1f56c35e0`
- `data/event_menu_ring_geometry.json`: `e09c472c7680accdaf0b129418c3979f8b97f4e9edadcd2398f971ef14429cb1`
- `data/event_menu_ring_geometry.coverage.json`: `b1a597b7e94c02b476b0312a7a7301fe77241fded8facaa9c1bf7669767f9145`
- `data/event_menu_ring_geometry.source_audit.json`: `3f3a264fce5eb655f5236bd9ff2fe7588d73200af6ee169e40305858abf62b9f`
