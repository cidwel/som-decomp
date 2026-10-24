; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1F2
boss_collision_word_c7f1f2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
