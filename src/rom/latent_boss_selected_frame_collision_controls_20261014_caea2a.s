; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA2A
boss_collision_word_caea2a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_caea2c:
    ; collision signed-axis displacement to actorC8/C9
    .word $EE08
boss_collision_word_caea2e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caea30:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
