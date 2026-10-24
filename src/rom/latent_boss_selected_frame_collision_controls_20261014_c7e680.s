; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E680
boss_collision_word_c7e680:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e682:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e684:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
