; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E394
boss_collision_word_cae394:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae396:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $141C
boss_collision_word_cae398:
    ; collision signed-axis displacement to actorC0/C1
    .word $F404
boss_collision_word_cae39a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
