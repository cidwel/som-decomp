; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DDB4
boss_collision_word_c7ddb4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7ddb6:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_c7ddb8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ddba:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
