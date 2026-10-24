; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F648
boss_collision_word_c7f648:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A06
boss_collision_word_c7f64a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f64c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f64e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
