; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E342
boss_collision_word_cae342:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae344:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $141C
boss_collision_word_cae346:
    ; collision signed-axis displacement to actorC0/C1
    .word $F504
boss_collision_word_cae348:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
