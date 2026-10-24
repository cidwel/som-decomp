; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E212
boss_collision_word_c7e212:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e214:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7e216:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e218:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
