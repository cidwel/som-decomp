; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E00E
boss_collision_word_cae00e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae010:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF09
boss_collision_word_cae012:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae014:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
