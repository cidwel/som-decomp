; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EACC
boss_collision_word_c7eacc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1014
boss_collision_word_c7eace:
    ; collision signed-axis displacement to actorC8/C9
    .word $F1FC
boss_collision_word_c7ead0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ead2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
