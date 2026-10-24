; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $C896
boss_collision_word_cac896:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_cac898:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $090B
boss_collision_word_cac89a:
    ; collision signed-axis displacement to actorC0/C1
    .word $EA1C
boss_collision_word_cac89c:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
