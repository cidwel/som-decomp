; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBC4
boss_collision_word_cacbc4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $130F
boss_collision_word_cacbc6:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_cacbc8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $2314
boss_collision_word_cacbca:
    ; collision signed-axis displacement to actorC0/C1
    .word $F31D
boss_collision_word_cacbcc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
