; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F806
boss_collision_word_c7f806:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0F10
boss_collision_word_c7f808:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f80a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1010
boss_collision_word_c7f80c:
    ; collision signed-axis displacement to actorC0/C1
    .word $2000
boss_collision_word_c7f80e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0B07
boss_collision_word_c7f810:
    ; collision signed-axis displacement to actorCC/CD
    .word $051A
