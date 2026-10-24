; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F620
boss_collision_word_c7f620:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0909
boss_collision_word_c7f622:
    ; collision signed-axis displacement to actorC8/C9
    .word $F501
boss_collision_word_c7f624:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f626:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
