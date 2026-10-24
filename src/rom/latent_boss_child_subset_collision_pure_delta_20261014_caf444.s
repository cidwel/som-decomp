; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F444
boss_collision_word_caf444:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0008
boss_collision_word_caf446:
    ; collision signed-axis displacement to actorC8/C9
    .word $0898
boss_collision_word_caf448:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $3E48
boss_collision_word_caf44a:
    ; collision signed-axis displacement to actorC0/C1
    .word $08B8
boss_collision_word_caf44c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $3E4C
boss_collision_word_caf44e:
    ; collision signed-axis displacement to actorCC/CD
    .word $08D8
