; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F5A2
boss_collision_word_caf5a2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
