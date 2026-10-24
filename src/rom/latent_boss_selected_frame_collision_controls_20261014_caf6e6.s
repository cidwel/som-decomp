; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F6E6
boss_collision_word_caf6e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
