; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE58
boss_collision_word_cabe58:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cabe5a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cabe5c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
