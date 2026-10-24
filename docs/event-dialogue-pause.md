# Dialogue cursor suspension and window pause requests

`EventDialoguePause` closes six complete entries covering 160 instruction bytes. New sources total 107 bytes: C00FE1 temporary closure/workspace composition (25), C00F08 cursor snapshot (36), C00F59 secondary pause (19), C00F6C primary pause (17) and C00F7D shared suspension (10). C01063's 53-byte workspace source already exists; its new CPU adapter reuses `map_transition_cleanup.menu` and receives zero duplicate credit. The previously verified dialogue closure adapter and its source are reused unchanged.

Cursor snapshot leaves an already suspended state 2 untouched; otherwise it records the incremented 16-bit script pointer, script bank and previous state. Primary pause sets state 50 and opens/suspends only when flag A187.0 is clear; secondary pause sets state 51 and either requests A15E=4 or saves/suspends the current message. Temporary closure executes the full existing close/reset chain and clears the complete message workspace. Incoming pointer overflow wraps the word without incrementing its bank, matching the original.

The nine-case smoke and first complete 3,648-call capture passed unchanged. Cursor cases cover four state values 0/1/2/FF and 256 pointer contexts including 0/1/7FFF/8000/FFFF (1,024 calls). Both pause prefixes cover every A187 byte and all four states (2,048), shared suspension adds 64 contexts, and temporary closure/direct workspace add 512 calls across D=0/300/1234 and DB=00/7E/7F/42. Native ABI is M8 with both index widths; cursor/pause use D=0/DB=7E. All status flags and binary contexts vary. Comparison checks full WRAM outside observed stack, all CPU registers/flags and S/D/DB, video/arithmetic peripherals and APU acknowledgement state. No hooks or interrupts occur.

The capture contains 158 PC/M/X states and 108 dependency fingerprints, with stack watermarks 1EF1, 1EF4, 1EFC and 1EFE. All six complete bodies pass instruction-boundary and immediate-width recovery. Tools, report and capture are immutable for integration. The full dialogue coordinator, renderer, vblank/input schedule, interactive menu and event opcode 2E remain open. State 5F's complete decimal-message construction and geometry/reset dependencies are the next coherent frontier.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_pause.py | 2d7abe580e5e95ec4b1b1113ab1b956e0f6466bef6049399cc0dabe54efaa104 |
| tools/event_dialogue_workspace.py | 5362209534f8dca53645e67d2311da54fb9f365fd65257b6c0d7cbfa00f41c8a |
| data/event_dialogue_pause.json | b225178ef2913575b48ea6b1f1adca17741de09454afac1e79d6468959c0063a |
| data/event_dialogue_pause.coverage.json | a41f3a2dc38d11031629bee5b35d4fb5a61fdf40366d193e520e1c0fa5ef2489 |
