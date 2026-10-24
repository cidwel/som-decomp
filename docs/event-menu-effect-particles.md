# Radial transition particle motion and OAM

`EventMenuEffectParticles` reconstructs C2CBEF (24 bytes) and C2CC07 (334 bytes), the complete particle driver and single-particle update used by C2C976. The driver updates twenty eight-byte records in F640 and publishes visible sprites to OAM workspace 0900. Each record advances its phase, rotates its angular parameter when the phase wraps, selects the original FD22 trigonometric values and computes both coordinates through the actual multiplier ports. Expansion and contraction alter particle lifetime and direction. Both coordinate rejection branches return without publishing a sprite; accepted coordinates publish the complete position and tile/attribute words and advance the OAM cursor by four bytes.

The first smoke of eight calls and the first full capture of 640 calls passed without model changes. The driver was compared in 128 runtime contexts and the single-particle body in 512. The domain includes expansion and contraction, the phase divisibility guard, all four angular quadrants, all twenty particle slots and coordinate clipping and publication. All C/N/Z/V combinations and both M widths are covered; the driver supports both index widths, while the original single-particle caller requires X16 and Y equal to eight times a slot index. D=0, DB=7E and binary mode are explicit.

Each original body executes completely without instruction hooks. The comparison covers full WRAM outside the observed return stack, complete CPU flags/registers and stack/D/DB context, and all video and arithmetic peripherals. Native multiplier writes and result reads remain real. No NMI is needed in this block. Observed stack watermarks are 1EFC for the driver and 1EFE for direct single-particle calls.

The capture has 175 PC/M/X states and all 41 dependency fingerprints match. Both bodies pass instruction-boundary and immediate-width reconstruction, totaling 358 bytes before the integrator's physical overlap audit. The 512-frame window animation, graphics upload, HUD restoration and full opcode 29 remain separate pending work. The stable 247-byte preparation module is reused unchanged.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_effect_particles.py | 4b618dd890736100280036645001a5b993f680e58c703e174bdc05131a810ea5 |
| data/event_menu_effect_particles.json | f0513fc6239a4c3bdc7d7f82bb19ca810d9224f7ccc2fbf0c7321a0779eccbb1 |
| data/event_menu_effect_particles.coverage.json | fb6c79b3237832ac1c92af6c4782daafcc7cc769ddeacfd345900953da23f5b3 |
