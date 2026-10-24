; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E88E
boss_collision_word_c7e88e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e890:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e892:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
