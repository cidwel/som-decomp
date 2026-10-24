; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFB6
boss_collision_word_cadfb6:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF02
boss_collision_word_cadfb8:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFC8
boss_collision_word_cadfba:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFD8
