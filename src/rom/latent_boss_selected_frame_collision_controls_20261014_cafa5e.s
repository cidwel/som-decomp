; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA5E
boss_collision_word_cafa5e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
