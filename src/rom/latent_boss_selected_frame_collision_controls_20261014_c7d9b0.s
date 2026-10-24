; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9B0
boss_collision_word_c7d9b0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7d9b2:
    ; collision signed-axis displacement to actorC8/C9
    .word $E9FC
boss_collision_word_c7d9b4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d9b6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
