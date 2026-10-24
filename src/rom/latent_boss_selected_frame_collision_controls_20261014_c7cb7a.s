; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB7A
boss_collision_word_c7cb7a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_c7cb7c:
    ; collision signed-axis displacement to actorC8/C9
    .word $F100
boss_collision_word_c7cb7e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D0D
boss_collision_word_c7cb80:
    ; collision signed-axis displacement to actorC0/C1
    .word $10E5
boss_collision_word_c7cb82:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
