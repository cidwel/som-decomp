; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F102
boss_collision_word_c7f102:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0007
