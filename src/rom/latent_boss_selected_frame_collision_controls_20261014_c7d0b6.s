; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0B6
boss_collision_word_c7d0b6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d0b8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F001
boss_collision_word_c7d0ba:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $120B
boss_collision_word_c7d0bc:
    ; collision signed-axis displacement to actorC0/C1
    .word $CF0B
boss_collision_word_c7d0be:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
