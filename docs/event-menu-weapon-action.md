# Native weapon and spell menu consumer

C072B3/108 reconstructs the complete menu action: persists the selected row, reads the equipment description, tests actor state and MP, builds and selects original targets, then writes the cast record and calls public C0001B. That public routine validates MP/level and publishes the message request; this caller does not itself execute the later actor scheduler.

Smoke2 and the first full6 capture pass: success, cancel, state rejection, MP rejection, no eligible targets, and a native MP rejection after the earlier unsigned eligibility check accepts255. The fixture composes the proven active-window/transfer producer; actual NMI/RTI, audio acknowledgements, rendering, joypad polling and cast preparation all execute without hooks. Complete WRAM, CPU/context and peripheral states match.

Audit39/39 original instruction starts, exact boundaries and immediate widths,2552 distinct PC addresses captured,233 dependencies unchanged. Physical manifest inspection found no existing overlapping source block for C072B3/108. Consumable consumer primary13 also passes, but its separate interior-entry fallback awaits a directed supplement. The full interactive menu remains open.

Integration spec: `event_menu_weapon_action_check:EventMenuWeaponAction:event-menu-weapon-action:event_menu_weapon_action`.

## Frozen hashes

- `tools/event_menu_weapon_action.py`: `fda51d4b7993a9bfc066ea69f85bae6eb64613a66ec5dd6f08053688399b33c0`
- `tools/event_menu_weapon_action_check.py`: `1ded4a421b10f8ea0c322dd8064e1469d5ce35d65edcd2826b12b000b5259a84`
- `data/event_menu_weapon_action.json`: `b3c445baed6ebbe9c074fd571d1289e6c7aecf4a39748055792803262869c518`
- `data/event_menu_weapon_action.coverage.json`: `b3a950964d63d2d85e7b6bffc030f579cbb0846079909d74183919fa3b35136f`
- `data/event_menu_weapon_action.source_audit.json`: `6e5c533a7544b70f547f4941a39bbbe525f98d3f804affd2f1a143899026240d`
