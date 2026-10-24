; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C966
boss_collision_word_cac966:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1512
boss_collision_word_cac968:
    ; collision signed-axis displacement to actorC8/C9
    .word $DB00
boss_collision_word_cac96a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cac96c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
