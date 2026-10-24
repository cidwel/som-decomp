; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFCE
boss_collision_word_c7dfce:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1008
boss_collision_word_c7dfd0:
    ; collision signed-axis displacement to actorC8/C9
    .word $E8F8
boss_collision_word_c7dfd2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7dfd4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
