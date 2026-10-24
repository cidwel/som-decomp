; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF26
boss_collision_word_cadf26:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadf28:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1134
boss_collision_word_cadf2a:
    ; collision signed-axis displacement to actorC0/C1
    .word $EE01
boss_collision_word_cadf2c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
