; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD7E
boss_collision_word_c7cd7e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F10
boss_collision_word_c7cd80:
    ; collision signed-axis displacement to actorC8/C9
    .word $F101
boss_collision_word_c7cd82:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $2E0C
boss_collision_word_c7cd84:
    ; collision signed-axis displacement to actorC0/C1
    .word $F202
boss_collision_word_c7cd86:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
