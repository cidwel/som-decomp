; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA1C
boss_collision_word_c7da1c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0C0C
boss_collision_word_c7da1e:
    ; collision signed-axis displacement to actorC8/C9
    .word $EC0C
boss_collision_word_c7da20:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0A14
boss_collision_word_c7da22:
    ; collision signed-axis displacement to actorC0/C1
    .word $E62C
boss_collision_word_c7da24:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0411
boss_collision_word_c7da26:
    ; collision signed-axis displacement to actorCC/CD
    .word $E72A
