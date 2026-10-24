; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0EE
boss_collision_word_cac0ee:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac0f0:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1020
boss_collision_word_cac0f2:
    ; collision signed-axis displacement to actorC0/C1
    .word $FE00
boss_collision_word_cac0f4:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0F18
boss_collision_word_cac0f6:
    ; collision signed-axis displacement to actorCC/CD
    .word $E700
