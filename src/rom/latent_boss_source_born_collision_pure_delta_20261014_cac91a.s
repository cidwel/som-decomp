; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C91A
boss_collision_word_cac91a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0004
