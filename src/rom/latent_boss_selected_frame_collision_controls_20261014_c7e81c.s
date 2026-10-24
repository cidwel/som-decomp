; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E81C
boss_collision_word_c7e81c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e81e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e820:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C14
boss_collision_word_c7e822:
    ; collision signed-axis displacement to actorCC/CD
    .word $EDFC
