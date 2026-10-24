; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3BE
boss_collision_word_c7f3be:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A0A
boss_collision_word_c7f3c0:
    ; collision signed-axis displacement to actorC8/C9
    .word $F404
boss_collision_word_c7f3c2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f3c4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
