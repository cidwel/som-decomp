; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE0E
boss_collision_word_c7ce0e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7ce10:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7ce12:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C3D
boss_collision_word_c7ce14:
    ; collision signed-axis displacement to actorC0/C1
    .word $EE00
boss_collision_word_c7ce16:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
