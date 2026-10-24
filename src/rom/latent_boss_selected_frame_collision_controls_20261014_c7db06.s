; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB06
boss_collision_word_c7db06:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7db08:
    ; collision signed-axis displacement to actorC8/C9
    .word $E90C
boss_collision_word_c7db0a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1115
boss_collision_word_c7db0c:
    ; collision signed-axis displacement to actorC0/C1
    .word $EF2F
boss_collision_word_c7db0e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0912
boss_collision_word_c7db10:
    ; collision signed-axis displacement to actorCC/CD
    .word $E932
