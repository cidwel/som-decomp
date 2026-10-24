; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FF3A
boss_collision_word_dbff3a:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorCC/CD
    .word $0000
boss_collision_word_dbff3c:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0404
boss_collision_word_dbff3e:
    ; collision signed-axis displacement to actorC0/C1
    .word $0014
boss_collision_word_dbff40:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
