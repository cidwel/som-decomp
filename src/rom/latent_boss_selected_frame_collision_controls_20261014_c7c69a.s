; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C69A
boss_collision_word_c7c69a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_c7c69c:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_c7c69e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c6a0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0F0F
boss_collision_word_c7c6a2:
    ; collision signed-axis displacement to actorCC/CD
    .word $CCEF
