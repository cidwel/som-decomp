# Native menu inventory availability

The complete45-byte routine D9FC90..D9FCBC selects an inventory scan from1847. Mode0 scans36 entries from7ECC24, mode2 scans48, and other modes return available immediately. Values belowFE indicate a selectable entry; FE/FF are sentinels. The result is low accumulator1 when an entry exists and0 when the selected range is exhausted.

`MenuInventoryGate` was already readable but had no successful standalone capture or catalogue source. The new proof preserves that existing model and checker, counts their genuine native calls without changing instructions, and captures40 complete comparisons. These execute5,052 original instructions. All21 own instruction starts and unique immediate widths are observed; independent assembly matches all45 ROM bytes.

The directed API cases cover modes0/2, first/last selectable entries, exhausted ranges, modes1/3/80/FF, selectable0/1/FD/7F, FE/FF sentinels, incoming M/X widths, D0/300 and DB00/7E in binary arithmetic. Full WRAM outside observed call-stack scratch, registers and S/D/DB match. The body performs no writes except the caller's stack frames and does not access SRAM or peripheral ports. This standalone gate does not establish complete menu scheduling or arbitrary corrupt inventory state.

The frozen report and coverage are `data/event_menu_inventory_gate.json` and its `.coverage.json`; the independent own-source audit is `data/event_menu_inventory_gate.source_audit.json`.
