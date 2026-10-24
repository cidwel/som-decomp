; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9EA
boss_collision_word_cac9ea:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1612
boss_collision_word_cac9ec:
    ; collision signed-axis displacement to actorC8/C9
    .word $DB00
boss_collision_word_cac9ee:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac9f0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
