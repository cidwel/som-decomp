; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C768
boss_collision_word_cac768:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1310
boss_collision_word_cac76a:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF8
boss_collision_word_cac76c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac76e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
