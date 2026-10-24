; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F82A
boss_collision_word_caf82a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
