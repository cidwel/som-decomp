; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF92
boss_collision_word_cadf92:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $FF02
boss_collision_word_cadf94:
    ; collision signed-axis displacement to actorC8/C9
    .word $FFE0
boss_collision_word_cadf96:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $FFE0
