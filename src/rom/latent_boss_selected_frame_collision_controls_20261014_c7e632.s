; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E632
boss_collision_word_c7e632:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7e634:
    ; collision signed-axis displacement to actorC8/C9
    .word $F0F8
boss_collision_word_c7e636:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7e638:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
