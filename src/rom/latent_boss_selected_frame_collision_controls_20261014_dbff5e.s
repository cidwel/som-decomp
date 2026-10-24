; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF5E
boss_collision_word_dbff5e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbff60:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_dbff62:
    ; collision signed-axis displacement to actorC0/C1
    .word $1616
boss_collision_word_dbff64:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
