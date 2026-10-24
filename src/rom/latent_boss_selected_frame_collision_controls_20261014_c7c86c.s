; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C86C
boss_collision_word_c7c86c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7c86e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7c870:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1617
boss_collision_word_c7c872:
    ; collision signed-axis displacement to actorCC/CD
    .word $E601
