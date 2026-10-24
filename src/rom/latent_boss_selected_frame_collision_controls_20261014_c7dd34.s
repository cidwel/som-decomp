; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DD34
boss_collision_word_c7dd34:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7dd36:
    ; collision signed-axis displacement to actorC8/C9
    .word $E8FC
boss_collision_word_c7dd38:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C18
boss_collision_word_c7dd3a:
    ; collision signed-axis displacement to actorC0/C1
    .word $E520
boss_collision_word_c7dd3c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0413
boss_collision_word_c7dd3e:
    ; collision signed-axis displacement to actorCC/CD
    .word $E71C
