; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFDA
boss_collision_word_caefda:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caefdc:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_caefde:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
