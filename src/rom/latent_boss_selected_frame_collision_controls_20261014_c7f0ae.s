; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0AE
boss_collision_word_c7f0ae:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
