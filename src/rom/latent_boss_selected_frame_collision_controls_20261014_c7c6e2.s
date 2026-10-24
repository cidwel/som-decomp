; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C6E2
boss_collision_word_c7c6e2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1510
boss_collision_word_c7c6e4:
    ; collision signed-axis displacement to actorC8/C9
    .word $E500
boss_collision_word_c7c6e6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c6e8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $110F
boss_collision_word_c7c6ea:
    ; collision signed-axis displacement to actorCC/CD
    .word $CBF0
