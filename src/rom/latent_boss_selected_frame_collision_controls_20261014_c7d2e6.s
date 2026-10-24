; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2E6
boss_collision_word_c7d2e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d2e8:
    ; collision signed-axis displacement to actorC8/C9
    .word $E800
boss_collision_word_c7d2ea:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d2ec:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
