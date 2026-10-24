; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D716
boss_collision_word_c7d716:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7d718:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_c7d71a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7d71c:
    ; collision signed-axis displacement to actorC0/C1
    .word $C800
boss_collision_word_c7d71e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C08
boss_collision_word_c7d720:
    ; collision signed-axis displacement to actorCC/CD
    .word $CC00
