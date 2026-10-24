; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D646
boss_collision_word_cad646:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad648:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad64a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad64c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
