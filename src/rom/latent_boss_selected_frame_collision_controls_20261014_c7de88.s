; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE88
boss_collision_word_c7de88:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0810
boss_collision_word_c7de8a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7de8c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7de8e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0C20
boss_collision_word_c7de90:
    ; collision signed-axis displacement to actorCC/CD
    .word $DC00
