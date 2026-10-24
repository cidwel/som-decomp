; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D31C
boss_collision_word_c7d31c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E10
boss_collision_word_c7d31e:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_c7d320:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d322:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
