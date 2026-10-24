; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DCFA
boss_collision_word_c7dcfa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7dcfc:
    ; collision signed-axis displacement to actorC8/C9
    .word $ECFC
boss_collision_word_c7dcfe:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C16
boss_collision_word_c7dd00:
    ; collision signed-axis displacement to actorC0/C1
    .word $E81E
boss_collision_word_c7dd02:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0311
boss_collision_word_c7dd04:
    ; collision signed-axis displacement to actorCC/CD
    .word $E819
