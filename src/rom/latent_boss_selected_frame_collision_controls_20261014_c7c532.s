; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C532
boss_collision_word_c7c532:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1510
boss_collision_word_c7c534:
    ; collision signed-axis displacement to actorC8/C9
    .word $E500
boss_collision_word_c7c536:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c538:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
