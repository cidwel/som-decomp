; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD56
boss_collision_word_cacd56:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_cacd58:
    ; collision signed-axis displacement to actorC8/C9
    .word $DD00
boss_collision_word_cacd5a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0B0C
boss_collision_word_cacd5c:
    ; collision signed-axis displacement to actorC0/C1
    .word $FD04
boss_collision_word_cacd5e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
