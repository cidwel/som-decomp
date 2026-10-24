; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECEE
boss_collision_word_c7ecee:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C14
boss_collision_word_c7ecf0:
    ; collision signed-axis displacement to actorC8/C9
    .word $ECFC
boss_collision_word_c7ecf2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ecf4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
