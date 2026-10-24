; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C7CA
boss_collision_word_c7c7ca:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7c7cc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c7ce:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
