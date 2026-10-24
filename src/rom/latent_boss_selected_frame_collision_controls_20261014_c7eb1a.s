; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB1A
boss_collision_word_c7eb1a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1014
boss_collision_word_c7eb1c:
    ; collision signed-axis displacement to actorC8/C9
    .word $F1FC
boss_collision_word_c7eb1e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7eb20:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
