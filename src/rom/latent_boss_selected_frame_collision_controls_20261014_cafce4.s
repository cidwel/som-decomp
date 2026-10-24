; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FCE4
boss_collision_word_cafce4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
