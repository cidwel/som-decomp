; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFBC
boss_collision_word_caefbc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $2020
boss_collision_word_caefbe:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_caefc0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caefc2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
