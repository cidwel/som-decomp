; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E8F2
boss_collision_word_cae8f2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae8f4:
    ; collision signed-axis displacement to actorC8/C9
    .word $EE08
boss_collision_word_cae8f6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae8f8:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
