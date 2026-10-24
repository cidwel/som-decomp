; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E6C4
boss_collision_word_cae6c4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae6c6:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_cae6c8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae6ca:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
