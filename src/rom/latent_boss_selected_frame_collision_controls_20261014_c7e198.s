; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E198
boss_collision_word_c7e198:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e19a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F800
boss_collision_word_c7e19c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e19e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
