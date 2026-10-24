; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8CC
boss_collision_word_c7c8cc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
