; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5AA
boss_collision_word_c7c5aa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1310
boss_collision_word_c7c5ac:
    ; collision signed-axis displacement to actorC8/C9
    .word $E701
boss_collision_word_c7c5ae:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c5b0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
