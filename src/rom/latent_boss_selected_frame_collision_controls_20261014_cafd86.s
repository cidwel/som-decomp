; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD86
boss_collision_word_cafd86:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
