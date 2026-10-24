; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C532
boss_collision_word_cac532:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_cac534:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF8
boss_collision_word_cac536:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac538:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
