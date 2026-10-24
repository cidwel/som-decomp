; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA46
boss_collision_word_cada46:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cada48:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cada4a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
