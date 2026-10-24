; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E620
boss_collision_word_cae620:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae622:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_cae624:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae626:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
