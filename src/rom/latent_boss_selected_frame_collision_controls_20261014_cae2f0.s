; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E2F0
boss_collision_word_cae2f0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae2f2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $151C
boss_collision_word_cae2f4:
    ; collision signed-axis displacement to actorC0/C1
    .word $F404
boss_collision_word_cae2f6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
