; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF82
boss_collision_word_dbff82:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbff84:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_dbff86:
    ; collision signed-axis displacement to actorC0/C1
    .word $1500
boss_collision_word_dbff88:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
