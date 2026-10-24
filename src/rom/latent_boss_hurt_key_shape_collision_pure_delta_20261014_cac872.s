; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C872
boss_collision_word_cac872:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac874:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac876:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
