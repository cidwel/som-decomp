; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF9C
boss_collision_word_c7df9c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1008
boss_collision_word_c7df9e:
    ; collision signed-axis displacement to actorC8/C9
    .word $E9F8
boss_collision_word_c7dfa0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7dfa2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
