# Event menu actor selection and sprite palette dependencies

`EventMenuActorSelection` reconstructs nine complete dependency bodies for the still-open opcode 2E/menu chain: C2AB30/C2AB42 shadow-palette restore/snapshot (18 bytes each), C1CB88 sprite priority selection (67), C064A4 native context normalization (15), C0692D menu-loop/input-state request (18), C06696 saved-coordinate/menu-mode initialization (31), C06A5B primary-mode flag selection (24), C06A73 controller-to-party-actor binding (50), and C06AA5 controller/descriptor initialization (57). Total: 298 instruction bytes.

The palette copies retain incoming DB and copy 128 words, including literal ignored writes when the incoming bank maps the shadow destination to ROM. OAM priority selection snapshots the palette, derives flags from word 98 shifted four times, and adjusts bit 0800 in each of 64 OAM records. Native context normalization sets D and DB to zero while preserving the incoming A value and C/V, and returns M16/X16. Menu initialization saves X/Y into 183E/1840, clears mode flags and initializes its loop/input words. Controller binding searches D9 then DA, falls back to the third actor, updates the upper mode bits and stores the selected actor index. Descriptor initialization applies the original signed controller-selection order and reads its table through the actual D8FB80 pointer; no table payload is saved.

The nine-entry smoke and first full 2,176-call capture passed unchanged. There are 128 calls for each shadow copy across DB=00/7E/7F/42/80, 256 OAM priority calls, 128 calls each for context/request/initialization, all 256 primary-mode values, 512 low controller/request combinations and 512 controller/descriptor contexts. Both incoming M/X widths and C/N/Z/V states are covered; normalization includes D=0/0300/1234 and incoming bank variation. The other native menu helpers use D=0, DB=0; OAM priority uses DB=7E. Every call uses binary arithmetic.

Comparison executes the full original instructions with zero hooks or interrupts, checking all WRAM outside observed stack, CPU registers/flags and S/D/DB, video/arithmetic peripherals and audio acknowledgement state. The capture records 193 PC/M/X states and 104 current dependency fingerprints. Stack watermarks are 1EF8, 1EF9, 1EFA, 1EFB, 1EFD and 1EFE. All nine bodies pass complete instruction-boundary and immediate-width recovery. No current function interval overlaps these bodies; independent source assembly and final physical-overlap audit belong to root integration.

The modules' initial header comments predate native validation; this document and the verified report describe the completed evidence. The interactive C06617 menu driver, its vblank/input schedule and opcode 2E remain open. The next coherent dependency block selects and changes the menu's current party actor through C06A41/C06B03/C06B0A/C06ADE/C06986/C069F0. No complete-menu or complete-event-VM credit is claimed.

| Artifact | SHA-256 |
|---|---|
| tools/event_sprite_palette_priority.py | 63464eba9046ef1f9ee279729de3fb8a4b982a04b7241eabaa17aa3ddb30445c |
| tools/event_menu_actor_selection.py | 7fa5f2db8b35b07e0b692d13f1e3ecda22517547585c79361ddadb3c1ac7712c |
| data/event_menu_actor_selection.json | 870529ac9b66f71e143311917cec4794eab614e9159a4082c986e0801f7edd61 |
| data/event_menu_actor_selection.coverage.json | d5b73bcfa2fd17ff6af08f19ffd428678b82fb584f076cb79f33fc17b37ea94e |
