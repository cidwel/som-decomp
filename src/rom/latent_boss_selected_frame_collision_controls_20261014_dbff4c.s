; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF4C
boss_collision_word_dbff4c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbff4e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_dbff50:
    ; collision signed-axis displacement to actorC0/C1
    .word $0B18
boss_collision_word_dbff52:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
