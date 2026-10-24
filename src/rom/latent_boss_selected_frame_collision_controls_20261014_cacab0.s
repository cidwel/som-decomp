; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAB0
boss_collision_word_cacab0:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1607
boss_collision_word_cacab2:
    ; collision signed-axis displacement to actorC8/C9
    .word $DAF9
boss_collision_word_cacab4:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacab6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
