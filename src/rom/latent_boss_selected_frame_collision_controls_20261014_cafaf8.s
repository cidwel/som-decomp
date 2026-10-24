; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FAF8
boss_collision_word_cafaf8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
