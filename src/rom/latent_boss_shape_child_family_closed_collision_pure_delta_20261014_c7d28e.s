; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $D28E
boss_collision_word_c7d28e:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0003
boss_collision_word_c7d290:
    ; collision packed-axis extents/presence to actorCE/CF; collision signed-axis displacement to actorC8/C9
    .word $F4F8
boss_collision_word_c7d292:
    ; collision packed-axis extents/presence to actorC2/C3; collision signed-axis displacement to actorCC/CD
    .word $0C80
boss_collision_word_c7d294:
    ; collision signed-axis displacement to actorC0/C1
    .word $E4F0
boss_collision_word_c7d296:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0CA0
boss_collision_word_c7d298:
    ; collision signed-axis displacement to actorCC/CD
    .word $E400
