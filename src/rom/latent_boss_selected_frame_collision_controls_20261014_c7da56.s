; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA56
boss_collision_word_c7da56:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7da58:
    ; collision signed-axis displacement to actorC8/C9
    .word $E9FC
boss_collision_word_c7da5a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7da5c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $040C
boss_collision_word_c7da5e:
    ; collision signed-axis displacement to actorCC/CD
    .word $D4FC
