; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8F8
boss_collision_word_cac8f8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
