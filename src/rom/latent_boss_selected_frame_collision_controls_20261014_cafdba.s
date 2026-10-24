; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDBA
boss_collision_word_cafdba:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
