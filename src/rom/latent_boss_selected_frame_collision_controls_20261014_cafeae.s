; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FEAE
boss_collision_word_cafeae:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0009
