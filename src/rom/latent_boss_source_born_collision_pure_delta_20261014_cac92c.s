; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C92C
boss_collision_word_cac92c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $000E
