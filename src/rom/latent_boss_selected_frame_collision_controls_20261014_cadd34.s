; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DD34
boss_collision_word_cadd34:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadd36:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0B2D
boss_collision_word_cadd38:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_cadd3a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
