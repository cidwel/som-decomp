; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C780
boss_collision_word_c7c780:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100F
boss_collision_word_c7c782:
    ; collision signed-axis displacement to actorC8/C9
    .word $E701
boss_collision_word_c7c784:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1225
boss_collision_word_c7c786:
    ; collision signed-axis displacement to actorC0/C1
    .word $FEF8
boss_collision_word_c7c788:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0A0E
boss_collision_word_c7c78a:
    ; collision signed-axis displacement to actorCC/CD
    .word $FC06
