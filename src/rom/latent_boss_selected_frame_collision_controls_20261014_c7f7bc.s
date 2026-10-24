; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F7BC
boss_collision_word_c7f7bc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f7be:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f7c0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C0C
boss_collision_word_c7f7c2:
    ; collision signed-axis displacement to actorCC/CD
    .word $0000
