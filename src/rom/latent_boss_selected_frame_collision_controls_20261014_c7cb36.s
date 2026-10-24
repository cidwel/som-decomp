; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB36
boss_collision_word_c7cb36:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cb38:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7cb3a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0D
boss_collision_word_c7cb3c:
    ; collision signed-axis displacement to actorC0/C1
    .word $0EDA
boss_collision_word_c7cb3e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
