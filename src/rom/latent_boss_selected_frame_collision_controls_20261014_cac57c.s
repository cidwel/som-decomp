; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C57C
boss_collision_word_cac57c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1411
boss_collision_word_cac57e:
    ; collision signed-axis displacement to actorC8/C9
    .word $ECF8
boss_collision_word_cac580:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac582:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
