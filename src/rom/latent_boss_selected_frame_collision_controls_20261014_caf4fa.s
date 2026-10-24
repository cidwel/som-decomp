; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F4FA
boss_collision_word_caf4fa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
