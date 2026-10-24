; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D822
boss_collision_word_c7d822:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7d824:
    ; collision signed-axis displacement to actorC8/C9
    .word $E8FF
boss_collision_word_c7d826:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1016
boss_collision_word_c7d828:
    ; collision signed-axis displacement to actorC0/C1
    .word $BDFE
boss_collision_word_c7d82a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0F05
boss_collision_word_c7d82c:
    ; collision signed-axis displacement to actorCC/CD
    .word $B90D
