; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DD6E
boss_collision_word_c7dd6e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7dd70:
    ; collision signed-axis displacement to actorC8/C9
    .word $E8FC
boss_collision_word_c7dd72:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C17
boss_collision_word_c7dd74:
    ; collision signed-axis displacement to actorC0/C1
    .word $E71F
boss_collision_word_c7dd76:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0412
boss_collision_word_c7dd78:
    ; collision signed-axis displacement to actorCC/CD
    .word $E71A
