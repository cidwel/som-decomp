; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDC6
boss_collision_word_c7cdc6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cdc8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F101
boss_collision_word_c7cdca:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0C
boss_collision_word_c7cdcc:
    ; collision signed-axis displacement to actorC0/C1
    .word $DAE5
boss_collision_word_c7cdce:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
