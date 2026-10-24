; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD9A
boss_collision_word_dbfd9a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbfd9c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_dbfd9e:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_dbfda0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
