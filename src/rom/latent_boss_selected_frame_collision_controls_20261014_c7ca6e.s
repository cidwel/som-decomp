; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA6E
boss_collision_word_c7ca6e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7ca70:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7ca72:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ca74:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
