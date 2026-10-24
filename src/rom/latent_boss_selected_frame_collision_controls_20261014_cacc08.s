; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC08
boss_collision_word_cacc08:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $130F
boss_collision_word_cacc0a:
    ; collision signed-axis displacement to actorC8/C9
    .word $ED00
boss_collision_word_cacc0c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1120
boss_collision_word_cacc0e:
    ; collision signed-axis displacement to actorC0/C1
    .word $0808
boss_collision_word_cacc10:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
