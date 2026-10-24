; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F7E8
boss_collision_word_c7f7e8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7f7ea:
    ; collision signed-axis displacement to actorC8/C9
    .word $0001
boss_collision_word_c7f7ec:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7f7ee:
    ; collision signed-axis displacement to actorC0/C1
    .word $2000
boss_collision_word_c7f7f0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0B07
boss_collision_word_c7f7f2:
    ; collision signed-axis displacement to actorCC/CD
    .word $0519
