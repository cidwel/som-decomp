; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E000
boss_collision_word_c7e000:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C10
boss_collision_word_c7e002:
    ; collision signed-axis displacement to actorC8/C9
    .word $EC08
boss_collision_word_c7e004:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7e006:
    ; collision signed-axis displacement to actorC0/C1
    .word $F820
boss_collision_word_c7e008:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
