; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3D2
boss_collision_word_caf3d2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf3d4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0E0E
boss_collision_word_caf3d6:
    ; collision signed-axis displacement to actorC0/C1
    .word $23E0
boss_collision_word_caf3d8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
