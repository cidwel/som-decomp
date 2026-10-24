; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FB7C
boss_collision_word_cafb7c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
