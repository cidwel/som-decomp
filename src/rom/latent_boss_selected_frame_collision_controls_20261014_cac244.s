; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C244
boss_collision_word_cac244:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac246:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac248:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
