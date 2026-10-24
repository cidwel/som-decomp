; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D388
boss_collision_word_c7d388:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d38a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d38c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C10
boss_collision_word_c7d38e:
    ; collision signed-axis displacement to actorCC/CD
    .word $ED00
