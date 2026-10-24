# Native sold-item inventory mutation

C07DB1/97 reduces consumable quantity, returns immediately when quantity remains, or clears the selection flag and compacts the physical slot list when the last quantity is sold. For equipment, the real owner bits identify the attached hero, its field receives sentinel21 and the existing complete public C00036 stat rebuild executes before compaction. The model preserves saved X/Y around that rebuild. It reuses existing C07E12/30 compaction including C07E2A success tail, without inserting an extra mana cap or a substitute return.

Smoke2 and first full7 passed: retained and last consumable quantities, unowned equipment, owned hero0 and hero1 equipment, the final physical slot, and the existing interior success return. All47/47 new-body instruction starts and widths are observed,569 distinct PCs and404 dependencies unchanged. Complete WRAM/CPU/context, real stat arithmetic and other peripherals match without hooks. Discarded ordinary call frames use the observed stack watermark while caller context remains compared.

New source candidate is97 instruction bytes only. C07E12/30 already contains C07E2A/6, so its extra direct case strengthens the existing contract with zero new byte credit. The shop confirmation, dialogue request and complete buy/sell/service callbacks remain open. Integration spec: `event_menu_shop_inventory_remove_check:EventMenuShopInventoryRemove:event-menu-shop-inventory-remove:event_menu_shop_inventory_remove`.

## Frozen hashes

- `tools/event_menu_shop_inventory_remove.py`: `385cd78f3f952caf258f9cb6483a6544c4c8640f1ec95782ccec62c4b4137cc8`
- `tools/event_menu_shop_inventory_remove_check.py`: `3f94e910e9e617660b9a2e3a76deae860d3f8c5df67d63ebd4d4a96bef0842ab`
- `data/event_menu_shop_inventory_remove.json`: `015397495f2661df5a89e178796dbb21729279ea5f857571621c9199e4e92371`
- `data/event_menu_shop_inventory_remove.coverage.json`: `0ad0a354ff783838991d778e4de60408c5eb67b89dc86cd1e84c010b22e9fb43`
- `data/event_menu_shop_inventory_remove.source_audit.json`: `edd8735c18ed14a9f46b497c6d2a42cfee0d5a6a6ac147e87b6f685863924edc`

Source acceptance: 97 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_attack_entries_skill_shop_inventory.json`.
