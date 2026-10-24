; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF0C
boss_collision_word_dbff0c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
