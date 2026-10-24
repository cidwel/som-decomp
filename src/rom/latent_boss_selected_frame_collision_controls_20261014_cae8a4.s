; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E8A4
boss_collision_word_cae8a4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae8a6:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF08
boss_collision_word_cae8a8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae8aa:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
