; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C7BA
boss_collision_word_cac7ba:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_cac7bc:
    ; collision signed-axis displacement to actorC8/C9
    .word $ECF8
boss_collision_word_cac7be:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac7c0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
