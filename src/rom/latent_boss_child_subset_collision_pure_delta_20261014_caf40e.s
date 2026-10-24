; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F40E
boss_collision_word_caf40e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF02
boss_collision_word_caf410:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFC0
boss_collision_word_caf412:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFF0
