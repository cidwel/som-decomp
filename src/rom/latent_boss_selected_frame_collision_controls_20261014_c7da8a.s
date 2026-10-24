; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA8A
boss_collision_word_c7da8a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7da8c:
    ; collision signed-axis displacement to actorC8/C9
    .word $E904
boss_collision_word_c7da8e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1308
boss_collision_word_c7da90:
    ; collision signed-axis displacement to actorC0/C1
    .word $EC18
boss_collision_word_c7da92:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0808
boss_collision_word_c7da94:
    ; collision signed-axis displacement to actorCC/CD
    .word $E118
