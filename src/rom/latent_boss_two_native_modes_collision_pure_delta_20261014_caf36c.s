; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $F36C
boss_collision_word_caf36c:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0000
boss_collision_word_caf36e:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $1007
boss_collision_word_caf370:
    ; collision signed-axis displacement to actorC0/C1
    .word $131A
boss_collision_word_caf372:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $0000
