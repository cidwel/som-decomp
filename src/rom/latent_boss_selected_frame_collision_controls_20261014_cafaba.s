; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FABA
boss_collision_word_cafaba:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0005
