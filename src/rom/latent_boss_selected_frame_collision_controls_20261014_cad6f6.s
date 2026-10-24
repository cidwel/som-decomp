; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6F6
boss_collision_word_cad6f6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad6f8:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad6fa:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad6fc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
