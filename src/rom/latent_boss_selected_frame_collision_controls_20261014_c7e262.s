; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E262
boss_collision_word_c7e262:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e264:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7e266:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7e268:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1010
boss_collision_word_c7e26a:
    ; collision signed-axis displacement to actorCC/CD
    .word $0000
