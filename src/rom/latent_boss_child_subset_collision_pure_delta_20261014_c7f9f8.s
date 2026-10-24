; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F9F8
boss_collision_word_c7f9f8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
