# Native inventory descriptor category rows

Four reconstructed bodies cover 275 bytes: D0D0FB/45 publishes consumables; D0D128/134 builds owned weapon/armor rows including the special seventh slot; D0D1CF/44 constructs armor rows with actual positional description offset and ownership attributes; D0D22F/52 builds the three general inventory categories with their real category spans. Frozen table, row-attribute and description-offset helpers are reused intact.

Smoke 3 and the first full capture 9 passed without corrections. Cases cover consumable filters and missing slots, hero zero, both owned equipment arrays, special seventh-slot branches, armor rows and all three general categories. Original descriptor tables are read at runtime; inventory arrays include their native FF holes. The produced ABI is D0/DB0/M16/X16 with valid category/item indices and a descriptor output pointer.

All **124/124 instruction starts**, four exact boundaries and all immediate widths have original execution evidence. Capture: 270 PC/M/X states; all 206 dependency hashes match. Full WRAM outside observed stack, CPU/context and graphics/input/audio peripherals match; no native callees are bypassed. Models/checker/report/capture are frozen.

Integration spec: `event_menu_inventory_rows_check:EventMenuInventoryRows:event-menu-inventory-rows:event_menu_inventory_rows`.

Inventory status masks and CF9C descriptor composition are subsequent contracts; the full interactive menu remains open.

## Frozen hashes

- `tools/event_menu_inventory_rows.py`: `970578a7c73d19252b9d5aab3c05a98c70e607a27b3595e2ebfaac4bca02c72c`
- `tools/event_menu_inventory_rows_check.py`: `c2bcc7abd6f55ade22bd0492a3a2b4d29573ce881e51400a323b3dfa574f93f3`
- `data/event_menu_inventory_rows.json`: `a9eb290fa30d6bd48774b5e935587b39523d94b4f9cb9fc6df32063459688d98`
- `data/event_menu_inventory_rows.coverage.json`: `19ced1aa025251ecf96209fc91839d98bf6d756817d7e64ccb9731665fa45544`
- `data/event_menu_inventory_rows.source_audit.json`: `1830856f1da95baeb0a8026fbd0f5e7e00ce470078221d8c5c738ea8e47c1425`
