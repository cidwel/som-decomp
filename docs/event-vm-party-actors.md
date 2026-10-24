# Event actor activation and removal

`EventPartyActors` reconstructs two complete coordinators: opcode 2B at C1ECA0 (97 bytes) and opcode 2C at C1ED01 (52 bytes). Activation selects one of sixteen actor slots, marks it active, copies the two metadata words from the current NPC, clears velocity, copies three byte fields from the event's current actor and reverses its facing field. It marks field 30 as FF and executes the actual program initializer selected by the target slot's E180 byte, including real status continuation and stat rebuilding, then rebuilds the full party HUD. Removal marks the selected actor inactive, clears its pad binding when present, clears the associated controller binding and executes the complete original reassignment logic before rebuilding the HUD.

All dependencies are stable existing models. The new composition supplies the actual controller-HUD NMI context at C0BF47; the older standalone controller model used a fixed temporary stack address in its wait helper. This adapter uses the genuine stack depth and real NMI/RTI handler without altering any stable dependency. Program/controller audio packets use the original bounded external APU acknowledgement contract and ordered writes. No original instructions are bypassed.

The representative six-call smoke and first full 4,832-call capture passed without model changes. The capture contains 4,096 activation calls covering all sixteen target slots and all 256 program bytes, 640 removal calls covering pad bindings 0..4 and eight contexts per slot/binding, and 96 calls through the actual event dispatcher. HUD enabled/disabled, current hero and NPC source variation, status masks, appearance classes, C/N/Z/V states and the real program/status/stat paths are included. The event-handler ABI is M8/X8, D=0, DB=7E and binary mode.

Every call performs the complete two-NMI HUD restoration; enabled controller rebinding adds one genuine controller-HUD frame. The capture totals 9,936 native NMI/RTI events. Comparison covers full WRAM outside observed stack, CPU registers/flags and stack/D/DB context, all video/arithmetic peripherals and ordered APU writes/acknowledgement state. Stack watermarks are 1EE0, 1EE9 and 1EEC. The capture contains 1,338 PC/M/X states; all 100 dependency fingerprints match. Both bodies pass complete instruction-boundary and immediate-width recovery for 149 bytes, subject to physical overlap audit. Existing program, controller and HUD sources receive no duplicate credit. Other event families and the complete VM remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_vm_party_actors.py | c9f6bdfff3913f48320e458bdc4c5e6d9bf827c0b5dac5f170b8581364abd22f |
| data/event_vm_party_actors.json | 208fb71b22a6719714fa52a2e53dd1cb548e2cf265b45ecdc418a467e9aa1737 |
| data/event_vm_party_actors.coverage.json | 35be452c69488821429639f6ba5eab7345591167cb95f6467bcc9129efd9d82d |

Root integration: all declared instruction sources and typed numeric sources are now independently assembled and byte-exact in the joint2361-block/398-component build. Reused dependencies receive no duplicate byte credit.
