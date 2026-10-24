; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C84E
boss_collision_word_cac84e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac850:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac852:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
