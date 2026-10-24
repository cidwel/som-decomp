; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F34A
boss_collision_word_caf34a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf34c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0F07
boss_collision_word_caf34e:
    ; collision signed-axis displacement to actorC0/C1
    .word $1613
boss_collision_word_caf350:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
