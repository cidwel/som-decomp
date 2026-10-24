; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D91A
boss_collision_word_c7d91a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7d91c:
    ; collision signed-axis displacement to actorC8/C9
    .word $E804
boss_collision_word_c7d91e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7d920:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
