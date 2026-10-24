; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E856
boss_collision_word_cae856:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae858:
    ; collision signed-axis displacement to actorC8/C9
    .word $EE08
boss_collision_word_cae85a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae85c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
