; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DC44
boss_collision_word_c7dc44:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0410
boss_collision_word_c7dc46:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_c7dc48:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1A10
boss_collision_word_c7dc4a:
    ; collision signed-axis displacement to actorC0/C1
    .word $0200
boss_collision_word_c7dc4c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1608
boss_collision_word_c7dc4e:
    ; collision signed-axis displacement to actorCC/CD
    .word $FF00
