; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EAB2
boss_collision_word_caeab2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0002
