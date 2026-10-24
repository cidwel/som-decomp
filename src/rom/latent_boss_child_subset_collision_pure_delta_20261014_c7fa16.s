; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA16
boss_collision_word_c7fa16:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $D508
boss_collision_word_c7fa18:
    ; collision signed-axis displacement to actorC8/C9
    .word $4187
boss_collision_word_c7fa1a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $F9BC
boss_collision_word_c7fa1c:
    ; collision signed-axis displacement to actorC0/C1
    .word $E1DE
boss_collision_word_c7fa1e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $AB87
boss_collision_word_c7fa20:
    ; collision signed-axis displacement to actorCC/CD
    .word $75FE
