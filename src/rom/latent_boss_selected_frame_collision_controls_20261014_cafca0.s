; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FCA0
boss_collision_word_cafca0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
