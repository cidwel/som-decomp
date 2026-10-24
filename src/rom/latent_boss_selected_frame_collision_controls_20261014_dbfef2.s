; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FEF2
boss_collision_word_dbfef2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
