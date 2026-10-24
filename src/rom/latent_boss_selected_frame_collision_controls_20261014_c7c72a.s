; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C72A
boss_collision_word_c7c72a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1410
boss_collision_word_c7c72c:
    ; collision signed-axis displacement to actorC8/C9
    .word $E400
boss_collision_word_c7c72e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $2011
boss_collision_word_c7c730:
    ; collision signed-axis displacement to actorC0/C1
    .word $E5DF
boss_collision_word_c7c732:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0A09
boss_collision_word_c7c734:
    ; collision signed-axis displacement to actorCC/CD
    .word $F3DD
