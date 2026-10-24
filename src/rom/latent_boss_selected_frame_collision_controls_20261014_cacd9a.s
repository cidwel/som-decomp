; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD9A
boss_collision_word_cacd9a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1310
boss_collision_word_cacd9c:
    ; collision signed-axis displacement to actorC8/C9
    .word $DE00
boss_collision_word_cacd9e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_cacda0:
    ; collision signed-axis displacement to actorC0/C1
    .word $FD03
boss_collision_word_cacda2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
