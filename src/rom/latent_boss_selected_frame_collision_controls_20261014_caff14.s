; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF14
boss_collision_word_caff14:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0001
