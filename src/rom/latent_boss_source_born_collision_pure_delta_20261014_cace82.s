; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE82
boss_collision_word_cace82:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cace84:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cace86:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
