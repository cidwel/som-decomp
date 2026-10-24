; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C60C
boss_collision_word_cac60c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1310
boss_collision_word_cac60e:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF9
boss_collision_word_cac610:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac612:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
