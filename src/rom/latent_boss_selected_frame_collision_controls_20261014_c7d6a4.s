; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6A4
boss_collision_word_c7d6a4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d6a6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d6a8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1010
boss_collision_word_c7d6aa:
    ; collision signed-axis displacement to actorCC/CD
    .word $E800
