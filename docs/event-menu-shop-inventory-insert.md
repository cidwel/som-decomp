# Native purchased-item inventory insertion

C07D83/46 preserves the native shop-item conversion (subtract123, and for IDs beyond the armor range subtract63 then add64), invokes the existing complete public C00051 inventory command, returns its actual CF0F result and clears that result byte. The insertion call retains its full native status/context contract; it is not replaced by direct synthetic inventory writes.

Smoke2 and first full7 passed: head/body/accessory insertion, new consumable, incremented quantity, quantity cap and armor inventory full. Fixtures use real classified hero records and valid physical inventory slots, with explicit existing quantity/capacity states. All20/20 own instruction starts and widths are observed,113 distinct PCs and403 dependency hashes unchanged. WRAM, full CPU/context and peripherals match without hooks, with discarded ordinary call-frame bytes excluded by the observed watermark.

One body totals46 candidate new instruction bytes with no physical manifest overlap at preparation. Existing C00051 and all category/quantity insertion callees receive zero duplicate credit. Outer shop confirmation/payment callbacks remain open. Integration spec: `event_menu_shop_inventory_insert_check:EventMenuShopInventoryInsert:event-menu-shop-inventory-insert:event_menu_shop_inventory_insert`.

## Frozen hashes

- `tools/event_menu_shop_inventory_insert.py`: `6be1d8d8f57ca0765a473ef49c3f60709f92785e2bff6fee2a40d60bb0acc92a`
- `tools/event_menu_shop_inventory_insert_check.py`: `ab001dbf8350422fe392f7e86d58d03727e9ddbd97d6d1a3453992e646ad8c33`
- `data/event_menu_shop_inventory_insert.json`: `59d011c47374db5c189f2a57104d4567dde789cacafd1459ed9cd07a5f03d030`
- `data/event_menu_shop_inventory_insert.coverage.json`: `1e91dd65c73cc9b5e0b27a2cce0de065349d16be1b3a588c86b4e36172c434d6`
- `data/event_menu_shop_inventory_insert.source_audit.json`: `6ff854799fba48bed0f0a9c67f90b25e8b357dcbaffb4b86511fdaeb883e9453`

Source acceptance: 46 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_attack_entries_skill_shop_inventory.json`.
