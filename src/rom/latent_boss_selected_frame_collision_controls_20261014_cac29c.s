; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C29C
boss_collision_word_cac29c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1418
boss_collision_word_cac29e:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_cac2a0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac2a2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
