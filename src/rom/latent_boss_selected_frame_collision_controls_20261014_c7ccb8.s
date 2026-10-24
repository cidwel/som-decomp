; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCB8
boss_collision_word_c7ccb8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7ccba:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7ccbc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ccbe:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
