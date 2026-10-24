; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCB4
boss_collision_word_caccb4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caccb6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caccb8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
