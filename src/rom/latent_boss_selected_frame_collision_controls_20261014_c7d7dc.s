; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7DC
boss_collision_word_c7d7dc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d7de:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_c7d7e0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0F17
boss_collision_word_c7d7e2:
    ; collision signed-axis displacement to actorC0/C1
    .word $C3FC
boss_collision_word_c7d7e4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0F05
boss_collision_word_c7d7e6:
    ; collision signed-axis displacement to actorCC/CD
    .word $C10D
