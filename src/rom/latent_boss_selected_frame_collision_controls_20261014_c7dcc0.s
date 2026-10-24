; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DCC0
boss_collision_word_c7dcc0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C10
boss_collision_word_c7dcc2:
    ; collision signed-axis displacement to actorC8/C9
    .word $EC00
boss_collision_word_c7dcc4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1410
boss_collision_word_c7dcc6:
    ; collision signed-axis displacement to actorC0/C1
    .word $CC00
boss_collision_word_c7dcc8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C08
boss_collision_word_c7dcca:
    ; collision signed-axis displacement to actorCC/CD
    .word $CD00
