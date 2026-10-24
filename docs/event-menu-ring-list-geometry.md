# Native ring-list center, count and angle-table selection

Three complete bodies cover154 bytes: C07108/44 chooses hero and menu offsets; C07134/24 derives the center from actual hero coordinates; C0714C/86 changes shop actor context, counts terminated descriptors, selects the original angle table and returns the native empty/special-first guard. Empty list behavior is executed exactly, including the FFFE index of its table read; C06F93 redirects such a result before traversal. This validates the source producer for bounded positive ring row counts.

Smoke3 and the first full8 passed without changes: all three heroes, shop and alternate-menu offsets, empty list, special-first descriptor and direct center call. Original runtime tables, full WRAM outside observed stack, CPU/context and peripherals match.

Audit: **69/69 instruction starts**; every immediate width and body boundary matches source. All 216 dependency hashes are unchanged. No hooks or ROM/assets are persisted. The list constructor and seven-phase interactive menu remain open.

Integration spec: `event_menu_ring_list_geometry_check:EventMenuRingListGeometry:event-menu-ring-list-geometry:event_menu_ring_list_geometry`.

## Frozen hashes

- `tools/event_menu_ring_list_geometry.py`: `90edaa3a8d9ec1b6ac34273412f097c634823e965cf74fc9b8b3c49c891e78e6`
- `tools/event_menu_ring_list_geometry_check.py`: `5cdf084fd7bc75e2905c27b7b631a35e1bc84d1d0c86844e795c97587472094d`
- `data/event_menu_ring_list_geometry.json`: `46a4271c805fe7b247bf75b1e74ec95fd96f9de3a29e110c33b1b74cf1ccb380`
- `data/event_menu_ring_list_geometry.coverage.json`: `2109f46e8ad54388a4534083153edb4c69e9e7e15c3ab118f9638e94e92764d7`
- `data/event_menu_ring_list_geometry.source_audit.json`: `5f02f419121d81a15e5430b1b86eca749502ef2df62acf36b5b60562e1bd9aa3`
