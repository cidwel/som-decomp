; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F9DA
boss_collision_word_c7f9da:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
