; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB44
boss_collision_word_c7db44:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7db46:
    ; collision signed-axis displacement to actorC8/C9
    .word $E904
boss_collision_word_c7db48:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $120C
boss_collision_word_c7db4a:
    ; collision signed-axis displacement to actorC0/C1
    .word $ED1E
boss_collision_word_c7db4c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $080C
boss_collision_word_c7db4e:
    ; collision signed-axis displacement to actorCC/CD
    .word $E51D
