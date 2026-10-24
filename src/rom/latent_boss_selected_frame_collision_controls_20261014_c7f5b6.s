; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F5B6
boss_collision_word_c7f5b6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0908
boss_collision_word_c7f5b8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f5ba:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f5bc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
