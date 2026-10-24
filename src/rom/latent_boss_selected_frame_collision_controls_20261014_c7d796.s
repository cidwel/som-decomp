; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D796
boss_collision_word_c7d796:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C10
boss_collision_word_c7d798:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_c7d79a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C14
boss_collision_word_c7d79c:
    ; collision signed-axis displacement to actorC0/C1
    .word $D0FF
boss_collision_word_c7d79e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1005
boss_collision_word_c7d7a0:
    ; collision signed-axis displacement to actorCC/CD
    .word $D10C
