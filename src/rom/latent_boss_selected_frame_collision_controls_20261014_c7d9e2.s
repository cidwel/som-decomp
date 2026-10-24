; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9E2
boss_collision_word_c7d9e2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7d9e4:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED04
boss_collision_word_c7d9e6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0B0E
boss_collision_word_c7d9e8:
    ; collision signed-axis displacement to actorC0/C1
    .word $E61E
boss_collision_word_c7d9ea:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $060A
boss_collision_word_c7d9ec:
    ; collision signed-axis displacement to actorCC/CD
    .word $E61A
