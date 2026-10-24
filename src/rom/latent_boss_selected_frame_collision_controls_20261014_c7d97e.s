; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D97E
boss_collision_word_c7d97e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7d980:
    ; collision signed-axis displacement to actorC8/C9
    .word $E904
boss_collision_word_c7d982:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d984:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
