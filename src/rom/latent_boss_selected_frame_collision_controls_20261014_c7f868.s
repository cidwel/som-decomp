; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F868
boss_collision_word_c7f868:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7f86a:
    ; collision signed-axis displacement to actorC8/C9
    .word $0001
boss_collision_word_c7f86c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7f86e:
    ; collision signed-axis displacement to actorC0/C1
    .word $2000
boss_collision_word_c7f870:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C08
boss_collision_word_c7f872:
    ; collision signed-axis displacement to actorCC/CD
    .word $0419
