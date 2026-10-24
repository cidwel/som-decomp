; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E94E
boss_collision_word_c7e94e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7e950:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e952:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
