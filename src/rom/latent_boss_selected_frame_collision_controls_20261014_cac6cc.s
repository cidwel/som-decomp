; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C6CC
boss_collision_word_cac6cc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F11
boss_collision_word_cac6ce:
    ; collision signed-axis displacement to actorC8/C9
    .word $F1F7
boss_collision_word_cac6d0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac6d2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
