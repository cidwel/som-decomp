; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA46
boss_collision_word_caea46:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caea48:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_caea4a:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_caea4c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
