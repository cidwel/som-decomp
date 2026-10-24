; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1FA
boss_collision_word_cae1fa:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae1fc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $151B
boss_collision_word_cae1fe:
    ; collision signed-axis displacement to actorC0/C1
    .word $F504
boss_collision_word_cae200:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
