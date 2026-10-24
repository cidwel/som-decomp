; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F7C6
boss_collision_word_caf7c6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
