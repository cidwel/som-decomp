; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8A4
boss_collision_word_cac8a4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0001
