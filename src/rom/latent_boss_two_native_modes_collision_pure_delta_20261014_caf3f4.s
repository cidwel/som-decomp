; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3F4
boss_collision_word_caf3f4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf3f6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0E0E
boss_collision_word_caf3f8:
    ; collision signed-axis displacement to actorC0/C1
    .word $27D3
boss_collision_word_caf3fa:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
