; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3C6
boss_collision_word_c7d3c6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d3c8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $180D
boss_collision_word_c7d3ca:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7d3cc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1908
boss_collision_word_c7d3ce:
    ; collision signed-axis displacement to actorCC/CD
    .word $FA00
