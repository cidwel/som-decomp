; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDB4
boss_collision_word_dbfdb4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbfdb6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_dbfdb8:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_dbfdba:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
