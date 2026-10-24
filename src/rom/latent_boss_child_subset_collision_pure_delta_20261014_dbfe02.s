; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE02
boss_collision_word_dbfe02:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbfe04:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1414
boss_collision_word_dbfe06:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_dbfe08:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
