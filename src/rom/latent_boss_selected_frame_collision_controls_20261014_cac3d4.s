; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3D4
boss_collision_word_cac3d4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1418
boss_collision_word_cac3d6:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_cac3d8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac3da:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
