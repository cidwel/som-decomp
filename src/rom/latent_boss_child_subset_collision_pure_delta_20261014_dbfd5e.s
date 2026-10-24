; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD5E
boss_collision_word_dbfd5e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
