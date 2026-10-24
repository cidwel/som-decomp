; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F36C
boss_collision_word_c7f36c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0A0A
boss_collision_word_c7f36e:
    ; collision signed-axis displacement to actorC8/C9
    .word $F501
boss_collision_word_c7f370:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f372:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
