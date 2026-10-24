; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D546
boss_collision_word_c7d546:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C08
boss_collision_word_c7d548:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_c7d54a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d54c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1005
boss_collision_word_c7d54e:
    ; collision signed-axis displacement to actorCC/CD
    .word $F1ED
