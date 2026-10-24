; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4D2
boss_collision_word_cac4d2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac4d4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac4d6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1418
boss_collision_word_cac4d8:
    ; collision signed-axis displacement to actorCC/CD
    .word $E400
