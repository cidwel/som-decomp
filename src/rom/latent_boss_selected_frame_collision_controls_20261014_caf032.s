; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F032
boss_collision_word_caf032:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf034:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caf036:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
