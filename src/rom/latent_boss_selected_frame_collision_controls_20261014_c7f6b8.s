; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F6B8
boss_collision_word_c7f6b8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A09
boss_collision_word_c7f6ba:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f6bc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f6be:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
