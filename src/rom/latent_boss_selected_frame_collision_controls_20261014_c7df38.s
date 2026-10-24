; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF38
boss_collision_word_c7df38:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0710
boss_collision_word_c7df3a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7df3c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7df3e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $101C
boss_collision_word_c7df40:
    ; collision signed-axis displacement to actorCC/CD
    .word $D900
