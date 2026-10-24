; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF50
boss_collision_word_cadf50:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cadf52:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cadf54:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
