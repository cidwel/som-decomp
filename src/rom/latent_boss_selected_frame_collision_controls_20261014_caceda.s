; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEDA
boss_collision_word_caceda:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $1610
boss_collision_word_cacedc:
    ; collision signed-axis displacement to actorC8/C9
    .word $DB00
boss_collision_word_cacede:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $0000
boss_collision_word_cacee0:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
