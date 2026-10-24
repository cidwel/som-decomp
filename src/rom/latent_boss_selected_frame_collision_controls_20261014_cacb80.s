; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB80
boss_collision_word_cacb80:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacb82:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacb84:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
