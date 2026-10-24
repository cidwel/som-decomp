; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F864
boss_collision_word_caf864:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
