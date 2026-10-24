; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA2C
boss_collision_word_caca2c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1312
boss_collision_word_caca2e:
    ; collision signed-axis displacement to actorC8/C9
    .word $DD00
boss_collision_word_caca30:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caca32:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
