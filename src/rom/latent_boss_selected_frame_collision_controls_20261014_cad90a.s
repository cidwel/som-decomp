; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D90A
boss_collision_word_cad90a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad90c:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad90e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad910:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
