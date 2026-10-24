; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDE2
boss_collision_word_cacde2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1508
boss_collision_word_cacde4:
    ; collision signed-axis displacement to actorC8/C9
    .word $DCF8
boss_collision_word_cacde6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacde8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1B0A
boss_collision_word_cacdea:
    ; collision signed-axis displacement to actorCC/CD
    .word $E10B
