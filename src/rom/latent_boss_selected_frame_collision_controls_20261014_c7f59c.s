; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F59C
boss_collision_word_c7f59c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0807
boss_collision_word_c7f59e:
    ; collision signed-axis displacement to actorC8/C9
    .word $F600
boss_collision_word_c7f5a0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f5a2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
