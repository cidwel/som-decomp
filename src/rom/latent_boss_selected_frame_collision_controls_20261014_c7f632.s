; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F632
boss_collision_word_c7f632:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B07
boss_collision_word_c7f634:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f636:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f638:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
