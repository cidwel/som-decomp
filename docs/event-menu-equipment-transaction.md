# Native equipment ownership transactions

Eight complete bodies (C07504/27, C0751F/8, C07527/58, C07561/16, C07571/35, C0759E/16, C075AE/54 and C075E4/38) reconstruct retargeting, protected equipment checks, equipping, removal, ownership cleanup and the final stats/row publication. The composition calls the existing real inventory lookup, field access, ownership compaction, stat rebuild, sprite markers, list producers, phase controller and vblank handler. No dependency body is replaced by a hook or an empty guard.

The primary sixteen directed cases cover changed and unchanged selection, protected/reassigned previous equipment, armor and other categories, modal and ordinary sprite contexts, normal/special/protected removal, and both publication modes. Its first full run exposed an invalid standalone fixture width at interior C0759E: that entry is reached with M8 after the producer PLA, whereas the fixture had M16. Only the fixture was corrected, with the exact failing case replayed successfully before the full sixteen-case capture passed. The model and dependencies were unchanged. C0759E therefore retains that produced M8 ABI rather than accepting arbitrary entry widths.

The immutable primary observes 98/99 instruction starts. A separate complete hero-zero publication observes the remaining C075FD INC: the doubled hero index is zero and the original explicitly increments it before storing the hero mask. That one-case supplement passed without repeating the primary. The union observes all 99/99 starts and exact immediate widths, with 1,909 distinct PCs and 1,974 PC/M/X states. All 241 primary and 242 supplemental dependency hashes remain unchanged. Full WRAM, CPU flags and widths, stack/context, render/DMA peripherals, audio and real interrupts match. The primary's stack watermark excludes ordinary discarded call-frame bytes from WRAM comparison while preserving observable caller context and peripheral transfers.

These eight bodies total 252 new instruction source bytes, independently assembled to the original ROM with no physical overlap. The higher equipment exchange, dispatcher, category-two modal branch and full public ring loop remain open; this is not a claim that the whole menu is complete.

Integration spec: `event_menu_equipment_transaction_check:EventMenuEquipmentTransaction:event-menu-equipment-transaction:event_menu_equipment_transaction`. Supplemental checker: `event_menu_equipment_transaction_guard.py`; preserve both independent captures and use `event_menu_equipment_transaction.complete_source_audit.json` for the combined source contract.

## Frozen hashes

- `tools/event_menu_equipment_transaction.py`: `503e01ea8715c3bd8fa2e3f8d34643b54dbdb94e664ac9687ca7349e162fae7b`
- `tools/event_menu_equipment_transaction_check.py`: `70c2f7734bf78162dcbbbf96d75ca5b5fb7d42e1348d422a75cfb49a18393837`
- `tools/event_menu_equipment_transaction_guard.py`: `4a6d4b66b8b80a0018a515fa99fdf0717f086bcfaf899ff65b33e003490f8ab6`
- `data/event_menu_equipment_transaction.json`: `05f1cef6d217aa48281fc32cc47c8eb40077de1e32e4c0e5b73e8e9df36e6ecf`
- `data/event_menu_equipment_transaction.coverage.json`: `6bcbf1bd18c76debd8a4121c137e24395d8c8a9f9d3aa729beaf21f0ca8a634c`
- `data/event_menu_equipment_transaction.source_audit.json`: `4dc22d12a27dcf7e2b0b8bb8be17bd541b93032d9c310bebc06baa934958a0d4`
- `data/event_menu_equipment_transaction_guard.json`: `c9b481472948a82ab5e0407139ead9732bff872cdf37301d1c05dafc773cee98`
- `data/event_menu_equipment_transaction_guard.coverage.json`: `99bd6865ba6c7bf21eebed95a193d10df267e1f52e70ca3f0f737c89ad80ec23`
- `data/event_menu_equipment_transaction.complete_source_audit.json`: `287ee731d17197c5225099602d565d311c25fb3f9835f25b1d84477c655c19a1`
