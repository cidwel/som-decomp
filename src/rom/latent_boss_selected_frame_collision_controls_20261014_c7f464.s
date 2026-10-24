; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F464
boss_collision_word_c7f464:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B0A
boss_collision_word_c7f466:
    ; collision signed-axis displacement to actorC8/C9
    .word $F400
boss_collision_word_c7f468:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f46a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
