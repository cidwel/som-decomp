; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F284
boss_collision_word_c7f284:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0808
boss_collision_word_c7f286:
    ; collision signed-axis displacement to actorC8/C9
    .word $F900
boss_collision_word_c7f288:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_c7f28a:
    ; collision signed-axis displacement to actorC0/C1
    .word $F900
boss_collision_word_c7f28c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
