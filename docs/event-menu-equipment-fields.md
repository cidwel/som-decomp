# Native equipment field access

C079F9/9 tests the protected-item bit through the existing ROM usability reader C07A02. C07A54/41 reads an actor equipment field while preserving status and restoring the original index. C07A7D/56 writes that field. The weapon slot's F1+ palette alias selects the companion field; ordinary weapon writes update both original fields, while the alias writes only the companion field. Armor accesses the ordinary field.

Smoke2 and first full8 pass: protected/unprotected actual ROM item records, armor/ordinary weapon/palette-alias reads and all three write routes. Full WRAM/CPU/context and peripherals match original execution without hooks. All51/51 instruction starts and widths are audited;75 distinct PC addresses captured,236 frozen dependencies unchanged. Existing C07A02 receives no duplicate credit; the106 bytes of these three bodies had no manifest overlap.

The ownership-mutation and full equipment-menu dispatch remain open. Integration spec: `event_menu_equipment_fields_check:EventMenuEquipmentFields:event-menu-equipment-fields:event_menu_equipment_fields`.

## Frozen hashes

- `tools/event_menu_equipment_fields.py`: `a734b8ceb5246c122af27fe3cf01b3a262b61a6df62b6d9a6f82c911841673c1`
- `tools/event_menu_equipment_fields_check.py`: `0804d98b48b70efae4be32de8cca0f7589b71b2d4de09c28d4619a5a65e2e0da`
- `data/event_menu_equipment_fields.json`: `1b6d7cb375bb901f58d5a05fb3a3ec7cfba40e9aabd70f2b9d667ee890ceb88f`
- `data/event_menu_equipment_fields.coverage.json`: `0c401f5f04b5286fc737121e9c3d77921fd59468073fed4735f0d27be83425d9`
- `data/event_menu_equipment_fields.source_audit.json`: `299617970945bdf7fa15c5c831583fda7e7edd11c280de5ba1e6b17e15565b09`
