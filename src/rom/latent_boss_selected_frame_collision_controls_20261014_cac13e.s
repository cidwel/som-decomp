; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C13E
boss_collision_word_cac13e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac140:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1020
boss_collision_word_cac142:
    ; collision signed-axis displacement to actorC0/C1
    .word $FE00
boss_collision_word_cac144:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1018
boss_collision_word_cac146:
    ; collision signed-axis displacement to actorCC/CD
    .word $E700
