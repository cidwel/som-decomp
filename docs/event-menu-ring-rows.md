# Native menu ring traversal and input-aware repeat

C06D1C/27 traverses every produced ring row and preserves the count/index around each full row call; C06D55/31 waits and polls real input between repeat frames, propagating actual reset transfers. The positive rowcount1..12 domain comes from C07108 counting the terminated descriptors produced by the complete builder; an empty list re-enters category selection in C06F93 before a ring is traversed. Raw count0 would execute65536 iterations, so it is outside this produced bounded ring ABI.

Smoke2 and first full6 passed without corrections: counts1/3/12, repeat0 and held/released contexts with real vblank/RTI and input sampling. Primary all-start audit is27/28: C06D70 is absent because the sampled direction stays held in those fixtures. A separate single-call supplement with explicit zero autojoypad/serial inputs passed on its first capture and observes C06D70. Primary evidence is unchanged; union now closes all58 bytes.

Audit: **28/28 instruction starts in the union**, every immediate width and all body boundaries reproduce source exactly. All 214 dependency hashes match. The outer seven-phase dispatcher and interactive C0666F/C066B5 menu remain open. No hooks or ROM/assets are persisted.

Integration spec: `event_menu_ring_rows_check:EventMenuRingRows:event-menu-ring-rows:event_menu_ring_rows`.

## Frozen primary hashes

- `tools/event_menu_ring_rows.py`: `2621c6edd92fcb46799dbc9f2991d538adb4eaf20c79c1bc7f983542a3847eb3`
- `tools/event_menu_ring_rows_check.py`: `1f0ff8f1580f98276d10e6f850e6e79d097649c8e35e7def11bc4bf942cdaaf4`
- `data/event_menu_ring_rows.json`: `4417b5eb75d265ede8d80ebb625e1311ef989cf4145dd9b7eaaddbb31af86365`
- `data/event_menu_ring_rows.coverage.json`: `ec1682bce6fb45a2bb4701608159501621ab15d6bcbfec91b49cc090952ed0f6`
- `data/event_menu_ring_rows.source_audit.json`: `d803dc0354395f98b0665e57e629e77c679f06fba6bdd26b0c3475432bca048b`

## Supplement and union hashes

- `tools/event_menu_ring_rows_guard.py`: `ea87514a23ca7ad2eb1b3df21700b03687cadc55affe88a10f741beef36355d3`
- `data/event_menu_ring_rows_guard.json`: `6ab8522c10ae98ddddb2cedbaaac3520e7ff7e1a5df2b5f10836eba905f38d3f`
- `data/event_menu_ring_rows_guard.coverage.json`: `c2662c14b90d48c22a76e75485c8e3c8089280f7e2c0968842afd59194608dca`
- `data/event_menu_ring_rows.complete_source_audit.json`: `dcb79683caacc4ac017ce8a8d83cd55735b02542a6fa0d5ff1eed640a24c2377`
