; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9A8
boss_collision_word_cac9a8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1512
boss_collision_word_cac9aa:
    ; collision signed-axis displacement to actorC8/C9
    .word $DC00
boss_collision_word_cac9ac:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac9ae:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
