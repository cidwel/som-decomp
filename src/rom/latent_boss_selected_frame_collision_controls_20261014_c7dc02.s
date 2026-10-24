; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DC02
boss_collision_word_c7dc02:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0410
boss_collision_word_c7dc04:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_c7dc06:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1810
boss_collision_word_c7dc08:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7dc0a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1408
boss_collision_word_c7dc0c:
    ; collision signed-axis displacement to actorCC/CD
    .word $FD00
