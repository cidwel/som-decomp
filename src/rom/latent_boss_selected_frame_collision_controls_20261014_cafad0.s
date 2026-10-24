; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FAD0
boss_collision_word_cafad0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
