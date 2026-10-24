; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD18
boss_collision_word_dbfd18:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
