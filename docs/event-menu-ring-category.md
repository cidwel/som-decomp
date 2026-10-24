# Native menu ring category stepping

C06EF0/110 reconstructs category stepping completely: packed categories4..6, shop skip-loop across ordinary equipment categories, normal four-category wrap and missing-hero backward skip. The produced direction is +1/-1; the original shop skip loop is preserved.

Smoke3 and the first full10 passed without changes. Packed lower/middle/wrap, shop backward/skip/wrap, ordinary backward/wrap and missing/present hero paths cover every instruction. Full original loop, byte flags, WRAM outside observed stack, CPU/context and peripherals match.

Audit: **53/53 instruction starts**; every immediate width and body boundary matches source. All 217 dependency hashes are unchanged. No hooks or ROM/assets are persisted. The list constructor and seven-phase interactive menu remain open.

Integration spec: `event_menu_ring_category_check:EventMenuRingCategory:event-menu-ring-category:event_menu_ring_category`.

## Frozen hashes

- `tools/event_menu_ring_category.py`: `b9ba1eb7df09c492ae96cdbf4bdf0b155c71da742df2c5ba5b039af2568d706b`
- `tools/event_menu_ring_category_check.py`: `484eabd892af03aae8d587f60525a8d9ea898436edc8b473a6c09030c7d4c33f`
- `data/event_menu_ring_category.json`: `487ff32e6ff7814cd77295d2f874f08319df85ad7279d61027c7c62d0f019a82`
- `data/event_menu_ring_category.coverage.json`: `662a611144b6f0f8a924cf98010a3b5b4655a569362aac26d5294fa702c18afb`
- `data/event_menu_ring_category.source_audit.json`: `873a9b8201fb709af39741912486519e8f177c7dbad68e1104f2bf32cf238ff8`
