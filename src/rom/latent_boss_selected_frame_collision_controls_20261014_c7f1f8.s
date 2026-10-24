; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1F8
boss_collision_word_c7f1f8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0605
boss_collision_word_c7f1fa:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7f1fc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f1fe:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
