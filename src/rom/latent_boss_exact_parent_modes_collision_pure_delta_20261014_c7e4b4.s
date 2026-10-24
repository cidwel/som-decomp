; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $E4B4
boss_collision_word_c7e4b4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0006
boss_collision_word_c7e4b6:
    ; collision signed-axis displacement to actorC8/C9
    .word $16EC
boss_collision_word_c7e4b8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $3A20
boss_collision_word_c7e4ba:
    ; collision signed-axis displacement to actorC0/C1
    .word $10F4
boss_collision_word_c7e4bc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1A26
boss_collision_word_c7e4be:
    ; collision signed-axis displacement to actorCC/CD
    .word $04F4
