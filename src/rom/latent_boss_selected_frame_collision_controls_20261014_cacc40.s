; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC40
boss_collision_word_cacc40:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $140F
boss_collision_word_cacc42:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_cacc44:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacc46:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
