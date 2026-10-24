; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3A0
boss_collision_word_c7f3a0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B0A
boss_collision_word_c7f3a2:
    ; collision signed-axis displacement to actorC8/C9
    .word $F302
boss_collision_word_c7f3a4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f3a6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
