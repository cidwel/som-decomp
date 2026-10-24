# Complete radial transition and real frame sequence

`EventMenuEffectAnimation` reconstructs four complete bodies: C2C9E0 (314 bytes), C2C9D7 (9 bytes), C2C98B (76 bytes) and C2C976 (21 bytes), totaling 420 bytes before physical overlap audit. C2C976 prepares actor-relative window HDMA, loads particle graphics and palette, initializes the particle records, builds the radial curve, and runs the complete expanding and contracting animation.

The single-frame window body divides FF00 by the phase (using divisor 1 for phase zero), samples and interpolates the radial curve through the native arithmetic registers, computes clamped left/right bounds around the actor, and publishes 224 scanline windows. It waits through a real NMI/RTI with EC=0C, updates fixed color and window/color-math registers, then copies the window coordinates into the indirect HDMA table. Its frame wrapper clears the particle OAM slots and runs all twenty actual particle updates. The coordinator executes every phase 0..255 followed by 255..0, then hides the particles and restores the original screen/color settings. The outer transition also includes the graphics setup NMI.

The four-call smoke and first full 322-call capture passed without model changes. The capture includes every phase value in 256 direct frame calls, 64 complete window/particle frame calls, one complete 512-frame animation and one complete 513-NMI outer transition. Four horizontal origins and four valid vertical origins, expansion and contraction guards, both incoming M widths and all C/N/Z/V combinations are covered in the direct-frame domain. Complete coordinators use a controlled actor-relative origin and the actual seven-byte graphics/palette wrapper; X16, D=0, DB=7E and binary mode match their caller contract.

All 1,345 native NMI/RTI events execute the original handler. Frame requests have explicit finite budgets; no EC byte is substituted and no instruction hooks or callback replacements are used. The comparison includes all WRAM outside observed native stack, CPU result/context and all video/arithmetic peripherals. Stack watermarks range from 1EEE to 1EE6. The capture contains 837 PC/M/X states and all 88 dependency fingerprints match. Every immediate width and instruction boundary in all four bodies is captured unambiguously.

Preparation, particle motion, graphics and HUD models remain stable. The final opcode 29 composition is still pending its own original-call proof; this transition proof does not claim the complete event VM.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_effect_animation.py | ac3f6e3e4b6f403504303aaf410a2284eeaf97ba55bd2179a62d220b120637cf |
| data/event_menu_effect_animation.json | 0b5ed2db4694366705a35b8831443cff19d7529128fc90e6998bba3cece5e060 |
| data/event_menu_effect_animation.coverage.json | 57ad0d431e08d497da7dff5b9468c24623c2039fe8baf77c94370e41367fa5b1 |
