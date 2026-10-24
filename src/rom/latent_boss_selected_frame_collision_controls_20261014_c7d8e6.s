; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D8E6
boss_collision_word_c7d8e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $070B
boss_collision_word_c7d8e8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F103
boss_collision_word_c7d8ea:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d8ec:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1011
boss_collision_word_c7d8ee:
    ; collision signed-axis displacement to actorCC/CD
    .word $D901
