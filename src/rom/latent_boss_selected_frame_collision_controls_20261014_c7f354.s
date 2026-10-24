; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F354
boss_collision_word_c7f354:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f356:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f358:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
