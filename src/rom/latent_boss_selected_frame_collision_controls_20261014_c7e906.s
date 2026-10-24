; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E906
boss_collision_word_c7e906:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e908:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e90a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
