; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1C2
boss_collision_word_c7e1c2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e1c4:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7e1c6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e1c8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
