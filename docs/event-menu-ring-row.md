# Native menu ring-row motion and OAM publication

C06D74/281 is reconstructed completely: phase/direction angle updates, boundary crossing and selection wrap, native CF10 selection sound, shop half-turn, centered projection, clipping, blink cadence, primary OAM words and secondary hero marker placement. It composes the original projection/audio bodies and frozen row-visibility helper; no branch or sound callback is replaced.

Smoke3 and first full12 passed without corrections: idle and both phase groups, positive/negative/exact-zero crossings, shop, x/y clipping, blink4/8 and marker absent. Runtime tables remain in ROM. Full native callees, WRAM outside observed stack, CPU/context, OAM and peripherals/ACK state match.

Audit: **133/133 instruction starts**, every immediate width and all body boundaries reproduce source exactly. All 212 dependency hashes match. The outer seven-phase dispatcher and interactive C0666F/C066B5 menu remain open. No hooks or ROM/assets are persisted.

Integration spec: `event_menu_ring_row_check:EventMenuRingRow:event-menu-ring-row:event_menu_ring_row`.

## Frozen primary hashes

- `tools/event_menu_ring_row.py`: `63231904392a9690eee177b6a21f12acb4a985e05f6bba6199f29192395dc2e4`
- `tools/event_menu_ring_row_check.py`: `dca26724006c91c1cd1cf9598ae40804915122216718e2331f5704c4565f0ae7`
- `data/event_menu_ring_row.json`: `fb13c21d92e659f41ee2e00e9e2da6d6cac4a6ad8dfb527ac34108571b65322e`
- `data/event_menu_ring_row.coverage.json`: `e112748b9366d4a2bb3468134992041352ca2dad55411ffc427e0ad07b045796`
- `data/event_menu_ring_row.source_audit.json`: `51162391e396ea009e1331831724f36b1d48ac562245181e679ce21009c11be1`
