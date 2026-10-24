; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFF8
boss_collision_word_cacff8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cacffa:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0812
boss_collision_word_cacffc:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_cacffe:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $060D
boss_collision_word_cad000:
    ; collision signed-axis displacement to actorCC/CD
    .word $0000
