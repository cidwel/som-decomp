; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E6D4
boss_collision_word_c7e6d4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e6d6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e6d8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1014
boss_collision_word_c7e6da:
    ; collision signed-axis displacement to actorCC/CD
    .word $F1FD
