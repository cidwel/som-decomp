; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F90C
boss_collision_word_caf90c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
