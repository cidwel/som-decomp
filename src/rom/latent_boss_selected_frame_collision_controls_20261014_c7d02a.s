; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D02A
boss_collision_word_c7d02a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F0F
boss_collision_word_c7d02c:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7d02e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d030:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
