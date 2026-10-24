; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1A8
boss_collision_word_cae1a8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae1aa:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $141C
boss_collision_word_cae1ac:
    ; collision signed-axis displacement to actorC0/C1
    .word $F504
boss_collision_word_cae1ae:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
