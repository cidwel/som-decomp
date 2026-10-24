; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BEC6
boss_collision_word_cabec6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1414
boss_collision_word_cabec8:
    ; collision signed-axis displacement to actorC8/C9
    .word $E4FD
boss_collision_word_cabeca:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cabecc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
