; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6DA
boss_collision_word_c7d6da:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d6dc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $080D
boss_collision_word_c7d6de:
    ; collision signed-axis displacement to actorC0/C1
    .word $D100
boss_collision_word_c7d6e0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1410
boss_collision_word_c7d6e2:
    ; collision signed-axis displacement to actorCC/CD
    .word $E500
