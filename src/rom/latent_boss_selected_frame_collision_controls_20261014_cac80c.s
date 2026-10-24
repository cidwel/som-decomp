; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C80C
boss_collision_word_cac80c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1310
boss_collision_word_cac80e:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF8
boss_collision_word_cac810:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac812:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
