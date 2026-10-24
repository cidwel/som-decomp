; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D864
boss_collision_word_c7d864:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0D0D
boss_collision_word_c7d866:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDFE
boss_collision_word_c7d868:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d86a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0907
boss_collision_word_c7d86c:
    ; collision signed-axis displacement to actorCC/CD
    .word $FB12
