; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF66
boss_collision_word_cacf66:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacf68:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacf6a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1910
boss_collision_word_cacf6c:
    ; collision signed-axis displacement to actorCC/CD
    .word $E100
