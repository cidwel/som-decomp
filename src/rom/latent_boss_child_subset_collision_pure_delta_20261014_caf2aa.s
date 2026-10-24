; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2AA
boss_collision_word_caf2aa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf2ac:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caf2ae:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
