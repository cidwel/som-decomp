; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E44C
boss_collision_word_c7e44c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
