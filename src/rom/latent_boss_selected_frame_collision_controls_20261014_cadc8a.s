; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DC8A
boss_collision_word_cadc8a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadc8c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cadc8e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
