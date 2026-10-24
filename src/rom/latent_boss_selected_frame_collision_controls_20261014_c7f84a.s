; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F84A
boss_collision_word_c7f84a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_c7f84c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7f84e:
    ; collision signed-axis displacement to actorC0/C1
    .word $2000
boss_collision_word_c7f850:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
