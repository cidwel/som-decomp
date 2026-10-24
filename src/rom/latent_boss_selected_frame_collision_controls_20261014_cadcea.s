; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DCEA
boss_collision_word_cadcea:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadcec:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0928
boss_collision_word_cadcee:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_cadcf0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
