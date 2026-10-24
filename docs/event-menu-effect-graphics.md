# Radial transition graphics and palette publication

`EventMenuEffectGraphics` reconstructs three complete entries: C1864D (7 bytes), C2CD70 (161 bytes) and C2CD67 (9 bytes). The public RTL wrapper composes the existing secondary graphics converter and actor palette loader. The radial-effect graphics body selects actor 0200 and palette command 83, performs that real graphics/palette conversion, copies five palette words from 078C to BF8C, waits through the original NMI/RTI handler, and uploads all tiles and blank padding through native DMA channels 6 and 7. The outer initializer then copies the original particle descriptors through the stable CE11 preparation model.

The representative smoke covered all three entries and passed without semantic changes. The first full 192-call capture also passed: 64 contexts per entry, both M widths, X16 as supplied by the original callers, all C/N/Z/V combinations, three standalone actor slots and four graphics styles. D=0, DB=7E and binary mode are explicit. The graphics bodies each consume one explicitly supplied native NMI; the standalone public wrapper consumes none. All 128 NMI/RTI events and every native DMA transfer execute completely without instruction hooks.

Comparison covers all WRAM outside each observed stack, complete CPU registers/flags and D/DB/stack context, and all PPU/arithmetic peripheral state. Observed stack watermarks are 1EF5 for the standalone wrapper, 1EEE for the graphics body and 1EEC for its initializer. All 86 dependency fingerprints match and all 177 instruction bytes pass boundary and immediate-width recovery. New-byte credit remains subject to the integrator's physical overlap audit. The radial animation coordinator and full opcode 29 remain pending separate comparisons.

| Artifact | SHA-256 |
|---|---|
| tools/event_menu_effect_graphics.py | 5060349660e5173c0ffec157bd72e213cd1c5e0cbc6111f9c0c75d6751b1c5e2 |
| data/event_menu_effect_graphics.json | df1e15e0c771bef7e214e1a2f700fdb4f5020ec7d0fc324b2017db3e47e521be |
| data/event_menu_effect_graphics.coverage.json | 3d41933a0361f1b6f609777c52164e2b93fef9c6170416cfcd598ed194e01657 |
