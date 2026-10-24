; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D504
boss_collision_word_c7d504:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C08
boss_collision_word_c7d506:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_c7d508:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0F16
boss_collision_word_c7d50a:
    ; collision signed-axis displacement to actorC0/C1
    .word $0C01
boss_collision_word_c7d50c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1A06
boss_collision_word_c7d50e:
    ; collision signed-axis displacement to actorCC/CD
    .word $03F2
