; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F52E
boss_collision_word_c7f52e:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0808
boss_collision_word_c7f530:
    ; collision signed-axis displacement to actorC8/C9
    .word $F600
boss_collision_word_c7f532:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f534:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
