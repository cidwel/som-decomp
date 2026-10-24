; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E808
boss_collision_word_cae808:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0E17
boss_collision_word_cae80a:
    ; collision signed-axis displacement to actorC8/C9
    .word $EE08
boss_collision_word_cae80c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae80e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
