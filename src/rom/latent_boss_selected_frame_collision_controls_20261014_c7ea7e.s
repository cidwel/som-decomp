; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA7E
boss_collision_word_c7ea7e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1014
boss_collision_word_c7ea80:
    ; collision signed-axis displacement to actorC8/C9
    .word $F0FC
boss_collision_word_c7ea82:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ea84:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
