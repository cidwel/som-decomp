; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F60A
boss_collision_word_c7f60a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0B09
boss_collision_word_c7f60c:
    ; collision signed-axis displacement to actorC8/C9
    .word $F401
boss_collision_word_c7f60e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f610:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
