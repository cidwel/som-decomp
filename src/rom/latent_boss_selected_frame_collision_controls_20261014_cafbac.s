; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FBAC
boss_collision_word_cafbac:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
