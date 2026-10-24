; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CED6
boss_collision_word_c7ced6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7ced8:
    ; collision signed-axis displacement to actorC8/C9
    .word $F101
boss_collision_word_c7ceda:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0F11
boss_collision_word_c7cedc:
    ; collision signed-axis displacement to actorC0/C1
    .word $E11C
boss_collision_word_c7cede:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
