; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D5C2
boss_collision_word_c7d5c2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C10
boss_collision_word_c7d5c4:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_c7d5c6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d5c8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
