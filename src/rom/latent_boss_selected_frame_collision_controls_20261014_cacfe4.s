; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFE4
boss_collision_word_cacfe4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacfe6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0711
boss_collision_word_cacfe8:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_cacfea:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $050E
boss_collision_word_cacfec:
    ; collision signed-axis displacement to actorCC/CD
    .word $0000
