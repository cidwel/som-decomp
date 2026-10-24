; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF8C
boss_collision_word_cabf8c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1414
boss_collision_word_cabf8e:
    ; collision signed-axis displacement to actorC8/C9
    .word $E4FD
boss_collision_word_cabf90:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cabf92:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
