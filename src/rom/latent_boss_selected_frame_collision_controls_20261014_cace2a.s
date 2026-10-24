; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE2A
boss_collision_word_cace2a:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1508
boss_collision_word_cace2c:
    ; collision signed-axis displacement to actorC8/C9
    .word $DDF8
boss_collision_word_cace2e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cace30:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $1A0A
boss_collision_word_cace32:
    ; collision signed-axis displacement to actorCC/CD
    .word $E10A
