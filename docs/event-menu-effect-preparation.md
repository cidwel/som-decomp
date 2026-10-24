# Event radial-effect preparation

Four complete dependencies of C2C976 are reconstructed with readable models in `EventMenuEffectPreparation`. They prepare an expanding/contracting HDMA window and the particle overlay used by the special flag-zero increment branch of event opcode 29.

| Entry | Bytes | Behavior |
|---|---:|---|
| C2CB1A | 85 | Configure channel 2 window HDMA, indirect table F018, horizontal origin and camera-relative vertical origin. |
| C2CB6F | 128 | Convert both halves of the original FD22 trigonometric table through the native multiplier into lookup F700; fill zero gaps across its first 208 bytes. |
| C2CD55 | 18 | Hide 20 particle sprites in OAM workspace 0900 with E0FF coordinates. |
| C2CE11 | 16 | Copy the original particle descriptors CE21..CEBF into F640 using the actual overlapping word writes and decrement-by-one loop. |

The 247-byte sum is subject to the integrator's physical source overlap audit. All four bodies pass instruction-boundary and immediate-width reconstruction from the new execution capture.

The first eight-call smoke and first full 512-call comparison passed without model changes. Each entry has 128 generated runtime contexts. The original executes completely without instruction hooks. The comparison includes all WRAM outside the observed return stack, CPU registers and flags, D/DB/stack context, video and arithmetic peripherals. Binary mode, D=0 and DB=7E are explicit. All M/X and C/N/Z/V combinations are covered except the descriptor initializer, whose original caller supplies X16. Every call reached stack 1EFE. Native multiplier ports remain real; the model supplies operand writes and reads their hardware result. No NMI is required in these four helpers.

The report contains 512 original calls, the capture 152 PC/M/X states, and all 40 dependency fingerprints match. The particle update, 512-frame radial animation, graphics setup, HUD restoration and opcode 29 remain open. This preparation proof does not claim their completion.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_effect_preparation.py | 12b4665155b18a69c58b4a1dc1086cd475c2e79ad1c112d0d5d6efc2170bd4f2 |
| data/event_menu_effect_preparation.json | bc26a20efb5c1bc6fc712701a446a0546db772651979ead3c0c899335aee88c8 |
| data/event_menu_effect_preparation.coverage.json | e56c74f2a1c976fe2dacd2e88f6d067f7ad02beabfc0daa1001915f2e5ca9e7b |
