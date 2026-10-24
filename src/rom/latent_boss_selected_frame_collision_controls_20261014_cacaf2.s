; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAF2
boss_collision_word_cacaf2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1907
boss_collision_word_cacaf4:
    ; collision signed-axis displacement to actorC8/C9
    .word $E1F9
boss_collision_word_cacaf6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacaf8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1C0B
boss_collision_word_cacafa:
    ; collision signed-axis displacement to actorCC/CD
    .word $E40C
