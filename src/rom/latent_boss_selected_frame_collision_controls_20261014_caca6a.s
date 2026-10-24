; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA6A
boss_collision_word_caca6a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1513
boss_collision_word_caca6c:
    ; collision signed-axis displacement to actorC8/C9
    .word $DB00
boss_collision_word_caca6e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caca70:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
