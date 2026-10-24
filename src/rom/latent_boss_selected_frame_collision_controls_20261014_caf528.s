; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F528
boss_collision_word_caf528:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorCC/CD
    .word $0001
