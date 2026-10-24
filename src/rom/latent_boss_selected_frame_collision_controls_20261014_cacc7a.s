; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC7A
boss_collision_word_cacc7a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_cacc7c:
    ; collision signed-axis displacement to actorC8/C9
    .word $DD00
boss_collision_word_cacc7e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacc80:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
