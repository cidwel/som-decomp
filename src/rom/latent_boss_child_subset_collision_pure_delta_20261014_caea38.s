; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA38
boss_collision_word_caea38:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caea3a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_caea3c:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_caea3e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
