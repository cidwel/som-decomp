# Native button mapping and three-player publication

`GameControllerMapping` reconstructs C09434 (66 instruction bytes), applying the three controller mapping bytes to the published words, and C09476 (166), the complete byte permutation routine. The model retains the literal direction/button exchanges, conditional high-bit swaps, memory BIT flags and scratch direct-page fields. Existing controller BIOS and dialogue dependencies are reused without duplicate credit.

The 12-case smoke and first complete 5,120-call capture passed unchanged. The inner permutation has all 256 mapping bytes ×16 high/low button contexts (4,096 calls); publication has all 256 bytes ×four controller-word contexts (1,024). Incoming D includes 0000/0300/0100/1800, DB=00/7E/7F/42 and M8/X8, with binary arithmetic. Full WRAM outside the occupied native stack, CPU/status/S/D/DB, graphics/arithmetic peripherals and audio acknowledgement agree; no hook or interrupt is used.

The capture has 126 PC/M/X states and 118 dependency fingerprints. All 126/126 instruction starts are observed: 32 in publication and 94 in permutation. Both sources pass immediate-width and complete-boundary recovery; stack watermarks are 1EFC/1EFE. Tool, report and coverage are frozen. Polling, controller reassignment/HUD events and hotkey boot transfer remain a separate composed proof.

| Artifact | SHA-256 |
|---|---|
| tools/game_controller_mapping.py | c7e6227e3a9f90d327d7d9d6d2d8757655713c697d333b8c250ba66804f76d03 |
| data/game_controller_mapping.json | dc777ca1cc2e78ebd07c22651a226d290514e5cd1061277591c3d1d55a43f4ba |
| data/game_controller_mapping.coverage.json | 9f59fb9fc2e6f6f6590a14016fb05d9d8879050a89a5f811e30295c64dfde3a6 |
