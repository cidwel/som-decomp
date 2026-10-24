; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0FE
boss_collision_word_c7d0fe:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d100:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7d102:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0F0C
boss_collision_word_c7d104:
    ; collision signed-axis displacement to actorC0/C1
    .word $CA0C
boss_collision_word_c7d106:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
