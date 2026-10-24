; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3B0
boss_collision_word_caf3b0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf3b2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0A0C
boss_collision_word_caf3b4:
    ; collision signed-axis displacement to actorC0/C1
    .word $F831
boss_collision_word_caf3b6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
