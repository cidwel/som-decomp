; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5E0
boss_collision_word_c7c5e0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7c5e2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c5e4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $130F
boss_collision_word_c7c5e6:
    ; collision signed-axis displacement to actorCC/CD
    .word $E700
