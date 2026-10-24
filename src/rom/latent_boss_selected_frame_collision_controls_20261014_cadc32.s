; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DC32
boss_collision_word_cadc32:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadc34:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cadc36:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
