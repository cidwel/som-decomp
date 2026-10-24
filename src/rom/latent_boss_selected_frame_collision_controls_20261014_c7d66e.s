; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D66E
boss_collision_word_c7d66e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d670:
    ; collision signed-axis displacement to actorC8/C9
    .word $E800
boss_collision_word_c7d672:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d674:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
