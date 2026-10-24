; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D47C
boss_collision_word_c7d47c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d47e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0915
boss_collision_word_c7d480:
    ; collision signed-axis displacement to actorC0/C1
    .word $0001
boss_collision_word_c7d482:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1506
boss_collision_word_c7d484:
    ; collision signed-axis displacement to actorCC/CD
    .word $F6F2
