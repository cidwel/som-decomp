# Native menu casting target record

C0731F reconstructs141 bytes that publish the selected spell/weapon, resource amount, target count and target IDs into the actor casting record. Individual selections encode heroes1..3 or enemies4..6; multi-target selections retain only available actors and compact their IDs without changing order.

Smoke2 and the first directed9-call capture pass without model changes. Three individual hero targets, one individual enemy, full hero/enemy lists, missing first/middle actors and an empty publication list match full original execution. The audit observes60/60 starts, exact widths and boundaries;225 dependency hashes remain unchanged. Full WRAM/CPU/context/peripherals match without hooks or saved payloads. This producer does not claim completion of the following spell execution or the category menu coordinator.

Integration spec: `event_menu_cast_targets_check:EventMenuCastTargets:event-menu-cast-targets:event_menu_cast_targets`.

## Frozen hashes

- `tools/event_menu_cast_targets.py`: `bd2d38062c2b8fdfee77606948ceaff07c58d91e80ca3fd5d265d3b4b9bb23da`
- `tools/event_menu_cast_targets_check.py`: `cba134c5dcb6d802c4d3fd2b987f0151c27f6fea2ad4f017b50d96fb734dae30`
- `data/event_menu_cast_targets.json`: `625dde4db3571fb8c306933d3f9e83a23fc27e99e1f2a60b2b9b9a75f389a222`
- `data/event_menu_cast_targets.coverage.json`: `f651efc48b4a2c6ae32e9e6b9e48ec07061833f84a72332741ac1effcccf51a5`
- `data/event_menu_cast_targets.source_audit.json`: `aac8de072d20a31cfbf4a8bdba0d4a214efe75ff364a6092d725f76af626e4d1`
