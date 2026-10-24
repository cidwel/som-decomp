; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEE4
boss_collision_word_c7dee4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0810
boss_collision_word_c7dee6:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7dee8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7deea:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $101C
boss_collision_word_c7deec:
    ; collision signed-axis displacement to actorCC/CD
    .word $D800
