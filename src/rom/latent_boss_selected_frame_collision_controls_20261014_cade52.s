; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE52
boss_collision_word_cade52:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cade54:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D30
boss_collision_word_cade56:
    ; collision signed-axis displacement to actorC0/C1
    .word $EF00
boss_collision_word_cade58:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
