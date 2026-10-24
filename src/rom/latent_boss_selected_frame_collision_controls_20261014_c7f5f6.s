; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F5F6
boss_collision_word_c7f5f6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f5f8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f5fa:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
