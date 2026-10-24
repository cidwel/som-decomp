; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F6FC
boss_collision_word_caf6fc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
