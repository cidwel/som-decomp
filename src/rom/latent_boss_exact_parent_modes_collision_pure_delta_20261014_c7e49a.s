; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E49A
boss_collision_word_c7e49a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
