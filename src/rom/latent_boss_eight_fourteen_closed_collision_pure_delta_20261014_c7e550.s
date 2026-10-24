; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E550
boss_collision_word_c7e550:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0011
