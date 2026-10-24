; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8DA
boss_collision_word_c7c8da:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $000A
boss_collision_word_c7c8dc:
    ; collision signed-axis displacement to actorC8/C9
    .word $D8F0
boss_collision_word_c7c8de:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1A2C
boss_collision_word_c7c8e0:
    ; collision signed-axis displacement to actorC0/C1
    .word $D800
boss_collision_word_c7c8e2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1A2E
boss_collision_word_c7c8e4:
    ; collision signed-axis displacement to actorCC/CD
    .word $E8F0
