; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F576
boss_collision_word_c7f576:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0808
boss_collision_word_c7f578:
    ; collision signed-axis displacement to actorC8/C9
    .word $F601
boss_collision_word_c7f57a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f57c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
