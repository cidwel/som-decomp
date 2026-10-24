; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FEF6
boss_collision_word_cafef6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
