; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F756
boss_collision_word_caf756:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
