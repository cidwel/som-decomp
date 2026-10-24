; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F804
boss_collision_word_caf804:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0009
