; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F8E2
boss_collision_word_caf8e2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
