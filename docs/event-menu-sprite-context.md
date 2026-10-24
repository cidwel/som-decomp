# Event menu sprite staging and restoration

`EventMenuSpriteContext` reconstructs C1F3EA (9 bytes) and C1F3F3 (16 bytes), 25 new instruction bytes. The staging wrapper saves the full X/Y actor context, executes the complete original sprite workspace/frame/emission chain through C0E328, copies palettes and adjusts all 64 OAM priority records through C1CB88, then restores both saved indices. Restoration executes C0E351 and the existing menu palette shadow restoration at C2AB30. All dependencies are reused without duplicate source credit. The interactive menu and event opcode 2E remain open.

Four selected smoke cases passed after adding a missing `store` import to the harness. The first complete capture passed 512 calls unchanged: 256 staging and 256 restoration contexts, all 256 priority-selector high bytes, 16 actor indices, arbitrary full saved Y, ordinary and boss actors, active/inactive/negative records, varied geometry/group coordinates, and HUD enabled/disabled. Original execution contains no hooks or interrupts. Incoming ABI is D=0, DB=7E, X16, both accumulator widths, binary arithmetic. Comparisons check full WRAM outside the observed stack, CPU registers/flags and S/D/DB, video/arithmetic peripherals and APU acknowledgement state.

The capture contains 1,695 PC/M/X states and 148 dependency fingerprints. Stack watermarks are 1ED9, 1EDA, 1EDB, 1EDD, 1EDE, 1EE9, 1EF4 and 1EF5. Both complete bodies pass instruction-boundary and immediate-width recovery. Tool, report and capture are immutable for root's physical-overlap audit and independent assembly.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_sprite_context.py | f480e80b21abe0299a1d6dd17e108749daf98a05b2db283c065a4c38e409147c |
| data/event_menu_sprite_context.json | 93df7bf0e1be7d1f91b1a9de20cba6460c0c9d7fba985a7b4d71293c21c44dff |
| data/event_menu_sprite_context.coverage.json | f956a2d23842b5ec598736a01c10c5dba5cf4c128bc9d91562a3b8ccf1b7652f |
