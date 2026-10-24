# Native inventory ownership and compaction

C076C7/5 and C076CC/73 convert the selected hero to original ownership bits and scan8 armor or11 other inventory slots. The first wrapper retains the existing removal-control field; the second enables removal. FF holes are skipped, matched ownership bits can be cleared, absent ownership retains the original bounded scan result. C07E12/30 compacts successive physical bytes and writes FF to the vacated tail, preserving the native terminal A=0/M16 result.

Smoke2 and first full8 pass: hero0/1/2 owners, both slot spans, absent owners, ownership removal, first-slot and last-slot compaction. The proof preserves native status/index residues and compares complete memory/CPU/context/peripherals with no hooks. All51/51 starts and widths observed,239 dependencies unchanged; no manifest overlaps for108 bytes. Higher equipment mutation/dispatch remains open.

Integration spec: `event_menu_inventory_ownership_check:EventMenuInventoryOwnership:event-menu-inventory-ownership:event_menu_inventory_ownership`.

## Frozen hashes

- `tools/event_menu_inventory_ownership.py`: `9930a01d8e7ac95c369ae6c8b35f10a04088122483f3125f56d1549461361fab`
- `tools/event_menu_inventory_ownership_check.py`: `230ae8811e8dab4eb6e31c16d8b4abc70eb418e6b2a6bb4ce6c00bb5917c5a8b`
- `data/event_menu_inventory_ownership.json`: `6c32616b8cdc16981e9e4ad8c59060ccf63363ef4f18a4c5f7df70a4d55f76a9`
- `data/event_menu_inventory_ownership.coverage.json`: `3e18c6f9388621fd04855338b7803d9dffb5899cae88f7482636b569ad175cc3`
- `data/event_menu_inventory_ownership.source_audit.json`: `d8b25cd53802569acbb8517032ff7ad3e07268018bf1fc26a3f2bdc7db787f5e`
