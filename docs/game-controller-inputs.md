# Native controller input and Multi5 BIOS

`GameControllerInputs` reconstructs three complete bodies, totaling 298 instruction bytes: CFFE00 (83) reads and publishes the native controller words; CFFE70 (97) probes both serial interfaces; CFFF2A (118) reads Multi5 automatic and serial controller fields. `ControllerInputCPU` supplies explicit external autojoypad words, busy intervals and ordered serial samples through the actual mapped bus. Every original BIOS instruction runs; no hook substitutes a controller routine.

The public CFFE00 entry uses its real long-return ABI, allocates twenty scratch bytes below its own native stack frames, temporarily changes direct page and data bank, and restores the caller's context. The two internal helpers use their real short-return ABI and native DB=00 contract. The model preserves status while retaining the original index truncation caused by entering eight-bit index mode. Multi5 detection, both interface flags, automatic words, serial shifts and port-control writes are modeled literally.

The 16-case smoke and first complete 6,144-call capture passed unchanged. Each of three entries receives 256 bus contexts and eight incoming width/direct-page/interface combinations. Incoming D includes 0000/0300/1800/0100; the public entry also covers DB=00/7E/7F/42. Binary arithmetic is required. The check compares full WRAM outside the observed occupied stack, CPU/status/S/D/DB, graphics/arithmetic peripherals, audio acknowledgement, serial consumption counts and ordered port writes. No interrupt was used in this BIOS-only proof.

Coverage has 185 PC/M/X states and 117 dependency fingerprints. All 152/152 instruction starts are observed (43 public, 51 probe, 58 Multi5 reader); all three bodies pass immediate-width and complete-boundary recovery. Stack watermarks are 1EE2 and 1EFD. Tool, report and coverage are frozen. Mapping, polling, hotkey reset and the full interactive dialogue/menu coordinator receive their own composition proofs.

| Artifact | SHA-256 |
|---|---|
| tools/game_controller_inputs.py | 34986c99a8f84f86bc53da361b0f108dbee03cc0e66f61573d63b533553f2537 |
| data/game_controller_inputs.json | c854b808cb23cd28eedea2dcd170ea610689daebd740b7057becf816e5258999 |
| data/game_controller_inputs.coverage.json | d59a4ed4cdcbd479766388bb538f71c32dffa79d1c49e065302a149c82ba0950 |
