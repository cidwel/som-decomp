; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB3E
boss_collision_word_cacb3e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacb40:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacb42:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1711
boss_collision_word_cacb44:
    ; collision signed-axis displacement to actorCC/CD
    .word $DD00
