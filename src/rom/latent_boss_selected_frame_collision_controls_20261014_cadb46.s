; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB46
boss_collision_word_cadb46:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F0C
boss_collision_word_cadb48:
    ; collision signed-axis displacement to actorC8/C9
    .word $E901
boss_collision_word_cadb4a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cadb4c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
