; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E05C
boss_collision_word_cae05c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0D17
boss_collision_word_cae05e:
    ; collision signed-axis displacement to actorC8/C9
    .word $EF08
boss_collision_word_cae060:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae062:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
