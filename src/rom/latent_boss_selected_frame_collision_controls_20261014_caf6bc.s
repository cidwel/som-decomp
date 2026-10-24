; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F6BC
boss_collision_word_caf6bc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
