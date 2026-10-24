; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $D276
boss_collision_word_c7d276:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0001
boss_collision_word_c7d278:
    ; collision packed-axis extents/presence to actorCE/CF; collision signed-axis displacement to actorC8/C9
    .word $F0F8
boss_collision_word_c7d27a:
    ; collision packed-axis extents/presence to actorC2/C3; collision signed-axis displacement to actorCC/CD
    .word $0C8A
boss_collision_word_c7d27c:
    ; collision signed-axis displacement to actorC0/C1
    .word $0001
boss_collision_word_c7d27e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $F0F8
boss_collision_word_c7d280:
    ; collision signed-axis displacement to actorCC/CD
    .word $0CAA
