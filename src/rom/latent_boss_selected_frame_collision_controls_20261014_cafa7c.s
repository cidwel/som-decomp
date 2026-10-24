; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA7C
boss_collision_word_cafa7c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
