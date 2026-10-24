; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD66
boss_collision_word_dbfd66:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_dbfd68:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0808
boss_collision_word_dbfd6a:
    ; collision signed-axis displacement to actorC0/C1
    .word $0000
boss_collision_word_dbfd6c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
