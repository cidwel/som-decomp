; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFF6
boss_collision_word_caeff6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caeff8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caeffa:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
