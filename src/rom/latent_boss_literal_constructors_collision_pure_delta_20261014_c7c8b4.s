; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8B4
boss_collision_word_c7c8b4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0002
