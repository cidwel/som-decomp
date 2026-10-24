; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E7BA
boss_collision_word_cae7ba:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae7bc:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_cae7be:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae7c0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
