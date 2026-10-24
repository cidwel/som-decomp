; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F760
boss_collision_word_c7f760:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7f762:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f764:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_c7f766:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f768:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
