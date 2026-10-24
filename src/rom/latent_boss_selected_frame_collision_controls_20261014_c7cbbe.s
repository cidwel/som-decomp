; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBBE
boss_collision_word_c7cbbe:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cbc0:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7cbc2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C18
boss_collision_word_c7cbc4:
    ; collision signed-axis displacement to actorC0/C1
    .word $1108
boss_collision_word_c7cbc6:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
