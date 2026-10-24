; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C56C
boss_collision_word_c7c56c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $130F
boss_collision_word_c7c56e:
    ; collision signed-axis displacement to actorC8/C9
    .word $E600
boss_collision_word_c7c570:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c572:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
