; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F30A
boss_collision_word_caf30a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf30c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caf30e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
