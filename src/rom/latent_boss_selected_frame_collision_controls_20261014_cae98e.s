; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E98E
boss_collision_word_cae98e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae990:
    ; collision signed-axis displacement to actorC8/C9
    .word $EE08
boss_collision_word_cae992:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae994:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
