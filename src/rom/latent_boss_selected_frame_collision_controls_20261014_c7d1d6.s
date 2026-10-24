; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D1D6
boss_collision_word_c7d1d6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7d1d8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7d1da:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d1dc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
