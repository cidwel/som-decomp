; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF6C
boss_collision_word_c7df6c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7df6e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7df70:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
