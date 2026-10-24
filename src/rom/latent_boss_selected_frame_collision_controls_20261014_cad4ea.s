; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D4EA
boss_collision_word_cad4ea:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad4ec:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad4ee:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad4f0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
