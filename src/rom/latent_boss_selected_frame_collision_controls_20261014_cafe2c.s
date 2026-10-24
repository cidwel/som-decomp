; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE2C
boss_collision_word_cafe2c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
