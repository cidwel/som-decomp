; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE1A
boss_collision_word_cafe1a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
