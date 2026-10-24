; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1BC
boss_collision_word_cac1bc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac1be:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac1c0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
