; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFC8
boss_collision_word_cadfc8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0011
