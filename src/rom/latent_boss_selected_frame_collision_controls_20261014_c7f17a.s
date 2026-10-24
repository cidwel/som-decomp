; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F17A
boss_collision_word_c7f17a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
