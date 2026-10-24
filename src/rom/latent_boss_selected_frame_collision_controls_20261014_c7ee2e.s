; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EE2E
boss_collision_word_c7ee2e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C14
boss_collision_word_c7ee30:
    ; collision signed-axis displacement to actorC8/C9
    .word $ECFD
boss_collision_word_c7ee32:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ee34:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
