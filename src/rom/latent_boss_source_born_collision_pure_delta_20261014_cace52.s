; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE52
boss_collision_word_cace52:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cace54:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cace56:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
