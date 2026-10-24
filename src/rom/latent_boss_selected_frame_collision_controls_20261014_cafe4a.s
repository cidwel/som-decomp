; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE4A
boss_collision_word_cafe4a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
