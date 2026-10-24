; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF08
boss_collision_word_cabf08:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1414
boss_collision_word_cabf0a:
    ; collision signed-axis displacement to actorC8/C9
    .word $E4FD
boss_collision_word_cabf0c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cabf0e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
