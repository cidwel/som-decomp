; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F828
boss_collision_word_c7f828:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1008
boss_collision_word_c7f82a:
    ; collision signed-axis displacement to actorC8/C9
    .word $00F8
boss_collision_word_c7f82c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7f82e:
    ; collision signed-axis displacement to actorC0/C1
    .word $2000
boss_collision_word_c7f830:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $130F
boss_collision_word_c7f832:
    ; collision signed-axis displacement to actorCC/CD
    .word $0310
