; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E9DC
boss_collision_word_cae9dc:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E17
boss_collision_word_cae9de:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF08
boss_collision_word_cae9e0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae9e2:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
