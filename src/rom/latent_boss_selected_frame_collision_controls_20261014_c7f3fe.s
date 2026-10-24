; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3FE
boss_collision_word_c7f3fe:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A09
boss_collision_word_c7f400:
    ; collision signed-axis displacement to actorC8/C9
    .word $F404
boss_collision_word_c7f402:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f404:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
