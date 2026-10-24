; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F72C
boss_collision_word_c7f72c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7f72e:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f730:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_c7f732:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f734:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
