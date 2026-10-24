; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF5E
boss_collision_word_c7cf5e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cf60:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7cf62:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0C
boss_collision_word_c7cf64:
    ; collision signed-axis displacement to actorC0/C1
    .word $0729
boss_collision_word_c7cf66:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
