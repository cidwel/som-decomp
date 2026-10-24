; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C340
boss_collision_word_cac340:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1518
boss_collision_word_cac342:
    ; collision signed-axis displacement to actorC8/C9
    .word $E500
boss_collision_word_cac344:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac346:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
