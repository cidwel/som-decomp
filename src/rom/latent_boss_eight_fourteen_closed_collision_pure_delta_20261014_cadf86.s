; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF86
boss_collision_word_cadf86:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF01
boss_collision_word_cadf88:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFC8
boss_collision_word_cadf8a:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFD8
