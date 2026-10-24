# Dialogue line/page completion and control-object publication

`EventDialogueLineCompletion` reconstructs five bodies totaling 315 new instruction bytes: C0126F (79) completes a line and selects the next render phase; C012BE (65) finishes a page, restores a suspended script or enters numeric selection; C00F2C (45) restores the saved dialogue context and cursor; C01322 (26) marks or publishes the control object; C0133C (100) publishes eight native OAM records. Manifest interval searches found no previous sources for these bodies. Existing geometry, cursor and graphics publication models are reused without additional credit.

All message-flag branches remain active. Page completion preserves the native flag masks, state transitions and controller-7 callback. Suspended restoration includes the complete state-2 geometry/cursor reconstruction, saved script word and bank. Control-object publication retains both the existing-object guard and all eight descending OAM slots, the native horizontal offset and packed sprite flags.

The 13-case smoke and first full 5,120-call capture passed unchanged. Line completion has 1,024 calls across all 256 message flags and four contexts; page completion has 2,048 across eight state/controller contexts; suspended restoration has 1,024 across four prior-state/cursor contexts; the control-object dispatcher and complete OAM body each have 512 calls. Incoming D=0, DB=7E, M8/X16, binary. Full WRAM outside observed native stack, CPU/status/S/D/DB, video/arithmetic peripherals and audio acknowledgement state agree. There are no hooks, interrupts or saved ROM/graphics payloads.

Coverage contains 210 PC/M/X states and 116 dependency fingerprints. Stack watermarks are 1EF7, 1EF9, 1EFA, 1EFC and 1EFE. All five bodies pass complete instruction-boundary and immediate-width recovery. The tool, report and capture are immutable for independent assembly.

The C0111A method in this delivery supplies only phases 0–9 and its existing message-pause branch; C0111A is deliberately absent from FUNCTIONS and receives no source credit here. Its phase-10 window completion and all eleven-phase composition are reconstructed separately in the new render-core pipeline and await native proof. General dialogue dispatch, interactive menu and event 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_line_completion.py | 1aed260942f7f680f45116faafa5aaae03ad6e2f2f07a78f93f1635e3afe7ae5 |
| data/event_dialogue_line_completion.json | 3b31938cd3ad4d8cd86e1ea9e18c97f41ed4552414b1436635c974bb96a3e939 |
| data/event_dialogue_line_completion.coverage.json | d4c277ef4a60393eeaf80a95cdd4056c25fc8881bbc9462fb9637e1c992e7eb9 |

Instruction-start audit: the captured5,120 cases cover126/127 starts. C0129B is not observed in this capture; exact source bytes and immediate widths pass independently, while this branch awaits a directed equality context in the next composed proof. No full branch-coverage claim is made.

Supplement: the frozen complete renderer5,120-case capture now observes C0129B(M8/X16) using native phase8 equality contexts. Original primary LineCompletion coverage remains unchanged; this closes its missing-start evidence without any additional byte credit.
