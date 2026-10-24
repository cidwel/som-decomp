; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FB06
boss_collision_word_cafb06:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0002
