; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD2C
boss_collision_word_cafd2c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
