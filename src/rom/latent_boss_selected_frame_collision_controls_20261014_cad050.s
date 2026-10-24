; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D050
boss_collision_word_cad050:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cad052:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_cad054:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cad056:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
