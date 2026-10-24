; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC36
boss_collision_word_c7cc36:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7cc38:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7cc3a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
