; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F4F6
boss_collision_word_c7f4f6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0909
boss_collision_word_c7f4f8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F501
boss_collision_word_c7f4fa:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f4fc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
