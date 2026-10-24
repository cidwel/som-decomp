; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD3E
boss_collision_word_c7cd3e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cd40:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7cd42:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0C
boss_collision_word_c7cd44:
    ; collision signed-axis displacement to actorC0/C1
    .word $08E3
boss_collision_word_c7cd46:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
