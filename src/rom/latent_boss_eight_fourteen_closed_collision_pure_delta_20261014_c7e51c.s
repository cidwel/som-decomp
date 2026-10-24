; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E51C
boss_collision_word_c7e51c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
