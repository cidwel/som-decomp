; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C82E
boss_collision_word_cac82e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac830:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac832:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
