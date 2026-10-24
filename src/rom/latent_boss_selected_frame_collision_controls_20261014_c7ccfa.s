; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCFA
boss_collision_word_c7ccfa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7ccfc:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7ccfe:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0B3E
boss_collision_word_c7cd00:
    ; collision signed-axis displacement to actorC0/C1
    .word $F200
boss_collision_word_c7cd02:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
