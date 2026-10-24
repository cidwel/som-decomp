; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DDE8
boss_collision_word_cadde8:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caddea:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0D2F
boss_collision_word_caddec:
    ; collision signed-axis displacement to actorC0/C1
    .word $EE00
boss_collision_word_caddee:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
