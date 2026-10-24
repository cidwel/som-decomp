; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F386
boss_collision_word_c7f386:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B0A
boss_collision_word_c7f388:
    ; collision signed-axis displacement to actorC8/C9
    .word $F402
boss_collision_word_c7f38a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f38c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
