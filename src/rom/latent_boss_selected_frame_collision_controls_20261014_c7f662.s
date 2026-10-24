; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F662
boss_collision_word_c7f662:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A06
boss_collision_word_c7f664:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f666:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f668:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
