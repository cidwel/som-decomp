; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E102
boss_collision_word_cae102:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0D17
boss_collision_word_cae104:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF08
boss_collision_word_cae106:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_cae108:
    ; collision signed-axis displacement to actorC0/C1
    .word $EFE5
boss_collision_word_cae10a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
