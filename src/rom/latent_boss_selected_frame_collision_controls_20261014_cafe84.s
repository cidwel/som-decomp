; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE84
boss_collision_word_cafe84:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $000A
