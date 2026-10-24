; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB0E
boss_collision_word_caeb0e:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorCC/CD
    .word $0002
