; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCEC
boss_collision_word_caccec:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_caccee:
    ; collision signed-axis displacement to actorC8/C9
    .word $DC00
boss_collision_word_caccf0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caccf2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
