; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F4CC
boss_collision_word_c7f4cc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f4ce:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f4d0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
