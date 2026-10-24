; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD00
boss_collision_word_cafd00:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
