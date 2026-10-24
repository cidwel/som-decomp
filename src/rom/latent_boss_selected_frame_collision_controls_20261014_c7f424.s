; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F424
boss_collision_word_c7f424:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A0A
boss_collision_word_c7f426:
    ; collision signed-axis displacement to actorC8/C9
    .word $F404
boss_collision_word_c7f428:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f42a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
