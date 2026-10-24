; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DBC4
boss_collision_word_c7dbc4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7dbc6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7dbc8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1008
boss_collision_word_c7dbca:
    ; collision signed-axis displacement to actorCC/CD
    .word $E810
