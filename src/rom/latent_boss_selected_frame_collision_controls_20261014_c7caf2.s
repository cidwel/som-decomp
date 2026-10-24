; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAF2
boss_collision_word_c7caf2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7caf4:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7caf6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0D
boss_collision_word_c7caf8:
    ; collision signed-axis displacement to actorC0/C1
    .word $0DD9
boss_collision_word_c7cafa:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
