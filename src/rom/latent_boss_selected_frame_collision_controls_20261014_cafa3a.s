; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA3A
boss_collision_word_cafa3a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
