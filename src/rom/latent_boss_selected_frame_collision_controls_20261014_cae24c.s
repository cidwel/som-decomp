; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E24C
boss_collision_word_cae24c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae24e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $131C
boss_collision_word_cae250:
    ; collision signed-axis displacement to actorC0/C1
    .word $F404
boss_collision_word_cae252:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
