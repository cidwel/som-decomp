; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F18C
boss_collision_word_c7f18c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF02
boss_collision_word_c7f18e:
    ; collision signed-axis displacement to actorC8/C9
    .word $FF90
boss_collision_word_c7f190:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFD0
boss_collision_word_c7f192:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f194:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0B1C
boss_collision_word_c7f196:
    ; collision signed-axis displacement to actorCC/CD
    .word $5E09
