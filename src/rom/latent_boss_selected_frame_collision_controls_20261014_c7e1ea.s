; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1EA
boss_collision_word_c7e1ea:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e1ec:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7e1ee:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e1f0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
