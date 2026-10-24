; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C020
boss_collision_word_cac020:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac022:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac024:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1410
boss_collision_word_cac026:
    ; collision signed-axis displacement to actorCC/CD
    .word $E300
