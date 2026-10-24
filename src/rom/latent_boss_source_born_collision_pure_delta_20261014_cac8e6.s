; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8E6
boss_collision_word_cac8e6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
