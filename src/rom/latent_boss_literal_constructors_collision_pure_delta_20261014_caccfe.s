; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCFE
boss_collision_word_caccfe:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacd00:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacd02:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
