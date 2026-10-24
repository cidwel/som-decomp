; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D758
boss_collision_word_c7d758:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d75a:
    ; collision signed-axis displacement to actorC8/C9
    .word $E800
boss_collision_word_c7d75c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1810
boss_collision_word_c7d75e:
    ; collision signed-axis displacement to actorC0/C1
    .word $C000
boss_collision_word_c7d760:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1308
boss_collision_word_c7d762:
    ; collision signed-axis displacement to actorCC/CD
    .word $C400
