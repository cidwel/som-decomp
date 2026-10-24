; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3E6
boss_collision_word_cae3e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae3e8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $141C
boss_collision_word_cae3ea:
    ; collision signed-axis displacement to actorC0/C1
    .word $F504
boss_collision_word_cae3ec:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
