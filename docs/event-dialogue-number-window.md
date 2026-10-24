# Complete temporary numeric dialogue window

`EventDialogueNumberWindow` reconstructs six complete entries, 453 new instruction bytes: C754DB decimal quantity conversion (100), C019C7 script digit formatting and suffix (69), C01999 numeric-script construction (46), C00D8B window geometry (113), C0193F cursor/render-state initialization (90), and the complete state-5F C00F87 numeric-window coordinator (35). Manifest interval and existing model searches found no previous source for these bodies. The shared render-origin helper C0197C is inside the 90-byte cursor body and receives no additional credit.

The converter follows all 24 native shift/add iterations with four packed decimal bytes under SED, restores CLD, and exports the original seven digit fields. Inputs above seven decimal digits retain the native first packed-byte behavior. Formatting preserves leading blank glyphs and appends the original terminated ROM suffix. Script construction reads the complete four-byte quantity field, installs its WRAM script pointer/bank and preserves literal upper accumulator effects. Geometry uses the original state-indexed ROM tables and both primary/secondary window modes. State 5F composes cursor snapshot, script construction, geometry and render initialization, requests state 53 and preserves the native message flags.

The twelve-case smoke and first complete 5,888-call capture passed unchanged. Quantity conversion, digit formatting, script construction and full state 5F have 1,024 calls each, spanning input states 0/1/2/FF, decimal boundaries from zero through FFFFFF and randomized 24-bit quantities. Geometry has 768 calls across states 0/1/2 and both window selectors; render initialization has 1,024 calls across all 256 controller selector bytes and four states. Native ABI is D=0, DB=7E, M8/X16, binary on entry; the converter executes SED/CLD literally. Full WRAM outside observed stack, CPU/status/S/D/DB, decimal mode, video/arithmetic peripherals and APU acknowledgement state agree. There are no hooks or interrupts and no saved ROM/text payload.

The capture contains 220 PC/M/X states and 109 dependency fingerprints. Stack watermarks are 1EF8, 1EFA, 1EFC, 1EFD and 1EFE. All six complete bodies pass instruction-boundary and immediate-width recovery. Tool, report and capture are immutable for independent assembly. The general dialogue coordinator, font renderer, interactive menu and opcode 2E remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_number_window.py | de8268769ea46811a2dc8021310601bc46e64b02eb82ab691eee20afbe63980d |
| data/event_dialogue_number_window.json | 2c51e42efe0c1addb25cb5df50d876c30744c0183d5cae587a1f45c56b95b3dd |
| data/event_dialogue_number_window.coverage.json | f23e1c973edbd0300da833a690d23720f0bd6798e613571bd26d1b628704e442 |
