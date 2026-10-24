; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F704
boss_collision_word_c7f704:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7f706:
    ; collision signed-axis displacement to actorC8/C9
    .word $0000
boss_collision_word_c7f708:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0C0C
boss_collision_word_c7f70a:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_c7f70c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
