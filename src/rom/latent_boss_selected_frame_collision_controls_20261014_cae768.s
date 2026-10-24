; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E768
boss_collision_word_cae768:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1010
boss_collision_word_cae76a:
    ; collision signed-axis displacement to actorC8/C9
    .word $F000
boss_collision_word_cae76c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cae76e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
