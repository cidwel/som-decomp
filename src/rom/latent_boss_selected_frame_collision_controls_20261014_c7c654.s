; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C654
boss_collision_word_c7c654:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1110
boss_collision_word_c7c656:
    ; collision signed-axis displacement to actorC8/C9
    .word $E701
boss_collision_word_c7c658:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c65a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
