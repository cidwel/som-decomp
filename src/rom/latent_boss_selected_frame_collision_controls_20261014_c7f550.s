; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F550
boss_collision_word_c7f550:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0807
boss_collision_word_c7f552:
    ; collision signed-axis displacement to actorC8/C9
    .word $F500
boss_collision_word_c7f554:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f556:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
