; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FC5C
boss_collision_word_cafc5c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
