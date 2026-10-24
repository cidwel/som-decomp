; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C716
boss_collision_word_cac716:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1311
boss_collision_word_cac718:
    ; collision signed-axis displacement to actorC8/C9
    .word $EDF8
boss_collision_word_cac71a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac71c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
