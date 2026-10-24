; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DC82
boss_collision_word_c7dc82:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F10
boss_collision_word_c7dc84:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_c7dc86:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7dc88:
    ; collision signed-axis displacement to actorC0/C1
    .word $C900
boss_collision_word_c7dc8a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C08
boss_collision_word_c7dc8c:
    ; collision signed-axis displacement to actorCC/CD
    .word $CC00
