; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F4E0
boss_collision_word_c7f4e0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0909
boss_collision_word_c7f4e2:
    ; collision signed-axis displacement to actorC8/C9
    .word $F4FF
boss_collision_word_c7f4e4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f4e6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
