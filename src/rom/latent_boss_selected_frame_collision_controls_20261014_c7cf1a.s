; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF1A
boss_collision_word_c7cf1a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cf1c:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_c7cf1e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $160E
boss_collision_word_c7cf20:
    ; collision signed-axis displacement to actorC0/C1
    .word $FC29
boss_collision_word_c7cf22:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
