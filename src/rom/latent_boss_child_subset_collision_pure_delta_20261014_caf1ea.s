; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1EA
boss_collision_word_caf1ea:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf1ec:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caf1ee:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
