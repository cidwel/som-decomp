; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD2E
boss_collision_word_dbfd2e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
