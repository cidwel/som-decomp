; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D37A
boss_collision_word_cad37a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad37c:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad37e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad380:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
