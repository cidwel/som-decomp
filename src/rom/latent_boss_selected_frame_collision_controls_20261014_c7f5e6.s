; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F5E6
boss_collision_word_c7f5e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f5e8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f5ea:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
