; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F298
boss_collision_word_c7f298:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0707
boss_collision_word_c7f29a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F801
boss_collision_word_c7f29c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_c7f29e:
    ; collision signed-axis displacement to actorC0/C1
    .word $F800
boss_collision_word_c7f2a0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
