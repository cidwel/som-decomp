; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E184
boss_collision_word_c7e184:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e186:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7e188:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e18a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
