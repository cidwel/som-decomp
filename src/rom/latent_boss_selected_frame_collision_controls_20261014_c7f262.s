; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F262
boss_collision_word_c7f262:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0808
boss_collision_word_c7f264:
    ; collision signed-axis displacement to actorC8/C9
    .word $F900
boss_collision_word_c7f266:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_c7f268:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
