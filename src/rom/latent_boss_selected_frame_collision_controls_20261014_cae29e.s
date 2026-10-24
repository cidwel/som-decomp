; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E29E
boss_collision_word_cae29e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cae2a0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $151C
boss_collision_word_cae2a2:
    ; collision signed-axis displacement to actorC0/C1
    .word $F504
boss_collision_word_cae2a4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
