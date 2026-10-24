; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F74C
boss_collision_word_c7f74c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7f74e:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f750:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_c7f752:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f754:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
