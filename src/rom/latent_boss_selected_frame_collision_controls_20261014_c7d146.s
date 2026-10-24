; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D146
boss_collision_word_c7d146:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7d148:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7d14a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0E0E
boss_collision_word_c7d14c:
    ; collision signed-axis displacement to actorC0/C1
    .word $D31E
boss_collision_word_c7d14e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
