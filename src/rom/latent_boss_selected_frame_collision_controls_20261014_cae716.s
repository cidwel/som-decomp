; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E716
boss_collision_word_cae716:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae718:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_cae71a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae71c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
