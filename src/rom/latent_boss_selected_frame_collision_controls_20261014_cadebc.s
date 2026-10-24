; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEBC
boss_collision_word_cadebc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadebe:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1031
boss_collision_word_cadec0:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_cadec2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
