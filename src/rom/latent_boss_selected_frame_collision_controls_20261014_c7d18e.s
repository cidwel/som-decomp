; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D18E
boss_collision_word_c7d18e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7d190:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7d192:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0E14
boss_collision_word_c7d194:
    ; collision signed-axis displacement to actorC0/C1
    .word $D2FC
boss_collision_word_c7d196:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
