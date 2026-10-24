; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FC7E
boss_collision_word_cafc7e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
