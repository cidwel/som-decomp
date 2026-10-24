; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC04
boss_collision_word_c7ec04:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C14
boss_collision_word_c7ec06:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDFC
boss_collision_word_c7ec08:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ec0a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
