# Native menu shop, inventory and packed-equipment coordinator

Six reconstructed bodies cover 334 candidate bytes: D0CF48/25 selects shop versus inventory; CF9C/37 builds descriptors, applies actual status masks and rotates rows; CFC1/43 dispatches seven categories or packed equipment with real mode2 guards; CFFA/94 builds three packed rank rows; D058/88 appends one enabled rank row and eligibility attributes; C073AC/47 tests hero state and equipment level. The fourteen-byte CFEC jump table is data.

The composition executes the complete shop/category/ownership/status/order chain, using frozen models without bypasses. Its equipment description helper reproduces D0CEBF/32, already an interior of the frozen CE5D/130 source; those 32 bytes receive **zero new source credit**.

Smoke 3 and the first complete capture 21 passed without corrections. Cases include all seven ordinary categories, shop, packed weapon/armor, both mode2 guard outcomes, direct dispatch and row calls, absent row, valid hero/weapon/armor and failed state/level eligibility. Full WRAM outside observed stack, CPU/context and graphics/input/audio peripherals match the original. Runtime tables are read from the ROM; no payloads are saved.

Primary audit observes 165/170 instruction starts, including all 16 starts in the existing CEBF interior. A separate two-call full-CF9C supplement passed on its first execution: blocked packed-weapon state80 observes D098/9A/9D/A0, and eighth armor slot observes D027. The frozen primary is unchanged. The union now observes **170/170 instruction starts**, supplies every immediate-width state and reproduces all six body boundaries exactly; it also validates the existing CEBF interior without new credit. All primary 209 and supplement 210 dependency hashes match. The completed six-body source claim is **334 new bytes**; union contains 672 PC/M/X states.

Integration spec: `event_menu_inventory_builder_check:EventMenuInventoryBuilder:event-menu-inventory-builder:event_menu_inventory_builder`; supplemental validator `event_menu_inventory_builder_guard.py`.

The next frontier is native list/ring geometry, the seven-phase dispatcher C06BF8 and action consumers C067A8. The full C0666F/C066B5 interactive menu remains open.

## Primary frozen hashes

- `tools/event_menu_inventory_builder.py`: `b85a81c655e73e86d9eb9bb259b8923fc7af8879f2eac0603a365adbee7bed92`
- `tools/event_menu_inventory_builder_check.py`: `ff7f32c7509943c9ff51498108d9ae607ab8f9e4208f26d4b73d4a2a6b542f1e`
- `data/event_menu_inventory_builder.json`: `31877dfa03f68b9a500c018942c1afe194a8a3f15948b56e3d7b173451a04121`
- `data/event_menu_inventory_builder.coverage.json`: `b348cdfa93f31b7931dc00143f89d6d2141a2d8578a23acad4da58e0a0d7cd79`
- `data/event_menu_inventory_builder.source_audit.json`: `a04018a917db33863687a755b55b8f8a12f47bf51442c4aedf905f9115667e24`

## Supplement and union frozen hashes

- `tools/event_menu_inventory_builder_guard.py`: `cf0986173e9d360f099208d7170880f792e27ff32aee7da173a8b95ba175f67a`
- `data/event_menu_inventory_builder_guard.json`: `49d18b13dfda2e65d079408001d3b8b35d7a4dd5cee012cef5c9c83e1f72d4d7`
- `data/event_menu_inventory_builder_guard.coverage.json`: `b60e1dd77fbc394e4ca91faf3fe1b5e386fbe21131d5bc65b414a1782ad4f988`
- `data/event_menu_inventory_builder.complete_source_audit.json`: `33042c9b70a9ddd0c4bda8e72ecc35bbd420e13dc8d54043e2b6bf080b2669ce`
