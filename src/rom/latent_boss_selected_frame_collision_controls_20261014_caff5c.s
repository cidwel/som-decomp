; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF5C
boss_collision_word_caff5c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $F000
boss_collision_word_caff5e:
    ; collision signed-axis displacement to actorC8/C9
    .word $5FA4
boss_collision_word_caff60:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $F0F0
boss_collision_word_caff62:
    ; collision signed-axis displacement to actorC0/C1
    .word $1FA4
boss_collision_word_caff64:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $00F0
boss_collision_word_caff66:
    ; collision signed-axis displacement to actorCC/CD
    .word $9FA4
