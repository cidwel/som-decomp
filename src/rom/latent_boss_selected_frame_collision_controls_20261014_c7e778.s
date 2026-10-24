; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E778
boss_collision_word_c7e778:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e77a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e77c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1014
boss_collision_word_c7e77e:
    ; collision signed-axis displacement to actorCC/CD
    .word $F1FD
