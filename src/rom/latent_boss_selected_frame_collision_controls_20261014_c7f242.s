; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F242
boss_collision_word_c7f242:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f244:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f246:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
