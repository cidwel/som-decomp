; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FCDC
boss_collision_word_dbfcdc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
