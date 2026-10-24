; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E96E
boss_collision_word_c7e96e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e970:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $201C
boss_collision_word_c7e972:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_c7e974:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1010
boss_collision_word_c7e976:
    ; collision signed-axis displacement to actorCC/CD
    .word $F000
