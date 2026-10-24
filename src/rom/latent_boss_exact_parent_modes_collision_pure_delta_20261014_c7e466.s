; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E466
boss_collision_word_c7e466:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
