; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F640
boss_collision_word_caf640:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
