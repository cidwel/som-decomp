; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D40A
boss_collision_word_c7d40a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d40c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $200D
boss_collision_word_c7d40e:
    ; collision signed-axis displacement to actorC0/C1
    .word $0800
boss_collision_word_c7d410:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $2108
boss_collision_word_c7d412:
    ; collision signed-axis displacement to actorCC/CD
    .word $0100
