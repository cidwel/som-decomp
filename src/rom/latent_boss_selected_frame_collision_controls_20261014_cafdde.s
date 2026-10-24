; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDDE
boss_collision_word_cafdde:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
