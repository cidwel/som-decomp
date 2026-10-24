; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EAA2
boss_collision_word_caeaa2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caeaa4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caeaa6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
