; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C646
boss_collision_word_cac646:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1411
boss_collision_word_cac648:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF8
boss_collision_word_cac64a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac64c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
