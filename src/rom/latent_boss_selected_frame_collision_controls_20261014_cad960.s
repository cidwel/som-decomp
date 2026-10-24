; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D960
boss_collision_word_cad960:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad962:
    ; collision signed-axis displacement to actorC8/C9
    .word $0001
boss_collision_word_cad964:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad966:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
