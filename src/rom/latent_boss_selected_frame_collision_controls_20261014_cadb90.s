; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB90
boss_collision_word_cadb90:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F0C
boss_collision_word_cadb92:
    ; collision signed-axis displacement to actorC8/C9
    .word $E900
boss_collision_word_cadb94:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cadb96:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
