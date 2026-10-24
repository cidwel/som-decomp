; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F69E
boss_collision_word_c7f69e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B07
boss_collision_word_c7f6a0:
    ; collision signed-axis displacement to actorC8/C9
    .word $F300
boss_collision_word_c7f6a2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f6a4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
