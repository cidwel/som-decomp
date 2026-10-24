; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE60
boss_collision_word_cafe60:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0002
