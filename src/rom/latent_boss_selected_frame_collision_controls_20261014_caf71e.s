; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F71E
boss_collision_word_caf71e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
