; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F73C
boss_collision_word_c7f73c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7f73e:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f740:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_c7f742:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f744:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
