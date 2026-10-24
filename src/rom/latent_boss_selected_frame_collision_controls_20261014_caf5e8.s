; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F5E8
boss_collision_word_caf5e8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
