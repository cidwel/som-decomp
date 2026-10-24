; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E156
boss_collision_word_cae156:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae158:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $141A
boss_collision_word_cae15a:
    ; collision signed-axis displacement to actorC0/C1
    .word $F500
boss_collision_word_cae15c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
