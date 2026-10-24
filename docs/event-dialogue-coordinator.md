# Complete public native dialogue coordinator

`EventDialogueCoordinator` reconstructs the full public text dispatcher through C00113, C0012C and the C00092 jump alias. Four new instruction bodies total281 bytes, with no physical overlap with any existing matching source. The shared C00165 tail is reached through the genuine public prefixes; it is not exposed as a fabricated standalone subroutine.

The sixteen-entry state table now composes every real state: window construction50, close51, final52, render53..59/5B/5C, numeric choice5A, pauses5D/5E and numeric entry5F. State7D and newly encountered script byte7D execute the complete seven-phase scrolling scene, including the native compressed graphics decoder and successful64-sprite construction. The dispatcher retains ordinary and preempting window geometry, temporary-window restoration, actual script pointers, hold and cleanup guards, incoming-bank reads and status/D/DB restoration. All previously reconstructed dependencies are reused without duplicate byte credit.

The original plan of4,934 executions was reduced before capture to200 directed calls:128 covering both public RTL entries across all sixteen states and four M/X/context combinations;16 through the public jump alias;28 covering both RTL entries and all seven scrolling phases with tick boundaries;20 raw-script/hold/cleanup scenarios;6 actual3030 reset transfers on three controller bindings; and2 directed cleanup cases. Public entries cover D0/0300, DB00/7E, both accumulator and index widths, binary arithmetic. The jump alias is compared at D0/DB7E/M16/X16 through all sixteen states.

Smoke6 passed. The first200-call comparison stopped at trial178: the newly encountered7D script path left1D04=1 in the original but the model cleared it. Original C001B4 calls CC0900 and C001B8 branches directly to C0021F, skipping idle-script cleanup at C001D7. Only the mutable coordinator was corrected; no proven dependency was changed. The failed evidence and original dependency fingerprints remain in `data/event_dialogue_coordinator.failed_trial178.json`. The exact trial178 replay then passed, followed by the corrected complete200-call capture, also passing.

The checker executes every original instruction and callee without hooks. It compares full WRAM outside the actual occupied caller stack and, for real hotkey reset, the separately observed bootstrap stack. CPU/status/S/D/DB, PPU/arithmetic peripherals, audio acknowledgements and controller state agree. Six cases genuinely transfer to boot target7EAF0B; they are not counted as returning calls. No synthetic NMI or IRQ event substitutes for a routine body.

The capture records3,056 PC/M/X states and173 dependency fingerprints. All124/124 starts across the four new bodies were observed; each body passes immediate-width and boundary recovery. Caller stack watermarks are1EB0/1EBA/1EC7/1EDF/1EE8/1EEC/1EED/1EEE/1EEF/1EF0/1EF1/1EF3/1EF5/1EF7. Model, checker, passing report and capture are immutable after delivery.

| Entry | Bytes | Observed starts | Contract |
|---|---:|---:|---|
| C00092 | 3 | 1/1 | Public JMP to C00113, preserving the caller's JSL frame |
| C00113 | 25 | 10/10 | Ordinary dialogue geometry prefix; full shared RTL tail |
| C0012C | 57 | 22/22 | Preempting dialogue geometry prefix; full shared RTL tail |
| C00165 | 196 | 91/91 | Shared tail reached with the prefix's PHP frame; contextual ABI |

Integration spec: `event_dialogue_coordinator_check:event_dialogue_coordinator.EventDialogueCoordinator:event-dialogue-coordinator`. The complete interactive event menus0E/0F/2E, their input loops and the external-vblank menu driver remain separate work; this proof closes the native text coordinator rather than the whole menu engine or event VM.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_coordinator.py | 692037e681c4088872cdc1c012089f0f62df43051f8090fcec6358581cbe3bbe |
| tools/event_dialogue_coordinator_check.py | 2a2cb43403c564aee75f82469b364b7d51a4136ebf82525d5e51573ea3a040ac |
| data/event_dialogue_coordinator.json | 5cff591ff8024eed3fe7d0b40924805bfb873ffb78907ffdafee5679fc857f11 |
| data/event_dialogue_coordinator.coverage.json | 2eef220d2ee834c3c10dbfe755cff2f27a795800de7c21421c4e7d45b3429b98 |
