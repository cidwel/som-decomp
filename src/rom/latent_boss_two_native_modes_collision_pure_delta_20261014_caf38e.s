; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F38E
boss_collision_word_caf38e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf390:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0E07
boss_collision_word_caf392:
    ; collision signed-axis displacement to actorC0/C1
    .word $0D1E
boss_collision_word_caf394:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
