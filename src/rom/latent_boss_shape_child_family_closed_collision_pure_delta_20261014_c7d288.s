; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $D288
boss_collision_word_c7d288:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
