; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D352
boss_collision_word_c7d352:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d354:
    ; collision signed-axis displacement to actorC8/C9
    .word $E800
boss_collision_word_c7d356:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d358:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
