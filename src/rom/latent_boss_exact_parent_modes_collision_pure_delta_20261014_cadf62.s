; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF62
boss_collision_word_cadf62:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF01
boss_collision_word_cadf64:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFE0
boss_collision_word_cadf66:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFE0
