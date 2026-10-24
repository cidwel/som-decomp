; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFCE
boss_collision_word_cabfce:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cabfd0:
    ; collision signed-axis displacement to actorC8/C9
    .word $E700
boss_collision_word_cabfd2:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cabfd4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
