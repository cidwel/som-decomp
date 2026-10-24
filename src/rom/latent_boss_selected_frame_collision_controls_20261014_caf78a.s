; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F78A
boss_collision_word_caf78a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
