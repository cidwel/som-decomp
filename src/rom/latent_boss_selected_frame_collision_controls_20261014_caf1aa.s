; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1AA
boss_collision_word_caf1aa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf1ac:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caf1ae:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
