; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EACA
boss_collision_word_caeaca:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $0003
