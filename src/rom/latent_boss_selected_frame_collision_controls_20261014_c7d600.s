; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D600
boss_collision_word_c7d600:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0408
boss_collision_word_c7d602:
    ; collision signed-axis displacement to actorC8/C9
    .word $DC00
boss_collision_word_c7d604:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d606:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C10
boss_collision_word_c7d608:
    ; collision signed-axis displacement to actorCC/CD
    .word $ED00
