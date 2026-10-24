; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E24E
boss_collision_word_c7e24e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e250:
    ; collision signed-axis displacement to actorC8/C9
    .word $0800
boss_collision_word_c7e252:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e254:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
