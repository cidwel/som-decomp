# Event palette and brightness transition

`EventPaletteTransition` reconstructs opcode 2D at C1ED35 (157 bytes), the bank-aware palette snapshot at C2C806 (26 bytes), and the complete RGB offset and phase updater at C2C820 (342 bytes). The handler controls brightness requests, window flags, palette fade modes, target RGB offsets, transition reversal and an asynchronous scene request. All 256 parameter bytes have literal behavior, including the sixteen 80..8F palette modes, reserved no-op parameters and the different two-byte/four-byte cursor increments. Requests that yield return without dispatch; ordinary commands resume the actual event dispatcher.

The snapshot reads and writes through the incoming DB, copies all 256 source colors and mirrors palette color zero into color sixteen. The updater temporarily selects DB=7E, transforms either the first 128 colors or all 256, clamps the three RGB components independently on addition/subtraction, preserves the first fifteen non-background colors, and copies transformed color sixteen into cache color zero. The target sign selects color subtraction, while mode bit 80 independently selects phase reduction. Phase arithmetic preserves the original byte/word operations, including encoded unusual inputs and the extra zero-phase tick before clearing mode. DB and the original final register/flag contracts are restored exactly.

The eight-call smoke passed. The first full attempt reached an invalid generated continuation after a reserved command: its random color bytes were interpreted as another opcode. The fixture was corrected to supply a zero continuation for parameters that do not consume a color operand. The completed 2,526-call capture then passed: 128 snapshots; 862 RGB updates; all 256 handler parameters with five prior modes (1,280 calls); and all 256 parameters through the actual dispatcher. RGB source palettes cover all 32,768 RGB colors for each palette length and each add/subtract direction, with every channel offset 0..31 and fade-in/fade-out, zero/equal/different targets. Snapshot cases include DB=00/7E/7F/42/80; updater cases restore four DB values. Both incoming M/X widths and C/N/Z/V states are covered for the primitives; the event ABI is M8/X8, D=0, DB=7E and binary arithmetic.

Direct handler cursor-wrap fixtures use the genuine E2 pause guard after completing the command. Dispatcher fixtures use normal 4000 cursors and real continuation. Native comparisons execute the complete original bodies with no hooks or interrupts and compare all WRAM outside the observed stack, CPU registers and flags, S/D/DB, video/arithmetic peripherals and APU acknowledgement state. Stack watermarks are 1EFA, 1EFD and 1EFE. The capture records 313 PC/M/X states; all 101 dependency fingerprints match. All three declared bodies pass complete instruction-boundary and immediate-width recovery for 525 bytes; current function intervals show no overlap, subject to root's independent physical source audit and assembly.

This closes the command and its RGB consumer. The complete asynchronous scene driver that later consumes E2 bit 8 remains open; this does not claim a complete event VM or a whole scene transition.

| Artifact | SHA-256 |
|---|---|
| tools/event_vm_palette_transition.py | f9a51974703c90e45f9f8b4576398ecb7b57c2164bc372a4fade3f4a2b4dc969 |
| data/event_vm_palette_transition.json | 92736ed092a0f09e1439fc0427005372c25054edf5e836a1fce02672ee47f1bf |
| data/event_vm_palette_transition.coverage.json | 4379a513981915aa08cdbee8601a319ef70fca82b9a39f858c86ae1c7f64107a |

Root integration: every declared instruction interval and typed selector source now independently assembles byte-exactly in the2390-block/404-component joint build. Existing dependencies are reused without duplicate byte credit.
