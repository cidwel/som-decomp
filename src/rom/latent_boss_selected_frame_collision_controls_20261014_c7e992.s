; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E992
boss_collision_word_c7e992:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e994:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1814
boss_collision_word_c7e996:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_c7e998:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1010
boss_collision_word_c7e99a:
    ; collision signed-axis displacement to actorCC/CD
    .word $F000
