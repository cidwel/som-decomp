; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2F6
boss_collision_word_cac2f6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1418
boss_collision_word_cac2f8:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_cac2fa:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac2fc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
