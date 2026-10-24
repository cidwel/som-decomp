; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5C2
boss_collision_word_cac5c2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_cac5c4:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF9
boss_collision_word_cac5c6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac5c8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
