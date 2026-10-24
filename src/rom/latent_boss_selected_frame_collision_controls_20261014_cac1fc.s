; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1FC
boss_collision_word_cac1fc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac1fe:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac200:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
