; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD4A
boss_collision_word_cafd4a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
