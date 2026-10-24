; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE38
boss_collision_word_cafe38:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0004
