; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EAF2
boss_collision_word_caeaf2:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0001
