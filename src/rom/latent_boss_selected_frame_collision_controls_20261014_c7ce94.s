; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE94
boss_collision_word_c7ce94:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F10
boss_collision_word_c7ce96:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7ce98:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7ce9a:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
