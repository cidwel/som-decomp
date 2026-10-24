; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB38
boss_collision_word_caeb38:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0006
boss_collision_word_caeb3a:
    ; collision packed-axis extents/presence to actorCE/CF; collision signed-axis displacement to actorC8/C9
    .word $F4EC
boss_collision_word_caeb3c:
    ; collision packed-axis extents/presence to actorC2/C3; collision signed-axis displacement to actorCC/CD
    .word $0A0C
boss_collision_word_caeb3e:
    ; collision signed-axis displacement to actorC0/C1
    .word $FCF8
boss_collision_word_caeb40:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0A0C
boss_collision_word_caeb42:
    ; collision signed-axis displacement to actorCC/CD
    .word $0400
