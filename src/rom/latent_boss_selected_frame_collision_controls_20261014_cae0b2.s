; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E0B2
boss_collision_word_cae0b2:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E18
boss_collision_word_cae0b4:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF09
boss_collision_word_cae0b6:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_cae0b8:
    ; collision signed-axis displacement to actorC0/C1
    .word $EFE5
boss_collision_word_cae0ba:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
