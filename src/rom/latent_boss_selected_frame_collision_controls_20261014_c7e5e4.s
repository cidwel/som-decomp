; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E5E4
boss_collision_word_c7e5e4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1014
boss_collision_word_c7e5e6:
    ; collision signed-axis displacement to actorC8/C9
    .word $F1FD
boss_collision_word_c7e5e8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e5ea:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
