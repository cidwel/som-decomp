; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F420
boss_collision_word_caf420:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF02
boss_collision_word_caf422:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFD0
boss_collision_word_caf424:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFF0
