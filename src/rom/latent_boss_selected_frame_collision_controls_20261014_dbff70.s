; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF70
boss_collision_word_dbff70:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbff72:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_dbff74:
    ; collision signed-axis displacement to actorC0/C1
    .word $180C
boss_collision_word_dbff76:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
