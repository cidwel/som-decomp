; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D442
boss_collision_word_c7d442:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7d444:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d446:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C10
boss_collision_word_c7d448:
    ; collision signed-axis displacement to actorCC/CD
    .word $ED00
