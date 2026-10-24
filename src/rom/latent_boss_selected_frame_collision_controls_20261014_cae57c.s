; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E57C
boss_collision_word_cae57c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae57e:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_cae580:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae582:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
