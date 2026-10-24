; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F6D2
boss_collision_word_c7f6d2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0909
boss_collision_word_c7f6d4:
    ; collision signed-axis displacement to actorC8/C9
    .word $F500
boss_collision_word_c7f6d6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f6d8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
