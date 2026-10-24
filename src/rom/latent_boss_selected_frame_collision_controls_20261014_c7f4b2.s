; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F4B2
boss_collision_word_c7f4b2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B0B
boss_collision_word_c7f4b4:
    ; collision signed-axis displacement to actorC8/C9
    .word $F200
boss_collision_word_c7f4b6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f4b8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
