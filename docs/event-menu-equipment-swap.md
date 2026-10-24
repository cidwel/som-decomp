# Native two-hero equipment exchange

Five complete bodies C07715/37, C0773A/173, C077E7/55, C0781E/72 and C07866/24 reconstruct the owned-row search, complete exchange of two actors' fields, physical inventory ownership rewriting, item eligibility and sentinel handling, real sprite/stat rebuild and final publication. Existing field, selection, ownership, stats, list and vblank implementations compose the native calls.

Smoke2 and the first primary13 passed unchanged: positive armor/other exchanges, changed selection and absent owner, both mode2 busy guards, completed mode2 publication, cleared physical owner bits, invalid-field sentinel, accepted armor and rejected other equipment, and owner-to-actor resolution. The produced owner metadata is nonzero and derives from real inventory and descriptor/geometry producers. The resolver does not claim that owner-zero rows are valid actors.

The primary observes170/171 instruction starts. A separate inverse hero1→hero0 complete exchange observes C077DA INC for the second hero-zero mask; its first one-case capture passed. Union is171/171, 1,875 distinct PCs and 1,905 PC/M/X states. All captured dependency hashes remain unchanged. WRAM, full CPU/status/context, real stat arithmetic peripherals, render transfers and vblank/RTI match without hooks. Discarded ordinary stack frames are excluded by the observed watermark while observable caller context and transfers remain compared.

Candidate new source totals361 instruction bytes, with no physical manifest overlap at preparation. The dispatch vector and outer menu are not included in this credit. Integration spec: `event_menu_equipment_swap_check:EventMenuEquipmentSwap:event-menu-equipment-swap:event_menu_equipment_swap`; add the independent `event_menu_equipment_swap_guard.py` capture and combined source audit.

## Frozen hashes

- `tools/event_menu_equipment_swap.py`: `f40fb0e02af415831ec0ec927db7543e504228e5d80b81922d88244b8743dd26`
- `tools/event_menu_equipment_swap_check.py`: `01c75a6d2c76cc8c9c8df5600a11790070fb70c3a799e6bd2620e462bf88bce0`
- `tools/event_menu_equipment_swap_guard.py`: `fe0ac92b9d7bb6841114a2465c17201fb6719236c42843c5c482c19f1366a4fd`
- `data/event_menu_equipment_swap.json`: `69e16fd916e0148be135bc6fcf74251ce29cd00215319df2fff3b7189110034c`
- `data/event_menu_equipment_swap.coverage.json`: `08e402dac0bac71be9fbc9980ab353fb0ffa86c0e0555430b72f5ba6283766ce`
- `data/event_menu_equipment_swap.source_audit.json`: `52f18c8f7436a0cc12951454406f1ab56f8e8e8f6d829949f065c7f5871f83ec`
- `data/event_menu_equipment_swap_guard.json`: `59230a02bf0bd4e311044f74d31c047e603f11768079273c7cf2174e0e1aa6df`
- `data/event_menu_equipment_swap_guard.coverage.json`: `2da5a831d51f05f497ab1633dcc5c95e50567f22fc9bbf0c2816516684548a30`
- `data/event_menu_equipment_swap.complete_source_audit.json`: `a88b2b7bd6298f1c62dc5d3f67ed188e6e39d19313490f775ecf54dadd597078`

Source acceptance: all 361 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_actor_targets_equipment_ring_name.json`.
