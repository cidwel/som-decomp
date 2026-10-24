; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F510
boss_collision_word_c7f510:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0908
boss_collision_word_c7f512:
    ; collision signed-axis displacement to actorC8/C9
    .word $F500
boss_collision_word_c7f514:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f516:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
