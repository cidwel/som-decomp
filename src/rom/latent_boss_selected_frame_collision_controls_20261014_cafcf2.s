; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FCF2
boss_collision_word_cafcf2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
