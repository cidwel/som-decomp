; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D4C0
boss_collision_word_c7d4c0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d4c2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D15
boss_collision_word_c7d4c4:
    ; collision signed-axis displacement to actorC0/C1
    .word $0500
boss_collision_word_c7d4c6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1506
boss_collision_word_c7d4c8:
    ; collision signed-axis displacement to actorCC/CD
    .word $FEF2
