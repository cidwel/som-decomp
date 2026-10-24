; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E940
boss_collision_word_cae940:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E17
boss_collision_word_cae942:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF08
boss_collision_word_cae944:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae946:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
