; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFA2
boss_collision_word_c7cfa2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1110
boss_collision_word_c7cfa4:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7cfa6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7cfa8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
