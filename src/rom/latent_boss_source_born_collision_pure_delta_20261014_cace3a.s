; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE3A
boss_collision_word_cace3a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cace3c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cace3e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
