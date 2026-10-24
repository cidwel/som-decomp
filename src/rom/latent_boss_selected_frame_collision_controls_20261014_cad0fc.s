; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0FC
boss_collision_word_cad0fc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad0fe:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad100:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad102:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
