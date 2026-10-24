; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD16
boss_collision_word_cacd16:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacd18:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacd1a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
