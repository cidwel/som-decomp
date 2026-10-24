; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C09E
boss_collision_word_cac09e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac0a0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1020
boss_collision_word_cac0a2:
    ; collision signed-axis displacement to actorC0/C1
    .word $FE00
boss_collision_word_cac0a4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1018
boss_collision_word_cac0a6:
    ; collision signed-axis displacement to actorCC/CD
    .word $E700
