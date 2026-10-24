; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDD0
boss_collision_word_cafdd0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
