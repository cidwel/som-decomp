; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DD7E
boss_collision_word_cadd7e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadd80:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D2E
boss_collision_word_cadd82:
    ; collision signed-axis displacement to actorC0/C1
    .word $F000
boss_collision_word_cadd84:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
