; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C81A
boss_collision_word_c7c81a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E0F
boss_collision_word_c7c81c:
    ; collision signed-axis displacement to actorC8/C9
    .word $E300
boss_collision_word_c7c81e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c820:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
